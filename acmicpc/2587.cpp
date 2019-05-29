#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[5], sum = 0;

	for (int i=0; i<5; ++i) {
		cin >> num[i];
		sum += num[i];
	}

	sort(num, num+5);

	cout << sum/5 << '\n' << num[2] << '\n';

	return 0;
}
