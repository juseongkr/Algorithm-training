#include <iostream>
using namespace std;
#define MAX 200001

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

	if (n > m) {
		cout << "0\n";
	} else {
		long long ans = 1;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				ans = (ans * abs(num[i] - num[j])) % m;
		cout << ans << '\n';
	}

	return 0;
}
