#include "urun.h"

class Kasa
{
private:
    float nakitMiktari;

public:
    void odemeAl(Urun &satilacakurun);

    float nakitMiktariOku() const;

    Kasa(float nakitMiktariAta = 500);
};

void Kasa::odemeAl(Urun &satilacakurun)
{
    nakitMiktari += satilacakurun.fiyatOku();
    satilacakurun.stokSayisiAzalt();
    std::cout << "Urununuzu asagidan aliniz.\n";
}

float Kasa::nakitMiktariOku() const
{
    return nakitMiktari;
}

Kasa::Kasa(float nakitMiktariAta)
{
    if (nakitMiktariAta < 0)
    {
        nakitMiktari = 500;
    }
    else
    {
        nakitMiktari = nakitMiktariAta;
    }
}