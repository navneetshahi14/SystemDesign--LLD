#include <iostream>
using namespace std;

class EmailValidator
{
public:
    static bool isValid(string email)
    {
        if (email.empty())
            return false;
        bool hasAt = email.find('@') != string::npos;
        bool hasDot = email.find('.') != string::npos;
        bool validEnding = email.size() >= 4 && (email.substr(email.size() - 4) == ".com" || email.substr(email.size() - 4) == ".org");
        return hasAt && hasDot && validEnding;
    }
};

int main()
{

    string email = "navneet.shahi2004@gmail.com";
    if (EmailValidator::isValid(email))
    {
        // logic
    }



    return 0;
}