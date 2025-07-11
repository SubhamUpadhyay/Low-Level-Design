#include<bits/stdc++.h>
using namespace std;
class product{
    public:
        string name;
        int price;
        product(string name , int price)
            {
                this->name = name;
                this->price = price;
            }
};

class shoopingCart
    {
        private:
            vector<product*>products;

            public:

            //something like value setter 
                void addProduct(product *p)
                    {
                        products.push_back(p);
                    }

            const vector<product*>&getProduct()
                    {
                        return products;
                    }

            int total_price()
                    {
                        int totalPrice = 0;
                        for(auto it:products)
                            {
                                totalPrice +=it->price;
                            }
                        return totalPrice;
                    }
    };

class cardInvoice
    {
        private:
            shoopingCart *cart_details;
        public:
            cardInvoice(shoopingCart *cart)
                {
                    cart_details = cart;
                }

            void printInvoice()
                {
                    cout<<endl<<"Shooping cart Invoice"<<endl;
                    for(auto p:cart_details->getProduct())
                        {
                            cout<<p->name<<" -$"<<p->price<<endl;
                        }

                    cout<<endl<<"Total : $"<<cart_details->total_price();
                }

    };

class saving_to_DB{

    private:
        shoopingCart *cart_details_to;
        public:
            saving_to_DB(shoopingCart *cart)
                {
                    cart_details_to = cart;
                }


            //here the principle of open close is violated as it says if we have to add the new feautre and we can't do that into the same class we have to create a new class for that 

            void saveToDATABASE()
                {
                    cout<<endl<<"Successfully loaded the data into the DATABASE";
                }

            void saveToMYSQL()
                {
                    cout<<endl<<"Successfully loaded the data into the mysql";
                }

            void saveToMyFiles()
                {
                    cout<<endl<<"Successfully loaded the data into my Files";
                }
};

int main()
    {
        shoopingCart *cart = new shoopingCart{};
        cart->addProduct(new product("Laptop",500));
        cart->addProduct(new product("Mouse",50));

        
        cardInvoice *inv = new cardInvoice{cart};
        inv->printInvoice();

        saving_to_DB *db = new saving_to_DB{cart};
        db->saveToDATABASE();

        return 0;

        
    }