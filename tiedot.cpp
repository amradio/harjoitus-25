/*
    Tiedosto: tiedot.cpp
    Tekij‰: Antti M‰kel‰
    Tarkoitus: Sis‰lt‰‰ useita aliohjelmia tietokannan hallintaan
*/

#include <fstream>

#include "maarittely.hpp"


henkiloLista* luoLista()
{
    henkiloLista* lista = new henkiloLista;
    lista->ensimmainen = 0;
    lista->viimeinen = 0;
    return lista;
}

henkilo* luoHenkilo(henkiloLista* lista)
{
    henkilo* uusi = new henkilo;

    uusi->seuraava = 0; //uudella j‰senell‰ ei ole seuraavaa j‰sent‰

    if (lista->ensimmainen == 0) // jos lista on tyhj‰:
    {
        lista->ensimmainen = uusi; //aseta uusi j‰sen ensimm‰iseksi...
        lista->viimeinen = uusi; //...ja viimeiseksi j‰seneksi
        uusi->edellinen = 0;  //uudella ja ainoalla j‰senell‰ ei ole t‰llˆin edelt‰v‰‰ j‰sent‰ listassa

    }
    else //jos lista ei ole tyhj‰
    {

        lista->viimeinen->seuraava = uusi; // linkitet‰‰n nykyinen viimeinen j‰sen ja uusi j‰sen yhteen
        uusi->edellinen = lista->viimeinen;
        lista->viimeinen = uusi; // uusi j‰sen on nyt listan viimeinen
    }

    return uusi;
}

void lisaaHenkilo(henkiloLista* lista)
{
    henkilo* uusi = luoHenkilo(lista);

    std::cin.clear();
    std::cin.ignore();

    std::cout << "\n";
    std::cout << "Anna nimi: ";
    std::getline(std::cin, uusi->nimi); //voidaan lukea nimi‰ joissa on v‰lej‰ toisin kuin perus >> operaattorilla

    std::cout << "\n";
    std::cout << "Anna koulumatka: ";
    std::cin >> uusi->koulumatka;

    std::cout << "\n";
    std::cout << "Anna hatun koko: ";
    std::cin >> uusi->hatunKoko;

}
henkilo* haeHenkiloNumerolla(henkiloLista* lista, int i) // hakee listasta n:nnen j‰senen alkaen nollasta
{
    henkilo* it = lista->ensimmainen;
    while (it != 0)
    {
        if (i==0)
            return it;
        i--;
        it = it->seuraava;
    }
    assert(0); //lista loppui kesken, virheellist‰ toimintaa
}

henkilo* kysyHenkilo(henkiloLista* lista)
{

    // Tulostetaan listassa olevat nimet joista k‰ytt‰j‰ voi valita

    int maara = 1;
    henkilo* it = lista->ensimmainen;
    while (it != 0)
    {
        std::cout << maara << ". " << it->nimi << "\n"; //tulostetaan sijainti listassa (maara) ja pelk‰st‰‰n henkilˆn nimi

        maara++;
        it = it->seuraava;
    }
    std::cout << "0. peruuta \n"; //ja jos k‰ytt‰j‰‰ ei kiinnostakkaan

    int valinta;
    while (true) // j‰lleen karhutaan vastausta loputtomiin
    {
        std::cin >> valinta;

        if (valinta == 0)
            return 0;

        if (valinta > 0)
            if (valinta < maara)
            {
                // vastaus hyv‰ksytty, jatketaan ohjelmaa poistumalla
                break;
            }

    }
    return haeHenkiloNumerolla(lista,valinta-1); //miinustetaan valinnasta yksi koska tietokoneessa listat alkaa nollasta eik‰ yhdest‰

}



void naytaHenkilo(henkiloLista* lista)
{
    std::cout << "Valitse n‰ytett‰v‰ henkilˆ\n";
    henkilo* hlo = kysyHenkilo(lista);
    if (hlo) //jos kysyHenkilo palautti jotain muuta kuin NULL pointterin (k‰ytt‰j‰ vastasi peruuta)
    {
        std::cout << "\n";
        std::cout << "Nimi: " << hlo->nimi << "\n";
        std::cout << "Koulumatka: " << hlo->koulumatka << "\n";
        std::cout << "Hatun koko: " << hlo->hatunKoko << "\n";
    }

}

void naytaKaikkiHenkilot(henkiloLista* lista)
{
    henkilo* it = lista->ensimmainen;
    int maara = 1;
    while (it != 0) //kelataan listan l‰pi ja tulostetaan kasa tietoja
    {
        std::cout << maara++ << ". "  <<  "Nimi: " << it->nimi << "\n";
        std::cout << "Koulumatka: " << it->koulumatka << "\n";
        std::cout << "Hatun koko: " << it->hatunKoko << "\n"; //hatun koko, miksi?

        it = it->seuraava;
    }

}

void poistaKaikki(henkiloLista* lista)
{
    henkilo* it = lista->ensimmainen;
    henkilo* poista;
    int maara = 0;
    while (it != 0) // iteroidaan listan l‰pi ja poistetaan aina edellinen j‰sen
    {
        poista = it;
        it = it->seuraava;
        delete poista; //lopputuloksena kaikki j‰senet poistettu
        maara++;
    }

    lista->ensimmainen = 0; //nollataan lista
    lista->viimeinen = 0;
}



