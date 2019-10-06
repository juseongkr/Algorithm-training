#include <iostream>
using namespace std;

int n, cnt;
int num[101];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		if (num[i] % 2 == 1)
			cnt++;
	}
	cout << min(cnt, n-cnt) << '\n';

	return 0;
}
