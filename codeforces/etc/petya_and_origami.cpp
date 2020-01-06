#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long double n, k;
    long long result = 0;

    cin >> n >> k;

    result = (ceil((2 * n)/k) + ceil((5 * n)/k) + ceil((8 * n)/k));

    cout << result << '\n';

    return 0;
}

