
//Project : Month of the Year

#include<stdio.h>

void print_month(int m)
{
    switch(m)
    {
        case 1: printf("\n             ---JANUARY---\n");
                break;
        case 2: printf("\n             ---FEBRUARY---\n");
                break;
        case 3: printf("\n             ---MARCH---\n");
                break;
        case 4: printf("\n             ---APRIL---\n");
                break;
        case 5: printf("\n             ---MAY---\n");
                break;
        case 6: printf("\n             ---JUNE---\n");
                break;
        case 7: printf("\n             ---JULY---\n");
                break;
        case 8: printf("\n             ---AUGUST---\n");
                break;
        case 9: printf("\n             ---SEPTEMBER---\n");
                break;
        case 10: printf("\n             ---OCTOBER---\n");
                break;
        case 11: printf("\n             ---NOVEMBER---\n");
                break;
        case 12: printf("\n             ---DECEMBER---\n");
                break;
    }
}
int month(int m,int y)
{
    if(m==4||m==6||m==9||m==11)
        return 30;
    else if(m==2 && (y%4==0))
        return 29;
    else if(m==2 && (y%4!=0))
        return 28;
    else return 31;
}
void check_day(int m,int y)
{
    int day,moncode,year,leapyear;

    day=1;

    // code of months from inter-net, to use the trick of finding day of date
    if(m==1 || m==10) moncode=0;
    else if(m==5) moncode=1;
    else if(m==8) moncode=2;
    else if(m==2||m==3||m==11) moncode=3;
    else if(m==6) moncode=4;
    else if(m==9||m==12) moncode=5;
    else moncode=6;

    year=y-1900;

    leapyear=year/4;

    int x;

    if(((y%100==0) && (y%400!=0)) || y%4!=0) x=(day+moncode+year+leapyear)%7;
    else
    {
        if(m==1||m==2) x=(day+moncode+year+leapyear-1)%7;
        else x=(day+moncode+year+leapyear)%7;
    }

    print_month(m);

    printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
    int week=7;

    for(int i=1; i<=month(m,y); i++)
    {
        if(i==1)
        {
            int n=(6*x+5);
            while(n--) printf(" ");

            printf("1");
            x++;

            if(x>6)
            {
                printf("\n");
                x=0;
            }
            continue;
        }

        printf("%6d",i);
        x++;
        if(x>6)
        {
            printf("\n");
            x=0;
        }
    }
    printf("\n");
}
void main()
{
    printf("Which calender would you like to see...??\n");
    printf("Enter...\n");
    printf("1 : For Month of Year\n");
    printf("2 : For Year\n");

    int ch;
    scanf("%d",&ch);

    if(ch==1)
    {
        int m,y;
        printf("Enter Year : ");
        scanf("%d",&y);
        if(y<1900)
        {
            printf("Enter year after 1900 :( \n");
            return;
        }

        printf("Enter Month : ");
        scanf("%d",&m);
        if(m>12)
        {
            printf("There are only 12 months in a year & you are entering %d :(\n",m);
            return;
        }
        check_day(m,y);
    }
    else if(ch==2)
    {
        int m=1,y;
        printf("Enter Year : ");
        scanf("%d",&y);
        if(y<1900)
        {
            printf("Enter year after 1900 :( \n");
            return;
        }
        while(m!=13)
        {
            check_day(m,y);
            m++;
        }
    }
    else
    {
        printf("You have entered wrong choice :(");
        return 0;
    }

}
