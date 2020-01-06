#include <iostream>
using namespace std;

int main()
{
	long long num, result = 0;
	long long person[101] = {0, };
	cin >> num;

	for (int i=0; i<num; ++i)
		cin >> person[i];

	for (int i=1; i<num; ++i)
		result += i * 4 * person[i];

	cout << result << '\n';

	return 0;
}
