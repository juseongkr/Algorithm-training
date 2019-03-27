#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int num, coin, l, r, cnt = 0, cost = 0;
	int array[100], result[100];

	memset(result, -1, sizeof(result));
	cin >> num >> coin;
	for (int i=0; i<num; ++i)
		cin >> array[i];

	for (int i=1; i<num; ++i) {
		r = 0;
		l = 0;
		for (int j=0; j<i; ++j) {
			if (array[j] % 2 == 0)
				l++;
			else
				l--;
		}

		for (int k=i; k<num; ++k) {
			if (array[k] % 2 == 0)
				r++;
			else
				r--;
		}

		if (l == 0 && r == 0)
			result[i] = abs(array[i] - array[i-1]);
	}

	sort(result, result + 100);

	for (int i=0; i<100; ++i) {
		if (cost + result[i] <= coin && result[i] >= 0) {
			cost += result[i];
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
