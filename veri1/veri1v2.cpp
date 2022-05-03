#include <iostream>



using namespace std;
typedef char yiginveritipi;
struct Yigin
{
    Dugum* bas;
    void kapatt();
    void eklee();
    void olusturr();
    void cikarr();
    bool bosmuu();
    int curr_size=0;
    Kuyruk q1, q2;
    void pop();
    int size();
    int tepe()
};

#ifndef  KUYRUK_H
#define KUYRUK_H
typedef char KuyrukVeriTipi;

struct Dugum
{
    KuyrukVeriTipi veri;
    Dugum* sonraki;
    yiginveritipi veri;
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


void Yigin::kapatt()
{
    Dugum* p;
    while (bas)
    {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}
void Yigin::eklee(yiginveritipi yeni)
{
    Dugum* yenidugum = new Dugum;
    yenidugum->veri = yeni;
    yenidugum->sonraki = bas;
    bas = yenidugum;
}
void Yigin::cikarr()
{
    Dugum* ustdugum;
    yiginveritipi gecici;
    ustdugum = bas;
    bas = bas->sonraki;
    gecici = ustdugum->veri;
    delete ustdugum;
    return gecici;
};


void Yigin::olusturr()
{
    bas = NULL;
};

void Yigin::cikarr()
{
    if (q1.bosmu())
        return;

   
    while (q1.kuyrukboyutu != 1) {
        q2.ekle(q1.bas->sonraki->veri);
        q1.cikar();
    }

    q1.cikar();
    curr_size--;

  
    Kuyruk q = q1;
    q1 = q2;
    q2 = q;
}

void Yigin::eklee(int x)
{
    q1.ekle(x);
    curr_size++;
}

int Yigin::size()
{
    return curr_size;
}

int Yigin::tepe()
{
    if (q1.bosmu())
        return -1;

    while (q1.kuyrukboyutu != 1) {
        q2.ekle(q1.bas->sonraki->sonraki);
        q1.cikar();
    }

    
    int temp = q1.bas->sonraki->veri;

    
 
    q1.cikar();

  
    q2.ekle(temp);

 
    Kuyruk q = q1;
    q1 = q2;
    q2 = q;
    return temp;
}

int main() 
{
    Yigin s;
    s.eklee(1);
    s.eklee(2);
    s.eklee(3);
    s.eklee(4);
    cout<<"zorttt"
    cout << "current size: " << s.size()
        << endl;
    cout << s.tepe() << endl;
    s.cikarr();
    cout << s.tepe() << endl;
    s.pop();
    cout << s.tepe() << endl;
    cout << "current size: " << s.size()
        << endl;
    return 0;

}
