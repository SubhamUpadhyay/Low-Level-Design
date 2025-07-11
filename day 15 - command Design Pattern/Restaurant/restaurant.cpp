#include<bits/stdc++.h>
using namespace std;
//Command Interface
class Command{
    public:
    virtual void execute() = 0;
    ~Command(){};
};

//Receivers
class MostOrdered {
    public:
    void menuItem() {
        cout << "Most Ordered Item: Chicken Biryani " << endl;
    }
};

class LeastOrdered {
    public:
    void menuItem() {
        cout << "Least Ordered Item: Bitter Gourd Salad " << endl;
    }
};
//Concrete Command
class most_ordered_item : public Command{
    private:
        MostOrdered *most_ordered;
    public:
        most_ordered_item(MostOrdered *mo):most_ordered(mo){};
        void execute()
            {
                most_ordered->menuItem();
            }

};

class least_ordered_item :  public Command{
    private:
        LeastOrdered *least_ordered;
    public:
        least_ordered_item(LeastOrdered *lo):least_ordered(lo){};
        void execute()
            {
                least_ordered->menuItem();
            }
};


//Invoker
class Order{
    private:
        Command *cmd;
    public:
        Order(Command *obj):cmd(obj){};
        void order_food(){
            cmd->execute();
        }

};
int main()
{
    MostOrdered m;
    most_ordered_item *item = new most_ordered_item(&m);
    Order *o = new Order(item);
    o->order_food();
    delete o , item;
    return 0;
} 