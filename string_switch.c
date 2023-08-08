/*#include <stdio.h>

int main()
{
    char str1[100];
    char str2[100];
    
    scanf("%s",str1);
    scanf("%s",str2);
    
    int i,j,m=0,n=0,k=0,p=0,x=0,temp=0,flag;
    
    for(i=0;str1[i] != '\0';i++)
    {
        m++;
    }
    
    for(i=0;str2[i] != '\0';i++)
    {
        n++;
    }
   
    for(i=0;str2[i] != '\0';i++)
    {
       for(j=0;str1[j] != '\0';j++)
       {
           if(str1[j] == str2[i])
           {
               while(str1[j+p] == str1[j+p+1])
               {
                   p++;
               }
               temp = j+p;
               break;
           }
       }
        if(str1[j] == str2[i])
           {
               
               break;
           }
    }
   
   for(i=0;str2[i] != '\0';i++)
   {
       if(str1[temp] == str2[i])
       {
           flag = 1;
           break;
       }
       else
       {
           flag = 2;
           k++;
       }
   }
   
    
   if(flag == 1)
   {    
   for(i=0;i<temp;i++)
   {
       printf("%c",str1[i]);
       x++;
   }
   for(i=0;str2[k+i] != '\0';i++)
   {
       printf("%c",str2[k+i]);
       x++;
   }
    printf("\n");
   printf("%d",x);
   }
   else
   {
       printf("*");
   }
return(0);    
}



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j,k=0;
	char a[100],b[100];
	printf("enter the 1st string\n");
	scanf("%s",a);
	printf("enter the 2nd string\n");
	scanf("%s",b);
	int l1=strlen(a);
	int l2=strlen(b);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	{
		
		if(a[i]==b[j])
		{
		    c[k]=a[i];
		    k++;
		while(a[i]==a[i+1])
		{
			c[k]=a[i];
			k++;
			i++;
}
			if(b[j+1]==a[i])
			
			
		}
		if()
		
		
		
		
		
		
		
	}
	}
	
	
	
	
}*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int string_switch(char a[], char b, int l, int c);
int main()
{

    char str_a[100];
    char str_b[100];
    scanf("%s", str_a);
    scanf("%s", str_b);
    int l1 = strlen(str_a);
    int l2 = strlen(str_b);
    int i = -1, j = -1;
    int temp = 0, k, flag = -1;
    char longest_str[100];
    int x = 0,a;
    while (i != l1 - 1 && j != l2 - 1)
    {
        if (temp == 0)
        {
            k = string_switch(str_a, str_b[j + 1], l1, i + 1);

            if (k != -1)
            {
                temp = -1;
                flag = 1;
                for ( a = i + 1; a <= k; a++)
                {
                    longest_str[x] = str_a[a];
                    x++;
                }
                i = k;
            }
            j++;
        }
        else if (temp == -1)
        {
            k = string_switch(str_b, str_a[i + 1], l2, j + 1);
            if (k != -1)
            {
                temp = 0;
                for ( a = j + 1; a <= k; a++)
                {
                    longest_str[x] = str_b[a];
                    x++;
                }
                j = k;
            }
            i++;
        }
    }
    if (i != l1 - 1)
    {
        while (i != l1 - 1)
        {
            longest_str[x] = str_a[i + 1];
            x++;
            i++;
        }
    }
    if (j != l2 - 1)
    {
        while (j != l2 - 1)
        {
            longest_str[x] = str_b[j + 1];
            x++;
            j++;
        }
    }
    longest_str[x]='\0';

    if (flag == -1)
    {
        printf("*");
    }
    else
    {
        printf("%s\n%ld", longest_str, strlen(longest_str));
    }

    return 0;
}
int string_switch(char a[], char b, int l, int c)
{
    int res = -1,i;
    for ( i = c; i < l; i++)
    {
        if (a[i] == b)
            res = i;
    }

    return (res);
}





















