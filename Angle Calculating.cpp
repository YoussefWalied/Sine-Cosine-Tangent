
#include <iostream>
using namespace std;

// j, i & n are just counts for the loops
// function for calculating x^2n & x^(2n+1) & x^(2n+2)
long double Sin_Cos_TanPow(double radian, int n)
{
    double RESULT = 1;
    for (int j = 0; j < n; j++)
        RESULT *= radian;
    return RESULT;
}
// function for calculating the factorial of 2n & 2n+1
long double Sin_CosFac(double n)
{
    double factorialCalc = 1;
    for (int i = 1; i <= n; i++)
        factorialCalc *= i;
    return factorialCalc;
}
// function for calculating the factorial of 2n + 2
long double TanFac(int x)
{
    double factorialCalc = 1;
    for (int i = 1; i <= x; i++)
        factorialCalc *= i;
    return factorialCalc;
}
// function for calculating the 2^(2n+2) in tan function
long double Tan2Pow(int x)
{
    double result = 1;
    for (int j = 0; j < x; j++)
        result *= 2;
    return result;
}


int main()
{
    double Angle; // Angle is for the x in degree in the formula
    cout << "Enter the angle you want to calculate in degrees: \n";
    cin >> Angle;
    double display = Angle;
    while (Angle <= -360)
        Angle += 360;
    while (Angle >= 360)
        Angle -= 360;
    double Pi = 3.141592653589793;
    double radian = Angle * Pi / 180; // making it radian

    //An array to store bernoulli values for the tan
    const int Ber = 31;
    long double Valu[Ber];
    Valu[4] = 0.03333333333;
    Valu[6] = 0.02380952381;
    Valu[8] = 0.03333333333;
    Valu[10] = 0.07575757576;
    Valu[12] = 0.25311355311;
    Valu[14] = 1.16666666667;
    Valu[16] = 7.09215686275;
    Valu[18] = 54.97117794486;
    Valu[20] = 529.1242424242;
    Valu[22] = 6192.1231884058;
    Valu[24] = 99731.68396624473;
    Valu[26] = 1425517.166666667;
    Valu[28] = 27298231.067816094;
    Valu[30] = 601580873.9006424;

    long double Cosine_Result = 0, Sine_Result = 0, Tangent_Result = 0; // variables for the sin, cos & taan
    int	sign = -1; // to determine the sign of the term in the formula

    // Calculating the cosine function
    for (int n = 2; n < 30; n += 2)
    {
        Cosine_Result += sign * (Sin_Cos_TanPow(radian, n) / Sin_CosFac(n));
        sign *= -1;
    }
    if (Cosine_Result < -0.9999999 && Cosine_Result > -1.0000001)
        Cosine_Result = -1;
    cout << "Cos(" << display << ") = " << 1 + Cosine_Result << "   ";

    // calculating the sine function
    for (int n = 3; n < 30; n += 2)
    {
        Sine_Result += sign * (Sin_Cos_TanPow(radian, n) / Sin_CosFac(n));
        sign *= -1;
    }
    cout << "Sin(" << display << ") = " << radian + Sine_Result << "   ";

    // calculating the tan function
    for (int n = 3; n < 31; n += 2)
    {
        int x;
        x = n + 1;
        Tangent_Result += Tan2Pow(x) * (Tan2Pow(x) - 1) * Valu[x] * Sin_Cos_TanPow(radian, n) / TanFac(x);
    }
    if (1 + Cosine_Result == 0)
        cout << "Tan(" << display << ") = undefined" << endl;
    else
        cout << "Tan(" << display << ") = " << (radian + Sine_Result) / (1 + Cosine_Result) << endl << endl;
}