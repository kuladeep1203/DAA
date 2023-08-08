
#include<stdio.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    else 
    return b;
}
void coinchange(int coins[],int money,int n)
{
    int d[money+1];
d[0]=0;
for(int i=1;i<money+1;i++)
{
    d[i]=__INT32_MAX__;
}
for(int i=0;i<money+1;i++)
{
    for(int j=0;j<n;j++)
    {
        if(coins[j]<=i &&d[i-coins[j]]!=__INT32_MAX__)
        d[i]=min(d[i],d[i-coins[j]]+1);
        
    }
    

}


     if(d[money]==money+1)
    printf("not possible\n");
    else
    printf("ff=%d",d[money]);

}
int main()
{
    int n,money;
    printf("enter the no.of denominations\n");
    scanf("%d",&n);
    int coins[n];
    printf("enter the denominations\n");
    for(int i=0;i<n;i++)
    scanf("%d",&coins[i]);
    printf("enter the amount\n");
    scanf("%d",&money);
    coinchange(coins,money,n);

}
/*
#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

int main()
{
   int n,sum,val;
   cout<<"Enter the sum value"<<endl;
   cin>>sum;
   cout<<"Enter no.of denominations"<<endl;
   cin>>n;
   
   vector<int> coins;
   vector<int> change(sum+1,sum+1);
   
   for(int i=0;i<n;i++)
   {
       cout<<"Enter the denomination "<<i+1<<" :"<<endl;
       cin>>val;
       
       coins.push_back(val);
   }
   
   change[0]=0;
   
   for(int i=0;i<sum+1;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(coins[j]<=i)
           {
               change[i]=min(change[i],change[i-coins[j]]+1);
           }
       }
   }
   
   if(change[sum]==sum+1)
   cout<<"No combination is possible"<<endl;
   else
   {
       cout<<"The minimum no.of coins reqired are :"<<change[sum]<<endl;
   }
    
    return(0);
}*/