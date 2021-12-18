#include<algorithm>
#include<fstream>
#include<iostream>
#include"maxheap.h"
using namespace std;
bool cmp1(Us_stock a,Us_stock b)
{

    string dt1=a.getDate();string dt2=b.getDate();
    //if(dt1.empty()==1 || dt2.empty()==1) cout<<1<<endl;
    //string y1=NULL;string m1=NULL;string d1=NULL;string y2=NULL;string m2=NULL;string d2=NULL;
    int tmp1=dt1.find_first_of('/');int tmp2=dt1.find_last_of('/');
    int y1=atoi(dt1.substr(0,tmp1).c_str());int m1=atoi(dt1.substr(tmp1+1,tmp2-tmp1-1).c_str());int d1=atoi(dt1.substr(tmp2+1,dt1.length()-tmp2).c_str());
    tmp1=dt2.find_first_of('/');tmp2=dt2.find_last_of('/');
    int y2=atoi(dt2.substr(0,tmp1).c_str());int m2=atoi(dt2.substr(tmp1+1,tmp2-tmp1-1).c_str());int d2=atoi(dt2.substr(tmp2+1,dt2.length()-tmp2).c_str());

    //compare
    if(y1>y2) {
        return true;
    }
    else{
        if(y1==y2){
            if(m1>m2) return true;
            else{
                if(m1==m2){
                    if(d1>d2) return true;
                    else{
                        if(d1==d2)
                        return a.getzdr()>=b.getzdr()?true:false;
                    }
                }
            }
        }
    }
    return false;
}
bool cmp2(Us_stock a,Us_stock b)
{
    string dt1=a.getDate();string dt2=b.getDate();
    //if(dt1.empty()==1 || dt2.empty()==1) cout<<1<<endl;
    //string y1=NULL;string m1=NULL;string d1=NULL;string y2=NULL;string m2=NULL;string d2=NULL;
    int tmp1=dt1.find_first_of('/');int tmp2=dt1.find_last_of('/');
    int y1=atoi(dt1.substr(0,tmp1).c_str());int m1=atoi(dt1.substr(tmp1+1,tmp2-tmp1-1).c_str());int d1=atoi(dt1.substr(tmp2+1,dt1.length()-tmp2).c_str());
    tmp1=dt2.find_first_of('/');tmp2=dt2.find_last_of('/');
    int y2=atoi(dt2.substr(0,tmp1).c_str());int m2=atoi(dt2.substr(tmp1+1,tmp2-tmp1-1).c_str());int d2=atoi(dt2.substr(tmp2+1,dt2.length()-tmp2).c_str());

    //compare
    if(y1>y2) {
        return true;
    }
    else{
        if(y1==y2){
            if(m1>m2) return true;
            else{
                if(m1==m2){
                    if(d1>d2) return true;
                    else{
                        if(d1==d2)
                        return abs(a.getzdr())>=abs(b.getzdr())?true:false;
                    }
                }
            }
        }
    }
    return false;
}
bool cmp3(Us_stock a,Us_stock b)
{
    string dt1=a.getDate();string dt2=b.getDate();
    int tmp1=dt1.find_first_of('/');int tmp2=dt1.find_last_of('/');
    int y1=atoi(dt1.substr(0,tmp1).c_str());int m1=atoi(dt1.substr(tmp1+1,tmp2-tmp1-1).c_str());int d1=atoi(dt1.substr(tmp2+1,dt1.length()-tmp2).c_str());
    tmp1=dt2.find_first_of('/');tmp2=dt2.find_last_of('/');
    int y2=atoi(dt2.substr(0,tmp1).c_str());int m2=atoi(dt2.substr(tmp1+1,tmp2-tmp1-1).c_str());int d2=atoi(dt2.substr(tmp2+1,dt2.length()-tmp2).c_str());
    //compare
    return a.getzdr()>b.getzdr()?true:false;
}
FILE* fileopen(char *filename,char *mode)
{
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}
void fun1(Us_stock &a,char *buff)
{
    string dt;string sy;float op=0.0;float hi=0.0;
    float lo=0.0;float cl=0.0;float vo=0.0;float zdv=0.0;
    float zdr=0.0;float adj=0.0;
    int cnt=0;
    char *substr=strtok(buff,",");
    while(substr){
       switch(cnt)
       {
          case 0:{dt=substr;break;}
          case 1:{
            sy=substr;
            break;
          }
          case 2:{
            op=strtof(substr,NULL);
            break;
          }
          case 3:{
            hi=strtof(substr,NULL);
            break;
          }
          case 4:{
            lo=strtof(substr,NULL);
            break;
          }
          case 5:{
            cl=strtof(substr,NULL);
            break;
          }
          case 7:{
            vo=strtof(substr,NULL);
            break;
          }
          case 6:{
            adj=strtof(substr,NULL);
            break;
          }
          case 8:{
            zdv=strtof(substr,NULL);
            break;
          }
          case 9:{
            zdr=strtof(substr,NULL);
            break;
          }
      }
      cnt++;
      substr=strtok(NULL,",");
   }
   Us_stock b(dt,sy,op,hi,lo,cl,vo,zdv,zdr,adj);
   a=b;
}
void fun2(Us_stock &a,char *buff){
    string dt;string sy;float op=0.0;float hi=0.0;
    float lo=0.0;float cl=0.0;float vo=0.0;float zdv=0.0;
    float zdr=0.0;float adj=0.0;
    int cnt=0;
    char *substr=strtok(buff,",");
    while(substr){
       switch(cnt)
       {
          case 0:{
          dt=substr;break;
          }
          case 1:{
            sy=substr;
            break;
          }
          case 2:{
            zdr=strtof(substr,NULL);
            break;
          }
      }
      cnt++;
      substr=strtok(NULL,",");
   }
   Us_stock b(dt,sy,op,hi,lo,cl,vo,zdv,zdr,adj);
   a=b;
}
void mergeFiles(char *outfile,const int runsize,const int runnums,int status)//
{
    FILE *in[runnums];
    for(int i=0;i<runnums;i++)
    {
        char filename[10];
        snprintf(filename,sizeof (filename),"%d",i);
        in[i]=fileopen(filename,"r");
    }
    FILE *out=fileopen(outfile,"w");
    MaxheapNode *harr=new MaxheapNode[runnums];  //结构体模板
    int i=0;
    char buf[200];
    for(i=0;i<runnums;i++)
    {
        if(fgets(buf,200,in[i])==NULL) break;
        fun1(harr[i].element,buf);
        harr[i].index=i;
    }
    Maxheap hp(harr,i,status);
    cout<<hp.getMax().element.getzdr()<<endl;
    int cnt=0;//jishuqi
    while(cnt!=i){
        MaxheapNode root=hp.getMax();
        string dt=root.element.getDate();
        string sy=root.element.getSym();
        const char *dt1=dt.c_str(); const char *sy1=sy.c_str();
        fprintf(out,"%s,%s,%f%,\n",dt1,sy1,root.element.getzdr());
        char *flag=fgets(buf,200,in[root.index]);
        fun1(root.element,buf);
        if(flag==NULL)
        {root.element=Minstock;cnt++;}
        hp.replaceroot(root);
    }
    for (int i = 0; i < runnums; i++)
        fclose(in[i]);
    fclose(out);
}
void creatruns(char *inputfile,int runsize,int runnums,int status)
{
    FILE *in=fileopen(inputfile,"r");
    FILE *out[runnums];//
    char filename[10];
    for(int i=0;i<runnums;i++)
    {
        snprintf(filename,sizeof (filename),"%d",i);
        out[i]=fileopen(filename,"w");
    }
    bool more_input=true;
    Us_stock *arr=new Us_stock[runsize];
    int next_output_file=0;
    char buf[200];
    while(more_input)
    {
        int i;
        for ( i=0;i<runsize;i++) {

            if(!fgets(buf,200,in)) //read till EOF
            {
                more_input=false;
                break;
            }
            //根据文件名进行两个数据集的构造.
            //if us_stock
            //cout<<buf<<endl;
           if(status==1 || status==2) fun1(arr[i],buf);
           if(status==3) fun2(arr[i],buf);
            //cout<<arr[i].getDate()<<endl;
            //else
            //fun2(&arr[i],buf);
        }
        //mergesort(arr,0,runsize-1);
        if(status==1)
        sort(arr,arr+i,cmp1);
        if(status==2)
        sort(arr,arr+i,cmp2);
        if(status==3)
        sort(arr,arr+i,cmp3);
        //if(i==291) cout<<arr[i-1].getDate()<<endl;
        //cout<<next_output_file<<more_input<<endl;
        //适应两个数据集
        for(int j=0;j<i;j++) {
            //fwrite((char *)&arr[i],sizeof(arr[i]),1,out[next_output_file]);  //二进制形式写入
        const char *dt=arr[j].getDate().c_str();const char *sy=arr[j].getSym().c_str();
        fprintf(out[next_output_file],"%s,%s,%f,%f,%f,%f,%f,%f,%f,%f\n",dt,sy,arr[j].getOpen(),arr[j].getHigh(),arr[j].getLow(),arr[j].getClose(),arr[j].getAdj(),arr[j].getVolume(),arr[j].getzdv(),arr[j].getzdr());
        dt=NULL;sy=NULL;
        }
        next_output_file++;
    }
    //delete arr;
    for(int i=0;i<next_output_file;i++)
    {
        fclose(out[i]);
    }
    fclose(in);

}
void externalsort(char *openfile,char *outfile,int runsize,int runnums,int status)
{
    creatruns(openfile,runsize,runnums,status);
    mergeFiles(outfile,runsize,runnums,status);
}
void strsplit(string a, int &y,int &m){
    int tmp1=a.find_first_of('/');int tmp2=a.find_last_of('/');
    y=atoi(a.substr(0,tmp1).c_str());m=atoi(a.substr(tmp1+1,tmp2-tmp1-1).c_str());
}
bool strcmp1(char* a, char* b){
    if(strlen(a)!=strlen(b)) return false;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}
