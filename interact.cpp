#include <math.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <string>

using namespace std;



string star_code;

int operate_num=-1;


void getCode(){
    getline(cin,star_code,'.');
    
}

void readCode(){
    if(star_code=="pause"){
        operate_num=1;
        //printf("stop");
    };
}

int interact(){
    while(1){
        getCode();
        readCode();
        if(operate_num==1){
            goto dd1215;
        }
        else{
            
        };
    }
    dd1215:
    return 0;
    
}