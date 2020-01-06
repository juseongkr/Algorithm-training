#include <iostream>
using namespace std;

int main()
{
	long long num, cnt = 0;

	cin >> num;

	cnt += num / 100;
	num %= 100;
	cnt += num / 20;
	num %= 20;
	cnt += num / 10;
	num %= 10;
	cnt += num / 5;
	num %= 5;
	cnt += num;

	cout << cnt << '\n';

	return 0;
}
