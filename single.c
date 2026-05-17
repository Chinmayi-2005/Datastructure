#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*new,*head=NULL,*ptr,*temp,*ptr1;
void insbeg()

{
    int item;
    new=(struct node*)malloc(sizeof(struct node));
    printf("read item to be inserted : ");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        new->link=head;
        head=new;
    }
}

void insend()
{
    int item;
    new=(struct node*)malloc(sizeof(struct node));
    printf("read item to be inserted : ");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;

    }
}
void inspos()
{
    int item,pos;
    int i;

    new=(struct node*)malloc(sizeof(struct node));
    printf("read item to be inserted : ");
    scanf("%d",&item);
    new->data=item;
    new->link=NULL;
    printf("read the position to insert element : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        if(head==NULL)
        {
            head=new;
        }
        else
        {
            new->link=head;
            head=new;
        }

        
    }
    else
    {
        ptr=head;   
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
            new->link=ptr->link;
            ptr->link=new;
        
    }
}
void delbeg()
{
    if(head==NULL)
    {
        printf("not possible");
    
    }
    else
    {
        temp=head;
        printf("deleted item : %d",temp->data);
        head=head->link;
        free(temp);
    }
}
void delend()
{
    if(head==NULL)
    {
        printf("not possible");
    
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        temp=ptr;
        printf("deleted item : %d",temp->data);
        ptr1->link=NULL;
        free(temp);
    }
}
void delpos()
{
    int pos,i;
    if(head==NULL)
    {
        printf("not possible");
    
    }
    else
    {
        printf("enter the position : ");
        scanf("%d",&pos);
        if(pos==1)
        {
        temp=head;
         printf("deleted item : %d",temp->data);
        head=head->link;
        free(temp);
    
        }
        else
        {
            ptr=head;
            for(i=1;i<pos-1;i++)
            {
                ptr=ptr->link;
            }
            temp=ptr->link;
            printf("deleted item : %d",temp->data);
            ptr->link=temp->link;
            free(temp);
        }
    }
}
void display()
{
    int i;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
void main()
{
    int ch;
    do
    {
        printf("\nenter the choice\n1 : insbeg()\n2 : insend()\n3 : inspos\n4 : delbeg()\n5 : delend()\n6 : delpos()\n7 : display()\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insbeg();
                break;
            case 2:
                insend();
                break;
            case 3:
                inspos();
                break;
            case 4:
                delbeg();
                break;
            case 5:
                delend();
                break;
            case 6:
                delpos();
                break;
            case 7:
                display();
                break;
            case 8:
                break;
            default:
                printf("invalid choice\n");
        }
    }while(ch!=8);
    
}