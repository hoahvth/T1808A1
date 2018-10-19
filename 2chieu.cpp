#include <stdio.h>
#include <stdlib.h>
//_________==>Sói<==__________//
int main(int argc, char *argv[]) {
//Start Code
int N,M;
printf("Nhap so hang N=");
scanf("%d",&N);
printf("Nhap so cot M=");
scanf("%d",&M);

int a[N][M],i,j;
for(i=0;i<N;i++){
	for(j=0;j<M;j++){
		printf("Nhap gia tri cua a[%d][%d]=",i,j);
		scanf("%d",&a[i][j]);
	}
	printf("\n");
}

for(i=0;i<N;i++){
	for(j=0;j<M;j++){
		printf("%d",a[i][j]);
	}
	printf("\n");
}
printf("\n N=%d",N);
printf("\n m=%d",M);

//End Code
	return 0;
}
//==========I_Can!===========//

