#include<stdio.h>
#include<stdlib.h>
int read(char *p)
{
    char *a=p,ch,temp;
    int i=0;
    printf("Plzz Enter the string::");
    do
    {
        scanf("%c",&ch);
        *a=ch;
        a++;
        i++;
    }while(ch!='\n');
    a--;
    *a='\0';
    printf("\n");
    return i;
}
void printset(char *p)
{
    printf("\t\tThe string entered is::%s\n\n",p);
}
void add(char s1[100],char s2[100])
{
    char s3[100];
    int i,j,k=0;
    for(i=0;s1[i]!='\0';i++)
        s3[i]=s1[i];
    s3[i]=(char)(32);
    i++;
    for(j=i;s2[k]!='\0';j++)
    {
     s3[j]=s2[k];
     k++;
    }
    s3[j]='\0';
    printf("\t\tThe new string is ::%s\n",s3);
}
void reverse(char s1[],int x,char s3[])
{
    int i,j;
    for(i=0,j=x-2;j>=0;i++,j--)
        s3[i]=s1[j];
    s3[i]='\0';
}
void compare(char s1[],char s2[],int x,int y)
{
    int i,flag=0;
    if(x==y)
    {
        for(i=0;i<x-1;i++)
        {
            if(s1[i]!=s2[i])
                flag++;
        }
        if(flag==0)
            printf("YES\n\n");
        else
            printf("NO\n\n");
    }
    else
    {
        printf("NO\n\n");
    }
}
void ifpal(char s1[],int x,char s3[])
{
  reverse(s1,x,s3);
  compare(s1,s3,x,x);
}
void vowels(char s1[],int x)
{
    char s[]={'a','e','i','o','u','\0'};
    char s3[20];
    int i,j,k=0,c,count;
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<5;j++)
        {
            if(s1[i]==s[j])
            {
                s3[k]=s[j];
                k++;
            }
        }
    }
    count=k;
    s3[k]='\0';
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(s3[i]==s3[j])
            {
                for(c=j;c<k;c++)
                {
                    s3[c]=s3[c+1];
                }
                k--;
                j--;
            }
        }
    }
    printf("There are %d number of vowels which are::",count);
    printf("%s",s3);
    printf("\n");
}
void sub(char s1[],char s3[],int l3,int x)
{
    int i,j;
    printf("\n");
    for (i=0,j=0;s1[i]!='\0'&&s3[j]!='\0';i++)
    {
        if (s1[i]==s3[j])
        {
            j++;
        }
        else
        {
            j=0;
        }
    }

    if (j==l3-1)
    {
        printf("Substring found in string at position %d\n",i-j+1);
    }
    else
    {
        printf("Substring not found in string\n");
    }
}
int main()
{
    int l1,l2,l3,ch,n,x=1,y=2;
    char s1[100],s3[100],s4[100],s5[100],dummy;
    char s2[100]={'k'};
    l1=read(s1);
    printset(s1);
    do
    {
        printf("What operation do you want perform now??\n\n");
        printf("1.Find length\n2.Add a new string\n3.Reverse\n4.Compare\n5.If palindrome??\n6.Find vowels\n7.Substring\n8.Enter new string\n9.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("You have entered choice 1\n");
                    printf("The length of the string is %d \n",l1-1);
                    break;
            case 2: printf("You have entered choice 2\n");
                    scanf("%c",&dummy);
                    l2=read(s2);
                    printset(s2);
                    add(s1,s2);
                    break;
            case 3: printf("You have entered choice 3\n");
                    reverse(s1,l1,s3);
                    printset(s3);
                    break;
            case 4: printf("You have entered choice 4\n");
                    scanf("%c",&dummy);
                    //free(s2);
                    l2=read(s2);
                    compare(s1,s2,l1,l2);
                    break;
            case 5: printf("You have entered choice 5\n");
                    ifpal(s1,l1,s3);
                    break;
            case 6: printf("You have entered choice 6\n");
                    vowels(s1,l1);
                    break;
            case 7: printf("You have entered choice 7\n");
                    scanf("%c",&dummy);
                    l3=read(s5);
                    sub(s1,s5,l3,x);
                    break;
            case 8: printf("You have entered choice 8\n");
                    printf("Enter the new string::");
                    scanf("%c",&dummy);
                    l1=read(s1);
                    break;
            case 9: printf("You have entered choice 9\n");
                    printf("\t\t----The End!@!@!@!@!");
                    break;
            default:printf("Plzz enter a valid option!!\n");
                    break;
        }
    }while(ch!=9);

}
