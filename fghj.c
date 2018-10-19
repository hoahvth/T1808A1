


void concat(char s1[50], char s2[50]) {
	
    printf("\nEnter the first string: "); fflush(stdin); fflush(stdout); gets(s1);
    printf("\nEnter the second string: "); fflush(stdin); fflush(stdout); gets(s2);
    strcat(s1, s2);
	printf("\nThe concatenated string: %s", s1);
} 

int main(int argc, char *argv[]) {
	char s1[50];
	char s2[50];
	concat(s1,s2);
	return 0;
}

