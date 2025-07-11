#include<bits/stdc++.h>
using namespace std;

class myComplex{
    private :
        int real , imag ;
    public:
        myComplex(){
            real = 0;
            imag = 0;
        }
        myComplex(int r , int i)
            {
                real = r;
                imag = i;
            }

        void print()    
            {
                cout<<real<<" + "<<imag<<"i"<<endl;
            }; 



    //Operator Overloading syntax we are returning obj so I have used the myComplex or else I could have used any other thing like void or any other return type ... but the operator keyword should be always there



            myComplex operator +(myComplex c)
                {
                    myComplex obj4{};
                    obj4.real = this->real + c.real;
                    obj4.imag = this->imag + c.imag;
                    return obj4;
                }

};
int main()
{
    myComplex obj1{4,5};
    myComplex obj2{3,6};

    myComplex obj3{};

    obj3 = obj1 + obj2; //-> this is equivalent to obj3 = obj1.operator+(obj2)


    //compiler will evaluate this  as obj3 = obj1.add(obj2)
     obj3.print();


     myComplex obj4{};
     obj4 = obj1+obj2+obj3;
    //                              compiler wil evaluate this as 
    //                              temp = obj1.operataor+(obj2)
    //                              ojb4  = temp.operator+(obj3)



     obj4.print();
    return 0;
}