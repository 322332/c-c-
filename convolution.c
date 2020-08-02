#include<stdio.h>

void conv(int Length, int *h, int *x, int *y);


int main(){
	int Length = 4, m;
	int x[] = {4, 3, 2, 1};
	int h[] = {1, 2, 3, 4};
	int y[Length];
	
	conv(4,h,x,y);
	
	for(m=0;m<Length;m++)
		printf("%d ", y[m]);
}



void conv(int Length, int *h, int *x, int *y){
int m, n;

	for(n = 0; n < Length; n++){
		int tmp = 0;
		for(m = 0; m < Length; m++){
			//printf("(%d*%d) ", n-m, m);
			if((n-m) >= 0 ){
				//printf("%d %d   ",h[n-m],x[m]);
				tmp += h[n-m]*x[m];	
			}
			else{
				//printf("%d %d   ",h[Length+(n-m)],x[m]);
				tmp += h[Length+(n-m)]*x[m];
			}
		}
		y[n] = tmp;
	//	printf("\n");
	}
}

