//Focuses on Data Security
#include<bits/stdc++.h>
using namespace std;

//so basically what does encapsulation says is that the behaviour must be encapsulated(defined within) the class only 

class sportsCar{
    private:

    //characters
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        //later declared for visualizing the setter
        string tyre;
    //constructor for the class sportCar

    public:

        sportsCar(string b ,string m)
            {
                this->brand = b;
                this->model = m;
                isEngineOn = false;
                currentSpeed = 0;
                currentGear  = 0;
                //later declared 

                tyre = "MRF";
            }

        //this is method or functions or behaviours


        //getter and setter
        string getTyre(){
            return this->tyre;
        }

        void setTyre(string tyre)
            {
                //we have a control we an set some validation or condtion . like if the tyre input is string or not or whether the tyre exist or not 
                this->tyre = tyre;
            }



        
        void startEngine()
            {
                isEngineOn = true;
                cout<<brand<<" "<<model<<" Engine starts with a roar !"<<endl;
            }

        void shiftGear(int gear )
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! cannot shift Gear !"<<endl;
                        return;
                    }
                if(gear >5)
                    {
                        cout<<brand<<" "<<model<<" cannot shift gear to "<<gear<<" , can only shift to 5 and can reverse "<<endl;
                        return;
                    }
                currentGear = gear;
                cout<<brand<<" "<<model<<" Shifted to Gear "<<currentGear<<endl;
            }

        void accelerate()
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! cannot Accelerate !"<<endl;
                        return;
                    }
                currentSpeed +=20;
                cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/hr" <<endl;
            }


        void brake()
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! no need to brake !"<<endl;
                        return;
                    }
                currentSpeed-=20;
                if(currentSpeed<0)
                    currentSpeed=0;
                cout<<brand<<" "<<model<< " : Braking! Speed is now "<<currentSpeed<<" km/hr"<<endl;
            }

         
        void stopEngine(){
            if(!isEngineOn)
                {
                    cout<<brand<<" "<<model<<" : Engine is already off!"<<endl;
                        return;
                }
            isEngineOn = false;
            currentGear = 0;
            currentSpeed= 0;
            cout<<brand<<" "<<model<<" : Engine truned off!"<<endl;
        }


    

        //getter function

        int getSpeed()
            {
                return this->currentSpeed;
            }

       
};
int main()
{
    sportsCar *new_car = new sportsCar("Ford","Mustang");

    new_car->startEngine();
    new_car -> shiftGear(3);
    new_car -> accelerate();
    
    


    new_car -> brake();
    new_car -> stopEngine();


    /*new_car->currentSpeed = 500;

    cout<<endl<<"Current speed of my new_car is "<<new_car->currentSpeed<<endl;
    */


    

    cout<<"current Speed of the car is : "<<new_car->getSpeed()<<" km/hr "<<endl;

    //it will give us 0 as we are calling it after stopping the engine;




    delete new_car;

    return 0;
} 


//getters and setters are used to get and set the value of any variable or characters 

