#include<stdio.h>
#include<stdlib.h>
void read_matrix(int **a,int row,int column)//sci-hub.tw
{
    int i,j;
    printf("Enter the elements in a row wise fashion\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
}
void print_matrix(int**a,int row,int column)
{
   int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
}
void add_matrix(int **a,int row,int column,int **b,int row1,int column2)
{
    int i,j;
    //int **q;
    if(row==row1&&column==column2)
    {
        int **q=(int**)calloc(row,sizeof(int*));
        for(i=0;i<row;i++)
            *(q+i)=(int*)calloc(column,sizeof(int));

        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
              q[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("The result is:\n");
        print_matrix(q,row,column);
    }
    else
        printf("The matrices cannot be added\n");
}
void sub_matrix(int **a,int row,int column,int **b,int row1,int column2)
{
    int i,j;
    //int **q;
    if(row==row1&&column==column2)
    {
        int **q=(int**)calloc(row,sizeof(int*));
        for(i=0;i<row;i++)
            *(q+i)=(int*)calloc(column,sizeof(int));

        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
              q[i][j]=a[i][j]-b[i][j];
            }
        }
        printf("The result is:\n");
        print_matrix(q,row,column);
    }
    else
        printf("The matrices cannot be subtracted\n");
}
void multiply(int **a,int row,int column,int **b,int row1,int column2)
{
    int i,j,k,sum;
    if(column==row1)
    {
        int **q=(int**)calloc(row,sizeof(int*));
        for(i=0;i<row;i++)
            *(q+i)=(int*)calloc(column2,sizeof(int));
    sum=0;
     for(i=0;i<row;i++)
     {
         for(j=0;j<column2;j++)
            {
                for(k=0;k<column;k++)
                {
                    sum = sum + a[i][k] * b[k][j];
                }
                q[i][j]=sum;
                sum=0;
            }
    }
     printf("\n\n");
     print_matrix(q,row,column2);

    }
    else
        printf("The matrices cannot be multiplied\n");
}
void magic(int**a,int row,int column)
{
    if(row!=column)
        printf("The matrix can't be a magic square!!! \n");
    else
    {
        int z,count=0;
        z=(((row*row)+1)*row)/2;
        //printf("%d",z);
        int i,j,k,sum=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                sum+=a[i][j];
            }
            if(i==0)
                k=sum;
            if(sum==k&&sum==z)
                count++;
            sum=0;
        }
        for(i=0;i<column;i++)
        {
            for(j=0;j<row;j++)
            {
                sum+=a[i][j];
            }
            if(sum==k&&sum==z)
                count++;
            sum=0;
        }
        if(count==row+column)
            printf("Its a magic Sqaure\n\n");
        else
            printf("It's not a magic sqaure\n");
    }
}
void sadpo(int **a,int row,int column)
{
    int min_row,col,count=0;
    int i,j,k,p,flag=0;
    for (i=0;i<row;i++)
    {
        flag=0;
        min_row = a[i][0],col=0;
        for (j=1;j<column;j++)
        {
            if(min_row > a[i][j])
            {
                min_row = a[i][j];
                col = j;
            }
        }
        for (k=0;k<row;k++)
        {
          if(min_row<a[k][col])
                break;
        }
        //min1_row=min_row;
        for(p=0;p<row;p++)
        {
            if(min_row==a[p][col])
            {
                flag++;
            }
        }
        if (k == column&&flag==1)
        {
           printf("Value of Saddle Point::%d\n", min_row);
           count++;
        }
    }
    if(count==0)
        printf("No saddle point\n");
}
void transpose(int **a,int row,int column)
{
    int i,j;
    /*int **p=(int**)calloc(row,sizeof(int*));
    for(i=0;i<row;i++)
        *(p+i)=(int*)calloc(column,sizeof(int));
    */
    printf("The transpose of the matrix is::\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    //print_matrix(p,row,column);
}
int main()
{
    int row,column,row1,column1,i,**q;
    printf("Tell the No of Rows\n");
    scanf("%d",&row);
    int **p=(int**)calloc(row,sizeof(int*));
    printf("Tell the no of columns\n");
    scanf("%d",&column);
    for(i=0;i<row;i++)
        *(p+i)=(int*)calloc(column,sizeof(int));//why not **(p+i)?

    read_matrix(p,row,column);
    print_matrix(p,row,column);
    int ch;
    do
    {
        printf(":::MENU:::\n");
        printf("1.Add\n2.Subtract\n3.Multiply\n4.Magic Square\n5.Saddle point\n6.Transpose\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Tell the No of Rows\n");
                    scanf("%d",&row1);
                    q=(int**)calloc(row1,sizeof(int*));
                    printf("Tell the no of columns\n");
                    scanf("%d",&column1);
                    for(i=0;i<row1;i++)
                        *(q+i)=(int*)calloc(column1,sizeof(int));

                    read_matrix(q,row1,column1);
                    printf("\n");
                    print_matrix(q,row1,column1);
                    add_matrix(p,row,column,q,row1,column1);
                    break;
            case 2: printf("Tell the No of Rows\n");
                    scanf("%d",&row1);
                    q=(int**)calloc(row1,sizeof(int*));
                    printf("Tell the no of columns\n");
                    scanf("%d",&column1);
                    for(i=0;i<row1;i++)
                        *(q+i)=(int*)calloc(column1,sizeof(int));

                    read_matrix(q,row1,column1);
                    printf("\n");
                    print_matrix(q,row1,column1);
                    sub_matrix(p,row,column,q,row1,column1);
                    break;
            case 3: printf("Tell the No of Rows\n");
                    scanf("%d",&row1);
                    q=(int**)calloc(row1,sizeof(int*));
                    printf("Tell the no of columns\n");
                    scanf("%d",&column1);
                    for(i=0;i<row1;i++)
                        *(q+i)=(int*)calloc(column1,sizeof(int));

                    read_matrix(q,row1,column1);
                    printf("\n");
                    print_matrix(q,row1,column1);
                    multiply(p,row,column,q,row1,column1);
                    break;
            case 4: magic(p,row,column);
                    break;
            case 5: sadpo(p,row,column);
                    break;
            case 6: transpose(p,row,column);
                    break;
        }
    }while(ch!=7);
}
