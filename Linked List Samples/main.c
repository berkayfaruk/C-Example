#include <stdio.h>
#include <stdlib.h>
void menu();
void yazdir();
void sonaEkle();
void basaEkle();
void arayaEkle();
void sondanSil();
void bastanSil();
void aradanSil();
void tersCevir();

struct node
{
    int data;
    struct node *sonraki;
};

struct node *start=NULL;
struct node*temp=NULL;
struct node* q=NULL;

int main()
{
   int secim,basa,sona,x,y;
   menu();

   while(1==1)
   {
       printf("\nBaska isleminiz varmi ?: ");
       scanf("%d",&secim);
       if(secim==0)
       {
           menu();
       }

       else if(secim==1)
       {
           printf("\nBasa eklemek istediginiz elamani girin:  ");
           scanf("%d",&basa);
           basaEkle(basa);
           yazdir();
       }
       else if(secim==2)
       {
           printf("\nSona eklemek istediginiz elamani girin: ");
           scanf("%d",&sona);
           sonaEkle(sona);
           yazdir();
       }
       else if(secim==3)
       {
           printf("Hangi sayinin onune ekleme yapacaksin: ");
           scanf("%d",&x);
           printf("Eklemek istediginiz elamani girin: ");
           scanf("%d",&y);
           arayaEkle(x,y);
           yazdir();
        }
        else if(secim==4)
        {
            sondanSil();
            yazdir();
        }
        else if(secim==5)
        {
            bastanSil();
            yazdir();
        }
        else if(secim==6)
        {
           printf("\nArada silmek istediginiz elamani girin: ");
           scanf("%d",&secim);
           aradanSil(secim);
           yazdir();
        }
        else if(secim==7)
        {
            tersCevir();
            yazdir();
        }
       else if(secim==-1)
       {
           printf("\nBitti...");
           break;
       }

   }

    return 0;
}
void tersCevir()
{
    struct node* temp;
    struct node* prev=NULL;
    q=start;
    while(q!=NULL)
    {
        temp=q->sonraki;
        q->sonraki=prev;
        prev=q;
        q=temp;
    }
    start=prev;

}
void aradanSil(int silinen)
{
    if(start->data==silinen)
    {
        bastanSil();
    }
    struct node* onceki=NULL;
    struct node* sonraki2=NULL;
    q=start;
    while(q->sonraki->data!=silinen)
    {
        q=q->sonraki; // q=silinen den bir öncekini
    }
    if(q->sonraki==NULL)
    {
        sondanSil();
    }
    onceki=q;
    sonraki2=q->sonraki->sonraki;
    free(q->sonraki);
    onceki->sonraki=sonraki2;

}
void bastanSil()
{
    struct node* ikinci=NULL;
    ikinci=start->sonraki;
    free(start);
    start=ikinci;
}
void sondanSil()
{
    q=start;
    while(q->sonraki->sonraki!=NULL)
    {
        q=q->sonraki;
    }
    free(q->sonraki);
    q->sonraki=NULL;
}
void basaEkle(int basa)
{
    struct node* basa_gelecek=(struct node*)malloc(sizeof(struct node));
    basa_gelecek->data=basa;
    basa_gelecek->sonraki=start;
    start=basa_gelecek;
}
void sonaEkle(int veri)
{
    struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data=veri;
    eklenecek->sonraki=NULL;

    if(start==NULL)
    {
        start=eklenecek;
    }
    else
    {
        temp=start;
        while(temp->sonraki!=NULL)
        {
            temp=temp->sonraki;
        }
        temp->sonraki=eklenecek;
    }
}
void arayaEkle(int x,int y)
{
    struct node* arayaEklenecek=(struct node*)malloc(sizeof(struct node));
    arayaEklenecek->data=y;
    q=start;
    while(q->sonraki->data!=x)
    {
        q=q->sonraki;
    }
    struct node* onune=(struct node*)malloc(sizeof(struct node));
    onune=q->sonraki;
    q->sonraki=arayaEklenecek;
    arayaEklenecek->sonraki=onune;
}
void yazdir()
{
    q=start;
    while(q->sonraki!=NULL)
    {
        printf("%d=>",q->data);
        q=q->sonraki;
    }
    printf("%d",q->data);
}
void menu()
{
       printf("**********ISLEMLER*********\n");
       printf("0.Menuyu tekrar gormek icib sifira basin\n");
       printf("1.Basa Elaman Ekle\n");
       printf("2.Sona Elaman Ekle\n");
       printf("3.Araya Elaman Ekle\n");
       printf("4.Sondan Elaman Silme\n");
       printf("5.Bastan Elaman Silme\n");
       printf("6.Aradan Elaman Silme\n");
       printf("\nYapmak istediginiz islemi seciniz\n");

       printf("Cikmak icin -1 i tuslayiniz\n");
}

