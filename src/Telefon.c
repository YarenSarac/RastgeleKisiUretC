/**  *  * @author YAREN SARAÇ-MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr- merve.kardes@ogr.sakarya.edu.tr * @since 24.04.2020  *  Telefon sýnýfýmýzý oluþturduk.  */ 

#include"Telefon.h"

 Telefon TelefonOlustur(){
 	
Telefon this;
this = (Telefon)malloc(sizeof(struct TELEFON));
this->rastgele=RastgeleOlustur();
this->toplam = malloc(7);
this->numaraAl = &numara_Al;
this->numaraVer=&numara_Ver;
this->Yoket=&TelefonYoket;
return this;
}

void numara_Al(Telefon this)
{
   
    char *kodlar[] = {"0501","0505","0506","0507","0551","0552","0553","0554","0555","0559","0530","0531","0532","0533","0534","0535","0536","0537","0538","0539","0561","0540","0541","0542","0543","0544","0545","0546","0547","0548","0549",NULL};
    int random_sayi = this->rastgele->anlikZaman(this->rastgele,31);
    this->telIlk=kodlar[random_sayi];
}
char* numara_Ver(Telefon this){
	
	
	this->numaraAl(this);
	char*basamak = malloc(1);
	int a=this->rastgele->anlikZaman(this->rastgele,10);
	this->telNo[0]=a;
	sprintf(basamak,"%d",a);
	snprintf(this->toplam,sizeof(basamak),"%s",basamak);
	for(int i=1;i<7;i++)
	{
		this->telNo[i]=this->rastgele->anlikZaman(this->rastgele,10);
		int b=this->telNo[i];
        sprintf(basamak,"%d",b);
        snprintf(this->toplam,8,"%s%s",this->toplam,basamak);
	}
	snprintf(this->tel,12,"%s%s",this->telIlk,this->toplam);
	free(basamak);
return this->tel;
}


void TelefonYoket(Telefon this)
{
	if(this == NULL) 
	return;
	free(this->toplam);
	 free(this->tel); 
	free(this);	
}

