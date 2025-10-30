#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        void setNumerator(int n) {
            numerator = n;
        }

        int getNumerator() {
            return numerator;
        }

        void setDenominator(int n) {
            if (n == 0) {
                std::cout << "denominator cannot be 0" << std::endl;
                return;
            }
            denominator = n;
        }

        int getDenominator() {
            return denominator;
        }

        void printFraction() {
            std::cout << numerator << '/' << denominator << std::endl;
        }
};

int main() {
    // Access specifiers control how the members of a class can be accessed.
    //     public - members are accessible outside the class
    //     private - members cannot be accessed outside the class
    //     protected - members cannot be accessed outside the class, but can be accessed by inheritance
    // In C++, structs are public by default, classes are private
    // To access and update the members, we add getters (get value), and setters (set value)

    Fraction frac;
    // frac.numerator = 11;
    // frac.denominator = 15;
    frac.setNumerator(11);
    frac.setDenominator(15);
    frac.setDenominator(0); //error message

    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << std::endl;
    frac.printFraction();
}

