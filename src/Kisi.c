/**  *  * @author YAREN SARAÇ - MERVE KARDEÞ * yaren.sarac@ogr.sakarya.edu.tr - merve.kardes@ogr.sakarya.edu.tr* @since 24.04.2020  *  Kisi sýnýfýmýzý oluþturduk.  */ 
 
#include"Kisi.h"
 
Kisi KisiOlustur(){
 	
Kisi this;
this = (Kisi)malloc(sizeof(struct KISI));
this->rast=RastgeleOlustur();
this->tel1=TelefonOlustur();
this->kimliikNo=KimlikNoOlustur();
this->imeiiNo=imeinoOlustur();
this->rastKisi=RastgeleKisiOlustur();
this->KisiVer=&Kisi_Ver;
this->YasAl=&Yas_Al;
this->Yoket=&KisiYoket;
return this;
}


char* Yas_Al(Kisi this){
	char *basamak=malloc(3);
  //  this->rast->anlikZaman(this->rast,101);
    int a= this->rast->anlikZaman(this->rast,101);
    
    sprintf(basamak,"%d",a);
    
    return basamak;
    
}




void Kisi_Ver(Kisi this,int b){
	
	
  FILE *fPointer;   
  fPointer =fopen("Kisiler.txt","w");
  for(int i=0;i<b;i++)
  { 
   char myTxt[100];
  this->rast=RastgeleOlustur();
  this->tel1=TelefonOlustur();
  this->kimliikNo=KimlikNoOlustur();
  this->imeiiNo=imeinoOlustur();
  this->rastKisi=RastgeleKisiOlustur();
    
    myTxt[0]=0;
 // 	fprintf(fPointer,"%s %s %s %s (%s) \n ",this->kimliikNo->KimlikNoAl(this->kimliikNo),this->rastKisi->secKisi(this->rastKisi),this->YasAl(this),this->tel1->numaraVer(this->tel1),this->imeiiNo->imeiVer(this->imeiiNo));
   
    if(i==(b-1))
	{
  //  fprintf(fPointer,"%s %s %s %s (%s)", this->kimliikNo->KimlikNoAl(this->kimliikNo),this->rastKisi->secKisi(this->rastKisi),this->YasAl(this),this->tel1->numaraVer(this->tel1),this->imeiiNo->imeiVer(this->imeiiNo));
    fprintf(fPointer,"%s ",this->kimliikNo->KimlikNoAl(this->kimliikNo));
    fprintf(fPointer,"%s ",this->rastKisi->secKisi(this->rastKisi));
    fprintf(fPointer,"%s ",this->YasAl(this));
    fprintf(fPointer,"%s ",this->tel1->numaraVer(this->tel1));
    fprintf(fPointer,"(%s)",this->imeiiNo->imeiVer(this->imeiiNo));
    
    
    
    
	}
  
  
  else
  {
// fprintf(fPointer,"%s %s %s %s (%s) \n", this->kimliikNo->KimlikNoAl(this->kimliikNo),this->rastKisi->secKisi(this->rastKisi),this->YasAl(this),this->tel1->numaraVer(this->tel1),this->imeiiNo->imeiVer(this->imeiiNo));

    fprintf(fPointer,"%s ",this->kimliikNo->KimlikNoAl(this->kimliikNo));
    fprintf(fPointer,"%s ",this->rastKisi->secKisi(this->rastKisi));
    fprintf(fPointer,"%s ",this->YasAl(this));
    fprintf(fPointer,"%s ",this->tel1->numaraVer(this->tel1));
    fprintf(fPointer,"(%s)",this->imeiiNo->imeiVer(this->imeiiNo));
    fprintf(fPointer,"\n");
    


  }
  
  }
 
  fclose(fPointer);	
	
}


void KisiYoket(Kisi this)
{
	
	if(this == NULL)
	return;  	
  this->rast->Yoket(this->rast);
  this->imeiiNo->Yoket(this->imeiiNo);
  this->kimliikNo->Yoket(this->kimliikNo);
  this->rastKisi->Yoket(this->rastKisi);
  this->tel1->Yoket(this->tel1);
  free(this);
  
}



