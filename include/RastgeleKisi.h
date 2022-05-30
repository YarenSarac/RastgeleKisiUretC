#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include"Rastgele.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>


struct RASTGELEKISI{
	int i;
	//char line[100];
	//char *isimTut[100];
	char* (*secKisi)(struct RASTGELEKISI*);
    void(*Yoket)(struct RASTGELEKISI*);	
	
};
typedef struct RASTGELEKISI* RastgeleKisi;
RastgeleKisi RastgeleKisiOlustur();
char* sec_Kisi(RastgeleKisi);
void RastgeleKisiYoket(RastgeleKisi);
#endif

