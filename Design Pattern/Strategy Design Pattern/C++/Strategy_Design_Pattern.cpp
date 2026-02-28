#include <iostream>
using namespace std;

class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() {};
};

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Normal work" << endl;
    }
};

class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Cannot walk" << endl;
    }
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() {};
};

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Fly normally..." << endl;
    }
};

class NoFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Can't Fly" << endl;
    }
};

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() {};
};

class NormalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Normal Talk" << endl;
    }
};

class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "No talk" << endl;
    }
};

class Robot
{
protected:
    Walkable *walkBehaviour;
    Talkable *talkBehaviour;
    Flyable *flyBehaviour;

public:
    Robot(Walkable *w, Talkable *t, Flyable *f)
    {
        this->flyBehaviour = f;
        this->talkBehaviour = t;
        this->walkBehaviour = w;
    }

    void walk()
    {
        walkBehaviour->walk();
    }

    void fly()
    {
        flyBehaviour->fly();
    }

    void talk()
    {
        talkBehaviour->talk();
    }

    virtual void projection() = 0;
};

// Concrete Robot Type

class CompanionRobot : public Robot
{
public:
    CompanionRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Displaying worker robot..." << endl;
    }
};

int main()
{

    Robot *rb1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    rb1->walk();
    rb1->fly();
    rb1->talk();
    rb1->projection();

    cout<<"----------------------------------------------"<<endl;

    Robot *rb2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());

    rb2->walk();
    rb2->fly();
    rb2->talk();
    rb2->projection();

    return 0;
}