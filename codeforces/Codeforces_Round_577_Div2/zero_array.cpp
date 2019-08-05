#include <iostream>
using namespace std;

long long n, t, sum, max_val;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		sum += t;
		max_val = max(max_val, t);
	}

	if (sum % 2 == 0 && max_val <= sum / 2)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
