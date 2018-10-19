#include <stdio.h>
#include <stdlib.h>

void concat (char s1[],char s2[]);
int main()
{
    char s1[30], s2[30];
  concat (s2,s1);
}

void concat (char s1[],char s2[])
{
    printf ("\nNhap vao chuoi s1:");
    gets (s1);
    printf ("\nNhap vao chuoi s2:");
    gets(s2);
    strcat(s2,s1);
    printf ("\nChuoi sau khi noi la: %s",s1);
}
