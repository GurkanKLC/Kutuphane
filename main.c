#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
	int guncelle();
	void sirala();
	int listele();
	void listele2();
	void atamayap();
	void ekle();
	int sil();
	void kitapmenu();
	int arama();
	int aktarma();
	void menu();
HANDLE wHnd;
HANDLE rHnd;
 static int idk;
int main() {

    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle("Kutuphane Otomasyonu");
    SMALL_RECT windowSize = {0, 0, 500, 100};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    COORD bufferSize = {150, 100};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
   printf("\t\t\tMerhaba Ne Yapmak Istiyorsunuz \n");
  	printf("\t\t\t-------------------------------\n");
menu();
	return 0;
}
void menu(){
	int durum11;
	printf("\nKitap Listesi Gormek ve Islem yapmak icin   | 1 | \n");
	printf("--------------------------------------------------\n");
	 system("COLOR B");

	scanf("%d",&durum11);
	if(durum11==1){
	kitapmenu();
	}else if(durum11==2){
	}
}
int aktarma(int giris){
	if(giris==1){
		arama();
	}
}
void kitapmenu(){
	int durum6;
      system("CLS");
      system("COLOR F");
	   atamayap();
		listele2();
		printf("-------------------------------\n");
		printf("Kitap Eklemek icin        | 1 |\n");
		printf("-------------------------------\n");
		printf("Kitap Guncellemek icin    | 2 |\n");
		printf("-------------------------------\n");
		printf("Kitap Silmek icin         | 3 |\n");
		printf("-------------------------------\n");
		printf("Kitap Aramak icin         | 4 |\n");
		printf("-------------------------------\n");
		printf("Ana Menu icin             | 5 |\n\nTusuna basiniz\n");
		scanf("%d",&durum6);
		if(durum6==1){
			ekle();

		}else if(durum6==2){
		printf("Guncelenecek kitabi seciniz\n");
		arama(1);

		}else if(durum6==3){
		printf("Silinecek kitabi seciniz\n");
		arama(2);
		}else if(durum6==4){
			arama(3);
		}else if(durum6==5){
			menu();
		}
		else{
			menu();
		}
}
void listele2(){
	FILE *kitaplaric;
	int id,basim,sayfa,kitapsayi,kbs=0,yzbs=0,yybs=0,tbs=0;
	char kitapadi[256],yazar[256],yayin[256],tur[256];
    char* kelime[10];
    char* kelime2[10];
    char* kelime3[10];
    char* kelime4[10];
	kitaplaric=fopen("kitaplar.txt","r");
		while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("ID=|%d|Ad: ",id);
	char* isim;
	isim=strtok(kitapadi,"*");
	while(isim!=NULL){
		printf("%s  ",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL,"*");
		kbs++;
	}
	printf(" |Yazar: ");
	char* yzr;
	yzr=strtok(yazar,"*");
	while(yzr!=NULL){
		printf("%s ",yzr);
		kelime2[yzbs]=yzr;
		yzr=strtok(NULL,"*");
		yzbs++;
	}
		printf(" |Yayinevi: ");
		char* yyn;
	yyn=strtok(yayin,"*");
	while(yyn!=NULL){
		printf("%s  ",yyn);
		kelime3[yybs]=yyn;
		yyn=strtok(NULL,"*");
		yybs++;
	}
		printf(" |Tur: ");
	char* tr;
	tr=strtok(tur,"*");
	while(tr!=NULL){
		printf("%s ",tr);
		kelime4[tbs]=yyn;
		tr=strtok(NULL,"*");
		tbs++;
	}
		printf("|Sayfa %d |Basim: %d |Adet: %d | \n",sayfa,basim,kitapsayi);
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
				}
				printf("\n%d adet kitap bulunmaktadir\n",idk-1);
				printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("Kitap id no / Kitap adi / Yazar adi / Yayinevi / Sayfa sayisi / Basim yili / Adet\n");
         	printf("\nKitap bilgilerinin siralamasi yukaridaki gibidir..\n");
	fclose(kitaplaric);

}
int listele(int idk){
	FILE *kitaplaric;
	int id,basim,sayfa,kitapsayi,kbs=0,yzbs=0,yybs=0,tbs=0;
	char kitapadi[256],yazar[256],yayin[256],tur[256];
    char* kelime[10];
    char* kelime2[10];
    char* kelime3[10];
    char* kelime4[10];
	kitaplaric=fopen("kitaplar.txt","r");
		while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(idk==id){
	printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("ID=|%d|Ad: ",id);
	char* isim;
	isim=strtok(kitapadi,"*");
	while(isim!=NULL){
		printf("%s  ",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL,"*");
		kbs++;
	}
	printf(" |Yazar: ");
	char* yzr;
	yzr=strtok(yazar,"*");
	while(yzr!=NULL){
		printf("%s ",yzr);
		kelime2[yzbs]=yzr;
		yzr=strtok(NULL,"*");
		yzbs++;
	}
		printf(" |Yayinevi: ");
		char* yyn;
	yyn=strtok(yayin,"*");
	while(yyn!=NULL){
		printf("%s  ",yyn);
		kelime3[yybs]=yyn;
		yyn=strtok(NULL,"*");
		yybs++;
	}
		printf(" |Tur: ");
	char* tr;
	tr=strtok(tur,"*");
	while(tr!=NULL){
		printf("%s ",tr);
		kelime4[tbs]=yyn;
		tr=strtok(NULL,"*");
		tbs++;
	}
		printf("|Sayfa: %d |Basim: %d |Adet: %d \n",sayfa,basim,kitapsayi);
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
				}
			}
	fclose(kitaplaric);

}


