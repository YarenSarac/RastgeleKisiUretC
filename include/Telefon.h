#ifndef TELEFON_H
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include"Rastgele.h"

struct TELEFON{
	
	Rastgele rastgele;
//	char telRandom[7];
	char *telIlk;
	int telNo[7];
	char tel[11];
	char* toplam;
	void (*numaraAl)(struct TELEFON*);
	char* (*numaraVer)(struct TELEFON*);
	void(*Yoket)(struct TELEFON*);	
//	char*(*numaraTamami)(struct TELEFON*);

};

typedef struct TELEFON* Telefon;
 Telefon TelefonOlustur();
 void numara_Al(Telefon);
 char* numara_Ver(Telefon);
 void TelefonYoket(Telefon);
 //void numara_Tamami(Telefon);


#endif
