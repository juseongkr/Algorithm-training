#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	long long array[100001], result[100001];
	long long n, m, j = 0, k = 0;

	cin >> n >> m;

	for (int i=0; i<n; ++i)
		cin >> array[i];

	sort(array, array + n);

	for (int i=1; i<=1000000000; ++i) {
		if (i > m)
			break;
		if (array[j] == i) {
			j++;
		} else {
			result[k++] = i;
			m -= i;
		}
	}

	cout << k << '\n';

	for (int i=0; i<k; ++i)
		cout << result[i] << " ";
	cout << '\n';

	return 0;
}
