#include <iostream>
using namespace std;

int main()
{
	int array[100] = {0, };
	int n, sum, result = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> array[i];

	for (int i=0; i<n; ++i) {
		for (int j=i; j<n; ++j) {
			sum = 0;
			for (int k=0; k<n; ++k) {
				if (i > k || k > j)
					sum += array[k];
				else
					sum += (1 - array[k]);
			}
			result = max(result, sum);
		}
	}

	cout << result << '\n';

	return 0;
}
