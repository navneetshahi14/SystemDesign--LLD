#include <iostream>
#include <vector>
using namespace std;

enum class OrderStatus
{
    PLACED,
    CONFIRMED,
    SHIPPED,
    DELIVERED,
    CANCELLED
};

enum class Coin
{
    PENNY,
    NICKEL,
    DIME,
    QUARTER
};

int getCoinValue(Coin coin)
{
    switch (coin)
    {
    case Coin::PENNY:
        return 1;
    case Coin::NICKEL:
        return 5;
    case Coin::DIME:
        return 10;
    case Coin::QUARTER:
        return 25;
    default:
        return 0;
    }
}

int main()
{

    OrderStatus status = OrderStatus::SHIPPED;

    if (status == OrderStatus::SHIPPED)
    {
        cout << "Your package is on the way!" << endl;
    }

    return 0;
}