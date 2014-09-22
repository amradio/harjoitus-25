/*
    Tiedosto: maarittely.hpp
    Tekij�: Antti M�kel�
    Tarkoitus: Esittelee aliohjelmat ja tarvittavat luokat
*/

#include <string>
#include <cassert>
#include <iostream>


/*
Muutama huomautus kuinka listoja k�sitell��n:
    -henkiloLista tietue on k�yt�nn�ss� vain osoitin listan ensimm�iseen ja viimeiseen j�seneen

    -listaa k�yd��n l�pi seuraavalla tavalla

        henkilo* it = lista->ensimmainen;   <-- haetaan osoitin ensimm�iseen j�seneen
        while (it != 0) {                   <-- onko listan j�sen olemassa, eli onko kyseinen osoitin erisuuri kuin 0
            teeAsioita(it*);                <-- jos on, niin sit� voidaan k�ytt��
            it = it->seuraava;              <-- asetetaan osoittimeen nykyisen j�senen osoittama seuraava j�sen
        }

    -henkiloLista tietuuen osoitinmuuttujat ensimmainen ja viimeinen osoittavat aina ensimm�iseen ja viimeiseen j�seneen, paitsi jos lista on tyhj�,
    jolloin ne ovat 0

*/


typedef struct _henkilo
{
    std::string nimi;
    int hatunKoko;
    float koulumatka;
    _henkilo* seuraava;
    _henkilo* edellinen;
} henkilo;

typedef struct
{
    henkilo* ensimmainen;
    henkilo* viimeinen;
} henkiloLista;



int valikko(); // palauttaa valinnan numeron, l�ytyy tiedostosta valikko.cpp

//kaikki muut aliohjelmat l�ytyv�t tiedot.cpp tiedostosta

henkiloLista* luoLista(); //luo uuden henkiloLista tietueen ja alustaa sen oikeilla luvuilla. Listan poistaminen muistettava

void lisaaHenkilo(henkiloLista* lista); //pyyt�� k�ytt�j�lt� uuden henkil�n tiedot
void naytaHenkilo(henkiloLista* lista); //n�ytt�� yhden henkil�n tiedot
void naytaKaikkiHenkilot(henkiloLista* lista); //n�ytt�� kaikkien henkil�itten tiedot
void poistaHenkilo(henkiloLista* lista); //poistaa yhden henkil�n
void tallennaTiedot(henkiloLista* lista); //tallentaa tiedot
void lueTiedot(henkiloLista* lista); //lukee tiedot tiedostosta

void poistaKaikki(henkiloLista* lista); //tyhjent�� koko listan henkil�ist�




