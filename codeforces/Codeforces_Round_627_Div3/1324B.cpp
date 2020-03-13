#include <iostream>
using namespace std;
#define MAX 5001

int T, n;
int num[MAX];

bool solve() {
	for (int i=0; i<n; ++i)
		for (int j=i+2; j<n; ++j)
			if (num[i] == num[j])
				return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
