#include<bits/stdc++.h>
using namespace std;

// Notification & Decorator
class INotification {
public:
    virtual string getcontent() const = 0;
    virtual ~INotification() {};
};

// Concrete Notification: Simple text notification
class simpleNotification : public INotification {
private:
    string text;
public:
    simpleNotification(const string &msg) : text(msg) {}

    string getcontent() const override {
        return text;
    }
};

class INotificationDecorator : public INotification {
protected:
    INotification *notification;
public:
    INotificationDecorator(INotification *a) : notification(a) {}
    virtual ~INotificationDecorator() {
        delete notification;
    }
};

class TimeStampDecorator : public INotificationDecorator {
public:
    TimeStampDecorator(INotification *n) : INotificationDecorator(n) {}
    string getcontent() const override {
        return "[2024-04-13 14:22:00] " + notification->getcontent();
    }
};

class SignatureDecorator : public INotificationDecorator {
public:
    string signature;
    SignatureDecorator(INotification *n, const string &sign)
        : INotificationDecorator(n), signature(sign) {}

    string getcontent() const override {
        return notification->getcontent() + "\n--" + signature + "\n\n";
    }
};

// Observer Pattern components
class IObserver {
public:
    virtual void update() = 0;
    virtual ~IObserver() {};
};

class IObservable {
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObservable() {}
};

// Concrete Observable
class NotificationObservable : public IObservable {
private:
    vector<IObserver*> observers;
    INotification *currentNotification;
public:
    NotificationObservable() {
        currentNotification = nullptr;
    }
    void addObserver(IObserver *obs) override {
        observers.push_back(obs);
    }

    void removeObserver(IObserver *obs) override {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void setNotifcation(INotification *notification) {
        if (currentNotification != nullptr) {
            delete currentNotification;
        }
        currentNotification = notification;
        notifyObservers();
    }

    INotification *getNotification() {
        return currentNotification;
    }

    string getNotificationContent() {
        if (currentNotification)
            return currentNotification->getcontent();
        return "";
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update();
        }
    }

    ~NotificationObservable() {
        if (currentNotification != nullptr)
            delete currentNotification;
    }
};

// Logger
class Logger : public IObserver {
private:
    NotificationObservable *notificationObservable;
public:
    Logger(NotificationObservable *obs) : notificationObservable(obs) {}

    void update() override {
        cout << "Logging New Notification : \n" << notificationObservable->getNotificationContent() << endl;
    }
};

// Strategy Pattern Components
class INotificationStrategy {
public:
    virtual void sendNotification(string content) = 0;
    virtual ~INotificationStrategy() {}
};

class EmailStrategy : public INotificationStrategy {
private:
    string emailId;
public:
    EmailStrategy(string Emailid) : emailId(Emailid) {}

    void sendNotification(string content) override {
        cout << "Sending email Notification to : " << emailId << "\n" << content << endl;
    }
};

class SMSStrategy : public INotificationStrategy {
private:
    string mobileNumber;
public:
    SMSStrategy(string number) : mobileNumber(number) {}

    void sendNotification(string content) override {
        cout << "Sending SMS notification to : " << mobileNumber << "\n" << content << endl;
    }
};

class PopUpStrategy : public INotificationStrategy {
public:
    void sendNotification(string content) override {
        cout << "Sending popUp Notification : \n" << content << endl;
    }
};

class NotificationEngine : public IObserver {
private:
    NotificationObservable *notificatioObs;
    vector<INotificationStrategy*> notificationStrategies;
public:
    NotificationEngine(NotificationObservable *obs) : notificatioObs(obs) {}

    void addNotificationStrategy(INotificationStrategy *ns) {
        this->notificationStrategies.push_back(ns);
    }

    void update() override {
        string notificationContent = notificatioObs->getNotificationContent();
        for (auto* strategy : notificationStrategies) {
            strategy->sendNotification(notificationContent);
        }
    }

    ~NotificationEngine() {
        for (auto* strategy : notificationStrategies)
            delete strategy;
    }
};

// NotificationService
class NotificationService {
private:
    NotificationObservable *observable;
    static NotificationService* instance;
    NotificationService() {
        observable = new NotificationObservable();
    }

public:
    static NotificationService *getInstance() {
        if (instance == nullptr) {
            instance = new NotificationService();
        }
        return instance;
    }

    NotificationObservable *getObservable() {
        return observable;
    }

    void sendNotification(INotification *notification) {
        observable->setNotifcation(notification);
    }

    ~NotificationService() {
        delete observable;
    }
};

NotificationService *NotificationService::instance = nullptr;

int main()
{
    NotificationService * notificationService = NotificationService::getInstance();
    NotificationObservable *notificationObservable = notificationService->getObservable();

    Logger *logger = new Logger(notificationObservable);
    NotificationEngine *notificationEngine = new NotificationEngine(notificationObservable);

    notificationEngine->addNotificationStrategy(new EmailStrategy("random.personal@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 1234567890"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    INotification *notification  = new simpleNotification("Your Order Have been shipped");
    notification  = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer Care");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}
