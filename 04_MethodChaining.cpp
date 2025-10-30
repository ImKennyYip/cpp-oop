#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction& setNumerator(int n) {
            numerator = n;
            return *this; //this is a pointer to self object, dereference to get object
        }

        int getNumerator() {
            return numerator;
        }

        Fraction& setDenominator(int n) {
            if (n == 0) {
                std::cout << "denominator cannot be 0" << std::endl;
                return;
            }
            denominator = n;
            return *this; //this is a pointer to self object, dereference to get object
        }

        int getDenominator() {
            return denominator;
        }

        Fraction& printFraction() {
            std::cout << numerator << '/' << denominator << std::endl;
            return *this; //this is a pointer to self object, dereference to get object
        }
};

int main() {
    // Method chaining is a technique for invoking consecutive method calls
    // Member functions that return void, can return a reference to the object instead
    // The reference can then be used to call another method 

    Fraction frac;
    // frac.setNumerator(11);
    // frac.setDenominator(15);
    // frac.printFraction();

    // Fraction& frac2 = frac.setNumerator(11);
    // frac2.setDenominator(15);
    frac.setNumerator(11).setDenominator(15).printFraction();
}

