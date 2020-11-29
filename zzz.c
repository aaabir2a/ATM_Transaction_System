/* ATM Transaction System */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


char card[20];
int pass;
char name[20];
char file_name[50];
char address[50];
int phone;
int amount;
int logged;

void timei()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
    printf(" \n the time is \n %s \n",buffer);


}


void password_change()
{
    void log_in ();
    int pass;
    printf("enter your new password \n");
    scanf("%d",&pass);
    FILE *fp = fopen(file_name, "w");
    fscanf(fp, " %s ",  name);
    fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
    fclose(fp);
    timei();

}

void new_account()
{
    system("cls");
    int pass,dp;
    char filename[20];
    char name[20];
    char address[50];
    int phone;
    FILE*fp;
    printf("enter file name");

    scanf("%s",filename);
    char buf[100];

    FILE *fp1=fopen("account.txt","r");
    char *p;

    while(fgets(buf,100,fp1))

    {
        p=strstr( buf, filename);
        if(p!=NULL)
        {
            printf("%s is already exist \n",p);

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
    printf("Enter the password \n");
    scanf("%d", &pass);

    fprintf(fp, "%d \n", pass);
    printf("Enter the amount you want to deposite\n");
    scanf("%d", &dp);
    fprintf(fp, " %d\n", dp);
    printf("enter the name \n");
    scanf("%s",name);
    printf("enter the address \n");
    scanf("%s",address);
    printf("enter the phone no. \n");
    scanf("%d",&phone);
    fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);


    fclose(fp);

    timei();

}


void checkbalance ()
{
    system("cls");
    system("COLOR 4D");
    char  name[20];
    int str1,dp;
    int year;


    FILE *fp = fopen(file_name, "r");


    rewind(fp);
    fscanf(fp, "%d %d %s ", &str1,&dp, name);
    printf("the dp is \n %d \n",dp);
    printf("the name is \n %s \n",name);
    timei();
}
void user()
{
    system("cls");
    int pp;
    char address[50];
    char name[50];
    int phone,str1,dp;
    FILE *fp = fopen(file_name, "r");
    fscanf(fp, "%d %d %s %s %s %d ", &pass,&amount, name,address,phone);
    printf("the dp is \n %d \n",dp);
    printf("the name is \n %s \n",name);
    printf("the address is %s",address);
    printf("the phone no %d",phone);

}

void withdraw ()
{
    system("cls");
    int with;
    printf("Enter the amount to deposit: ");
    scanf ("%d", &with);
    if(with>amount)
    {
        printf("sorry try again \n");
    }
    else
    {


        FILE *fp = fopen(file_name, "w");
        amount -= with;
        fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
        fclose(fp);
        timei();
    }
}

void deposite ()
{
    system("cls");
    int dip;
    printf("Enter the amount to deposit: ");
    scanf ("%d", &dip);
    FILE *fp = fopen(file_name, "w");
    fscanf(fp, "%d %d %s %s %d ", &pass,&amount, name,address,phone);
    amount += dip;

    fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
    fclose(fp);
    timei();

}

void transfer()
{
    system("cls");
    int trans;
    char transfer_account[20];
    printf ("Enter the account holder's name: ");
    scanf ("%s", transfer_account);
    printf ("Enter the amount: ");
    scanf ("%d", &trans);
    if(trans>amount)
    {
        printf("not ennough money \n");
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
        fscanf(fp,"%d %d %s %s %d", &temp_pass, &temp_am,name,address,&phone);
        fclose(fp);
        temp_am += trans;
        fp = fopen(file2, "w");
        fprintf(fp,"%d\n%d\n%s\n%s\n%d", temp_pass, temp_am,name,address,phone);

        fclose(fp);
        fp = fopen(file2, "r");

        fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
        fclose(fp);

        fp = fopen(file_name, "w");
        fscanf(fp, "%d %d %s %s %d ", &pass,&amount, name,address,phone);
        amount -= trans;
        fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
        fclose(fp);
        printf("%d tk transfer to %s successfully.\n", trans, transfer_account);
        fp = fopen(file_name, "r");
        fprintf(fp, "%d\n%d\n%s\n%s\n%d", pass, amount, name,address,phone);
        fclose(fp);
    }
    else
    {
        printf ("Account not found.\n");
        int ch;
        printf ("Press 1 to try again.\n");
        scanf ("%s", &ch);
        if (ch == 1)
            transfer();
    }
    timei();
}
}


void menu ()
{
    //system("cls");
    printf ("press 1 for log in.\n");
    printf("press 2 for create a new account. \n");
    printf ("press 3 for exit system.\n");

}

void display()
{

    printf ("Press 1 for check balance.\n");
    printf ("Press 2 for deposit.\n");
    printf ("Press 3 for withdraw money.\n");
    printf ("press 4 for transfer money.\n");

    printf ("Press 5 for log out.\n");
    printf("press 6 to change your password");
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
        fscanf(fp,"%d %d %s %s %d", &pass_check,&am,name,address,phone);
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
    char input[20];
    int passw;
    printf ("Enter the account name: ");
    scanf ("%s", input);
    strcpy (card, input);
    printf ("Enter your password: ");
    scanf ("%d", &pass);
    if (read_file(input))
    {
        printf ("logged in successfully\n");
        logged = 1;
    }
    else
    {
        printf ("input credential correctly.\n");
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
                case 7 :
                    user();
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
