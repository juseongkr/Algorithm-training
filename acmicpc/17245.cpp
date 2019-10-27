#include <iostream>
using namespace std;
#define MAX 10000001

int n, t;
int pc[MAX];
long long total;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> t;
			pc[t]++;
			total += t;
		}
	}

	if (n * n == pc[0]) {
		cout << "0\n";
		return 0;
	}

	long long ans = 0;
	long long server = n * n - pc[0];
	for (int i=1; i<=MAX; ++i) {
		ans += server;
		server -= pc[i];
		if (total <= ans * 2) {
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}
