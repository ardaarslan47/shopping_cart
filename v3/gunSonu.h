#include <vector>
#include <fstream>
#include "kasa.h"

class GunSonuIslemleri
{
private:
    int *satislar;

public:
    void urunEkle(int urunSirasi);
    void gunSonuAl(std::vector<Urun *> urunListesi, std::ofstream &dosyaYaz) const;

    GunSonuIslemleri(int urunSayisi);
};

void GunSonuIslemleri::urunEkle(int urunSirasi)
{
    satislar[urunSirasi]++;
}

void GunSonuIslemleri::gunSonuAl(std::vector<Urun *> urunListesi, std::ofstream &dosyaYaz) const
{
    dosyaYaz << "Satislar:\n";
    for (int i = 0; i < urunListesi.size(); i++)
    {
        if (satislar[i] == 0)
            continue;
        dosyaYaz << satislar[i] << " tane " << urunListesi[i]->isimOku() << " "
                 << std::fixed << std::showpoint << std::setprecision(2)
                 << satislar[i] * urunListesi[i]->fiyatOku() << " turk lirasi\n";
    }
}

GunSonuIslemleri::GunSonuIslemleri(int urunSayisi)
{
    satislar = new int[urunSayisi];
}
