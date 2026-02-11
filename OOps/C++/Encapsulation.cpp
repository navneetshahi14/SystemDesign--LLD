#include <iostream>
#include <vector>
using namespace std;

class Product{
    private:
        string name;
        int price;

    public:
        Product(string name, int price){
            this->name = name;
            this->price = price;
        }

        string getName() const {
            return name;
        }

        int getPrice() const{
            return price;
        }
};

int main() {

return 0;
}