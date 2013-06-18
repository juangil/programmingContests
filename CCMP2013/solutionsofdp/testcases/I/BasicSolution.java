
import java.util.*;
import java.io.*;

class Place
{
    public double   X, // X-axis coordinate
                    Y, // Y-axis coordinate
                    S; // Satisfaction

    public String   id,
                    name;

    public int      index;

    public Vector<Place>    adjacents;


    public Place()
    {
        adjacents = new Vector<Place>();
    }
    public Place( double X, double Y, double S, String id, String name )
    {
        this.X = X;
        this.Y = Y;
        this.S = S;
        this.id = id;
        this.name = name;

        adjacents = new Vector<Place>();
    }

    public void addAdjacent( Place other )
        throws Exception
    {
        if ( other == this )
            throw new Exception( "Trying to connect one place with itself!" );

        for( Place existent : this.adjacents )
            if ( existent.equals( other ) )
                throw new Exception( "Trying to connect one place to another already connected!" );

        this.adjacents.add( other );
    }

    public double timeRequired( Place other )
    {
        final double V = 60.0 / 4.0; // Velocidad en minutos/kilómetro considerando que a pie se camina a 4km/h.

        double dx = this.X - other.X;
        double dy = this.Y - other.Y;

        double d = Math.sqrt( dx*dx + dy*dy );

        return V*d; // Devuelve los minutos necesarios para ir de un lugar a otro, 'd' debe estar en kilómetros.
    }
    public double distanceOnAverage( Place other )
    {
        double dx = Math.abs( this.X - other.X );
        double dy = Math.abs( this.Y - other.Y );
        
        return (dx+dy+distance(other))/2.0;
    }
    public double distance( Place other )
    {
        double dx = this.X - other.X;
        double dy = this.Y - other.Y;

        return Math.sqrt( dx*dx + dy*dy );
    }

    public boolean isAdjacent( Place other )
    {
        for( Place place : adjacents )
            if ( place.id.equals( other.id ) ) return true;

        return false;
    }
}
class Path
    implements Comparable
{
    private Place   place;
    private double  f;
    private double  accumulatedSatisfaction;
    private double  time;

    private Place                   visited[];
    private Vector<Place>           sequence;
    private Vector<Boolean>         selected;

    public Path( Place place,
                 double f,
                 double accumulatedSatisfaction,
                 double time,
                 Place           visited[],
                 Vector<Place>   sequence,
                 Vector<Boolean> selected,
                 boolean enteringCurrentPlace )
    {
        this.place = place;
        this.f = f;
        this.time = time;
        this.accumulatedSatisfaction = accumulatedSatisfaction;

        this.visited = new Place [ 65 ];
        if ( visited != null )
            for( int i=0; i < this.visited.length; i++ ) this.visited[i] = visited[i];
        this.visited[ place.index ] = place;

        this.sequence = new Vector<Place>();
        if ( sequence != null ) {
            for( Place p : sequence ) this.sequence.add(p);
        }

        this.selected = new Vector<Boolean>();
        if ( selected != null ) {
            for( Boolean b : selected ) this.selected.add(b);
        }

        this.sequence.add( place );
        this.selected.add( enteringCurrentPlace );
    }

    public Place getPlace() { return place; }
    public double f() { return f; }

    public double getTime() { return time; }
    public double getAccumulatedSatisfaction() { return accumulatedSatisfaction; }

    public Place [] getVisited() { return visited; }
    public Vector<Place> getSequence() { return sequence; }
    public Vector<Boolean> getSelected() { return selected; }

    public boolean contains( Place place )
    {
        return visited[ place.index ] != null;
    }

    public int compareTo( Object o )
    {
        if ( o instanceof Path ) {
            Path other = (Path)o;
            return (int)Math.signum( this.f - other.f );
        } else {
            throw new NullPointerException( "Comparing incompatible objects!" );
        }
    }
    public int compareTo( Path other )
    {
        return (int)Math.signum( this.f - other.f );
    }

    public void toPrintStream( PrintStream ps, Place lastToBePrinted, double additionalTimeToReachTarget )
    {
        ps.printf( Locale.US, "PATH FOUND: %8.3f ", accumulatedSatisfaction-additionalTimeToReachTarget );

        for( int i=0; i < sequence.size(); i++ ) {
            boolean selected = this.selected.get(i);
            Place place = this.sequence.get(i);

            if ( selected )
                ps.printf( "  %s", place.id );
            else
                ps.printf( " !%s", place.id );
        }
        ps.println( " " + lastToBePrinted.id );
    }
}

