#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

public:
    int getNumerator() {
        return numerator;
    }
    int getDenominator() {
        return denominator;
    }
    void inputFraction();
    void printFraction();
    void reduceFraction();
    int gcd(int a, int b);
};

int main() {
    Fraction a;
    a.inputFraction();
    cout << "Fraction before reduction: ";
    a.printFraction();
    cout << "\nFraction after reduction: ";
    a.reduceFraction();
    a.printFraction();
}

void Fraction::inputFraction() {
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "Denominator cannot be zero. Enter again: ";
        cin >> denominator;
    }
}

void Fraction::printFraction() {
    cout << numerator << "/" << denominator;
}

int Fraction::gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void Fraction::reduceFraction() {
    int divisor = gcd(numerator, denominator);
    numerator = numerator / divisor;
    denominator = denominator / divisor;
}
