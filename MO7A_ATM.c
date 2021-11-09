#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "windows.h"
void space_fun(x);
int withdrawal(with_amount);
int deposite(dep_amount);
int scan(float y);
float balance =50000.00;
int main()
{ 
    int pin=123,count=0,continue_transaction=1,user_pin,option,mode=0;
    float dep_amount,with_amount;
    time_t now;
    time(&now);
    space_fun(1);
    printf("\t\t\t\t\t\t\t      %s",ctime(&now));
    printf("\t\t\t\t\t\t\t=========WELCOME TO MO7A ATM=========\t\t\t\t\t\t\t");
    space_fun(6);
    printf("ENTER '1'FOR LIGHT MODE AND '2' FOR DARK MODE: \n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:
        {
            system("color 7D");
            break;
        }
        case 2:
        {
            system("color 0F");
            break;
        }
        default:
            {
                printf("INVALID INPUT!!\n");
                exit(0);
            }


    }

    
    printf("please enter the Pin: \n");
    scanf("%d",&user_pin);
    printf("the value entered is %d \n",user_pin);
    
    do
    {
        if (user_pin!= pin)
        {
            Beep(400,500);
            printf("WRONG PIN!! PLEASE ENTER YOUR PIN AGAIN\n");
            count++;
            scanf("%d",&user_pin);
            printf("the value entered is %d \n",user_pin);

        }
        else
            break;
        
    }while(count<3);



     if (count>=3)
        {
            printf("YOU RAN OUT OF TRIES,PLEASE CALL THE CUSTOMER SERVICE FOR MORE INFORMATION");
             space_fun(5);
            printf("\t\t\t\t\t\t\t=========THANKS FOR USING THE MO7A ATM=========\t\t\t\t\t\t\t");
            exit(0);
        }
        while(continue_transaction!=0)
        {
        printf("\t\t\t\t\t\t\t\t==========THE TRANSACTIONS AVAILABLE==========\t\t\t\t\t\t\t\t\n");
        space_fun(3);
        printf("\t\t\t\t\t\t\t1.WITHDRAWAL\n");
        printf("\t\t\t\t\t\t\t2.DEPOSITE\n");
        printf("\t\t\t\t\t\t\t3.CHECK BALANCE\n");
        printf("please enter your choice: ");
        scanf("%d",&option);

     switch(option)
        {
            case 1:
            {
                space_fun(3);
                printf("PLEASE ENTER THE AMOUNT YOU WANT TO WITHDRAW FROM YOUR BALANCE: \n");
                scanf(" %.2f",&with_amount);
                if(with_amount<0)
                {
                    printf("INVALID VALUE !!");
                    break;
                }
                space_fun(3);
                withdrawal(with_amount);
                break;
            }
            case 2:
            {
                space_fun(3);
                printf("PLEASE ENTER THE AMOUNT YOU WANT TO DEPOSITE INTO YOUR BALANCE: \n");
                scanf(" %f",&dep_amount);
                if(dep_amount<0)
                {
                    printf("INVALID VALUE !!");
                    break;
                }
                space_fun(3);
                deposite(dep_amount);
                break;
            }
            case 3:
            {
                space_fun(3);
                printf("YOUR BALANCE IS %.2f L.E\n",balance);
                break;
            }
            default:
            {
                printf("INVALID INPUT!!\n");
            }
        }
        printf("\t\t\t\t\t\t\t DO YOU WANT TO DO ANOTHER TRANSACTION? [1]YES/[0]NO \t\t\t\t\t\t\t\n");
        scanf("%d",&continue_transaction);
        space_fun(3);
        }
    space_fun(5);
    printf("\t\t\t\t\t\t\t=========THANKS FOR USING THE MO7A ATM=========\t\t\t\t\t\t\t");




}
int withdrawal(with_amount)
{
    if(with_amount>balance)
    {
        printf("INSUFFICIENT BALANCE!\n");
        Beep(400,500);
    }
    else
    {
        balance-=with_amount;
        printf("YOU HAVE WITHDRAWED %.2f L.E, YOUR BALANCE IS NOW %.2f L.E\n",with_amount,balance);
        return balance;
    }
    return balance;
}
void space_fun(x)
{
    int i;
    for(i=1;i<=x;i++)
    {
        printf("\n");
    }
}
int deposite(dep_amount)
{
    balance+=dep_amount;
     printf("YOU HAVE DEPOSITED %.2f L.E, YOUR BALANCE IS NOW %.2f L.E\n",dep_amount,balance);
    return balance;
}