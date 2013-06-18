#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MAX = 1001;
const int MAXINT = 1000000000;
 
int n;
vvii G(MAX);//my grafo modelado como una lista de adyacencia
vi D(MAX, MAXINT);//vector que me indica la distancia más de un source a todos los nodos
 
void Dijkstra(int s)//distancia de un nodo s a todos los nodos diferentes.
{
    set<ii> Q; //genero una cola de prioridad usando un set.
    D[s] = 0;//la distancia hacia mi mismo es cero
    Q.insert(ii(0,s));// inserto en la cola mi elemento de inicio
 
    while(!Q.empty())
    {
        ii top = *Q.begin();//saco de la cola el primer elemento
        Q.erase(Q.begin());//lo elimino de la cola
        int v = top.second;//numero del vertice
        int d = top.first;//la distancia a mi nodo top
 
        for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++)//me muevo por todos los vecinos de top
        {
            int v2 = it->first;//nodo vecino de top
            int cost = it->second;//distancia al nodo top desde v2
            if (D[v2] > D[v] + cost)//si la distancia a v2 desde ese es mayor que la distancia a su padre mas el costo
            {
                if (D[v2] != 1000000000)//si el costo ya habia sido modificado
                {
                    Q.erase(Q.find(ii(D[v2], v2)));//elimine de la cola a v2, por que no me sirve.
                }
                D[v2] = D[v] + cost;//tenga ese nuevo costo ahi.
                Q.insert(ii(D[v2], v2));//inserte en la cola el vertice v2 con distancia v2
            }
        }
    }
}
 
int main()
{
    int m, s, t = 0;
    scanf("%d %d %d %d", &n, &m, &s, &t);
 
    for (int i = 0; i < m; i++)
    {
        int a, b, w = 0;
        scanf("%d %d %d", &a, &b, &w);
        G[a - 1].push_back(ii(b - 1, w));
        G[b - 1].push_back(ii(a - 1, w));
    }
 
    Dijkstra(s - 1);
 
    printf("%d\n", D[t - 1]);
 
    return 0;
}
