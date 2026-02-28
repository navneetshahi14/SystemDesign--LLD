#include <iostream>
using namespace std;

class Document
{
    string content;

public:
    Document(string content)
    {
        this->content = content;
    }

    string getContent()
    {
        return this->content;
    }
};

class Printer
{
public:
    void printing(Document &docs)
    {
        cout << "Printing " << docs.getContent() << endl;
    }
};

int main()
{

    Document docs("Hello world");

    Printer printer;

    printer.printing(docs);

    return 0;
}