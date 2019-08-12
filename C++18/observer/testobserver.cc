#include "subject.h"
#include "observer.h"
#include <memory>

int main(int argc, char *argv[])
{
    unique_ptr<Observer> baby1(new Baby("lucy"));
    unique_ptr<Observer> baby2(new Baby("Nancy"));
    unique_ptr<Observer> nurse1(new Nurse("xiaomao"));
    unique_ptr<Observer> nurse2(new Nurse("xiaoli"));

    Ring ring;
    ring.attach(baby1.get());
    ring.attach(baby2.get());
    ring.attach(nurse1.get());
    ring.attach(nurse2.get());

    Guest guest("Lucaus");
    guest.knock(ring);
    ring.detach(nurse1.get());
    cout << "hhh" << endl;
    guest.knock(ring);
    return 0;
}