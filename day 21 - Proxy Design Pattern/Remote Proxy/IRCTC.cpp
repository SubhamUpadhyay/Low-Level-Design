#include <iostream>
using namespace std;

// Subject Interface
class DataService {
public:
    virtual void fetchData() = 0;
    virtual ~DataService() {}
};

// Real Service (acts like a remote server)
class RemoteDataService : public DataService {
public:
    void fetchData() override {
        cout << "Fetching data from remote server...\n";
    }
};

// Remote Proxy
class DataProxy : public DataService {
    RemoteDataService* remoteService;

public:
    DataProxy() : remoteService(nullptr) {}

    void fetchData() override {
        cout << "Client contacted proxy...\n";
        if (!remoteService) remoteService = new RemoteDataService();
        remoteService->fetchData();
    }

    ~DataProxy() {
        delete remoteService;
    }
};

int main() {
    DataService* client = new DataProxy();
    client->fetchData();

    delete client;
    return 0;
}
