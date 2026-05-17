#include<stdio.h>
#define SIZE 5
int q[SIZE],rear=-1,front=-1;
void enqueue(int item);
void enque(int items);
void dequeue();
void deque();
void display();
void main()
{
    int ch,item,items;
    do
    {
        printf("\nenter the choice\n1 : enqueue()\n2 : dequeue()\n3 : display()\n3 : enque()\n4 : deque()\n5 : display()\n");
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
                enque(items);
                break;
            case 4:
                deque();
                break;

            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("invalid choice");

        }
    }
while(ch!=6);
}
void enqueue(int item)
{
    if(front==(rear+1)%SIZE)
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
            rear=(rear+1)%SIZE;
            printf("enter the item to insert");
            
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
            front=(front+1)%SIZE;
        }
    }
}
void enque(int item)
{

        int temp;
    
        if(front==-1)
        {
        rear=0;
        front=0;
        printf("enter the item to be inserted : ");
        scanf("%d",&item);
        q[rear]=item;

        } 
        else if(front==0)
        {
            temp=SIZE-1;
            if(temp==rear)
            {
                printf("not possible");
            }
            else
            {
                printf("enter the item to be inserted : ");
                scanf("%d",&item);
                q[front]=item;

            }
        }
        else
        {
            temp=front-1;
            if(temp==rear)
            {
                printf("not possible");
            }
            else
            {
                printf("enter the item to be inserted : ");
                scanf("%d",&item);
                q[front]=item;

            }
        }

    
}
void deque()
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
        else if(rear==0)
        {
            del=q[front];
            printf("deleted item : %d\n",del);
            rear=SIZE-1;
        }
        else
        {
            del=q[front];
            printf("deleted item : %d\n",del);
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
   
        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
            printf("%d ",q[i]);
        }
        printf("%d",q[i]);
    }
   
}
