
/*#include <stdio.h>

int dp(int n, int d[n], int w);
int min(int x, int y);

int main()
{
    int n, temp;

    printf("Enter no.of denominations : ");
    scanf("%d", &n);

    int d[n];

    printf("Enter %d denominations \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (d[i] > d[j])
            {

                temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }

    int w;

    printf("Enter the amount for the change is required : ");
    scanf("%d", &w);

    printf("%d\n", dp(n, d, w));

    return 0;
}

int dp(int n, int d[n], int w)
{
    int table[n][w + 1];

    for (int i = 0; i < n; i++)
    {
        table[i][0] = 0;
    }

    for (int i = 1; i < w + 1; i++)
    {
        table[0][i] = i / d[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (j < d[i])
            {
                table[i][j] = table[i - 1][j];
            }

            else
            {
                // printf("l71\n");
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - d[i]]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < w + 1; j++)
    //     {
    //         printf(" %d ", table[i][j]);
    //     }
    //     printf("\n");
    // }

    int a[table[n - 1][w]];

    int x = 0, i = n - 1, j = w;

    while (x < table[n - 1][w] & j >= 0)
    {
        if (table[i][j] == table[i - 1][j])
        {
            i--;
        }

        if (table[i][j] < table[i - 1][j])
        {
            a[x] = d[i];
            x++;
            j = j - d[i];
        }
    }

    for (int i = 0; i < x; i++)
    {
        printf(" %d ", a[i]);
    }

    printf("\n");

    return table[n - 1][w];
}

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }

    if (x > y)
    {
        return y;
    }
}
*/
#include<stdio.h>
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int b[n1],c[n2];
    for(int i=0;i<n1;i++)
    {
        b[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        c[i]=a[m+1+i];
    }
    int k=l;
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
        a[k]=b[i];
          i++;
        }
        else
        {
         a[k]=c[j];
         j++;
        }
        k++;
    }
      
 while(i<n1)
 {
    a[k]=b[i];
    k++;
    i++;
 }
 while(j<n2)
 {
    a[k]=c[j];
    k++;
    j++;
 }




}
void mergesort(int a[],int l,int r)
{

    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }

}

int main()
{
    int n;
    printf("enter the no.of integers\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the numbers\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
   
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
    
}