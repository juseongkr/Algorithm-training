#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
string s;
vector<string> vec;

int main()
{
	cin >> k >> n;
	for (int i=0; i<k; ++i) {
		cin >> s;
		vec.push_back(s);
	}

	sort(vec.begin(), vec.end(), [](string x, string y) {
		if (x.length() == y.length())
			return x > y;
		return x.length() > y.length();
	});

	vector<string> ans;
	for (int i=0; i<n-k; ++i)
		ans.push_back(vec[0]);
	for (int i=0; i<vec.size(); ++i)
		ans.push_back(vec[i]);

	sort(ans.begin(), ans.end(), [](string x, string y) {
		return x + y > y + x;
	});

	for (int i=0; i<ans.size(); ++i)
		cout << ans[i];
	cout << '\n';

	return 0;
}
