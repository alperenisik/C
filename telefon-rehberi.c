/// MENU EKRANI TXT İLE BASILMIŞTIR ///////////////////////////////////////////
// ALTERNATİF MENU , MENU FONKSİYONUNUN ALTINDA YORUM SATIRINA ALINMIŞTIR /////
#include <stdio.h>
#include <conio.h>
#include <string.h> // fflush
#include <stdlib.h> // strcmp
///////////////////////////////////////////////////////////////////////////////
struct kisi
{
	char ad[15];
	char soyad[15];
	char eposta[15];
	char mahalle[15];
	char ilce[15];
	char il[15];
	char sokak[15];
	char evtelefonu[15];
	char ceptelefonu[15];
	char istelefonu[15];
  char dogumtarihi[15];
}kayit[BUFSIZ];
///////////////////////////////////////////////////////////////////////////////
FILE *fp;
int N;
void menu();
void ekle();
void goruntule();
void degistir();
void sil();
void arama();
///////////////////////////////////////////////////////////////////////////////
main()
{
	int secim,flag=0;

	while(flag==0)
	{
		system("clear");
		menu();
		scanf("%d",&secim);

		switch (secim)
		{
			case 1:
			  ekle();
			  break;
			case 2:
			  goruntule();
			  getch();
			  break;
			case 3:
	   		arama();
				getch();
  			break;
			case 4:
			  degistir();
			  break;
			case 5:
			  sil();
			  break;
			case 0:
			  flag = 1;
			  break;
			default:
			printf("HATALI SEÇİM...");
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void menu()
{
	/*
	////////////////////////	 MENU.TXT DOSYA İÇERİĞİ  //////////////////////////

								.-/|  78   ~~**~~      \ /      ~~**~~   79  |\-.
								||||                    :                    ||||
								||||                    :                    ||||
								|||| +-+-+-+-+-+-+-+    :                    ||||
								|||| |T|e|l|e|f|o|n|    : 1 => EKLE          ||||
								|||| +-+-+-+-+-+-+-+    :                    ||||
								|||| |R|e|h|b|e|r|i|n|e|: 2 => GÖRÜNTÜLE     ||||
								|||| +-+-+-+-+-+-+-+-+-+:                    ||||
								|||| |H|o|s|g|e|l|d|i|n|: 3 => ARA           ||||
								|||| +-+-+-+-+-+-+-+-+-+:                    ||||
								||||                    : 4 => GÜNCELLE      ||||
								||||                    :                    ||||
								||||                    : 5 => SİL           ||||
								||||                    :                    ||||
								||||                    : 0 => ÇIKIŞ         ||||
								||||                    :                    ||||
								||||                    :                    ||||
								||||___________________ : ___________________||||
								||/====================\:/====================\||
								`---------------------~___~--------------------''
	*/
	FILE *m;
	int c;

	m=fopen("menu.txt","r");

	if(m==NULL)
	printf("Dosya Bulunamadı...");
	else
	{
			do
			{
				c=getc(m);
				putchar(c);
			}
			while(c != EOF);
	}
		fclose(m);

	/*   ALTERNATİF MENÜ
	printf("\n\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260");
	printf("\n\260\260                      //\\\\               \260");
	printf("\n\260\260 1-Ekle              //  \\\\              \260");
	printf("\n\260\260                    //    \\\\             \260");
	printf("\n\260\260 2-Goruntule       //      \\\\	           \260");
	printf("\n\260\260                  //TELEFON \\\\	   \260");
	printf("\n\260\260 3-Ara           //REHBERİNE \\\\          \260");
	printf("\n\260\260                //            \\\\	   \260");
	printf("\n\260\260 4-Guncelle    //              \\\\        \260");
	printf("\n\260\260              //                \\\\       \260");
	printf("\n\260\260 5-Sil       //   HOSGELDİNİZ    \\\\	   \260");
	printf("\n\260\260            //                    \\\\     \260");
	printf("\n\260\260 0-Cikis     -----------------------     \260");
	printf("\n\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260");
	printf("\n\n");
	printf("Lutfen bir secenek giriniz..\n\n");
 */

}
///////////////////////////////////////////////////////////////////////////////
void ekle()
{
	struct kisi kayit[BUFSIZ];

	printf("\nKisinin Adi\n");
	scanf("%s", kayit[N].ad);
	printf("\nKisinin Soyadi\n");
	scanf("%s", kayit[N].soyad);
	printf("\nKisinin e-posta adresi\n");
	scanf("%s", kayit[N].eposta);
	printf("\nKisinin Oturduğu İl\n");
	scanf("%s", kayit[N].il);
	printf("\nKisinin Oturduğu İlce\n");
	scanf("%s", kayit[N].ilce);
	printf("\nKisinin Oturduğu Mahalle\n");
	scanf("%s", kayit[N].mahalle);
	printf("\nKisinin Oturduğu Sokak Numarasi\n");
	scanf("%s", kayit[N].sokak);
	printf("\nKisinin Ev Telefonu\n");
	scanf("%s", kayit[N].evtelefonu);
	printf("\nKisinin Cep Telefonu\n");
	scanf("%s", kayit[N].ceptelefonu);
	printf("\nKisinin Is Telefonu\n");
	scanf("%s", kayit[N].istelefonu);
	printf("\nKisinin Doğum Günü\n");
	scanf("%s", kayit[N].dogumtarihi);
	N++;

		fp=fopen("rehber.txt","a");

		if(fp==NULL)
		printf("Dosya Bulunamadı...\n");
		else
		{
			for(int i=0;i<N;i++)
			{
				fprintf(fp,"\n%s\t %s\t %s\t %s\t %s\t %s\t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
				fprintf(fp,"\t%s\t %s\t %s\t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
			}
		}
	  fclose(fp);
}
////////////////////////////////////////////////////////////////////////////////
void goruntule()
{
	fp=fopen("rehber.txt","r");
	int c;

	if(fp==NULL)
	printf("Dosya Bulunamadi...");
	else
	{
			do
			{
				c=getc(fp);
				putchar(c);
			}
			while(c != EOF);
	}
		fclose(fp);
		getche();
}
///////////////////////////////////////////////////////////////////////////////
void arama()
{
	char kelime[15];
	int a=0,secim;

	fp=fopen("rehber.txt","r");

	if(fp==NULL)
	printf("Dosya Bulunamadı...");
	else
	{
				system("clear");
				printf("\n");
				printf("\n   Ada Göre Arama Yapmak İçin 1'i \n");
				printf("\n   Soyada Göre Aramak İçin 2'yi \n");
				printf("\n   Doğum Tarihine Göre Aramak İçin Lütfen 3'ü Tuşlayınız \n");
				scanf("%d",&secim);

				printf("Aranacak Veriyi Giriniz: ");
				scanf("%s",kelime);

			rewind(fp);
			while(!feof(fp))
			{
				fscanf(fp,"%s%s%s%s%s%s%s",kayit[a].ad,kayit[a].soyad,kayit[a].eposta,kayit[a].il,kayit[a].ilce,kayit[a].mahalle,kayit[a].sokak);
				fscanf(fp,"%s%s%s%s",kayit[a].evtelefonu,kayit[a].ceptelefonu,kayit[a].istelefonu,kayit[a].dogumtarihi);
				a++;
			}

			for(int i=0;i<=(a-1);i++)
			{
					if( secim=1 && strcmp(kelime,kayit[i].ad)==0 )
					{
						printf("\n %s\t %s \t %s \t %s \t %s \t %s \t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
						printf("%s ™\t %s \t %s \t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
					}

					if( secim=2 && strcmp(kelime,kayit[i].soyad)==0 )
					{
						printf("\n %s\t %s \t %s \t %s \t %s \t %s \t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
						printf("%s ™\t %s \t %s \t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
					}

					if( secim=3 && strcmp(kelime,kayit[i].dogumtarihi)==0 )
					{
						printf("\n %s\t %s \t %s \t %s \t %s \t %s \t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
						printf("%s ™\t %s \t %s \t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
					}
			}
	}
	fclose(fp);
	getche();
}
///////////////////////////////////////////////////////////////////////////////
void degistir()
{
	char kelime[15];
	int a=0,i=0,secim,flag=0;

	printf("\nDeğişiklik Yapılacak Kişiyi Girin: ");
	scanf("%s",kelime);

	fp=fopen("rehber.txt","r");
	if(fp==NULL)
	printf("Dosya Bulunamadı...");
	else
	{
			while(!feof(fp))
			{
					fscanf(fp,"%s %s %s %s %s %s %s",kayit[a].ad,kayit[a].soyad,kayit[a].eposta,kayit[a].il,kayit[a].ilce,kayit[a].mahalle,kayit[a].sokak);
					fscanf(fp,"%s %s %s %s",kayit[a].evtelefonu,kayit[a].ceptelefonu,kayit[a].istelefonu,kayit[a].dogumtarihi);
					a++;
			}

			for(i=0;i<=(a-1);i++)
			{
			 	if(strcmp(kelime,kayit[i].ad)==0)
			  {
					while (flag==0)
					{
						system("clear");
						printf("\n%s %s %s %s %s %s %s ",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
						printf("%s %s %s %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
						printf("\n");
						printf("1- AD \n");
						printf("2- SOYAD \n");
						printf("3- E POSTA \n");
						printf("4- İL \n");
						printf("5- İLÇE \n");
						printf("6- MAHALLE \n");
						printf("7- SOKAK \n");
						printf("8- EV TELEFONU \n");
						printf("9- CEP TELEFONU \n");
						printf("10- İŞ TELEFONU \n");
						printf("11- DOĞUM TARİHİ \n");
						printf("0 - ÇIKIŞ \n");

						printf("\nDeğişiklik Yapılacak Veri Tipini Seçiniz ");
						scanf("%d",&secim);

						switch (secim)
						{
								case 1:
				        	printf("\n %d. Kişinin Yeni Adı:  ",i+1);
				        	scanf("%s",kayit[i].ad);
				        	fflush(stdin);
									break;
								case 2:
									printf("\n %d. Kişinin Yeni Soyadı:  ",i+1);
									scanf("%s",kayit[i].soyad);
									fflush(stdin);
									break;
								case 3:
									printf("\n %d. Kişinin Yeni E-Posta Adresi:  ",i+1);
									scanf("%s",kayit[i].eposta);
									fflush(stdin);
									break;
								case 4:
									printf("\n %d. Kişinin Yeni İli:  ",i+1);
									scanf("%s",kayit[i].il);
									fflush(stdin);
									break;
								case 5:
									printf("\n %d. Kişinin Yeni İlçesi:  ",i+1);
									scanf("%s",kayit[i].ilce);
									fflush(stdin);
									break;
								case 6:
									printf("\n %d. Kişinin Yeni Mahallesi:  ",i+1);
									scanf("%s",kayit[i].mahalle);
									fflush(stdin);
									break;
								case 7:
									printf("\n %d. Kişinin Yeni Sokağı:  ",i+1);
									scanf("%s",kayit[i].sokak);
									fflush(stdin);
									break;
								case 8:
									printf("\n %d. Kişinin Yeni Ev-Telefonu:  ",i+1);
									scanf("%s",kayit[i].evtelefonu);
									fflush(stdin);
									break;
								case 9:
									printf("\n %d. Kişinin Yeni Cep-Telefonu:  ",i+1);
									scanf("%s",kayit[i].ceptelefonu);
									fflush(stdin);
									break;
								case 10:
									printf("\n %d. Kişinin Yeni İş-Telefonu:  ",i+1);
									scanf("%s",kayit[i].istelefonu);
									fflush(stdin);
									break;
								case 11:
									printf("\n %d. Kişinin Yeni Doğum Tarihi:  ",i+1);
									scanf("%s",kayit[i].dogumtarihi);
									fflush(stdin);
									break;
								case 0:
										flag=1;
										break;
								default:
									printf("Hatalı Seçim...");
						}
			   }
    	 }
	  }
 }
	fclose(fp);

	fp=fopen("rehber.txt","w");

	for(i=0;i<(a-1);i++)
	{
		fprintf(fp,"\n%s\t %s\t %s\t %s\t %s\t %s\t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
		fprintf(fp,"%s\t %s\t %s\t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
	}
	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////
void sil()
{
	goruntule();

	int a=0;
	char isim[15];

	printf("\nSilinecek Kişinin İsmini Girin:  ");
	scanf("%s",isim);

	fp=fopen("rehber.txt","r");

	if(fp==NULL)
	printf("Dosya Bulunamadı...");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"\n%s\t %s\t %s\t %s\t %s\t %s\t %s\t",kayit[a].ad,kayit[a].soyad,kayit[a].eposta,kayit[a].il,kayit[a].ilce,kayit[a].mahalle,kayit[a].sokak);
			fscanf(fp,"%s\t %s\t %s\t %s\n",kayit[a].evtelefonu,kayit[a].ceptelefonu,kayit[a].istelefonu,kayit[a].dogumtarihi);
			a++;
		}

		for(int i=0;i<=(a-1);i++)
		{
			if(strcmp(isim,kayit[i].ad)==0)
			{
				printf("\n %d.\n",i+1);
				printf("%s\t %s\t %s\t %s\t %s\t %s\t %s\t",kayit[i].ad,kayit[i].soyad,kayit[i].eposta,kayit[i].il,kayit[i].ilce,kayit[i].mahalle,kayit[i].sokak);
				printf("%s\t %s\t %s\t %s\n",kayit[i].evtelefonu,kayit[i].ceptelefonu,kayit[i].istelefonu,kayit[i].dogumtarihi);
			}
		}
	}
	fclose(fp);

	int b=0,d=0;
	printf("Silinecek Kişinin Numarasını Giriniz: ");
	scanf("%d",&b);
	d=b-1;

	fp=fopen("rehber.txt","w");

	strcpy(kayit[d].ad,kayit[a].ad);
	strcpy(kayit[d].soyad,kayit[a].soyad);
	strcpy(kayit[d].eposta,kayit[a].eposta);
	strcpy(kayit[d].il,kayit[a].il);
	strcpy(kayit[d].ilce,kayit[a].ilce);
	strcpy(kayit[d].mahalle,kayit[a].mahalle);
	strcpy(kayit[d].sokak,kayit[a].sokak);
	strcpy(kayit[d].evtelefonu,kayit[a].evtelefonu);
	strcpy(kayit[d].ceptelefonu,kayit[a].ceptelefonu);
	strcpy(kayit[d].istelefonu,kayit[a].istelefonu);
	strcpy(kayit[d].dogumtarihi,kayit[a].dogumtarihi);

	for(int c=0;c<a;c++)
	{
		fprintf(fp,"\n%s\t %s\t %s\t %s\t %s\t %s\t %s\t",kayit[c].ad,kayit[c].soyad,kayit[c].eposta,kayit[c].il,kayit[c].ilce,kayit[c].mahalle,kayit[c].sokak);
		fprintf(fp,"%s\t %s\t %s\t %s\n",kayit[c].evtelefonu,kayit[c].ceptelefonu,kayit[c].istelefonu,kayit[c].dogumtarihi);
	}
	fclose(fp);
}
