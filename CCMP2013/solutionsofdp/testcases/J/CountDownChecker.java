import java.util.*;
import java.io.*;

public class CountDownChecker
{
    private int objetivo,
                aproximacion;

    private ArrayList<Integer> disponiblesInput;
                    
    public CountDownChecker( String buffer )
    {
        sacaValoresChecking( buffer );
    }

    private void sacaValoresChecking( String buffer )
    {
        String partes[] = buffer.split( "\\s+" );
        int i=partes.length-1;

        this.aproximacion = Integer.parseInt( partes[i--] );
        this.objetivo = Integer.parseInt( partes[i--] );

        this.disponiblesInput = new ArrayList<Integer>();
        while( i >= 0 ) this.disponiblesInput.add( Integer.parseInt( partes[i--] ) );
    }
    private int [] extractAvailables( String buffer )
    {
        String partes[] = buffer.split( "\\s+" );
        int V[] = new int [101];

        int i=partes.length-1;

        while( i >= 0 ) {
            int valor = Integer.parseInt( partes[i--] );
            if ( 0 <= valor && valor < V.length ) V[ valor ]++;
        }

        return V;
    }

    public boolean compruebaCaso( Scanner sf )
    {
        String token = sf.next();

        if ( "Target:".equals( token ) == false ) {
            System.err.println( "Esperaba Target:" );
            return false;
        }

        int finalResult = sf.nextInt();


        int availables[] = null;
        int result = -finalResult;
        int bestApprox = -10*finalResult;
        boolean firstTime = true;
        while( sf.hasNext() ) {

            token = sf.next();

            if ( "Best".equals( token ) ) {

                token = sf.next();
                if ( "approx:".equals( token ) == false ) {
                    System.err.println( "Esperaba approx" );
                    return false;
                }

                bestApprox = sf.nextInt();

                break;

            } else if ( "Available:".equals( token ) ) {
                /*
                   availables = extractAvailables( sf.nextLine().trim() );

                   if ( firstTime ) {
                   firstTime=false;
                   for( int i=0; i < availables.length; i++ )
                   if ( availables[i] != this.disponiblesInput[i] ) {
                   System.err.println( "Availables diferentes!" );
                   return false;
                   }
                   if ( bestApprox <= 100 && availables[bestApprox] > 0 && this.disponiblesInput[bestApprox] > 0 )
                   result = bestApprox;
                   }
                 */

            } else {

                int A = Integer.parseInt( token );
                token = sf.next();
                char op = token.charAt(0);
                token = sf.next();
                int B = Integer.parseInt( token );
                token = sf.next();
                char assign = token.charAt(0);
                token = sf.next();
                int C = Integer.parseInt( token );

                switch( op ) {

                    case '+' : if ( A+B != C ) {
                                   System.err.printf( "%d + %d != %d\n", A, B, C );
                                   return false;
                               }
                               break;

                    case '-' : if ( A-B != C ) {
                                   System.err.printf( "%d - %d != %d\n", A, B, C );
                                   return false;
                               }
                               break;

                    case '*' : if ( A*B != C ) {
                                   System.err.printf( "%d * %d != %d\n", A, B, C );
                                   return false;
                               }
                               break;

                    case '/' : if ( A/B != C ) {
                                   System.err.printf( "%d / %d != %d\n", A, B, C );
                                   return false;
                               }
                               break;

                    default : 
                               System.err.println( "Operador erróneo: "  + op );
                               return false;
                }

                if ( this.disponiblesInput.contains( new Integer(A) ) == false ) {
                    System.err.printf( "Número %d ya no disponible!", A );
                    return false;
                } else {
                    this.disponiblesInput.remove( new Integer(A) );
                }

                if ( this.disponiblesInput.contains( new Integer(B) ) == false ) {
                    System.err.printf( "Número %d ya no disponible!", B );
                    return false;
                } else {
                    this.disponiblesInput.remove( new Integer(B) );
                }
                this.disponiblesInput.add( C );

                result = C;
            }
        }


        if ( this.disponiblesInput.contains( new Integer( bestApprox ) )
                && Math.abs( objetivo - bestApprox ) <= Math.abs( objetivo - aproximacion ) ) {
            return true;
        } else {
            System.err.printf( "%d == %d\n", result, bestApprox );
            return false;
        }
    }


    public static void main( String args[] )
    {
        try {

            if ( args.length != 2 ) {
                wrongAnswer();
                System.exit(-1);
            }


            Scanner outputProgram = new Scanner( new File( args[0] ) );
            Scanner checking      = new Scanner( new File( args[1] ) );

            boolean OK = true;

            while( OK && checking.hasNext() ) {
                
                String buffer = checking.nextLine();

                CountDownChecker cdc = new CountDownChecker( buffer );

                OK = cdc.compruebaCaso( outputProgram );
            }

            outputProgram.close();
            checking.close();

            writeResult( OK );
        }
        catch( Exception e ) 
        {
            e.printStackTrace( System.err );

            try { wrongAnswer(); } catch( Exception e2 ) {}
        }
    }

    private static void wrongAnswer() throws Exception { writeResult( false ); }
    private static void accepted()    throws Exception { writeResult( true ); }

    private static void writeResult( boolean ok )
        throws Exception
    {
        PrintWriter pw = new PrintWriter( "result.xml" );
        pw.println( "<?xml version=\"1.0\"?>" );
        pw.println( "<!DOCTYPE result [" );
        pw.println( "<!ELEMENT result (#PCDATA)>" );
        pw.println( "<!ATTLIST result outcome CDATA #REQUIRED>" );
        pw.println( "]>" );
        pw.printf( "<result outcome=\"%s\">%s</result>\n",
                                        ok ? "Accepted" : "Wrong Answer",
                                        ok ? "Accepted" : "Wrong Answer" );
        pw.close();
    }
}

