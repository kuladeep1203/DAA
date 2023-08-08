#include<stdio.h>
#include<stdlib.h>
struct list
{
    int a;
    struct list *down;
    struct list *side;
};
struct list*head=NULL;
void insert(int x)
{
    struct list*temp=head;
    struct list*newnode=malloc(sizeof(struct list));
    newnode->a=x;
    newnode->down=NULL;
    newnode->side=NULL;
    if(head==NULL){
    head=newnode;
    }
    else
    {
    while(temp->down!=NULL)
    temp=temp->down;

    temp->down=newnode;
    temp=temp->down;
    }
}
void display()
{
    struct list*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->a);
        temp=temp->down;
    }
}
void connect(int i,int k)
{
    struct list*newnode=malloc(sizeof(struct list));
    newnode->a=k;
    newnode->down=NULL;
    newnode->side=NULL;
    struct list*temp=head;
    while(temp!=NULL && temp->a!=i)
    {
        temp=temp->down;
    }
    struct list*temp1=temp;
    while(temp1->side!=NULL)
    temp1=temp1->side;
    temp1->side=newnode;
    temp1=newnode;
}
void displayedge(int i)
{
    struct list*temp=head;
    while(temp!=NULL && temp->a!=i)
    {
        temp=temp->down;
    }
   // printf("hi=%d\n",temp->a);
struct list*temp1=temp;
while(temp1!=NULL)
{
    printf("%d->\n",temp1->a);
    temp1=temp1->side;
}
}
int main()
{
int n,k,v;
printf("enter the no.of nodes\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
insert(i+1);
//display();
for(int i=0;i<n;i++)
{
    printf("enter no.of edges for %d node\n",i+1);
    scanf("%d",&v);
    printf("enter the nodes that %d is connected with\n",i+1);
    for(int j=0;j<v;j++){
    scanf("%d",&k);
    connect(i+1,k);
    }
}
printf("enter the node\n");
scanf("%d",&k);
displayedge(k);

}