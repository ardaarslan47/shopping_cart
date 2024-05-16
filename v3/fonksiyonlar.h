#include "kasa.h"

void UrunSat(Urun &satilacakUrun, Kasa &urunKasa)
{
    float nakitMiktar;
    float nakitMiktar2;

    if (satilacakUrun.stokSayisiOku() > 0)
    {
        std::cout << "Lutfen " << satilacakUrun.fiyatOku() << "tl atiniz.(Islemi iptal etmek icin 0 tuslayin)\n"
                  << "Nakit: ";
        std::cin >> nakitMiktar;

        if (nakitMiktar == 0)
        {
            std::cout << "Islem iptal edilmistir.\n";
            return;
        }

        while (nakitMiktar < satilacakUrun.fiyatOku())
        {
            std::cout << "Lutfen " << satilacakUrun.fiyatOku() - nakitMiktar << "tl daha atiniz.(Islemi iptal etmek icin 0 tuslayin)\n"
                      << "Nakit: ";
            std::cin >> nakitMiktar2;
            if (nakitMiktar2 == 0)
            {
                std::cout << "Islem iptal edilmistir. " << nakitMiktar << "tl iade edilmistir.\n";
                return;
            }
            else
            {
                nakitMiktar += nakitMiktar2;
            }
        }

        if (nakitMiktar > satilacakUrun.fiyatOku())
        {
            std::cout << "Para ustu: " << nakitMiktar - satilacakUrun.fiyatOku() << "tl aliniz.\n";
        }
        urunKasa.odemeAl(satilacakUrun);
    }
    else
    {
        std::cout << "Secilen urun stokta bulunmamaktadir.\n";
    }
}

void anaSayfa(Urun *urunListesi[], int urunSayisi)
{
    std::cout << "\n====HOSGELDINIZ====\n"
              << "Satin almak istediginiz urunun yanindaki sayiyi giriniz.\n";

    for (int i = 0; i < urunSayisi; i++)
    {
        std::cout << i + 1 << "- ";
        urunListesi[i]->urunListele();
    }

    std::cout << "=====================\n";
}