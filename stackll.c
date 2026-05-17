#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*top=NULL,*new,*ptr,*temp;
void push(int item)
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter the element to inserted : ");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
    if(top==NULL)
    {
        top=new;
    }
    else
    {
        new->link=top;
        top=new;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("ll is empty");
    }
    else
    {
        temp=top;
        printf("deleted item : %d",temp->data);
        top=temp->link;
        free(temp);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("ll is empty");
    }
    else
    {
        ptr=top;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
}
void main()
{
    int c,item;
    do
    {
        printf("\nenter the choice\n\n1 : push an element\n2 : pop an element\n3 : display\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3: 
                display();
                break;
            case 4:
                break;
            default:
                printf("invalid choice");
        }
    }while(c!=4);
}