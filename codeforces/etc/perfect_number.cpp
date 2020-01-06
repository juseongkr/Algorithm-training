#include <iostream>
using namespace std;

int main()
{
	int k, result, num;
	cin >> k;

	for (int i=1; ; ++i) {
		num = i;
		result = 0;
		while (num) {
			result += num % 10;
			num /= 10;
		}
		if (result == 10)
			k--;
		if (k == 0) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
