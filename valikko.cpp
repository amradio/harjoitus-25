/*
    Tiedosto: valikko.cpp
    Tekij‰: Antti M‰kel‰
    Tarkoitus: Sis‰lt‰‰ aliohjelman valikko()
*/

#include "maarittely.hpp"

int valikko()
{
    std::cout   << "\n---------------------------\n"
                << "1. Lis‰‰ henkilˆ\n"
                << "2. N‰yt‰ henkilˆ\n"
                << "3. N‰yt‰ kaikki henkilˆt\n"
                << "4. Poista henkilˆ\n"
                << "5. Tallenna tiedostoon\n"
                << "6. Lue tiedostosta\n"
                << "0. Lopeta\n";

    int valinta = -1;

    while (true) //karhutaan vastausta kunnes k‰ytt‰j‰ antaa jotain sopivaa
    {
        std::cout << "\n" << ">";
        std::cin >> valinta;
        if (valinta < 0 || valinta > 6) // jos se oli jotain sopimatonta...
        {
            std::cout << "\n" << "Virheellinen valinta"; //...niin herjataan
            continue;
        }

        return valinta;
    }
}
