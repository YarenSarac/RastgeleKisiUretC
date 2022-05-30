/**  *  * @author YAREN SARAÇ- MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr - merve.kardes@ogr.sakarya.edu.tr* @since 24.04.2020  * IMEI sýnýfýmý oluþturdum.  */ 

#include"IMEINo.h"
#include<string.h>
 IMEINo imeinoOlustur(){
 	
IMEINo this;
this = (IMEINo)malloc(sizeof(struct IMEINO));
this->rast=RastgeleOlustur();
this->toplam1 = 0;
this->toplam = malloc(16);
this->imeiVer=&imei_Ver;
this->imeiNoKontrol=&imeiNo_Kontrol;
this->Yoket=&IMEINoYoket;
return this;
}


    char* imei_Ver(IMEINo this)
	{
    	
    char*basamak = malloc(1);  
    char *kodlar[] = {	"10","30","33","35","44","45","49","50","51","52","53","54","86","91","98","99",NULL};
    int random_sayi = this->rast->anlikZaman(this->rast,16);
    snprintf(this->toplam,sizeof(kodlar[random_sayi]),"%s",kodlar[random_sayi]);
    if(random_sayi==0)
	{
        this->	imeiNo[0]=1;
        this->	imeiNo[1]=0;
	}
	
  

	if(random_sayi==0)
	{
			for(int i=2;i<14;i++)
	{
		
		this->imeiNo[i]=this->rast->anlikZaman(this->rast,10);
		int b=this->imeiNo[i];
        sprintf(basamak,"%d",b);
        snprintf(this->toplam,15,"%s%s",this->toplam,basamak);
      
	}
	}
	else
	{
		
	for(int i=2;i<14;i++)
	{
		int b=this->rast->anlikZaman(this->rast,10);
		sprintf(basamak,"%d",b);
        snprintf(this->toplam,15,"%s%s",this->toplam,basamak);
	}	
	
	
		
	char*eptr;
    long long imei = strtoll(this->toplam,&eptr,10);
	for(int i=13;i>=0;i--)
	{
		
	 this->imeiNo[i]=imei%10;
	 imei=imei/10;
	 	
	}
				
	}
  
   for(int m=0;m<14;m++)
	{
         if(m%2==0)
          {
           this->toplam1+=this->imeiNo[m];
          }
            
            else
            
            {
	            this->imeiNo[m]*=2;
	            
	            if(this->imeiNo[m]>9)
	            {
	            this->toplam1+=(this->imeiNo[m]%10)+1;
	            }
	            else
	            {
	            this->toplam1+=this->imeiNo[m];
            }
            }
		
	}
	
 int sayi=(this->toplam1*9)%10;
 sprintf(basamak,"%d",sayi);
 snprintf(this->toplam,16,"%s%s",this->toplam,basamak);	
 free(basamak);
 return this->toplam;
	
} 


void IMEINoYoket(IMEINo this)
{
    	if(this == NULL) 
		return; 
//		free(basamak);
	    free(this->toplam);
     	free(this);	
}




void imeiNo_Kontrol(IMEINo this){
	
	    
        FILE *dosya = fopen("Kisiler.txt","r");
        char k1[11];
        char k2[25];
        char k3[25];
        char k4[2];
        char k5[11];
        char k6[17];
        int dogru = 0;
        int yanlis = 0;
        if(dosya != NULL)
		{
        	

        	while(!feof(dosya))
			{
        		int toplam = 0;
        		int a=1;
        		fscanf(dosya,"%s %s %s %s %s %s",k1,k2,k3,k4,k5,k6);
        		char gecici[16];
        		strncpy(gecici,k6+1,strlen(k6)-2);
        		char *eptr;
		        long long imei2=strtoll(gecici,&eptr,10);
		        int  kontrolDizi[15];
		        for(int i=14;i>=0;i--)
				{
		           kontrolDizi[i]=imei2%10;
		           
		           imei2=imei2/10;	
				}
				if(strlen(gecici)!=15)
	         	{
			    yanlis++;
		        }
		        else
				{
		           if(kontrolDizi[0]==2||kontrolDizi[0]==6||kontrolDizi[0]==7)
				   {
	                yanlis++;
	                a++;
            		}	
					else
            {
                 if(kontrolDizi[0]==0)
        {
          if(kontrolDizi[1]!=1){
              yanlis++;
              a++;
          }
        }
        else if(kontrolDizi[0]==1)
        {
            if(kontrolDizi[1]!=0){
                yanlis++;
                a++;
            }
        }
         else if(kontrolDizi[0]==3)
        {
            if(kontrolDizi[1]!=0&&kontrolDizi[1]!=3&&kontrolDizi[1]!=5){
                yanlis++;
                a++;
            }
        }
         else if(kontrolDizi[0]==4)
        {
            if(kontrolDizi[1]!=4&&kontrolDizi[1]!=5&&kontrolDizi[1]!=9){
                yanlis++;
                a++;
            }
        }
            else if(kontrolDizi[0]==5)
        {
            if(kontrolDizi[1]!=0&&kontrolDizi[1]!=2&&kontrolDizi[1]!=3&&kontrolDizi[1]!=4&&kontrolDizi[1]!=1){
                yanlis++;
                a++;
            }
        }
         else if(kontrolDizi[0]==8)
        {
            if(kontrolDizi[1]!=6){
                yanlis++;
                a++;
            }
        }
           else if(kontrolDizi[0]==9)
        {
            if(kontrolDizi[1]!=1&&kontrolDizi[1]!=8&&kontrolDizi[1]!=9){
                yanlis++;
                a++;
            }
        }
        int imeitoplam=0;
        			    if(a==1)
             {
                for(int i=0;i<14;i++)
                {
                    if(i%2==0)
                    {
                    imeitoplam+=kontrolDizi[i];
                    }
                    else
                    { 
                   kontrolDizi[i]*=2;
                        if(kontrolDizi[i]>9)
                        {
                        imeitoplam+=(kontrolDizi[i]%10)+1;
                        }
                        else
                        {
                        imeitoplam+=kontrolDizi[i];
                        }
                    }
                }
                if(kontrolDizi[14]!=(imeitoplam*9)%10)
                {
                yanlis++;
                }
                else
                {
                dogru++;
                }

             }
            }	
            
				}
					        
			}
			
			
			printf("IMEI GECERLI: %d\n",dogru);
			printf("IMEI GECERSIZ: %d\n\n",yanlis);
			
        	
		}
		else
			printf("Dosya yok");
		
		
		
}







