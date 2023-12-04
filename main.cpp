#include <stdio.h>
#include <conio.h>
#include <list>
#include "/storage/emulated/0/C++Projects/theLastOne-2/maindoc.cpp"
#include <mutex>
#include <string>
#include <map>
int main_operate_num=0;

void readPack(){
    interact_mtx.lock();
    readPack_it=command_list.begin();//初始化读指针
    if(readPack_it!=--command_list.end()){
        readPack_it=command_list.erase(readPack_it);
        /*readPack_it++;
        command_list.pop_front();*/
        switch(readPack_it->command_type){
            case 1:
                main_operate_num=1;
                break;
            case 11:
                
                break;
            default:
                break;
        }
    };
    interact_mtx.unlock();
    printf("读包结束");
}

int main(){
    mainStart();
    thread thread_interact(interact);
    thread_interact.detach();
    
    
    
    while(1){
        mainUpdate();
        sleep(1);
        printf("tst1");
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