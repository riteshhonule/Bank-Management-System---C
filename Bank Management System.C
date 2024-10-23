// Bank Management System using c 
#include <stdio.h>  //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()
#include <time.h>   //time(),ctime()

char name[100];
int dip_amt, amt = 10000, acc_no;
int with_money;
int t_acc_no;
int trans_money;
char details[100];

void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void LastDetail();

void main()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    int choice;
    printf(" \t\t\t\tEnter your name :  ");
    gets(name);
    printf(" \t\t\t\tEnter your account no. :  ");
    scanf("\t\t%d", &acc_no);
    printf("\n");

    while (1)
    {
        printf("\t\t\t\t=> CHOICES : \n\n");
        printf("\t\t\t\t=> Your default balance is 10000/- \n\n");

        menu();
        int ch;
        printf(" \t\t\t\tEnter your choice :  \t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // system("cls");
            deposit_money();
            break;
        case 2:
            // system("cls");
            withdraw_money();
            break;

        case 3:
            // system("cls");
            transfer_money();
            break;

        case 4:
            // system("cls");
            account_details();
            break;

        case 5:
            // system("cls");
            LastDetail();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("*****Invalid choice*****");
        }
        // deposit_money();
    }
}
void menu()
{

    printf(" \t\t\t\t1.Deposit Money\n");
    printf(" \t\t\t\t2.Withdraw Money\n");
    printf(" \t\t\t\t3.Transfer Money\n");
    printf(" \t\t\t\t4.Account details\n");
    printf(" \t\t\t\t5.All Details\n");
    printf(" \t\t\t\t6.Exit\n\n");
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}

//!---------------------------------------------------------

void deposit_money()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    time_t tim;
    time(&tim);
    FILE *ptr = fopen("myaccountp5.txt", "a");
    printf(" \n\n\t\t\t\t******* DEPOSIT MONEY ********\n\n");
    printf("\t\t\t\tEnter the amount you want to deposit = \t");
    scanf("%d", &dip_amt);
    amt += dip_amt;
    printf(" \n\n\t\t\t\tyour money deposited Successfully\n");
    printf(" \n\n\t\t\t\tyour current total balance is =  %d\n", amt);
    fprintf(ptr, "RS. %d has been deposited to your account .", dip_amt);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tim));
    fclose(ptr);
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");

    printf("\n\n\t\t\t Press ENTER to countinue\n\n");
    getch();
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}

//!---------------------------------------------------------
void withdraw_money()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    time_t tim;
    time(&tim);
    FILE *ptr = fopen("myaccountp5.txt", "a");
    printf("\n\n\t\t\t\t******** WITHDRAW MONEY *********\n");
    printf(" \t\t\t\tyour current total balance is =  %d\n", amt);
    printf("\t\t\t\tEnter the money you want to withdraw  =  ");
    scanf("\t%d", &with_money);
    printf("\n");
    if (with_money > amt)
    {
        printf("\t\t\t\t***** Insufficient Amount *****");
    }
    amt -= with_money;
    printf("\n");
    printf("\t\t\t\tYour total current balance = %d", amt);
    fprintf(ptr, "RS. %d has been Withdrawn form your account .", with_money);
    fprintf(ptr, "Date/Time of transaction is :  %s\n", ctime(&tim));
    fclose(ptr);
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    printf("\n\n\t\t\t Press ENTER to countinue");
    getch();
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}

//!---------------------------------------------------------
void transfer_money()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    time_t tim;
    time(&tim);
    FILE *ptr = fopen("myaccountp5.txt", "a");
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");

    printf("\t\t\t\t*********** Transfer Money ************\n");
    printf("\t\t\t\tEnter Account Number to tranfer money :  \t");
    scanf("%d", &t_acc_no);
    printf("\t\t\t\tEnter  much amount you want to transfer :  \t");
    scanf("%d", &trans_money);
    if (amt < trans_money)
    {
        printf("\t\t\t\tYou don't have enough money to transfer ... Balance is => %d\n", amt);
    }
    else
    {
        amt -= trans_money;
        printf("\t\t\t\tYour amount has been tranferred in 10 second wait....\n");
        printf("\t\t\t\tYour total balance is %d\n", amt);
        fprintf(ptr, "RS. %d has been transferred form your account .", trans_money);
        fprintf(ptr, "Date/Time of transaction is :  %s\n\n", ctime(&tim));
        fclose(ptr);
        printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    }
    printf("\n\n\t\t\t Press ENTER to countinue\n\n");
    getch();
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}

//!---------------------------------------------------------
void account_details()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    char details[100];
    printf("\n\t\t\t\t************* Account Details ***************\n");
    printf("\n\t\t\t\tName         : %s\n", name);
    printf("\t\t\t\tAccount No.    : %d\n", acc_no);
    printf("\t\t\t\tTotal balance  = %d\n\n", amt);
    printf("\n\t\t\t Enter yes to save your details   :  ");
    scanf("%s", &details);
    if (details == "yes")
    {
        printf("\n\n\t\t\t\t\t*******Your Details has been saved successfully*******\n");
    }
    else
    {
        printf("\n\t\t\t\t\t******* Thank you!*******\n");
    }

    // if (details == "yes")
    // {
    //     FILE *ptr = fopen("Account_details.txt", "w");
    //     fprintf(ptr, "\n\t\t\t\t************* Account Details ***************\n");
    //     fprintf(ptr, "\n\t\t\t\tName          : %s\n", name);
    //     fprintf(ptr, "\t\t\t\t Account No.    : %d\n", acc_no);
    //     fprintf(ptr, "\t\t\t\t Total balance  = %d\n\n", amt);
    //     fclose(ptr);
    //     menu();
    // }
    // else
    // {
    //     exit(0);
    //     menu();
    // }
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    printf("\t\t\tPress any key.....");
    getch();
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}

void LastDetail()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    printf("\n\t\t\t\t************* Last Details ***************\n");
    printf("\n\t\t\t\tName         : %s\n", name);
    printf("\t\t\t\tAccount No.    : %d\n", acc_no);
    printf("\t\t\t\tTotal balance  = %d\n\n", amt);
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
    printf("\t\t\tPress any key.....");
    getch();
    printf("\n\t\t--------------------------------------------------------------------------------\n\n");
}