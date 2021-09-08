#include <stdio.h>
#include <string.h>
// Menüde Gezinilebilecek;
// Menüde Yanlýþ bir iþlem yapýldýðýnda Program Except //olmayacak
//Gecmis Basit Yöntemler ile tutulacak;
struct Veritabani{
  int X1Sayilar[10];
  int X2Sayilar[10];
  char Islemler[10];
  int X3Sonuclar[10];
  // Böyle Daha iyi kafa karýþtýrmaz.
};
void giris(struct Veritabani*veriler){
  int i;
  for(i  = 0; i < 10 ; i++) {
    veriler->X1Sayilar[i] = 0;
    
    veriler->X2Sayilar[i] = 0;
    
    veriler->X3Sonuclar[i] = 0;

    veriler->Islemler[i] = 'V';
  }

}

void limit(struct Veritabani * veriler) {
  int XIslemler = sizeof(veriler->Islemler)/sizeof(veriler->Islemler[0]); // Array Elman Sayýsý.

  int i;
  int counter = 1;
  for(i = 0; i < XIslemler;i++) {
    if(veriler->Islemler[i] != 'V') {
       counter++;
    } 
  }

  if(counter == 10) {
    for(i = 0; i < XIslemler-5; i++) {
      veriler->X1Sayilar[i] = 0;
      veriler->X2Sayilar[i] = 0;
      veriler->X3Sonuclar[i] = 0;
      veriler->Islemler[i] = 'V';
    }
  }
  
}

void addHistory(struct Veritabani* veriler , int sayi1 , int sayi2 , char islem ,int sonuc) {
  int i;
  for(i = 0; i<10 ; i++) {
    if(veriler->X1Sayilar[i] == 0 && veriler->X2Sayilar[i] == 0 && veriler->X3Sonuclar[i] ==0 && veriler->Islemler[i] == 'V') {

      veriler->X1Sayilar[i] = sayi1;
      veriler->X2Sayilar[i] = sayi2;
      veriler->X3Sonuclar[i] = sonuc;
      veriler->Islemler[i] = islem;
      break;
    }    
  }
}

void Gecmis(struct Veritabani *veriler) {
    printf("Geçmis \n");
    int i;
    for(i  = 0; i < 10 ; i++) {

        if(veriler->Islemler[i] != 'V') {
            printf("ISLEM KAYDI : %d %c %d = %d \n",veriler->X1Sayilar[i],veriler->Islemler[i],veriler->X2Sayilar[i],veriler->X3Sonuclar[i]);
        } else {
          continue;
        }

    }


}



int main() {
  // Program ;
  struct Veritabani veriler;
  giris(&veriler);
  // Geçmiþ Tutabilen Hesap Makinesi;
 int sayi1;
 int menuNotasyon;
 int sayi2;
 char islem;
 int sonuc;
 
 while(1 < 2) {
  
      printf("Hosgeldiniz: \n \n");
      limit(&veriler);
      printf("\t Geçmiþ Ýþlemler = 1 \n \t Hesap Makinesi = 2 \n \n");
      scanf("%d",&menuNotasyon);

      if(menuNotasyon == 1) {
          Gecmis(&veriler);
      }
      else if(menuNotasyon == 2) {
          printf("Ýlk Sayýyý Giriniz:");
          scanf("%d",&sayi1);
          printf("\n");
          printf("Ýkinci Sayýyý Giriniz:");
          scanf("%d",&sayi2);
          printf("\n");
          printf("Yapýlacak Ýþlemi Giriniz:");
          scanf(" %c",&islem);


          if(islem == '+') {
            printf("Sonuc: %d \n",sayi1+sayi2);
            addHistory(&veriler,sayi1,sayi2,islem,sayi1+sayi2);
          }
          else if(islem == '-') {
            printf("Sonuc: %d \n",sayi1-sayi2);
            addHistory(&veriler,sayi1,sayi2,islem,sayi1-sayi2);
          }
          else if(islem == '*'){
            printf("Sonuc %d \n", sayi1*sayi2);
            addHistory(&veriler,sayi1,sayi2,islem,sayi1*sayi2);

          }
          else if(islem == '/')
          {
            printf("Sonuc : %d \n",sayi1/sayi2);
            addHistory(&veriler,sayi1,sayi2,islem,sayi1/sayi2);
          }
          else{
            printf("Hatalý Giriþ Yaptýnýz. \n");            
            continue;
          }
      }
      else {
        printf(" \n Hatalý Seçim Yaptýnýz. \n");
        continue;
      }
      
  }

  return 0;
}
