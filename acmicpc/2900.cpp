#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX 1000001

int n, k, t, q, x, y;
long long p[MAX], num[MAX];
unordered_map<int, int> jump;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<k; ++i) {
		cin >> t;
		jump[t]++;
	}
	cin >> q;
	
	for (auto i : jump)
		for (int j=0; j<n; j+=i.first)
			num[j] += i.second;

	for (int i=0; i<n; ++i)
		p[i+1] = p[i] + num[i];

	while (q--) {
		cin >> x >> y;
		cout << p[y+1] - p[x] << '\n';
	}

	return 0;
}
