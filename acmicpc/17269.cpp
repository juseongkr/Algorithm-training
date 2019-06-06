#include <iostream>
#include <vector>
using namespace std;

const int dict[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main()
{
	int n, m, i, ans = 0;
	string a, b;
	vector<int> v;
	bool flag = false;

	cin >> n >> m >> a >> b;
	if (a.length() > b.length())
		flag = true;

	for (i=0; i<min(a.length(), b.length()); ++i) {
		v.push_back(dict[a[i]-'A']);
		v.push_back(dict[b[i]-'A']);
	}
	
	for (i=min(a.length(), b.length()); i<max(a.length(), b.length()); ++i) {
		if (flag)
			v.push_back(dict[a[i]-'A']);
		else
			v.push_back(dict[b[i]-'A']);
	}

	while (v.size() != 2) {
		vector<int> r;
		for (int j=0; j<v.size()-1; ++j)
			r.push_back((v[j]+v[j+1])%10);
		v = r;
	}
	ans += v[0]*10 + v[1];

	cout << ans << "%\n";

	return 0;
}
