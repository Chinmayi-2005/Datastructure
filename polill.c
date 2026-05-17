#include<stdio.h>
#include<stdlib.h>
struct poli
{
int coeff;
int exp;
struct poli *link;
}*poli1,*poli2,*poli3,*p1,*p2,*p3;
struct poli *createpoli()
{
struct poli *head=NULL,*new,*ptr;
int n,i,c,e;
printf("enter the No of term : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter the coefficient : ");
scanf("%d",&c);
printf("enter the exponent : ");
scanf("%d",&e);
new=(struct poli*)malloc(sizeof(struct poli));
new->coeff=c;
new->exp=e;
new->link=NULL;
if(head==NULL)
{
head=new;
ptr=new;
}
else
{
ptr->link=new;
ptr=new;
}
}
return head;

}
void display(struct poli *head)
{
struct poli *ptr1;
ptr1=head;
while(ptr1->link!=NULL)
{
printf("%dx^%d+",ptr1->coeff,ptr1->exp);
ptr1=ptr1->link;
}
printf("%dx^%d\n",ptr1->coeff,ptr1->exp);
}
struct poli *addpoli(struct poli *poli1,struct poli *poli2)
{
struct poli *head=NULL,*ptr=NULL;
p1=poli1;
p2=poli2;
while(p1!=NULL&&p2!=NULL)
{
p3=(struct poli *)malloc(sizeof(struct poli));
p3->link=NULL;
if(p1->exp==p2->exp)
{
p3->coeff=p1->coeff+p2->coeff;
p3->exp=p1->coeff;
p1=p1->link;
p2=p2->link;
}
else if(p1->exp>p2->exp)
{
p3->coeff=p1->coeff;
p3->exp=p1->exp;
p1=p1->link;

}
else
{
p3->coeff=p2->coeff;
p3->exp=p2->exp;
p2=p2->link;

}
if(head==NULL)
{
head=p3;
ptr=p3;
}
else
{
ptr->link=p3;
ptr=p3;
}
}
while(p1!=NULL)
{
p3=(struct poli *)malloc(sizeof(struct poli));
p3->coeff=p1->coeff;
p3->exp=p1->exp;
p3->link=NULL;
p1=p1->link;
ptr->link=p3;
ptr=p3;
}
while(p2!=NULL)
{
p3=(struct poli *)malloc(sizeof(struct poli));
p3->coeff=p2->coeff;
p3->exp=p2->exp;
p3->link=NULL;
p2=p2->link;
ptr->link=p3;
ptr=p3;
}
return head;
}
void main()
{
printf("enter the 1st polinomeal\n\n");
poli1=createpoli();
//printf("first poli : \n");
display(poli1);
printf("\nenter the 2nd polinomeal\n\n");
poli2=createpoli();
//printf("2nd poli : \n");
display(poli2);
poli3=addpoli(poli1,poli2); 
display(poli3);
}