class Map
{
    private HashMap<String,Place>  bars;

    private final static int minutesPerDay = 24*60;
    private final static double minimumBarTime = 15;

    private double  availableTime;
    private double  averageDistance,
                    averageSatisfaction;
    private long    counter;
    private boolean targetReached;

    public Map( Scanner input )
        throws Exception
    {
        int N = input.nextInt();
        int A = input.nextInt();

        bars = new HashMap<String,Place>();

        averageSatisfaction = 0.0;

        for( int i=0; i < N; i++ ) {

            Place p = new Place();

            p.X = input.nextDouble();
            p.Y = input.nextDouble();
            p.S = input.nextDouble();
            p.id = input.next();
            p.name = input.nextLine().trim();
            p.index = i;

            if ( bars.containsKey( p.id ) )
                throw new Exception( "Duplicated key: " + p.id );

            bars.put( p.id, p );

            averageSatisfaction += p.S;
        }
        averageSatisfaction /= N;

        averageDistance=0.0;

        for( int i=0; i < A; i++ ) {
            
            String id1 = input.next();
            String id2 = input.next();

            Place p1 = bars.get( id1 );
            Place p2 = bars.get( id2 );

            if ( p1 == null ) throw new Exception( "Non existent key: " + id1 );
            if ( p2 == null ) throw new Exception( "Non existent key: " + id2 );

            p1.addAdjacent( p2 );
            p2.addAdjacent( p1 );

            averageDistance += p1.distance( p2 );
        }
        averageDistance /= A;
    }

