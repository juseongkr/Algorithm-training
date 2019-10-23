#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int t, p;
bool check[MAX];
vector<int> prime;

void solve(int p)
{
	for (int i=0; i<prime.size(); ++i) {
		for (int j=0; j<prime.size(); ++j) {
			for (int k=0; k<prime.size(); ++k) {
				if (prime[i] + prime[j] + prime[k] == p) {
					cout << prime[i] << " " << prime[j] << " " << prime[k] << '\n';
					return;
				}
			}
		}
	}
	cout << "0\n";
}

int main()
{
	fill(check+2, check+MAX, true);
	for (int i=2; i<=MAX; ++i) {
		if (check[i])
			prime.push_back(i);
		for (int j=i; j<=MAX; j+=i)
			check[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> p;
		solve(p);
	}

	return 0;
}
