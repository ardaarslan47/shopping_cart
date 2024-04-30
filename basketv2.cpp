#include "item.cpp"
#include <vector>

class basket
{
private:
    std::vector<item *> items;

public:
    void addItem(char b[4]);
    void removeItem(char b[4]);
    void displayBasket() const;
    float calculateTotal() const;
    void printBill() const;
};

void basket::addItem(char b[4])
{
    for (int i = 0; i < itemListSize; i++)
    {
        if (b[0] == '#' && std::strcmp(itemList[i]->barcode + 1, b) == 0)
        {
            items.push_back(itemList[i]);
            return;
        }
        else if (std::strcmp(itemList[i]->barcode, b) == 0)
        {
            items.push_back(itemList[i]);
            return;
        }
    }
}

void basket::removeItem(char b[4])
{
    for (int i = 0; i < itemListSize; i++)
    {
        if (b[0] == '#' && std::strcmp(itemList[i]->barcode + 1, b) == 0)
        {
            items.erase(items.begin() + i);
            return;
        }
        else if (std::strcmp(itemList[i]->barcode, b) == 0)
        {
            items.erase(items.begin() + i);
            return;
        }
    }
}

void basket::displayBasket() const
{
    for (int i = 0; i < items.size(); i++)
    {
        items[i]->displayItem();
        std::cout << "\n";
    }
}

float basket::calculateTotal() const
{
    float total = 0;
    for (int i = 0; i < items.size(); i++)
    {
        total += items[i]->price;
    }
    return total;
}

void basket::printBill() const
{
    displayBasket();
    std::cout << "Total:"
              << "\t" << calculateTotal();
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