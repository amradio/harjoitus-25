/*
    Ohjelma: Henkilˆtiedostohallintasysteemi
    Tekij‰: Antti M‰kel‰
    Kuvaus: Ohjelma kysyy k‰ytt‰j‰lt‰ eri henkilˆiden tietoja ja tallentaa ne tietokantaan. Tietokanta voidaan tallentaa tiedostoon.
            K‰‰nnetty MinGW GCC 4.8.1
    Versio: 1




    Tiedosto: main.cpp
    Tarkoitus: Sis‰lt‰‰ p‰‰ohjelman main() joka hoitaa eri aliohjelmien kutsun p‰‰osin aliohjelman valikko() palauttaman arvon perusteella
*/



#include "maarittely.hpp"

int main()
{
    henkiloLista* lista = luoLista(); // luodaan uusi henkiloLista tietue
    bool poistuOhjelmasta = false; // viel‰ ei haluta poistua ohjelmasta
    int valinta;

    while (poistuOhjelmasta == false)
    {
        valinta = valikko(); //n‰ytet‰‰n valikko ja saadaan vastaus

        std::cout   << "\n---------------------------\n"; //tulostetaan hieno v‰liviiva

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
            break; //Ei pit‰isi tapahtua...
        }

        std::cin.clear(); //tyhjennet‰‰n std::cin mik‰li k‰ytt‰j‰ kirjoitti jotain sinne kelpaamatonta
        std::cin.ignore();
    }

    poistaKaikki(lista); // ollaan yst‰v‰llisi‰ ja poistetaan kaikki mik‰ tilattiin
    delete lista;

    return 0; //palautetaan nolla, koska miksi ei
}
