#include<cs50.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        fprintf(stderr," Usage : ./recover card.raw");
        return 1;
    }
    char *card.raw=argv[1];
    
    FILE*inptr=fopen(card.raw,"r");
    if(inptr==NULL)
    {
        fprintf(stderr,"couldn't open the file");
        return 2;
    }
    unsigned char buffer[512]
    
    int files_found=0;
    
    FILE*img=0;
    
    while(fread(buffer,512,1,inptr)==1)
    {
    
    if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0)
    {   
        if(img!=NULL)
        fclose(img);
        
        char filename[8]
        sprintf(filename,"%03i.jpg",files_found);
        FILE*img=fopen(filename,"w");
        
        files_found++;
        
    }
    if(img!=NULL)
    {
        fwrite(buffer,512,1,img);
    }
    }
    if(img!=NULL)
    fclose(img);
    fclose(inptr);
}