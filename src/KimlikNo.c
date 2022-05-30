/**  *  * @author YAREN SARAÇ- MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr - merve.kardes@ogr.sakarya.edu.tr * @since 24.04.2020  *  KimlikNo sýnýfýmýzý oluþturduk.  */ 

#include"KimlikNo.h"

 KimlikNo KimlikNoOlustur(){
 	
KimlikNo this;
this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));

this->toplam = malloc(11);
this->KimlikNoAl = &KimlikNo_Al;
this->KontrolTc=&Kontrol_Tc;
this->rast=RastgeleOlustur();
this->Yoket=&KimlikNoYoket;
return this;
}

char* KimlikNo_Al(KimlikNo this){
	
	char*basamak = malloc(1);
    this->KimlikNo1[0]=(this->rast->anlikZaman(this->rast,9)+1);
    sprintf(basamak,"%d",this->KimlikNo1[0]);
     snprintf(this->toplam,sizeof(basamak),"%s",basamak); 
     
	for(int i=1;i<=8;i++)
	{
		this->KimlikNo1[i]=this->rast->anlikZaman(this->rast,10);     
		int b=this->KimlikNo1[i];
        sprintf(basamak,"%d",b);
        snprintf(this->toplam,10,"%s%s",this->toplam,basamak);
	}

           int sonuc1= ((this->KimlikNo1[0]+this->KimlikNo1[2]+this->KimlikNo1[4]+this->KimlikNo1[6]+this->KimlikNo1[8])*7)-(this->KimlikNo1[1]+this->KimlikNo1[3]+this->KimlikNo1[5]+this->KimlikNo1[7]);
           int onbulma=sonuc1%10;
           this->KimlikNo1[9]=onbulma;
            
		 sprintf(basamak,"%d",this->KimlikNo1[9]);
         snprintf(this->toplam,11,"%s%s",this->toplam,basamak);	
			
			
			          
           int sonuc2= this->KimlikNo1[0]+this->KimlikNo1[1]+this->KimlikNo1[2]+this->KimlikNo1[3]+this->KimlikNo1[4]+this->KimlikNo1[5]+this->KimlikNo1[6]+this->KimlikNo1[7]+this->KimlikNo1[8]+this->KimlikNo1[9];
           int onbirbulma=sonuc2%10;
           this->KimlikNo1[10]=onbirbulma;   

         sprintf(basamak,"%d",this->KimlikNo1[10]);
         snprintf(this->toplam,12,"%s%s",this->toplam,basamak);	
       //  printf("%s",this->toplam);
         free(basamak);
         
return this->toplam;

}
void KimlikNoYoket(KimlikNo this){
	
	
	if(this == NULL)
	return;  
	free(this->toplam);
	free(this);
	

}


 void Kontrol_Tc(KimlikNo this){
	

	
	    int yanlis=0;
        int dogru=0;
               
        FILE *dosya;
        char k1[11];
        char k2[17];
        char k3[17];
        char k4[17];
        char k5[17];
        char k6[17];
        
        int dizi[11];
        
        if((dosya=fopen("Kisiler.txt","r"))!=NULL)
		{ 
		while(!feof(dosya))
		{
		   fscanf(dosya,"%s %s %s %s %s %s",&k1,&k2,&k3,&k4,&k5,&k6);	
		   
		   
		char *eptr;
		long long kimlik=strtoll(k1,&eptr,10);
		for(int i=10;i>=0;i--)
		{
		   dizi[i]=kimlik%10;
		   kimlik=kimlik/10;	
		}
		
		if(strlen(k1)!=11)
		{
			yanlis++;
		}
		else
		{
		  	if(dizi[0]==0)
			  {
		  		yanlis++;
			  }
			  else
			  {
			  	int sonuc1= ((dizi[0]+dizi[2]+dizi[4]+dizi[6]+dizi[8])*7)-(dizi[1]+dizi[3]+dizi[5]+dizi[7]);
			  	if(dizi[9]!=sonuc1%10){
			  		yanlis++;
				  }
				  else{
				  	int sonuc=0;
				  	for(int i=0;i<=9;i++){
				  		sonuc+=dizi[i];				  		
					  }
					  if(dizi[10]!=sonuc%10){
					  	yanlis++;
					  }
					  else{
					  	dogru++;
					  }
				  }
			  }		  
		}
		
			
		}
		printf("Kimlik GECERLI:%d\n",dogru);  
        printf("Kimlik GECERSIZ:%d\n\n",yanlis); 
        fclose(dosya);
		}
		
		
		
		
}
		






