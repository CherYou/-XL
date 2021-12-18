#include<algorithm>
#include<fstream>
#include<cstdio>
#include<iostream>
#include"stock.h"
#include"maxheap.h"
using namespace std;
FILE* fileopen(char *filename,char *mode)
{
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}
//template <class T>
void mergeFiles(char *outfile,const int runsize,const int runnums)
{
    FILE *in[runnums];
    for(int i=0;i<runnums;i++)
    {
        char filename[8];
        snprintf(filename,sizeof (filename),"%d",i);
        in[i]=fileopen(filename,"w");
    }

    FILE *out=fileopen(outfile,"w");
    MaxheapNode *harr=new MaxheapNode[runnums];  //结构体模板
    int i=0;
    for(i=0;i<runnums;i++)
    {
        if(!fread((char *)&harr[i].element,sizeof (harr[i].element),1,in[i])) break;
        harr[i].index=i;
    }

    Maxheap hp(harr,i);
    int cnt=0;//jishuqi
    while(cnt!=i){
        MaxheapNode root=hp.getMax();
        string dt=root.element.getDate();
        string sy=root.element.getSym();
        const char *dt1=NULL;dt1=dt.c_str(); const char *sy1=NULL;sy1=sy.c_str();

        fprintf(out,"%s,%s,%f,%f,%f,%f,%f,%f,%f,%f%,\n",dt,sy,root.element.getOpen(),
                root.element.getHigh(),root.element.getLow(),root.element.getClose(),root.element.getAdj(),
                root.element.getVolume(),root.element.getzdv(),root.element.getzdr());

        if(!fread((char *)&root.element,sizeof (root.element),1,in[root.index])) {root.element=0;cnt++;} //0为最小，需要改
        hp.replaceroot(root);
        for (int i = 0; i < runnums; i++)
                fclose(in[i]);

        fclose(out);
    }
}

void fun1(Us_stock a,char *buff)
{
    string dt;string sy;float op=0.0;float hi=0.0;
    float lo=0.0;float cl=0.0;float vo=0.0;float zdv=0.0;
    float zdr=0.0;float adj=0.0;float lastdc=0.0;
    int cnt=0;
    char *substr=strtok(buff,",");
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
          case 8:zdv=strtof(substr,NULL);
          case 9:zdr=strtof(substr,NULL);
      }
      cnt++;
      substr=strtok(NULL,",");
   }
   Us_stock b(dt,sy,op,hi,lo,cl,vo,zdv,zdr,adj);
   a=b;
}
//template <class T>
void creatruns(char *inputfile,int runsize,int runnums)
{
    FILE *in=fileopen(inputfile,"r");
    FILE *out[runnums];//
    char filename[8];
    for(int i=0;i<runnums;i++)
    {
        snprintf(filename,sizeof (filename),"%d",i);
        out[i]=fileopen(filename,"w");
    }
    Us_stock *arr=new Us_stock[runsize];
    bool more_input=true;
    int next_output_file=0;
    char buf[100];
    while(more_input)
    {
        int i;
        for ( i=0;i<runsize;i++) {
            if(fgets(buf,100,in)==NULL) //read till EOF
            {
                more_input=false;
                break;
            }
            //根据文件名进行两个数据集的构造.
            //if us_stock
            fun1(arr[i],buf);
            //else
            //fun2(&arr[i],buf);
        }
        //mergesort(arr,0,runsize-1);
        sort(,,cmp);
        //适应两个数据集
        for(int j=0;j<i;j++) {
            fwrite(arr[i],sizeof(arr[i]),1,out[next_output_file]);  //二进制形式写入
//            fprintf(out[next_output_file],"%s,%s,%f,%f,%f,%f,%f,%f,%f,%f%,\n",dt,sy,arr[i].getOpen(),
//            arr[i].getHigh(),arr[i].getLow(),arr[i].getClose(),arr[i].getAdj(),
//            arr[i].getVol(),arr[i].getZdv(),arr[i].getZdr());
        }
        next_output_file++;
    }
    for(int i=0;i<next_output_file;i++)
    {
        fclose(out[i]);
    }
    fclose(in);
}
//template<class T>
void externalsort(char *openfile,char *outfile,int runsize,int runnums)
{
    creatruns(openfile,runsize,runnums);
    mergeFiles(outfile,runsize,runnums);
}