void ekle(){
	FILE * kitaplaric;
	char* kelime[10];
    char* kelime2[10];
    char* kelime3[10];
    char* kelime4[10];
	int id=1,basim,sayfa,kitapsayi,kbs=0,yzbs=0,yybs=0,tbs=0;
	char kitapadi[256],yazar[256],yayin[256],tur[256];
	kitaplaric=fopen("kitaplar.txt","a+");
	printf("Kitap adini giriniz\n");
	gets(kitapadi);
	gets(kitapadi);
	printf("Kitap Yazarinin adini giriniz\n");
	gets(yazar);
	printf("Kitap Yayinevinin adini giriniz\n");
    gets(yayin);
	printf("Kitap Turunu giriniz\n");
	gets(tur);
	printf("Kitap Sayfa Sayisini giriniz\n");
	scanf("%d",&sayfa);
	printf("Kitap Basim Yilini giriniz\n");
	scanf("%d",&basim);
	printf("Kitap adetini giriniz\n");
	scanf("%d",&kitapsayi);
	fprintf(kitaplaric,"%d ",id);
		char* isim;
	isim=strtok(kitapadi," ");
	while(isim!=NULL){
		fprintf(kitaplaric,"%s*",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL," ");
		kbs++;
	}
	fprintf(kitaplaric," ");
	char* yzr;
	yzr=strtok(yazar," ");
	while(yzr!=NULL){
		fprintf(kitaplaric,"%s*",yzr);
		kelime2[yzbs]=yzr;
		yzr=strtok(NULL," ");
		yzbs++;
	}
		fprintf(kitaplaric," ");
		char* yyn;
	yyn=strtok(yayin," ");
	while(yyn!=NULL){
		fprintf(kitaplaric,"%s*",yyn);
		kelime3[yybs]=yyn;
		yyn=strtok(NULL," ");
		yybs++;
	}
		fprintf(kitaplaric," ");
	char* tr;
	tr=strtok(tur," ");
	while(tr!=NULL){
		fprintf(kitaplaric,"%s*",tr);
		kelime4[tbs]=yyn;
		tr=strtok(NULL," ");
		tbs++;
	}
		fprintf(kitaplaric," ");
	fprintf(kitaplaric,"%d %d %d \n",sayfa,basim,kitapsayi);
	fclose(kitaplaric);
	atamayap();
	kitapmenu();
}
int sil(int ida){
		FILE *kitaplaric;
	FILE *kitapkova;
	int idy=1,basim,sayfa,kitapsayi,id;
	char kitapadi[256],yazar[256],yayin[256],tur[256],kitapad[256];
	int kbs=0,yzbs=0,yybs=0,tbs=0,yenisayi=0,durum3;
    char* kelime[10];
    char* kelime2[10];
    char* kelime3[10];
    char* kelime4[10];
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id!=ida){
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
 	printf("%d no lu kitap silindi..\n",ida);
 	printf("Anamenu icin | 1 | e basiniz\n");
 	scanf("%c",&durum3);
 	if(durum3==1){
 		menu();
	 }else{
	 	printf("Hatali giris yaptiniz\nAktariliyorsunuz\n");
	 	kitapmenu();
	 }
}
int arama(int yon){
	   system("CLS");
      system("COLOR B");
		FILE * kitaplaric;
	int id,basim,sayfa,kitapsayi,kbs=0,yzbs=0,yybs=0,tbs=0,arama,gonder;
	kitaplaric=fopen("kitaplar.txt","a+");
	char kitapadi[256],yazar[256],yayin[256],tur[256];
   char* kelime[10];
   char* kelime2[10];
   char* kelime3[10];
   char* kelime4[10];
   char* kelime5[10];
   int kitapnolar[256];
	int durum6,adet=0;
	printf("Kitabi bulmak icin arama kriteri seciniz..\n\n");
	printf("Kitap adi icin     | 1 |\n");
	printf("------------------------\n");
	printf("Yazar adi icin     | 2 |\n");
	printf("------------------------\n");
	printf("Yayinevi icin      | 3 |\n");
	printf("------------------------\n");
	printf("Tur icin           | 4 |\n");
	printf("------------------------\n");
	printf("Sayfa sayisi icin  | 5 |\n");
	printf("------------------------\n");
	printf("Basim yili icin    | 6 |\n");
	printf("------------------------\n");
	printf("Kitap adeti icin   | 7 |\n\nGiriniz...\n");
	scanf("%d",&durum6);
	if(durum6==1){
		char aranan[256];
		printf("Kitap adini giriniz..\n");
	   scanf("%s",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	      char* isim;
	      isim=strtok(kitapadi,"*");
	      while(isim!=NULL){
		   kelime[kbs]=isim;
		   isim=strtok(NULL,"*");
			if(strcmp(aranan,kelime[kbs]) == 0){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);
		}
			kbs++;
	}
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
		}


}
else	if(durum6==2){
		char aranan[256];
		printf("Yazar adini giriniz..\n");
		scanf("%s",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	      char* isim;
	      isim=strtok(yazar,"*");
	      while(isim!=NULL){
		   kelime[kbs]=isim;
		   isim=strtok(NULL,"*");
			if(strcmp(aranan,kelime[kbs]) == 0){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);
		}
			kbs++;
	}
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
		}
		  printf("%d tane sonuc bulundu\n",adet);
}
else	if(durum6==3){
		char aranan[256];
		printf("Yayin adini giriniz..\n");
		scanf("%s",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	      char* isim;
	      isim=strtok(yayin,"*");
	      while(isim!=NULL){
		   kelime[kbs]=isim;
		   isim=strtok(NULL,"*");
			if(strcmp(aranan,kelime[kbs]) == 0){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);
		}
			kbs++;
	}
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
		}
		  printf("%d tane sonuc bulundu\n",adet);
}
else	if(durum6==4){
		char aranan[256];
		printf("Tur adini giriniz..\n");
		scanf("%s",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	      char* isim;
	      isim=strtok(tur,"*");
	      while(isim!=NULL){
		   kelime[kbs]=isim;
		   isim=strtok(NULL,"*");
			if(strcmp(aranan,kelime[kbs]) == 0){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);
		}
			kbs++;
	}
	kbs=0;
	yzbs=0;
	yybs=0;
	tbs=0;
		}
		  printf("%d tane sonuc bulundu\n",adet);
}
else	if(durum6==5){
		int aranan;
		printf("Sayfa sayisini giriniz..\n");
		scanf("%d",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
			if(aranan==sayfa){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);

	}
		}
		  printf("%d tane sonuc bulundu\n",adet);
}
else	if(durum6==6){

		int aranan;
		printf("Basim yilini giriniz..\n");
		scanf("%d",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
			if(aranan==basim){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);

	}
		}
		  printf("%d tane sonuc bulundu\n",adet);

}else if(durum6==7){
	int aranan;
		printf("Kitap adetini giriniz..\n");
		scanf("%d",&aranan);
			while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d\n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
			if(aranan==kitapsayi){
			adet++;
			kitapnolar[adet]=id;
			listele(kitapnolar[adet]);

	}
		}
		  printf("%d tane sonuc bulundu\n",adet);
}else{
	printf("Hatali deger girdiniz\n");
	kitapmenu();
}


