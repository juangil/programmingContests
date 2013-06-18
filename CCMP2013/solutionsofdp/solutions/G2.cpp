#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

#define DISTANCE 10000
#define ESPACIOS 20
int I[DISTANCE + 2];
int N;
char fall [50];
char mayFall [50];

int main ( int argc, char *argv[] ){
    int D, P;
    
    sprintf(fall,"The spider is going to fall!");
    sprintf(mayFall,"The spider may fall!");

    while( scanf("%d%d", &D, &P) != EOF) {
        //printf("%d %d ",D,P);
        int cont = 0;char c;
        char espacios[ESPACIOS];
        while( (c = getchar()) != '\n' && c != EOF ) {
            ungetc( c, stdin );
            int aux  = 0;
            
            /* Para evitar los warnings... */
            if (scanf("%d",&I[cont]) != 1) {
                return EXIT_FAILURE;
            }
            if ((aux = scanf("%[ ]", espacios)) < 0) {
                // Puede haber cualquier cantidad de espacios
                // Cero o mas
                return EXIT_FAILURE;
            }

            ++cont;
        }

        /*for(int i=0;i<cont;++i) {
            printf("%d ",I[i]);
        }
        printf("\n");*/
        N  = cont;

        if ( P < I[0] ) {
            printf("%s\n",fall);
            continue;
        } 

        bool isRecurrence = true;
        int a = 1, b = 1;
        
        // Si la posicion 1 es cero, la posicion 0 tambien porque es creciente la secuencia
        // Si las dos posiciones son cero, no puede ser una recurrencia lineal
        if (I[1] == 0) { 
            isRecurrence = false;        
        } else {

            int num = I[3]*I[0] - I[2]*I[1];
            int den = I[2]*I[0] - I[1]*I[1];

            if (den == 0) {
                //printf("%d %d %d %d",I[0],I[1],I[2],I[3]);
                b = I[2]/I[1];
            } else {
                b = num/den;
            }
            if ( b * den != num) 
                isRecurrence = false;

            if (isRecurrence) {
                a = (I[3] - b * I[2] ) / I[1];
                /*Comprobar que es una recurrencia */
                for(int i = 2; i < N ; ++i) {
                    if (I[i] != (I[i-2]*a + I[i-1]*b)) {
                        isRecurrence = false;
                        break;
                    }
                }
            }

            /*if (isRecurrence) 
                printf(" YES\n");
            else
                printf(" NO\n");*/
        }

        
        if (N >=D || !isRecurrence) {
            /* Si no es recurrencia o hay los elementos necesarios... */
            N = min(N,D);
            if ( P >= I[N-1]) {
                printf("%s\n",mayFall);
                continue;
            }

            int d = D;
            for(int i=1;i<N && i < D;++i) {
                if (P < I[i]) {
                    break;
                }
                --d;
            }
            
            if (d == 0) {
                printf("%s\n",mayFall);
            } else {
                printf("%d\n",d);
            }

        } else {
            /* Si no hay todos los elementos necesarios */
            int a1 = I[0], a2= I[1], a3 = I[2];
            int d = 2;
            if (P < I[1]) {
                d = 0;
                printf("%d\n",D);
                continue;
            } 
            
            while(d < D && a3 <= P){
                a1 = a2;
                a2 = a3;
                a3 = a1*a + a2*b;
                ++d;
            }
            /* The previous is the minimum distance */
            --d;

            /* If d == D, it means that reach the end of the sequence */
            if ( d<D) {
                printf("%d\n",D-d);
            }else{
                printf("%s\n",mayFall);
            }
            
        }





    }
    return EXIT_SUCCESS;
}


