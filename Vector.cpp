#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <random>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;

const int isvesties_plotis = 15;

struct Studentas
{
    std::string vardas, pavarde;
    double egzaminas, galutinis;
    std::vector<double> pazymiai;
};

void pazymiu_generavimas(Studentas *, int, int);
void Isvedimas(Studentas *, int, std::string, std::string, int);

int main()
{
    srand(time(NULL));
    int studentu_kiekis, n;
    std::string vid_med, generavimas, nd_pazymiai, vedimas;
    cout << "Kiek studentu noresite ivesti?" << endl;
    cin >> studentu_kiekis;
    while (!cin || studentu_kiekis < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Studentu kiekis gali buti tik teigiamas skaicius! ";
        cin >> studentu_kiekis;
    }
    if (studentu_kiekis == 0)
    {
        exit(1);
    }
    cout << "Galutiniam balui skaiciuoti naudoti namu darbu vidurki ar mediana? [vid/med]: ";
    cin >> vid_med;
    while (vid_med != "vid" && vid_med != "med")
    {
        cout << "Turite ivesti med arba vid! ";
        cin >> vid_med;
    }
    Studentas *st = new Studentas[studentu_kiekis];
    cout << "Namu darbu bei egzamino pazymius atsitiktinai generuoti? [Taip/Ne]: ";
    cin >> generavimas;
    while (generavimas != "Taip" && generavimas != "Ne")
    {
        cout << "Turite ivesti Taip arba Ne! ";
        cin >> generavimas;
    }
    cout << "Ar zinote kiek studentai turi namu darbu pazymiu? [Taip/Ne]: ";
    cin >> nd_pazymiai;
    while (nd_pazymiai != "Taip" && nd_pazymiai != "Ne")
    {
        cout << "Turite ivesti Taip arba Ne! ";
        cin >> nd_pazymiai;
    }
    if (nd_pazymiai == "Taip")
    {
        cout << "Iveskite studentu namu darbu skaiciu: ";
        cin >> n;
        while (!cin || n < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Namu darbu skaicius gali buti tik teigiamas skaicius! ";
            cin >> n;
        }
    }
    for (int i = 0; i < studentu_kiekis; i++)
    {
        if (nd_pazymiai == "Taip")
        {

            st[i].pazymiai.reserve(n);
            cout << "Iveskite " << i + 1 << " studento varda: ";
            cin >> st[i].vardas;
            cout << "Iveskite " << i + 1 << " studento pavarde: ";
            cin >> st[i].pavarde;
            if (generavimas == "Taip")
            {
                pazymiu_generavimas(st, i, n);
                st[i].egzaminas = 1 + rand() % 10;
            }
            else if (generavimas == "Ne")
            {
                cout << "Suveskite " << i + 1 << " studento namu darbu rezultatus desimtbaleje sistemoje:" << endl;
                for (int j = 0; j < n; j++)
                {
                    cout << j + 1 << " namu darbu pazymys: ";
                    cin >> st[i].pazymiai[j];
                    while (!cin || st[i].pazymiai[j] < 1 || st[i].pazymiai[j] > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                        cin >> st[i].pazymiai[j];
                    }
                }
                cout << "Iveskite " << i + 1 << " studento egzamino pazymi desimtbaleje sistemoje: ";
                cin >> st[i].egzaminas;
                while (!cin || st[i].egzaminas < 1 || st[i].egzaminas > 10)
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Egzamino pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                    cin >> st[i].egzaminas;
                }
            }
        }
        else if (nd_pazymiai == "Ne")
        {
            if (i == 0)
            {
                n = 0;
                cout << "Iveskite " << i + 1 << " studento varda: ";
                cin >> st[i].vardas;
                cout << "Iveskite " << i + 1 << " studento pavarde: ";
                cin >> st[i].pavarde;
                while (true)
                {
                    generavimas == "Taip" ? cout << "Ar generuoti " << n + 1 << " namu darbu pazymi? [Taip/Ne]" << endl : cout << "Ar ivesite " << n + 1 << " namu darbu pazymi? [Taip/Ne]" << endl;
                    cin >> vedimas;
                    if (vedimas == "Ne")
                    {
                        break;
                    }
                    if (generavimas == "Taip")
                    {
                        ++n;
                        st[i].pazymiai.push_back(1 + rand() % 10);
                    }
                    else
                    {
                        ++n;
                        double pazymys;
                        cout << n << " namu darbu pazymys: ";
                        cin >> pazymys;
                        while (!cin || pazymys < 1 || pazymys > 10)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                            cin >> pazymys;
                        }
                        st[i].pazymiai.push_back(pazymys);
                    }
                }
                if (generavimas == "Taip")
                {
                    st[i].egzaminas = 1 + rand() % 10;
                }
                else
                {
                    cout << "Iveskite " << i + 1 << " studento egzamino pazymi desimtbaleje sistmoje: ";
                    cin >> st[i].egzaminas;
                    while (!cin || st[i].egzaminas < 1 || st[i].egzaminas > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Egzamino pazymys turi buti skaicius desimtbaleje sistemoje! ";
                        cin >> st[i].egzaminas;
                    }
                }
            }
            else
            {
                cout << "Iveskite " << i + 1 << " studento varda: ";
                cin >> st[i].vardas;
                cout << "Iveskite " << i + 1 << " studento pavarde: ";
                cin >> st[i].pavarde;
                st[i].pazymiai.reserve(n);
                if (generavimas == "Taip")
                {
                    pazymiu_generavimas(st, i, n);
                    st[i].egzaminas = 1 + rand() % 10;
                }
                else
                {
                    cout << "Suveskite " << i + 1 << " studento namu darbu rezultatus desimtbaleje sistemoje:" << endl;
                    for (int j = 0; j < n; j++)
                    {
                        cout << j + 1 << " namu darbu pazymys: ";
                        cin >> st[i].pazymiai[j];
                        while (!cin || st[i].pazymiai[j] < 1 || st[i].pazymiai[j] > 10)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                            cin >> st[i].pazymiai[j];
                        }
                    }
                    cout << "Iveskite " << i + 1 << " studento egzamino pazymi desimtbaleje sistemoje: ";
                    cin >> st[i].egzaminas;
                    while (!cin || st[i].egzaminas < 1 || st[i].egzaminas > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Egzamino pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                        cin >> st[i].egzaminas;
                    }
                }
            }
        }
    }
    Isvedimas(st, studentu_kiekis, vid_med, generavimas, n);
    delete[] st;
    return 0;
}
void pazymiu_generavimas(Studentas *s, int kelintas, int n)
{
    for (int i = 0; i < n; i++)
    {
        s[kelintas].pazymiai.push_back(1 + rand() % 10);
    }
}
void Isvedimas(Studentas *st, int studentu_kiekis, std::string vid_med, std::string generavimas, int n)
{
    if (generavimas == "Taip" && n != 0)
    {

        for (int i = 0; i < studentu_kiekis; i++)
        {
            cout << i + 1 << " Studento sugeneruoti namu darbu pazymiai: ";
            for (int j = 0; j < n; j++)
            {
                cout << st[i].pazymiai[j] << " ";
            }
            cout << endl;
            cout << i + 1 << " Studento sugeneruotas egzamino pazymys: ";
            cout << st[i].egzaminas << endl;
        }
    }
    else if (generavimas == "Ne" && n != 0)
    {
        for (int i = 0; i < studentu_kiekis; i++)
        {
            cout << i + 1 << " Studento ivesti namu darbu pazymiai: ";
            for (int j = 0; j < n; j++)
            {
                cout << st[i].pazymiai[j] << " ";
            }
            cout << endl;
            cout << i + 1 << " Studento ivestas egzamino pazymys: ";
            cout << st[i].egzaminas << endl;
        }
    }
    if (vid_med == "vid")
    {
        cout << left << setw(isvesties_plotis) << "Pavarde" << left << setw(isvesties_plotis) << "Vardas" << left << setw(isvesties_plotis) << "Galutinis (Vid.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < studentu_kiekis; i++)
        {
            double suma = 0;
            for (int j = 0; j < n; j++)
            {
                suma += st[i].pazymiai[j];
            }
            if (n == 0)
            {
                st[i].galutinis = st[i].egzaminas * 0.6;
                cout << left << setw(isvesties_plotis) << st[i].pavarde << left << setw(isvesties_plotis) << st[i].vardas << left << setw(isvesties_plotis) << fixed << setprecision(2) << st[i].galutinis << endl;
            }
            else
            {
                st[i].galutinis = suma / n * 0.4 + st[i].egzaminas * 0.6;
                cout << left << setw(isvesties_plotis) << st[i].pavarde << left << setw(isvesties_plotis) << st[i].vardas << left << setw(isvesties_plotis) << fixed << setprecision(2) << st[i].galutinis << endl;
            }
        }
    }
    else if (vid_med == "med")
    {
        cout << left << setw(isvesties_plotis) << "Pavarde" << left << setw(isvesties_plotis) << "Vardas" << left << setw(isvesties_plotis) << "Galutinis (Med.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < studentu_kiekis; i++)
        {
            if (n != 0)
            {
                std::sort(st[i].pazymiai.begin(), st[i].pazymiai.end());
                if (n % 2 == 0)
                {
                    cout << st[i].pazymiai[n / 2] << " " << st[i].pazymiai[n / 2 - 1] << endl;
                    st[i].galutinis = (st[i].pazymiai[n / 2 - 1] + st[i].pazymiai[n / 2]) / 2.0 * 0.4 + st[i].egzaminas * 0.6;
                    cout << left << setw(isvesties_plotis) << st[i].pavarde << left << setw(isvesties_plotis) << st[i].vardas << left << setw(isvesties_plotis) << fixed << setprecision(2) << st[i].galutinis << endl;
                }
                else
                {
                    st[i].galutinis = st[i].pazymiai[n / 2] * 0.4 + st[i].egzaminas * 0.6;
                    cout << left << setw(isvesties_plotis) << st[i].pavarde << left << setw(isvesties_plotis) << st[i].vardas << left << setw(isvesties_plotis) << fixed << setprecision(2) << st[i].galutinis << endl;
                }
            }
            else if (n == 0)
            {
                st[i].galutinis = st[i].egzaminas * 0.6;
                cout << left << setw(isvesties_plotis) << st[i].pavarde << left << setw(isvesties_plotis) << st[i].vardas << left << setw(isvesties_plotis) << fixed << setprecision(2) << st[i].galutinis << endl;
            }
        }
    }
}
