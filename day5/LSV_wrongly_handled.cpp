#include<bits/stdc++.h>
using namespace std;

class Account{
    public:
        virtual void deposit(double amount) =0;
        virtual void withdraw(double amount) = 0;
};

class savingAccount : public Account{
    private :
        double balance;
    public :
        savingAccount()
            {
                balance = 0;
            }
        void deposit(double amount)
            {
                balance+=amount;
                cout<<endl<<"Depoised"<<amount<<" in the saving Account";
            }

        void withdraw(double amount)
            {
                if(balance<amount)
                    {
                        cout<<endl<<" Low Balance cannot Withdraw!";
                        return;
                    }
                balance-=amount;
                cout<<endl<<"Rs "<<amount<<" withdraw from the bank account \n Current Balance :"<<balance;

            }
};




class currentAccount : public Account{
    private :
        double balance;
    public :
        currentAccount()
            {
                balance = 0;
            }
        void deposit(double amount)
            {
                balance+=amount;
                cout<<endl<<"Depoised"<<amount<<" in the saving Account";
            }

        void withdraw(double amount)
            {
                if(balance<amount)
                    {
                        cout<<endl<<" Low Balance cannot Withdraw!";
                        return;
                    }
                balance-=amount;
                cout<<endl<<"Rs "<<amount<<" withdraw from the bank account \n Current Balance :"<<balance;

            }
};




class fixedDeposit: public Account{
    private :
        double balance;
    public :
        fixedDeposit()
            {
                balance = 0;
            }
        void deposit(double amount)
            {
                balance+=amount;
                cout<<endl<<"Depoised"<<amount<<" in the saving Account";
            }

        void withdraw(double amount)
            {
                cout<<endl;
                throw logic_error("Account Type : Fixed Deposit \n Cannot Withdraw");
            }
};




class BankClient{
    private:
        vector<Account*>accounts;
    public:
        BankClient(vector<Account*>accounts)
            {
                this->accounts = accounts;
            }

        void processTransaction()
            {
                for(Account * acc : accounts)
                    {
                       acc->deposit(1000);
                       //check account type 
                    if(typeid(*acc) == typeid(fixedDeposit))
                        {
                            cout<<endl<<"Skipping Withdraw for Fixed Deposit Account";
                        }
                    else
                        {
                            try
                                {
                                    acc->withdraw(450);
                                }catch(const logic_error &e)
                                    {
                                        cout<<endl<<"Exception : "<<e.what()<<endl; 
                                    }
                        }
                    }
            }
};


int main()
    {
        vector<Account*>accounts;
        accounts.push_back(new savingAccount{});
        accounts.push_back(new currentAccount{});
        accounts.push_back(new fixedDeposit{});

        BankClient *client = new BankClient(accounts);
        client->processTransaction();

        return 0;


    }

