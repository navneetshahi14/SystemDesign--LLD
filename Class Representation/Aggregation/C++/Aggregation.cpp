#include <iostream>
#include <vector>
using namespace std;

class Developer
{
private:
    string name;

public:
    Developer(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }
};

class Team
{

private:
    string name;
    vector<Developer *> devs;

public:
    Team(string name, vector<Developer *> devs)
    {
        this->name = name;
        this->devs = devs;
    }

    void printDevs()
    {
        cout << "Devs in " << this->name << " Team " << endl;
        for (int i = 0; i < this->devs.size(); i++)
        {
            cout << devs[i]->getName() << endl;
        }
    }
};

int main()
{

    return 0;
}