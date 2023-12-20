#include <stdio.h>
#include <list>
#include <map>
#include <math.h>
#include <string>
#include <thread>
//#include 
//#include "/storage/emulated/0/C++Projects/theLastOne-2/me.cpp"
using namespace std;

#define moveTick 1.000000

#define roughG 6.672590
#define tenPlusG -11.000000

#define parts_in_one_struct 15


typedef struct v{
    double vX;
    double vY;
    double vZ;
}v;
typedef struct pos{
    double posX;
    double posY;
    double posZ;
}pos;
typedef struct a{
    double aX;
    double aY;
    double aZ;
}a;


class star{
public:
    
    string name;
    
    double mass;
    double tenTime;
    
    pos starPos;
    
    v starV;
    a starA;
    int temprature;
    
    
    
    
    
    
    
    
    void updateV(){
        (this->starV).vX+=(this->starA).aX*moveTick;
        (this->starV).vY+=(this->starA).aY*moveTick;
        (this->starV).vZ+=(this->starA).aZ*moveTick;
    }
    
    void updatePos(){
        (this->starPos).posX+=(this->starV).vX*moveTick*pow(10.000000,-3.000000);
        (this->starPos).posY+=(this->starV).vY*moveTick*pow(10.000000,-3.000000);
        (this->starPos).posZ+=(this->starV).vZ*moveTick*pow(10.000000,-3.000000);
    }
    
    
    
    
};

multimap<string,star> starMap;





pair<string,star> createStar(string input_name,double input_mass,double input_tenTime,pos input_pos,v input_v,a input_a){
    
    star crtStar;
    
    crtStar.mass=input_mass;
    crtStar.tenTime=input_tenTime;
    crtStar.starPos=input_pos;
    crtStar.starV=input_v;
    crtStar.starA=input_a;
    
    pair<string,star> returnStar(input_name,crtStar);
    return returnStar;
}



/*………………………………………………玩家……………………………………*/


class myself{
public:
    star* me_at;
    int health_point;
    myself(){
        this->me_at=NULL;
        this->health_point=300;
    }
};


myself me;




/*…………………………………………………………组件………………………………………………*/
typedef struct one_part{
    //double part_mass;
    int type;
    int endurance;
    double P;
    bool isOpen;
}one_part;



class one_struct{
public:
    //double struct_mass;
    star* point_to_star;
    
    
    one_part parts[parts_in_one_struct];
    int linkmap[parts_in_one_struct][parts_in_one_struct];
    
    void struct_craft(){
        
    }
};
multimap<string,one_struct> structMap;

pair<string,one_struct> createStruct(string input_name,star* input_star_p,one_part input_parts[parts_in_one_struct],int input_linkmap[parts_in_one_struct][parts_in_one_struct]){


    one_struct createOneStruct;
    
    
    for(int ct1=0;ct1<parts_in_one_struct;ct1++){
        createOneStruct.parts[ct1]=input_parts[ct1];
        for(int ct2=0;ct2<parts_in_one_struct;ct2++){
            createOneStruct.linkmap[ct1][ct2]=input_linkmap[ct1][ct2];
        }
    }
    
    createOneStruct.point_to_star=input_star_p;
    
    pair<string,one_struct> output_struct_pair;
    output_struct_pair.first=input_name;
    output_struct_pair.second=createOneStruct;
    
    return output_struct_pair;
}

