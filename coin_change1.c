#include<stdio.h>
int main()
{
int n,temp1=0;
int k,count=0,temp, de;
scanf("%d",&n);
scanf("%d",&k);
int a[k];
for(int i=0;i<k;i++)
{
scanf("%d",&a[i]);
}
for(int i=0;i<k-1;i++)
{
    for(int j=i;j<k;j++)
    {
        if(a[i]>a[j])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=k-1;i>=0;i--)
{
    if(n%a[i]==0)
    {
     de=n/a[i];
     printf(" no.of %d coins-%d\n",a[i],de);
     temp1=1;
    break;
    }
}
if(temp1==0)
{
    printf("change for given denominations donot exist\n");
}
return 0;

}