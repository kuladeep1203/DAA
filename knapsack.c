#include<stdio.h>
int max(int a ,int b)
{
    if(a<b)
    return b;
    else 
    return a;
}
void coinchage(int w[],int p[],int n)
{
    int weight;
    printf("enter the weight of bag\n");
    scanf("%d",&weight);
    int table[n+2][weight+2];
    table[0][0]=0;
    for(int i=1;i<weight+2;i++)
    {
        table[0][i]=i-1;
    }
    for(int i=1;i<n+2;i++)
    {
    table[i][0]=i-1;
    }
    for(int i=1;i<weight+2;i++)
    {
        table[1][i]=0;
        
    }
    for(int i=1;i<n+2;i++)
    {
    table[i][1]=0;
    }
    for(int j=2;j<n+2;j++)
    {
        int a=w[j-2];
         for(int i=2;i<weight+2;i++)
         {
            if(i-1<a)
            table[j][i]=table[j-1][i];
            else if(j==2)
            table[j][i]=p[j-2];
            else
            table[j][i]=max(p[j-2]+table[j][i-a],table[j-1][i]);

         }

    }

      
for(int i=0;i<n+2;i++)
{
    for(int j=0;j<weight+2;j++)
    {
        printf("%d\t",table[i][j]);
    }
    printf("\n");
}

    printf("max profit  is %d",table[n+1][weight+1]);
}
int main()
{
    int n,temp;
    printf("enter the no.of objects\n");
    scanf("%d",&n);
    int p[n],w[n];
    printf("enter the profits\n");
    for(int i=0;i<n;i++)
    scanf("%d",&p[i]);
printf("enter the weights\n");
for(int i=0;i<n;i++)
    scanf("%d",&w[i]);
    coinchage(w,p,n);   
}















