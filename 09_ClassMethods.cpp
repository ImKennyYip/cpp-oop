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

        //this (self), vs other
        Fraction add(const Fraction& other) const {
            // int newNumerator = numerator * other.getDenominator() + denominator * other.getNumerator();
            // int newDenominator = denominator * other.getDenominator();

            //data members are private to the class, not the object
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
};

int main() {
    // Methods can take other instances of the same class as parameters
    // Methods can also return instances of the same class
    // Data Members are private to the class, not to the instance/object
    // Private data members of an instance can be accessed inside the method

    Fraction frac1(11, 15); //11/15
    frac1.printFraction();

    Fraction frac2(2, 3);   //2/3
    frac2.printFraction();

    //11/15 + 2/3 = 33/45 + 30/45 = 63/45
    std::cout << "Addition:" << std::endl;
    Fraction fracAdd = frac1.add(frac2);
    fracAdd.printFraction(); //63/45
    fracAdd = frac2.add(frac1);
    fracAdd.printFraction(); //63/45

    //11/15 - 2/3 = 33/45 - 30/45 = 3/45, and 2/3 - 11/15 = 30/45 - 33/45 = -3/45
    std::cout << "Subtraction:" << std::endl;
    Fraction fracSub = frac1.subtract(frac2);
    fracSub.printFraction(); //3/45
    fracSub = frac2.subtract(frac1);
    fracSub.printFraction(); //-3/45

    //11/15 * 2/3 = 22/45
    std::cout << "Multiplication:" << std::endl;
    Fraction fracMul = frac1.multiply(frac2);
    fracMul.printFraction(); //22/45
    fracMul = frac2.multiply(frac1);
    fracMul.printFraction(); //22/45

    //11/15 / 2/3 = 11/15 * 3/2 = 33/30, and 2/3 / 11/15 = 2/3 * 15/11 = 30/33
    std::cout << "Division:" << std::endl;
    Fraction fracDiv = frac1.divide(frac2);
    fracDiv.printFraction(); //33/30
    fracDiv = frac2.divide(frac1);
    fracDiv.printFraction(); //30/33
    
}


