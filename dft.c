#include<stdio.h>
#include<math.h>
#include <complex.h> 

#define PI 3.14159265359



void dft(double* x, double complex *X, int N);


int main(){
// x = data, X dft data
double x[]={1,0,0,1};
double complex X[5]; 
int N = 4, k;

dft(x, X, 4);	

	for(k=0;k<N;k++){
		printf(" %.2f + %.2fi\n",creal(X[k]),cimag(X[k]));
	}
}

void dft(double x[], double complex X[], int N){
	int  k,n;
		for( k=0; k < N; k++){
			for(n=0; n < N; n++){
				double complex T =	-1.0 *  k * n * (2 * PI) /N;
				double complex E = cos(T) + I * sin(T) ;
				 X[k] += x[n] * E;
			}
		}
}

