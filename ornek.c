#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
 
int main()
{
	//Değişkenlerimi tanımladım basamaklar için basamak adında int dizi tanımladım.
	int tahmin, dogru=0, yalnis=0, sayi=0, basamak[3];
	int i,y,o,b; //birler onlar yüzler basamakları
 
	srand(time(NULL));
	//for döngüsü içerisinde 3 basamaklı rastgele sayı üretmek için basamak değerleri teker teker üretildi
	for(i=0;i<3; i++){	
		basamak[i]=rand()%9;
	}
	//Buradaki iflerle basamaklardaki sayıların birbirine eşit olmaması için atamalar yapıldı.
	if(basamak[0] == basamak[1]){
		basamak[0]--;
	}
	if(basamak[1] == basamak[2]){
		basamak[2]++;
	}
	if(basamak[0] == basamak[2]){
		basamak[0]--;
	}
	//basamaktaki sayılar basamak degerleriyle carpılarak tahmin sayısı hazır hale getirildi
	tahmin = basamak[0]*100 + basamak[1]*10 + basamak[2];
	//Tahmin edilen ve girilen sayı birbirine eşit değilse sayı bulma işlemine gecildi.(döngüye girildi)
	while(tahmin != sayi){
			printf("3 basamakli bir sayi tahmin ediniz : ");
			scanf("%d",&sayi);
		//birler onlar ve yüzler basamakları sayı değeri haline getirildi. karsılatırma işlemi yapılacak
		b=sayi%10;
		o=(sayi%100-sayi%10)/10;
		y=(sayi-sayi%100-sayi%10)/100 + 1;
		//basmaklar karsılastırılıyor eger aynı deger varsa sayının tekrar girilmesi istenecek.
		while(y==o || o==b || y==b){
		
			printf("3 basamakli bir sayi tahmin ediniz : ");
			scanf("%d",&sayi);
		
		b=sayi%10;
		o=(sayi%100-sayi%10)/10;
		y=(sayi-sayi%100-sayi%10)/100 + 1;
 
		}
 
	//sayı 3 basamaktan küçükse tekrar sayı girilmesi istenecek
	while(sayi<100){
		printf("3 basamakli bir sayi tahmin ediniz : ");
		scanf("%d",&sayi);
	}
	//sayı 3 basamaktan büyükse tekrar sayı girilmesi istenecek
	while(sayi>999){
		printf("3 basamakli bir sayi tahmin ediniz : ");
		scanf("%d",&sayi);
	}
	//bu bölümdeki iflerle tahmin edilen sayının basamaklarıyla girilen sayının basamakları aynı değil ise puan azaltma işlemi yapıldı.
	if(basamak[0] != y && (basamak[0] == o || basamak[0] == b)){
		yalnis++;
	}
	if(basamak[1] != o && (basamak[1] == y || basamak[1] == b)){
		yalnis++;
	}
	if(basamak[2] != b && (basamak[2] == o || basamak[2] == y)){
		yalnis++;
	}
	//bu bölümdeki iflerle tahmin edilen sayının basamaklarıyla girilen sayının basamakları aynı ise puan arttırılma işlemi yapıldı.
	if(basamak[0] == y){
		dogru++;
	}
	if(basamak[1] == o){
		dogru++;
	}
	if(basamak[2] == b){
		dogru++;
	}
 
	//tahmin puanları ekrana yazdırıldı.
	printf("Sonuc : +%d",dogru);
	printf("  -%dn",yalnis);
 
	}
 
	system("PAUSE");
	return 0;
}
