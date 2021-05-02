#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int n, l, num[MAX];

int main()
{
	cin >> n >> l;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	for (int i=0; i<n; ++i)
		if (l >= num[i])
			l++;

	cout << l << '\n';

	return 0;
}
