#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction(int numerator = 0 , int denominator = 1)
            : numerator(numerator), denominator(denominator) {}
        
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
        
        friend Fraction operator+(int num, const Fraction& fraction) {
            int newNumerator = num * fraction.denominator + fraction.numerator;
            int newDenominator = fraction.denominator;
            return Fraction(newNumerator, newDenominator);        
        };

        friend Fraction operator+(int, const Fraction&);
};

Fraction operator+(int num, const Fraction& fraction) {
    // int newNumerator = num * fraction.getDenominator() + fraction.getNumerator();
    // int newDenominator = fraction.getDenominator();
    int newNumerator = num * fraction.denominator + fraction.numerator;
    int newDenominator = fraction.denominator;
    return Fraction(newNumerator, newDenominator);        
};

int main() {
    // Operators can be overloaded outside the class to support operations with other classes
    // Classes can provide access to private fields to others via friend functions
    // Friend functions are still "outside the class" but can access private fields
    // Use friend functions sparingly as too many will violate the idea of encapsulation
    // Friend functions are not inherited since they are not member functions

    Fraction frac1(11, 15);

    Fraction frac2 = frac1 + 2;
    frac2.printFraction();

    Fraction frac3 = 2 + frac1;
    frac3.printFraction();

}

