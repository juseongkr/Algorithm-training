#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 15001

int n, m;
int num[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = 0;
	while (n--) {
		if (binary_search(num, num+n, m-num[n]))
			ans++;
	}
	cout << ans << '\n';

	return 0;
}
