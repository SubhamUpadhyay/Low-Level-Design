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

    void Accelerate()
        {
            if(!isEngineOn)
                {
                    cout<<"Cannot Accelerate ! Engine is off!"<<endl;
                        return;
                }
            currentSpeed +=20;
            cout<<"Accelerated !!! ->current speed of car is"<<currentSpeed<<endl;

        }
    void brake()    
        {
            if(!isEngineOn)
                {
                    cout<<"Engine is already off!"<<endl;
                        return;
                }
            isEngineOn = false;
            currentSpeed = 0;
            cout<<"Brake Applied ! car stopped -> current speed:"<<currentSpeed<<endl;            
        }
    
    virtual ~car(){}
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
    };


    class electricCar: public car{

        private:
            int batterStatus;
        public:
            //constructor
        electricCar(string a, string b):car(a,b)
            {
                batterStatus = 100;
            }

        void chargeBattery()
            {
                if(batterStatus == 100)
                    {
                        cout<<"Batter is full no need to charge :"<<endl;
                        return;
                    }
                batterStatus = 100;
                cout<<"Batter Charged! You can remove the charger!"<<endl;
                    
            }        

    };

int main()
    {

        cout<<"ManualCar\n\n\n\n";
        //Manual Car
        ManualCar *myManualCar = new ManualCar("Ford","Mustang");
        myManualCar->startEngine();
        myManualCar->Accelerate();
        myManualCar->stopEngine();
        myManualCar->brake();
        myManualCar->shiftGear(3);  //->specific to Manual Car
        delete myManualCar;

        cout<<"\n\n\n\nElectricCar\n\n\n\n";

        //Electric Car
        electricCar *myElectricCar = new electricCar("Tesla","Model S");
        myElectricCar->startEngine();
        myElectricCar->Accelerate();
        myElectricCar->stopEngine();
        myElectricCar->brake();
        myElectricCar->chargeBattery();  //->Specific to electric car
        delete myElectricCar;

        return 0;
    }