#include<stdio.h>
#define max 3
int front=-1,rear=-1,queue[max];
void Enqueue(int data){
if(rear==(max-1)){
printf("\nQueue is full.");
return ;
}
if(front==-1&&rear==-1){
front=0;
rear=0;
}
else{
    rear++;
}
printf("\n %d added to queue\n",data);

queue[rear]=data;

}

int dequeue(){
if(front==-1||front>rear){
    printf("\nQueue is empty");
    return -1;
}

int val=queue[front];
front++;
return val;
}

void display(){
if(front==-1||front>rear){
    printf("\n Queue is empty!\n");
    return ;

}
for(int i=front;i<=rear;i++){
    printf("%d ",queue[i]);
}
}
int main(){
    while(1){
printf("\n\nMenu\n1.Insert\n2.Delete\n3.Display\n");
int choice;
printf("Enter your choice(1-3): ");
scanf("%d",&choice);
switch(choice){
case 1:
    int ele;
    printf("Enter the element to insert: ");
    scanf("%d",&ele);
    Enqueue(ele);
    break;
case 2:
    int res;
    res=dequeue();
    if(res!=-1){
    printf("\n%d removed from queue",res);
    }
        break;
case 3: display();
         break;
default:printf("Invalid choice!");
break;

}
}
return 0;
}
