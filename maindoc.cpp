//#include "/storage/emulated/0/C++Projects/theLastOne-2/star.cpp"
#include "/storage/emulated/0/C++Projects/theLastOne-2/interact.cpp"
//#include "/storage/emulated/0/C++Projects/theLastOne-2/me.cpp"
#include <string>
#include <map>
#include <thread>
#include <stdlib.h>
#include <fstream>
#include <iostream>


#define star_way "/storage/emulated/0/C++Projects/theLastOne-2/stardoc.lodoc"



long get_size(FILE* input_fp) 
{
    FILE *fp_gs = input_fp;
    fseek(fp_gs, 0, SEEK_END);
    long filesize = ftell(fp_gs)/(long)sizeof(pair<string,star>);
    fclose(fp_gs);
    return filesize;
}

void createNature(){
    starMap.insert(createStar("starship0",7.000000,3.000000,{0.000000,2345.000000,2345.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));//飞船
    
    
    starMap.insert(createStar("sun",1.989000,30.000000,{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));//太阳
    starMap.insert(createStar("earth",5.965000,24.000000,{0.000000,149597870.000000,0.000000},{0.000000,1800.000000,0.000000},{0.000000,0.000000,0.000000}));//地球
    
    multimap<string,star>::iterator crtNature=starMap.begin();
    
    me.me_at=&((*crtNature).second);
}

void mainStart(){
    printf("waking...\n");
    /*
    FILE* fp=NULL;
    fp=fopen(star_way,"rb");
    */
    
    fstream first_io;
    first_io.open(star_way,ios::in|ios::binary);//读取操作
    
    if(!first_io.is_open()){
        createNature();
        //fp=fopen(star_way,"wb+");
        first_io.open(star_way,ios::out|ios::binary);//写入
        
        
        printf("first\n");
        multimap<string,star>::iterator star_it_crtnat=starMap.begin();
        
        while(1){
            
            
            
            
            
            first_io.write((const char*)&(*star_it_crtnat),sizeof(pair<string,star>));
            
            
            if(star_it_crtnat!=--starMap.end()){
                star_it_crtnat++;
                printf("1\n");
            }
            else{
                goto dd1554;
            };
        }
        dd1554:
        //fclose(fp);
        first_io.close();
    }
    else{
        
        
        pair<string,star> star_read;//=new star;
        
        FILE* fp=fopen(star_way,"rb");
        long count=0l;
        long doc_length=get_size(fp);
        fclose(fp);
        while(1){
            
            
            count=count+1l;
            
            
            first_io.read((char*)&star_read,sizeof(pair<string,star>));
            
            sleep(1);
            printf("once\n");
            //printf("%ld",doc_length);
            starMap.insert(star_read);
            
            
            if(count==doc_length){
                goto dd00;
            };
        }
        dd00:
        //fclose(fp);
        //delete star_read;
        first_io.close();
        printf("size=%d\n",starMap.size());
    };
    printf("awake.\n");
}




void mainUpdate(){
    /*………………………………………………一次双循环…………………………………………………*/
    multimap<string,star>::iterator star_it_p=starMap.begin();
    multimap<string,star>::iterator star_it_t=starMap.begin();
    
    while(1){
        while(1){
            if(star_it_p!=star_it_t){
                double disX,disY,disZ;
                double distance;
                disX=((*star_it_p).second.starPos).posX-((*star_it_t).second.starPos).posX;
                disY=((*star_it_p).second.starPos).posY-((*star_it_t).second.starPos).posY;
                disZ=((*star_it_p).second.starPos).posZ-((*star_it_t).second.starPos).posZ;
                distance=sqrt(pow(disX,2.000000)+pow(disY,2.000000)+pow(disZ,2.000000))*pow(10.000000,3.000000);
                ((*star_it_p).second.starA).aX=roughG*((*star_it_t).second.mass)*pow(10.000000,tenPlusG+(*star_it_t).second.tenTime)*disX/pow(distance,3.000000);
                ((*star_it_p).second.starA).aY=roughG*((*star_it_t).second.mass)*pow(10.000000,tenPlusG+(*star_it_t).second.tenTime)*disY/pow(distance,3.000000);
                ((*star_it_p).second.starA).aZ=roughG*((*star_it_t).second.mass)*pow(10.000000,tenPlusG+(*star_it_t).second.tenTime)*disZ/pow(distance,3.000000);
            };
            
            
            
            
            
            
            
            
            
            
            
            printf("双循环一次");
            if(star_it_t!=--starMap.end()){
                star_it_t++;
            }
            else{
                goto dd1;
            };
        }
        dd1:
        if(star_it_p!=--starMap.end()){
            star_it_p++;
            star_it_t=starMap.begin();
            //star_it_t++;
        }
        else{
            goto dd2;
        };
    }
    dd2:
    printf("双循环结束");
    /*…………………………………………一次单循环…………………………………………………………*/
    multimap<string,star>::iterator star_it_u=starMap.begin();
    /*
    FILE* fp1=NULL;
    fp1=fopen(star_way,"wb+");
    */
    
    fstream star_save;
    star_save.open(star_way,ios::out|ios::binary);
    
    while(1){
        //更新位置
        
        /*
        ((*star_it_u).starV).vX+=((*star_it_u).starA).aX*moveTick;
        ((*star_it_u).starV).vY+=((*star_it_u).starA).aY*moveTick;
        ((*star_it_u).starV).vZ+=((*star_it_u).starA).aZ*moveTick;
        
        ((*star_it_u).starPos).posX+=((*star_it_u).starV).vX*moveTick;
        ((*star_it_u).starPos).posY+=((*star_it_u).starV).vY*moveTick;
        ((*star_it_u).starPos).posZ+=((*star_it_u).starV).vZ*moveTick;
        */
        
        (*star_it_u).second.updateV();
        (*star_it_u).second.updatePos();
        
        printf("%lf\n",((*star_it_u).second.starPos).posY);
        
        
        
        
        
        printf("断点");
        star_save.write((const char*)&(*star_it_u),sizeof(pair<string,star>));
        
        
        
        
        printf("单循环一次");
        //不满足则跳出
        if(star_it_u!=--starMap.end()){
            star_it_u++;
            printf("加1\n");
        }
        else{
            goto dd3;
        };
        
    }
    dd3:
    
    
    //printf("end\n数量：%d\n",starMap.size());
    
    //fclose(fp1);
    star_save.close();
}







