import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Node {
	
	
	public ArrayList<Integer> values;
	public int computed;
	public int score;
	Node ant;
	int vi;
	int vj;
	public int op;
	
	public Node(ArrayList<Integer> values, int target, Node ant, int vi, int vj, int op) {
		this.values = values;
		this.computeScore(target);
		this.ant = ant;
		this.vi = vi;
		this.vj = vj;
		this.op = op;
			
	}
	
	public String available() {
		String str = "Available:";
		for (int v: this.values) {
			str+= " "+v;
		}		
		return str;
	}
	public String toString() {
				return ""+computed;
	}
	
	public String getOps() {
		if (op == 0)
			return String.format("%d + %d = %d", vi, vj, vi+vj);
		if (op == 1)
			return String.format("%d - %d = %d", vi, vj, vi-vj);
		if (op == 2)
			return String.format("%d * %d = %d", vi, vj, vi*vj);
		if (op == 3)
			return String.format("%d / %d = %d", vi, vj, vi/vj);
		
		
		return "";
	}
	public void computeScore(int target) {
		
		int bestScore = target;
		int best = 0;
		for (int v: this.values) {
			int dif = Math.abs(target - v);
			if (dif < bestScore) {
				bestScore = dif;
				best = v;
				
			}
		}
		
		this.computed = best;
		this.score    = bestScore; 
		
		}
		
}




public class countdown_joan {

	static int best;
	static int bestScore;
	static Node bestNode;
   	
	public static ArrayList<Integer> combineValues(ArrayList<Integer> values, int i, int j, int value) {
		ArrayList<Integer> newArray = new ArrayList<Integer>();
		
		for (int v = 0; v < values.size(); ++v ){
			
			if (v != i && v != j) {
				newArray.add(values.get(v));
			}
			
			
		}
		newArray.add(value);
		
		return newArray;
	}
    
	
	// Takes a solution and generates all the posibles solution
	static public boolean exploreSolution(Node solution, Stack<Node> solutions, int target) {
	
		int n = solution.values.size();
		
		
		if (n == 1)
			return false;
		//Take all pairs of numbers
		for (int i = 0; i < n; ++i){
			for (int j = i+1; j < n; ++j) {
				int vi = solution.values.get(i);
				int vj = solution.values.get(j);
				int vn = 0;
				
				//Addition
				vn = vi + vj;
				
					
				ArrayList valuesAdd = combineValues(solution.values, i, j, vn);
				
				
				
				Node add = new Node(valuesAdd, target, solution,vi,vj,0);
				
				
				if (add.score == 0) {
					best = add.computed;
					bestScore = add.score;
					bestNode = add;
					return true;
					
				}
				if (add.score < bestScore) {
					best = add.computed;
					bestScore = add.score;
					bestNode = add;
					
				}
				
				solutions.add(add);
				
				if (vj > vi){
					int aux = vi;
					vi = vj;
					vj = aux;
					
				}
					
				//Substraction
				vn = vi - vj;
				
				if (vn != 0 ){
				ArrayList valuesSub = combineValues(solution.values, i, j, vn);
				
			
				Node sub = new Node(valuesSub, target,solution, vi, vj, 1);
								
				if (sub.score == 0) {
					best = sub.computed;
					bestScore = sub.score;
					bestNode = sub;
					return true;
					
				}
				if (sub.score < bestScore) {
					best = sub.computed;
					bestScore = sub.score;
					bestNode = sub;
					
				}
				
				solutions.add(sub);
				}
				//Multiply
				vn = vi * vj;
				
				ArrayList valuesMult = combineValues(solution.values, i, j, vn);
				
				Node mult = new Node(valuesMult, target, solution, vi, vj, 2);
				
				
				if (mult.score == 0) {
					best = mult.computed;
					bestScore = mult.score;
					bestNode = mult;
					return true;
					
				}
				if (mult.score < bestScore) {
					best = mult.computed;
					bestScore = mult.score;
					bestNode = mult;
				}
				
				solutions.add(mult);
				//Division
				if (vj > vi) {
					int aux;
					aux = vi;
					vi = vj;
					vj = aux;
					
				}
				
				if (vi % vj == 0) { 
				vn = vi/vj;
				
				ArrayList valuesDiv = combineValues(solution.values, i, j, vn);
				
				Node div = new Node(valuesDiv, target, solution, vi, vj, 3);
				
				
				if (div.score == 0) {
					best = div.computed;
					bestScore = div.score;
					bestNode = div;
					return true;
					
				}
				if (div.score < bestScore) {
					best = div.computed;
					bestScore = div.score;
					bestNode = div;
					
				}
				
				solutions.add(div);
				}
			}
		
		}
		return false;
	}
	
	
	
        public static void main(String[] args) {

            Scanner sc = new Scanner(System.in);

            int n_cases = sc.nextInt(); 
            for(int c = 0; c < n_cases; ++c) {

                if(c != 0)
                    System.out.println();
                ArrayList<Integer> values = new ArrayList<Integer>();
                for (int i = 0; i < 6; ++i) {
                    values.add(sc.nextInt());

                }

                int target = sc.nextInt();



                //Create the search list
                Stack<Node> solutions = new Stack<Node>();
                Node first = new Node(values, target, null,0,0, -1);
                best = first.computed;
                bestScore = first.score;
                bestNode = first;
                solutions.push(first);     

                boolean exact = false;

                int explored = 0;
                while(!exact && !solutions.isEmpty()) {

                    Node solution = solutions.pop();
                    explored++;

                    exact = exploreSolution(solution, solutions, target);

                    //System.out.println(String.format("Explored %d. Stack: %d. Best: %d Target: %d",
                    //		explored, solutions.size(), best, target));

                }
                //System.err.println(String.format("Explored %d. Stack: %d. Best: %d Target: %d",
                //            explored, solutions.size(), best, target));

                
                //System.out.println(bestNode.toString());
                
                System.out.println(String.format("Target: %d", target));
                
                //Reconstruir el camino
                Stack<Node> path = new Stack<Node>();
                Node current = bestNode;
                while (current != null) {
                	path.add(current);
                	current = current.ant;
                }
                 while (!path.empty()) {
                	current = path.pop();
                	
                	if (current.op != -1) {
                		System.out.println(current.getOps());
                		
                	}
                	               	
                }
                 System.out.println(String.format("Best approx: %d", best));
                	
            }
        }
}


