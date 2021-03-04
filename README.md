# Studentų galutinio balo skaičiuoklė
# Programos funkcijos
* Programa suteikia galimybę pasirinkti duomenų įvesties būdą: įvedimas rankomis arba failo nuskaitymas.
* Programa skaičiuoja studentų galutinį balą, kurį sudaro namų darbų pažymių vidurkis bei egzamino pažymys, pagal šią formulę:

![](https://latex.codecogs.com/gif.latex?Galutinis%20%3D%200.4%20*%20vidurkis%20&plus;%200.6%20*%20egzaminas)<br />
Gautas rezultatas pateikiamas šiuo pavidalu:

![](https://user-images.githubusercontent.com/78591148/108546571-fd763780-72f1-11eb-83e8-d9cbd783415e.png)

* Programa skaičiuoja studentų galutinį balą, kurį sudaro namų darbų pažymių mediana bei egzamino pažymys, pagal šią formulę:

![](https://latex.codecogs.com/gif.latex?Galutinis%20%3D%200.4%20*%20mediana%20&plus;%200.6%20*%20egzaminas)<br />
Gautas rezultatas pateikiamas šiuo pavidalu:

![](https://user-images.githubusercontent.com/78591148/108546956-89885f00-72f2-11eb-982e-422914af023f.png)

* Pasirinkus įvesties būdą (įvedimas ranka), galima pasirinkti namų darbų bei egzamino pažymių įvedimą generuojant atsitiktinai arba suvedant rankomis.
* Programa pateikia rezultatus studentų vardų abėcėline tvarka.
# Įsidiegimo bei naudojimosi instrukcija
* Reikia parsisiųsti Vector.cpp failą.
* Atsidaryti šį failą Visual Studio Code IDE.
* Windows Subsystem Linux komandinėje eilutėje reikia subuildinti projektą (g++ -o Vector Vector.cpp).
* Pasileisti programą (./Vector).
* Pasileidus programai reikia nurodyti duomenu įvesties būdą (įvedimas rankomis arba failo nuskaitymas), pasirinkti galutinio balo skaičiavimą pagal vidurkį arba medianą. Jeigu buvo pasirinktas įvedimas rankomis, tuomet reikia dar pasirinkti ar namų darbų ir egzamino pažymiai bus generuojami atsitiktinai ar suvedami ranka, nurodoma ar žinomas namų darbų skaičius. Toliau yra suvedami studentų duomenys atitinkamai: jei buvo pasirinktas namų darbų ir egzamino pažymių atsitiktinis generavimas tai įvedama tik vardas ir pavardė, o jeigu suvedimas ranka - įvedama vardas, pavardė, namų darbų bei egzamino pažymiai. Jeigu buvo pasirinktas įvesties būdas failo nuskaitymas, tai reikia tik pasirinkti būdą, pagal kurį bus skaičiuojamas studentų galutinis balas (vidurkį arba medianą).
