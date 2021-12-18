#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
void cal2(float cl1,float cl2,float *zdv,float*zdr)
{
    *zdv=cl1-cl2;
    *zdr=*zdv/cl2*100;
}
int main()
{
    //Us_stock *us=new Us_stock[10000];
    //������Ʊ���ݶ�д
    char *dt;char *sy;float op;float hi;float lo;float cl;float vo;float zdv=0;float zdr=0;float adj;float lastdc=0;
    FILE *fp=fopen("C:/Users/86158/Desktop/����2����ҵ/data/all_us_stock_daily.csv","r");
    FILE *fp1=fopen("C:/Users/86158/Desktop/����2����ҵ/data/test_us_stock_daily6.csv","w") ;
    char buf[128];
    char temp[128];
    int size=0; //ѭ��������
    int i=0;
    while(fgets(buf,128,fp))
    {
        if(i!=0){  //�ӵ�2�п�ʼ
        int cnt=0;//������
        int len=strlen(buf); //�����ַ���
        for(int j=0;j<len;j++)
        {
            temp[j]=buf[j];
        }
        temp[len]='\0';
        char *substr=strtok(buf,",");
        while(substr){
            switch(cnt)
            {
            case 0:dt=substr;
            case 1:sy=substr;
            case 2:op=strtof(substr,NULL);
            case 3:hi=strtof(substr,NULL);
            case 4:lo=strtof(substr,NULL);
            case 5:cl=strtof(substr,NULL);
            case 7:vo=strtof(substr,NULL);
            case 6:adj=strtof(substr,NULL);
        }
        cnt++;
        substr=strtok(NULL,",");
        }
        if(size>=1) cal2(cl,lastdc,&zdv,&zdr);
        lastdc=cl;//��¼���̼�
        fprintf(fp1,"%s,%s,%f,%f,%f,%f,%f,%f,%f,%f%,\n",dt,sy,op,hi,lo,cl,adj,vo,zdv,zdr);
        size++;
    }
    i++;
    }
 }
