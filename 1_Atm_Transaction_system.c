/* ATM Transaction System */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


char card[20];
int pass;
char name[20];
char file_name[50];
int amount;
int logged;




void password_change()
{
    void log_in ();
    int pass;
    printf("\n \n \t Enter your new pin no(0-9) : \n");
    scanf("%d",&pass);
    FILE *fp = fopen(file_name, "w");
    fscanf(fp, " %s ",  name);
    fprintf(fp, "%d\n%d\n%s", pass, amount,name);
    fclose(fp);


}

void new_account()
{
    system("cls");
    int pass,dp;
    char filename[20];
    char name[20];
    FILE*fp;
    printf("\n \n \t Enter file name : \n");

    scanf("%s",filename);
    char buf[100];

    FILE *fp1=fopen("account.txt","r");
    char *p;

    while(fgets(buf,100,fp1))

    {
        p=strstr( buf, filename);
        if(p!=NULL)
        {
            printf("\n \n \t This account already exists \n",p);

            return;
        }
    }
    fclose(fp1);
    fp1=fopen("account.txt","a");
    fprintf(fp1,"\n%s\n",filename);
    fclose(fp1);

    strcat(filename,".txt");

    fp=fopen(filename,"w");
    if (fp == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("\n \n \t Enter the pin no(0-9) :\n");
    scanf("%d", &pass);

    fprintf(fp, "%d \n", pass);
    printf("Enter the amount you want to deposit :\n");
    scanf("%d", &dp);
    fprintf(fp, " %d\n", dp);
    printf("enter the name: \n");
    scanf("%s",name);
    fprintf(fp,"%s",name);


    fclose(fp);



}


void checkbalance ()
{
    system("cls");
    system("COLOR 6A");
    char  name[20];
    int age;
    int str1,dp;
    FILE *fp = fopen(file_name, "r");
    fscanf(fp, "%d %d %s ", &str1,&dp, name);
    printf("\n \n          The deposit is: %d \n ",dp);
    printf("\n          The name is: %s \n",name);


}

void withdraw ()
{
    system("cls");
    system("COLOR 72");
    int with;
    printf("\n \n \t \t Enter the amount to withdraw: ");
    scanf ("%d", &with);
    if(with>amount)
    {
        printf("\n \n \t \t Sorry try again: \n");
    }
    else
    {


        FILE *fp = fopen(file_name, "w");
        amount -= with;
        fprintf(fp, "%d\n%d\n%s", pass, amount, name);
        fclose(fp);

    }
}

void deposite()
{
    system("cls");
    system("COLOR 0D");
    int dip;
    printf("\n \n           \tEnter the amount to deposit: ");
    scanf ("%d", &dip);
    FILE *fp = fopen(file_name, "w");
    fscanf(fp, "%d %d %s ", &pass,&amount, name);
    amount += dip;

    fprintf(fp, "%d\n%d\n%s", pass, amount, name);
    fclose(fp);

}

void transfer()
{
    system("cls");
    system("COLOR D0");
    int trans;
    char transfer_account[20];
    printf ("\n \n \t \t Enter the account holder's name: ");
    scanf ("%s", transfer_account);
    printf ("\n \n \t \t Enter the amount: ");
    scanf ("%d", &trans);
    if(trans>amount)
    {
        printf("\n \n \t \t Sorry not enough money on your account\n");
    }
    else
    {


    char file2[20] = "F:/";
    strcat (file2, transfer_account);
    strcat (file2, ".txt");

    FILE *fp = fopen(file2, "r");
    if (fp != NULL)
    {
        int temp_pass, temp_am;
        fscanf(fp,"%d %d %s", &temp_pass, &temp_am,name);
        temp_am += trans;
        fp = fopen(file2, "w");
        fprintf(fp,"%d\n%d\n%s", temp_pass, temp_am,name);

        fclose(fp);
        fp = fopen(file2, "r");
        fprintf(fp,"%d\n%d\n%s", temp_pass, temp_am,name,name);
        fprintf(fp, "%d\n%d\n%s", pass, amount, name);
        fclose(fp);

        fp = fopen(file_name, "w");
        fscanf(fp, "%d %d %s ", &pass,&amount, name);
        amount -= trans;
        fprintf(fp, "%d\n%d\n%s", pass, amount,name);

        fclose(fp);
        printf("\n \n \t \t %d tk transfered to %s successfully \n", trans, transfer_account);
        fp = fopen(file_name, "r");
        fprintf(fp, "%d\n%d\n%s", pass, amount, name);
        fclose(fp);
    }
    else
    {
        printf ("\n \n \t \t Account not found\n");
        int ch;
        printf ("\n \n \t \t Press 1 to try again.\n");
        scanf ("%s", &ch);
        if (ch == 1)
            transfer();
    }

}
}


void menu ()
{
    //system("cls");

    printf("\n\t                ____________________________________________________________________  \n\n");
            printf("\t\t\t----------------------Welcome to our ATM service--------------------- \n \n \n \n\n\n");
    system("color 6F");
    printf ("                    Please press 1 for logging in: \n \n \n");
    printf("                    Please press 2 for create a new account: \n \n \n");
    printf ("                    Please press 3 for exit system: \n \n  \n    \t \t\t");

}

void display()
{

    printf ("\n \n            Please press 1 for check balance:\n");
    printf ("\n \n            Please press 2 for deposit cash:\n");
    printf ("\n \n            Please press 3 for withdraw money:\n");
    printf ("\n \n            Please press 4 for transfer money:\n");

    printf ("\n \n            Please press 5 for log out:\n");
    printf("\n \n            Please press 6 to change your pin no: \n    \t \t \t");
}

int read_file (char c[20])
{
    int pass_check;
    int am;
    strcpy(file_name, "F:/");
    strcat(file_name, c);
    strcat (file_name, ".txt");
    FILE *fp = fopen(file_name, "r");
    if (fp != NULL)
    {
        fscanf(fp,"%d %d %s", &pass_check,&am,name);
        if (pass == pass_check)
        {
            amount = am;
            fclose(fp);
            return 1;
        }
        else
        {
            fclose(fp);
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void log_in ()
{
    system("cls");
    system("color 4D");
    char input[20];
    int passw;
    printf ("\n \n           Enter the account name: ");
    scanf ("%s", input);
    strcpy (card, input);
    printf ("\n \n           Enter your pin no(0-9): ");
    scanf ("%d", &pass);
    if (read_file(input))
    {
        printf ("  \n \n          Logged in successfully: ");
        printf("\n \n          Your options: \n ");
        logged = 1;
    }
    else
    {
        printf ("            Error!Please input credential correctly\n");
    }
}

int main ()
{
    int menue, choice;
    while (1)
    {
        menu();
        logged = 0;
        scanf("%d", &menue);
        if (menue == 1)
        {
            while (logged != 1)
                log_in();
            choice = 0;
            while (choice != 5)
            {
                display();
                scanf ("%d", &choice);
                switch (choice)
                {
                case 1 :
                    checkbalance();
                    break;
                case 2 :
                    deposite();
                    break;
                case 3 :
                    withdraw();
                    break;
                case 4 :
                    transfer();
                    break;
                case 5 :
                    printf ("logged out.\n");
                    break;

                case 6 :
                    password_change();
                    break;
                }
            }
        }
        else if(menue==2)
            new_account();
        else
            return 0;
    }
}
