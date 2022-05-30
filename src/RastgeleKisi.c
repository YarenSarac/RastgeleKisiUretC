/**  *  * @author YAREN SARAÇ-MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr - merve.kardes@ogr.sakarya.edu.tr * @since 24.04.2020  *  RastgeleKisi sýnýfýmýzý oluþturduk.  */ 

#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur(){
RastgeleKisi this;
this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
this->i = 0;
this->secKisi = &sec_Kisi;
this->Yoket=&RastgeleKisiYoket;

//this->Yoket = &RastgeleKisiYoket;
return this;
}


char* sec_Kisi(RastgeleKisi this )
{   
    Rastgele rast=RastgeleOlustur();
    int x= rast->anlikZaman(rast,3000);
	FILE *pFile;
//	char line[3000];
    char *isimTut=malloc(30);
    int i=1;
	pFile=fopen("random_isimler.txt","r");

	if(pFile!=NULL)
   {
	while((fgets(isimTut, 30, pFile) != NULL))
	{
	if(i==x){
		fclose(pFile);
		isimTut[strcspn(isimTut,"\n")] = 0;
		return isimTut;
	
	}		
//	isimTut[i]=fgets(line,i,pFile);
   // printf("%s",isimTut[i]);
	i++;
	}
	fclose(pFile);
   }
	else
	{
	printf("Dosya bulunamadi.");	
	}
	    
    return isimTut;
    
}

void RastgeleKisiYoket(RastgeleKisi this){
	if(this == NULL) 
	return;
	free(this);	
}



