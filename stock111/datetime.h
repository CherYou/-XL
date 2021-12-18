#ifndef DATETIME_H
#define DATETIME_H
#endif // DATETIME_H
#include<iostream>
using namespace std;
class Date{
    int year;
    int month;
    int day;
public:
    Date(){}
    Date(int y,int m,int d){year=y;month=m;day=d;}
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
};
bool compareDate( Date &a,Date &b){
    if(a.getYear()>b.getYear()) return true;
    if(a.getYear()==b.getYear()){
        if(a.getMonth()>b.getMonth()) return true;
        if(a.getMonth()==b.getMonth()) {
            if(a.getDay()>b.getDay()) return true;
        }
    }
    return false;
}
