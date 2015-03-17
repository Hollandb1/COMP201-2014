#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string email;
    string phone;
    string location;
};
struct Person {
    string name;
    int age;
    Contact contact;
};
int main() {
    // Allocates the space for a person on the stack
    Person me;
    // Allocates a pointer and that's it
    Person * them = &me;
    // Allocates a pointer, but it also creates a person on the heap
    Person * you = new Person;
    {
        them->name = "Joey";
        them->age = 33;
        them->contact.email = "lawrancej@wit.edu";
        them->contact.phone = "(617) 989-4749";
        them->contact.location = "Wentworth Institute of Technology";
        cout << me.name << " works at " << me.contact.location << endl;
        cout << me.name << " is " << me.age << " years old" << endl;
    }
    cout << (*them).name << " works at " << (*them).contact.location << endl;
    cout << them->name << " is " << them->age << " years old" << endl;
    you->name = "Bob the builder";
    you->age = 60000;
    you->contact.email = "builderb2@wit.edu";
    you->contact.phone = "(617) 989-9999";
    you->contact.location = "Wentworth Institute of Technology";
    cout << (*you).name << " works at " << (*you).contact.location << endl;
    cout << you->name << " is " << you->age << " years old" << endl;

    return 0;
}