#include "item.cpp"

class basket
{
private:
    int itemQuantities[itemListSize];
    float totalPrice;

public:
    void addItem(char b[4]);
    void removeItem(char b[4]);
    void displayBasket() const;
    void printBill() const;
    basket();
};

void basket::addItem(char b[4])
{
    bool found = false;

    for (int i = 0; i < itemListSize; i++)
    {
        if (b[0] == '#' && std::strcmp(itemList[i]->barcode, b + 1) == 0)
        {
            itemQuantities[itemList[i]->name]++;
            totalPrice += itemList[i]->price;
            std::cout << itemNumToString(itemList[i]->name) << " succesfully added. \n";
            found = true;
            break;
        }
        else if (std::strcmp(itemList[i]->barcode, b) == 0)
        {
            itemQuantities[itemList[i]->name]++;
            totalPrice += itemList[i]->price;
            std::cout << itemNumToString(itemList[i]->name) << " succesfully added. \n";
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "invalid barcode! \n";
}

void basket::removeItem(char b[4])
{
    for (int i = 0; i < itemListSize; i++)
    {
        if (b[0] == '#' && std::strcmp(itemList[i]->barcode, b + 1) == 0)
        {
            itemQuantities[itemList[i]->name]--;
            totalPrice -= itemList[i]->price;
            break;
        }
        else if (std::strcmp(itemList[i]->barcode, b) == 0)
        {
            itemQuantities[itemList[i]->name]--;
            totalPrice -= itemList[i]->price;
            break;
        }
    }
}

void basket::displayBasket() const
{
    for (int i = 0; i < itemListSize; i++)
    {
        if (itemQuantities[i] > 0)
        {
            std::cout << "#" << itemList[i]->barcode << "\t" << itemQuantities[i] << "\t" << itemNumToString(itemList[i]->name) << "\t"
                      << "$" << itemList[i]->price * itemQuantities[i] << "\n";
        }
    }
}

void basket::printBill() const
{
    displayBasket();
    std::cout << "Total:"
              << "\t" << totalPrice;
}

basket::basket()
{
    for (int i = 0; i < itemListSize; i++)
    {
        itemQuantities[i] = 0;
    }
    totalPrice = 0;
}

// int main()
// {
//     basket myBasket;
//     myBasket.addItem((char[3]){'3', '2', '\0'});
//     myBasket.addItem((char[3]){'3', '2', '\0'});
//     myBasket.addItem((char[3]){'3', '2', '\0'});
//     myBasket.addItem((char[3]){'9', '9', '\0'});

//     myBasket.removeItem((char[3]){'3', '2', '\0'});

//     myBasket.printBill();

//     return 0;
// }