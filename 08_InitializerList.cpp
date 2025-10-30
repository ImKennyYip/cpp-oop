#include <iostream>

class Fraction {
    int numerator;
    int denominator;
    //std::vector<std::string> vec; //for example, creates default vector

    // initializer list can be used for const member variables
    // const int numerator;
    // const int denominator;

    public:
        // Fraction() {
        //     this->numerator = 0;
        //     this->denominator = 1;
        // }

        Fraction(int numerator = 0, int denominator = 1)
            : numerator(numerator), denominator(denominator) {
            // this->numerator = numerator;
            // this->denominator = denominator;
            // this->vec = vec; //reassignment
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
};

struct ConstFraction {
    // initializer list can be used for const member variables
    const int numerator;
    const int denominator;

    public:
        ConstFraction(int numerator = 0, int denominator = 1)
            : numerator(numerator), denominator(denominator) {
        }
        
        void printFraction() const {
            std::cout << numerator << '/' << denominator << std::endl;
        }
};

int main() {
    // Intializer/Initialization List
    // Used to initialize member variables before the constructor is invoked
    // Useful for const member variables as they cannot be assigned values after creation
    // Can avoid this->, if the parameter names are the same as the member variable names
    // Useful for initializing base class (inheritance)

    Fraction frac1(11, 15);
    frac1.printFraction();

    Fraction frac2(11);
    frac2.printFraction();

    Fraction frac3;
    frac3.printFraction();

    ConstFraction constFrac1(4, 10);
    // constFrac1.numerator = 20;
    // constFrac1.denominator = 50;
    std::cout << constFrac1.numerator << '/' << constFrac1.denominator << std::endl;
    constFrac1.printFraction();
}

