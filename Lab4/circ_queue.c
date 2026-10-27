#include<stdio.h>
#define max 3
int front=-1,rear=-1,queue[max];
void Insert(int data){
if (front==0&&rear==max-1||(front==rear+1)){
    printf("\nQueue is full!cannot push %d\n",data);
    return;
}
if(front==-1&&rear==-1){
    rear=0;
    front=0;
}
else if(rear==max-1&&front!=0){
    rear=0;
}
else{
    rear++;
}
queue[rear]=data;
printf("%d added to queue\n",data);
}
void Delete(){
if(front==-1){
    printf("Queue is empty cannot delete1\n");
    return ;

}
int value=queue[front];
if(front==rear){
    front=-1;
    rear=-1;
}
else if(front==max-1){
    front=0;
}
else{
front++;
}
printf("%d removed from queue\n",value);

}
void display(){
    if(front==-1){
    printf("Queue is empty cannot delete\n");
    return ;

}
printf("Queue elements are:\n");
for(int i=front;i<=rear;i++){
    printf("%d ",queue[i]);
}
}
int main(){
int choice;

printf("---CIRCULAR QUEUE---\n1.Insert\n2.Delete\n3.Display\n");
while(1){
    printf("\n Enter your choice(1-3):");
    scanf("%d",&choice);
    switch(choice){
case 1:
    int data;
    printf("Enter the element to insert: ");
    scanf("%d",&data);
    Insert(data);
    break;
case 2: Delete();
        break;
case 3: display();
break;
default:printf("Please enter valid choice!\n");
break;

    }

}
return 0;
}
