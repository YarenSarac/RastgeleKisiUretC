#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include"Rastgele.h"
#include"RastgeleKisi.h"
#include"Telefon.h"
#include"IMEINo.h"
#include"KimlikNo.h"



struct KISI{
	
    Rastgele rast;
    Telefon tel1;
    KimlikNo kimliikNo;
    IMEINo imeiiNo;
    RastgeleKisi rastKisi;
    void(*KisiVer)(struct KISI*,int);
    char*(*YasAl)(struct KISI*);
    void(*Yoket)(struct KISI*);
    
};

typedef struct KISI* Kisi;
 Kisi KisiOlustur();
 void Kisi_Ver(Kisi,int);
 char* Yas_Al(Kisi);
 void KisiYoket(Kisi);

#endif

