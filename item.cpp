#include <string>
#include <iostream>

enum itemNums
{
    banana = 0,
    apple,
    grape,
    itemListSize
};

std::string itemNumToString(itemNums i)
{
    switch (i)
    {
    case banana:
        return "banana";
    case apple:
        return "apple";
    case grape:
        return "grape";
    default:
        return "unknown";
    }
}

struct item
{
    itemNums name;
    char barcode[3];
    float price;

    item(itemNums n, char b[3], float price);
    void displayItem() const;
};

item::item(itemNums n, char b[3], float p)
{
    name = n;
    price = p;
    for (int i = 0; i < 3; i++)
    {
        barcode[i] = b[i];
    }
}

void item::displayItem() const
{
    std::cout << "#" << barcode << "\t" << itemNumToString(name) << "\t"
              << "$" << price;
}

// data for items
item *itemList[itemListSize] = {
    new item(banana, (char[3]){'3', '2', '\0'}, 3.99),
    new item(apple, (char[3]){'0', '9', '\0'}, 0.99),
    new item(grape, (char[3]){'9', '9', '\0'}, 2.49)};

// int main()
// {
//     for (int i = 0; i < itemListSize; i++)
//     {
//         itemList[i]->displayItem();
//         std::cout << '\n';
//     }

//     return 0;
// }