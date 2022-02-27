#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct Salonlar{
    char Red[5][50];
    char Green[5][50];
    char Blue[5][50];
};

struct {
     char nickname[20];
     char sifre[20];
}kullanicilar[50];

struct tanimlayicilar{
    char kullanicisifresi [20];
    char kullaniciadi [20];
};
enum{
	ogrenci=1,
	tam
}ucretler;
int salonsecimi,odemesekli,koltuknumarasi, yapilacakodeme,matinesecimi;
int i,j,k;
int secim,hasilat;
int sayaclogin=0;
int tutar=0;
int sayackoltuk=0;
FILE *sifreleme,*hasilatlar,*kirmizi,*mavi,*yesil;
struct Salonlar sln;
struct Salonlar *psalon=&sln;
void EKRAN();
void OLUSTUR();
void GIRIS();
void ANA_MENU();
void SALON_SECIMI();
void HASILAT_BILGISI();
void IZLENME_BILGISI();
void BOS();
void BOS2();
int main()
{
 EKRAN();
 return 0;
}
void EKRAN(){
    printf("\n\n\t\t\t\t\t\t1-KULLANICI OLUSTUR\n\t\t\t\t\t\t2-GIRIS YAP\n\t\t\t\t\t\t3-CIKIS\n\t\t\t\t\t\tSeciminiz:");
    scanf("%d",&secim);
    if(secim==1){
        OLUSTUR();
    }
    else if(secim==2){
        GIRIS();
    }
    else if(secim==3){
        exit(1);
    }
}

void OLUSTUR(){

    sifreleme=fopen("sifre.txt","a+");
    printf("\n\t\t\t\t\t\tKullanmak istediginiz kullanici adinizi giriniz=");
    scanf("%s",kullanicilar[sayaclogin].nickname);
    printf("\n\t\t\t\t\t\tSifrenizi giriniz=");
    scanf("%s",kullanicilar[sayaclogin].sifre);
    printf("\n\t\t\t\t\t\tYonlendiriyorsunuz.....\n");
     fprintf(sifreleme,"%s \t%s\n",kullanicilar[sayaclogin].nickname,kullanicilar[sayaclogin].sifre);
    fclose(sifreleme);
    BOS();
}
void GIRIS(){
    char isim[20];
    char password[20];
    sifreleme=fopen("sifre.txt","r");
    printf("\n\t\t\t\t\t\tKULLANICI ADI GIRINIZ===>");
    scanf("%s",&isim);
    printf("\n\t\t\t\t\t\tSIFREYI GIRINIZ===>");
    scanf("%s",&password);
    while(!feof(sifreleme)){

    fscanf(sifreleme,"%s %s  ",kullanicilar[sayaclogin].nickname,kullanicilar[sayaclogin].sifre);
    if(strcmp(kullanicilar[sayaclogin].nickname,isim)==0 && strcmp(kullanicilar[sayaclogin].sifre,password)==0){
    printf("\n\tGIRIS BASARILI\n");
    sayaclogin++;
    BOS2();
   }
   else{
    printf("\n\tKULLANICI BULUNAMADI\n");
    exit(1);
   }

  }
fclose(sifreleme);
}
void BOS(){
    printf("\t\tKullanici hesabiniz basari ile olusturuldu.(BIR SONRAKI GIRISINIZDE OTURUM ACMANIZ GEREKLIDIR.)\n");
   BOS2();
}
void BOS2(){
printf("\n\n\t\t Sayin Musterilerimiz Bilet Satin Aldiktan Sonra Bilet Iptali ya da Matine Saati Degisikligi\n Yapmaniz Muessesemiz Tarafindan Yasaklanmistir!!!!!");
 ANA_MENU();
}

void ANA_MENU(){
	int x;

	tekrar:
	printf("\n\t\tSINEMA OTOMASYONUNA HOSGELDINIZ\n\t\t1-SALON SECIMI \n\t\t2-HASILAT BILGISI\n\t\t3-IZLENME BILGISI\n\t\t4-CIKIS");
    printf("\n\t\tLutfen seciminizi yapiniz:");
    scanf("%d",&x);
    if (x<5){
	    if (x==1){
	      SALON_SECIMI();
	    }
        else if(x==2){
    	   HASILAT_BILGISI();
	    }
	    else if(x==3){
		   IZLENME_BILGISI();
        }
       else if(x==4){
           exit(1);
       }



    }

    else{
        printf("\n\t\tGecersiz giris yaptiniz.\n");
	    goto tekrar;

    }
    }
