#include <iostream>
#include <cmath>
#include <locale.h>

double f(double x);

double f_derivada(double x);

double newton_raphson(double InitialGuess, double Tolerance, int MaxIterations);


int main() {
    setlocale(LC_ALL, "portuguese");

    double InitialGuess;
    double Tolerance{ 1e-6 };
    int MaxIterations = { 1000 };

    double intervals[4][2] = { {-19, -17}, {-6, -4}, {0, 3}, {8, 10} };
    double roots[4];

    for (int i = 0; i < 4; i++)
    {
        InitialGuess = (intervals[i][0] + intervals[i][1]) / 2;
        roots[i] = newton_raphson(InitialGuess, Tolerance, MaxIterations);
        std::cout << "A raíz número " << i + 1 << " é igual á: " << roots[i] << std::endl;
    }

    return 0;
}

double f(double x)
{
    return pow(x, 4) + 12.6 * pow(x, 3) - 155.7 * pow(x, 2) + 186;
}


double f_derivada(double x)
{
    return 4 * pow(x, 3) + 37.8 * pow(x, 2) - 311.4 * x;
}

double newton_raphson(double InitialGuess, double Tolerance, int MaxIterations)
{
    double x = InitialGuess;
    for (int i = 0; i < MaxIterations; i++) 
    {
        double fx = f(x);
        double fpx = f_derivada(x);

        if (std::fabs(fx) < Tolerance)
        {
            break;
        }

        x = x - fx / fpx;
    }
    return x;
}
