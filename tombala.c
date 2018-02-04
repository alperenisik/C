
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
void play();	//oyun baþlar kurallarý kontrol eder...
void cont(int rule) // oyuncu oyuna devam etmek istiyor mu ?
{
	if(rule != 0)
		printf("Tebrikler Kazandiniz %d. Kural Saglandi \n",rule);
	else
		printf("Malesef Kaybettiniz...! \n");
	printf("Devam etmek istiyormusunuz?(e/E)");
	char cevap = getch();
	if(cevap == 'e' || cevap == 'E')
		play();
	else
		exit(0);
		
}

int * sort(int sayi[])	// en büyük ve en küçük elemaný bulur.
{
	int sira[2]={*(sayi+0),*(sayi+0)};
	if(sira[0]<*(sayi+1))
		sira[0]=*(sayi+1);
	if(sira[0]<*(sayi+2))
		sira[0]=*(sayi+2);
	if(sira[1]>*(sayi+1))
		sira[1]=*(sayi+1);
	if(sira[1]>*(sayi+2))
		sira[1]=*(sayi+2);
	return sira;
}

void rule1 (int *sayi)		//1. kazanma kuralý (çekilen pullarýn toplamý < 150 )
{
	if(*(sayi+0)+*(sayi+1)+*(sayi+2)<150)
		cont(1);
}

void rule2(int *sayi)		//2. kazanma kuralý (çekilen pullarýn toplamý asal olursa)
{
	int i,flag=1,sum = *(sayi+0)+*(sayi+1)+*(sayi+2);
	for(i=2;i<sum;i++)
		if(sum%i == 0)
			flag=0;
	if(flag == 1)
		cont(2);	
}

void rule3(int *sayi)		//3. kazanma kuralý (çekilen pullardan büyük olan ile küçük olanýn farký ortancadan büyük olursa)
{
	int *sira = sort(sayi),sum = *(sayi+0)+*(sayi+1)+*(sayi+2);
	if (*(sira+0)-*(sira+1)>sum - *(sira+0) - *(sira+1))
		cont(3);
}

int * random()		// random deðerler üretilir
{
	int sayi[3],i;
	
	for(i=0;i<3;i++)
		sayi[i]=1+rand()%99;
	printf("\nPul 1 : %d\nPul 2 : %d\nPul 3 : %d\n", sayi[0], sayi[1], sayi[2]);

	return sayi;
}

int main ()		// oyuna baþlama koþulu
{
	printf("Oyuna baslamak icin e/E'ye basiniz\n");
	char cevap = getch();
	if(cevap == 'e' || cevap == 'E')
		play();	
	return 0;
}

void play() // I want to play game :)
{
	int *sayi = random();
	rule1(sayi);
	rule2(sayi);
	rule3(sayi);
	cont(0);
}
///////////////     //		//		//////////				//////////		//		  	//		///////
	  //			//		//		//						//				////		//		//	   //
	  //			//		//		//						//				//	//	  	//		//		//
	  //			//////////		//////					//////			//	  //	//		//		 //
	  //			//		//		//						//				//		//  //		//		//
	  //			//		//		//						//				//		  ////		//	   //
	  //			//		//		//////////				//////////		//			//		///////
	  
