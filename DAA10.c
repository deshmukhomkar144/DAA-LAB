#include <stdio.h> 
#include <string.h> 
void
matchString (char str[], char pat[], int q) 
{
 
int x = strlen (pat);
 int y = strlen (str);
 
int p = 0, t = 0, h = 1, d = 256;
 int i, j;
 
for (i = 0; i < x - 1; i++)
 
 {
 
h = (h * d) % q;
 
}
 
for (i = 0; i < x; i++)
 
 {
 
p = (d * p + pat[i]) % q;
 t = (d * t + str[i]) % q;
 
}
 
for (i = 0; i <= y - x; i++)
 
 {
 
if (p == t)
{
 
for (j = 0; j < x; j++)
 
 {
 
if (str[i + j] != pat[j])
{
 break;
}
 }
 if (j == x)
 
 {
 
printf ("\nMatch Found at index: %d \n", i);
 return;
 
}
}
 
if (i < y - x)
{
 
t = (d * (t - str[i] * h) + str[i + x]) % q;
 
if (t < 0)
{
 t=(t+q);
}
}
}
printf("Match is not found");
}
int main(){
 char str[100],pat[100];
 printf("string:");
 scanf("%[^\n]s",str);
 getchar();
 printf("pattern:");
 scanf("%[^\n]s",pat);
 int q=269;
 matchString(str,pat,q);
 return 0;
}