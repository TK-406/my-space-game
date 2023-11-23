#include "/storage/emulated/0/C++Projects/theLastOne-2/star.cpp"
#include "/storage/emulated/0/C++Projects/theLastOne-2/interact.cpp"

void createNature(){
    starList.push_back(createStar(1.989000,30.000000,{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000}));
    starList.push_back(createStar(5.965000,24.000000,{0.000000,149597870.000000,0.000000},{0.000000,1800.000000,0.000000},{0.000000,0.000000,0.000000}));
}

void mainStart(){
    FILE* fp;
    fp=fopen("/storage/emulated/0/C++Projects/theLastOne-2/stardoc.lodoc","rb");
    if(fp==NULL){
        createNature();
    }
    else{
        list<star>::iterator star_it_read=starList.begin();
        star* star_read=new star;
        while(1){
            fread(star_read,sizeof(star),1,fp);
            
            starList.push_front(*star_read);
            if(feof(fp)!=0){
                goto dd00;
            }
            else{
                
            };
        }
        dd00:
        delete star_read;
        fclose(fp);
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
                distance=sqrt(pow(disX,2.000000)+pow(disY,2.000000)+pow(disZ,2.000000));
                ((*star_it_p).starA).aX+=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disX/pow(distance,3.000000);
                ((*star_it_p).starA).aY+=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disY/pow(distance,3.000000);
                ((*star_it_p).starA).aZ+=roughG*pow(10.000000,tenPlusG+(*star_it_t).tenTime)*disZ/pow(distance,3.000000);
            };
            
            
            
            
            
            
            
            
            
            
            
            
            if(star_it_t!=starList.end()){
                star_it_t++;
            }
            else{
                goto dd1;
            };
        }
        dd1:
        if(star_it_p!=starList.end()){
            star_it_p++;
            star_it_t=starList.begin();
        }
        else{
            goto dd2;
        };
    }
    dd2:
    /*…………………………………………一次单循环…………………………………………………………*/
    list<star>::iterator star_it_u=starList.begin();
    
    FILE* fp;
    fp=fopen("/storage/emulated/0/C++Projects/theLastOne-2/stardoc.lodoc","wb+");
    
    
    while(1){
        //更新位置
        ((*star_it_u).starV).vX+=((*star_it_u).starA).aX*moveTick;
        ((*star_it_u).starV).vY+=((*star_it_u).starA).aY*moveTick;
        ((*star_it_u).starV).vZ+=((*star_it_u).starA).aZ*moveTick;
        
        ((*star_it_u).starPos).posX+=((*star_it_u).starV).vX*moveTick;
        ((*star_it_u).starPos).posY+=((*star_it_u).starV).vY*moveTick;
        ((*star_it_u).starPos).posZ+=((*star_it_u).starV).vZ*moveTick;
        
        
        
        //保存
        
        fwrite(&(*star_it_u),sizeof(star),1,fp);
        
        
        //不满足则跳出
        if(star_it_u!=starList.end()){
            star_it_u++;
        }
        else{
            goto dd3;
        };
        
    }
    dd3:
    
    
    
    fclose(fp);
}







