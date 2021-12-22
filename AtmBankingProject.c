#include<stdio.h>
#include<conio.h>           //for use getch() and system("CLS")
#include<stdlib.h>
#include<time.h>          //for use time,date show in output
#include<windows.h>
#include<math.h>      //for use mathmetically equations

int no_of_person;    //how many member store info. in file global

struct UserInfo          //Store User Information variable
{
    char name[25];
    int pinNumber,cardNumber,balance;
    double amount;
};
registation()
{
    FILE *file;
    file = fopen("User-information.txt","w");
    if(file == NULL)
    {
        printf("File does not created and opened successfully\n");
    }
    else
    {
        printf("How many number of person information store in file : ");
        scanf("%d",&no_of_person);
        struct UserInfo user[no_of_person];  //Input for no_of_person information using structure
        for(int i = 0 ; i<no_of_person ; i++)
        {
            printf("Store person information %d : \n",i + 1);
            printf("Input card used person name : ");
            fflush(stdin);
            gets(user[i].name);
            printf("Input card number is : ");
            scanf("%d",&user[i].cardNumber);
            printf("Input pin number :  ");
            scanf("%d",&user[i].pinNumber);
            printf("Input your Balance : ");
            scanf("%d",&user[i].balance);
            fwrite(&user[i],sizeof(user[i]),1,file);
            printf("\n");
        }
        fclose(file);
        printf("Now,Sign-in with Pin number\n");
        printf("\nPress any key to continue......................\n");
        getch();
        system("CLS");
        signIn();

    }
}

signIn()
{
    FILE *file;
    file = fopen("User-information.txt","r");
    if(file == NULL)
    {
        printf("File does not created and opened successfully\n");
    }
    else
    {
        struct UserInfo user;
        int pin;
        printf("Please !!!!!!!!!!......enter your 6 digits Pin/Password number : ");
        scanf("%d",&pin);
        while(fread(&user,sizeof(user),1,file))
        {
            if(pin == user.pinNumber)
            {
                printf("\nCongratulation !!!!!!!!.....Your ATM card successfully sign-in\n");
                printf("Now, you continue your banking system.....!!\n");
                getch();
                system("CLS");
                time_t currentTime;
                time(&currentTime);
                printf("\n\t\t\t\t\t\t\t\t\t\tDate : %s",ctime(&currentTime));
                printf("Your current account balance is : %d\t\t\t\t\t\tUser-name : %s\n",user.balance,user.name);
                printf("\t\t\t\t\t\t\t\t\t\tCard-number : %d\n",user.cardNumber);
                int opt;
                printf("Press 1 for withdraw...\nPress 2 for send money...\n");
                scanf("%d",&opt);
                int total = 0;
                if(opt == 1)
                {
                    int tk;
                    printf("Enter your amount : ");
                    scanf("%d",&tk);
                    switch(tk)
                    {
                    case 1000 :
                        total = total + tk;
                        break;
                    case 500 :
                        total = total + tk;
                        break;
                    case 200 :
                        total = total + tk;
                        break;
                    case 100 :
                        total = total + tk;
                        break;
                    }
                }
                else if(opt == 2)
                {
                    printf("Next time add to send option\n");
                }
                else
                {
                    printf("Sorry your press option is incorrect....Please try again !!!\n");
                }
                int current_balance = user.balance - total;
                printf("Your previous balance was : %d\n",user.balance);
                printf("Your withdraw balance is : %d\n",total);
                printf("Now,Current balance is : %d\n",current_balance);
                break;

            }
            else
            {
                continue;
                printf("Sorry !!!!!! Your Pin number is not correct\n");
                printf("Please !!!!!!!!!.....enter your correct pin/password\n");
            }

        }

    }
    fclose(file);
}

int main()
{
    int cho;
    printf("Press '1' for Registration in ATM card............ \nPress '2' for Login ATM card.........\n");
    scanf("%d",&cho);
    if(cho == 1)
    {
        system("CLS");
        registation();
    }
    else if(cho == 2)
    {
        system("CLS");
        signIn();
    }
    else
        printf("Incorrect option !!!!!!!!!!!.......Please correct option selected");


    getch();
}

