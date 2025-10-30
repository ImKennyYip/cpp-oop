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

        Fraction add(const Fraction& other) const {
            int newNumerator = numerator * other.denominator + other.numerator*denominator;
            int newDenominator = denominator * other.denominator;
            return Fraction(newNumerator, newDenominator);
        }

        Fraction subtract(const Fraction& other) const {
            int newNumerator = numerator * other.denominator - other.numerator*denominator;
            int newDenominator = denominator * other.denominator;
            return Fraction(newNumerator, newDenominator);
        }

        Fraction multiply(const Fraction& other) const {
            int newNumerator = numerator * other.numerator;
            int newDenominator = denominator * other.denominator;
            return Fraction(newNumerator, newDenominator);
        }

        Fraction divide(const Fraction& other) const {
            int newNumerator = numerator * other.denominator;
            int newDenominator = denominator * other.numerator;
            return Fraction(newNumerator, newDenominator);
        }

        Fraction operator+(const Fraction& other) {
            // int newNumerator = numerator * other.denominator + denominator * other.numerator;
            // int newDenominator = denominator * other.denominator;
            // return Fraction(newNumerator, newDenominator);
            return add(other);
        }

        Fraction operator-(const Fraction& other) {
            return subtract(other);
        }

        Fraction operator*(const Fraction& other) {
            return multiply(other);
        }

        Fraction operator/(const Fraction& other) {
            return divide(other);
        }
};

int main() {
    // Operator Overloading is a form of polymorphism
    // Provides functionalities with operators instead of method calls
    // e.g. + - * / 

    Fraction frac1(11, 15); //11/15
    frac1.printFraction();

    Fraction frac2(2, 3);   //2/3
    frac2.printFraction();

    //11/15 + 2/3 = 33/45 + 30/45 = 63/45
    std::cout << "Addition:" << std::endl;
    Fraction fracAdd = frac1 + frac2;
    fracAdd.printFraction(); //63/45
    fracAdd = frac2 + frac1;
    fracAdd.printFraction(); //63/45

    //11/15 - 2/3 = 33/45 - 30/45 = 3/45, and 2/3 - 11/15 = 30/45 - 33/45 = -3/45
    std::cout << "Subtraction:" << std::endl;
    Fraction fracSub = frac1 - frac2;
    fracSub.printFraction(); //3/45
    fracSub = frac2 - frac1;
    fracSub.printFraction(); //-3/45

    //11/15 * 2/3 = 22/45
    std::cout << "Multiplication:" << std::endl;
    Fraction fracMul = frac1 * frac2;
    fracMul.printFraction(); //22/45
    fracMul = frac2 * frac1;
    fracMul.printFraction(); //22/45

    //11/15 / 2/3 = 11/15 * 3/2 = 33/30, and 2/3 / 11/15 = 2/3 * 15/11 = 30/33
    std::cout << "Division:" << std::endl;
    Fraction fracDiv = frac1 / frac2;
    fracDiv.printFraction(); //33/30
    fracDiv = frac2 / frac1;
    fracDiv.printFraction(); //30/33
}

