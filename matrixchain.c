/*
#include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int p[], int n)
{
	int m[n][n];

	int i, j, k, L, q;

	for (i = 1; i < n; i++)
		m[i][i] = 0;

	
	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}


int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, size));

	getchar();
	return 0;
}
*/
#include<stdio.h>
void matrixchain(int p[],int n)
{
    int table[n][n];
    for(int i=1;i<n;i++)
    table[i][i]=0;
    int i,j,l,q,k;
     
  for( l=2;l<n;l++)
  {
  for(i=1;i<n-l+1;i++)
  {
    j=i+l-1;
    table[i][j]=__INT32_MAX__;
    for( k=i;k<=j-1;k++)
    {
    q=table[i][k]+table[k+1][j]+p[i-1]*p[k]*p[j];
   if(q<table[i][j])
   table[i][j]=q;

    }
  }
  }

printf("%d",table[1][n-1]);

}




int main()
{
    int n;
    printf("enter the no.of matrices\n");
    scanf("%d",&n);
   int p[n+1];
   printf("enter the products\n");
   for(int i=0;i<n+1;i++)
   {
    scanf("%d",&p[i]);
   }
   matrixchain(p,n+1);
}
















