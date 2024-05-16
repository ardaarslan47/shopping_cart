#include "fonksiyonlar.h"

int main()
{
    int const URUNSAYISI = 10;
    Urun *URUNLER[URUNSAYISI];
    
    Kasa urunKasa;

    URUNLER[0] = new Urun("SU", 100, 5.50);
    URUNLER[1] = new Urun("SODA", 20, 11.90);
    URUNLER[2] = new Urun("LIMONLU SODA", 10, 16.25);
    URUNLER[3] = new Urun("SOGUK KAHVE", 50, 30.00);
    URUNLER[4] = new Urun("MEYVE SUYU", 10, 12.40);
    URUNLER[5] = new Urun("SANDVIC", 50, 56.50);
    URUNLER[6] = new Urun("CIKOLATA", 120, 12.50);
    URUNLER[7] = new Urun("KOLA", 200, 20.00);
    URUNLER[8] = new Urun("AYRAN", 50, 9.90);
    URUNLER[9] = new Urun("DONDURMA", 2, 49.90);

    int secim;

    do
    {
        anaSayfa(URUNLER, URUNSAYISI);
        std::cout << "Secim: ";
        std::cin >> secim;

        if (secim == 0)
            break;

        if (secim >= 1 && secim <= 10)
        {
            UrunSat(*URUNLER[secim - 1], urunKasa);
        }
        else
        {
            std::cout << "Gecersiz urun numarasi girilmistir.\n";
        }

    } while (true);
}