#include<stdio.h>
void printset(int *p,int x)
{
    printf("\n");
    int i;
    int *a,*b,*c;
    for(a=p;a<p+x;a++)
    {
        for(b=a+1;b<p+x;b++)
        {
            if(*a==*b)
            {
                for(c=b;c<p+x;c++)
                {
                    *c=*(c+1);
                }
                x--;
                b--;
            }
        }
    }
    for(i=0;i<x;i++)
        printf("%d ",*(p+i));
    printf("\n\n");
}
int getset(int *p)
{
    int *a;
    int n;
    printf("Plzz tell the size of the set\n");
    scanf("%d",&n);
    printf("Kindly enter the elements of the set\n\n");
    for(a=p;a<p+n;a++)
        scanf("%d",a);
    a=p;
    printf("The entered set is:");
    printset(p,&n);
    return n;
}
void uni(int *p,int *q,int x,int y)
{
    int set3[100],i,j=0;
    for(i=0;i<x;i++)
        *(set3+i)=*(p+i);
    for(i=x;i<(x+y);i++)
       {
        *(set3+i) = *(q+j);
        j++;
       }
    printset(set3,i);
}
void inter(int *p,int *q,int x,int y)
{
    int *a,*b;
    int i=0,set3[100];
    for(a=p;a<p+x;a++)
    {
        for(b=q;b<q+y;b++)
        {
            if(*a==*b)
            {
                set3[i]=*b;
                i++;
            }
        }
    }
    printset(set3,i);
}
int diff(int *p,int *q,int x,int y)
{
    int *a,*b;
    int set3[100],i=0,k=0;
    for(a=p;a<p+x;a++)
    {
        i=0;
        for(b=q;b<q+y;b++)
        {
            if(*a==*b)
                i++;
        }
        if(i==0)
        {
            *(set3+k)= *a;
            k++;
        }
    }
    printset(set3,k);
}
void symdiff(int *p,int *q,int x,int y)
{
    int *a,*b;
    int set3[100],set4[100],i=0,k1=0,k2=0;
    for(a=p;a<p+x;a++)
    {
        i=0;
        for(b=q;b<q+y;b++)
        {
            if(*a==*b)
                i++;
        }
        if(i==0)
        {
            *(set3+k1)= *a;
            k1++;
        }
    }
    for(a=q;a<q+y;a++)
    {
        i=0;
        for(b=p;b<p+x;b++)
        {
            if(*a==*b)
                i++;
        }
        if(i==0)
        {
            *(set4+k2)= *a;
            k2++;
        }
    }
    uni(set3,set4,k1,k2);
}
int main()
{
    int set1[100],set2[100];
    int l1,l2;
    int n,ch;
    l1=getset(set1);
    l2=getset(set2);

    do
    {
        printf("What operation do you want to perform\n");
        printf("1.union\n2.intersection\n3.difference\n4.symmetric difference\n5.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("You have entered 1\n");
                    uni(set1,set2,l1,l2);
                    break;
            case 2: printf("You have entered 2\n");
                    inter(set1,set2,l1,l2);
                    break;
            case 3: printf("You have entered 3\n");
                    printf("If set1-set2 then enter 1 or if set2-set1 enter 2\n");
                    scanf("%d",&ch);
                    if(ch==1)
                        diff(set1,set2,l1,l2);
                    else if(ch==2)
                        diff(set2,set1,l2,l1);
                    else
                        printf("Enter a correct choice\n");
                    break;
            case 4: printf("You have entered 4\n");
                    symdiff(set1,set2,l1,l2);
                    break;
            case 5: printf("You have entered 5\n");
                    printf("Have a Nice day!!!!!!\n\n");
                    break;
            default:printf("You have Entered incorrect choice\n\n");
        }
    }while(n!=5);
}
