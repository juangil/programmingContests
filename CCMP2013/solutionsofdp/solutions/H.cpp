#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

typedef struct Accion {
    int compra; /* today */
    int venta;  /* tomorrow */
}Accion;

typedef struct AccionPaquete{
    int id; //Accion share;
    int num;
} AccionPaquete;

typedef struct Paquete {
   // vector<AccionPaquete> packet;  
    long long int profit;
    long long int cost;
}Paquete;


/*  Estructura archivo */
/* 
Capital
#Paquetes #Acciones
c_i v_i      //Por cada accion el precio de compra y el de venta (dia siguiente)
l_i          // Limite para el numero de acciones de cada tipo i
n_j a_i an_i // Por cada paquete n_j es el numero de acciones que contiene dicho paquete
             // En la misma linea por cada accion del paquete, 
             // se indica el indice de la accion a_i
             // y el numero de acciones de ese tipo que contiene an_i
*/
long long int calculate_gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return calculate_gcd (b, a % b);
    /*if (a<b) { 
        long long int x = a; 
        a = b; 
        b = x;
    }
    long long int r = 0;
    while (a%b>0) {
        r = a%b;
        a = b; 
        b = r;
    }
    return b;*/
}

long long int *shares_dyn_act, *shares_dyn_prev, *shares_dyn_aux;

int main( int argc, char*argv[]) {
    /* Reading and Post-processing */
    long long int capital;
    if (scanf("%lld", &capital) != 1) return EXIT_FAILURE;

    int acciones ; 
    if (scanf("%d",&acciones) != 1) return EXIT_FAILURE;

    int paquetes ;
    if (scanf("%d",&paquetes) != 1) return EXIT_FAILURE;

    vector<Accion> shares;
    
    for (int i = 0; i < acciones; ++i) {
        Accion a;
        if ( scanf("%d%d",&a.compra, &a.venta) != 2) return EXIT_FAILURE;

        shares.push_back(a);
    }

    vector<Paquete> packets;    
    long long int gcd = -1;
    for (int i = 0; i < paquetes; ++i) {
        int num ; 
        if (scanf("%d",&num) != 1) return EXIT_FAILURE;
        Paquete p;
        p.profit = 0;
        p.cost = 0;
        for (int j=0;j<num;++j) {
            AccionPaquete a;
            int aux;
            if (scanf("%d%d", &aux, &a.num) != 2) return EXIT_FAILURE;
            a.id = aux-1;
            //p.packet.push_back(a);
            
            /* price -> beneficio por la venta de las acciones */
            p.profit += (long long int) a.num * (shares[a.id].venta - shares[a.id].compra); 
            /* weight -> precio de la compra */
            p.cost += (long long int )a.num * shares[a.id].compra;  
        }
        /* Si es cero, utilizas dinero y no consigues nada 
        Si es negativo, utilizas dinero y pierdes beneficio */
        if (p.profit <= 0) continue;
        if (p.cost > capital) continue;
        if (p.cost < 0 ) {
            cout << "Problema " << p.cost << endl;
        }
        packets.push_back(p);
        //cout << p.cost << " " << p.profit <<endl;

        if(gcd == -1){
            gcd = p.cost;
        } else {
            if (p.cost >= 0) {
                gcd = calculate_gcd(gcd, p.cost);
            }
        }
    }

    // cout << "Packets "<< packets.size()<<" GCD " << gcd << endl;
    if (packets.size() == 0) {
        printf("0\n");
        return EXIT_SUCCESS;
    }

    /* Initialization knapsack problem */
    long long int newCapital = capital/gcd;

    shares_dyn_prev = (long long int *) calloc (newCapital + 1, sizeof(long long int));
    if (shares_dyn_prev == NULL ) {
        cout << "Problema 3"<<endl;
        return EXIT_FAILURE;
    }
    shares_dyn_act = (long long int *) calloc (newCapital + 1, sizeof(long long int));
    if (shares_dyn_act == NULL ) {
        cout << "Problema 4"<<endl;
        return EXIT_FAILURE;
    }

    /* Knapsack Problem */
    long long int cost, newcost, costeAnt;
    for (int i = 1; i <= (int)packets.size(); ++i) {
        cost = gcd;
        newcost = packets[i-1].cost/gcd;
        for (long long int j = 1; cost <= capital && j <= newCapital; ++j) {
            costeAnt = j - newcost;

            if ( cost < packets[i-1].cost ) {
                shares_dyn_act[j] = shares_dyn_prev[j];
            } else {
                /* check shares limit */
                if (shares_dyn_prev[j] < shares_dyn_prev[costeAnt] + packets[i-1].profit) {
                    shares_dyn_act[j] = shares_dyn_prev[costeAnt] + packets[i-1].profit;
                    if (shares_dyn_act[j] < 0) {
                        cout << " Problema " << shares_dyn_act[j] << endl;
                    }
                } else {
                    shares_dyn_act[j] = shares_dyn_prev[j];
                }
            }
            cost += gcd;
            /* Check with the previous amount of capital (propagate) */
            if (shares_dyn_act[j-1]>shares_dyn_act[j]){
                shares_dyn_act[j] = shares_dyn_act[j-1];
            }
        }

        /* Update rows */
        shares_dyn_aux = shares_dyn_act;
        shares_dyn_act = shares_dyn_prev;
        shares_dyn_prev = shares_dyn_aux;
    }

    printf("%lld\n",shares_dyn_prev[newCapital]);

    //free(shares_dyn_prev);
    //free(shares_dyn_act);

    return EXIT_SUCCESS;
}


