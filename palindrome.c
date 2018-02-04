#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
int secenek=0;
printf("sayi ise 2 ||  harf/kelime vs için 1 ye bas: ");
scanf("%d",&secenek);

if(secenek==1)
{
   int i,adet;
   char *c;
   char A[100],B[100];

   c=A;

   printf("Kac harf gireceksiniz? (max 100 harf): ");

   scanf("%d",&adet);

   for(i=0;i<adet;i++){
      printf("\n %d. harf : ",i+1);
      scanf("%s",c);
      c++;
   }
   //en son harften sonra da adres ötelendi bir geri almak lazım
   //
   c--;
   //kontrol -> sondan basa B'ye kaydet.
   printf("\n");

   for(i=0;i<adet;i++){
      B[i]=*c;
      printf("%c",A[i]);
      c--;
   }

   //iki dizi kontrol
   for(i=0;i<adet;i++){
      if(A[i]!=B[i]){
         printf("\n\nPalindrom degildir.");
         goto end;
      }
   }
   printf("\n\nBu bir palindromdur!");

   end:

getch();
}

if(secenek==2)
{
	int sayi,ters,duz;

		  ters=0; // doğru sonuç için başta 0 a eşitle
	    printf("Bir sayi giriniz: ");
	    scanf("%d",&sayi);
	    if (sayi<=0) { // 0 dan küçük olmaz
        printf("ERROR \n 0 dan küçük bir sayi girdiniz...\n");
      }
      else
      {
        duz=sayi; // islemde sayının değeri bozulacak... yedekleme işlemi
      }
    	while (sayi>0) {
		    ters=ters*10+sayi%10; // basamakları ters çevir
		    sayi/=10;
    	}
      // yedek ve tersi karşılaştır
    	if (duz==ters)
    		printf("Sayi Palindromdur.\n\n");
    	else
    		printf("Sayi Palindrom Degildir.\n\n");

	return 0;
}

}
