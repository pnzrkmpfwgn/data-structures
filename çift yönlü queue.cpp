#include <stdio.h>
#include <malloc.h>
 
//D���mleri tutaca��m�z struct yap�m�z
struct node {
 
    int data;
    struct node *next;
    struct node *prev;
};
 
//Ba�lang�� d���m� bizim i�in �ok �nemli, global de�i�ken olarak tan�mlad�k ve ba�lang��ta NULL atad�k.
struct node* start = NULL;
 
//D���m olusturup return eden fonksiyon
struct node* dugumOlustur(int veri)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;
 
    return yeniDugum;
}
 
//�ift y�nl� ba�l� listede sona d���m ekleyen fonksiyon
void sonaEkle(int veri)
{
    struct node* sonaEklenecek = dugumOlustur(veri);
 
    //E�er listede hi� eleman yoksa yeni eleman ekliyoruz
    if (start == NULL)
    {
        start = sonaEklenecek;
    }
 
    else
    {
        //traverse etmek i�in temp de�i�kenine start de�i�kenini atad�k, maksat start de�i�kenini bozmamak.
        struct node* temp = start;
 
        //A�a��daki d�ng� traverse yap�yor ve temp d���m� d�ng� sonunda son d���m oluyor.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
 
        //temp eleman� (eski son) oldu�u i�in sonaEklenecek (yeni son) d���m�n�n prev i�aret�isi tempi g�sterecek.
        sonaEklenecek->prev = temp;
 
        //temp de�i�keninin next i�aret�isi ise art�k yeni son eleman�m�z olan sonaEklenecek d���m�n� i�aret edecek.
        temp->next = sonaEklenecek;
    }
}
 
//�ift y�nl� ba�l� listede ba�a d���m ekleyen fonksiyon
void basaEkle(int veri)
{
    struct node* basaEklenecek = dugumOlustur(veri);
 
    if (start == NULL)
    {
        start = basaEklenecek;
        return;
    }
 
    start->prev = basaEklenecek;
    basaEklenecek->next = start;
    start = basaEklenecek;
}
 
//�ift y�nl� ba�l� listede araya d���m ekleyen fonksiyon
void arayaEkle(int kiminOnune, int eklenecek)
{
    struct node* temp = start;
    struct node* arayaEklenecek = dugumOlustur(eklenecek);
    struct node* onceki = NULL;
 
    if (start == NULL)
    {
        start = arayaEklenecek;
    }
    else if(start->data == kiminOnune)
    {
        basaEkle(eklenecek);
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == kiminOnune)
            {
                onceki = temp->prev;
                break;
            }
            temp = temp->next;
        }
        temp->prev = arayaEklenecek;
        arayaEklenecek->next = temp;
        arayaEklenecek->prev = onceki;
        onceki->next = arayaEklenecek;
    }
 
 
}
 
//�ift y�nl� ba�l� listede ba�tan d���m silen fonksiyon
void bastanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }
 
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
 
    struct node* ikinci = start->next;
    free(start);
    ikinci->prev = NULL;
    start = ikinci;
}
 
//�ift y�nl� ba�l� listede sondan d���m silen fonksiyon
void sondanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }
 
    if (start->next == NULL)
    {
        bastanSil();
        return;
    }
 
    struct node* temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
 
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
}
 
//�ift y�nl� ba�l� listede aradan d���m silen fonksiyon
void aradanSil(int silinecek)
{
    struct node* temp = start;
    while (temp->next != NULL)
    {
        if (temp->data == silinecek)
            break;
        temp = temp->next;
    }
    struct node* sonraki = temp->next;
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = sonraki;
    sonraki->prev = onceki;
}
 
//D���m yap�s�n� ekrana 
void yazdir()
{
    struct node* temp = start;
 
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}
 
 
 
int main()
{
 
    int i, secim, sayi, sayi1;
 
    while (1)
    {
        printf("\n 1- sona eleman ekleme");
        printf("\n 2- basa eleman ekleme");
        printf("\n 3- araya eleman ekleme");
        printf("\n 4- bastan eleman sil");
        printf("\n 5- sondan eleman sil");
        printf("\n 6- aradan eleman sil");
        printf("\n Seciminizi yapin ... ");
        scanf("%d", &secim);
 
        switch (secim)
        {
            case 1:
                printf("\n Sona Eklemek istediginiz elemani girin ... ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;
            case 2:
                printf("\n Basa Eklemek istediginiz elemani girin ... ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;
 
            case 3:
                printf("\n Araya Eklemek istediginiz sayiyi girin ... ");
                scanf("%d", &sayi);
                printf("\n Hangi elemanin onune eklemek istiyorsunuz... ");
                scanf("%d", &sayi1);
                arayaEkle(sayi1, sayi);
                yazdir();
                break;
            case 4:
                bastanSil();
                yazdir();
                break;
 
            case 5:
                sondanSil();
                yazdir();
                break;
 
            case 6:
                printf("\n Silinmesini istedigini elemani girin ... ");
                scanf("%d", &sayi);
                aradanSil(sayi);
                yazdir();
                break;
 
        }
    }
 
    return 0;
}
