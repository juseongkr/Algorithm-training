#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> ans;
	long long n;

	cin >> n;
	while (n) {
		ans.push_back(n%2);
		n /= 2;
	}
	reverse(ans.begin(), ans.end());

	for (int i=0; i<ans.size(); ++i)
		cout << ans[i];

	return 0;
}
