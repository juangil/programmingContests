#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cfloat>

using namespace std;

// velocidad km/h
#define SPEED 4.0 
// minutos dentro del local
#define INSIDE 15


#define MINIMO_ERROR 0.1

#define MAX_P 64

#define CADENA_MAX 20
typedef struct NODO{
    int num;
    double x;
    double y;
    double s;
    string id;

    bool operator() (const NODO &a, const NODO &b) {
        return a.id.compare(b.id);
    }
}NODO;

NODO lista[MAX_P];

double distances[MAX_P][MAX_P];

map<string,int> dict;
bool matAdy[MAX_P][MAX_P];
bool visitados[MAX_P];

/* Distancia en  Kilometros */
double euclidean(NODO p, NODO t) {
    return sqrt( pow(p.x - t.x, 2) + pow(p.y - t.y,2));
}

/* minutos */
double timeNodes(NODO p, NODO t) {
    double tiempo = euclidean(p,t) / SPEED;

    return tiempo * 60.0;
}

double timeNodes(int p1, int p2) {
    return  distances[p1][p2] * 60.0 / SPEED;
}

typedef struct State{
    bool visitados[MAX_P];
    int indicePrevio;
    int indiceActual;
    double timeDone;
    double satact;    
    string ruta;
    double priority;

}State;

class StateComparision {
    public:
    bool operator()(const State & a, const State &b) {
        return a.priority < b.priority;
    }
};

/* Floyd-Wharsall*/
void calculateDistances(int P) {

    for(int k=0;k< P;++k){
        for(int i =0; i<P;++i){
            for (int j=0;j<P;++j) {
                double dt = distances[i][k] + distances[k][j];
                if(distances[i][j] > dt) {
                    distances[i][j] = dt;
                }
            }
        }
    }

    return;
}

/* Valor de la heuristica */
double assignPriority(State &st, bool entra, int nodoDestino, double satFinal) {
    double value = st.priority + 1.0; // Depth search
    
    /* Heuristica -> Tiempo maximo 16 segundos Test4 */
    //value = st.priority - timeNodes(st.indicePrevio, nodoDestino); 
    value = -(fabs(satFinal - (st.satact - timeNodes(st.indicePrevio, nodoDestino)))); 

    return value;
}

/* devuelve la satisfaccion */
State search(bool visitados[], int nodoOrigen, int nodoDestino, int P, int satMax, int satActual, double totalTime){

    string rutaBest = "";
    double best = DBL_MAX; 
    State origen, bestState;
    for(int i=0;i<MAX_P;++i){
        origen.visitados[i] = false;
    }
    origen.indicePrevio = nodoOrigen;
    origen.satact = 0;
    origen.timeDone = 0.0;
    origen.priority = 0.0;
    origen.ruta =string("");

    bestState.timeDone = -1;

    priority_queue<State, vector<State>, StateComparision> cola;
    cola.push(origen);

    while(!cola.empty() ){
        State st = cola.top();
        cola.pop();

        if (st.indicePrevio == nodoDestino) {
            st.ruta += " ";
            st.ruta += lista[nodoDestino].id;

            if (st.timeDone > totalTime) continue;

            if ( fabs(st.satact - satMax) < fabs(best - satMax)) {
                best = st.satact;
                rutaBest = st.ruta;
                bestState = st;
            }
            if( fabs(st.satact - satMax) < MINIMO_ERROR  ) {
                bestState = st;
                return bestState; 
            }
            continue;
        }
        
        if (st.timeDone > totalTime) {
            continue;
        }

        int anterior = st.indicePrevio;
        double anteriorSat = st.satact;
        double anteriorTiempo = st.timeDone;
        double anteriorPriority = st.priority;
        string anteriorRuta = st.ruta;

        if (totalTime < st.timeDone + timeNodes(anterior, nodoDestino)) continue;

        for(int i=0;i<P;++i){
            if (i == anterior ) continue; 
            if (st.visitados[i]) continue; 
            
            if(matAdy[anterior][i]) {
                double tiempo = timeNodes(anterior,i);

                if (totalTime < st.timeDone + tiempo) {
                    continue; /* Podar */
                }

                /* Entra */
                if ( totalTime  >= st.timeDone + tiempo  + INSIDE ){ 
                    st.visitados[anterior] = true;
                    st.timeDone = anteriorTiempo + tiempo + INSIDE;
                    st.satact = anteriorSat - tiempo + lista[anterior].s;
                    st.indicePrevio = i;
                    st.ruta += " ";
                    st.ruta += lista[anterior].id;

                    st.priority = assignPriority(st, true, nodoDestino, satMax);

                    cola.push(st);
                    
                    /* restaurar valores */
                    st.satact = anteriorSat;
                    st.indicePrevio = anterior;
                    st.timeDone = anteriorTiempo;
                    st.ruta = anteriorRuta;
                    st.priority = anteriorPriority;
                }
                

                /* No entra */
                st.visitados[anterior] = true;
                st.timeDone = anteriorTiempo + tiempo ;
                st.satact = anteriorSat - tiempo ;
                st.indicePrevio = i;
                st.ruta += " !";
                st.ruta += lista[anterior].id;

                st.priority = assignPriority(st, false, nodoDestino, satMax);

                cola.push(st);

                /* restaurar valores */
                st.satact = anteriorSat;
                st.indicePrevio = anterior;
                st.timeDone = anteriorTiempo;
                st.ruta = anteriorRuta;
                st.priority = anteriorPriority;
            }
        }
    }

    return bestState;
}

