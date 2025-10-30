#include <iostream>
#include <vector>
#include <algorithm> //sort, count

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

        bool operator<(const Fraction& other) {
            return numerator*other.denominator < other.numerator*denominator;
        }

        bool operator<=(const Fraction& other) {
            return numerator*other.denominator <= other.numerator*denominator;
        }

        bool operator>(const Fraction& other) {
            return numerator*other.denominator > other.numerator*denominator;
        }

        bool operator>=(const Fraction& other) {
            return numerator*other.denominator >= other.numerator*denominator;
        }

        bool operator==(const Fraction& other) {
            return numerator*other.denominator == other.numerator*denominator;
        }

        bool operator!=(const Fraction& other) {
            return numerator*other.denominator != other.numerator*denominator;
        }
};

int main() {
    // Operator Overloading is a form of polymorphism
    // Provides functionalities with operators instead of method calls
    // e.g. Comparison Operators: < <= > >= == !=
    // < is needed for sorting
    // == is needed for search related (find, count, remove) operations

    Fraction frac1(11, 15); //11/15
    Fraction frac2(2, 3);   //2/3
    Fraction frac3(5, 10);  //5/10
    Fraction frac4(1, 5);   //1/5
    Fraction frac5(8, 12);  //8/12

    std::cout << "11/15 < 2/3 " << (frac1 < frac2) << std::endl;
    std::cout << "2/3 < 11/15 " << (frac2 < frac1) << std::endl;
    std::cout << "2/3 == 8/12 " << (frac2 == frac5) << std::endl;
    std::cout << "5/10 != 1/5 " << (frac3 != frac4) << std::endl;

    std::vector<Fraction> fractions{frac1, frac2, frac3, frac4};
    std::cout << "Before Sorting: " << std::endl;
    for (const Fraction& fraction : fractions) {
        fraction.printFraction();
    }

    //need to overload operator<
    std::sort(fractions.begin(), fractions.end());

    //need to overload operator==
    std::cout << "Count 11/15: " << (std::count(fractions.begin(), fractions.end(), frac1)) << std::endl;

    std::cout << "After Sorting: " << std::endl;
    for (const Fraction& fraction : fractions) {
        fraction.printFraction();
    }
}

