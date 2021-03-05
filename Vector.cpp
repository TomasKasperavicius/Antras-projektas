#include <iostream>
#include "funkcijos.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const char* failas = "kursiokai.txt";

int main()
{
    char vid_med, ivestis;
    int ilgiausia_pavarde=0, ilgiausias_vardas=0;
    vector<Studentas> st;
    cout << "Studentu duomenis ivesite ar nuskaitysite is failo? [I/F]: ";
    cin >> ivestis;
    while (char(tolower(ivestis)) != 'i' && char(tolower(ivestis)) != 'f')
    {
        cout << "Turite ivesti i - ivestis rankomis arba f - nuskaitymas is failo! ";
        cin >> ivestis;
    }
    cout << "Galutiniam balui skaiciuoti naudoti namu darbu vidurki ar mediana? [V/M]: ";
    cin >> vid_med;
    while (char(tolower(vid_med)) != 'v' && char(tolower(vid_med)) != 'm')
    {
        cout << "Turite ivesti m - mediana arba v - vidurkis! ";
        cin >> vid_med;
    }
    if (char(tolower(ivestis)) == 'f')
    {

        FailoSkaitymas(st, vid_med, ilgiausia_pavarde, ilgiausias_vardas,failas);
    }
    else
    {
        Ivedimas(st, vid_med, ilgiausia_pavarde, ilgiausias_vardas);
    }
    Isvedimas(st, vid_med, ivestis, ilgiausia_pavarde, ilgiausias_vardas);
    return 0;
}
