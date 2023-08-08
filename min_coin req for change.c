#include<stdio.h>
int min(int a ,int b)
{
    if(a<b)
    return a;
    else 
    return b;
}
void coinchage(int d[],int n)
{
    int change;
    printf("enter the money you want change\n");
    scanf("%d",&change);
    int table[n+1][change+2];
    for(int i=1;i<change+2;i++)
    {
        table[0][i]=i-1;
    }
    for(int i=1;i<n+1;i++)
    {
    table[i][0]=d[i-1];
    }
    for(int i=1;i<change+2;i++)
    {
        table[1][i]=table[0][i]/table[1][0];
    }
    
    for(int j=2;j<n+1;j++)
    {
        int a=d[j-1];
         for(int i=1;i<change+2;i++)
         {
            if(i<a)
            table[j][i]=table[j-1][i];
            else
            table[j][i]=min(1+table[j][i-a],table[j-1][i]);

         }

    }

      
for(int i=0;i<n+1;i++)
{
    for(int j=0;j<change+2;j++)
    {
        printf("%d\t",table[i][j]);
    }
    printf("\n");
}

    printf("min no.of coins required is %d",table[n][change+1]);
}
int main()
{
    int n,temp;
    printf("enter the no.of denominations\n");
    scanf("%d",&n);
    int d[n];
    printf("enter the denominations\n");
    for(int i=0;i<n;i++)
    scanf("%d",&d[i]);
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
    coinchage(d,n);   
}