    public void findAllPaths( String departureTime, String departurePlace, String arrivalTime, String arrivalPlace, double satisfaction )
        throws Exception
    {
        final int minutesPerDay = 24*60;

        String parts[] = departureTime.split( ":" );
        int minutesDeparture = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );
        parts = arrivalTime.split( ":" );
        int minutesArrival   = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );

        this.availableTime = ((minutesArrival - minutesDeparture) + minutesPerDay) % minutesPerDay;

        Place origin = bars.get( departurePlace );
        if ( origin == null ) throw new Exception( "Unknown place: " + departurePlace );
        Place target = bars.get( arrivalPlace );
        if ( target == null ) throw new Exception( "Unknown place: " + arrivalPlace );

        counter = 0;

        this.findAllPaths(  origin,
                            new Path( origin, 0.0, origin.S, minimumBarTime, null, null, null, true ),
                            target,
                            satisfaction );

        this.findAllPaths(  origin,
                            new Path( origin, 0.0, 0.0,      0.0,            null, null, null, false ),
                            target,
                            satisfaction );
    }

    private void findAllPaths( Place currentPlace, Path currentPath, Place target, double satisfaction )
    {
        if ( currentPlace == target ) {
            System.err.println( "ERROR GRAVE! POR AQUÍ NUNCA DEBERÍA PASAR" );
            System.exit(-1);
        }

        for( Place reachable : currentPlace.adjacents ) {

            if ( currentPath.contains( reachable ) ) continue;

            double additionalTime = currentPlace.timeRequired( reachable );

            if ( reachable == target ) {
            
                checkPath( currentPath, target, additionalTime );
                currentPath.toPrintStream( System.out, reachable, additionalTime );

                continue;
            }

            // Entering the reachable BAR or PUB
            double totalTime = currentPath.getTime()
                             + additionalTime
                             + minimumBarTime;

            double accumulatedSatisfaction = currentPath.getAccumulatedSatisfaction()
                                           - additionalTime
                                           + reachable.S;

            if ( totalTime <= availableTime ) {

                findAllPaths( reachable,
                              new Path( reachable, 0.0, accumulatedSatisfaction,
                                                        totalTime,
                                                        currentPath.getVisited(),
                                                        currentPath.getSequence(),
                                                        currentPath.getSelected(),
                                                        true ), 
                              target, satisfaction );
            }

            // Do not entering the reachable BAR or PUB
            totalTime = currentPath.getTime()
                      + additionalTime;

            accumulatedSatisfaction = currentPath.getAccumulatedSatisfaction()
                                    - additionalTime;

            if ( totalTime <= availableTime ) {

                findAllPaths( reachable,
                              new Path( reachable, 0.0, accumulatedSatisfaction,
                                                        totalTime,
                                                        currentPath.getVisited(),
                                                        currentPath.getSequence(),
                                                        currentPath.getSelected(),
                                                        false ), 
                              target, satisfaction );
            }
        }
    }

    public boolean findPathOptimized( String departureTime, String departurePlace,
                                      String   arrivalTime, String   arrivalPlace,
                                      double satisfaction )
        throws Exception
    {
        String parts[] = departureTime.split( ":" );
        int minutesDeparture = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );
        parts = arrivalTime.split( ":" );
        int minutesArrival   = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );

        this.availableTime = ((minutesArrival - minutesDeparture) + minutesPerDay) % minutesPerDay;

        Place origin = bars.get( departurePlace );
        if ( origin == null ) throw new Exception( "Unknown place: " + departurePlace );
        Place target = bars.get( arrivalPlace );
        if ( target == null ) throw new Exception( "Unknown place: " + arrivalPlace );

        PriorityQueue<Path> pq = new PriorityQueue<Path>( 591 );

        pq.add( new Path( origin, 0.0, origin.S, minimumBarTime, null, null, null, true ) );
        pq.add( new Path( origin, 0.0, 0.0,      0.0,            null, null, null, false ) );

        targetReached = false;

        while( pq.size() > 0  &&  !targetReached ) {

            Path currentPath = pq.poll();
            Place currentPlace = currentPath.getPlace();

            for( Place reachable : currentPlace.adjacents ) {

                double additionalTime = currentPlace.timeRequired( reachable );

                if ( reachable == target ) {

                    double accumulatedSatisfaction = currentPath.getAccumulatedSatisfaction() - additionalTime;

                    double totalTime = currentPath.getTime() + additionalTime;

                    if ( totalTime <= availableTime  &&  Math.abs( satisfaction - accumulatedSatisfaction ) < 0.1 ) {

                        // Show accumulatedSatisfaction and completed path
                        checkPath( currentPath, target, additionalTime );
                        currentPath.toPrintStream( System.out, reachable, additionalTime );

                        targetReached = true;

                        pq.clear();
                        break;
                    }

                    continue;
                }

                if ( currentPath.contains( reachable ) ) continue;

                // Entering the reachable BAR or PUB
                double totalTime = currentPath.getTime() + additionalTime + minimumBarTime;

                double accumulatedSatisfaction, f;

                if ( totalTime <= availableTime ) {

                    accumulatedSatisfaction = currentPath.getAccumulatedSatisfaction()
                                            - additionalTime
                                            + reachable.S;

                    f = accumulatedSatisfaction - h( currentPlace, target ); f = Math.abs( f - satisfaction );

                    pq.add( new Path( reachable, f,
                                        accumulatedSatisfaction,
                                        totalTime,
                                        currentPath.getVisited(),
                                        currentPath.getSequence(),
                                        currentPath.getSelected(),
                                        true ) );
                }

                // Do not entering the reachable BAR or PUB
                totalTime = currentPath.getTime() + additionalTime;

                if ( totalTime <= availableTime ) {

                    accumulatedSatisfaction = currentPath.getAccumulatedSatisfaction()
                                            - additionalTime;

                    f = accumulatedSatisfaction - h( currentPlace, target ); f = Math.abs( f - satisfaction );

                    pq.add( new Path( reachable, f, accumulatedSatisfaction,
                                                    totalTime,
                                                    currentPath.getVisited(),
                                                    currentPath.getSequence(),
                                                    currentPath.getSelected(),
                                                    false ) );
                }
            }
        }

        pq.clear();

        return targetReached;
    }

    private double h( Place current, Place target )
    {
        return current.timeRequired( target );
    }


    public boolean checkPath( Path path, Place target, double additionalTimeToReachTarget )
    {
        double accumulatedSatisfaction = 0.0;
        double totalTime = 0.0;

        Place previousPlace = target;

        for( int i=path.getSequence().size()-1; i >= 0; --i ) {

            boolean entering = path.getSelected().get(i);
            Place currentPlace = path.getSequence().get(i);

            if ( entering ) {
                totalTime += minimumBarTime;
                accumulatedSatisfaction += currentPlace.S;
            }
            double additionalTime = previousPlace.timeRequired( currentPlace );
            totalTime += additionalTime;
            accumulatedSatisfaction -= additionalTime;

            previousPlace = currentPlace;
        }

        double pathTime = path.getTime()+additionalTimeToReachTarget;
        double pathSatisfaction = path.getAccumulatedSatisfaction() - additionalTimeToReachTarget;

        if ( Math.abs( totalTime - pathTime ) > 0.01 ) {
            System.err.println( "ERROR GRAVE!  Satisfaction checked = " + accumulatedSatisfaction  + " diff: " + (accumulatedSatisfaction-pathSatisfaction) );
            System.err.println( "ERROR GRAVE!  Time checked = " + totalTime  + " vs " + pathTime + " diff: " + (totalTime-pathTime) );
            path.toPrintStream( System.err, target, additionalTimeToReachTarget );
            tracePath( path, target );
            System.exit(-2);
        }
        if ( Math.abs( accumulatedSatisfaction - pathSatisfaction ) > 0.01 ) {
            System.err.println( "ERROR GRAVE!  Satisfaction checked = " + accumulatedSatisfaction  + " diff: " + (accumulatedSatisfaction-pathSatisfaction) );
            System.err.println( "ERROR GRAVE!  Time checked = " + totalTime  + " vs " + pathTime + " diff: " + (totalTime-pathTime) );
            path.toPrintStream( System.err, target, additionalTimeToReachTarget );
            tracePath( path, target );
            System.exit(-2);
        }

        return true;
    }
    private void tracePath( Path path, Place target )
    {
        boolean entering = path.getSelected().get(0);
        Place previousPlace = path.getSequence().get(0);

        System.err.printf( " %s %s %f\n", previousPlace.id, entering ? "YES" : "NO ", previousPlace.S );

        for( int i=1; i < path.getSequence().size(); ++i ) {

            Place currentPlace = path.getSequence().get(i);
            entering = path.getSelected().get(i);

            System.err.printf( " %s --> %s : %f\n", previousPlace.id, currentPlace.id, previousPlace.timeRequired( currentPlace ) );
            System.err.printf( " %s %s %f\n", currentPlace.id, entering ? "YES" : "NO ", currentPlace.S );

            previousPlace = currentPlace;
        }
        System.err.printf( " %s --> %s : %f\n", previousPlace.id, target.id, previousPlace.timeRequired( target ) );
    }
    public boolean checkSolution( String line,
                                  String departureTime, String departurePlace,
                                  String   arrivalTime, String   arrivalPlace,
                                  double satisfaction )
        throws Exception
    {
        String parts[] = departureTime.split( ":" );

        int minutesDeparture = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );
        parts = arrivalTime.split( ":" );
        int minutesArrival   = Integer.parseInt( parts[0] ) * 60 + Integer.parseInt( parts[1] );

        this.availableTime = ((minutesArrival - minutesDeparture) + minutesPerDay) % minutesPerDay;

        if ( line.equals( "Impossible!" ) ) {
            return !this.findPathOptimized( departureTime, departurePlace, arrivalTime, arrivalPlace, satisfaction );
        }

        parts = line.split( "\\s+" );

        double satisfactionObtained = Double.parseDouble( parts[2] );

        if ( Math.abs( satisfactionObtained - satisfaction ) > 0.10001 ) {
            System.out.printf( "Different satisfaction: %f vs %f \n", satisfaction, satisfactionObtained );
            return false;
        }

        String id = parts[3];
        if ( id.charAt(0) == '!' ) id = id.substring( 1 );
        if ( !id.equals( departurePlace ) ) {
            System.out.printf( "Different departure places: %s vs %s exist\n", id, departurePlace );
            return false;
        }

        id = parts[ parts.length-1 ];
        if ( id.charAt(0) == '!' ) id = id.substring( 1 );
        if ( !id.equals( arrivalPlace ) ) {
            System.out.printf( "Different arrival places: %s vs %s exist\n", id, arrivalPlace );
            return false;
        }

        double accumulatedSatisfaction = 0.0;
        double totalTime = 0.0;
        Place previous = null;

        for( int i=3; i < parts.length; i++ ) {

            id = parts[i];
            boolean notEntering = (id.charAt(0) == '!');
            if ( notEntering ) id = id.substring(1);

            for( int j=i-1; j >= 3; j-- ) {
                if ( parts[j].endsWith( id ) ) {
                    System.out.printf( "Place %s repeated in the path, a loop exists\n", id );
                    return false;
                }
            }

            Place current = bars.get( id );
            if ( current == null ) {
                System.out.printf( "Place %s does not exist\n", id );
                return false;
            }

            if ( previous != null ) {

                if ( !previous.isAdjacent( current ) ) {
                    System.out.printf( "%s is not adjacent of %s\n", current.id, previous.id );
                    return false;
                }

                double additionalTime = previous.timeRequired( current );

                if ( notEntering  ||  i == parts.length-1 ) {
                    accumulatedSatisfaction -= additionalTime;
                    totalTime += additionalTime;
                } else {
                    accumulatedSatisfaction = accumulatedSatisfaction - additionalTime + current.S;
                    totalTime += additionalTime + minimumBarTime;
                }

            } else {

                if ( notEntering == false ) {
                    accumulatedSatisfaction += current.S;
                    totalTime += minimumBarTime;
                }
            }

            if ( totalTime > availableTime ) {
                System.out.printf( "Time required exceded\n" );
                return false;
            }

            previous = current;
        }

        if ( Math.abs( accumulatedSatisfaction - satisfactionObtained ) > 0.01 ) {
            System.out.printf( "Different satisfaction obtained: %f %f %f\n", accumulatedSatisfaction, satisfactionObtained, satisfaction );
            return false;
        }

        return true;
    }
}

