#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction(int numerator, int denominator) {
            // parameter name conflicts with member variable name
            // numerator = numerator;
            // denominator = denominator;
            
            //this keyword is a pointer to self (the class itself)
            this->numerator = numerator;
            this->denominator = denominator;

            // if you don't want to use this keyword, you can prefix variable names with m
            // mNumerator, mDenominator or m_numerator, m_denominator
            // can be quite messy if a data member is a pointer
            // e.g. this->courses->push_back();
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
            // no name conflict here so this is optional
            std::cout << this->numerator << '/' << this->denominator << std::endl;
        }
};

int main() {
    // Constructors are used to initialize data member with input values upon object creation
    // When an object is created, the constructor is invoked

    Fraction frac(11, 15);
    frac.printFraction();
}

