#include <stdio.h>
#include <list>
#include <math.h>
#include <thread>
using namespace std;

#define moveTick 1.000000

#define roughG 6.672590
#define tenPlusG -11.000000




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
    double mass;
    double tenTime;
    
    pos starPos;
    
    v starV;
    a starA;
    
};



list<star> starList;


star createStar(double input_mass,double input_tenTime,pos input_pos,v input_v,a input_a){
    
    star crtStar;
    crtStar.mass=input_mass;
    crtStar.tenTime=input_tenTime;
    crtStar.starPos=input_pos;
    crtStar.starV=input_v;
    crtStar.starA=input_a;
    return crtStar;
}









