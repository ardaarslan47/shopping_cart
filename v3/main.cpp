#include "fonksiyonlar.h"

int main()
{
    std::vector<Urun *> URUNLER;

    URUNLER.push_back(new Urun("SU", 100, 5.50));
    URUNLER.push_back(new Urun("SODA", 20, 11.90));
    URUNLER.push_back(new Urun("LIMONLU SODA", 10, 16.25));
    URUNLER.push_back(new Urun("SOGUK KAHVE", 50, 30.00));
    URUNLER.push_back(new Urun("MEYVE SUYU", 10, 12.40));
    URUNLER.push_back(new Urun("SANDVIC", 50, 56.50));
    URUNLER.push_back(new Urun("CIKOLATA", 120, 12.50));
    URUNLER.push_back(new Urun("KOLA", 200, 20.00));
    URUNLER.push_back(new Urun("AYRAN", 50, 9.90));
    URUNLER.push_back(new Urun("DONDURMA", 2, 49.90));

    Kasa urunKasa;
    GunSonuIslemleri gunsonu(URUNLER.size());

    std::ofstream dosyaYaz;
    dosyaYaz.open("rapor.txt", std::ios::app);

    if (!dosyaYaz.is_open())
    {
        std::cout << "Rapor dosyasi acilamadi.";
        return 1;
    }

    dosyaYaz << "Kasa acilis tutari: " << urunKasa.nakitMiktariOku() << "\n\n";

    int secim;

    do
    {
        anaSayfa(URUNLER, URUNLER.size());
        std::cout << "Secim: ";
        std::cin >> secim;

        if (secim == 1453)
            break;

        if (secim >= 1 && secim <= URUNLER.size())
        {
            UrunSat(*URUNLER[secim - 1], urunKasa, gunsonu, secim - 1);
        }
        else
        {
            std::cout << "Gecersiz urun numarasi girilmistir.\n";
        }

    } while (true);

    gunsonu.gunSonuAl(URUNLER, dosyaYaz);
    dosyaYaz << "\nGun sonu tutari: " << urunKasa.nakitMiktariOku() << "\n\n";
    dosyaYaz.close();
}