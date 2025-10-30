#include <iostream>

class Fraction {
    int numerator;
    int denominator;
    
    public:
        void setNumerator(int n) {
            numerator = n;
        }

        int getNumerator() const {
            return numerator;
        }

        void setDenominator(int n) {
            if (n == 0) {
                std::cout << "denominator cannot be 0" << std::endl;
                return;
            }
            denominator = n;
        }

        int getDenominator() const {
            return denominator;
        }

        void printFraction() {
            std::cout << numerator << '/' << denominator << std::endl;
        }
};

// Fraction addFractions(Fraction frac1, Fraction frac2)
Fraction addFractions(const Fraction& frac1, const Fraction& frac2) {
    int newNumerator = frac1.getNumerator()*frac2.getDenominator() + 
                       frac2.getNumerator()*frac1.getDenominator();

    int newDenominator = frac1.getDenominator()*frac2.getDenominator();

    Fraction newFraction;
    newFraction.setNumerator(newNumerator);
    newFraction.setDenominator(newDenominator);
    return newFraction;
}

int main() {
    // Const Member Functions (Const Methods) 
    // Ensure that member variables will not change when a method is call
    // 11/15 + 2/3 -> 33/45 + 30/45 = 63/45
    
    Fraction frac1;
    frac1.setNumerator(11);
    frac1.setDenominator(15);
    frac1.printFraction();

    Fraction frac2;
    frac2.setNumerator(2);
    frac2.setDenominator(3);
    frac2.printFraction();

    Fraction frac3 = addFractions(frac1, frac2);
    frac3.printFraction();
}

