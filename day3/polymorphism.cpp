#include<bits/stdc++.h>
using namespace std;

class car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;


    public:
    car(string b, string a)
        {
            this->brand = b;
            this->model = a;
            isEngineOn = false;
            currentSpeed = 0;
        }
//common method for all car

    void startEngine()
        {
            isEngineOn = true;
            cout<<"Engine is on"<<endl;
        }

    void stopEngine()
        {
            isEngineOn = false;
            currentSpeed = 0;
            cout<<"Engine is off!"<<endl;
        }

    //  =0 signifies that the function has to compoulsorly declared in the child class

    //this is method overriding  -> you have to declare these method in the child class as per the need!
    virtual void Accelerate() = 0; //this is to be defined in the child class 
    virtual void brake() = 0;


    //If you don't define a destructor (e.g., virtual ~car(); without {}), the compiler will automatically generate a destructor. However, it won't perform any custom cleanup, and it may not be sufficient if you want to manage resources in the base class.



    virtual ~car(){
        cout<<endl<<"Car Destructor Called"<<endl;
    };
};


class ManualCar : public car
    {
        private:
        int currentGear; //specific to manual car

        public:
            //constructor
        ManualCar(string a, string b):car(a,b){
            currentGear = 0;
        } 

        //this function acts as an setter for currentGear as currentGear is private and not accessible from outside 
        void shiftGear(int gear)
            {
                //Before I change the gear I have to check whether or not the car is one or off.
                if(!isEngineOn)
                    {
                        cout<<"Engine is off ! cannot shift Gear !"<<endl;
                        return;
                    }

                if(gear<0 || gear>5)
                    {
                        cout<<"Gear shift not possible  !"<<endl;;
                        return;
                    }
                currentGear = gear;
                cout<<"Gear Shifted ! ton"<<gear<<endl;;
            }

        //Over riding polymorphism - > function Accelerate () and brake(); 

        void Accelerate(){
            if(!isEngineOn)
                {
                    cout<<"Cannot Accelerate ! Engine is off"<<endl;
                    return;
                }
            currentSpeed += 20;
            cout<<"Accelerated ! Current Speed is now "<<currentSpeed<<" km /hr"<<endl;
        }


        //Static polymorphism / Method OverLoading for function Accelerate
        void Accelerate(int x){
            if(!isEngineOn)
                {
                    cout<<"Cannot Aceelerate ! Engine is off!"<<endl;
                    return;
                }
            currentSpeed +=x;
            cout<<"Accelerated ! Current Speed is now "<<currentSpeed<<" km / hr"<<endl;
        }

        void brake(){
            if(!isEngineOn)
                {
                    cout<<"Engine is off ! no need to brake"<<endl;
                    return;
                }
            isEngineOn = true;
            currentSpeed  = 0;
        }


        

        virtual ~ManualCar(){
            cout<<endl<<"Manual Car Destructed"<<endl;
        }
    };


    class electricCar: public car{

        private:
            int batteryStatus;
        public:
            //constructor
        electricCar(string a, string b):car(a,b)
            {
                batteryStatus = 100;
            }

        void chargeBattery()
            {
                if(batteryStatus == 100)
                    {
                        cout<<"Batter is full no need to charge :"<<endl;
                        return;
                    }
                batteryStatus = 100;
                cout<<"Battery Charged! You can remove the charger!"<<endl;
                    
            }        


            //Over riding polymorphism - > function Accelerate () and brake();
        void Accelerate(){
            if(!isEngineOn)
                {
                    cout<<"Cannot Accelerate ! Engine is off"<<endl;
                    return;
                }
            batteryStatus -=10;

            currentSpeed += 15;
            cout<<"Accelerated ! Current Speed is now "<<currentSpeed<<" km /hr"<<endl;
            cout<<"Battery Status :"<<batteryStatus<<"%"<<endl;
        }

        void brake(){
            if(!isEngineOn)
                {
                    cout<<"Engine is off ! no need to brake"<<endl;
                    return;
                }
            isEngineOn = true;
            currentSpeed  = 0;
        }

        //Static polymorphism / Method OverLoading for function Accelerate
        void Accelerate(int x){
            if(!isEngineOn)
                {
                    cout<<"Cannot Aceelerate ! Engine is off!"<<endl;
                    return;
                }
            batteryStatus-=12;
            currentSpeed +=x;
            cout<<"Accelerated ! Current Speed is now "<<currentSpeed<<" km / hr"<<endl;
            cout<<"Battery Status :"<<batteryStatus<<"%"<<endl;
        }


        virtual ~electricCar(){
            cout<<endl<<"Virtual Car Destructed"<<endl;
        }


    };

int main()
    {

        cout<<"ManualCar\n\n\n\n";
        //Manual Car
        ManualCar *myManualCar = new ManualCar("Ford","Mustang");
        myManualCar->startEngine();
        myManualCar->Accelerate();//Expected output is 20km/hr
        myManualCar->Accelerate(25); //Expected output is 45 km/hr
        myManualCar->stopEngine();
        myManualCar->brake();
        myManualCar->shiftGear(3);  //->specific to Manual Car
        delete myManualCar;

        cout<<"\n\n\n\nElectricCar\n\n\n\n";

        //Electric Car
        electricCar *myElectricCar = new electricCar("Tesla","Model S");
        myElectricCar->startEngine(); 
        myElectricCar->Accelerate(); //Expected output is 15 km / hr
        myElectricCar->Accelerate(18); //Expected output is 33 km/hr
        myElectricCar->stopEngine();
        myElectricCar->brake();
        myElectricCar->chargeBattery();  //->Specific to electric car
        delete myElectricCar;

        return 0;
    }