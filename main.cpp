#include <stdio.h>
#include <conio.h>
#include <list>
#include "/storage/emulated/0/C++Projects/theLastOne-2/mainDoc.cpp"


void main_operate(){
    
}

int main(){
    mainStart();
    thread thread_interact(interact);
    thread_interact.detach();
    while(1){
        mainUpdate();
        sleep(1);
        main_operate();
        if(operate_num==1){
            
            printf("safe");
            goto dd1209;
        };
    }
    dd1209:
    printf("end");
    return 0;
}