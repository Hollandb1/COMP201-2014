#include <string>
#include <iostream>
#include <vector>

struct Person {
    int age;
    std::string name;
};

struct DateType
{
	int day;
	int month;
	int year;
};
struct PersonType
{
	int age;
	float weight;
	DateType birthday;
};

class Someone {
public:
    Someone() {
        age = 42;
    }
    friend int getAge(Someone & someone) {
        return someone.age;
    }
private:
    int age;
};

class ItemClass
{
public:
	ItemClass( ) {
        size = 42;
    }
	ItemClass(int newSize, float newCost);
	int getSize( );
	float getCost( );
	void setSize(int newSize);
	void setCost(float newCost);
private:
	int size;
	float cost;
};

class Rational
{
public:
    Rational();
    Rational(int numer, int denom);
    Rational(int whole);

    int getNumerator();
    int getDenominator();

//    friend void display(ostream& out, const Rational& value);
private:
    int numerator;
    int denominator;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

int main() {
    using namespace std;

    vector < float > numbers; 

    cout << numbers.size() << endl;
    Rational num1;
    Rational num2;
    
    string line;
    getline(cin, line);
/*    ItemClass myItem;
//    ItemClass myOtherItem;

    Someone mumble;
    std::cout << getAge(mumble) << std::endl;
    DateType today = {1,1,2000};
    today.day = 27;
    today.month = 2;
    today.year = 2015;
    PersonType joey;
    joey.age = 33;
    joey.weight = 72;
    joey.birthday.year = 1981;
    // you are on the stack, Spock
    Person you;
    you.age = 83;
    you.name = "Leonard Nimoy";
    
    // I'm on the heap
    Person * me = new Person;
    me->age = 33;
    me->name = "Joey Lawrance";
    
    delete me;
    */
    
}