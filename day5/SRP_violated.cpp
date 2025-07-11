#include<bits/stdc++.h>
using namespace std;

//code will work but not following the SRP (single Responsibility Principle);

class product {
    public:
        string name;
        int price;
        
        product(string name , int price)
            {
                this->name = name;
                this->price = price;
            }
};

//violating SRP :shooping cart is handling multiple responsibility at a single time
class shoppingCart{
    private :

        //vector for storing multiple products 
        //it will store both name and the price 
        //it is of class type
        vector<product*>products;

    public:
         void addProduct(product *p)
            {
                products.push_back(p);
            }

        const vector<product*>&getProducts()
            {
                return products;
            }


        //calculate the total price in cart
        double calculateTotal()
            {
                double total = 0;
                for(auto p:products)    
                    {
                        total+=p->price;
                    }
                return total;
            }

        // violating SRP -> printing the invoice 
        void printInvoice()
            {
                cout<<endl<<"Shooping cart Invoice !";
                for(auto p:products)
                    {

                        //this will sequentially print the product and its price 
                        cout<<p->name<< " - $"<<p->price<<endl;
                    }
                //calling the calculateTotal function as we have already calculated the price

                cout<<endl<<"Total price :"<<calculateTotal()<<endl;
            }

        void saveToDB()
            {
                cout<<endl<<"Saving Shopping Cart Data to the DATABASE";
            }
};


int main()
    {
        shoppingCart *cart = new shoppingCart{};
        cart->addProduct(new product{"Laptop",500});
        cart->addProduct(new product{"Mouse",10});

        cart->calculateTotal();
        cart->printInvoice();
        cart->saveToDB();
    }