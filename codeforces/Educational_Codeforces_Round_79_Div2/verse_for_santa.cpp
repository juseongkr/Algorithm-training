#include <iostream>
using namespace std;
#define MAX 100001

int t, n, s;
int num[MAX];

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		int cur = 1;
		for (int i=1; i<=n; ++i) {
			if (num[cur] < num[i])
				cur = i;
			s -= num[i];
			if (s < 0)
				break;
		}
		if (s < 0)
			cout << cur << '\n';
		else
			cout << "0\n";
	}

	return 0;
}
