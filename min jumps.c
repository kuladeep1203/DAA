#include<stdio.h>
int min(int c,int d)
{
    if (c<=d)
    return c;
    else
    return d;
}
int minJump(int a[], int n){
    int minJumps[n];
    for(int i=0;i<n;i++)
    minJumps[i]=__INT32_MAX__;
    minJumps[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1 ; j < min(i+a[i]+1, n);j++) {
            minJumps[j] = min(minJumps[j], 1 + minJumps[i]);
        }
    }
    return minJumps[n-1];
}
int main()
{
int n;
printf("enetr the no.of elements\n");
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int k=minJump(a,n);
printf("\n%d\n",k);



}
