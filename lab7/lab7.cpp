#include <iostream>
#include <list>
#include <Windows.h>

using namespace std;

class Warehouse
{
private:
    list<int> productionAvailable = { 1, 2, 3, 4, 5 };
public:
    int getProductId(int counter)
    {
        auto iter = productionAvailable.begin();

        for (int i = 0; i < counter; i++)
        {
            ++iter;
        }

        return *iter;
    }

    void addProduct(int productToAdd)
    {
        cout << "Adding product " << productToAdd << " to warehouse" << endl;
        productionAvailable.push_back(productToAdd);
    }

    int transferProduct(int productToGet)
    {
        if (productionAvailable.empty())
        {
            cout << "Warehouse is empty!";
            return 0;
        }
        auto iter = productionAvailable.begin();

        for (int i = 0; i < productionAvailable.size(); i++)
        {
            if (*iter == productToGet)
            {
                int product = *iter;
                productionAvailable.erase(iter);
                i--;
                iter = productionAvailable.begin();
                return product;
            }
            else {
                ++iter;
            }
        }
    }

    void showAllProducts()
    {
        cout << "Warehouse list: ";

        if (!productionAvailable.empty())
        {
            for (int i : productionAvailable)
            {
                cout << i << ", ";
            }
        }
        else 
        {
            cout << "out of products";
        }

        cout << endl << "===================" << endl;
    }

};

class Shop
{
private:
    Warehouse warehouse;
    list<int> productionOrdered = { 1, 2 };
public:
    void buyProducts()
    {
        auto iter = productionOrdered.begin();

        for (int i = 0; i < productionOrdered.size(); i++)
        {
            if (warehouse.transferProduct(*iter) == *iter)
            {
                cout << "Product " << *iter << " was buyed" << endl;
                productionOrdered.erase(iter); 
                iter = productionOrdered.begin();
                i--;
            }
            else
            {
                ++iter;
            }

            
        }
    }

    void requestProduct(int requestedProduct)
    {
        warehouse.addProduct(requestedProduct);
    }

    void showOrderList()
    {
        cout << endl << "===================" << endl;
        cout << "Order list: ";

        if (!productionOrdered.empty())
        {
            for (int i : productionOrdered)
            {
                cout << i << ", ";
            }
        }
        else
        {
            cout << "out of orders";
        }

        cout << endl << "===================" << endl;

        warehouse.showAllProducts();
    }

    void addtoList(int productToAdd)
    {
        cout << "Adding product " << productToAdd << " to order list" << endl;
        productionOrdered.push_back(productToAdd);
    }
};

int main()
{
    Shop shop;

    shop.showOrderList();
    shop.addtoList(6);
    shop.requestProduct(6);
    shop.showOrderList();
    shop.buyProducts();
    shop.showOrderList();
}
