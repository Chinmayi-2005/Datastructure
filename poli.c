#include<stdio.h>
int t1,t2,t3;
void add();
struct poli
{
int coeff;
int exp;
}p1[10],p2[10],p3[10];
void main()
{
int c,e,i,k=0,m=0;
printf("enter the 1st polinomeal\n");
printf("enter the no of terms : ");
scanf("%d",&t1);
for(i=0;i<t1;i++)
{
scanf("%d",&c);
scanf("%d",&e);
p1[i].coeff=c;
p1[i].exp=e;
}
for(i=0;i<t1-1;i++)
{
printf("%dx^%d+",p1[i].coeff,p1[i].exp);
k++;
}
printf("%dx^%d",p1[k].coeff,p1[k].exp);
printf("\nenter the 2nd polinomeal\n");
printf("enter the no of terms : ");
scanf("%d",&t2);
for(i=0;i<t2;i++)
{
scanf("%d",&c);
scanf("%d",&e);
p2[i].coeff=c;
p2[i].exp=e;
}
for(i=0;i<t2-1;i++)
{
printf("%dx^%d+",p2[i].coeff,p2[i].exp);
m++;
}
printf("%dx^%d\n",p2[m].coeff,p2[m].exp);
add();
}
void add()
{
int i=0,j=0,k=0,m,n=0;
while(i<t1&&j<t2)
{
if(p1[i].exp==p2[j].exp)
{
p3[k].exp=p1[i].exp;
p3[k].coeff=p1[i].coeff+p2[j].coeff;
i++;
j++;
k++;
}
else if(p1[i].exp<p2[j].exp)
{
p3[k].exp=p2[j].exp;
p3[k].coeff=p2[j].coeff;
j++;
k++;
}
else
{
p3[k].exp=p1[i].exp;
p3[k].coeff=p1[i].coeff;
i++;
k++;
}
}
while(i<t1)
{
p3[k].exp=p1[i].exp;
p3[k].coeff=p1[i].coeff;
i++;
k++;
}
while(j<t2)
{
p3[k].exp=p2[j].exp;
p3[k].coeff=p2[j].coeff;
j++;
k++;
}
printf("resultant polinomeal\n");
for(m=0;m<k-1;m++)
{
printf("%dx^%d+",p3[m].coeff,p3[m].exp);
n++;
}
printf("%dx^%d",p3[n].coeff,p3[n].exp);
}