public class BasicSolution
{
    public static void main( String args[] )
    {
        boolean wrongAnswer = false;
        try {
            Scanner input = new Scanner( System.in ).useLocale( Locale.US );

            boolean checkAllSolutions = false;
            String fileNameSolutions = null;
            Scanner solutionsFile = null;

            for( int i=0; i < args.length; i++ ) {
                if ( args[i].equals( "--check-all-solutions" ) ) {
                    checkAllSolutions = true;
                } else if ( args[i].equals( "--check-solutions" ) ) {
                    fileNameSolutions = args[++i];
                    solutionsFile = new Scanner( new File( fileNameSolutions ) ).useLocale( Locale.US );
                }
            }

            int mapNumber = 0;

            Map map = null;

            while( input.hasNext()  &&  !wrongAnswer ) {

                String str = input.next();

                if ( "MAP".equals( str ) ) {

                    map = new Map( input );

                    str = input.next();

                    if ( "ARRIVALS". equals( str ) == false )
                        throw new Exception( "Received \"" + str + "\" when expecting \"ARRIVALS\"!" );

                    if ( solutionsFile == null ) {
                        System.out.printf( "MAP %d\n", ++mapNumber );
                    } else {
                        solutionsFile.nextLine(); // Line with "MAP #" is ignored.
                    }


                } else {

                    String departureTime  = str;
                    String departurePlace = input.next();
                    String arrivalTime    = input.next();
                    String arrivalPlace   = input.next();
                    double satisfaction   = input.nextDouble();
                    input.nextLine();

                    if ( solutionsFile == null ) {

                        if ( checkAllSolutions ) {

                            System.out.printf( Locale.US, "ARRIVAL %s %s %s %s %.3f\n",
                                    departureTime, departurePlace,
                                    arrivalTime, arrivalPlace,
                                    satisfaction );

                            map.findAllPaths( departureTime, departurePlace, arrivalTime, arrivalPlace, satisfaction );
                        } else {
                            boolean targetReached = map.findPathOptimized( departureTime, departurePlace, arrivalTime, arrivalPlace, satisfaction );
                            if ( !targetReached ) System.out.println( "Impossible!" );
                        }

                    } else {

                        if ( solutionsFile.hasNext() ) {

                            String line = solutionsFile.nextLine().trim();
                            if ( line.startsWith( "ARRIVAL" ) ) line = solutionsFile.nextLine().trim();

                            wrongAnswer = !map.checkSolution( line, departureTime, departurePlace, arrivalTime, arrivalPlace, satisfaction );

                            if ( wrongAnswer ) System.out.println( "\n" + line );

                        } else {
                            wrongAnswer = true;

                            System.out.printf( "No line for the following: " );
                            System.out.printf( Locale.US, "ARRIVAL %s %s %s %s %.3f\n",
                                    departureTime, departurePlace,
                                    arrivalTime, arrivalPlace,
                                    satisfaction );
                        }
                    }
                }
            }
            if ( wrongAnswer ) {
                System.out.println( "WRONG ANSWER!" );
            }
        }
        catch( Exception e )
        {
            wrongAnswer=true;
        }

        try {
            if ( !wrongAnswer ) {
                PrintWriter ps = new PrintWriter( "result.xml" );

                ps.println( "<?xml version=\"1.0\"?>" );
                ps.println( "<!DOCTYPE result [" );
                ps.println( "<!ELEMENT result (#PCDATA)>" );
                ps.println( "<!ATTLIST result outcome CDATA #REQUIRED>" );
                ps.println( "]>" );
                ps.println( "<result outcome=\"Accepted\">Accepted</result>" );

                ps.close();
            }
        }
        catch( Exception e )
        {
            wrongAnswer=true;
        }
    }
}
