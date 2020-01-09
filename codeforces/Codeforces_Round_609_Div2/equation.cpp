#include <iostream>
using namespace std;

bool check(int k)
{
	for (int i=2; i*i<=k; ++i)
		if (k % i == 0)
			return true;
	return false;
}

int main()
{
	int n;

	cin >> n;
	int i = 2;
	while (1) {
		if (check(i+n) && check(i)) {
			cout << i+n << " " << i << '\n';
			return 0;
		}
		i++;
	}

	return 0;
}
