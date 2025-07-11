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
            shoopingCart *cart;
        public:
            cardInvoice(shoopingCart *cart)
                {
                    this->cart = cart;
                }

            void printInvoice()
                {
                    cout<<endl<<"Shooping cart Invoice"<<endl;
                    for(auto p:cart->getProduct())
                        {
                            cout<<p->name<<" -$"<<p->price<<endl;
                        }

                    cout<<endl<<"Total : $"<<cart->total_price();
                }

    };


    class DBPersistance{
        private:
            shoopingCart *cart;
            public:
                virtual void save(shoopingCart *cart) = 0 ; 
    };

    class saveTOSQL : public DBPersistance{
        public:
            void save(shoopingCart *cart) {
                cout<<endl<<"Saving to the SQL DATABASE";
            };
    };

    class saveToMONGO : public DBPersistance{
        public:
            void save(shoopingCart *cart) 
                {
                 cout<<endl<<" Saving to the Mongo DATABASE";
                }
    };



int main()
    {
        shoopingCart *cart = new shoopingCart{};
        cart->addProduct(new product("Laptop",500));
        cart->addProduct(new product("Mouse",50));
 
        
        cardInvoice *inv = new cardInvoice{cart};
        inv->printInvoice();

        DBPersistance *sql_1 = new saveTOSQL{};
        DBPersistance *mongo_1 = new saveToMONGO{};


        sql_1->save(cart);
        mongo_1->save(cart) ;



        return 0;

        
    }