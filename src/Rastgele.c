/**  *  * @author YAREN SARAÇ - MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr- merve.kardes@ogr.sakarya.edu.tr * @since 24.04.2020  *  Rastgele sýnýfýmýzý oluþturduk.  */ 

#include "Rastgele.h"
#include <time.h>
#include <sys/time.h>


Rastgele RastgeleOlustur(){
Rastgele this;
this = (Rastgele)malloc(sizeof(struct RASTGELE));
this->yenimilisaniye = 0;
this->milisaniye = 0;
this->i = 0;
this->zamanFarki = &zamanFarki1;
this->anlikZaman=&anlikZaman1;
this->Yoket=&RastgeleYoket;
return this;
}

float zamanFarki1(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

    int anlikZaman1(Rastgele this,int i)
	 {
	 	int deger=507;
	 	static int deger1=768;
	 	deger1 += deger;
    struct timeval te; 
    gettimeofday(&te, NULL); 
    this->milisaniye = te.tv_sec*1000LL + te.tv_usec/1000 + deger1; // calculate milliseconds  
    this-> yenimilisaniye=((this->milisaniye)%i);
    return this->yenimilisaniye;
     }

void RastgeleYoket(Rastgele this)
{
	if(this == NULL) 
	return;
	free(this);	
}
