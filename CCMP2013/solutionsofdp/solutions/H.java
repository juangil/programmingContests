import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.Math;


class pack {


    public int cost;
    public int benefit;

    public pack(int c, int b) {
        this.cost = c;
        this.benefit = b;
    }

}



public class shares_0 {

    /**
     * @param args
     */
    static int gcd (int a, int b) {

        if (a<b) { 
            int x = a; 
            a = b; 
            b = x;
        }
        while (a%b>0) {
            int r = a%b;
            a = b; 
            b = r;
        }
        return b;

    }



    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        //Capital
        int C = sc.nextInt();
        //Number of shares
        int N = sc.nextInt();
        int P = sc.nextInt();
        //Number of packets


        int []pshares = new int[N]; //Price per share
        int []bshares = new int[N]; // Benefit per share

        int nP = 0;
        int totalCost = 0;
        int totalBenefit = 0;
        ArrayList<pack> packets = new ArrayList<pack>();

        // Read the price and the cost
        for (int i = 0; i < N; ++i) {
            int act = sc.nextInt();
            int tomorrow = sc.nextInt();
            pshares[i] =  act;
            bshares[i] =  tomorrow - act;
            
        }

        int mcd = 0;

        for (int p = 0; p < P; ++p) {
            // For each package compute the cost and benefit
            int n_acts = sc.nextInt();
            int cost = 0;
            int benefit = 0;

            for (int i = 0; i < n_acts; ++i) {

                int id  = sc.nextInt();
                int cant = sc.nextInt();

                cost += pshares[id - 1]*cant;

                int share_benefit = bshares[id - 1]*cant; 
                benefit += share_benefit; 


            }

            if (benefit <= 0 || cost > C ) continue;
            //			totalBenefit += benefit;
            //			totalCost += cost;


            packets.add(new pack(cost, benefit));
            //				packets[p].cost = cost;
            //				packets[p].benefit = benefit;
            //	
            if (nP > 0) {
                mcd = gcd(mcd, cost);

            }
            else {
                mcd = cost;

            }
            ++nP;
        }

        P = nP;
        for(int p = 0; p < P; ++p) {

            packets.get(p).cost /= mcd;

        }


        if (nP == 0) {
            System.out.println("0");
            return;
        }
        C = (int)Math.floor(C/mcd);
        //		//The algorithm

        //Matrix Vector
        int []Dact = new int[C+1];
        int []Dant = new int[C+1];

        for (int i = 0; i <= C; ++i) Dant[i] = 0;


        //Knapsack problem
        for (int p = 1; p <= P; ++p ) {

            for (int c = 0; c <= C; ++c ) {


                if (c >= packets.get(p-1).cost) {

                    if (Dant[c] >= (Dant[c-packets.get(p-1).cost] + packets.get(p-1).benefit)) {

                        Dact[c] = Dant[c];
                    }
                    else {
                        int cant = c - packets.get(p-1).cost;
                        Dact[c] = Dant[cant] + packets.get(p-1).benefit;
                    }



                }
                else{


                    Dact[c] = Dant[c];

                }


            }
            //Change the vect
            int []aux = Dant;
            Dant = Dact;
            Dact = aux;

        }


        int sol = Dant[C];
        System.out.println(sol);

        //		for(int s = 0; s < N; ++s) {
        //			System.out.println(L[P][C][s]);	
        //		}

    }


}


