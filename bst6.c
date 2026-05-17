#include<stdio.h>
#include<stdlib.h>
int flag=0;
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
}*new,*root=NULL,*ptr,*parent,*ptr1,*del;
void insertion()
{
    int ele;
    printf("enter the node value : ");
    scanf("%d",&ele);
    new=(struct node *)malloc(sizeof(struct node));
    new->data=ele;
    new->lptr=NULL;
    new->rptr=NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ele<ptr->data)
            {
            	ptr=ptr->lptr;
                
            }
            else if(ele>ptr->data)
            {
                ptr=ptr->rptr;
            }
            else
        	{
        		printf("insertion not possible");
       	 		break;
       	 	}
            
        }
        if(ele<parent->data)
        {
            parent->lptr=new;
        }
   
        else if(ele>parent->data)
        {
            parent->rptr=new;
        }
        
    }
}
void preorder(struct node *ptr)
{
   
    if(ptr==NULL)
    {
       return;  
    }
   
    else
    {
        printf("%d ",ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}
void inorder(struct node *ptr)
{
   
    if(ptr==NULL)
    {
       return;  
    }
   
    else
    {
       
        inorder(ptr->lptr);
        printf("%d ",ptr->data);
        inorder(ptr->rptr);
    }
}
void postorder(struct node *ptr)
{
     
    if(ptr==NULL)
    {
       return;  
    }
   
    else
    {
       
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        printf("%d ",ptr->data);
    }
}
void search(struct node *ptr,int key)
{
    flag=0;
    parent=NULL;
    while(ptr!=NULL)
    {
        if(key==ptr->data)
        {
            flag=1;
            
            break;
        }
        else if(key<ptr->data)
        {
        	
            ptr=ptr->lptr;
        }
        else
        {
        
            ptr=ptr->rptr;
        }
    }
    if(flag==0)
    {
        printf("key not found");
    }
    else
    {
        printf("key found");
    }
}
struct node *insucc(struct node *ptr) {
    ptr1 = ptr->rptr;
    while (ptr1->lptr != NULL) {
        ptr1 = ptr1->lptr;
    }
    return ptr1;
}

void delete(int del_val)
{

    int item;
    flag=0;
    parent=NULL;
    printf("enter the node value to delete : ");
    scanf("%d",&del_val);
    
	ptr=root;
	while(ptr!=NULL)
	{
		if(del_val==ptr->data)
        {
            flag=1;
            del=ptr;
            break;
        }
        else if(del_val<ptr->data)
        {
        	parent=ptr;
            ptr=ptr->lptr;
        }
        else
        {
        	parent=ptr;
            ptr=ptr->rptr;
        }
	}
    if(flag==0)
    {
        printf("not found");
        return;
      
    }
    else
    {
        if ((del->lptr == NULL) && (del->rptr == NULL)) {
            // Node is a leaf
           
                if (parent->lptr == del) {
                    parent->lptr = NULL;
                } else {
                    parent->rptr = NULL;
                }
           
        }
        else if(del->lptr!=NULL&&del->rptr!=NULL)
        {
            struct node *insuccptr=insucc(del);
           
            item=insuccptr->data;
            delete(insuccptr->data);
            del->data=item;
        }
        
        else
        {
            if(parent->lptr==del)
            {
                if(del->rptr==NULL)
               
                {
 
                    parent->lptr=del->lptr;
                }
                else{
                    parent->lptr=del->rptr;
                }
            }
            else
            {
                if(del->lptr==NULL)
                {
                    parent->rptr=del->rptr;
                }
                else
                {
                    parent->rptr=del->lptr;
                }
            }
           
        }
        
    }
    free(del);
}

void main()
{
    int c,key,del_val;
    do
    {
        printf("\n\nenter choice\n1: insertion\n2: deletion\n3: preorder\n4: inorder\n5: postorder\n6: search\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                insertion();
                break;
            case 2:
            	delete(del_val);
            	break;
            case 3:
                printf("preorder traversal : ");
                preorder(root);
                break;
            case 4:
                printf("inorder traversal : ");
                inorder(root);
                break;
            case 5:
                printf("postorder traversal : ");
                postorder(root);
                break;
            case 6:

                printf("enter value to search : ");
                scanf("%d",&key);
                search(root,key);
            case 7:
                break;
            default:
            	printf("invalid choice");
        }
    }while(c!=7);
}

