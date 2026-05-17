#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex;
    struct node*link;
}*GPTR[50],*ptr,*p;
int front=-1,rear=-1,top=-1,u,i=0,dfs[20],s[20],bfs[20],q[20],bf,v1,df,k,n,m,og[20],j,op,v;
void graph_rep();
void DFS(int);
void BFS(int);
void enqueue(int it);
int dequeue();
void push(int);
int search(int[20],int,int);
int pop();
int main()
{
    do
    {
        printf("\nEnter MENU\n1-Graph_Representation\n2-DFS\n3-BFS\n4-Quit\n");
        printf("Enter option:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            graph_rep();
            break;
            case 2:
            printf("Enter the vertex from which traversal is to begin");
            scanf("%d",&df);
            DFS(df);
            break;
            case 3:
            printf("Enter the vertex from which traversal is to begin");
            scanf("%d",&bf);
            BFS(bf);
            break;
            case 4:
            printf("program terminated");
            break;
        }
    }while(op<4);
}
void graph_rep()
{
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        GPTR[i]=NULL;
    }
    for(i=1;i<=n;i++)
    {
        printf("Enter the number of ADJACENT vertices for vertex %d",i);
        scanf("%d",&m);
        ptr=GPTR[i];
        for(j=1;j<=m;j++)
        {
            printf("Enter the vertex:");
            scanf("%d",&v);
            struct node*p=(struct node*)malloc(sizeof(struct node));
            p->vertex=v;
            p->link=NULL;
            if(ptr==NULL)
            {
                GPTR[i]=p;
                ptr=p;
            }
            else
            {
                ptr->link=p;
                ptr=p;
            }
        }
    }
}
void DFS(int v1)
{
    int u=v1,j=0;
    push(u);
    while(top!=-1)
    {
        u=pop();
        if(search(dfs,j,u)==0)
        {
            dfs[j]=u;
            j++;
            ptr=GPTR[u];
            while(ptr!=NULL)
            {
                push(ptr->vertex);
                ptr=ptr->link;
            }
        }
    }
    dfs[j]=0;
    for(i=0;i<n;i++)
    {
        if(dfs[i]!=0)
        {
            printf("%d\t",dfs[i]);
        }
    }
}
void BFS(int v1)
{
    int u=v1,j=0;
    enqueue(u);
    while(front!=-1)
    {
        u=dequeue();
        if(search(bfs,j,u)==0)
        {
            bfs[j]=u;
            j++;
            ptr=GPTR[u];
            while(ptr!=NULL)
            {
                enqueue(ptr->vertex);
                ptr=ptr->link;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(bfs[i]!=0)
        {
            printf("%d\t",bfs[i]);
        }
    }
}
void push(int m)
{
    top++;
    s[top]=m;
}
int pop()
{
    int h;
    h=s[top];
    top--;
    return h;
}
int dequeue()
{
    int it;
    if(front==rear)
    {
        it=q[front];
        front=-1;
        rear=-1;
    }
    else
    {
        it=q[front];
        front++;
    }
    return it;
}
void enqueue(int it)
{
    if(front==-1&&rear==-1)
    {
        rear++;
        q[rear]=it;
        front++;
    }
    else
    {
        rear++;
        q[rear]=it;
    }
}
int search(int og[],int size,int o)
{
    for(k=0;k<size;k++)
    {
        if(og[k]==0)
        {
            return 1;
        }
    }
    return 0;
}