void SALON_SECIMI(){

    kirmizi=fopen("redkolt.txt","a+");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Red[j][k] = getc(kirmizi) ;
        }

    }
    fclose(kirmizi);

    mavi=fopen("bluekolt.txt","a+");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Blue[j][k] = getc(mavi) ;
        }

    }
    fclose(mavi);

    yesil=fopen("greenkolt.txt","a+");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Green[j][k] = getc(yesil) ;
        }

    }
    fclose(yesil);
   seans:
   printf("\n\t\tHangi salona rezarvasyon yapmak istersiniz?\n\t\t((Red Salon (Hizli ve Ofkeli8) Icin R ya da r'yi tuslayiniz.) \n\t\t(Green Salon Icin (Korku Seansi 3)G/gyi tuslayiniz.)\n\t\t(Blue Salon Icin (Avengers Endgame) B/byi tuslayiniz.)\nSeciminiz:");
            scanf(" %c",&salonsecimi);
            switch(salonsecimi)
            {
                case 'R':
                case 'r':

                    printf("\n\n\t\tKac numarali matinede rezarvasyon yapmak istersiniz?\n\t\t(1.Matine (10.30)/t2.Matine (12.00)/t3.Matine (14.45)/t4.Matine(19.00)/t5.Matine(22.00))\n\t\tSeciminiz:");
                    scanf("%d",&matinesecimi);
                    for(i=matinesecimi-1;i<matinesecimi;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Red[i][j] == '0')
                            {
                                psalon->Red[i][j] = '1';
                                koltuknumarasi = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\n\t\tOdeme sekliniz?\n\t\t(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\nvRezarvasyon Bilgileri:\n");
                    printf("\n\n\t\t%d numarali koltuga rezerve yapilmistir.\n",koltuknumarasi+1);
                    printf("\n\t\tUcretiniz %d liradir.\n",tutar);

                    kirmizi=fopen("redkolt.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Red[j][k] == '1'){
                            fputc('1',kirmizi);
                            }
                        else{
                            fputc('0',kirmizi);
                        }
                        }

                    }
                    fclose(kirmizi);

                    hasilatlar=fopen("log.txt","w+");

                    fprintf(hasilatlar,"\n\nToplam hasilatimiz:%d",hasilat);

                    fclose(hasilatlar);
                   ANA_MENU();


                break;
                break;

                case 'G':
                case 'g':
                    printf("\n\nvKac numarali matinede rezarvasyon yapmak istersiniz?\n\t\t(1.Matine (10.30)/t2.Matine (12.00)/t3.Matine (14.45)/t4.Matine(19.00)/t5.Matine(22.00))\n\t\tSeciminiz:");
                    scanf("%d",&matinesecimi);
                    for(i=matinesecimi-1;i<matinesecimi;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Green[i][j] == '0')
                            {
                                psalon->Green[i][j] = '1';
                                koltuknumarasi = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\n\t\tOdeme sekliniz?\n\t\t(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\n\t\tRezarvasyon Bilgileri:\n");
                    printf("\n\n\t\t%d numarali koltuga rezerve yapilmistir.\n",koltuknumarasi+1);
                    printf("\n\t\tUcretiniz %d liradir.\n",tutar);

                    yesil=fopen("greenkolt.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Green[j][k] == '1')
                            fputc('1',yesil);
                        else
                            fputc('0',yesil);
                        }

                    }
                    fclose(yesil);
                    hasilatlar=fopen("log.txt","w+");

                    fprintf(hasilatlar,"\n\nToplam hasilatimiz:%d",hasilat);

                    fclose(hasilatlar);

                     ANA_MENU();
                    break;
                    break;

                case 'B':
                case 'b':
                    printf("\n\n\t\tKac numarali matinede rezarvasyon yapmak istersiniz?\n\t\t(1.Matine (10.30)/t2.Matine (12.00)/t3.Matine (14.45)/t4.Matine(19.00)/t5.Matine(22.00))\n\t\tSeciminiz:");
                    scanf("%d",&matinesecimi);
                    for(i=matinesecimi-1;i<matinesecimi;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Blue[i][j] == '0')
                            {
                                psalon->Blue[i][j] = '1';
                                koltuknumarasi = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\n\t\tOdeme sekliniz?\n\t\t(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci )
                    {
                        tutar = 20;
                        hasilat+=tutar;
                    }
                    else if(odemesekli == tam)
                    {
                        tutar = 30;
                        hasilat+=tutar;
                    }
                    printf("\n\t\tRezarvasyon Bilgileri:\n");
                    printf("\n\n\t\t%d numarali koltuga rezerve yapilmistir.\n",koltuknumarasi+1);
                    printf("\n\t\tUcretiniz %d liradir.\n",tutar);

                   mavi=fopen("bluekolt.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Blue[j][k] == '1')
                            fputc('1',mavi);
                        else
                            fputc('0',mavi);
                        }

                    }
                    fclose(mavi);
                    hasilatlar=fopen("log.txt","w+");

                    fprintf(hasilatlar,"\n\nToplam hasilatimiz:%d",hasilat);

                    fclose(hasilatlar);
                   ANA_MENU();
                    break;
                    break;

                default:
                    printf("\n\t\tYanlis secim yaptiniz.\n");
                    goto seans;
                    break;
}

}
void HASILAT_BILGISI(){
hasilatlar=fopen("log.txt","r");
     fscanf(hasilatlar,"%d",&hasilat);
printf("\t\t\n\nToplam hasilatimiz:%dTL'dir.\n\n",hasilat);
fclose(hasilatlar);
ANA_MENU();
}
void IZLENME_BILGISI(){
	FILE *izlenme;
   izlenme=fopen("izlenme.txt","w+");
   izlenme=fopen("izlenme.txt","a+");
	printf("\t\tBugun Red salonunda, ");
	 for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Red[i][j] == '1')
                    {
                        sayackoltuk++;

                    }
                }
                printf("\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
                fprintf(izlenme, "\nBugun Red salonunda,\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
				sayackoltuk=0;
            }
            printf("\t\tBugun Green salonunda, ");
	 for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Green[i][j] == '1')
                    {
                        sayackoltuk++;

                    }
                }
                printf("\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
                 fprintf(izlenme, "\nBugun Green salonunda,\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
                sayackoltuk=0;
            }
            printf("\t\tBugun Blue salonunda, ");
	 for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Blue[i][j] == '1')
                    {
                        sayackoltuk++;

                    }
                }
                printf("\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
                fprintf(izlenme, "\nBugun Blue salonunda,\n%d. Matinede %d izlenme olmustur.\n",i+1,sayackoltuk);
				sayackoltuk=0;
            }
     fclose(izlenme);
}
