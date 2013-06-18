import java.util.Scanner;

public class solucion_joan {



  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int cases = sc.nextInt();
    sc.nextLine();

    for (int c = 0; c < cases; ++c) {
        String orig = sc.nextLine();
        String dest = sc.nextLine();
        int N = orig.length();
        int A, B, C, D, E, F;
        A = B = C = D = E = F = 0;

        for(int i = 0; i < N ; ++i){
            if(orig.charAt(i) == '0') {
                if(dest.charAt(i) == '0')  ++A;


                else ++B;


            }
            else if(orig.charAt(i) == '1') {

                if(dest.charAt(i) == '0')  ++C;


                else ++D;

            } 
            else {

                if(dest.charAt(i) == '0')  ++E;


                else ++F;

            }



        }
        int sol = 0;

        //Se intercambian los 1 y los 0
        if (B == C) {
            sol += B;
            B = 0;
            C = 0; 

        }
        else if(B > C) {
          sol+=C;
          B = B - C;
          C = 0;
          

        }
        else {
          sol += B;
          C = C - B;;
          B = 0;
        }
        
        // Se pasan los 0 a los 1 
        if (B > 0) {
           sol += B;
           sol += E + F;
                
        }
        else {
            
            if (F < C)
                sol = -1;
            else {
                //Se cambian los 1s por ?
                sol += C;
                E -= C;
                //Se cambian los ?s por 0
                sol += C;
                sol += E + F;

            }
        } 

        //Se cambian los 0 a 1
        System.out.println("Case "+(c+1)+": "+sol);
    }//case


  }

}



