#include<stdio.h>
#include<math.h>
void sort(int d[],int n)
{
    int temp;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (d[i] > d[j])
            {

                temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }
    printf("max profit=%d\n",d[n]);
}

int main()
{
    int n,b,sum=0,sum1=0,W;
    printf("enter the no.of objects\n");
    scanf("%d",&n);
    int w[n],p[n];
    int profit[n];
    int a[n][n];
    for(int i=1;i<=n;i++)
    {
        printf(" enter %d object weight\n",i);
        scanf("%d",&b);
        if(b<=0){
        printf("enter valid\n");
        break;
        }
        else
        w[i]=b;
    }
    for(int i=1;i<=n;i++)
    {
        printf(" enter %d object profit\n",i);
        scanf("%d",&b);
        if(b<=0){
        printf("enter valid\n");
        break;
        }
        else
        p[i]=b;
    }
    printf("enter weight of bag\n");
    scanf("%d",&W);
    int c=pow(2,n);
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=i%2;
            i=i/2;
        }
    }
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
               sum=sum+w[j];
               sum1=sum1+p[j];
            }
        }
        if(sum<=W)
        profit[i]=sum1;
    }
    sort(profit,n);
    
    
    
    
    
    
}