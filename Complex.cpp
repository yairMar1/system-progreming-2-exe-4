#include "Complex.hpp"
#include <string>
#include <cmath> 

using namespace std;

// constructors
Complex::Complex(double r, double i) : real(r), imaginary(i) {}
Complex::Complex(double r) : real(r), imaginary(0) {}
Complex::Complex() : real(0), imaginary(0) {}

double Complex::get_real() const{return real;}

double Complex::get_imaginary() const{return imaginary;}

Complex &Complex::operator+=(const Complex &other){
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex &Complex::operator-=(const Complex &other){
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

bool Complex::operator==(const Complex &other) const{
    return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex &other){
    return !(*this == other);
}

// bool Complex::operator<(const Complex &other){
//     return real < other.real || (real == other.real && imaginary < other.imaginary);
// }

bool Complex::operator<(const Complex &other) const{
    double thisMagnitude = sqrt(pow(real, 2) + pow(imaginary, 2));
    double otherMagnitude = sqrt(pow(other.real, 2) + pow(other.imaginary, 2));
    return thisMagnitude < otherMagnitude;
}

bool Complex::operator>(const Complex &other){
    return other < (*this);
}

string Complex::to_string() const{
    return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
}

ostream& operator<<(ostream& os, const Complex& c) {
    string res = to_string(c.real) + "+" + to_string(c.imaginary) + "i";
    // os << c.real << "+" << c.imaginary << "i";
    os << res;
    return os;
}