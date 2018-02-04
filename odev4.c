
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct Yapisi
typedef struct 
{
	unsigned long ogrNo;
	char ad[15];
	char soyad[15];
	unsigned vize;
	unsigned final;
	unsigned proje;
	unsigned short devam;
} ogrTip;

char * harfNotu(ogrTip ogr); //Harf Notlari (function)
int harfsayi[11]={0};       //Harf Notlari  (array)
float ortalama(ogrTip ogr); // Ogrenci Ortalamasi 

main()
{
	FILE *dd; //CENG101_IN.TXT (r) mod
	FILE *fp; //CENG101_OUT.TXT (w) mod 
	FILE *fr; //CENG101_OUT.TXT (r) mod
	fp=fopen("c://CENG101_OUT.txt","w");
	dd=fopen("c://CENG101_IN.txt","r");
	
	int N; //Ogrenci sayisi 
	float toplam=0; // Notlar toplami
	float ort=0; // Genel Ortalama
	ogrTip ogrenci[BUFSIZ]; // ogrTip Tipinde Ogrenci Degiskeni 
	
	// Ogrenci Sayisi 
	int i=0;
	while(!feof(dd))
	{
		fscanf(dd,"%d %s %s %d %d %d %d",&ogrenci[i].ogrNo,ogrenci[i].ad,ogrenci[i].soyad,&ogrenci[i].vize,&ogrenci[i].final,&ogrenci[i].proje,&ogrenci[i].devam);
		i++;
	}
	N=i; //Ogrenci Sayisi N'ye atandi
	
	fprintf(fp,"OGRENCI#\tAD\tSOYAD\tVIZE\tFINAL\tPROJE\tB.NOTU\tHARF");
	fprintf(fp,"\n======================================================================\n");
	
	//CENG101_IN.TXT'Den Veri Okuyup CENG101_OUT.TXT'E Aktarma && Notlar Toplami
	for(int i=0; i<N; i++)
	{
		fscanf(dd,"%d %s %s %d %d %d %d",&ogrenci[i].ogrNo,&ogrenci[i].ad,&ogrenci[i].soyad,&ogrenci[i].vize,&ogrenci[i].final,&ogrenci[i].proje,&ogrenci[i].devam);	
		fprintf(fp,"%d\t%s\t%s\t%d\t%d\t%d\t%3.0f\t%s\n",ogrenci[i].ogrNo,ogrenci[i].ad,ogrenci[i].soyad,ogrenci[i].vize,ogrenci[i].final,ogrenci[i].proje,ortalama(ogrenci[i]),harfNotu(ogrenci[i]));
		toplam+=ortalama(ogrenci[i]);	
	}
	fclose(dd);
	
	ort=toplam/N;
	fprintf(fp,"\nOgrenci Sayisi: %d", N);
	fprintf(fp,"\nBasari Notlari Ortalamasi: %3.2f",ort);

	//Standart Sapma Hesabi 
	float top=0; // Standart Sapma Icin Toplama 
	float sapma=0; 
	for(int i=0; i<N; i++)
		top=top+pow(ortalama(ogrenci[i])-ort, 2);
	sapma=sqrt(top/(N-1));
	fprintf(fp,"\nBasari Notlari Standart Sapmasi: %3.2f", sapma);
	
	fprintf(fp,"\nHarf Notlari Dagilimlari: \n");
	char harfler[11] = {'A','A','B','B','C','C','D','D','E','F','F'};
	for(int i = 0; i<11;i++)
		fprintf(fp,"%c%d :\t%d\n",harfler[i],i%2+1,harfsayi[i]);

	fclose(fp);
	fr=fopen("c://CENG101_OUT.txt","r");
	// dosyayi okuyup ekrana yazdirmak icin 
	int c;
	if(fr==NULL)
		printf("Dosya Bulunamadi...");
	else
	{
		do
		{
			c=getc(fr);
			putchar(c);
		}
		while(c != EOF);
	}
	fclose(fr);
	getche(); 	
}

float ortalama(ogrTip ogr) 
{	
	return ogr.vize*0.3+ogr.final*0.4+ogr.proje*0.3;
}

char * harfNotu(ogrTip ogr)
{
	char harfN[2];
	if(ogr.devam == 0)
	{
		strcpy(harfN, "F2");
		harfsayi[10] ++;	
	}
	else if(ortalama(ogr)>89)
	{
		strcpy(harfN, "A1");
		harfsayi[0] ++;	
	}
	else if(ortalama(ogr)<=89 && ortalama(ogr)>79)
	{
		strcpy(harfN, "A2");	
		harfsayi[1] ++;
	}
	else if(ortalama(ogr)<=79 && ortalama(ogr)>74)
	{
		strcpy(harfN, "B1");	
		harfsayi[2] ++;
	}
	else if(ortalama(ogr)<=74 && ortalama(ogr)>69)
	{
		strcpy(harfN, "B2");	
		harfsayi[3] ++;
	}
	else if(ortalama(ogr)<=69 && ortalama(ogr)>64)
	{
		strcpy(harfN, "C1");	
		harfsayi[4] ++;
	}
	else if(ortalama(ogr)<=64 && ortalama(ogr)>59)
	{
		strcpy(harfN, "C2");	
		harfsayi[5] ++;
	}
	else if(ortalama(ogr)<=59 && ortalama(ogr)>54)
	{
		strcpy(harfN, "D1");	
		harfsayi[6] ++;
	}
	else if(ortalama(ogr)<=54 && ortalama(ogr)>49)
	{
		strcpy(harfN, "D2");	
		harfsayi[7] ++;
	}
	else if(ortalama(ogr)<=49 && ortalama(ogr)>39)
	{
		strcpy(harfN, "E");	
		harfsayi[8] ++;
	}
	else if(ortalama(ogr)<=39 && ortalama(ogr)>=0)
	{
		strcpy(harfN, "F1");
		harfsayi[9] ++;	
	}
	return harfN;
}