void poistaHenkilo(henkiloLista* lista)
{
    std::cout << "Valitse poistettava henkilˆ\n";
    henkilo* hlo = kysyHenkilo(lista);

    if (hlo) //vastasiko k‰ytt‰j‰ muuta kuin peruuta
    {


        if (hlo->edellinen) //onko valitulla j‰senell‰ edellinen j‰sen? (listan keskell‰ tai lopussa)
        {
            hlo->edellinen->seuraava = hlo->seuraava; //yhdistet‰‰n edellinen j‰sen seuraavaan
        }
        else // listan ensimm‰inen j‰sen valittu poistoon
        {
            lista->ensimmainen = hlo->seuraava; //asetetaan uusi ensimm‰inen j‰sen (poikkeustapauksessa hlo->seuraava = 0, eli lista on operaation j‰lkeen tyhj‰)
        }

        if (hlo->seuraava) //onko valitulla j‰senell‰ seuraava j‰sen? (listan keskell‰ tai alussa)
        {
            hlo->seuraava->edellinen = hlo->edellinen; // linkitet‰‰n seuraava edelliseen
        }
        else // listan viimeinen j‰sen valittu poistoon
        {
            lista->viimeinen = hlo->edellinen; //poistettavan edellinen j‰sen on uusi listan viimeinen (poikkeustapauksessa listan viimeiseksi asetetaan 0 kun lista on tyhj‰)
        }


        delete hlo; // pyyhit‰‰n roskat poistamalla tietue
    }

}

void tallennaTiedot(henkiloLista* lista)
{
    std::ofstream tiedosto; //k‰ytet‰‰n c++ tarjoamia fstream olioita
    tiedosto.open("tiedot.txt");  //avataan tekstimuodossa

    if (!tiedosto) // jos tiedosto ei auennut jostain syyst‰
    {
        std::cout << "Tapahtui virhe avatessa tiedostoa 'tiedot.txt'\n";
        return; //poistutaan
    }

    henkilo* it = lista->ensimmainen; //iteroidaan listan l‰pi...
    int i = 0;
    while (it != 0)
    {
        tiedosto << it->nimi << std::endl; //... ja tyˆnnet‰‰n kaikki data tiedostoon, riviv‰lein
        tiedosto << it->koulumatka << std::endl;
        tiedosto << it->hatunKoko << std::endl;
        it = it->seuraava;
        i++;
    }

    tiedosto.close(); //suljetaan tiedosto, turhaan kyll‰kin (ofstreamin destruktori hoitaa)


    std::cout << i << " tietuetta tallennettu tiedostoon 'tiedot.txt'\n";


}

void lueTiedot(henkiloLista* lista)
{

    //Kysyt‰‰n k‰ytt‰j‰lt‰ jos h‰n haluaa korvata, vai lis‰t‰ tietoja

    std::cout << "1. Lis‰‰ tiedostosta\n";
    std::cout << "2. Korvaa tiedostosta\n";
    std::cout << "0. Peruuta \n";

    int valinta = 0;

    while (true)
    {
        std::cin >> valinta;
        if (valinta == 0)
            return;
        if (valinta > 0 && valinta < 3)
            break;
    }


    std::ifstream tiedosto;

    tiedosto.open("tiedot.txt"); //avataan tekstitiedostona



    if (!tiedosto) // jos tiedosto ei auennut jostain syyst‰
    {
        std::cout << "Tapahtui virhe avatessa tiedostoa 'tiedot.txt'\n";
        return; //poistutaan
    }
    if (valinta == 2)  //k‰ytt‰j‰ valitsi tiedostojen korvaamisen
        poistaKaikki(lista); //eli poistetaan kaikki ennen listaan lis‰‰mist‰





    //m‰‰ritell‰‰n jotain muuttujia
    int i = 0;
    std::string nimi;
    float koulumatka;
    int hatunKoko;

    while (!tiedosto.eof())
    {

        std::getline(tiedosto,nimi); //k‰ytet‰‰n std::getline‰ koska se antaa koko rivin ja huomioi v‰lit

        if (!tiedosto.good()) //tapahtuiko virhe?
            break;

        //hyv‰, ei tapahtunut

        tiedosto >> koulumatka; //hoidetaan homma loppuun

        if (!tiedosto.good())
            break;

        tiedosto >> hatunKoko;

        if (!tiedosto.good())
            break;


        //jos virheit‰ ei tapahtunut, lis‰t‰‰n henkilˆ listaan

        henkilo* uusi = luoHenkilo(lista);

        uusi->nimi = nimi;
        uusi->koulumatka = koulumatka;
        uusi->hatunKoko = hatunKoko;

        std::getline(tiedosto,nimi); // luetaan viimeinen rivi loppuun koska >> operaattori ei mene seuraavalle riville

        i++;
    }

    tiedosto.close();


    std::cout << i << " tietuetta luettu tiedostosta 'tiedot.txt'\n";

}