int main(int arg, char *argv[]){
    
    int M, P;
    string impos("Impossible!");

    /* Quitar la palabra MAP */
    if (scanf("%*s") != 0) {
        return EXIT_FAILURE;
    }

    char clave[CADENA_MAX];
    char id1[CADENA_MAX], id2[CADENA_MAX];
    char s1[CADENA_MAX], s2[CADENA_MAX];

    int cases = 1;
    while(scanf("%d%d",&P, &M)!= EOF){
        
        /* Nodes */
        NODO n;
        for(int p = 0; p < P; ++p) {
            char ident[CADENA_MAX];
            if (scanf("%lf%lf%lf %s %*[^\n]",&n.x,&n.y,&n.s, ident) != 4 ) {
                return EXIT_FAILURE;
            }

            n.id = string(ident);
            dict[n.id] = p;
            lista[p] = n;

        }

        /* Paths */
        for(int i = 0; i < P ; ++i)
            for(int j = 0; j < P; ++j)
                matAdy[i][j] = false;

        /* Inicializar matriz distancias */
        for(int i=0;i<P;++i){
            for(int j=0;j<P;++j){
                if(i==j)
                    distances[i][j] = 0.0;
                else 
                    distances[i][j] = DBL_MAX; /* Infinito */
            }
        }

        for(int m= 0; m < M; ++m) {
            if (scanf("%s %s",s1, s2) != 2) {
                return EXIT_FAILURE;
            }
            int p1 = dict[s1];
            NODO n1 = lista[p1];
            int p2 = dict[s2];
            NODO n2 = lista[p2];

            //ady[ make_pair(p1,p2) ] = true;
            //ady[ make_pair(p2,p1) ] = true;

            distances[p1][p2] = euclidean(n1,n2);
            distances[p2][p1] = distances[p1][p2];

            matAdy[p1][p2] = true;
            matAdy[p2][p1] = true;

           // cout << s1 << " " << s2 << endl;

        }

        calculateDistances(P);

        /* buscar la palabra ARRIVALS */
        while( scanf("%s",clave) ) {
            if( strcmp(clave, "ARRIVALS") == 0 )
                break;
        }

        /* Arrivals */
        int h1, h2, m1, m2;
        double sat;

        printf("MAP %d\n",cases);
        State achieved;
        while( scanf("%d:%d %s %d:%d %s %lf", &h1, &m1, id1, &h2, &m2, id2, &sat) == 7) {
            bool impossible = false;
            /* Ejecutar algoritmo por cada caso */
            if(h2 < h1) h2+=24;
            double totalTime = (h2*60 + m2) - (h1*60 +m1);

            for(int i = 0; i < P; ++i){
                visitados[i] = false;
            }

            int p1 = dict[id1];
            int p2 = dict[id2];

            achieved = search(visitados, p1, p2, P, sat, 0, totalTime);

            if ( achieved.timeDone < 0) {
                impossible = true;
            } else  if ( fabs(sat - achieved.satact) > MINIMO_ERROR ) {
                impossible = true;
            }
    
            if (impossible) {
                printf("%s\n",impos.c_str());
            } else {
                printf("PATH FOUND: %.3lf %s\n", achieved.satact, achieved.ruta.c_str());
            }

        }

        ++cases;
        /* buscar la palabra MAP*/
        while( scanf("%s",clave) != EOF ) {
            if( strcmp(clave, "MAP") == 0 )
                break;
        }
        
    }

    return EXIT_SUCCESS;
}


