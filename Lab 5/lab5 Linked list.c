#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
void createList(struct Node **head){
int n ,value;
struct Node *newNode,*temp;
*head=NULL;
printf("Enetr number of initial nodes: ");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("Enetr the data for node %d: ",i+1);
    scanf("%d",&value);
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        temp=*head;
    }
    else{
        temp->next=newNode;
        temp=temp->next;

    }

    }
    printf("List created with %d elements\n",n);
}
void InsertFirst(struct Node **head,int value){
struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
if(newNode==NULL){
    printf("memory allocation failed!\n");
    return ;
}
newNode->data=value;
newNode->next=*head;
*head=newNode;
    printf("%d inserted at the beginning\n",value);
}


void InsertLast(struct Node **head,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
    printf("memory allocation failed!\n");
    return ;
}
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        printf("%d inserted at end\n",value);
        return ;
    }
    struct Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=newNode;
    printf("%d inserted at end\n",value);
}

void InsertAtPosition(struct Node **head,int value,int pos){
    if(pos<1){printf("Invalid position");
    return ;
    }
    if(pos==1){
        InsertFirst(head,value);
        return;
    }
    struct Node *temp=*head;
    for(int i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;

    }
    if(temp==NULL){
        printf("Position out of range\n");
        return ;
    }
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
    printf("memory allocation failed!\n");
    return ;
}
newNode->data=value;
newNode->next=temp->next;
temp->next=newNode;
printf("%d Insetted at position %d\n",value,pos);

}

void display(struct Node *head){
if(head==NULL){
    printf("List is empty!\n");
    return ;

}
struct Node *temp=head;
while(temp!=NULL){
    printf("%d-> ",temp->data);
    temp=temp->next;
}
printf("NULL\n");
}
int main(){
struct Node *head=NULL;
int choice,value,pos;
printf("\n---MENU---\n");
printf("1.CreateList\n2.Insert At First\n3.Insert At Position\n4.Insert At End\n5.Display\n\n");
while(1){
    printf("\nEnter your Choice: ");
    scanf("%d",&choice);
    switch(choice){
case 1:createList(&head);
break;
case 2:
     printf("\nEnter the value: ");
     scanf("%d",&value);
     InsertFirst(&head,value);
     break;
case 3:
    printf("\nEnter the value: ");
     scanf("%d",&value);
    printf("\nEnter the position: ");
     scanf("%d",&pos);
     InsertAtPosition(&head,value,pos);
     break;
case 4: printf("\nEnter the value: ");
     scanf("%d",&value);
     InsertLast(&head,value);
     break;
case 5: display(head);
break;
default: printf("Enter Valid choice !\n");
break;


    }
}
return 0;
}
