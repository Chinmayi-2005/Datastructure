#include<stdio.h>
#include<stdlib.h>
void main()
{
    int item,a[20],N=0,n,i,p,x,y,lc,rc,j,temp;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        N++;
        a[N]=item;
        i=N;
        p=i/2;
        while(p>0&&a[i]>a[p])
        {
            temp=a[i];
            a[i]=a[p];
            a[p]=temp;
            i=p;
            p=i/2;
        }
    }
    printf("The passes:\n");
    while(N>1)
    {
        temp=a[1];
        a[1]=a[N];
        a[N]=temp;
        N--,i=1;
        while(i<=N)
        {
            lc=2*i,rc=2*i+1;
            if(lc<=N)
            {
                x=a[lc];
            }
            else
            {
                x=-1;
            }
            if(rc<=N)
            {
                y=a[rc];
            }
            else
            {
                y=-1;
            }
            if(a[i]>=x&&a[i]>=y)
            {
                break;
            }
            else
            {
                if(x>=y&&a[i]<=x)
                {
                    temp=a[i];
                    a[i]=a[lc];
                    a[lc]=temp;
                    i=lc;
                }
                else if(y>x&&a[i]<=y)
                {
                    temp=a[i];
                    a[i]=a[rc];
                    a[rc]=temp;
                    i=rc;
                }
            }
        }
    
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
printf("Sorted array\n");
for(i=1;i<=n;i++)
{
    printf("%d\t",a[i]);
}
}