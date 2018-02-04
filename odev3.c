
#include <stdio.h>
void giris(int no[], int notu[], int N);      // OGRENCİNİN NUMARASI VE NOTU GİRİLİR
float ortalama(int notu[], int N);            // GENEL ORTALAMA
float ortalama2(int notu[], int N);          // 20 USTU NOTLARIN ORTALAMASI
void goruntule(int no[], int notu[], int N); // OGRENCI NO VE NOTLARINI GORUNTULE
void otele(int no[], int notu[], int N, double fark); // 20 USTU NOTLARIN ORTALAMASI 50 DEN DÜŞÜKSE 50 YE TAMAMLAYANA KADAR 30 ÜSTÜ NOTLARA EKLE
void bubblesort(int no[],int notu[],int N);     // NOTA VE NUMARAYA GORE SIRALAMA
void histogram1(int notu[], int N, int puan[]); // DİKEY HİSTOGRAM
void harfNot(int notu[], int N, int puan[]);    // NOTLARI HARFE GORE SIRALAMAK ICIN DIZI
void histogram2(int notu[], int N, int puan[]); // YATAY HİSTOGRAM

main()

  {
  int puan[10];
  for (int p = 0; p <10; p++) {
    puan[p]=0;
  }

  double fabs(double fark);
	int N;
	int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	float ort;
  float ort2;
	printf("Ogrenci sayisini giriniz: ");
	scanf("%d", &N);
		giris(OgrNo, BNotu, N);
		goruntule(OgrNo, BNotu, N);
		ort = ortalama(BNotu, N);
    ort2 = ortalama2(BNotu, N);
    double fark=50-ort2;
    fark>=0;
    otele(OgrNo, BNotu, N, fark);
		printf("\n Tum ogrencilerin not ortalamasi: %5.2f\n", ort);
    printf(" 20'den yüksek alan ogrencilerin not ortalamasi: %5.2f\n", ort2);
    if(ort2<50)
    {
    fark=50-ort2;
    printf(" Otelenen Not Miktarı %5.2f\n",fark);
    ort=ortalama(BNotu, N);
    printf(" Otelenmis ortalama: %5.2f\n",ort);
    }
    else
    printf(" Notlar otelenmedi...\n");

    bubblesort(OgrNo, BNotu, N);
    harfNot(BNotu, N, puan);
    histogram1(BNotu, N, puan);
    histogram2(BNotu, N, puan);
  }


	void giris(int no[], int notu[], int N)
  {
	int i;
	for (i=0; i<N; i++)
  {
	printf("Ogrenci no gir: ");
	scanf("%d", &no[i]);
	printf("%d numarali ogrencinin basari notunu gir : ", no[i]);
	scanf("%d", &notu[i]);
  }
  }

	void goruntule(int no[], int notu[], int N)
  {
	printf("\n Ogrenci#\tNotu\n");
	for (int i=0; i<N; i++)
	printf("%8d\t%3d\n", no[i], notu[i]);
  }

	float ortalama(int notu[], int N)
  {
	float t;
	int i;
	t = 0;
	for (i=0; i<N; i++)
	t = t + notu[i];
	float ort = t / N;
	return ort;
  }

  float ortalama2(int notu[], int N)
  {
    float q;
    int r=0;
    q=0;
    for (int i=0; i<N; i++)
    {
      if(notu[i]>=20)
      {
      r+=1;
      q+=notu[i];
      float yeniort = q / r;
      }
      else
      continue;
    }
  }

  void otele(int no[], int notu[], int N, double fark)
  {
    fark>=0;
    for (int i=0; i<N; i++)
    {
      if (notu[i]>=30)
      {
        if(fark>=0)
        notu[i]+=fark;
        else
        continue;
      }
      else
      continue;
    }
   printf("\n Ogrenci#\tNotu\n");
  	for (int i=0; i<N; i++)
  	printf("%8d\t%3d\n", no[i], notu[i]);
  }

  void bubblesort(int no[], int notu[], int N)
  {
    int temp;
    int temp2;
    int temp3;
    int temp4;
    printf("\n OGRENCI NOTUNA GORE SIRALAMA\n");
    printf("\n Ogrenci Notu    Ogrenci Numarasi \n");
    for (int i = 0; i < N-1; i++)
    {
      for (int j = 0; j < N-i-1; j++)
      {
        if(notu[j]>notu[j+1])
        {
          temp=notu[j];
          notu[j]=notu[j+1];
          notu[j+1]=temp;
          temp2=no[j];
          no[j]=no[j+1];
          no[j+1]=temp2;
        }
      }
    }
    for (int i=0; i < N; i++)
        printf("\t%d\t\t%d\n",notu[i],no[i]);

        printf("\n\n OGRENCI NUMARASINA GORE SIRALAMA\n");
        printf("\n Ogrenci Numarasi Ogrenci Notu\n");
    for (int i = 0; i < N-1; i++)
    {
      for (int j = 0; j < N-i-1; j++)
      {
        if(no[j]>no[j+1])
        {
          temp3=no[j];
          no[j]=no[j+1];
          no[j+1]=temp3;
          temp4=notu[j];
          notu[j]=notu[j+1];
          notu[j+1]=temp4;
        }
      }
    }
    for (int i=0; i < N; i++)
        printf("\t%d\t\t%d\n",no[i],notu[i]);
  }

  void harfNot(int notu[], int N, int puan[])
  {
    for( int i =0; i<N; i++)
    {
      if (notu[i]<40)
        puan[9]++;
     if (notu[i]<50 && notu[i]>=40)
        puan[8]++;
     if (notu[i]<55 && notu[i]>=50)
        puan[7]++;
     if (notu[i]<60 && notu[i]>=55)
        puan[6]++;
     if (notu[i]<65 && notu[i]>=60)
        puan[5]++;
     if (notu[i]<70 && notu[i]>=65)
        puan[4]++;
     if (notu[i]<75 && notu[i]>=70)
        puan[3]++;
     if (notu[i]<80 && notu[i]>=75)
        puan[2]++;
     if (notu[i]<90 && notu[i]>=80)
        puan[1]++;
     if (notu[i]<100 && notu[i]>=90)
        puan[0]++;
  }
}

  void histogram1(int notu[], int N, int puan[])
  {
    int maks=puan[0];
      for(int i=0; i<10; i++)
        if(maks<puan[i])
          maks=puan[i];

    int x=maks;
    for (x; x>=1; x--)
    {
      printf("%2d",x);
      for (int w = 0; w <10; w++)
      {
        if(puan[w]>=x)
        printf("| * ");
        else
        printf("|   ");
      }
      printf("|\n");
    }
    printf("\n");
    printf("---------------------------------------------");
    printf("\n  | A1| A2| B1| B2| C1| C2| D1| D2| E | F1| \n");
  }

  void histogram2(int notu[], int N, int puan[])
  {
    int maks=puan[0];
    int min=puan[9];
      for(int i=0; i<10; i++)
        if(maks<puan[i])
          maks=puan[i];
      int x=maks;
      for (int i = 0; i <10; i++)
      if(min>puan[i])
      min=puan[i];
      int y=min;


      printf("\nA1|");
      for(int i=1 ; i<= puan[0]; i++)
      {
      printf("*  ");
      }
      printf("\nA2|");
      for(int i=1 ; i<= puan[1]; i++)
      {
      printf("*  ");
      }
      printf("\nB1|");
      for(int i=1 ; i<= puan[2]; i++)
      {
      printf("*  ");
      }
      printf("\nB2|");
      for(int i=1 ; i<= puan[3]; i++)
      {
      printf("*  ");
      }
      printf("\nC1|");
      for(int i=1 ; i<= puan[4]; i++)
      {
      printf("*  ");
      }
      printf("\nC2|");
      for(int i=1 ; i<= puan[5]; i++)
      {
      printf("*  ");
      }
      printf("\nD1|");
      for(int i=1 ; i<= puan[6]; i++)
      {
      printf("*  ");
      }
      printf("\nD2|");
      for(int i=1 ; i<= puan[7]; i++)
      {
      printf("*  ");
      }
      printf("\nE |");
      for(int i=1 ; i<= puan[8]; i++)
      {
      printf("*  ");
      }
      printf("\nF1|");
      for(int i=1 ; i<= puan[9]; i++)
      {
      printf("*  ");
      }
      printf("\n");
      printf("--+-");
      for (int n=0;n<x;n++)
     printf("---");
      printf("\n  ");
      for (int n=0;n<x;n++)
        printf("%3d",n+1);
        printf("\n");
  } // THE END
///////////////     //		//		//////////				//////////		//		  	//		///////
	  //			//		//		//						//				////		//		//	   //
	  //			//		//		//						//				//	//	  	//		//		//
	  //			//////////		//////					//////			//	  //	//		//		 //
	  //			//		//		//						//				//		//  //		//		//
	  //			//		//		//						//				//		  ////		//	   //
	  //			//		//		//////////				//////////		//			//		///////
