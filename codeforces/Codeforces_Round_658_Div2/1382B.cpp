#include <iostream>
using namespace std;

int T, n;
int p[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		bool flag = false;
		for (int i=0; i<n; ++i)
			cin >> p[i];

		for (int i=0; i<n-1; ++i) {
			if (p[i] != 1)
				break;
			flag = !flag;
		}

		if (flag)
			cout << "Second\n";
		else
			cout << "First\n";
	}

	return 0;
}
