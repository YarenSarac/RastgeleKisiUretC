#ifndef IMEINO_H
#define IMEINO_H

#include "stdio.h"
#include "stdlib.h"
#include"Rastgele.h"

struct IMEINO{
	
    Rastgele rast;
	int imeiNo[14];
	char* imeiIlk;
	char* toplam;
	int toplam1;
	char* (*imeiVer)(struct IMEINO*);
    void(*imeiNoKontrol)(struct IMEINO*);
    void(*Yoket)(struct IMEINO*);
};

  typedef struct IMEINO* IMEINo;
  IMEINo imeinoOlustur();
  char* imei_Ver(IMEINo);
  void imeiNo_Kontrol(IMEINo);
  void IMEINoYoket(IMEINo);

#endif

