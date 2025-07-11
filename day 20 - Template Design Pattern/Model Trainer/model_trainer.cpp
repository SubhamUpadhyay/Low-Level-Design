#include<bits/stdc++.h>
using namespace std;
class ModelTrainer{
    public:
        void TemplateMethod(){
            path();
            preapre();
            train();
            evaluate();
            save();
        }
        
        void preapre(){
            cout<<"Preapring the Training"<<endl;
        }
        void train(){
            cout<<"Training the Model"<<endl;
        }
        void evaluate(){
            cout<<"Evaluating the Result"<<endl;
        }
        virtual void save() = 0;
        virtual void path() = 0;

};

class NeuralNetworkModel : public ModelTrainer{
    string name;
    string database;
    public:
    NeuralNetworkModel(string n , string db):name(n),database(db){};
    void path() override
        {
            cout<<"Setting the path for the model  of "<<name<<endl;
        }
    void save() override
        {
            cout<<"Saving to the database : "<<database<<endl;
        }

};

class DecisionTreeModel : public ModelTrainer{
    private:
    string name;
    string database;
    public:
    DecisionTreeModel(string n , string db):name(n),database(db){};
    void path() override
        {
            cout<<"Setting the path for the model of "<<name<<endl;
        }
    void save() override
        {
            cout<<"Saving to the database : "<<database<<endl;
        }
};
int main()
{
    ModelTrainer *ptr = new NeuralNetworkModel("neural network model ", "MongoDB");
    ptr->TemplateMethod();
    cout<<"\n\n\n\n\n";
    ModelTrainer *ptr2 = new DecisionTreeModel("Decision Tree Model ", "MySQL");
    ptr2->TemplateMethod();
    return 0;
}