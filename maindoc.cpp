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
#define struct_way "/storage/emulated/0/C++Projects/theLastOne-2/structdoc.lodoc"
#define fon_way "/storage/emulated/0/C++Projects/theLastOne-2/first_or_not.lodoc"
template <typename T1>
long get_size(FILE* input_fp) 
{
    FILE *fp_gs = input_fp;
    fseek(fp_gs, 0, SEEK_END);
    long filesize = ftell(fp_gs)/(long)sizeof(pair<string,T1>);
    fclose(fp_gs);
    return filesize;
}

void createNature(){
    starMap.insert(createStar("starship0",7.000000,3.000000,{0.000000,2345.000000,2345.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));//飞船
    
    
    starMap.insert(createStar("sun",1.989000,30.000000,{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));//太阳
    starMap.insert(createStar("earth",5.965000,24.000000,{0.000000,149597870.000000,0.000000},{0.000000,1800.000000,0.000000},{0.000000,0.000000,0.000000}));//地球
    
    multimap<string,star>::iterator crtNature_star_it=starMap.begin();
    
    me.me_at=&(crtNature_star_it->second);
    one_part crtNature_parts1[parts_in_one_struct];
    int crtNature_linkmap1[parts_in_one_struct][parts_in_one_struct];
    for(int ct1=0;ct1<parts_in_one_struct;ct1++){
        crtNature_parts1[ct1]={0,0,0.000000,false};
        for(int ct2=0;ct2<parts_in_one_struct;ct2++){
            crtNature_linkmap1[ct1][ct2]=0;
        }
    }
    crtNature_parts1[1]={3,100,1.000000,false};
    crtNature_parts1[2]={22,100,1.000000,false};
    crtNature_linkmap1[1][2]=1;
    structMap.insert(createStruct("starship00",me.me_at,crtNature_parts1,crtNature_linkmap1));
    
}



void mainStart(){
    printf("waking...\n");
    
    fstream first_star_io;
    fstream first_struct_io;
    
    fstream first_fon_io;
    
    first_fon_io.open(fon_way,ios::in|ios::binary);//读取操作
    
    
    if(!first_fon_io.is_open()){//如果不存在
        first_fon_io.open(fon_way,ios::out|ios::binary);
        first_fon_io.close();
        
        
        createNature();
        //star写入开始
        first_star_io.open(star_way,ios::out|ios::binary);//写入
        multimap<string,star>::iterator star_it_crtnat=starMap.begin();
        while(1){
            first_star_io.write((const char*)&(*star_it_crtnat),sizeof(pair<string,star>));
            
            
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
        first_star_io.close();
        //star写入结束
        
        //struct写入开始
        first_struct_io.open(struct_way,ios::out|ios::binary);
        multimap<string,one_struct>::iterator struct_it_crtnat=structMap.begin();
        while(1){
            
            first_struct_io.write((const char*)&(*struct_it_crtnat),sizeof(pair<string,one_struct>));
            
            if(struct_it_crtnat!=--structMap.end()){
                struct_it_crtnat++;
                printf("1\n");
            }
            else{
                goto dd2005;
            };
        }
        
        dd2005:
        
        first_struct_io.close();
        //struct写入结束
    }
    else{//如果存在
        first_fon_io.close();
        {//star作用域开始…………………………………………………………………………………………
        //star开始
        pair<string,star> star_read;//=new star;
        
        FILE* fp=fopen(star_way,"rb");
        long count=0l;
        long doc_length=get_size<star>(fp);
        fclose(fp);
        
        
        first_struct_io.open(struct_way,ios::in|ios::binary);
        while(1){
            
            
            count=count+1l;
            
            
            first_star_io.read((char*)&star_read,sizeof(pair<string,star>));
            
            sleep(1);
            printf("once\n");
            printf("%ld",doc_length);
            starMap.insert(star_read);
            
            
            if(count==doc_length){
                goto dd00;
            };
        }
        dd00:
        
        first_star_io.close();
        printf("size=%d\n",starMap.size());
        }//star作用域结束……………………………………………………………………………………
        //one_struct开始
        {//one_struct作用域开始………………………………………………………………
        pair<string,one_struct> struct_read;//
        
        
        FILE* fp=fopen(struct_way,"rb");
        long count=0l;
        long doc_length=get_size<one_struct>(fp);
        fclose(fp);
        
        
        first_struct_io.open(struct_way,ios::in|ios::binary);
        while(1){
            
            
            count=count+1l;
            
            
            first_struct_io.read((char*)&struct_read,sizeof(pair<string,one_struct>));
            
            sleep(1);
            printf("once\n");
            printf("%ld",doc_length);
            structMap.insert(struct_read);
            
            
            if(count==doc_length){
                goto dd0919;
            };
        }
        dd0919:
        
        first_struct_io.close();
        
        }//one_struct作用域结束………………………………………………………………
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
            
            
            
            
            
            
            
            
            
            
            
            //printf("双循环一次");
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
    //printf("双循环结束");
    /*…………………………………………一次star单循环……………………………………………………*/
    multimap<string,star>::iterator star_it_u=starMap.begin();
    
    
    fstream star_save;
    star_save.open(star_way,ios::out|ios::binary);
    
    while(1){
        //更新位置
        (*star_it_u).second.updateV();
        (*star_it_u).second.updatePos();
        
        
        //printf("断点");
        star_save.write((const char*)&(*star_it_u),sizeof(pair<string,star>));
        
        
        
        
        //printf("单循环一次");
        //不满足则跳出
        if(star_it_u!=--starMap.end()){
            star_it_u++;
            //printf("加1\n");
        }
        else{
            goto dd3;
        };
        
    }
    dd3:
    star_save.close();
    
    
    
    /*…………………………………………struct单循环一次……………………………………*/
    multimap<string,one_struct>::iterator struct_it_u=structMap.begin();
    
    fstream struct_save;
    struct_save.open(struct_way,ios::in|ios::binary);
    
    while(1){
        
        //printf("断点");
        //struct_save.write((const char*)&(*struct_it_u),sizeof(pair<string,one_struct>));
        
        //不满足则跳出
        if(struct_it_u!=--structMap.end()){
            struct_it_u++;
            
        }
        else{
            goto dd2012;
        };
        
    }
    dd2012:
    
    
    struct_save.close();
}