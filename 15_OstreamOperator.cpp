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

        friend std::ostream& operator<<(std::ostream& os,  const Fraction& fraction) {
            os << fraction.numerator << '/' << fraction.denominator;
            return os;
        };

        // friend std::ostream& operator<<(std::ostream&, const Fraction&);
};

// std::ostream& operator<<(std::ostream& os,  const Fraction& fraction) {
//      os << fraction.getNumerator() << '/' << fraction.getDenominator();
//      os << fraction.numerator << '/' << fraction.denominator;
//     return os;
// };

int main() {
    // Classes can be printed with cout by overloading the << operator as a non member function
    // << operator can be declared as a friend function to access private data members

    Fraction frac1(11, 15);
    frac1.printFraction();
    std::cout << frac1 << std::endl;

    Fraction frac2(2, 3);
    frac2.printFraction();
    std::cout << frac2 << std::endl;
}

