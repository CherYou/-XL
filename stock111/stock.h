#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<Qstring>
#include<cmath>
using namespace std;
class Base_stock
{
public:
    Base_stock() {}
    Base_stock(string dt,string sy,float op,float hi,float lo,float cl,float vo,float zdv,float zdr) {
    this->datetime=dt;   	this->symbol=sy;   	this->open=op;   	this->high=hi;   	this->low=lo;
    this->close=cl;   	this->volume=vo;   	this->zdval=zdv;   	this->zdrate=zdr;
    }
    string getDate(){return datetime;}
    string getSym(){return symbol;}
    float getOpen(){return open;}
    float getHigh(){return high;}
    float getLow(){return low;}
    float getClose();
    float getVolume(){return volume;}
    float getzdv(){ return zdval;   }
    float getzdr() {return zdrate;}
    void setzdval(float);
    void setzdrate(float);
private:
    string datetime;//date
    string symbol;//股票代码
    float open;//开盘价
    float high;//最高价
    float low;//最低价
    float close;//收盘价
    float volume;//成交量
    float zdval;//涨跌额
    float zdrate;//涨跌率
};
class Zh_stock:public virtual Base_stock{
public:
    Zh_stock(){}
    void computeZD1(Zh_stock);//涨跌额
    void computeZD2(Zh_stock);//涨跌率
private:
    float share;//流动股本
    float turnover;//换手率=成交量/流动股本
};
class Us_stock:public  Base_stock
{
public:
    Us_stock() {}
    Us_stock(string dt,string sy,float op,float hi,float lo,float cl,float vo,float zdv,float zdr,float adj)
    :Base_stock(dt,sy,op,hi,lo,cl,vo,zdv,zdr)
    {
        this->adjclose=adj;
    }
    float getAdj(){return adjclose;}
private:
    float adjclose;//复权后的收盘价
};
float Base_stock::getClose(){
    return close;
}
void Base_stock::setzdval(float a){
    zdval=a;
}
void Base_stock::setzdrate(float a){
    zdrate=a;
}
