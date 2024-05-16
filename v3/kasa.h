#include "urun.h"

class Kasa
{
private:
    float nakitMiktari;

public:
    void odemeAl(Urun &satilacakurun);

    Kasa(float nakitMiktariAta = 500)
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
};

void Kasa::odemeAl(Urun &satilacakurun)
{
    nakitMiktari += satilacakurun.fiyatOku();
    satilacakurun.stokSayisiAzalt();
    std::cout << "Urununuzu asagidan aliniz.\n";
}