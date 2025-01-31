//Service Project on C Language
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct account
{
    int ac_no;
    char name[30];
    int amt;
    int dd,mm,yy;
    char addr[30];
    int mobile_no;
    char gender[10];
};
struct account a[100];
int count=0;
void menu();
void create_account();
void Update_account();
void transaction_money();
void check_account();
void remove_account();
void account_list();
void last_details();

int main()
{
    int i,p,option,n,ch;
    for(i=1;i<=3;i++)
    {
        printf("This C Mini Project is developed by code with C team!\n");
    }
    printf("*********************************************\n");
    printf("*      WELCOME TO MANASA BANK                \n");
    printf("*********************************************\n");
    printf("Enter the password to log in:\n");
    scanf("%d",&p);
    if (p==2023)
    {
        while(1)
        {
            menu();
            printf("Enter your option: \n");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                create_account();
                break;
                case 2:
                Update_account();
                break;
                case 3:
                transaction_money();
                break;
                case 4:
                check_account();
                break;
                case 5:
                remove_account();
                break;
                case 6:
                account_list();
                break;
                case 7:
                last_details();
                break;
                default :
                printf(" Enter correct option!!!\n");
                break;
            }
        }
    }
    else
    {
        printf("Enter correct password to log in!!!\n");
    }    
    return(0);
}    
void menu()
{
    printf("     CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM     \n");
    printf("----------------------------------------------------\n");
    printf("        ||||| WELCOME TO THE MAIN MENU |||||        \n");
    printf("1. Create new account \n");
    printf("2. Update information of existing account \n");
    printf("3. For transaction \n");
    printf("4. Check the details of existing account \n");
    printf("5. Removing existing account \n");
    printf("6. View customer's list \n");
    printf("7. Exit \n");
}
void create_account()
{
    FILE *ptr=fopen("Account.txt","a");
    printf("**************************************\n");
    printf("          CREATE NEW ACCOUNT          \n");
    printf("**************************************\n");
    printf("Enter customer account number :\n");
    scanf("%d",&a[count].ac_no);
    printf("Enter customer name :\n");
    scanf("%s",a[count].name);
    printf("Enter amount :\n");
    scanf("%d",&a[count].amt);
    printf("Enter customer DOB :dd/mm/yy\n");
    scanf("%d/%d/%d",&a[count].dd,&a[count].mm,&a[count].yy);
    printf("Enter customer gender :\n");
    scanf("%s",a[count].gender);
    printf("Enter customer address :\n");
    scanf("%s",a[count].addr);
    printf("Enter customer mobile number :\n");
    scanf("%d",&a[count].mobile_no);
       
    printf("Account successfully created\n");
    fprintf(ptr,"        NEW ACCOUNT         \n");
    fprintf(ptr,"Customer account number:%d \n",a[count].ac_no);
    fprintf(ptr,"Customer name : %s \n",a[count].name);
    fprintf(ptr,"Amount : %d \n",a[count].amt);
    fprintf(ptr,"customer DOB : %d/%d/%d \n",a[count].dd,a[count].mm,a[count].yy);
    fprintf(ptr,"customer gender : %s \n",a[count].gender);
    fprintf(ptr,"customer address : %s \n",a[count].addr);
    fprintf(ptr,"customer mobile number : %d \n",a[count].mobile_no);
    fprintf(ptr,"Account created successfully\n"); 
    count++;
    
}
void Update_account()
{
    int n,i;
    FILE *ptr=fopen("Account.txt","a");
    printf("****************************************\n");
    printf("             TO UPDATE ACCOUNT          \n");
    printf("****************************************\n");
    printf("Enter customer account number \n:");
    scanf("%d",&n);
    
    for (i=0;i<count;i++)
    {
        if(n==a[i].ac_no) 
        {
            printf("Coustom account number:%d\n",a[i].ac_no);
            printf("Enter name :\n");
            scanf("%s",a[i].name);
            printf("Enter DOB :dd/mm/yy\n");
            scanf("%d/%d/%d",&a[i].dd,&a[i].mm,&a[i].yy);
            printf("Enter gender:\n");
            scanf("%s",a[i].gender );
            printf("Enter address :\n");
            scanf("%s",a[count].addr);
            printf("Enter mobile number :\n");
            scanf("%d",&a[i].mobile_no);
            printf("Account Successfully Updated\n");
            
            fprintf(ptr,"       UPDATED ACCOUNT       \n");
            fprintf(ptr,"Customer Name: %s\n",a[i].name);
            fprintf(ptr,"Customer Account number: %d\n",a[i].ac_no);
            fprintf(ptr,"Amount : %d \n",a[i].amt);
            fprintf(ptr,"Customer DOB: %d/%d/%d \n",a[i].dd,a[i].mm,a[i].yy);
            fprintf(ptr,"Customer gender : %s\n",a[i].gender);
            fprintf(ptr,"Customer address :%s\n",a[i].addr);
            fprintf(ptr,"Customer mobile number : %d\n",a[i].mobile_no);
            fprintf(ptr,"Account Updated Successfully\n");
            return;
    
        }
    }
    printf("Enter correct account number!!!\n");
    fprintf(ptr,"Enter correct account number!!!\n");
}
void transaction_money()
{
    int i,n,ch,amt;
    FILE *ptr=fopen("Account.txt","a");
    fprintf(ptr,"      FOR TRANSACTION      \n");
    printf("****************************************\n");
    printf("             FOR TRANSACTION MONEY      \n");
    printf("****************************************\n");
    printf("Enter customer account number :\n");
    scanf("%d",&n);
    for(i=0;i<count;i++) 
    {
       if(n==a[i].ac_no)
       {
           printf("1. Deposit\n2. Withdraw\nEnter your choice : \n");
           scanf("%d",&n);
           if(n==1)
           {
               printf("Enter ammount to Deposit :\n ");
               scanf("%d",&amt);
               a[i].amt += amt;
              printf("transaction Successfull\n");
              fprintf(ptr,"%d amount deposited in your account number %d.\n",amt,a[i].ac_no);
           }
           else
           {
               printf("Enter amount to Withdraw : \n");
               scanf("%d",&amt);
               if(amt <= a[i].amt)
               {
                   a[i].amt -= amt;
                   printf("transaction Successfull\n");
                   fprintf(ptr,"%d amount is Withdraw from your account of number %d.\n",amt,a[i].ac_no);
               }
               else
               {
               printf("Insufficient Balance!!!\n");
               printf("Transaction Failed\n");
               fprintf(ptr,"Transaction Failed\n");
               }
           }
           printf("Account Balance : %d\n",a[i].amt);
           fprintf(ptr,"Account balance: %d\n hm",a[i].amt);
           return;
       }
        
    }
    printf("Enter correct account number!!\n");
    fprintf(ptr,"Enter correct account number!!!\n");
}
void check_account()
{
    int j,n,i;
    FILE *ptr=fopen("Account.txt","a");
    fprintf(ptr,"     TO CHECK ACCOUNT     \n");
    printf("*****************************************\n");
    printf("            TO CHECK ACCOUNT             \n");
    printf("*****************************************\n");
    printf("Enter customer account number :\n");
    scanf("%d",&n);
     
    for (i=0;i<count;i++)
    {
        if(n==a[i].ac_no)
        {
            printf("Ac.no \tName     \t Amount \t DOB     \t Gender \t Address   \t Mobile_no    \n");
            printf("%d    \t%s       \t %d     \t %d/%d/%d\t%s      \t%s         \t%d            \n",a[i].ac_no,a[i].name,a[i].amt,a[i].dd,a[i].mm,a[i].yy,a[i].gender,a[i].addr,a[i].mobile_no);
            fprintf(ptr," ac_no \t  Name   \t Amount \t   DOB    \t Gender \t  Address  \t  Mobile_no \n");
            fprintf(ptr,"%d     \t%s       \t%d      \t %d/%d/%d \t %s     \t%s         \t %d         \n",a[i].ac_no,a[i].name,a[i].amt,a[i].dd,a[i].mm,a[i].yy,a[i].gender,a[i].addr,a[i].mobile_no);
            return;
        }
    }
    printf("Enter correct account number!!\n");
    fprintf(ptr,"Enter correct account number!!!\n");
    
   
}
void remove_account()
{
    int j,n,i;
    FILE *ptr=fopen("Account.txt","a");
    fprintf(ptr,"     TO REMOVE ACCOUNT      \n");
    printf("******************************************\n");
    printf("             TO REMOVE A ACCOUNT          \n");
    printf("******************************************\n");
    printf("Enter customer account number :\n");
    scanf("%d",&n);
    
    for (i=0;i<count;i++)
    {
        if(n==a[i].ac_no)
        {
            count--;
            for(j=i;j<count;j++)
            {
                a[j] = a[j+1];
            }
           printf("Account successfully Deleted\n");
           fprintf(ptr,"%d account is successfully deleted \n",a[i].ac_no);
           return;
            
        }
    }
    printf("Enter correct account number!!\n");
    fprintf(ptr,"Enter correct account number!!!\n");
}
void account_list()
{
    FILE *ptr=fopen("Account.txt","a");
    fprintf(ptr,"     ACCOUNTS LIST      \n");
    printf("*******************************************\n");
    printf("                  ACCOUNTS LIST            \n");
    printf("*******************************************\n");
    
    if(count!=0)
    {
        for(int i=0;i<count;i++)
        {
            
            printf("Ac.no \tName     \t Amount \t DOB     \t Gender \t Address   \t Mobile_no    \n");
            printf("%d    \t%s       \t %d     \t %d/%d/%d\t%s      \t%s         \t%d            \n",a[i].ac_no,a[i].name,a[i].amt,a[i].dd,a[i].mm,a[i].yy,a[i].gender,a[i].addr,a[i].mobile_no);
            fprintf(ptr,"  ac_no  \t Name   \t Amount  \t    DOB    \t Gender \t Address   \t mobile_no   \n");
            fprintf(ptr," %d      \t%s      \t %d      \t %d/%d/%d  \t %s     \t %s        \t %d          \n",a[i].ac_no,a[i].name,a[i].amt,a[i].dd,a[i].mm,a[i].yy,a[i].gender,a[i].addr,a[i].mobile_no);
        }
    }
    else
    {
        printf("Accounts are not available!!!\n");
        fprintf(ptr,"Accounts are not available!!!\n");
    }
    getch();
}
void last_details()
{
    FILE *ptr=fopen("Account.txt","a");
    printf("Exit\n");
    fprintf(ptr,"Exit\n");
    fclose(ptr);
    exit(0);  
}


















