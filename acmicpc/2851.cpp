#include <iostream>
using namespace std;

int main()
{
	int num[10], sum = 0;

	for (int i=0; i<10; ++i)
		cin >> num[i];

	for (int i=0; i<10; ++i) {
		int next = sum + num[i];
		if (abs(next-100) <= abs(sum-100))
			sum += num[i];
		else
			break;
	}
	cout << sum << '\n';

	return 0;
}
