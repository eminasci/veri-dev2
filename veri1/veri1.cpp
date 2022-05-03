#include <iostream>
//#include <bits/stdc++.h>


using namespace std;


#ifndef  KUYRUK_H
#define KUYRUK_H
typedef char KuyrukVeriTipi;

struct Dugum
{
    KuyrukVeriTipi veri;
    Dugum* sonraki;

};
struct  Kuyruk
{
    Dugum* bas;
    Dugum* son;
    void olustur();
    void kapat();
    void ekle(KuyrukVeriTipi);
    KuyrukVeriTipi cikar();
    bool bosmu();
    int kuyrukboyutu=0;
};
#endif 
void Kuyruk::olustur()
{
    bas = NULL;
    son = NULL;
}
void Kuyruk::kapat()
{
    Dugum* p;
    while (bas)
    {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}
void Kuyruk::ekle(KuyrukVeriTipi yeni)
{
    Dugum* yenidugum = new Dugum;
    yenidugum->veri = yeni;
    yenidugum->sonraki = NULL;
    if (bas == NULL)
    {
        bas = yenidugum;
        son = bas;
        kuyrukboyutu++;
    }
    else
    {
       
        son->sonraki = yenidugum;
        son = yenidugum;
        kuyrukboyutu++;
    }
}

KuyrukVeriTipi Kuyruk::cikar()
{
    Dugum* ustdugum;
    KuyrukVeriTipi gecici;
    ustdugum = bas;
    bas = bas->sonraki;
    gecici = ustdugum->veri;
    delete ustdugum;
    kuyrukboyutu--;
    return gecici;
}
bool Kuyruk::bosmu()
{
    return bas == NULL;
}

int main() 
{


}
