#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>

#define MAX_LINE 100000
using namespace std;



int main() {


    int D, P;
    char line[MAX_LINE];
    int elem = 0;
    int V[20000];
    int F[20000];



    while(scanf("%d %d", &D, &P) == 2) {

        gets(line);

        //printf("D: %d P: %d\n",D, P);
        //printf("Line: %s\n",line);

        //isstream 
        //
        stringstream ss(line);

        elem = 0;
        while (ss >> V[elem++]);

//        for (int i = 0; i < elem; ++i) {
//            printf("%d ",V[i]);

//        }
        
        //The algorithm
        //
        if (elem == D+2)
            for (int i = 0; i <= D; ++i) F[i] = V[i];

        else if( V[3] == 0) {
            printf("The spider may fall!\n");
            continue;
        }
        else {
          // Generate the sequence
          int x0 = V[0];
          int x1 = V[1];
          int x2 = V[2];
          int x3 = V[3];
          
          int num = x3*x0 - x1*x2;
          int den = x2*x0 - x1*x1;

          float alpha = 0.0;
          if (den == 0) {
            alpha = x2/x1;
          }
          else {
            alpha = num/den;
          }
          float beta = (x3-alpha*x2)/x1;

          F[0] = x0;
          F[1] = x1;
          F[2] = x2;
          F[3] = x3;
          

          for (int i = 4; i <= D; ++i){
            F[i] = beta*F[i-2] + alpha*F[i-1];
          }
        
        //  for(int i = 0; i <= D; ++i)
        //      printf("%d ", F[i]);
        }
        //Compute the solution

        if (F[0] > P) {
          printf("The spider is going to fall!\n");
          continue;
        }
        
       int found = 0;
       for (int i = 0; i <= D; ++i) {
          if (F[i] > P) {
             printf("%d\n",D-i+1);
             found = 1;
             break;
          }

       } 
       
       if (!found)
         printf("The spider may fall!\n"); 


    }
    return EXIT_SUCCESS;
}
