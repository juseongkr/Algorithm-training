#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 51

int num[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int cnt = 1;
	int cur = num[0];
	for (int i=1; i<n; ++i) {
		if (cur < num[i]) {
			cur = num[i];
			cnt++;
		}
	}
	cout << cnt << '\n';

	reverse(num, num+n);

	cnt = 1;
	cur = num[0];
	for (int i=1; i<n; ++i) {
		if (cur < num[i]) {
			cur = num[i];
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
