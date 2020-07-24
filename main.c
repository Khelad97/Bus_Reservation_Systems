#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int n ; // number of process
int sum, pass,i,cancel,bobus;
int bus_number[6]= {0,1,2,3,4,5};
int bus_seat[6]= {40,30,25,50,50};
int bus_avai[6]= {20,15,22,14,3};
int(*ptr_aval)[6];
char name[];

int main()
{
    printf(" \t \t \t \t \t Bus Reservation System \n ");
    password();

    while(1)
    {
        intro_system();
        switch (n)
        {
        case 1 :
            printf("please enter your bus number : ");
            int bus ;
            scanf("%i",&bus);
            Bus_view(bus);
            break;
        case 2 :
            printf("choose your Bus :  ");
            int book ;
            scanf("%i",&book);
            printf("enter number of seat in  Bus :  ");
            int seat ;
            scanf("%i",&seat);
            printf("Enter name: ");
            scanf("%s", name);
            booking(book,seat,name);

            break;
        case 3 :

            printf("Do you want to cancel booking [1,2]  ? ");
            int cmd;
            scanf("%d",&cmd);
            cancel_booking(cmd);
            break;
        case 4 :
            exit(0);
            break;
        default:

            break;

        }
    }
    return 0;
}
void intro_system()
{
    printf("Hello in our bus reservation system \n");
    printf(" 1-view bus information \n 2-for booking \n 3-Cancel bookings \n 4-exit\n \n ");
    printf("choose your option : ");
    scanf("%d",&n);
}
void Bus_view(int a)
{

    ptr_aval=bus_avai;
    printf("BUS NO        Seat        available         destination        Time \n" );
    printf(" %d            %d            %d                 Cairo         12:00 pm \n \n",bus_number[a],bus_seat[a],bus_avai[a]);


}

void password()
{
    printf("please enter Your password : ");
    scanf("%i",&pass);
    if (pass== 12345)
    {
        printf(" success to entering our system hello User \n \n ");
    }
    else
    {
        for(i=0; i<=1 ; i++)
        {
            printf("please enter Your password : ");
            scanf("%i",&pass);
            if (pass== 12345)
            {
                printf(" success to entering our system hello User \n  \n");
                break;
            }
            else
            {

                printf("please enter Your password : ");
                scanf("%i",&pass);
                if (pass== 12345)
                {
                    printf(" success to entering our system hello User \n \n ");
                    break;
                }
                else
                {
                    exit(0);
                }
            }
        }
    }
}
void booking(int a, int b,char s[])
{

    ptr_aval=bus_avai;

    printf("BUS NO        Seat        available     your seat    new available  name     destination        Time \n" );
    printf(" %d            %d            %d             %d            %d          %s        Cairo          12:00 pm \n \n",bus_number[a],bus_seat[a],bus_avai[a],b,*((*ptr_aval+a))-b,s);
    bus_avai[a]=*((*ptr_aval+a))-b;
    cancel=b;
    bobus=a;

}
void cancel_booking(int s)
{
    if (s == 1)
    {
        ptr_aval=bus_avai;

        bus_avai[bobus]=*((*ptr_aval+bobus))+cancel;
    }
    if(s==2)
    {

    }
    else
    {

    }

}

