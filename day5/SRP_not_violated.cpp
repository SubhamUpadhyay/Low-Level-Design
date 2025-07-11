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
                        //return the reference to the actual vector stored in the class
                        //even though you have the reference but because of const keyword you can modify the value



                        
            const vector<product*>&getProduct()
                    {
                        return products;
                    }


            //

            int total_price()
                    {
                        int totalPrice=0;
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
            shoopingCart *cart_information;
        public:
            cardInvoice(shoopingCart *cart)
                {
                    cart_information = cart;
                }

            void printInvoice()
                {
                    cout<<endl<<"Shooping cart Invoice"<<endl;
                    for(auto p:cart_information->getProduct())
                        {
                            cout<<p->name<<" -$"<<p->price<<endl;
                        }

                    cout<<endl<<"Total : $"<<cart_information->total_price();
                }

    };

class saving_to_DB{

    private:
        shoopingCart *cartInfo;
        public:
            saving_to_DB(shoopingCart *cart)
                {
                    cartInfo = cart;
                }

            void saveToDATABASE()
                {
                    cout<<endl<<"Successfully loaded the data into the DATABASE";
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