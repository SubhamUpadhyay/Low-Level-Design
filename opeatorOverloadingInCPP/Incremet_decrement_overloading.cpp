#include<bits/stdc++.h>
using namespace std;
class Weight{
    private:
        int kg;
    public:
        Weight()
            {
                kg = 0;
            }
        
        Weight(int x)
            {
                kg = x;
            }
        void printWeight()
            {
                cout<<endl<<"Weight in KG:"<<kg<<endl;
            }   
        //using void as we are only working with one argument here we are working with the value and not with the class

        //if you want to do something like
                /*
                    Weight ob1{},obj2{};
                    obj1 = ++obj2;
                    then in that case we have to change the return type of the function to class 
                    

                    say 
                    Weight operator ++()
                        {
                            Weight temp{};
                            temp.kg = ++kg;
                            return temp;


                            or 

                            Weight *temp = new Weight();
                            temp->kg = ++kg;
                            return temp;



                            This server as a 2 way solution . even you can do ++obj1   & can also do obj2 = ++obj1;

                        }
                */
        


        //pre incement
        //equivalent to obj.opeator++();
        void operator ++()
            {
                ++kg;
            }


        //post increment
        //equivalen to obj.opeator++(0);
        void operator ++(int)
            {
                kg++;
            }
        ~Weight(){};
        

};
int main()
{
    Weight obj{};
    obj.printWeight();
    ++obj; //-> equivalent to obj.opeator++();
    obj.printWeight();
    obj++;  //-> equivalent to obj.operator ++(0);
    obj.printWeight();


    
    return 0;
}