void creatruns1(char *inputfile)  //
{
    FILE *in=fileopen(inputfile,"r");
    char buf[200];
    char *substr=NULL;int tot=0;char lastfina[20];bool flag=false;
    char *dt;char *sy;float zdr;
    while(fgets(buf,200,in))
    {
        int cnt=0;
        substr=strtok(buf,",");
        while(substr)
        {
            switch(cnt){
                case 0:{
                    dt=substr;
                    break;
                }
                case 1:{
                    sy=substr;
                    break;
                }
                case 2:{
                    zdr=atof(substr);
                    break;
                }
            }
            cnt++;
            substr=strtok(NULL,",");
        }
        string tmp=dt; char filename[20];
        int year;int month;
        strsplit(tmp,year,month);
        snprintf(filename,sizeof(filename),"%d-%d.csv",year,month);
        if(!flag) {
            flag=true;
            int i;
            for(i=0;i<strlen(filename);i++)
            lastfina[i]=filename[i];
            lastfina[i]='\0';
        }
        if(strcmp1(lastfina,filename)==false) {
            tot++;
            int i;
            for(i=0;i<strlen(filename);i++) lastfina[i]=filename[i];
            lastfina[i]='\0';
        }
        FILE *out=fileopen(filename,"a");
        fprintf(out,"%s,%s,%f%,\n",dt,sy,zdr);
        fclose(out);
    }

}
void topkexternalsort(char *openfile,char *outfile){
    //externalsort("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_daily1.csv",
    //           "C:/Users/86158/Desktop/程设2大作业/data/test_us_ex_sort2.csv",1000,216,2);
    //creatruns1(openfile);
    int y,m,k;
    cin>>y>>m>>k;
    char filename[20];char outfilename1[20];char outfilename2[20];
    snprintf(filename,sizeof(filename),"%d-%d.csv",y,m);
    //cout<<filename;
    snprintf(outfilename1,sizeof(outfilename1),"%d-%dtop%d1.csv",y,m,k);
    snprintf(outfilename2,sizeof(outfilename2),"%d-%dtop%d2.csv",y,m,k);
    externalsort(filename,outfilename1,100,10,3);
    FILE *in=fopen(outfilename1,"r");
    FILE *out=fopen(outfilename2,"w");
    char buf[100];
    for(int i=0;i<k;i++)
    {
        fgets(buf,100,in);
        //fputs(buf,out);
        fprintf(out,"%s",buf);
    }
}
void cal2(float cl1,float cl2,float *zdv,float*zdr)
{
    *zdv=cl1-cl2;
    *zdr=*zdv/cl2*100;
}
void filerandw()
{
    char *dt;char *sy;float op;float hi;float lo;float cl;float vo;float zdv=0;float zdr=0;float adj;float lastdc=0;
    FILE *fp=fopen("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_daily.csv","r");
    FILE *fp1=fopen("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_daily11.csv","w") ;
    char buf[128];
    char temp[128];
    int size=0; //循环计数器
    int i=0;
    while(fgets(buf,128,fp))
    {
        if(i!=0){  //从第2行开始
        int cnt=0;//计数器
        int len=strlen(buf); //复制字符串
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
        lastdc=cl;//记录收盘价
        fprintf(fp1,"%s,%s,%f,%f,%f,%f,%f,%f,%f,%f%,\n",dt,sy,op,hi,lo,cl,adj,vo,zdv,zdr);
        size++;
    }
    i++;
    }
}
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
void sharpe()
{
    char* dt;char* sy;float op;float hi;float lo;float cl;float vo;float zdv=0;float zdr=0;float adj;
    FILE *fp=fopen("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_daily1.csv","r");
    FILE *fp1=fopen("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_dailyxiapu.csv","w") ;
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
        int cnt=0;//计数器
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
                {  //年份不同
                    xiapu=cal1(zdrmean,cnt1);
                    cnt1=0;
                    //cout<<lastyear<<sy<<xiapu<<endl;
                    fprintf(fp1,"%s,%s,%f,\n",lastyear,sy,xiapu);
                    memset(zdrmean,false,sizeof(zdrmean));
                    temp3=thisyear;  //更新lastyear
                    lastyear=(char *)temp3.c_str();
                }
            }
            else
            {
                thisyear=strtok(dt,"/");
                xiapu=cal1(zdrmean,cnt1);
                fprintf(fp1,"%s,%s,%f,\n",lastyear,lastsy,xiapu);
                memset(zdrmean,false,sizeof(zdrmean));
                temp3=thisyear;  //更新lastyear
                lastyear=(char *)temp3.c_str();
                cnt1=1;
                temp2=sy;  //更新lastsy
                lastsy=(char *)temp2.c_str();
            }
        }
        i++;
    }
}
int main()
{
      //filerandw();
      //sharpe();
      externalsort("C:/Users/86158/Desktop/程设2大作业/data/test_us_stock_daily1.csv",
                 "C:/Users/86158/Desktop/程设2大作业/data/test_us_ex_sort2.csv",1000,216,2);
    topkexternalsort("C:/Users/86158/Desktop/程设2大作业/data/test_us_ex_sort2.csv","");
}
