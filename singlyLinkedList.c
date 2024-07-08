#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head,*temp=NULL;
/*************************************************************************************************/
void create()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
 int data;
 printf("enter Data :");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 if(head==NULL)
 {
    head=newnode;
    temp=newnode;
 }
 else
 {
    temp=head;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next=newnode;
 }
}
/*************************************************************************************************/
void print()
{
struct node *temp=head;
if(temp==NULL)
{
printf("\nNo Elements in Linked list ");
return;
}
printf("\nSINGLY LINKED LIST IS.......................\n");
printf("\nelements are :\n");
while(temp!=NULL)
{
printf("%d    ",temp->data);
temp=temp->next;
}
}
/*************************************************************************************************/
struct node in_beg()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
int data;
printf("enter Data :");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
}
/****************************************************************************************/
struct node in_mid()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............");
}
int data,p;
printf("\nenter position : ");
scanf("%d",&p);
if(p!=1)
{
printf("enter Data :");
scanf("%d",&newnode->data);
}
if(p<1)
{
printf("Invalid position "); 
free(newnode); 
}
if(p==1)
{
in_beg();
free(newnode);
}
else
{
temp=head;
for(int i=1;i<p-1&&temp!=NULL;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Position out of Bound...");
free(newnode);
}
newnode->next=temp->next;
temp->next=newnode;
}
}
/*******************************************************************************/
struct node in_end()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
int data;
printf("enter Data :");
scanf("%d",&newnode->data);
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
//************************************************************************
struct node del_beg()
{
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
else
{
temp=head;
head=head->next;
free(temp);
}
}
////////////////////////////////////////////////////////////////////
struct node del_mid()
{
struct node *nextnode=(struct node*)malloc(sizeof(struct node));
struct node *prenode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
int p;
if(p!=1)
{
printf("\nenter position : ");
scanf("%d",&p);
}
if(p<1)
{
printf("Invalid position "); 
}
if(p==1)
{
del_beg();
}
else
{
temp=head;
for(int i=0;i<p-1&&temp!=NULL;i++)
{
prenode=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("Position Out Of Bound");
}
prenode->next=temp->next;
free(temp);
}
}
///////////////////////////////////////////////////////////////////////////
struct node del_last( )
{
struct node *prenode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
else
{
temp=head;
while(temp->next!=NULL)
{
prenode=temp;
temp=temp->next;
}
prenode->next=temp->next;    // or prenode->next=NULL
free(temp);
}
}
/*************************************************************************************************/
int main()
{
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
printf("\nCREATING THE LINKED LIST ......................\n");
create();
print();
printf("\nINSERTING AT BEGGINING IN LINKED LIST IS.......................\n");
in_beg();
print();
printf("\nINSERTING AT END IN LINKED LIST IS.......................\n");
in_end();
print();
printf("\nINSERTION AT MID IN LINKED LIST IS.......................\n");
in_mid();
print();

printf("\nINSERTION AT MID IN LINKED LIST IS.......................\n");
in_mid();
print();

printf("\nDELETION AT BEGGINING IN LINKED LIST IS.......................\n");
del_beg();
print();   

printf("\nDELETION AT END IN LINKED LIST IS.......................\n");
del_last();
print();

printf("\nDELETION AT MID IN LINKED LIST IS.......................\n");
del_mid();
print();
return 0;
}