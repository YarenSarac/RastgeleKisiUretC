#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "stdio.h"
#include "stdlib.h"
#include"Rastgele.h"
#include<string.h>

struct KIMLIKNO{
	
    Rastgele rast;
	int KimlikNo1[11];	
	char* toplam;
//	char*belirtec;
    void (*KontrolTc)(struct KIMLIKNO*);
	char* (*KimlikNoAl)(struct KIMLIKNO*);
	void(*Yoket)(struct KIMLIKNO*);
};

  typedef struct KIMLIKNO* KimlikNo;
  KimlikNo KimlikNoOlustur();
  char* KimlikNo_Al(KimlikNo);
  void Kontrol_Tc(KimlikNo);
  void KimlikNoYoket(KimlikNo);

#endif
