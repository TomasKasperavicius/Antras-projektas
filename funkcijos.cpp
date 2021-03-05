#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <random>
#include <sstream>
#include <fstream>
#include "funkcijos.hpp"

using std::left;
using std::fixed;
using std::setprecision;
using std::setw;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

double GalutinisBalas(Studentas &st, char vid_med)
{
    if (char(tolower(vid_med)) == 'v')
    {
        double suma = 0;
        for (int j = 0; j < st.pazymiai.size(); j++)
        {
            suma += st.pazymiai[j];
        }
        if (st.pazymiai.size() == 0)
        {
            return st.egzaminas * 0.6;
        }
        else
        {
            return suma / st.pazymiai.size() * 0.4 + st.egzaminas * 0.6;
        }
    }
    else
    {
        if (st.pazymiai.size() == 0)
        {
            return st.egzaminas * 0.6;
        }
        else
        {
            
            std::sort(st.pazymiai.begin(), st.pazymiai.end());
            if (st.pazymiai.size() % 2 == 0)
            {
                return (st.pazymiai[st.pazymiai.size() / 2 - 1] + st.pazymiai[st.pazymiai.size() / 2]) / 2.0 * 0.4 + st.egzaminas * 0.6;
            }
            else
            {
                return st.pazymiai[st.pazymiai.size() / 2] * 0.4 + st.egzaminas * 0.6;
            }
        }
    }
    return 0;
}
void PazymiuGeneravimas(Studentas &st, int n)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    for (int i = 0; i < n; i++)
    {
        st.pazymiai.push_back(dist(mt));
    }
    st.egzaminas = dist(mt);
}
void Isvedimas(vector<Studentas> &st, char vid_med, char ivestis, int ilgiausia_pavarde,int ilgiausias_vardas)
{
    std::sort(st.begin(),st.end());
    std::string vid="Galutinis (Vid.)",med="Galutinis (Med.)";
    int v_plotis=ilgiausias_vardas+2<6?8:ilgiausias_vardas+2,pav_plotis=ilgiausia_pavarde+1<7?8:ilgiausia_pavarde+1;
    if (char(tolower(vid_med)) == 'v')
    {
        if(char(tolower(ivestis)) == 'i')
        {
        cout << left << setw(pav_plotis) << "Pavarde " << left << setw(v_plotis) << "Vardas " << left << setw(vid.size()) << vid << endl;
        for(int i=0;i<v_plotis+pav_plotis+vid.size();i++)
        {
            cout << "-";
        }
        cout << endl;
        for (auto &i:st)
        {
            cout << left << setw(pav_plotis) << i.pavarde << left << setw(v_plotis) << i.vardas << left << setw(vid.size()) << fixed << setprecision(2) << i.galutinis << endl;
        }
        }
        else
        {
            std::fstream f("Rezultatai.txt", std::ios::out);
            f << left << setw(pav_plotis) << "Pavarde " << left << setw(v_plotis) << "Vardas " << left << setw(vid.size()) << vid << endl;
            for(int i=0;i<v_plotis+pav_plotis+vid.size();i++)
            {
                f <<"-";
            }
            f << endl;
            for (auto &i:st)
            {
                f << left << setw(pav_plotis) << i.pavarde << left << setw(v_plotis) << i.vardas << left << setw(vid.size()) << fixed << setprecision(2)<<i.galutinis <<endl;
            }
            f.close();
        }
    }
    else
    {
        if(char(tolower(ivestis)) == 'i')
        {
        cout << left << setw(pav_plotis) << "Pavarde " << left << setw(v_plotis) << "Vardas " << left << setw(med.size()) << med << endl;
        for(int i=0;i<v_plotis+pav_plotis+vid.size();i++)
        {
            cout << "-";
        }
        cout << endl;
        for (auto &i:st)
        {
            cout << left << setw(pav_plotis) << i.pavarde << left << setw(v_plotis) << i.vardas << left << setw(med.size()) << fixed << setprecision(2) << i.galutinis << endl;
        }
        }
        else
        {
            std::fstream f("Rezultatai.txt", std::ios::out);
            f << left << setw(pav_plotis) << "Pavarde " << left << setw(v_plotis) << "Vardas " << left << setw(med.size()) << med << endl;
            for(int i=0;i<v_plotis+pav_plotis+vid.size();i++)
            {
                f <<"-";
            }
            f << endl;
            for (auto &i:st)
            {
                f << left << setw(pav_plotis) << i.pavarde << left << setw(v_plotis) << i.vardas << left << setw(med.size()) << fixed << setprecision(2)<<i.galutinis << endl;
            }
            f.close();
        }
    }
}
void FailoSkaitymas(vector<Studentas> &st, char vid_med, int &ilgiausia_pavarde, int &ilgiausias_vardas,const char* failas)
{
    std::fstream f;
    f.open(failas, std::ios::in);
    std::string failo_turinys((std::istreambuf_iterator<char>(f)), (std::istreambuf_iterator<char>()));
    try
    {
        if (!f)
        {
            throw "Nepavyko atidaryti failo!"; 
        }
    }
    catch(const char* zinute)
    {
        std::cerr << zinute << endl;
        exit(1);
    }
    f >> failo_turinys;
    f.close();
    Studentas stud;
    vector<double> pazymiai;
    std::string eilute="";
    for (int i = 0; i < failo_turinys.size(); i++)
    {
        eilute += failo_turinys[i];
        if (failo_turinys[i] == '\n')
        {
            break;
        }
        if (eilute.size() == failo_turinys.size())
        {
            exit(1);
        }
    }
    int eil_ilgis = eilute.size(), eilutes_numeris=1;
    eilute.clear();
    for (int i = eil_ilgis; i < failo_turinys.size(); i++)
    {
        eilute += failo_turinys[i];
        if (failo_turinys[i] == '\n'||i==failo_turinys.size()-1)
        {
        ++eilutes_numeris;
        std::stringstream ss(eilute);
        std::string temp;
        ss >> stud.vardas >> stud.pavarde;
        while(ss>>temp)
        {
            int skaiciai=0;
            for(char &c:temp)
            {
                if(isdigit(c))
                {
                    skaiciai++;
                }
            }
            try
            {
            if(skaiciai==temp.size())
            {
            std::stringstream skaicius(temp);
            double pazymys;
            skaicius>>pazymys;
            if(pazymys<1||pazymys>10)
            {
                std::ostringstream os;
                os << eilutes_numeris;
                throw os.str()+" failo eiluteje buvo rastas pazymys, kuris neatitinka intervalo [1,10]!";  
            }
            pazymiai.push_back(pazymys);
            }
            else
            {
                std::ostringstream os;
                os << eilutes_numeris;
                throw os.str()+" failo eiluteje buvo rastas pazymys, sudarytas is simboliu!";
            }
            }catch(std::string zinute)
            {
                std::cerr << zinute << endl;
                exit(1);
            }
        }
        try
        {
            if(pazymiai.size()==0)
            {
                std::ostringstream os;
                os << eilutes_numeris;
                throw os.str()+" failo eiluteje yra studentas neturi pazymiu";
            }
            for(int j=0;j<pazymiai.size()-1;j++)
            {
                stud.pazymiai.push_back(pazymiai[j]);
            }
            stud.egzaminas=pazymiai[pazymiai.size()-1];
            stud.galutinis=GalutinisBalas(stud,vid_med);
        }
        catch(std::string zinute)
        {
            std::cerr << zinute << endl;
            exit(1);
        }
        if(stud.vardas.size()>ilgiausias_vardas)
        {
            ilgiausias_vardas=stud.vardas.size();
        }
        if(stud.pavarde.size()>ilgiausia_pavarde)
        {
            ilgiausia_pavarde=stud.pavarde.size();
        }
        st.push_back(stud);
        stud.pazymiai.clear();
        eilute.clear();
        pazymiai.clear();
        }
    }
    if(st.empty())
    {
        cout << "Failas yra tuscias!"<<endl;
        exit(1);
    }
}
void Ivedimas(vector<Studentas> &st, char vid_med, int &ilgiausia_pavarde,int &ilgiausias_vardas)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    int n = 0;
    char nd_pazymiai, vedimas, prideti_studenta, generavimas;
    cout << "Namu darbu bei egzamino pazymius atsitiktinai generuoti? [T/N]: ";
    cin >> generavimas;
    while (char(tolower(generavimas)) != 't' && char(tolower(generavimas)) != 'n')
    {
        cout << "Turite pasirinkti ar pazymius generuoti - t ar ne - n! ";
        cin >> generavimas;
    }
    cout << "Ar zinote kiek studentai turi namu darbu pazymiu? [T/N]: ";
    cin >> nd_pazymiai;
    while (char(tolower(nd_pazymiai)) != 't' && char(tolower(nd_pazymiai)) != 'n')
    {
        cout << "Turite ivesti t - jei zinote studento namu darbu skaiciu arba n, jei nezinote! ";
        cin >> nd_pazymiai;
    }
    if (char(tolower(nd_pazymiai)) == 't')
    {
        cout << "Iveskite studentu namu darbu skaiciu: ";
        cin >> n;
        while (!cin || n < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Namu darbu skaicius gali buti tik teigiamas skaicius ir nelygus nuliui! ";
            cin >> n;
        }
    }
    Studentas stud;
    double pazymys;
    while (true)
    {
        st.size() == 0 ? cout << "Ar prideti pirma studenta? [T/N]" << endl : cout << "Ar prideti dar viena studenta? [T/N]" << endl;
        cin >> prideti_studenta;
        while (char(tolower(prideti_studenta)) != 't' && char(tolower(prideti_studenta)) != 'n')
        {
            cout << "Turite ivesti t - prideti studenta arba n - neprideti! ";
            cin >> prideti_studenta;
        }
        if (char(tolower(prideti_studenta)) == 'n')
        {
            break;
        }
        if (char(tolower(nd_pazymiai)) == 't')
        {
            stud.pazymiai.reserve(n);
            cout << "Iveskite studento varda: ";
            cin >> stud.vardas;
            cout << "Iveskite studento pavarde: ";
            cin >> stud.pavarde;
            if (char(tolower(generavimas)) == 't')
            {
                PazymiuGeneravimas(stud, n);
            }
            else
            {
                cout << "Suveskite studento namu darbu rezultatus desimtbaleje sistemoje:" << endl;
                for (int j = 0; j < n; j++)
                {
                    cout << j + 1 << " namu darbu pazymys: ";
                    cin >> pazymys;
                    while (!cin || pazymys < 1 || pazymys > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                        cin >> pazymys;
                    }
                    stud.pazymiai.push_back(pazymys);
                }
                cout << "Iveskite studento egzamino pazymi desimtbaleje sistemoje: ";
                cin >> stud.egzaminas;
                while (!cin || stud.egzaminas < 1 || stud.egzaminas > 10)
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Egzamino pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                    cin >> stud.egzaminas;
                }
            }
            stud.galutinis=GalutinisBalas(stud, vid_med);
            if(stud.vardas.size()>ilgiausias_vardas)
            {
                ilgiausias_vardas=stud.vardas.size();
            }
            if(stud.pavarde.size()>ilgiausia_pavarde)
            {
                ilgiausia_pavarde=stud.pavarde.size();
            }
            st.push_back(stud);
            stud.pazymiai.clear();
        }
        else
        {
            if (st.size() == 0)
            {
                cout << "Iveskite studento varda: ";
                cin >> stud.vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> stud.pavarde;
                while (true)
                {
                    char(tolower(generavimas)) == 't' ? cout << "Ar generuoti " << n + 1 << " namu darbu pazymi? [T/N]" << endl : cout << "Ar ivesite " << n + 1 << " namu darbu pazymi? [T/N]" << endl;
                    cin >> vedimas;
                    while (char(tolower(vedimas)) != 't' && char(tolower(vedimas)) != 'n')
                    {
                        char(tolower(generavimas)) == 't' ? cout << "Turite ivesti t, jei norite generuoti pazymi, n, jei nenorite generuoti pazymio " << endl : cout << "Turite ivesti t, jei norite ivesti pazymi, n, jei nevesite pazymio" << endl;
                        cin >> vedimas;
                    }
                    if (char(tolower(vedimas)) == 'n')
                    {
                        break;
                    }
                    if (char(tolower(generavimas)) == 't')
                    {
                        ++n;
                        stud.pazymiai.push_back(dist(mt));
                    }
                    else
                    {
                        ++n;
                        cout << n << " namu darbu pazymys: ";
                        cin >> pazymys;
                        while (!cin || pazymys < 1 || pazymys > 10)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                            cin >> pazymys;
                        }
                        stud.pazymiai.push_back(pazymys);
                    }
                }
                if (char(tolower(generavimas)) == 't')
                {
                    stud.egzaminas = dist(mt);
                }
                else
                {
                    cout << "Iveskite studento egzamino pazymi desimtbaleje sistmoje: ";
                    cin >> stud.egzaminas;
                    while (!cin || stud.egzaminas < 1 || stud.egzaminas > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Egzamino pazymys turi buti skaicius desimtbaleje sistemoje! ";
                        cin >> stud.egzaminas;
                    }
                }
                stud.galutinis=GalutinisBalas(stud, vid_med);
                if(stud.vardas.size()>ilgiausias_vardas)
                {
                    ilgiausias_vardas=stud.vardas.size();
                }
                if(stud.pavarde.size()>ilgiausia_pavarde)
                {
                    ilgiausia_pavarde=stud.pavarde.size();
                }
                st.push_back(stud);
                stud.pazymiai.clear();
            }
            else
            {
                stud.pazymiai.reserve(n);
                cout << "Iveskite studento varda: ";
                cin >> stud.vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> stud.pavarde;
                if (char(tolower(generavimas)) == 't')
                {
                    PazymiuGeneravimas(stud, n);
                }
                else
                {
                    cout << "Suveskite studento namu darbu rezultatus desimtbaleje sistemoje:" << endl;
                    for (int j = 0; j < n; j++)
                    {
                        cout << j + 1 << " namu darbu pazymys: ";
                        cin >> pazymys;
                        while (!cin || pazymys < 1 || pazymys > 10)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Namu darbo pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                            cin >> pazymys;
                        }
                        stud.pazymiai.push_back(pazymys);
                    }
                    cout << "Iveskite studento egzamino pazymi desimtbaleje sistemoje: ";
                    cin >> stud.egzaminas;
                    while (!cin || stud.egzaminas < 1 || stud.egzaminas > 10)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Egzamino pazymys gali buti tik skaicius desimtbaleje sistemoje! ";
                        cin >> stud.egzaminas;
                    }
                }
                stud.galutinis=GalutinisBalas(stud, vid_med);
                if(stud.vardas.size()>ilgiausias_vardas)
                {
                    ilgiausias_vardas=stud.vardas.size();
                }
                if(stud.pavarde.size()>ilgiausia_pavarde)
                {
                    ilgiausia_pavarde=stud.pavarde.size();
                }
                st.push_back(stud);
                stud.pazymiai.clear();
            }
        }
    }
    if(st.empty())
    {
        exit(1);
    }
}
