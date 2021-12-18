#ifndef MAXHEAP_H
#include"stock.h"
#define MAXHEAP_H
#endif // MAXHEAP_H
struct MaxheapNode
{
    Us_stock element;
    int index;
};
Us_stock Minstock=Us_stock("0/0/0","aaa",-1,-1,-1,-1,-1,-1,-1,-1);
bool islagerThan1(Us_stock a,Us_stock b)//1为a>b
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
bool islagerThan2(Us_stock a,Us_stock b)//1为a>b
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
bool islagerThan3(Us_stock a,Us_stock b)//1为a>b
{
    string dt1=a.getDate();string dt2=b.getDate();
    //if(dt1.empty()==1 || dt2.empty()==1) cout<<1<<endl;
    //string y1=NULL;string m1=NULL;string d1=NULL;string y2=NULL;string m2=NULL;string d2=NULL;
    int tmp1=dt1.find_first_of('/');int tmp2=dt1.find_last_of('/');
    int y1=atoi(dt1.substr(0,tmp1).c_str());int m1=atoi(dt1.substr(tmp1+1,tmp2-tmp1-1).c_str());int d1=atoi(dt1.substr(tmp2+1,dt1.length()-tmp2).c_str());
    tmp1=dt2.find_first_of('/');tmp2=dt2.find_last_of('/');
    int y2=atoi(dt2.substr(0,tmp1).c_str());int m2=atoi(dt2.substr(tmp1+1,tmp2-tmp1-1).c_str());int d2=atoi(dt2.substr(tmp2+1,dt2.length()-tmp2).c_str());
    //compare
    return a.getzdr()>b.getzdr()?true:false;
}
void swap(MaxheapNode *a,MaxheapNode *b){
    MaxheapNode temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
class Maxheap
{
private:
    MaxheapNode *val;
    int capacity;//最小堆的最大容纳量
    int n_size;//当前堆中元素数
    int status;//选择比较函数1.2两种
public:
    Maxheap(MaxheapNode a[],int size,int s) {
    val=a;n_size=size;status=s;
    int i=(n_size-1)/2;
    while(i>=0) {
        heapify(i);
        i--;
    }
    }
    void heapify(int);//使得堆满足最小最大化
    int parent(int i){return (i-1)/2;}
    int leftson(int i){return 2*i+1;}
    int rightson(int i) {return 2*i+2;}
    MaxheapNode getMax();//返回根
    void replaceroot(MaxheapNode x);
};
void Maxheap::heapify(int i){
   int l=leftson(i);
   int r=rightson(i);
   int maxnum=i;
   if(status==1){
      if(l<n_size && islagerThan1(val[l].element,val[maxnum].element)==true) maxnum=l;  //与左儿子相比
      if(r<n_size && islagerThan1(val[r].element,val[maxnum].element)==true) maxnum=r;  //与右儿子相比
   }
   if(status==2){
      if(l<n_size && islagerThan2(val[l].element,val[maxnum].element)==true) maxnum=l;  //与左儿子相比
      if(r<n_size && islagerThan2(val[r].element,val[maxnum].element)==true) maxnum=r;  //与右儿子相比
   }
   if(status==3){
      if(l<n_size && islagerThan3(val[l].element,val[maxnum].element)==true) maxnum=l;  //与左儿子相比
      if(r<n_size && islagerThan3(val[r].element,val[maxnum].element)==true) maxnum=r;  //与右儿子相比
   }
   if(maxnum!=i)                          // 如果根节点小，则下沉
   {
       swap(&val[maxnum],&val[i]);
       heapify(maxnum);
   }
}
MaxheapNode Maxheap::getMax(){
    return val[0];
}
void Maxheap::replaceroot(MaxheapNode x){
    val[0]=x;
    heapify(0);
}


