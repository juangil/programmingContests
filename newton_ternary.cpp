# include <iostream>
# include <math.h>
# include <cstdlib>
# include <cstdio>

using namespace std;

const double numero_aureo = (-1.0 + sqrt(5.0))/2.0;
const double EPS =  1.0e-6;

double fun(double x){
	return (6*exp(-2*x)) + (2*x*x);
}

double fun_derivative(double x){
	return (-12*exp(-2*x)) + (4*x);
}

void seccion_dorada(){
	double low = 0.0, high = 2.0;
	double lambda2 = numero_aureo; double lambda1 = 1 - numero_aureo;
	double ret = 0.0;
	while(true){
		double mid1 = low + (high - low)*lambda1;
		double mid2 = low + (high - low)*lambda2;
		if(fabs(mid1 - mid2) < EPS){
			ret = mid1;
			break;
		}
		double eval1 = fun(mid1);
		double eval2 = fun(mid2);
		if(eval1 > eval2)
			low = mid1;
		else
			high = mid2;
	}
	cout<<"Seccion dorada: "<<ret<<endl;
}

double nuevo_x_newton(double x){
	return x - (fun(x)/fun_derivative(x));
}

void newton(){
	double x_n = 0.0;
	double x_n_1 = 0.7;
	int max_it = 8;
	int cont = 0;
	while(fabs(x_n - x_n_1) > EPS && cont < max_it){
		x_n = x_n_1;
		x_n_1 = nuevo_x_newton(x_n_1);
		cont++;
		//cout<<x_n_1<<endl;
	}
	cout<<"Newton Raphson: "<<x_n_1<<endl;
}

int main(){
	seccion_dorada();
	newton();
	return 0;
}