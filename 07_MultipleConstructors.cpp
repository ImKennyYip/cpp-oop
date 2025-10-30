#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction() {
            this->numerator = 0;
            this->denominator = 1;
        }

        // Fraction(int numerator) { //ambiguity with constructor below
        //     this->numerator = numerator;
        //     this->denominator = 1;
        // }

        Fraction(int numerator, int denominator = 1) { //default parameter
            this->numerator = numerator;
            this->denominator = denominator;
        }
        
        void setNumerator(int numerator) {
            this->numerator = numerator;
        }

        int getNumerator() const {
            return this->numerator;
        }

        void setDenominator(int denominator) {
            if (denominator == 0) {
                std::cout << "denominator cannot be 0" << std::endl;
                return;
            }
            this->denominator = denominator;
        }

        int getDenominator() const {
            return this->denominator;
        }

        void printFraction() const {
            std::cout << this->numerator << '/' << this->denominator << std::endl;
        }
};

int main() {
    // Access specifiers control how the members of a class can be accessed.
    // Constructors are used to initialize values upon object creation
    // When an object is created, the constructor is invoked

    Fraction frac1(11, 15);
    frac1.printFraction();

    Fraction frac2(11);
    frac2.printFraction();

    Fraction frac3; //default constructor needs to specified
    frac3.printFraction();
}