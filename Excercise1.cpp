#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void concat(char s1[],char s2[]){
	int i,n;
	i=0;
	while (s1[i] != '\0'){
		i++;
	}
	n = 0;
	while (s2[n] != '\0'){
		s1[i] = s2[n];
		n++;
		i++;
	}
	s1[i] = '\0';
}
int main() {
	char s1[30];
	char s2[30];
	printf("\nEnter the first string : ");
	gets(s1);
	printf("\nEnter the second string : ");
	gets(s2);
	concat(s1,s2);
	printf("\nThe concatenated string : %s",s1);
	return 0;
}
