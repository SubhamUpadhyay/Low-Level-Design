#include<bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
    public:
    virtual void deposit(double amount) = 0;
};

class WithdrawAbleAccount:public DepositOnlyAccount
    {   
        public:
            virtual void withdraw(double amount) = 0;
    };


class savingAccount:public WithdrawAbleAccount{
    private:
        double balance;
    public:
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

class currentAccount:public WithdrawAbleAccount{
    private:
        double balance;
    public: 
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

class fixedDepositAccount : public DepositOnlyAccount{
    private:
        double balance;
    public:
        fixedDepositAccount()
            {
                balance = 0;
            }
        void deposit(double amount)
            {
                balance+=amount;
                cout<<endl<<"Deposited :"<<amount<<" to Fixed Deposit Account";
             }
      
};

class bankClient
    {
        private:
            vector<DepositOnlyAccount*>depositOnly;
            vector<WithdrawAbleAccount*>withdrawOnly;

        public:
            bankClient(vector<WithdrawAbleAccount*>withdrawOnly , vector<DepositOnlyAccount*>depositOnly)
                {
                    this->withdrawOnly = withdrawOnly;
                    this->depositOnly = depositOnly;
                }

            void processTransactions()
                {
                    for( auto* acc : withdrawOnly)
                        {
                            acc->deposit(1000);
                            acc->withdraw(550);
                        }
                    for(auto *acc : depositOnly)
                        {
                            acc->deposit(1000);
                        }
                }

    };

    int main()
        {
            vector<WithdrawAbleAccount*>WithdrawAbleAccounts;
            WithdrawAbleAccounts.push_back(new savingAccount());
            WithdrawAbleAccounts.push_back(new currentAccount);


            vector<DepositOnlyAccount*>DepositOnlyAccounts;
            DepositOnlyAccounts.push_back(new fixedDepositAccount);

            bankClient *client = new bankClient(WithdrawAbleAccounts,DepositOnlyAccounts);

            client->processTransactions();

            return 0;

        }