import java.util.AbstractQueue;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

import java.lang.Math;


class graph {

	ArrayList<Integer> []adj;
	boolean []vis;
	int []parent;
	int []cost;
	int m = 0;

	graph(int n) {
		adj = new ArrayList[n];

		
		vis = new boolean[n];
		parent = new int[n];
		cost = new int[n];

		for (int i = 0; i < n; ++i) {
			adj[i]  = new ArrayList<Integer>();
			vis[i]  = false;
			cost[i] = 0;

		}
	}


	void addEdge(int u, int v) {
		adj[u].add(v);
		adj[v].add(u);
		++m;
	}


}

public class solucion_joan {

	/**
	 * @param args
	 */




	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		//Capital
		int T = sc.nextInt();
		int n = 0;
		int m = 0;
		int u = 0;
		int v = 0;


		for (int t = 0; t < T; ++t) {

			n = sc.nextInt();
			m = sc.nextInt();		
			graph myGraph = new graph(n);

			for(int i = 0; i < m; ++i) {
				u = sc.nextInt();
				v = sc.nextInt();
				myGraph.addEdge(u,v);


			}

			int inf = 12345;
			int best = inf;
			for(int x = 0; x < n; ++x) {
				for (int i = 0; i < n; ++i) myGraph.vis[i] = false;
				
				myGraph.vis[x] = true;
				myGraph.cost[x] = 0;
				myGraph.parent[x] = -1;
			    Queue<Integer> q = new ArrayDeque<Integer>();
				q.add(x);

				boolean found = false;

				while (!found && !q.isEmpty()) {
					int e = q.poll();

					for(int a : myGraph.adj[e]) {
						if ( a == myGraph.parent[e])
							continue;

						if (!myGraph.vis[a]) {
							myGraph.parent[a] = e;
							myGraph.vis[e]    = true;
							myGraph.cost[a]   = myGraph.cost[e]+1;
							q.add(a);
						}
						else {
							best = Math.min(best, myGraph.cost[e]+myGraph.cost[a]+1);
							found = true;
							break;
						}
					}
				}

				if (best == 3)
					break;


				

			}
			if (best == inf) {

				System.out.println(String.format("Case %d: impossible",t+1));
			}
			else
				System.out.println(String.format("Case %d: %d",t+1,best));

		}
	}
	

	//
}





