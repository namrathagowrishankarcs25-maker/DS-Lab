#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
void createlist(struct Node **head){
int n,value;
struct Node *newNode,*temp;
*head=NULL;
printf("Enter n value:");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("Enter data for node %d:",i+1);
scanf("%d",&value);
newNode=(struct Node *)malloc(sizeof(struct Node));
newNode->data=value;
newNode->next=NULL;
if(*head==NULL){
*head=newNode;
temp=*head;
}else{
temp->next=newNode;
temp=temp->next;
}
}
printf("List created with %d elements.\n",n);
}
void deleteBeginning(struct Node **head){
struct Node *temp=*head;
if(*head==NULL){
printf("List is Empty,\n");
return;
}
*head=temp->next;
printf("%d is deleted.\n",temp->data);
free(temp);
}
void deleteEnd(struct Node **head){
struct Node *temp=*head;
if(*head==NULL){
printf("List is Empty.\n");
return;
}
if(temp->next==NULL){
printf("%d is deleted.\n",temp->data);
free(temp);
*head=NULL;
return;
}
 while(temp->next->next!=NULL){
temp=temp->next;
}
printf("%d is deleted.\n",temp->next->data);
free(temp->next);
temp->next=NULL;
}
void deletePosition(struct Node **head,int position){
struct Node *temp=*head;
if(*head==NULL){
printf("List is empty.\n");
return;
}
if(position==0){
deleteBeginning(head);
return;
}
for(int i=1;i<position-1 && temp!=NULL;i++){
temp=temp->next;
}
if(temp==NULL || temp->next==NULL){
printf("Position is out of range.\n");
return;
}
struct Node *next=temp->next->next;
printf("%d is deleted.\n",temp->next->data);
free(temp->next);
temp->next=next;
}
void display(struct Node *head){
struct Node *temp=head;
if(head==NULL){
printf("List is Empty.\n");
return;}
printf("Linked List:");
while(temp!=NULL){
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
int main(){
struct Node *head=NULL;
int choice,position;
printf("==MENU==\n1.Create LinkedList\n2.Delete at Beginning\n3.Delete at End\n4.Delete at any position\n5.Display\n");
while(1){
printf("Enter Choice:");
scanf("%d",&choice);
switch(choice){
case 1:
createlist(&head);
break;
case 2:
deleteBeginning(&head);
break;
case 3:
deleteEnd(&head);
break;
case 4:
printf("Enter position:");
scanf("%d",&position);
deletePosition(&head,position);
break;
case 5:
display(head);
break;
default:
printf("Invalid Choice.\n");
}}
return 0;
}
