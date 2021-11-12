/*
Znajdź liczbę trójelementowych kombinacji liczb z zadanego ciągu,których suma jest równa zadanej liczbie M
Przyklad:
[1,2,5,1,2,1,2,4]  M=6
-> Liczba kombinacji wynosi 2: [2,2,2], [1,2,4]
*/

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
//zapisywanie elementow tablicy

//deklarowanie zmiennych globalnych
//stała wartość c
const int c = 100;
//tablica pomocnicza
int B[c];
//zmienne pomocnicze
int obecnyIndeks = 0;
//deklaracja funkcji
bool SprawdzCzyKombinacjaIstnieje(int a, int j, int k);
void DodajAktualnaKombinacje(int a, int j, int k);

int main()
{
    // czas rozpoczęcia pracy programu
    auto start = chrono::high_resolution_clock::now();
    ofstream zapis("wyniki.txt");
    //rozmiar głównej tablicy
    const int n = 8;
    //inicjalizacja zmiennych
    int M, ilosc = 0;
    //inicjalizacja tablicy
    int A[n];
    cout << "podaj elementy tablicy " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];//wpisywanie liczb do tablicy
    }
    cout << "Tablica A: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";//wyswietlenie liczb tablicy
    }
    cout << endl;
    cout << "Podaj liczbe M: " << endl;//podanie liczby M
    cin >> M;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] + A[j] + A[k] == M)
                {
                    if (obecnyIndeks == 0 || !SprawdzCzyKombinacjaIstnieje(A[i], A[j], A[k]))
                    {
                        zapis <<"["<< A[i] << "," << A[j] << "," << A[k] <<"]"<< endl; //wyświetlenie znalezionych kombinacji
                        ilosc++;
                        DodajAktualnaKombinacje(A[i], A[j], A[k]);
                    }
                }
            }
        }
    }
    zapis <<"Ilosc kombinacji wynosi: "<< ilosc << endl;//Podanie ilości znalezionych kombinacji
    cout <<"Wyniki zapisano w pliku tekstowym wyniki.txt"<<endl;
    zapis.close ();
    // czas zakończenia pracy programu
    auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;  //obliczenie czasu pracy programu
    cout << "Czas trwania: " << elapsed.count() << " s\n"; //wyświetlenie czasu pracy programu
}
bool SprawdzCzyKombinacjaIstnieje(int a, int j, int k)   //funkcja pomocnicza - sprawdza czy dana kombinacja występuje w ciągu
{
    for (int i = 0; i < obecnyIndeks; i++)
    {
        if (i + 1 < obecnyIndeks)
        {
            if (B[i] == a && B[i + 1] == j && B[i + 2] == k)
                return true;
        }
    }
    return false;
}

void DodajAktualnaKombinacje(int a, int j, int k) //funkcja pomocnicza - likwiduje powtórzenia tych samych kombinacji
{
    B[obecnyIndeks] = a;
    B[obecnyIndeks + 1] = j;
    B[obecnyIndeks + 2] = k;
    obecnyIndeks += 3;
}
