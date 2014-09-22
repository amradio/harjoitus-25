/*
    Tiedosto: maarittely.hpp
    Tekijä: Antti Mäkelä
    Tarkoitus: Esittelee aliohjelmat ja tarvittavat luokat
*/

#include <string>
#include <cassert>
#include <iostream>


/*
Muutama huomautus kuinka listoja käsitellään:
    -henkiloLista tietue on käytännössä vain osoitin listan ensimmäiseen ja viimeiseen jäseneen

    -listaa käydään läpi seuraavalla tavalla

        henkilo* it = lista->ensimmainen;   <-- haetaan osoitin ensimmäiseen jäseneen
        while (it != 0) {                   <-- onko listan jäsen olemassa, eli onko kyseinen osoitin erisuuri kuin 0
            teeAsioita(it*);                <-- jos on, niin sitä voidaan käyttää
            it = it->seuraava;              <-- asetetaan osoittimeen nykyisen jäsenen osoittama seuraava jäsen
        }

    -henkiloLista tietuuen osoitinmuuttujat ensimmainen ja viimeinen osoittavat aina ensimmäiseen ja viimeiseen jäseneen, paitsi jos lista on tyhjä,
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



int valikko(); // palauttaa valinnan numeron, löytyy tiedostosta valikko.cpp

//kaikki muut aliohjelmat löytyvät tiedot.cpp tiedostosta

henkiloLista* luoLista(); //luo uuden henkiloLista tietueen ja alustaa sen oikeilla luvuilla. Listan poistaminen muistettava

void lisaaHenkilo(henkiloLista* lista); //pyytää käyttäjältä uuden henkilön tiedot
void naytaHenkilo(henkiloLista* lista); //näyttää yhden henkilön tiedot
void naytaKaikkiHenkilot(henkiloLista* lista); //näyttää kaikkien henkilöitten tiedot
void poistaHenkilo(henkiloLista* lista); //poistaa yhden henkilön
void tallennaTiedot(henkiloLista* lista); //tallentaa tiedot
void lueTiedot(henkiloLista* lista); //lukee tiedot tiedostosta

void poistaKaikki(henkiloLista* lista); //tyhjentää koko listan henkilöistä




