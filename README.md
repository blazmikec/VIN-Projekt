# VIN-Projekt
## Ideja
Za projekt sem se odločil izdelati preprost sistem za prijavo, ki ga je mogoče uporabiti kot alternativo ključa v stanovalskih poslopjih. Uporabnik se enostavno prijavi z uporabniškim imenom ter geslom preko tipkovnice. Dodal sen tudi možnost dodajanja novih uporabnikov, ki omogoča boljši pregled delovanja. Za prikaz informacij sem uporabil LCD zaslon ter za izboljšanje uporabniške izkušnje sem dodal tudi piskač, ki z zvoki označuje stanje sistema. Vključen je tudi potenciometer, ki nadzira svetlost zaslona.
## Prikaz uporabe naprave (Povezava do videa)
[![Prikaz delovanja](https://img.youtube.com/vi/gqiYvM1Tya4/maxresdefault.jpg)](https://youtu.be/gqiYvM1Tya4))
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
> <img src="https://github.com/blazmikec/VIN-Projekt/assets/71345003/d4d6d820-9a51-410d-a3ce-6d286a71a8e7" width=75% height=75%>
> 
> Je zmogljiv mikrokrmilnik, ki omogoča enostavno upravljanje raznolikih vhodno/izhodnih naprav. S pomočjo programskega okolja Arduino IDE lahko enostavno vključujemo že napisane knjižnice za posamezne komponente in odpravljamo morebitne programske napake

> # LCD 16x2
> ![image](https://github.com/blazmikec/VIN-Projekt/assets/71345003/816dd8a9-eac0-429a-960a-5836ec17cc53)
>
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
> Je majhna elektronska komponenta, ki pretvarja električne impulze v zvočne valove. S pomočjo pritiska na kristalni material znotraj piskača ustvarja zvočne tone. Pogosto se uporablja za signalizacijo in ustvarjanje preprostih zvočnih učinkov v različnih elektronskih napravah.
> # Potenciometer
> Je nastavljiva elektronska komponenta, ki omogoča uporabniku nadzor nad električnim tokom s spreminjanjem upora. S tem omogoča prilagajanje parametrov, kot svetlost zaslona
> # Tipkovnica 4x4
> <img src="https://github.com/blazmikec/VIN-Projekt/assets/71345003/46abe262-f2e8-44aa-8c7d-f1848f6ee571" width=50% height=50%>
> 
> Je matrika 16 tipk, ki delujejo tako, da se ob pritisku vzpostavi stik med vrstico in stolpcem. To sproži električni signal, ki se prepozna in omogoča uporabniku vnos podatkov ali izvajanje ukazov. Ima 8 izhodnih pinov (4 vrstice in 4 stolpce), ki so povezani s tipkami.



