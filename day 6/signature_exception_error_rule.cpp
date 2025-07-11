#include <iostream>
#include <stdexcept>  // for standard exceptions

using namespace std;

/*
std::exception
│
├── std::bad_alloc
├── std::bad_cast
├── std::bad_typeid
├── std::logic_error
│   ├── std::domain_error
│   ├── std::invalid_argument
│   ├── std::length_error
│   └── std::out_of_range
├── std::runtime_error
│   ├── std::range_error
│   ├── std::overflow_error
│   └── std::underflow_error
└── std::ios_base::failure

*/




// --- Exception hierarchy ---
class MyBaseException : public std::logic_error {
public:
    MyBaseException(const string& msg) : logic_error(msg) {}
};

class MyDerivedException : public MyBaseException {
public:
    MyDerivedException(const string& msg) : MyBaseException(msg) {}
};

// --- Class hierarchy with covariant return ---
class Base {
public:
    virtual MyBaseException* getException() {
        cout << "Base::getException()" << endl;
        return new MyBaseException("Base logic error");
    }

    virtual void throwException() {
        throw MyBaseException("Exception from Base");
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    // Covariant return type: MyDerivedException* is allowed
    MyDerivedException* getException() override {
        cout << "Derived::getException()" << endl;
        return new MyDerivedException("Derived logic error");
    }

    void throwException() override {
        throw MyDerivedException("Exception from Derived");
    }
};

// --- Main test ---
int main() {
    Base* obj = new Derived();

    // Covariant return type example
    MyBaseException* e = obj->getException();
    cout << "Returned exception message: " << e->what() << endl;
    delete e;

    // Exception throwing and catching
    try {
        obj->throwException();
    } catch (const MyDerivedException& ex) {
        cout << "Caught MyDerivedException: " << ex.what() << endl;
    } catch (const MyBaseException& ex) {
        cout << "Caught MyBaseException: " << ex.what() << endl;
    } catch (const exception& ex) {
        cout << "Caught std::exception: " << ex.what() << endl;
    }

    delete obj;
    return 0;
}
