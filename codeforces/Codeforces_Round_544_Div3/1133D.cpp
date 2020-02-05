#include <iostream>
#include <map>
using namespace std;
#define MAX 200001

int n;
long long a[MAX], b[MAX];
map<long double, long long> m;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
		cin >> b[i];

	long long cnt = 0;
	for (int i=0; i<n; ++i) {
		if (a[i] == 0 && b[i] == 0)
			cnt++;
		else if (a[i] == 0)
			continue;
		else
			m[-1.0*b[i]/a[i]]++;
	}

	long long ans = 0;
	for (auto &it : m)
		ans = max(ans, it.second);

	cout << ans + cnt << '\n';

	return 0;
}
