#include <stdio.h>
#include <conio.h>
#include <list>
#include "/storage/emulated/0/C++Projects/theLastOne-2/maindoc.cpp"
#include "/storage/emulated/0/C++Projects/theLastOne-2/prtPart.cpp"
#include <mutex>
#include <string>
#include <map>
#include <iostream>

multimap<string,one_struct>::iterator operate_struct_it;

bool checkStructLink(one_struct input_struct){
    int count=0;
    for(int ct1=0;ct1<parts_in_one_struct;ct1++){
        if((input_struct.parts[ct1]).type>=41&&(input_struct.parts[ct1]).type<=50){
            count++;
        };
    }
    if(count>0){
        return true;
    }
    else{
        return false;
    };
}

void readPack(){
    interact_mtx.lock();
    readPack_it=command_list.begin();//初始化读指针
    while(readPack_it!=command_list.end()){
        if(readPack_it->pauseTime==0){
            cout<<readPack_it->coms[0]<<endl;
            if(readPack_it->coms[0]=="pause"){
                main_operate_num=1;
            }
            else if(readPack_it->coms[0]=="open"){
                multimap<string,one_struct>::iterator find_it=structMap.find(readPack_it->coms[1]);
                if(find_it==structMap.end()){
                    printf("\n-连接失败-\n");
                    cout<<(readPack_it->coms)[1]<<endl;
                }
                else{
                    
                    operate_struct_it=find_it;
                    main_operate_num=2;
                    
                    for(int ct1=0;ct1<parts_in_one_struct;ct1++){
                        prtPart(((operate_struct_it->second).parts[ct1]).type);
                    }
                    
                };
            }
            else if(readPack_it->coms[0]=="exit"&&main_operate_num==2){
                main_operate_num=0;
            }
            else if(readPack_it->coms[0]=="putOn"&&main_operate_num==2){
                
            }
            else{
                printf("无效指令\n");
                
            };
            readPack_it=command_list.erase(readPack_it);
        }
        else{
            (readPack_it->pauseTime)--;
            readPack_it++;
        };
        
        
    }
    interact_mtx.unlock();
    //printf("读包结束");
}

int main(){
    mainStart();
    thread thread_interact(interact);
    thread_interact.detach();
    
    
    
    while(1){
        mainUpdate();
        sleep(10);
        //printf("tst1");
        //mainRead_mtx.lock();
        readPack();
        //mainRead_mtx.unlock();
        switch(main_operate_num){
            case 1:
                goto dd1209;
                break;
            default:
                break;
        }
    }
    dd1209:
    printf("end");
    return 0;
}