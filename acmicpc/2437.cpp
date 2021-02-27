#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1002

int n;
int num[MAX], sum[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	sort(num, num+n+1);

	if (num[1] != 1) {
		cout << "1\n";
		return 0;
	}

	for (int i=1; i<=n; ++i) {
		sum[i] = sum[i-1] + num[i];
		if (sum[i-1]+1 < num[i]) {
			cout << sum[i-1]+1 << '\n';
			return 0;
		}
	}

	cout << sum[n]+1 << '\n';

	return 0;
}
