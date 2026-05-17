#include<stdio.h>
#define MAX_SIZE 3
int q[MAX_SIZE],rear=-1,front=-1;
void enqueue(int item);
void dequeue();
void display();
void main()
{
    int ch,item;
    do
    {
        printf("\nenter the choice\n1 : enqueue()\n2 : dequeue()\n3 : display()\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
           enqueue(item);
           break;
            case 2:
           dequeue();
           break;
            case 3:
           display();
           break;
            case 4:
           break;
            default:
           printf("invalid choice");

        }
    }
while(ch!=4);
}
void enqueue(int item)
{
    if(front==(rear+1)%MAX_SIZE)
    {
    printf("not possible");
    }
    else
    {
        if(front==-1)
        {
        rear=0;
        front=0;
        printf("enter the item to be inserted : ");
        scanf("%d",&item);
        q[rear]=item;

        }  
        else
        {
            rear=(rear+1)%MAX_SIZE;
            printf("enter the item to be inserted : ");
            scanf("%d",&item);
            q[rear]=item;
        }
    }
}
void dequeue()
{
    int del;
    if(front==-1)
    {
        printf("not possible\n");
    }
    else
    {
        if(front==rear)
        {
            del=q[front];
            printf("deleted item : %d\n",del);
            front=-1;
            rear=-1;
        }
        else
        {
            del=q[front];
            printf("deleted item : %d",del);
            front=(front+1)%MAX_SIZE;
        }
    }
}
void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("QUEUE IS : \n");
   
        for(i=front;i!=rear;i=(i+1)%MAX_SIZE)
        {
            printf("%d ",q[i]);
        }
        printf("%d",q[i]);
    }
   
}
