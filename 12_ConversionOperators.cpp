#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction(int numerator = 0, int denominator = 1)
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

        operator int() {
            return numerator/denominator; //int division
        }

        operator double() {
            // return numerator/denominator; //int division
            return (double) numerator/denominator;
        }

        operator float() {
            // return numerator/denominator; //int division
            return (float) numerator/denominator;
        }

        operator bool() { //implicit conversion
            return numerator != 0;
        }

};

int main() {
    // Operator Overloading is a form of polymorphism
    // Provides functionalities with operators instead of method calls
    // We can overload type conversions for primitive types: int, double, float, bool, char
    // Primitive types can be converted between each other

    //explicit conversion (type casting)
    Fraction frac1(151, 15);
    std::cout << (int) frac1 << std::endl;
    std::cout << (double) frac1 << std::endl; //will convert to int if double isn't supported
    std::cout << (float) frac1 << std::endl;
    std::cout << (bool) frac1 << std::endl;
    
    //implicit conversion
    int num1 = frac1;
    std::cout << num1 << std::endl;
    
    if (frac1) {
        std::cout << "not equal to 0" << std::endl;
    }
    else {
        std::cout << "equal to 0" << std::endl;
    }

    //frac1 is converted to an int, will cause ambiguity with multiple operator types
    // std::cout << frac1 + 15 << std::endl;
    std::cout << (int) frac1 + 15 << std::endl; //explicit type cast instead

}

