#include <iostream>
using namespace std;

int main()
{
	long long num, result = 1;

	cin >> num;

	for (int i=1; i<=num; ++i)
		result *= i;

	cout << result << '\n';

	return 0;
}
