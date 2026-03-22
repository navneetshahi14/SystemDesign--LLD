#include <iostream>
#include <vector>
using namespace std;

class Character
{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}
};

class Mario : public Character
{
public:
    string getAbilities() const override
    {
        return "Mario";
    }
};

class CharacterDecorator : public Character
{
protected:
    Character *character;

public:
    CharacterDecorator(Character *ch)
    {
        this->character = ch;
    }
};

class HeightUp : public CharacterDecorator
{
public:
    HeightUp(Character *c) : CharacterDecorator(c) {}
};

int main()
{

    return 0;
}