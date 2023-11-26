#include "/storage/emulated/0/C++Projects/theLastOne-2/star.cpp"
#include "/storage/emulated/0/C++Projects/theLastOne-2/interact.cpp"
#include "/storage/emulated/0/C++Projects/theLastOne-2/me.cpp"
#include <thread>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#define star_way "/storage/emulated/0/C++Projects/theLastOne-2/stardoc.lodoc"

long get_size(FILE* input_fp) 
{
    FILE *fp_gs = input_fp;
    fseek(fp_gs, 0, SEEK_END);
    long filesize = ftell(fp_gs)/(long)sizeof(star);
    fclose(fp_gs);
    return filesize;
}

void createNature(){
    
    starList.push_back(createStar(1.989000,30.000000,{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));
    starList.push_back(createStar(5.965000,24.000000,{0.000000,149597870.000000,0.000000},{0.000000,1800.000000,0.000000},{0.000000,0.000000,0.000000}));
}

void mainStart(){
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
        list<star>::iterator star_it_crtnat=starList.begin();
        
        while(1){
            
            
            
            
            //fwrite(&(*star_it_crtnat),sizeof(star),1,fp);
            first_io.write((const char*)&(*star_it_crtnat),sizeof(star));
            
            
            if(star_it_crtnat!=--starList.end()){
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
        
        
        star star_read;//=new star;
        
        FILE* fp=fopen(star_way,"rb");
        long count=0;
        long doc_length=get_size(fp);
        fclose(fp);
        while(1){
            
            
            count=count+1;
            
            //fread(&star_read,sizeof(star),1,fp);
            first_io.read((char*)&star_read,sizeof(star));
            
            sleep(1);
            printf("once\n");
            //printf("%ld",doc_length);
            starList.push_back(star_read);
            
            
            if(count==doc_length){
                goto dd00;
            };
        }
        dd00:
        //fclose(fp);
        //delete star_read;
        first_io.close();
        printf("size=%d\n",starList.size());
    };
    
}




void mainUpdate(){
    /*………………………………………………一次双循环…………………………………………………*/
    list<star>::iterator star_it_p=starList.begin();
    list<star>::iterator star_it_t=starList.begin();
    
    while(1){
        while(1){
            if(star_it_p!=star_it_t){
                double disX,disY,disZ;
                double distance;
                disX=((*star_it_p).starPos).posX-((*star_it_t).starPos).posX;
                disY=((*star_it_p).starPos).posY-((*star_it_t).starPos).posY;
                disZ=((*star_it_p).starPos).posZ-((*star_it_t).starPos).posZ;
                distance=sqrt(pow(disX,2.000000)+pow(disY,2.000000)+pow(disZ,2.000000))*pow(10.000000,3.000000);
                ((*star_it_p).starA).aX=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disX/pow(distance,3.000000);
                ((*star_it_p).starA).aY=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disY/pow(distance,3.000000);
                ((*star_it_p).starA).aZ=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disZ/pow(distance,3.000000);
            };
            
            
            
            
            
            
            
            
            
            
            
            
            if(star_it_t!=--starList.end()){
                star_it_t++;
            }
            else{
                goto dd1;
            };
        }
        dd1:
        if(star_it_p!=--starList.end()){
            star_it_p++;
            star_it_t=starList.begin();
            //star_it_t++;
        }
        else{
            goto dd2;
        };
    }
    dd2:
    /*…………………………………………一次单循环…………………………………………………………*/
    list<star>::iterator star_it_u=starList.begin();
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
        (*star_it_u).updateV();
        (*star_it_u).updatePos();
        
        printf("%lf\n",((*star_it_u).starPos).posY);
        
        //保存
        
        //fwrite(&(*star_it_u),sizeof(star),1,fp1);
        
        star_save.write((const char*)&(*star_it_u),sizeof(star));
        
        
        
        
        
        
        
        
        //不满足则跳出
        if(star_it_u!=--starList.end()){
            star_it_u++;
            printf("加1\n");
        }
        else{
            goto dd3;
        };
        
    }
    dd3:
    
    
    //printf("end\n数量：%d\n",starList.size());
    
    //fclose(fp1);
    star_save.close();
}







