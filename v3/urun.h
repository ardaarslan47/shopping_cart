#include <string>
#include <iostream>
#include <iomanip>

class Urun
{
private:
    std::string isim;
    int stokSayisi;
    float fiyat;

public:
    std::string isimOku() const;
    int stokSayisiOku() const;
    float fiyatOku() const;

    void stokSayisiAzalt();

    void urunListele() const;

    Urun(std::string isimAta = "unknown", int stokSayisiAta = 100, float fiyatAta = 1);
};

std::string Urun::isimOku() const
{
    return isim;
}

int Urun::stokSayisiOku() const
{
    return stokSayisi;
}

float Urun::fiyatOku() const
{
    return fiyat;
}

void Urun::stokSayisiAzalt()
{
    stokSayisi--;
}

void Urun::urunListele() const
{
    std::cout << std::setw(2) << isim
              << std::setw(20 - isim.length()) << std::fixed << std::showpoint << std::setprecision(2)
              << fiyat << "tl\n";
}

Urun::Urun(std::string isimAta, int stokSayisiAta, float fiyatAta)
{
    isim = isimAta;

    if (stokSayisiAta < 0)
    {
        stokSayisi = 100;
    }
    else
    {
        stokSayisi = stokSayisiAta;
    }

    if (fiyatAta < 0)
    {
        fiyat = 1;
    }
    else
    {
        fiyat = fiyatAta;
    }
}