#include <stdio.h>
int main(int argc, char **argv[])
{
	int a,b,c,d;
	float t, h;
	
	printf("nhap gia tri cua a");
	scanf("%d",&a);
	printf("nhap gia tri cua b");
	scanf("%d",&b);
	printf("nhap gia tri cua c");
	scanf("%d",&c);
	printf("nhap gia tri cua d");
	scanf("%d",&d);
	t=(a*a*a*a*a)+(b*b*b*b)*c+(a*b*d*d);
	h=a*b*c*d;
	
	printf("t=%.1f,h=%.1f",t,h);
}
