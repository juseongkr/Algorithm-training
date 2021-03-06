#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 5001

int n, m;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		if (num[i] == m) {
			cout << "1\n";
			return 0;
		}
	}

	sort(num, num+n);

	for (int i=0; i<n; ++i) {
		int val = m - num[i];
		int l = i+1, r = n-1;
		while (l < r) {
			if (num[l] + num[r] == val) {
				cout << "1\n";
				return 0;
			} else if (num[l] + num[r] < val) {
				l++;
			} else {
				r--;
			}
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (num[i] + num[j] == m) {
				cout << "1\n";
				return 0;
			}
		}
	}

	cout << "0\n";

	return 0;
}
