#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[1001];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	cout << num[n-1]-num[0] << '\n';

	return 0;
}
