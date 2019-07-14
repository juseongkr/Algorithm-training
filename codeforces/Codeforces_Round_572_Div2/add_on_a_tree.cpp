#include <iostream>
using namespace std;
#define MAX 100001

int in[MAX];

int main()
{
	int n, a, b;
	bool flag = false;

	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> a >> b;
		in[a]++;
		in[b]++;
	}

	for (int i=1; i<=n; ++i)
		if (in[i] == 2)
			flag = true;

	if (flag)
		cout << "NO\n";
	else
		cout << "YES\n";

	return 0;
}
