#include <iostream>
using namespace std;
class Stos//struktura danych jako obiekt
{
  private:
     int wierzcholek;
     int tab[6];
  public:
    Stos()//konstuktor-tworzy tablice na stosu
    {
        wierzcholek=-1;//wierzcho³ek stosu
        for (int i=0;i<6;i++)
        {
            tab[i]=0;
        }
    }
    void dodaj (int wartosc)//operacja dodawania elementów
    {
        if(Czy_jest_pelny())
        {
            cout<<"Stos jest juz pelny"<<endl;
        }
        else
        {
            wierzcholek++;
            tab[wierzcholek]=wartosc;
        }
    }
    int usun()//operacja usuwania elementów
    {
        if(Czy_jest_pusty())
        {
            cout <<"Stos jest juz pusty"<<endl;
        }
        else
        {
            int usuwana_wartosc = tab[wierzcholek];
            tab[wierzcholek]=0;
            wierzcholek--;
            return usuwana_wartosc;
        }
    }
    bool Czy_jest_pelny()//operacja sprawdzaj¹ca czy stos jest pe³ny
    {
        if(wierzcholek==5)
            return true;
        else
            return false;
    }
    bool Czy_jest_pusty()//operacja sprawdzaj¹ca czy stos jest pusty
    {
        if(wierzcholek==-1)
            return true;
        else
            return false;
    }
    int zlicz()//operacja zliczaj¹ca elementy stosu
    {
        return(wierzcholek+1);
    }
    int wyszukaj(int pozycja)//operacja wyszukuj¹ca dany element stosu
    {
         if(Czy_jest_pusty())
        {
            cout <<"Stos jest pusty"<<endl;
        }
        else
        {
            return tab[pozycja];
        }
    }
    void wyswietl()//operacja wyœwietlaj¹ca elementy stosu
    {
        cout <<"Elementy stosu to:"<<endl;
        for(int i=5;i>=0;i--)
        {
            cout<<tab[i]<<endl;
        }
    }
};

int main()
{
    Stos s1;
    int opcja,pozycja,wartosc;
        cout <<"Jaka operacje chcesz wykonac? Wcisnij 0 aby wyjsc."<<endl;
        cout <<"1.Dodaj element"<<endl;
        cout <<"2.Usun element"<<endl;
        cout <<"3.Sprawdz czy zbior jest pelny"<<endl;
        cout <<"4.Sprawdz czy zbior jest pusty"<<endl;
        cout <<"5.Sprawdz ile jest elementow w zbiorze"<<endl;
        cout <<"6.Wyszukaj zadany element zbioru"<<endl;
        cout <<"7.Wyswietl zbior"<<endl;
        cout <<"8.Wyczysc ekran"<<endl;
        //prosty interfejs pozwalaj¹cy u¿ytkownikowi na personalizacjê stosu
    do{
        cin>>opcja;
        switch(opcja)
        {
        case 1://dodanie elementu
            cout<<"Jaki element chcesz dodac?"<<endl;
            cin>>wartosc;
            s1.dodaj(wartosc);
            break;
        case 2://usuniêcie elementu
            cout<<"Usunieto element "<<s1.usun()<<endl;
            break;
        case 3://sprawdzenie czy stos jest pe³ny
            if (s1.Czy_jest_pelny())
            {
                cout <<"Stos jest pelny"<<endl;
            }
            else
            {
                cout <<"Stos nie jest pelny"<<endl;
            }
            break;
        case 4://sprawdzenie czy stos jest pisty
            if (s1.Czy_jest_pusty())
            {
                cout <<"Stos jest pusty"<<endl;
            }
            else
            {
                cout <<"Stos nie jest pusty"<<endl;
            }
            break;
            case 5://zliczenie elementów stosu
            cout<<"Elementow w stosie jest "<<s1.zlicz()<<endl;
            break;
        case 6://wyszukanie danego elememtu stosu
            cout <<"Element na jakiej pozycji chcesz wyszukac?"<<endl;
            cin>>pozycja;
            cout<<"Ten element to "<<endl<<s1.wyszukaj(pozycja)<<endl;
            break;
        case 7://wyœwietlenie elementu stosu
            s1.wyswietl();
            break;
        case 8://wyczyszczenie ekranu
            system("cls");
            break;
        default:
            cout <<"Jaka operacje chcesz wykonac?"<<endl;
        }
        }while (opcja!=0);//wybranie opcji 0 spowoduje zakoñczenie dzia³ania programu
    return 0;
}
