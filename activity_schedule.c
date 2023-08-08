/*#include <stdio.h>
int main()
{
    int m, n, temp;
    printf("enter no.of denominations\n");
    scanf("%d", &m);
    int b[m];
    printf("enter the denominations\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i; j < m; j++)
        {
            if (b[i] > b[j])
            {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
    printf("enter the amount\n");
    scanf("%d", &n);
    int c[n + 1];
    for (int i = 0; i < n + 1; i++)
        c[i] = i;
    int a[m][n + 1];
    for (int i = 0; i < m; i++)
        a[i][0] = 1;
    for (int i = 0; i < n + 1; i++)
    {
        if (c[i] % b[0] == 0)
            a[0][i] = 1;
        else
            a[0][i] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (b[i] > c[j])
            {
                a[i][j] = a[i - 1][j];
            }

            else
            {
                a[i][j] = a[i - 1][j] + a[i][c[j] - b[i]];
            }
        }
    }
    printf("no.of ways to give the change=%d", a[m - 1][n]);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int x,int y)
{
    if(x>y)
    return y;
    else
    return x;
}
int solve(int i,int j,char s[])
{
            if ( i >= j)
            return 0;
         if( s[i] == s[j])
            return solve(i + 1, j - 1,s);
          else
            return min(solve(i + 1, j,s), solve(i, j - 1,s)) + 1;
}
int main()
{
    char a[100];
    printf("enter the string\n");
    scanf("%s",a);
int b=solve(0,strlen(a)-1,a);
printf("%d",b);
}
#include <stdio.h>
int main()
{
    int n, temp, temp1;
    printf("Enter number of activities \n");
    scanf("%d", &n);
    int a[2][n];
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("Enter the start time ofactivities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter the end time of activities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[1][i] > a[1][j])
            {

                temp = a[1][j];
                a[1][j] = a[1][i];
                a[1][i] = temp;

                temp1 = a[0][j];
                a[0][j] = a[0][i];
                a[0][i] = temp1;
            }
        }
    }
    int b[n];
    int x = 0;
    b[0] = 0;
    x++;
    for (int i = 1; i < n; i++)
    {
        if (a[0][i] >= a[1][b[x - 1]])
        {
            b[x] = i;
            x++;
        }
    }
    printf("Actvities that can be done are : \n");

    for (int i = 0; i < x; i++)
    {
        printf(" %d %d \n", a[0][b[i]], a[1][b[i]]);
    }
    return 0;
}
*/
#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    if (x < y)
        return y;
    
}
int maxactivities(int n, int a[3][n])
{
    int answr[n];
    int x = 0;
    answr[0] = 0;
    x++;
    for (int i = 1; i < n; i++)
    {
        if (a[0][i] >= a[1][answr[x - 1]])
        {
            answr[x] = i;
            x++;
        }
    }
    return x;
}
void dp(int n, int a[3][n])
{
    int d[n];
    int count = 0, j,i;
    int z=maxactivities(n,a);
    int answr[z];
    int k=0;
    d[0] = a[2][0];

    for (i = 1; i < n; i++)
    {
        int x = a[2][i];

        for (j = i - 1; j >= 0; j--)
        {
            if (a[1][j] <= a[0][i])
            {
                count++;
                break;
            }
        }

        if (count != 0)
        {
            x += d[j];
        }

        d[i] = max(x, d[i - 1]);

        if(x>d[i-1])
        {  
            answr[k]=j;
            k++;
        }

        else
        {
            if(d[i]!=d[i-1])
            {
                answr[k]=i-1;
                k++;
            } 
        }  
    }

    answr[z-1]=i-1;

    for (int i = 0; i < z; i++)
    {
        printf(" Activity - %d \n",answr[i]+1);
        printf(" Start time : %d \n",a[0][answr[i]]);
        printf(" End time : %d \n",a[1][answr[i]]);
    }
    printf("Maximum profit is : %d \n",d[n-1]);
}

int main()
{
    int n, temp, temp1, temp2;
    printf("Enter no.of activities \n");
    scanf("%d", &n);
    int a[3][n];
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("Enter the start time of activities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter the end time of activities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 2)
        {
            printf("Enter corresponding weights for activities \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[1][i] > a[1][j])
            {

                temp = a[1][j];
                a[1][j] = a[1][i];
                a[1][i] = temp;

                temp1 = a[0][j];
                a[0][j] = a[0][i];
                a[0][i] = temp1;

                temp2 = a[2][j];
                a[2][j] = a[2][i];
                a[2][i] = temp2;
            }
        }
    }
    dp(n, a);
return 0;
}