/**  *  * @author YAREN SARAÇ-MERVE KARDEÞ yaren.sarac@ogr.sakarya.edu.tr-merve.kardes@ogr.sakarya.edu.tr * @since 24.04.2020  *  Test sýnýfýmýzý oluþturduk.  */ 

#include"Rastgele.h"
#include"RastgeleKisi.h"
#include"Telefon.h"
#include "IMEINo.h"
#include"KimlikNo.h"
#include"Kisi.h"

int main(){

	int secim;
		
	while(secim!=3)
	{
		printf("1- Rastgele Kisi Uret\n");
    	printf("2- Uretilmis Dosya Kontrol Et\n");
        printf("3- Cikis\n");
        printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMI SECIN\n");
        
		scanf("%d",&secim);
		
		if(secim==1)
		{
			int sayi;
			printf("Kac Kisi Olusturmak Istiyorsunuz Lutfen Giriniz\n");
			scanf("%d",&sayi);
			Kisi kisi1= KisiOlustur();
	 		kisi1->KisiVer(kisi1,sayi);	
	 		printf("\n");
		}
		
		else if(secim==2)
		{
				 
			KimlikNo kimlik1=KimlikNoOlustur();
			kimlik1->KontrolTc(kimlik1);
			IMEINo imei1=imeinoOlustur();
 		    imei1->imeiNoKontrol(imei1);
			
		}
		
		else
		{
			printf("Cikis yapiliyor.\n");
			break;
		}
	}		
	}
	


   





      



