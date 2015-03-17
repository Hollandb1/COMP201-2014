#include <iostream>
#include <string>
using namespace std;
struct Location {
    double latitude;
    double longitude;
    string name;
};
// Group together related stuff
struct Person {
    string name;
    int age;
    Location location;
};

// RAM[pointer]     *pointer    De-reference (follow the pointer)
// data = 42
//                  &data       Address of

void age(Person person) {
    person.age ++;
}

int main() {
    // Allocates memory on the stack
    Person * people = new Person[20];
    people->name = "Joey";
    return 0;
}

int oldIshMain() {
    // Allocates memory on the stack
    Person him;
    Person * me = new Person;
    me = &him;
    me->name = "Joey";
    (*me).age = 33;
    me->location.latitude = 42;
    me->location.longitude = 22;
    me->location.name = "Wentworth Institute of Technology";
    age(*me);
    
    cout << me->name << " works at " << me->location.name << endl;
    cout << me->name << " is " << me->age << " years old" << endl;
    return 0;
}



int oldMain() {
    // Allocates memory on the stack
    Person me;
    me.name = "Joey";
    me.age = 33;
    me.location.latitude = 42;
    me.location.longitude = 22;
    me.location.name = "Wentworth Institute of Technology";
    cout << me.name << " works at " << me.location.name << endl;
    return 0;
}