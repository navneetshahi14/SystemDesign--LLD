#include <iostream>
#include <vector>
using namespace std;

// Unidirectional Association
class PaymentGateway
{
public:
    void processPayment(double amount)
    {
        cout << "Processing payment of $" << amount << endl;
    }
};

class Order
{
private:
    PaymentGateway *paymentgateway;

public:
    Order(PaymentGateway *paymentgateway)
    {
        this->paymentgateway = paymentgateway;
    }

    void checkout()
    {
        paymentgateway->processPayment(100.0);
    }
};

// Bidirectional Association
class Developer
{

    private:
        Team* team;

    public:
        void setTeam(Team* team){
            this->team = team;
        }
};

class Team
{
    private:
        vector<Developer*> devs;

    public:
        void addDevs(Developer* dev){
            devs.push_back(dev);
            dev->setTeam(this);
        }
};

int main()
{

    return 0;
}