#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction(int numerator = 0 , int denominator = 1)
            : numerator(numerator), denominator(denominator) {
                std::cout << "Constructor: " << numerator << " " << denominator << std::endl;
            }
        
        void setNumerator(int numerator) {
            this->numerator = numerator;
        }

        int getNumerator() const {
            return numerator;
        }

        void setDenominator(int denominator) {
            if (denominator == 0) {
                std::cout << "denominator cannot be 0" << std::endl;
                return;
            }
            this->denominator = denominator;
        }

        int getDenominator() const {
            return denominator;
        }

        void printFraction() const {
            std::cout << numerator << '/' << denominator << std::endl;
        }

        Fraction operator+(const Fraction& other) const {
            int newNumerator = numerator * other.denominator + other.numerator*denominator;
            int newDenominator = denominator * other.denominator;
            return Fraction(newNumerator, newDenominator);        
        }

        Fraction operator+(int num) { //not needed
            return this->operator+(Fraction(num));
        }
};

Fraction operator+(int num, const Fraction& fraction) {
    return fraction + num; //revert to RHS
    // return Fraction(num) + fraction; //invoke constructor
}

int main() {
    // Operator Overloading is a form of polymorphism
    // Provides functionalities with operators instead of method calls
    // Operators can be overloaded with different parameter types
    // Some operators can invoke the constructor for implicit type conversion
    // Operators can be overloaded outside the class to support operations with other classes

    Fraction frac1(11, 15);
    Fraction frac2(2, 3);
    // Fraction frac3 = frac1.operator+(frac2);
    Fraction frac3 = frac1 + frac2;
    frac3.printFraction();

    //will try to implicitly convert 2 to a fraction via Fraction(2)
    Fraction frac4 = frac1 + 2;
    // Fraction frac4 = frac1 + (Fraction) 2; //explicit type conversion
    frac4.printFraction();

    //equal to 2.operator+(frac1), which isn't supported by int
    Fraction frac5 = 2 + frac1;
    frac5.printFraction();
}

