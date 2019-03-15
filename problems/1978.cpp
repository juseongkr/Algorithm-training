#include <iostream>
#include <cmath>
using namespace std;

bool check(int n)
{
	if (n < 2)
		return 0;

	for (int i=2; i<=sqrt(n); ++i)
		if (n % i == 0)
			return 0;

	return 1;
}

int main()
{
	int num, n, cnt = 0;
	
	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> n;
		if (check(n))
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
