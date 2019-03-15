#include <iostream>
using namespace std;

int main()
{
	int array[10] = {0, };
	long long num;

	cin >> num;

	while (num) {
		array[num % 10]++;
		num /= 10;
	}

	for (int i=9; i>=0; --i)
		for (int j=0; j<array[i]; ++j)
			cout << i;

	cout << "\n";

	return 0;
}
