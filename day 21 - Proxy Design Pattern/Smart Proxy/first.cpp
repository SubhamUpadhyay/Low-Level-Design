#include <bits/stdc++.h>
using namespace std;
class File
{
public:
    virtual void open() = 0;
    ~File() {};
};

class RealFile : public File
{
public:
    void open() override
    {
        cout << "File Opened \n";
    };
};

class SmartFileProxy : public File
{
private:
    RealFile *rf;
    int OpenCount;

public:
    SmartFileProxy() : OpenCount(0), rf(nullptr) {};
    void open() override
    {
        if (!rf)
        {
            rf = new RealFile();
            cout<<"\n Object Created "<<OpenCount+1<<" time(s) \n";
        }
        OpenCount++;
        cout << "\n File Opened : " << OpenCount << " time(s)\n";
        rf->open();
    };

    ~SmartFileProxy()
    {
        delete rf;
    }
};

//the object will be created only once and that is enough to open that file ... we avoid creating object for more than once using proxy and we actually same the computational time and the memory as well
int main()
{

    File *file = new SmartFileProxy;
    file->open();
    cout<<"\n\n\n\n";
    file->open();
    cout<<"\n\n\n\n";
    file->open();
    cout<<"\n\n\n\n";
    file->open();
    cout<<"\n\n\n\n";
    file->open();
    cout<<"\n\n\n\n";
    file->open();
    return 0;
}