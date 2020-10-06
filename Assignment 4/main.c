#include<stdio.h>
#include<stdlib.h>
typedef struct employee
{
    int id;
    char name[30];
    long int salary;
    int flag;
    union ref
    {
        long int mob_no;
        char email[60];
    }r;
}employee;
int main()
{
    employee *e;
    int ch,ch1,ch2,l,l1,i,id,j;
    char dummy;
    do
    {
        printf("Enter Your Choice\n");
        printf("\t1.Create_a_database\n\t2.Display\n\t3.Update\n\t4.Delete_a_record\n\t5.Insert_a_record\n\t6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("How Many records you want to enter\n");
                scanf("%d",&l);
                l1=l;
                e=(employee*)malloc(l*sizeof(employee));
                for(i=0;i<l1;i++)
                {
                    printf("Enter The ID and NAME\n");
                    scanf("%d",&(e+i)->id);
                    for(j=0;j<l;j++)
                    {
                        if((e+i)->id==(e+j)->id&&j!=i)
                        {
                            printf("Please Enter a New Id\n");
                            scanf("%d",&(e+i)->id);
                            j=-1;
                        }
                    }
                    scanf("%c",&dummy);
                    scanf("%[^\n]s",&(e+i)->name);
                    printf("Enter The Salary::");
                    scanf("%ld",&(e+i)->salary);
                    printf("For MobNo press 1 and for email press 2\n");
                    scanf("%d",&ch1);
                    if(ch1==1)
                       {
                        scanf("%ld",&(e+i)->r.mob_no);
                        (e+i)->flag=1;
                       }
                    else if(ch1==2)
                        {
                         scanf("%s",(e+i)->r.email);
                         (e+i)->flag=2;
                        }
                }
                break;
        case 2: ch1=1;//default print will be all
                printf("Press 1 if you want to display all and 2 to display a specific record\n");
                scanf("%d",&ch1);
                if(ch1==1)
                {
                    printf("ID\tNAME\tSALARY\tMOB.NO OR EMAIL\n");
                    for(i=0;i<l1;i++)
                    {
                        printf("%d\t%s\t%ld\t",(e+i)->id,(e+i)->name,(e+i)->salary);
                        if((e+i)->flag==1)
                            printf("%ld\n",(e+i)->r.mob_no);
                        if((e+i)->flag==2)
                            printf("%s\n",(e+i)->r.email);
                    }
                }
                else if(ch1==2)
                {
                    printf("Enter the Id of the record you want to print\n");
                    scanf("%d",&id);
                    for(i=0;i<l1;i++)
                    {
                        if((e+i)->id==id)
                        {
                            printf("ID\tNAME\tSALARY\tMOB.NO OR EMAIL\n");
                            printf("%d\t%s\t%ld\t",(e+i)->id,(e+i)->name,(e+i)->salary);
                            if((e+i)->flag==1)
                                printf("%ld\n",(e+i)->r.mob_no);
                            if((e+i)->flag==2)
                                printf("%s\n",(e+i)->r.email);
                        }
                    }
                }
                break;
        case 3: printf("Enter the Id no of the employee\n");
                scanf("%d",&id);
                for(i=0;i<l1;i++)
                {
                    if((e+i)->id==id)
                    {
                        printf("Enter the name\n");
                        scanf("%c",&dummy);
                        scanf("%[^\t\n]s",&(e+i)->name);
                        printf("Enter The Salary::");
                        scanf("%ld",&(e+i)->salary);
                        printf("For MobNo press 1 and for email press 2\n");
                        scanf("%d",&ch1);
                        if(ch1==1)
                        {
                            scanf("%ld",&(e+i)->r.mob_no);
                            (e+i)->flag=1;
                        }
                        else if(ch1==2)
                        {
                            scanf("%s",(e+i)->r.email);
                            (e+i)->flag=2;
                        }
                        break;
                    }
                }
                break;
        case 4: printf("Enter the Id number of the employee\n");
                scanf("%d",&id);
                for(i=0;i<l1;i++)
                {
                    if((e+i)->id==id)
                    {
                        for(j=i;j<l1;j++)
                        {
                            *(e+j)=*(e+j+1);
                        }
                        l1--;
                        break;
                    }
                }
                e=(employee*)realloc(e,l1*sizeof(employee));
                break;
        case 5:     printf("Where do you want to insert the record?\n");
                    l1++;
                     e=(employee*)realloc(e,l1*sizeof(employee));
                    scanf("%d",&ch2);
                    if(ch2!=l1)
                    {
                    for(i=ch2-1;i<l1;i++)
                    {
                        *(e+i+1)=*(e+i);
                    }
                    printf("Enter The ID and NAME\n");
                    scanf("%d",&(e+ch2-1)->id);
                    for(j=0;j<l1;j++)
                    {
                        if((e+ch2-1)->id==(e+j)->id && j!=ch2-1)
                        {
                            printf("Please Enter a New Id\n");
                            scanf("%d",&(e+ch2-1)->id);
                            j=-1;
                        }
                    }
                    scanf("%c",&dummy);
                    scanf("%[^\t\n]s",&(e+ch2-1)->name);
                    printf("Enter The Salary::");
                    scanf("%ld",&(e+ch2-1)->salary);
                    printf("For MobNo press 1 and for email press 2\n");
                    scanf("%d",&ch1);
                    if(ch1==1)
                       {
                        scanf("%ld",&(e+ch2-1)->r.mob_no);
                        (e+ch2-1)->flag=1;
                       }
                    else if(ch1==2)
                        {
                         scanf("%s",(e+ch2-1)->r.email);
                         (e+ch2-1)->flag=2;
                        }
                    }
                else
                {
                    printf("Enter The ID and NAME\n");
                    scanf("%d",&(e+ch2-1)->id);
                    scanf("%c",&dummy);
                    scanf("%[^\t\n]s",&(e+ch2-1)->name);
                    printf("Enter The Salary::");
                    scanf("%ld",&(e+ch2-1)->salary);
                    printf("For MobNo press 1 and for email press 2\n");
                    scanf("%d",&ch1);
                    if(ch1==1)
                       {
                        scanf("%ld",&(e+ch2-1)->r.mob_no);
                        (e+ch2-1)->flag=1;
                       }
                    else if(ch1==2)
                        {
                         scanf("%s",(e+ch2-1)->r.email);
                         (e+ch2-1)->flag=2;
                        }
                }
                break;
        case 6: printf("-------END-------");
                break;
        default:printf("Wrong choice\n");
                break;
        }
        }while(ch!=6);

}
