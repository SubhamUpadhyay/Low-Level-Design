#include "Resume.hpp"   
#include "MyResume.hpp"

int main()
    {
        Resume *blockchain = new MyResume("subham","1234567890","abcde@gmail.com");
        blockchain->setPosition("Blockchain Engineer");




        Resume *frontend = blockchain->clone();
        frontend->setPosition("Frontend"); 
        


        Resume *DSA = blockchain->clone();
        DSA->setPosition("DSA ");

        

        Resume *LLD = blockchain->clone();
        LLD->setPosition("LLD");



        blockchain->print();
        frontend->print();
        DSA->print();
        LLD->print();


        delete blockchain;
        delete frontend;
        delete DSA;
        delete LLD;



        return 0;
        
    }