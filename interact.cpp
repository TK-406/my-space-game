#include <math.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <map>
#include "/storage/emulated/0/C++Projects/theLastOne-2/star.cpp"

//using namespace std;


/*…………………………………………………………………………………………………………………………*/
int main_operate_num=0;
/*..............................................................................................................................*/


typedef struct command_pack{
    string coms[10];
    int pauseTime;
}command_pack;

string star_code;

list<command_pack> command_list;
list<command_pack>::iterator readPack_it;


command_pack writeComBuffer;


void getCode(){
    
    getline(cin,star_code,'.');
    
}

mutex interact_mtx;
mutex main_operate_mtx;
mutex scan_mtx;


void readCode_pushPack(){
    
    for(int ct1=0;star_code.empty()!=true;ct1++){
        writeComBuffer.coms[ct1]=star_code.substr(0,star_code.find_first_of("_"));
        star_code.erase(0,star_code.find_first_of("_")+1);
    }
    writeComBuffer.pauseTime=0;
    interact_mtx.lock();//锁
    command_list.push_back(writeComBuffer);
    printf("push一次");
    interact_mtx.unlock();//去锁
}

int interact(){
    
    while(1){
        getCode();
        
        readCode_pushPack();
        
        if(writeComBuffer.coms[0]=="pause"){
            goto dd1215;
        };
    }
    dd1215:
    printf("end_interact");
    return 0;
    
}
