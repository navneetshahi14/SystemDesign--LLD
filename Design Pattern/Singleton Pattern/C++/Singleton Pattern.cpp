#include <iostream>
#include <mutex>
using namespace std;

// Lazy Initialization
class LazySingleton
{
private:
    static LazySingleton *instance;

    LazySingleton() {}

public:
    static LazySingleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new LazySingleton();
        }
        return instance;
    }
};

// Thread Safe
class ThreadSafeSingleton
{
private:
    static ThreadSafeSingleton *instance;
    static mutex lock;

    ThreadSafeSingleton() {}

public:
    static ThreadSafeSingleton *getInstance()
    {
        lock_guard<mutex> guard(lock);
        if (instance == nullptr)
        {
            instance = new ThreadSafeSingleton();
        }
        return instance;
    }
};

// Double Check Lock
class DoublecheckedSingletonLock
{
    static DoublecheckedSingletonLock *instance;
    static mutex lock;

    DoublecheckedSingletonLock() {};

public:
    static DoublecheckedSingletonLock *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> guard(lock);
            if (instance == nullptr)
            {
                instance = new DoublecheckedSingletonLock();
            }
        }

        return instance;
    }
};

// Eager Singleton
class EagerSingleton{
    private:
        static EagerSingleton* instance;

        EagerSingleton(){}

    public:
        static EagerSingleton* getInstance(){
            return instance;
        }
};

// Bill pugh singleton
class BillPughSingleton{
    private:
        BillPughSingleton(){}

    public:
        static BillPughSingleton* getInstance(){
            static BillPughSingleton instance;
            return &instance;
        }
};

int main()
{

    return 0;
}