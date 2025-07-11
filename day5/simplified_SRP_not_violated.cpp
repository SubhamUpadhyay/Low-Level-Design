#include<bits/stdc++.h>
using namespace std;
class Product
{
public:
    string name;
    int price;

    Product(string n, int p) : name(n), price(p) {} // Using member initializer list
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts() const
    { // Made const-correct
        return products;
    }

    int calculateTotal() const
    { // Made const
        int total = 0;
        for (Product *p : products)
        {
            total += p->price;
        }
        return total;
    }
};

class InvoicePrinter
{
private:
    ShoppingCart *cart;

public:
    InvoicePrinter(ShoppingCart *c) : cart(c) {} // Using member initializer list

    void print()
    {
        cout << "\nShopping Cart Invoice\n";
        for (Product *p : cart->getProducts())
        {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "\nTotal: $" << cart->calculateTotal() << endl;
    }
};

class DatabaseSaver
{
private:
    ShoppingCart *cart;

public:
    DatabaseSaver(ShoppingCart *c) : cart(c) {} // Using member initializer list

    void save()
    {
        cout << "\nSuccessfully saved the cart to database\n";
    }
};

int main()
{
    // Create products directly (no dynamic allocation)
    Product laptop("Laptop", 500);
    Product mouse("Mouse", 50);

    // Create shopping cart on stack
    ShoppingCart cart;
    cart.addProduct(&laptop); // Pass address of existing products
    cart.addProduct(&mouse);

    // Create services
    InvoicePrinter printer(&cart);
    DatabaseSaver saver(&cart);

    // Use services
    printer.print();
    saver.save();

    return 0;
}