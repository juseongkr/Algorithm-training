#include <iostream>
using namespace std;
#define MAX 1001

int main()
{
	char c;
	int t, n, a, b;
	int num[MAX];

	cin >> t;
	while (t--) {
		cin >> n;
		fill(num, num+MAX, 0);
		for (int i=0; i<n; ++i) {
			cin >> c >> a >> b;
			for (int i=a; i<b; ++i)
				num[i]++;
		}
		for (int i=0; i<MAX; ++i)
			if (num[i])
				cout << char(num[i]+'A'-1);
		cout << '\n';
	}

	return 0;
}
