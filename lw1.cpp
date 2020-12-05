#include <iostream>


using namespace std;


typedef struct _complex
{
    double real;
    double imaginary;
} complex;


complex add(complex& lhs, complex& rhs)
{
    complex result = {};

    result.real = lhs.real + rhs.real;
    result.imaginary = lhs.imaginary + rhs.imaginary;

    return result;
}


complex sub(complex& lhs, complex& rhs)
{
    complex result = {};

    result.real = lhs.real - rhs.real;
    result.imaginary = lhs.imaginary - rhs.imaginary;

    return result;
}


complex mul(complex& lhs, complex& rhs)
{
    complex result = {};

    result.real = (lhs.real * rhs.real) - (lhs.imaginary * rhs.imaginary);
    result.imaginary = (lhs.real * rhs.imaginary) + (lhs.imaginary * rhs.real);

    return result;
}


double pow_2(double& a)
{
    return a * a;
}


complex div(complex& lhs, complex& rhs)
{
    complex result = {};

    result.real = ((lhs.real * rhs.real) + (lhs.imaginary * rhs.imaginary)) / 
                    (pow_2(rhs.real) + pow_2(rhs.imaginary));
    result.imaginary = ((lhs.imaginary * rhs.real) - (lhs.real * rhs.imaginary)) /
                        (pow_2(rhs.real) + pow_2(rhs.imaginary));

    return result;
}


int main(int argc, char * const argv[])
{

    complex first = {(double)atof(argv[1]), (double)atof(argv[2])};
    complex second = {(double)atof(argv[3]), (double)atof(argv[4])};

    complex res = add(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = sub(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = mul(first, second);

    cout << res.real << " " << res.imaginary << endl;

    res = div(first, second);

    cout << res.real << " " << res.imaginary << endl;
}
