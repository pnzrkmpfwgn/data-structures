#include <iostream>

using namespace ::std;

struct node{
    int data;
    struct node *next;
};

struct node* start = NULL;
struct node *q = NULL;

void sonaekle(int veri){
    int i = 0;
    struct node *eklenecek = (struct node *)malloc(sizeof(struct node));
    eklenecek->data = veri;
    eklenecek->next = NULL;

    if(start == NULL){
        start = eklenecek;
        i++;
    }
    else{
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = eklenecek;
    }
}

void yazdir(){
    q = start;
    while (q->next!=NULL)
    {
        cout << q->data;
        q = q->next;
    }
    cout << q->data;
}

void basaekle(int basa){
    struct node *basagelecek = (struct node *)malloc(sizeof(struct node));
    basagelecek->data = basa;
    basagelecek->next = start;
    start = basagelecek;
}

int main(){
    int secim;
    int sona, basa;
    cout << "1= basa eleman ekle" << endl;
    cout << "2= sona eleman ekle";

    while (1)   
    {
        cout << "Yapmak istediginiz islemi secin\n";
        cin >> secim;

        switch(secim){
			case 1:{
                cout << "Sayi giriniz:";
                cin >> sona;
                sonaekle(sona);
                yazdir();
                cout << endl;
                break;
            }
			case 2:{
                cout <<  "sayi giriniz:";
                cin >> basa;
                basaekle(basa);
                yazdir();
                cout << endl;
                break;
            }
		}
    }
           cout << endl;
        return 0;
}