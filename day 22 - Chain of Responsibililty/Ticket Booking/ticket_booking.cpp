#include <bits/stdc++.h>
using namespace std;

class BookTicket {
protected:
    BookTicket* bookticket;

public:
    BookTicket() : bookticket(nullptr) {}
    void tryChain(BookTicket* next) {
        bookticket = next;
    }
    virtual void book(int difficulty) = 0;
    virtual ~BookTicket() {}
};

class SupportA : public BookTicket {
public:
    void book(int difficulty) override {
        if (difficulty <= 2) {
            cout << "Ticket Booked Through A support\n";
            return;
        } else {
            cout << "Ticket cannot be booked by support A, trying Support B...\n";
            if (bookticket)
                bookticket->book(difficulty);
        }
    }
};

class SupportB : public BookTicket {
public:
    void book(int difficulty) override {
        if (difficulty <= 4) {
            cout << "Ticket Booked Through B support\n";
            return;
        } else {
            cout << "Ticket cannot be booked by support B, trying Support C...\n";
            if (bookticket)
                bookticket->book(difficulty);
        }
    }
};

class SupportC : public BookTicket {
public:
    void book(int difficulty) override {
        if (difficulty <= 6) {
            cout << "Ticket Booked Through C support\n";
            return;
        } else {
            cout << "Ticket cannot be booked by support C, trying Supervisor...\n";
            if (bookticket)
                bookticket->book(difficulty);
        }
    }
};

class Supervisor : public BookTicket {
public:
    void book(int difficulty) override {
        if (difficulty <= 8) {
            cout << "Ticket Booked Through Supervisor\n";
            return;
        } else {
            cout << "Ticket cannot be booked by Supervisor, trying Manager...\n";
            if (bookticket)
                bookticket->book(difficulty);
        }
    }
};

class Manager : public BookTicket {
public:
    void book(int difficulty) override {
        if (difficulty <= 10) {
            cout << "Ticket Booked Through Manager\n";
            return;
        } else {
            cout << "No seat available. Better luck next time.\n";
        }
    }
};

int main() {
    BookTicket* SA = new SupportA();
    BookTicket* SB = new SupportB();
    BookTicket* SC = new SupportC();
    BookTicket* SU = new Supervisor();
    BookTicket* MG = new Manager();

    SA->tryChain(SB);
    SB->tryChain(SC);
    SC->tryChain(SU);
    SU->tryChain(MG);

    vector<int> arr = {-3, 2, 4, 6, 8, 10,12};

    for (auto val : arr) {
        cout << "Difficulty: " << val << endl;
        SA->book(val);
        cout << "---------------------------\n";
    }

    delete SA;
    delete SB;
    delete SC;
    delete SU;
    delete MG;

    return 0;
}
