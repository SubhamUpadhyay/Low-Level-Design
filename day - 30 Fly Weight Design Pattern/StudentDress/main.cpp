#include "DressFactory.hpp" 
#include "Student.hpp" 
#include<vector>
int main()
    {

        DressFactory factory;
        Dress *schoolDress = factory.getDress("Uniform","Blue");
        vector<Student*>students={
            new Student("Hausala","S",schoolDress),
            new Student("Smritee","L",schoolDress),
            new Student("Subham","M",schoolDress),
            new Student("RajKumar","XS",schoolDress),
            new Student("Saroj","XXL",schoolDress),
        };

            for(auto student :students) 
            {
                student->show();
            }
            for(auto student:students)
                {
                    delete student;
                }
        return 0;
    }