#include<bits/stdc++.h>
using namespace std;
class Image{
    public:
    virtual void display() = 0;
    ~Image(){};
};

class RealImage : public Image{
    private:
        string fileName;
    public:
        RealImage(string n):fileName(n){
            loadFromDisk();
        };

        void loadFromDisk()
            {
                cout<<"Loading "<<fileName<<" from the disk ... "<<endl;
            }
        void display() override{
            cout<<"Displaying Image : "<<fileName<<endl;
        }

};

class ProxyImage : public Image{
    private:
        string fileName;
        RealImage *realimage;
    public:
        ProxyImage(string n):fileName(n),realimage(nullptr){};
        void display() override{
            if(realimage == nullptr)
                realimage = new RealImage(fileName);
            realimage->display();
        }
    ~ProxyImage(){
        delete realimage;
    };
};


int main()
{
    Image *image = new ProxyImage("Design_pattern.png");
    cout<<"Image Created ! Not displayed Yet !"<<endl;
    //display the trigger Loading
    image->display();
    //Display Again No need to load again
    //meaning you have already loaded the image thing in the earlier go .... now calling the dispaly won't take any extra time as it have already loaded the image
    image->display();
    delete image;

    return 0;
}