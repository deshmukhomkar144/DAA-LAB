#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int mat[100][100], s[100][100], count = 0;
int
MCM (int p[], int i, int j)
{
 
if (i == j)
 {
 
mat[i][j] = 0;
 
return 0;
 
}
 
mat[i][j] = 30000;
 
for (int k = i; k < j; k++)
 {
 
count = MCM (p, i, k) + MCM (p, k + 1, j) + p[i - 1] * p[k] * p[j];
 
if (count < mat[i][j])
{
 
mat[i][j] = count;
 
s[i][j] = k;
}
 
}
 
return mat[i][j];
}
void
POP (int i, int j)
{
 
if (i == j)
 
printf ("M%d", i);
 
 else
 {
 
printf ("(");
 
POP (i, s[i][j]);
 
POP (s[i][j] + 1, j);
 
printf (")");
 
}
}
void
main ()
{
 
int num;
 
clock_t start, end;
 
printf ("\nEnter the number of inputs you want to give: ");
 
scanf ("%d", &num);
 
int p[num];
 
printf ("\nEnter the order of matrices: ");
 
start = clock ();
 
for (int i = 0; i < num; i++)
 {
 
printf ("\nEnter value for place %d: ", i + 1);
 
scanf ("%d", &p[i]);
 
} 
printf ("The minimum number of multiplications required are: 
%d\n\n",
MCM (p, 1, num - 1));
 
end = clock ();
 
for (int i = 1; i < num; i++)
 {
 
for (int j = 1; j < num; j++)
{
 
printf ("%d\t", mat[i][j]);
} 
printf ("\n");
 
} 
printf ("\nThe optimal solution is: \n");
 
POP (1, num - 1);
 
printf ("\nThe time required for matrix chain multiplication is 
%f seconds", ((double) end - start) / CLOCKS_PER_SEC);
}
