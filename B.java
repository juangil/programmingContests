import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class B {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
	}
	
	static double eps=1e-8;
	
	static boolean igual(double a,double b){
		return Math.abs(a-b)<eps;
	}
	
	static class point{
		double x,y;
		int reference;
		LinkedList<point> vecinos=new LinkedList<point>();
		public point(double xx,double yy){
			x=xx;
			y=yy;
			reference=-1;
		}
		boolean igual(point a){
			return Math.abs(x-a.x)<eps && Math.abs(y-a.y)<eps;
		}
		point resta(point a){
			return new point(x-a.x,y-a.y);
		}
		double cross(point a){
			return x*a.y - y*a.x;
		}
		double dot(point a){
			return x*a.x + y*a.y;
		}
		double norm(){
			return Math.sqrt(this.dot(this));
		}
		double angle(point a){
			return Math.acos(this.dot(a)/(this.norm()*a.norm()));
		}
		public String toString(){
			return "("+ x +","+ y +")";
		}
	}
	
	static class edge{
		point a,b;
		boolean visited;
		int boundarie;
		public edge(double xx,double yy,double x,double y){
			a=new point(xx,yy);
			b=new point(x,y);
			boundarie=0;
			visited=false;
		}
	}

	static edge[] array=new edge[210];
	static int[] ans=new int[210];
	
	
	
	static point seleccionar(point a,point b){
		point ret=null;
		point vector=b.resta(a);
		double medida=0;
		for(point v: b.vecinos){
			if (v.igual(a))
				continue;
			point t=v.resta(b);
			if (vector.cross(t)>eps)
				continue;
	        double angulo=vector.angle(t);
			if (ret==null || angulo<medida){
				ret=v;
				medida=angulo;
			}
		}
		medida=-1;
		for(point v: b.vecinos){
			if (v.igual(a))
				continue;
			point t=v.resta(b);
			if (vector.cross(t)<eps)
				continue;
	        double angulo=vector.angle(t);
			if (ret==null || angulo>medida){
				ret=v;
				medida=angulo;
			}
		}
		return ret;
	}
	
	static int traversal(point p, point parada,point papa){
		System.out.println(p);
		if (p.igual(parada))
			return 1;
		array[p.reference].visited=true;
		point sig=seleccionar(papa,p);
		return 1+traversal(sig,parada,p);
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc=new Scanner();
		int minx=Integer.MAX_VALUE;
		int miny=Integer.MAX_VALUE;
		int maxx=Integer.MIN_VALUE;
		int maxy=Integer.MIN_VALUE;
		for(int c=0;true;c++){
			int N=sc.nextInt();
			if (N==0)
				break;
			for(int i=0;i<210;i++)
				ans[i]=0;
			for(int i=0;i<N;i++){
				array[i]=new edge(sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt());
				array[i].a.reference=i;
				array[i].b.reference=i;
				minx=Math.min( Math.min(minx,(int) array[i].a.x),(int)array[i].b.x);
				miny=Math.min( Math.min(miny,(int) array[i].a.y),(int)array[i].b.y);
				maxx=Math.max( Math.max(maxx,(int) array[i].a.x),(int)array[i].b.x);
				maxy=Math.max( Math.max(maxy,(int) array[i].a.y),(int)array[i].b.y);
			}
			for(int i=0;i<N;i++){
				if (igual(array[i].a.x,array[i].b.x) && igual(array[i].a.x,minx))
					array[i].boundarie=1;
				if (igual(array[i].a.x,array[i].b.x) && igual(array[i].a.x,maxx))
					array[i].boundarie=3;
				if (igual(array[i].a.y,array[i].b.y) && igual(array[i].a.y,miny))
					array[i].boundarie=2;
				if (igual(array[i].a.y,array[i].b.y) && igual(array[i].a.y,maxy))
					array[i].boundarie=4;
			}
			
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if (array[i].a.igual(array[j].a)){
						array[i].a.vecinos.add(array[j].b);
					}
					if (array[i].a.igual(array[j].b)){
						array[i].a.vecinos.add(array[j].a);
					}
					if (array[i].b.igual(array[j].b)){
						array[i].b.vecinos.add(array[j].a);
					}
					if (array[i].b.igual(array[j].a)){
						array[i].b.vecinos.add(array[j].b);
					}
				}
			}
			
			/*
			for(int i=0;i<N;i++){
				System.out.println(array[i].a);
				System.out.println("vecinos"+array[i].a.vecinos);
				System.out.println(array[i].b);
				System.out.println("vecinos"+array[i].b.vecinos);
			}
			point sig=seleccionar(array[4].a,array[4].b);
			ans[traversal(sig,array[4].b,array[4].b)]++;*/
			
			
			
			for(int i=0;i<N;i++){
				if (array[i].boundarie==0)
					continue;
				if (array[i].visited)
					continue;
				array[i].visited=true;
				if (array[i].boundarie==1){
					if (array[i].a.y<array[i].b.y){
						point sig=seleccionar(array[i].b,array[i].a);
						ans[traversal(sig,array[i].a,array[i].a)]++;
					}
					else{
						point sig=seleccionar(array[i].a,array[i].b);
						ans[traversal(sig,array[i].b,array[i].b)]++;
					}
				}
				if (array[i].boundarie==2){
					if (array[i].a.x<array[i].b.x){
						point sig=seleccionar(array[i].a,array[i].b);
						ans[traversal(sig,array[i].b,array[i].b)]++;
					}
					else{
						point sig=seleccionar(array[i].b,array[i].a);
						ans[traversal(sig,array[i].a,array[i].a)]++;
					}
				}
				if (array[i].boundarie==3){
					if (array[i].a.y<array[i].b.y){
						point sig=seleccionar(array[i].a,array[i].b);
						ans[traversal(sig,array[i].b,array[i].b)]++;
					}
					else{
						point sig=seleccionar(array[i].b,array[i].a);
						ans[traversal(sig,array[i].a,array[i].a)]++;
					}
				}
				if (array[i].boundarie==4){
					if (array[i].a.x<array[i].b.x){
						point sig=seleccionar(array[i].b,array[i].a);
						ans[traversal(sig,array[i].a,array[i].a)]++;
					}
					else{
						point sig=seleccionar(array[i].a,array[i].b);
						ans[traversal(sig,array[i].b,array[i].b)]++;
					}
				}
			}
			for(int i=0;i<15;i++)
				System.out.print(" "+ans[i]);
			System.out.println();
		}
		
	}
	
}
