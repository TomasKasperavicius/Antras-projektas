#ifndef FUNKCIJOS_HPP
#define FUNKCIJOS_HPP
#include <vector>
#include <string>

struct Studentas
{
    std::string vardas, pavarde;
    double egzaminas, galutinis;
    std::vector<double> pazymiai;
    bool operator<(const Studentas& st) const
    {
        return (vardas < st.vardas);
    }
};
double GalutinisBalas(Studentas&, char);
void PazymiuGeneravimas(Studentas&, int);
void Isvedimas(std::vector<Studentas>&, char, char, int, int);
void FailoSkaitymas(std::vector<Studentas> &, char, int&, int&,const char*);
void Ivedimas(std::vector<Studentas>&, char, int&, int&);
#endif