if(yon==1){
			printf("Guncellemek istediginiz kitabin id numarasini giriniz\n");
			scanf("%d",&gonder);
			int i;
			for(i=1;i<=idk;i++){
				if(kitapnolar[i]==gonder){
						guncelle(gonder);
				}
			}
		printf("Bulunan degerler disinda deger girdiniz\n");
		printf("---------------------------------------\n");
		printf("Ana Menu icin             | M |\n\nHarfine basiniz\n");
		char durum4;
		scanf("%c",&durum4);
				scanf("%c",&durum4);

		if(durum4=='M'){
			kitapmenu();
		}
}
else if(yon==2){
		printf("Uyari!\nKitap silme islemi geri alinamaz ve tum kitap adetlerini siler\nKitap adetinde degisiklik icin Guncelle bolumune gidiniz\n");
		printf("Silmek istediginiz kitabin id numarasini giriniz\n");
			scanf("%d",&gonder);

				int i;
			for(i=1;i<=idk;i++){
				if(kitapnolar[i]==gonder){
							sil(gonder);
				}
			}
		printf("Bulunan degerler disinda deger girdiniz\n");
		printf("---------------------------------------\n");
		printf("Ana Menu icin             | M |\n\nHarfine basiniz\n");
		char durum5;
		scanf("%c",&durum5);
				scanf("%c",&durum5);

		if(durum5=='M'){
			kitapmenu();
		}
}
else if(yon==3){
	int durum9;
	   printf("Kitap secimi icin id no giriniz\n");
	    scanf("%d",&gonder);
	   printf("-------------------------------\n");
		printf("Bu kitap hangi islemi gerceklestireceksiniz?\n");
		printf("--------------------------------------------\n");
		printf("Kitap Guncellemek icin    | 1 |\n");
		printf("-------------------------------\n");
		printf("Kitap Silmek icin         | 2 |\n");
		printf("-------------------------------\n");
		printf("Yeni Arama icin           | 3 |\n");
		printf("-------------------------------\n");
		printf("Menu icin                 | 4 |\n");
		printf("-------------------------------\n");
		scanf("%d",&durum9);
		if(durum9==1){
			int i;
			for(i=1;i<=idk;i++){
				if(kitapnolar[i]==gonder){
						guncelle(gonder);
				}
			}
		printf("Bulunan degerler disinda deger girdiniz\n");
		printf("---------------------------------------\n");
		printf("Ana Menu icin             | M |\n\nHarfine basiniz\n");
		char durum4;
		scanf("%c",&durum4);
				scanf("%c",&durum4);

		if(durum4=='M'){
			kitapmenu();
		}
		}else if(durum9==2){
			printf("Uyari!\nKitap silme islemi geri alinamaz ve tum kitap adetlerini siler\nKitap adetinde degisiklik icin Guncelle bolumune gidiniz\n");

				int i;
			for(i=1;i<=idk;i++){
				if(kitapnolar[i]==gonder){
							sil(gonder);
				}
			}
		printf("Bulunan degerler disinda deger girdiniz\n");
		printf("---------------------------------------\n");
		printf("Ana Menu icin             | M |\n\nHarfine basiniz\n");
		char durum5;
		scanf("%c",&durum5);
				scanf("%c",&durum5);

		if(durum5=='M'){
			kitapmenu();
		}
		else{
			menu();
		}
		}else if(durum9==3) {
		kitapmenu();
		}
}
fclose(kitaplaric);
}

