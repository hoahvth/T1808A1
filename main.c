#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	int choose;
	
	do	{
		showMenu();
		printf("Choose: ");
		scanf("%d", &choose);
		
		switch(choose) {
			case 1:
				input();
			break;
			case 2:
				read();
			break;
			case 3:
				find();
			break;
			case 4:
				exportfile();
			break;
			case 5:
				printf("Goodbye!!!");
			break;
			default:
				printf("Input Failed.");
			break;
		}
	} while(choose != 5);
	return 0;
}

void showMenu()	{
	printf("\n1. Input data of motorbikes.");
	printf("\n2. Sort, display details information and statistic of all  motorbikes.");
	printf("\n3. Find  the  motorbike  by madein.");
	printf("\n4. Export to text file motorbike.txt.");
	printf("\n5. Exit.");
}

void input() {
	int N=1;
	char s;
	while(1) {
		if(total == 0) {
			p = (motorbike *) calloc (N, sizeof(motorbike));
		} else {
			p = (motorbike *) realloc (p, (N + total) * sizeof(motorbike));
		}
		printf("Enter data of motorbike %d: \n", total+1);
		fflush(stdin); fflush(stdout);
		printf("Name: ");
		gets(p[total].name);
		fflush(stdin); fflush(stdout);
		printf("Manufacturer: ");
		gets(p[total].manufacturer);
		fflush(stdin); fflush(stdout);
		printf("Made In: ");
		gets(p[total].madein);
		printf("Price: ");
		scanf("%d", &p[total].price);
		
		FILE *fp = fopen("motorbike.dat", "ab");
		fwrite(&p[total], sizeof(motorbike), 1, fp);
		
		fflush(stdin); fflush(stdout);
		printf("Continue(Y/N)? ");
		scanf("%c", &s);
		
		fclose(fp);
		
		total+=N;

		if(s == 'n')
		break;
	}
}

void read()	{
	int i, j;
	int count[total];
	
	FILE *fp = fopen("motorbike.dat", "rb");
	fread(p, sizeof(motorbike), total, fp);
	
	for(i=0; i<total-1; i++)	{
		for(j=i+1; j<total; j++)	{
			int cmp = strcmp(p[i].manufacturer, p[j].manufacturer);
			if(cmp < 0)	{
				motorbike tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for(i=0; i<total; i++)	{
		count[i]=1;
	}
	for(i=0; i<total-1; i++)	{
		for(j=i+1; j<total; j++)	{
			int cmp = strcmp(p[i].manufacturer, p[j].manufacturer);
			if(cmp == 0 && count[j] != 0)	{
				count[i]++;
				count[j]--;
			}
		}
	}
	
	printf("%6s||%20s||%20s||%20s||%20s||\n", "No", "Name", "Manufacturer", "Made In", "Price");
	for(i=0; i<total; i++)	{
		printf("%6d||%20s||%20s||%20s||%20d||\n", i+1, p[i].name, p[i].manufacturer, p[i].madein, p[i].price);
	}
	for(i=0; i<total; i++)	{
		if(count[i] != 0)	{
			printf("%s has %d motorbike.\n", p[i].manufacturer, count[i]);
		}
	}
	fclose(fp);
}

void find()	{
	int i, count=0;
	char search[12];
	fflush(stdin); fflush(stdout);
	printf("Enter madein for search: ");
	gets(search);
	
	FILE *fp = fopen("motorbike.dat", "rb");
	fread(p, sizeof(motorbike), total, fp);

	for(i=0; i<total; i++) {
		int cmp = strcmp(search, p[i].madein);
		if(cmp==0)
		count++;
	}
	if(count != 0) {
		printf("%6s||%20s||%20s||%20s||%20s||\n", "No", "Name", "Manufacturer", "Made In", "Price");
		for(i=0; i<total; i++){
			int cmp = strcmp(search, p[i].madein);
			if(cmp==0)	printf("%6d||%20s||%20s||%20s||%20d||\n", i+1, p[i].name, p[i].manufacturer, p[i].madein, p[i].price);
		}
	} else {
		printf("\nThere are no motorbike by this made in.");
	}
	fclose(fp);
}

void exportfile() {
	FILE *fp = fopen("motorbike.dat", "rb");
	fread(p, sizeof(motorbike), total, fp);
	
	FILE *ft = fopen("motorbike.txt", "w");
	
	int i;
	for(i=0; i<total; i++) {
		fprintf(ft, "Name of motorbike %d: %s\n", i+1, p[i].name);
		fprintf(ft, "Manufacturer of motorbike %d: %s\n", i+1, p[i].manufacturer);
		fprintf(ft, "\n");
	}
	fclose(ft);
	fclose(fp);
}
