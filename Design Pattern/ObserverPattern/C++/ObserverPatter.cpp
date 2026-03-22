#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ISubscriber
{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel
{
public:
    virtual void subscribe(ISubscriber *sub) = 0;
    virtual void unsubscribe(ISubscriber *sub) = 0;
    virtual void notifySubs() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel
{
private:
    vector<ISubscriber *> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string &name)
    {
        this->name = name;
    }

    void subscribe(ISubscriber *sub) override
    {
        if (find(subscribers.begin(), subscribers.end(), sub) == subscribers.end())
        {
            subscribers.push_back(sub);
        }
    }

    void unsubscribe(ISubscriber *subscribe) override
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscribe);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }

    void notifySubs() override
    {
        for (ISubscriber *sub : subscribers)
        {
            sub->update();
        }
    }

    void uploadVideo(const string &title)
    {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"\n";
        notifySubs();
    }

    string getVideoData()
    {
        return "\nCheckout our new Video: " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber
{
private:
    string name;
    Channel *channel;

public:
    Subscriber(const string &name, Channel *channel)
    {
        this->name = name;
        this->channel = channel;
    }

    void update() override
    {
        cout << "Hey " << name << ", " << this->channel->getVideoData();
    }
};

int main()
{

    Channel *channel = new Channel("Robinav");
    Subscriber *sub1 = new Subscriber("Navneet", channel);
    Subscriber *sub2 = new Subscriber("Saksham", channel);

    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("Observer Pattern Tutorial");

    channel->unsubscribe(sub1);

    channel->uploadVideo("Decrator Pattern tutorial");

    return 0;
}