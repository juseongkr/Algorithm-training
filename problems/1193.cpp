#include <iostream>
using namespace std;

int main()
{
	int i = 1, sum = 1;
	int n, sub;
	cin >> n;

	while (n > sum) {
		i++;
		sum += i;
	}

	sub = sum - n + 1;
	if (i % 2 == 0)
		cout << i - sub + 1 << "/" << sub << '\n';
	else
		cout << sub << "/" << i - sub + 1 << '\n';

	return 0;
}
