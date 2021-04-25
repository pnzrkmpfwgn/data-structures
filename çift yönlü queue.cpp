#include <stdio.h>
#include <malloc.h>
 
//Düðümleri tutacaðýmýz struct yapýmýz
struct node {
 
    int data;
    struct node *next;
    struct node *prev;
};
 
//Baþlangýç düðümü bizim için çok önemli, global deðiþken olarak tanýmladýk ve baþlangýçta NULL atadýk.
struct node* start = NULL;
 
//Düðüm olusturup return eden fonksiyon
struct node* dugumOlustur(int veri)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;
 
    return yeniDugum;
}
 
//Çift yönlü baðlý listede sona düðüm ekleyen fonksiyon
void sonaEkle(int veri)
{
    struct node* sonaEklenecek = dugumOlustur(veri);
 
    //Eðer listede hiç eleman yoksa yeni eleman ekliyoruz
    if (start == NULL)
    {
        start = sonaEklenecek;
    }
 
    else
    {
        //traverse etmek için temp deðiþkenine start deðiþkenini atadýk, maksat start deðiþkenini bozmamak.
        struct node* temp = start;
 
        //Aþaðýdaki döngü traverse yapýyor ve temp düðümü döngü sonunda son düðüm oluyor.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
 
        //temp elemaný (eski son) olduðu için sonaEklenecek (yeni son) düðümünün prev iþaretçisi tempi gösterecek.
        sonaEklenecek->prev = temp;
 
        //temp deðiþkeninin next iþaretçisi ise artýk yeni son elemanýmýz olan sonaEklenecek düðümünü iþaret edecek.
        temp->next = sonaEklenecek;
    }
}
 
//Çift yönlü baðlý listede baþa düðüm ekleyen fonksiyon
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
 
//Çift yönlü baðlý listede araya düðüm ekleyen fonksiyon
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
 
//Çift yönlü baðlý listede baþtan düðüm silen fonksiyon
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
 
//Çift yönlü baðlý listede sondan düðüm silen fonksiyon
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
 
//Çift yönlü baðlý listede aradan düðüm silen fonksiyon
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
 
//Düðüm yapýsýný ekrana 
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
