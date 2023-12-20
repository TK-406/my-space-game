#include <stdio.h>


void prtPart(int input_type){
    if(input_type==0){
        printf("空");
    }
    else if(input_type>0&&input_type<=20){
        switch(input_type){
            case 1:
                printf("锂电池");
                break;
            case 2:
                printf("钠电池");
                break;
            case 3:
                printf("核电池");
                break;
            case 4:
                printf("低温电池");
                break;
            default:
                printf("不认识");
                break;
        }
    }
    else{
        
    };
    printf("\n");
}