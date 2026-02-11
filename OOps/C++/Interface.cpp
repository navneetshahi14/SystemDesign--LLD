#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

class IPaymentGateway
{
public:
    virtual ~IPaymentGateway() {}
    virtual void initiatePayment(double amount) = 0;
};

class StripePayment : public IPaymentGateway
{
public:
    void initiatePayment(double amount) override
    {
        cout << "Processing payment via Stripe: $" << amount << endl;
    }
};

class RazoPay : public IPaymentGateway
{
public:
    void initiatePayment(double amount) override
    {
        cout << "Processing payment via RazorPay: $" << amount << endl;
    }
};

class CheckOutService
{
private:
    IPaymentGateway *paymentGateway;

public:
    CheckOutService(IPaymentGateway *gateway) : paymentGateway(gateway) {}

    void setPaymentGateway(IPaymentGateway *gateway)
    {
        paymentGateway = gateway;
    }

    void checkout(double amount)
    {
        if (paymentGateway != nullptr)
        {
            paymentGateway->initiatePayment(amount);
        }
    }
};

int main()
{

    StripePayment stripeGateway;

    CheckOutService service(&stripeGateway);

    service.checkout(120.5);

    RazoPay razopay;
    service.setPaymentGateway(&razopay);
    service.checkout(200.2);

    return 0;
}