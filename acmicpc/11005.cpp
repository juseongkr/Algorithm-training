#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	int b;
	vector<char> ans;

	cin >> n >> b;
	while (n) {
		int t = (n%b);
		if (10 <= t && t <= 35) {
			t += 55;
			ans.push_back(t);
		} else {
			ans.push_back(t + '0');
		}
		n /= b;
	}

	for (int i=ans.size()-1; i>=0; i--)
		cout << ans[i];
	cout << '\n';

	return 0;
}
