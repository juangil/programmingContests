/* problema cookie
las observaciones claves son las siguientes:

1) Todos los pol�gonos que se forman dentro de la galleta son convexos.
2) cada pol�gono que es "atravesado" por un cut puede a lo sumo dividirse en otros dos pol�gonos convexos(debido a que el pol�gono original es convexo).

Entonces el algoritmo consiste en mantener los pol�gonos que se forman en la galleta hasta el cut i-�simo, para tener los pol�gonos despu�s del cut (i+1) entonces se cogen cada uno de los pol�gonos despu�s del cut (i) y se mira si se intersectan con la linea que representa el cut (i+1) , si no se intersectan entonces el pol�gono continua as� (completo), si se intersectan entonces ese pol�gono se divide en dos nuevos pol�gonos. Para hallar los dos pol�gonos resultantes se us� una ligera modificaci�n del algorimto de Sutherland�Hodgman[1] (el cual me pareci� muy elegante e intuitivo). Es importante aclarar que al inicio el �nico pol�gono es la galleta.

Finalmente , despu�s de procesar todos los cut's entonces se tienen todos los pol�gonos formados y ya se pueden usar los algoritmos de la ancheta para saber si un punto (galleta) est� dentro de un pol�gono y para calcular el �rea del mismo.

En cuanto a complejidad, la construcci�n de los pol�gonos es aproximadamente O(n^2) (sin tener en cuenta que la "intersecci�n" de la recta con un pol�gono implica recorrer las aristas de este), donde n representa la cantidad de pol�gonos que se forman al final. Y la parte de mirar si las galletas est�n dentro de cada pol�gono es aproximadamente O(n*c), donde c representa la cantidad de galletas.

Si no estoy equivocado en el peor de los casos n est� entre 600 y 700, en todo caso la soluci�n corri� en 1.4 segundos.

[1]http://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm

Nos hablamos y si tienen alguna inquietud no duden en compartirla*/
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class cookie {
	
	static class point{
		double x,y;
		public point(double xx,double yy){
			x=xx;
			y=yy;
		}
		public point sub(point a){
			return new point(x - a.x,y - a.y);
		}
		public point add(point a){
			return new point(x + a.x,y + a.y);
		}
		public double cross(point a){
			return x*a.y - y*a.x;
		}
		public point multbyscalar(double ua) {
			return  new point(ua*x,ua*y);
		}
	}
	
	
	static point intersectionbtwlines(point p1,point p2,point p3,point p4){
		point p2_p1=p2.sub(p1);
		point p4_p3=p4.sub(p3);
		double den=p2_p1.cross(p4_p3);
		if (Math.abs(den)<eps)//the lines are parallel or coincident
			return null;
		point p1_p3=p1.sub(p3);
		double num=p4_p3.cross(p1_p3);
		double ua=num/den;
		return p2_p1.multbyscalar(ua).add(p1);
	}
	
	
	static double eps=1e-7;
	
	static point[] sutherland_hodgman(point[]  line,point[] poly,int flag){
		ArrayList<point> output=new ArrayList<point>();
		point S=poly[poly.length-1];
		for(int i=0;i<poly.length;i++){
			point E=poly[i];
			double ecross=line[1].sub(line[0]).cross(E.sub(line[0]));
			double scross=line[1].sub(line[0]).cross(S.sub(line[0]));
			if (Math.abs(ecross)<eps)
				output.add(E);
			else if (ecross*flag>eps){
				if (scross*flag<-eps)
					output.add(intersectionbtwlines(line[0],line[1],S,E));
				output.add(E);
			}
			else if(scross*flag>eps)
				output.add(intersectionbtwlines(line[0],line[1],S,E));
			S=E;
		}
		point[] ret=new point[output.size()];
		return output.toArray(ret);
	}
	
	static point[][] bisection(point[] line, point[] poly){
		point[] uno=sutherland_hodgman(line,poly,1);
		point[] dos=sutherland_hodgman(line,poly,-1);
		int amount=(uno.length>2)?1:0;
		amount+=(dos.length>2)?1:0;
		point[][] ret=new point[amount][];
		int index=0;
		if (uno.length>2)
			ret[index++]=uno;
		if (dos.length>2)
			ret[index++]=dos;
		return ret;
	}
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner() throws FileNotFoundException{
			br = new BufferedReader(new FileReader("cookie.in"));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException {
			return Double.valueOf(next());
		}
	}
	
	
	static int L,S,K;
	
	static point[] initpoly(int L){
		point[] ret=new point[4];
		ret[0]=new point(0,0);
		ret[1]=new point(L,0);
		ret[2]=new point(L,L);
		ret[3]=new point(0,L);
		return ret;
	}
	
	static double polygonarea(point[] a, int n){
		double r=0;
		for(int i=0;i<n;i++)
			r+=a[i].cross(a[(i+1)%n]);
		return Math.abs(r/2.0);
	}
	
	
	static double ccw(point a,point b,point c){
		return a.sub(b).cross(c.sub(b));
	}
	
	static boolean insidepolygon(point[] p , int n,point t){
		int mask=0;
		for(int i=0;i<n;i++){
			double z=ccw(p[i],p[(i+1)%n],t);
			if (Math.abs(z)<eps)
				return false;
			else if (z<0)
				mask |= 1;
			else if (z>0)
				mask |= 2;
			if (mask==3)
				return false;
		}
		return true;
	}
	
	static void dbg(point[] a){
		System.out.println("===");
		for(int i=0;i<a.length;i++)
			System.out.println(a[i].x+" "+a[i].y);
		System.out.println("===");
	}
	
	
	static point[] chips=new point[5010];
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc=new Scanner();
		while(true){
			L=sc.nextInt();
			S=sc.nextInt();
			K=sc.nextInt();
			if (L==0) return;
			for(int i=0;i<S;i++)
				chips[i]=new point(sc.nextInt(),sc.nextInt());
			point[] p=initpoly(L);
			ArrayList<point[]> array=new ArrayList<point[]>();
			array.add(p);
			ArrayList<point[]> tmp;
			for(int i=0;i<K;i++){
				tmp=new ArrayList<point[]>();
				point[] line=new point[2];
				line[0]=new point(sc.nextInt(),sc.nextInt());
				line[1]=new point(sc.nextInt(),sc.nextInt());
				for(point[] poly: array){
					point[][] result=bisection(line, poly);
					for(int j=0;j<result.length;j++)
						tmp.add(result[j]);
				}
				array=tmp;
				//dbg
				/*
				for(point[] poly: array)
					dbg(poly);*/
			}
			double max=-1;
			for(point[] poly: array){
				//dbg(poly);
				int nchips=0;
				for(int i=0;i<S;i++)
					if (insidepolygon(poly,poly.length,chips[i]))
						nchips++;
				double area=polygonarea(poly,poly.length);
				double value=nchips/area;
				max=Math.max(max, value);
			}
			System.out.printf("%.3f\n",max);
		}
	}
}
