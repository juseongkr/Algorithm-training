#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, a, b, k, result = 0;

	cin >> n >> a >> b;

	k = abs(b);
	result = a;
	while (k > 0) {
		if (b < 0) {
			if (result == 1)
				result = n;
			else
				result--;
		} else {
			if (result == n)
				result = 1;
			else
				result++;
		}
		k--;
	}
	

	cout << result << '\n';

	return 0;
}
