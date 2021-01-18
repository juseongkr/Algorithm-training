#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int n, m, x;
int arr[MAX];
string s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i] >> arr[i];

	for (int i=0; i<m; ++i) {
		cin >> x;
		auto idx = lower_bound(arr, arr+n, x) - arr;
		cout << s[idx] << '\n';
	}

	return 0;
}
