# VIN-Projekt
## Ideja
Za projekt sem se odločil izdelati preprost sistem za prijavo, ki ga je mogoče uporabiti kot alternativo ključa v stanovalskih poslopjih. Uporabnik se enostavno prijavi z uporabniškim imenom ter geslom preko tipkovnice. Dodal sen tudi možnost dodajanja novih uporabnikov, ki omogoča boljši pregled delovanja. Za prikaz informacij sem uporabil LCD zaslon ter za izboljšanje uporabniške izkušnje sem dodal tudi piskač, ki z zvoki označuje stanje sistema. Vključen je tudi potenciometer, ki nadzira svetlost zaslona.
## Prikaz uporabe naprave (Povezava do videa)
[![Prikaz delovanja](https://img.youtube.com/vi/gqiYvM1Tya4/maxresdefault.jpg)](https://www.youtube.com/gqiYvM1Tya4)
## Shema
![Shema projekta](https://github.com/blazmikec/VIN-Projekt/assets/71345003/2c4dae34-ea9d-4454-bffd-12230f1f8a31)
## Komponenti
| Komponent | Število |
| ------ | ------- |
| Arduino Uno | 1 |
| Piskač (Piezo) | 1 |
| LCD zaslon 16x2 | 1 |
| Potenciometer | 1 |
| Upor 220Ω | 2 |
| Tipkovnica 4x4 | 1 |
## Opis komponent
> # Arduino Uno
> <div> <img src="https://github.com/blazmikec/VIN-Projekt/assets/71345003/d4d6d820-9a51-410d-a3ce-6d286a71a8e7" width=75% height=75%> </div>
> Je zmogljiv mikrokrmilnik, ki omogoča enostavno upravljanje raznolikih vhodno/izhodnih naprav. S pomočjo programskega okolja Arduino IDE lahko enostavno vključujemo že napisane knjižnice za posamezne komponente in odpravljamo morebitne programske napake

> # LCD 16x2
> ![image](https://github.com/blazmikec/VIN-Projekt/assets/71345003/816dd8a9-eac0-429a-960a-5836ec17cc53)
> Zaslon prikazuje dve vrsti ter omogoča prikaz 16 črk na vrstico.
> - VSS: Ta pin je povezan na zemljo (GND), kar zagotavlja referenčno ozemljitev za zaslon.
> - VDD: Povezava na 5V
> - V0: Pin za kontrast (0V) - maksimalen kontrast, (5V) - minimalen kontrast
> - RS: "Register Select" pin določa, ali bo naslednji poslan signal ukaz ali podatek. Ko je postavljen na 0, se pošlje ukazni signal, ko pa je na 1, se pošlje podatek.
> - RW: "Read Write" pin omogoča izbiro med načini pisanja (0) in branja (1) podatkov iz zaslona.
> - E: "Enable" pin omogoča vklop zaslona. Aktiviranje tega pina omogoči izvajanje ukaza ali prenos podatkov.
> - D0-D7: Ti pini tvorijo podatkovno vodilo za LCD. Skozi te pine se prenašajo podatki med krmilnikom in zaslonom, omogočajoč tako izris besedil in grafike.
> - LED+: Anoda za osvetlitev odzadja (3.3V)
> - LED-: Katoda za osvetlitev odzadja (GND)
> # Piskač (Piezo)
> 
> # Potenciometer
> # Tipkovnica 4x4



