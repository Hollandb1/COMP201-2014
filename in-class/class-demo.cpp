#include <iostream>
using namespace std;

class Object {
public:
    Object(string saythis) {
        greeting = saythis;
    }
    void speak() {
        cout << greeting << endl;
    }
private:
    string greeting;
};

int main() {
    Object cow("moo");
    Object pig("oink");
    
    Object * person;
    person = new Object("hello");
    
    cow.speak();
    pig.speak();
    
    // This is dorky:
    (*person).speak();
    // is the same as
    // Please do it this way:
    person->speak();
    
    delete person;
}