#include <iostream>
#include <set>
using namespace std;
#define MAX 5001

int n, m;
int num[MAX];
set<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		st.insert(num[i]);
	}

	if (st.count(m)) {
		cout << "1\n";
		return 0;
	}

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (num[i] + num[j] == m) {
				cout << "1\n";
				return 0;
			} else if (num[i] + num[j] < m) {
				int val = m - (num[i] + num[j]);
				if (st.count(val) && num[i] != val && num[j] != val) {
					cout << "1\n";
					return 0;
				}
			}
		}
	}

	cout << "0\n";

	return 0;
}
