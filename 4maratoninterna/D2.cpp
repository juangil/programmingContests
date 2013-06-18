# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <cstring>
# define FR(i,n) for(int i = 0; i < (n); ++i)
# define fr(i,j,n) for(int i = j; i < n; ++i)
# define forDown(i,j) for(int i = j ; i > 0; i--)
using namespace std;

bool isGrow(char a, string target)
{
   FR(i, target.length()) if(target[i] == a) return true;
   return false;
}
   
   
   

int main()
{
   int a,b;
   while(cin >> a >> b and (a+b))
   {
      //cout<<a<<" -  "<<b<<endl;
      string target;
      cin >> target; //cadena de vitaminas
      char field [a][b]; // cultivo
      FR(i,a)
        scanf("%s", &field[i]); 
      int intImage [target.length()][a][b]; //arreglo de integral images para cada vitamina
      memset(intImage, 0, sizeof(intImage[0][0][0])); //no le ponga cuidado a esto 
      FR(j,target.length()){
           if(target[j] == field[0][0]) intImage [j][0][0] = 1; //seteo el valor de la primera posición dependiendo de la letra que este ahi
           else intImage [j][0][0] = 0;
      }
      fr(i,1,b){
        FR(j,target.length())
           if(target[j] == field[0][i]) intImage [j][0][i] =  intImage [j][0][i-1] + 1; //lleno la primera fila
           else intImage [j][0][i] =  intImage [j][0][i-1];
      }           
      fr(i,1,a){
        FR(j,target.length())
           if(target[j] == field[i][0]) intImage [j][i][0] =  intImage [j][i-1][0] + 1; //lleno la priemra columna
           else intImage [j][i][0] =  intImage [j][i-1][0];
      }
      fr(i,1,a){
        fr(h,1,b){
          //cout<<i<<" "<<h<<endl;
          FR(k,target.length()){
             if(field[i][h] == target[k]) intImage[k][i][h] = intImage[k][i-1][h] + intImage[k][i][h-1] - intImage[k][i-1][h-1] + 1; //lleno el resto de  las posiciones
             else intImage[k][i][h] = intImage[k][i-1][h] + intImage[k][i][h-1] - intImage[k][i-1][h-1];
          }
        }
      }     
      /*FR(i,target.length()){
         cout<<target[i]<<endl;
         FR(j,a){
           FR(k,b)
              cout<<intImage[i][j][k]<<" ";
           cout<<endl;
         }
         cout<<endl;
      }*/
      
      int area = 0;
      bool flag = false;
      forDown(i,a){ //supongo un tamaño
       forDown(j,b){
         area = i*j;
         //cout<<"tamaño: "<<i<<" "<<j<<endl;
         FR(k,a){ //supongo una posición sobre la matriz
           FR(m,b){
              if(k + (i-1) >= a || m + (j-1) >= b) break; //si me paso del tamañoi de la matriz no tomo esta posición como una válida
              int total = 0;
              //cout<<"empieza en: "<<k<<"-"<<m<<" termina en: "<<k+(i-1)<<"-"<<m+(j-1)<<endl;
              FR(l,target.length()){//calculo de cuantas letras de vitaminas ahay en un recuadro cualquiera
                 if(k==0 && m == 0) total += intImage[l][k+(i-1)][m+(j-1)];
                 else if(k==0 && m > 0) total += intImage[l][k+(i-1)][m+(j-1)] - intImage[l][k][m-1];
                 else if(m == 0 && k > 0) total += intImage[l][k+(i-1)][m+(j-1)] - intImage[l][k-1][m];
                 else total += intImage[l][k+(i-1)][m+(j-1)] - intImage[l][k-1][m] - intImage[l][k][m-1] + intImage[l][k-1][m-1];
                 //cout<<" valor "<<l<<" : "<<intImage[l][k+(i-1)][m+(j-1)]<<" "<<intImage[l][k+(i-1) - 1][m+(j-1)]<<" "<<intImage[l][k+(i-1)][m+(j-1) - 1]<<" "<<intImage[l][k][m];//
                 
              }
              //cout<<total<<endl;
              if(total == i*j){//si el numerod e vitaminas en un recuadro esw igual al area listo.
                 flag = true;
                 break;
              }
           }
           //cout<<endl;
           if(flag) break;
         }
         if(flag) break;
       }
       if(flag) break;
      }
      cout<<area<<endl;
  }
  return 0;
}
      
              
          
      
      
      
      
            
          
        
           
      
      
      
      
      
      
      
      
      
      
