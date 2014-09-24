/*
    Ohjelma: Henkilötiedostohallintasysteemi
    Tekijä: Antti Mäkelä
    Kuvaus: Ohjelma kysyy käyttäjältä eri henkilöiden tietoja ja tallentaa ne tietokantaan. Tietokanta voidaan tallentaa tiedostoon.
    Versio: 1

*/

/*
    Tiedosto: main.cpp
    Tarkoitus: Sisältää pääohjelman main() joka hoitaa eri aliohjelmien kutsun pääosin aliohjelman valikko() palauttaman arvon perusteella
*/



#include "maarittely.hpp"

int main()
{
    henkiloLista* lista = luoLista(); // luodaan uusi henkiloLista tietue
    bool poistuOhjelmasta = false; // vielä ei haluta poistua ohjelmasta
    int valinta;

    while (poistuOhjelmasta == false)
    {
        valinta = valikko(); //näytetään valikko ja saadaan vastaus

        std::cout   << "\n---------------------------\n"; //tulostetaan hieno väliviiva

        switch (valinta) //valinta on.....
        {
        case 0: //lopetus
            poistuOhjelmasta = true;
            break;
        case 1:
            lisaaHenkilo(lista);
            break;
        case 2:
            naytaHenkilo(lista);
            break;
        case 3:
            naytaKaikkiHenkilot(lista);
            break;
        case 4:
            poistaHenkilo(lista);
            break;
        case 5:
            tallennaTiedot(lista);
            break;
        case 6:
            lueTiedot(lista);
            break;
        default:
            break; //Ei pitäisi tapahtua...
        }

        std::cin.clear(); //tyhjennetään std::cin mikäli käyttäjä kirjoitti jotain sinne kelpaamatonta
        std::cin.ignore();
    }

    poistaKaikki(lista); // ollaan ystävällisiä ja poistetaan kaikki mikä tilattiin
    delete lista;

    return 0; //palautetaan nolla, koska miksi ei
}