int guncelle(int ida){
	FILE *kitaplaric;
	FILE *kitapkova;
	int idy=1,basim,sayfa,id,kitapsayi;
	char kitapadi[256],yazar[256],yayin[256],tur[256],kitapad[256];
	int kbs=0,yzbs=0,yybs=0,tbs=0,yenisayi=0,durum7;
    char* kelime[10];
    char* kelime2[10];
    char* kelime3[10];
    char* kelime4[10];
   printf("Degistirmek istediginiz bolumu seciniz..\n\n");
	printf("Kitap adi icin     | 1 |\n");
	  printf("------------------------\n");
   printf("Yazar adi icin     | 2 |\n");
     printf("------------------------\n");
   printf("Yayinevi  icin     | 3 |\n");
     printf("------------------------\n");
   printf("Tur icin           | 4 |\n");
     printf("------------------------\n");
   printf("Sayfa sayisi icin  | 5 |\n");
     printf("------------------------\n");
   printf("Basim yili icin    | 6 |\n");
     printf("------------------------\n");
   printf("Kitap adeti icin   | 7 |\n");
	scanf("%d",&durum7);
if(durum7==1){
	printf("%d no lu kitap'in adi degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni kitap adini giriniz\n");
	   gets(kitapad);
	    gets(kitapad);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d ",id);
		char* isim;
	   isim=strtok(kitapad," ");
   	while(isim!=NULL){
		fprintf(kitapkova,"%s*",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL," ");
		kbs++;
	}
		fprintf(kitapkova," %s %s %s %d %d %d \n",yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==2){
	printf("%d no lu kitap'in yazari degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni yazar adini giriniz\n");
	   gets(kitapad);
	    gets(kitapad);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s ",id,kitapadi);
		char* isim;
	   isim=strtok(kitapad," ");
   	while(isim!=NULL){
		fprintf(kitapkova,"%s*",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL," ");
		kbs++;
	}
		fprintf(kitapkova," %s %s %d %d %d \n",yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==3){
	printf("%d no lu kitap'in yayinevi degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni yayinevi adini giriniz\n");
	   gets(kitapad);
	    gets(kitapad);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s %s ",id,kitapadi,yazar);
		char* isim;
	   isim=strtok(kitapad," ");
   	while(isim!=NULL){
		fprintf(kitapkova,"%s*",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL," ");
		kbs++;
	}
		fprintf(kitapkova," %s %d %d %d \n",tur,sayfa,basim,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==4){
	printf("%d no lu kitap'in turu degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni kitap turu adini giriniz\n");
	   gets(kitapad);
	    gets(kitapad);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s %s %s ",id,kitapadi,yazar,yayin);
		char* isim;
	   isim=strtok(kitapad," ");
   	while(isim!=NULL){
		fprintf(kitapkova,"%s*",isim);
		kelime[kbs]=isim;
		isim=strtok(NULL," ");
		kbs++;
	}
		fprintf(kitapkova," %d %d %d \n",sayfa,basim,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==5){
	printf("%d no lu kitap'in sayfa sayisi degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni sayfa sayisini giriniz\n");
	 scanf("%d",&yenisayi);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,yenisayi,basim,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==6){
	printf("%d no lu kitap'in basim yili degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni basim yilini giriniz\n");
	 scanf("%d",&yenisayi);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,yenisayi,kitapsayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	if(durum7==7){
	printf("%d no lu kitap'in adeti degistiriliecek\n",ida);
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");

		printf("Yeni adet giriniz\n");
	 scanf("%d",&yenisayi);
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
	if(id==ida){
	printf("%d %d",id,ida);
   	fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,yenisayi);
			idy++;
				}
				else{
			fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
			}
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
	kitapmenu();
}
void atamayap(){
	FILE *kitaplaric;
	FILE *kitapkova;
	int idy=1,basim,sayfa,id,kitapsayi;
	char kitapadi[256],yazar[256],yayin[256],tur[256];
	kitaplaric=fopen("kitaplar.txt","r");
	kitapkova=fopen("kitapkova.txt","w+");
	while(fscanf(kitaplaric,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitapkova,"%d %s %s %s %s %d %d %d \n",idy,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
			idy++;
				}
				idk=idy;
				fclose(kitapkova);
				fclose(kitaplaric);
				kitaplaric=fopen("kitaplar.txt","w");
                kitapkova=fopen("kitapkova.txt","r");
		while(fscanf(kitapkova,"%d %s %s %s %s %d %d %d \n",&id,&kitapadi,&yazar,&yayin,&tur,&sayfa,&basim,&kitapsayi) !=EOF){
		fprintf(kitaplaric,"%d %s %s %s %s %d %d %d \n",id,kitapadi,yazar,yayin,tur,sayfa,basim,kitapsayi);
				}
	fclose(kitaplaric);
	fclose(kitapkova);
}
