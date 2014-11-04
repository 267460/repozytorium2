#include<iostream>
#include<ctime>
#include<cstring>
#include<list>
using namespace std;


class IPolaczenie{
public:
    virtual list<string> pobierzSzczegoly()=0;
      virtual void drukuj ()=0;
};
class Wydruk {
public:
    static void drukujPolaczenie(Polaczenie p);
};

class Wyszukiwanie
{
private:
    string przystanekPoczatkowy;
    string przystanekKonczowy;
    int liczbaPrzesiadek;
    time_t data;
public:
    Wyszukiwanie(string pP, string pK, time_t d, int lP ){
    przystanekPoczatkowy= pP;
    przystanekKonczowy=pK;
    liczbaPrzesiadek=lP;
    data=d;
    };
    list <IPolaczenie> szukajPolaczenia();
};


class Polaczenie:IPolaczenie{
private:
    time_t czasOdjazdu;
    time_t czasPrzyjazdu;
    string miejscePrzyjazdu;
    string miejsceOdjazdu;
public:
    Polaczenie(time_t cO, time_t cP, string mP, string mO){
    czasOdjazdu=cO;
    czasPrzyjazdu=cP;
    miejscePrzyjazdu=mP;
    miejsceOdjazdu=mO;
    };
    list<string> pobierzSzczegoly();
    void drukuj(){
        Wydruk::drukujPolaczenie(*this);
    }

};


class PolaczenieBezposrednie:Polaczenie {
private:
    float dlugoscTrasy;
    float prowizorycznaCenaBiletu;
    time_t czasOdjazdu;
public:
    PolaczenieBezposrednie(time_t cO, time_t cP, string mP, string mO, float dT, float pCB):Polaczenie(cO,cP,mP,mO), dlugoscTrasy(dT), prowizorycznaCenaBiletu(pCB){}
    list<string> pobierzSzczegoly();
    void drukuj();
};
class MiejscePrzesiadki{
private:
    string miejscowosc;
    int peronPrzyjazdu;
    int peronOdjazdu;
public:
    MiejscePrzesiadki (string m, int pP, int pO ) {
    miejscowosc=m;
    peronPrzyjazdu=pP;
    peronOdjazdu=pO;
    }

};
class PolaczeniePosrednie:Polaczenie{
private:
    string miejscowosc;
    time_t czasPrzesiadki;
    MiejscePrzesiadki miejscePrzesiadki;
public:
    PolaczeniePosrednie(time_t cO, time_t cP, string mP, string mO, MiejscePrzesiadki miejsce, time_t czasP):Polaczenie(cO,cP,mP,mO),miejscePrzesiadki(miejsce), czasPrzesiadki(czasP){}
    list <string> pobierzSzczegoly();
    void drukuj();
};



int main ()
{
    return 0;
}
