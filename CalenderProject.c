//Project : Tell me date, I'll tell you day

#include<stdio.h>
void tell_day_of_date(int d,int m,int y)
{
    int day,moncode,year,leapyear;

    day=d;

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

    switch(x)
    {
        case 0: printf("Sunday\n");
                break;
        case 1: printf("Monday\n");
                break;
        case 2: printf("Tuesday\n");
                break;
        case 3: printf("Wednesday\n");
                break;
        case 4: printf("Thursday\n");
                break;
        case 5: printf("Friday\n");
                break;
        case 6: printf("Saturday\n");
                break;
    }


}
void check_day(int d,int m,int y)
{
    if((m==4 || m==6 || m==9 || m==11) && d>30)
    {
        printf("There are only 30 days in this month & you are entering %d :(",d);
        return;
    }
    else if(m==2 && (y%4!=0) && d>28)
    {
        printf("There are only 28 days in FEB of this Year & you are entering %d :(",d);
        return;
    }
    else if(m==2 && (y%4==0) && d>29)
    {
        printf("There are only 29 days in FEB of this Year & you are entering %d :(",d);
        return;
    }
    else
    {
        if(d>31)
         {
            printf("There are only 31 days in this month & you are entering %d :(",d);
            return;
        }
    }
    tell_day_of_date(d,m,y);
}
void main()
{
    int d,m,y;
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

    printf("Enter Day : ");
    scanf("%d",&d);
    check_day(d,m,y);

}
