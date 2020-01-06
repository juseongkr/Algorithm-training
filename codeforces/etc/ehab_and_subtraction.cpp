#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k, temp, sum = 0;
    long long array[100001] = {0, };
    cin >> n >> k;

    for (long long i=0; i<n; ++i)
        cin >> array[i];

    sort(array, array + n);

    for (long long i=0; i<k; ++i) {
        temp = array[upper_bound(array, array + n, sum) - array];
        if (temp <= 0) {
            cout << "0\n";
        } else {
            cout << temp - sum << '\n';
            sum = temp;
        }
    }

    return 0;
}
