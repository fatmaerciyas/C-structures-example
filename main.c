#include <stdio.h>
#include <stdlib.h>                                                

typedef struct ders
{

    char dersadi[10];
    int vizenotu;
    int finalnotu;

} dersler;

typedef struct ogrenci
{
    char ad[10];
    char soyad[15];
    int numara;
    int dersSayisi;
    dersler *p2;

} bilgiler;

int i,j,ogrsayi;

bilgiler *p;

bilgiler Bilgileri_Al()
{

    int i,j;


    p=(bilgiler*)calloc(ogrsayi,sizeof(bilgiler)); 


    for(i=0; i<ogrsayi; i++)
    {

        printf("\n\n****%d. ogrenci icin****\n\n",i+1);

        printf(" adini giriniz: ");
        scanf("%s",(p+i)->ad);

        printf(" soyadini giriniz: ");
        scanf("%s",(p+i)->soyad);

        printf(" numarasini giriniz: ");
        scanf("%d",&(p+i)->numara);

        printf("ders sayisini giriniz: ");
        scanf("%d",&(p+i)->dersSayisi);

        (p+i)->p2=(dersler*)calloc((p+i)->dersSayisi,sizeof(dersler));

        for(j=0; j<(p+i)->dersSayisi; j++)
        {


            printf("%d.dersinin adini giriniz: ",j+1);
            scanf("%s",(((p+i)->p2)+j)->dersadi);


            printf("%d.dersinin vize notunu giriniz: ",j+1);
            scanf("%d",&(((p+i)->p2)+j)->vizenotu);

            printf("%d.dersinin final notunu giriniz: ",j+1);
            scanf("%d",&(((p+i)->p2)+j)->finalnotu);
            printf("\n\n");



        }

    }
    return *p;

}



void Ogrenci_ara()
{

    char ad[50];
    int aduzunluk=0,c,sayac=0;


    printf("kullanicinin adini giriniz: ");
    scanf("%s",ad);


    for(c=0; ad[c]!='\0'; c++)
    {
        aduzunluk++;
    }
    printf("adin uzunlugu :%d\n\n",aduzunluk);




    for(i=0; i<ogrsayi; i++)
    {
        for(j=0; j<aduzunluk; j++)
        {

            if( ad[j]==(p+i)->ad[j])
            {

                sayac++;
                if(sayac==aduzunluk)
                {
                    printf(" ogrencinin adi:%s\n soyadi:%s\n numarasi:%d\n ders sayisi:%d\n",(p+i)->ad,(p+i)->soyad,(p+i)->numara,(p+i)->dersSayisi);
                    for(c=0; c<(p+i)->dersSayisi; c++)
                    {
                        printf("ogrencinin aldigi %d.ders: %s\n",c+1,((p+i)->p2+c)->dersadi);
                    }

                }

            }
            else
            {
                sayac=0;
            }

        }


    }

}


void Durum_goster()
{
    float sonuc=0.0;

    for(i=0; i<ogrsayi; i++)
    {

        for(j=0; j<(p+i)->dersSayisi; j++)
        {

            sonuc=(((p+i)->p2+j)->vizenotu)*0.4+(((p+i)->p2+j)->finalnotu)*0.6;

            printf("%s %s in %s dersi ortalamasi :%.2f\n",(p+i)->ad,(p+i)->soyad,(((p+i)->p2)+j)->dersadi,sonuc);

            


            if(sonuc>=60)
            {
                printf("%s %s,%s dersinde basarili.\n",(p+i)->ad,(p+i)->soyad,(((p+i)->p2)+j)->dersadi);
            }

            else
            {
                printf("%s %s,%s dersinde basarisiz.\n",(p+i)->ad,(p+i)->soyad,(((p+i)->p2)+j)->dersadi);
            }

        }

    }
}


void Listele()
{

    for(i=0; i<ogrsayi; i++)
    {
        for(j=0; j<(p+i)->dersSayisi; j++)
        {
            printf("-------------------\n");
            printf(" ***%d.ogrencinin***\n adi: %s\n soyadi: %s\n numarasi: %d\n ders sayisi: %d\n",i+1,(p+i)->ad,(p+i)->soyad,(p+i)->numara,(p+i)->dersSayisi);
            printf(" ***%s dersinin***\n vize notu: %d\n final notu: %d\n\n",((((p+i)->p2)+j)->dersadi),((((p+i)->p2)+j)->vizenotu),((((p+i)->p2)+j)->finalnotu));


        }
    }
}


int main()
{

    int a;

    printf("kac adet ogrenci girmek istiyorsun:");
    scanf("%d",&ogrsayi);


    Bilgileri_Al(ogrsayi);



    a=1;
    while(a!=0)//surekli menünün ekrana gelmesi icin while olusturdum
    {

        printf(" \n1-Ogrenci Ara\n 2-Durum Goster\n 3-Listele\n 4-Cikis\n\n");
        int islem;
        printf("islemi seciniz: ");
        scanf("%d",&islem);
        printf("\n\n");

        if(islem!=4)
        {


            

            switch(islem)
            {
            case 1:
                Ogrenci_ara();

                break;

            case 2:

                Durum_goster();
                break;

            case 3:
                Listele();

                break;


            }//switch


        }//if

        else
        {
            a=0;
        }
    }//while



    return 0;
}
