#include <iostream>
using namespace std;

void binary(int n)
{
	if (n == 0)
		return;

	if (n % -2 == 0) {
		binary(n/-2);
		cout << "0";
	} else {
		binary((n-1)/-2);
		cout << "1";
	}
	return;
}

int main()
{
	int n;

	cin >> n;
	if (n == 0)
		cout << "0\n";
	else
		binary(n);

	return 0;
}
