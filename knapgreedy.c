#include<stdio.h>
void sort1(float c[],int n,float d[],int p[],int w[])
{
    int k=0,W;
    float profit=0;
    int fweight[n],fprofit[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(d[i]==c[j])
            {
                if(k==0){
                fweight[k]=w[j];
                k++;
                }
                else if(w[j]!=fweight[k-1]){
                fweight[k]=w[j];
                k++;
                }
            }
        }
    }
    
k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(d[i]==c[j] && k<n)
            {
                if(k==0){
                fprofit[k]=p[j];
                k++;
                }
                if(fprofit[k]!=fprofit[k-1]){
                fprofit[k]=p[j];
                k++;
               }
                
            }
        }
    }
    printf("enter the weight ofthe bag\n");
    scanf("%d",&W);
    int i=0;
for( i=0;i<n;i++)
{
    if(fweight[i]<=W)
    {
        
        profit=profit+fprofit[i];
        W=W-fweight[i];
    }
    else
    {
        profit=profit+(W/fweight[i])*p[i];
         W=W-(fweight[i])*(W/fweight[i]);
    }
}
printf("maxprofit=%d\n",profit);





    
    
}
void sort(float c[],int n,int p[],int w[])
{
    float d[n],temp;
    for(int i=0;i<n;i++)
    d[i]=c[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (d[i] <= d[j])
            {

                temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }
    printf("d[i]=");
    for(int i=0;i<n;i++)
    printf("%f\t",d[i]);
    sort1(c,n,d,p,w);
}
int main()
{
    int n,a;
    printf("enter the no.of objects\n");
    scanf("%d",&n);
    int w[n],p[n];
    for(int i=0;i<n;i++)
    {
        printf(" enter %d object weight\n",i);
        scanf("%d",&a);
        if(a<=0){
        printf("enter valid\n");
        break;
        }
        else
        w[i]=a;
    }
    for(int i=0;i<n;i++)
    {
        printf(" enter %d object profit\n",i);
        scanf("%d",&a);
        if(a<=0){
        printf("enter valid\n");
        break;
        }
        else
        p[i]=a;
    }
    float c[n];
    for(int i=0;i<n;i++)
    {
        c[i]=p[i]/w[i];
    }
    

    sort(c,n,p,w);
}