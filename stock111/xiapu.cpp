#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
float zdrmean[370];
bool thisyear=true;
bool thisstock=true;
char *lastsy=NULL;char *lastyear=NULL;int cnt1=0;float xiapu=0.0;
float cal1(float a[],int size){
    if(size==1) return 0;
    float mean=0.0,std=0.0;
    for(int i=0;i<size;i++){
        mean+=a[i];
    }
    mean/=size;
    for(int i=0;i<size;i++)
    {
        std+=(a[i]-mean)*(a[i]-mean);
    }
    std/=size;
    std=sqrt(std);
    if(std==0) return 0;
    return mean/std;
}
int main()
{
    char* dt;char* sy;float op;float hi;float lo;float cl;float vo;float zdv=0;float zdr=0;float adj;
    FILE *fp=fopen("C:/Users/86158/Desktop/����2����ҵ/data/test_us_stock_daily1.csv","r");
    FILE *fp1=fopen("C:/Users/86158/Desktop/����2����ҵ/data/test_us_stock_dailyxiapu.csv","w") ;
    char buf[128];
    string temp;
    string temp1;
    string temp2;
    string temp3;
    int i=0;
    while(fgets(buf,128,fp))
    {
        dt=NULL;op=0.0;hi=0.0;lo=0.0;cl=0.0;vo=0.0;
        sy=NULL;zdv=0.0;zdr=0.0;adj=0.0;
        int cnt=0;//������
        char *substr=strtok(buf,",");
        while(substr)
        {
            switch(cnt)
            {
            case 0:{
                temp=substr;
                dt=(char *)temp.c_str();
                break;
            }
            case 1:{
                temp1=substr;
                sy=(char *)temp1.c_str();
                break;
            }
            case 2:op=strtof(substr,NULL);
            case 3:hi=strtof(substr,NULL);
            case 4:lo=strtof(substr,NULL);
            case 5:cl=strtof(substr,NULL);
            case 7:vo=strtof(substr,NULL);
            case 6:adj=strtof(substr,NULL);
            case 8:zdv=strtof(substr,NULL);
            case 9:zdr=strtof(substr,NULL);
            }
        cnt++;
        substr=strtok(NULL,",");
        }
        char *thisyear=NULL;
        if(i==0)
        {
            temp2=sy;
            lastsy=(char *)temp2.c_str();
            lastyear=strtok(dt,"/");
            zdrmean[cnt1++]=zdr;
        }
        else
        {
            if(strcmp(lastsy,sy)==0)
            {
                thisyear=strtok(dt,"/");
                if(strcmp(thisyear,lastyear)==0)
                {
                    zdrmean[cnt1++]=zdr/100;
                }
                else
                {  //���ݲ�ͬ
                    xiapu=cal1(zdrmean,cnt1);
                    cnt1=0;
                    cout<<lastyear<<sy<<xiapu<<endl;
                    fprintf(fp1,"%s,%s,%f,\n",lastyear,sy,xiapu);
                    memset(zdrmean,false,sizeof(zdrmean));
                    temp3=thisyear;  //����lastyear
                    lastyear=(char *)temp3.c_str();
                }
            }
            else
            {
                thisyear=strtok(dt,"/");
                xiapu=cal1(zdrmean,cnt1);
                cout<<lastyear<<lastsy<<xiapu<<endl;
                fprintf(fp1,"%s,%s,%f,\n",lastyear,lastsy,xiapu);
                memset(zdrmean,false,sizeof(zdrmean));
                temp3=thisyear;  //����lastyear
                lastyear=(char *)temp3.c_str();
                cnt1=1;
                temp2=sy;  //����lastsy
                lastsy=(char *)temp2.c_str();
            }
        }
        i++;
    }
 }
