#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ----------------------------
// Data structure for payment details (converted to class)
// ----------------------------
class PaymentRequest {
private:
    string sender;
    string receiver;
    double amount;
    string currency;

public:
    PaymentRequest(const string& sender, const string& receiver, double amt, const string& curr)
        : sender(sender), receiver(receiver), amount(amt), currency(curr) {}

    const string& getSender() const { return sender; }
    const string& getReceiver() const { return receiver; }
    double getAmount() const { return amount; }
    const string& getCurrency() const { return currency; }
};

// ----------------------------
// Banking System interface and implementations (Strategy)
// ----------------------------
class BankingSystem {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~BankingSystem() {}
};

class PaytmBankingSystem : public BankingSystem {
public:
    bool processPayment(double amount) override {
        int r = rand() % 100;
        return r < 80;
    }
};

class RazorpayBankingSystem : public BankingSystem {
public:
    bool processPayment(double amount) override {
        cout << "[BankingSystem-Razorpay] Processing payment of " << amount << "...\n";
        int r = rand() % 100;
        return r < 90;
    }
};

// ----------------------------
// Abstract base class for Payment Gateway (Template Method Pattern)
// ----------------------------
class PaymentGateway {
protected:
    BankingSystem* bankingSystem;
public:
    PaymentGateway() { bankingSystem = nullptr; }
    virtual ~PaymentGateway() { delete bankingSystem; }

    virtual bool processPayment(PaymentRequest* request) {
        if (!validatePayment(request)) {
            cout << "[PaymentGateway] Validation failed for " << request->getSender() << ".\n";
            return false;
        }
        if (!initiatePayment(request)) {
            cout << "[PaymentGateway] Initiation failed for " << request->getSender() << ".\n";
            return false;
        }
        if (!confirmPayment(request)) {
            cout << "[PaymentGateway] Confirmation failed for " << request->getSender() << ".\n";
            return false;
        }
        return true;
    }

    virtual bool validatePayment(PaymentRequest* request) = 0;
    virtual bool initiatePayment(PaymentRequest* request) = 0;
    virtual bool confirmPayment(PaymentRequest* request) = 0;
};

class PaytmGateway : public PaymentGateway {
public:
    PaytmGateway() {
        bankingSystem = new PaytmBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Validating payment for " << request->getSender() << ".\n";
        return request->getAmount() > 0 && request->getCurrency() == "INR";
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Initiating payment of " << request->getAmount() << " "
             << request->getCurrency() << " for " << request->getSender() << ".\n";
        return bankingSystem->processPayment(request->getAmount());
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Paytm] Confirming payment for " << request->getSender() << ".\n";
        return true;
    }
};

class RazorpayGateway : public PaymentGateway {
public:
    RazorpayGateway() {
        bankingSystem = new RazorpayBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Validating payment for " << request->getSender() << ".\n";
        return request->getAmount() > 0;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Initiating payment of " << request->getAmount() << " "
             << request->getCurrency() << " for " << request->getSender() << ".\n";
        return bankingSystem->processPayment(request->getAmount());
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Razorpay] Confirming payment for " << request->getSender() << ".\n";
        return true;
    }
};

class PaymentGatewayProxy : public PaymentGateway {
    PaymentGateway* realGateway;
    int retries;
public:
    PaymentGatewayProxy(PaymentGateway* gateway, int maxRetries) {
        realGateway = gateway;
        retries = maxRetries;
    }
    ~PaymentGatewayProxy() {
        delete realGateway;
    }
    bool processPayment(PaymentRequest* request) override {
        bool result = false;
        for (int attempt = 0; attempt < retries; ++attempt) {
            if (attempt > 0) {
                cout << "[Proxy] Retrying payment (attempt " << (attempt + 1)
                     << ") for " << request->getSender() << ".\n";
            }
            result = realGateway->processPayment(request);
            if (result) break;
        }
        if (!result) {
            cout << "[Proxy] Payment failed after " << retries
                 << " attempts for " << request->getSender() << ".\n";
        }
        return result;
    }
    bool validatePayment(PaymentRequest* request) override {
        return realGateway->validatePayment(request);
    }
    bool initiatePayment(PaymentRequest* request) override {
        return realGateway->initiatePayment(request);
    }
    bool confirmPayment(PaymentRequest* request) override {
        return realGateway->confirmPayment(request);
    }
};

enum class GatewayType {
    PAYTM,
    RAZORPAY
};

class GatewayFactory {
private:
    static GatewayFactory instance;
    GatewayFactory() {}
    GatewayFactory(const GatewayFactory&) = delete;
    GatewayFactory& operator=(const GatewayFactory&) = delete;

public:
    static GatewayFactory& getInstance() {
        return instance;
    }
    PaymentGateway* getGateway(GatewayType type) {
        if (type == GatewayType::PAYTM) {
            return new PaymentGatewayProxy(new PaytmGateway(), 3);
        } else {
            return new PaymentGatewayProxy(new RazorpayGateway(), 1);
        }
    }
};

GatewayFactory GatewayFactory::instance;

class PaymentService {
private:
    static PaymentService instance;
    PaymentGateway* gateway;
    PaymentService() { gateway = nullptr; }
    ~PaymentService() { delete gateway; }
    PaymentService(const PaymentService&) = delete;
    PaymentService& operator=(const PaymentService&) = delete;

public:
    static PaymentService& getInstance() {
        return instance;
    }
    void setGateway(PaymentGateway* g) {
        if (gateway) delete gateway;
        gateway = g;
    }
    bool processPayment(PaymentRequest* request) {
        if (!gateway) {
            cout << "[PaymentService] No payment gateway selected.\n";
            return false;
        }
        return gateway->processPayment(request);
    }
};

PaymentService PaymentService::instance;

class PaymentController {
private:
    static PaymentController instance;
    PaymentController() {}
    PaymentController(const PaymentController&) = delete;
    PaymentController& operator=(const PaymentController&) = delete;

public:
    static PaymentController& getInstance() {
        return instance;
    }
    bool handlePayment(GatewayType type, PaymentRequest* req) {
        PaymentGateway* paymentGateway = GatewayFactory::getInstance().getGateway(type);
        PaymentService::getInstance().setGateway(paymentGateway);
        return PaymentService::getInstance().processPayment(req);
    }
};

PaymentController PaymentController::instance;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    PaymentRequest* req1 = new PaymentRequest("Aditya", "Shubham", 1000.0, "INR");
    cout << "Processing via Paytm\n";
    cout << "------------------------------\n";
    bool res1 = PaymentController::getInstance().handlePayment(GatewayType::PAYTM, req1);
    cout << "Result: " << (res1 ? "SUCCESS" : "FAIL") << "\n";
    cout << "------------------------------\n\n";

    PaymentRequest* req2 = new PaymentRequest("Shubham", "Aditya", 500.0, "USD");
    cout << "Processing via Razorpay\n";
    cout << "------------------------------\n";
    bool res2 = PaymentController::getInstance().handlePayment(GatewayType::RAZORPAY, req2);
    cout << "Result: " << (res2 ? "SUCCESS" : "FAIL") << "\n";
    cout << "------------------------------\n";

    return 0;
}
