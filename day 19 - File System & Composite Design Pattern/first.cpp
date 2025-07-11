#include <bits/stdc++.h>
using namespace std;
class Composite
{
public:
    virtual string ls() = 0;
    virtual void openAll() = 0;
    virtual int getSize() = 0;
    virtual string getName() = 0;
    virtual ~Composite(){};
};

//Leaf Component - File
class File : public Composite
{
private:
    string name;
    int size;

public:
    File(string n, int s) : name(n), size(s) {};
    string getName() override
    {
        return name;
    }
    string ls() override
    {
        return getName();
    };
    void openAll() override {
        cout<<"Opening File :"<<name<<endl;
    };
    int getSize() override
    {
        return size;
    };
};

//Composite Component - Folder

class Folder: public Composite{
    private:
        string name;
        vector<Composite*>content;
    public:
    Folder(string n):name(n){};
    void add(Composite *component)
        {
            content.push_back(component);
        }

    string getName() override{
        return name;
    };

    string ls() override{
        string result = "Folder"+name+"\n";
        for(Composite *item : content)
            {
                result += "  "+item->ls()+"\n";
            }
        return result;
    };
 
    void openAll() override{
        cout<<"Opening Folder : "<<name<<endl;
        for(Composite *item : content)
            {
                item->openAll();
            }
    };

    int getSize() override{
        int totalSize = 0;
        for(Composite *item : content)
            {
                totalSize+= item->getSize();
            }
        return totalSize;
    };

    ~Folder(){
        for(Composite *item : content)
            {
                delete item;
            }
    };


};
int main()
{
    Folder *root = new Folder("Root");
    Folder *docs = new Folder("Docs");
    Folder *pics = new Folder("Pics");

    File *file1 = new File("Resume.pdf",120);
    File *file2 = new File("Photo.jpg",300);
    File *file3 = new File("report.docx",200);

    docs->add(file1);
    docs->add(file3);

    pics->add(file2);

    root->add(docs);
    root->add(pics);

    cout<<root->ls()<<endl;
    root->openAll();
    cout<<"Total Size : "<<root->getSize()<<" KB "<<endl;
    delete root;

    return 0;
}