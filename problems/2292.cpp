#include <iostream>
using namespace std;

int main()
{
	long long n, t = 1, i = 1;

	cin >> n;
	while (t < n) {
		 t += (6*i);
		 i++;
	}

	cout << i << '\n';

	return 0;
}
