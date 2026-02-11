#include <iostream>
#include <string>
using namespace std;

// create a car class with methods acclerate and displayStatus

class Car
{
private:
    string brand;
    string model;
    int speed;

public:
    Car(string brand, string model){
        this->brand = brand;
        this->model = model;
        this->speed = 0;
    }

    void accelerate (int increment) {
        speed += increment;
    }

    void displayStatus(){
        cout<<brand<<" is running at "<<speed<<" km/hr "<<endl;
    }
};

int main()
{
}