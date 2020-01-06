#include <iostream>
#include <cmath>

double theatre_square(double n, double m, double a)
{
    double row;
    double col;

    row = ceil(n / a);
    col = ceil(m / a);

    return row * col;
}

int main(int argc, char** argv)
{
    long long n, m, a;
    std::cin >> n >> m >> a;
    long long result;

    result = theatre_square(n, m, a);
        
    std::cout << result << std::endl;

    return 0;
}
