#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef struct _complex {
    double real;
    double imaginary;
} complex;

void get_norm(complex& num) {
    return;
}

complex add(complex& lhs, complex& rhs) {
    complex result = {};

    result.real = lhs.real + rhs.real;
    result.imaginary = lhs.imaginary + rhs.imaginary;

    return result;
}

complex sub(complex& lhs, complex& rhs) {
    complex result = {};

    result.real = lhs.real - rhs.real;
    result.imaginary = lhs.imaginary - rhs.imaginary;

    return result;
}

complex mul(complex& lhs, complex& rhs) {
    complex result = {};

    result.real = (lhs.real * rhs.real) - (lhs.imaginary * rhs.imaginary);
    result.imaginary = (lhs.real * rhs.imaginary) + (lhs.imaginary * rhs.real);

    return result;
}

double sqrt(double& a) {
    return a * a;
}

complex div(complex& lhs, complex& rhs) {
    complex result = {};

    result.real = ((lhs.real * rhs.real) + (lhs.imaginary * rhs.imaginary)) / (sqrt(rhs.real) + sqrt(rhs.imaginary));
    result.imaginary = ((lhs.imaginary * rhs.real) - (lhs.real * rhs.imaginary)) / (sqrt(rhs.real) + sqrt(rhs.imaginary));

    return result;
}

int main()
{

    complex first = {1, 2};
    complex second = {10, 20};

    complex res = add(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = sub(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = mul(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = div(first, second);

    cout << res.real << " " << res.imaginary << endl;

}
