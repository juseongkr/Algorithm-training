#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	long long a = 0, b = 0;
	for (int i=0; i<n/2; ++i)
		a += num[i];

	for (int i=n/2; i<n; ++i)
		b += num[i];

	cout << (a*a) + (b*b) << '\n';

	return 0;
}
