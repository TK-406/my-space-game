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
void create_a_struct(){
    printf("create_a_struct");
}
/*..............................................................................................................................*/


typedef struct command_pack{
    int command_type;
    int num1;
    int num2;
}command_pack;

string star_code;

list<command_pack> command_list;
list<command_pack>::iterator readPack_it;
command_pack writeComBuffer;


void getCode(){
    
    getline(cin,star_code,'.');
    
}

mutex interact_mtx;

void readCode_pushPack(){
    string operate_str=star_code.substr(0,star_code.find_first_of("_"));
    
    if(operate_str=="pause"){
        writeComBuffer.command_type=1;
    }
    else if(operate_str=="opencrt"){
        star_code.erase(0,star_code.find_first_of("_")+1);
        operate_str=star_code.substr(0,star_code.find_first_of("_"));
        if(structMap.find(operate_str)==structMap.end()){
            printf("机器不存在");
        }
        else if(operate_str.empty()==true){
            printf("无效指令");
        }
        else{
            create_a_struct();
        };
        writeComBuffer.command_type=11;
        
    }
    else{
        printf("无效指令");
    };
    interact_mtx.lock();
    command_list.push_back(writeComBuffer);
    interact_mtx.unlock();
}

int interact(){
    writeComBuffer={0,0,0};
    interact_mtx.lock();
    command_list.push_front(writeComBuffer);//别删，初始化list的
    interact_mtx.unlock();
    while(1){
        getCode();
        readCode_pushPack();
        if(writeComBuffer.command_type==1){
            goto dd1215;
        };
    }
    dd1215:
    return 0;
    
}
