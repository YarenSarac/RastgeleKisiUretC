#ifndef RASTGELE_H
#define RASTGELE_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include<sys/time.h>

struct RASTGELE{
int yenimilisaniye;
long long milisaniye;
int i;
float (*zamanFarki)(struct timeval,struct timeval );
int (*anlikZaman)(struct RASTGELE*,int);
void(*Yoket)(struct RASTGELE*);	
};

typedef struct RASTGELE* Rastgele;
Rastgele RastgeleOlustur();
int anlikZaman1(Rastgele,int);
float zamanFarki1(struct timeval,struct timeval);
void RastgeleYoket(Rastgele);

#endif

