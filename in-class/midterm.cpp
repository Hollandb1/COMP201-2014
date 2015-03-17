#include <iostream>
#include <string>
#include <fstream>

class Something
{
public:
    Something() {
        stuff = 42;
    }
    int getStuff() {
        return stuff;
    }
    friend int function (Something & something) {
        return something.stuff;
    }
private:
    int stuff;
};

struct MyStruct
{
    int size;
    float weight;
};

struct DateType
{
	int day;
	int month;
	int year;
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

    friend void display(std::ostream& out, const Rational& value);
private:
    int numerator;
    int denominator;
};

// This defines the constructor
Rational::Rational() {
    
}

void display(std::ostream& out, const Rational& value) {
    
}

using namespace std;

int main() {
    int x;
    int y = 123;
    
    ItemClass myItem;
    ifstream fin;
    DateType today = {27,2,2015};
    today.day = 27;
    today.month = 2;
    today.year = 2015;
    Something wonderful;
    string line;
    getline(std::cin, line);
    std::cout << function(wonderful) << std::endl;
    return 0;
}