#include <iostream>
#include <map>
using namespace std;
#define MAX 1001

int main()
{
	map<string, int> dict;
	string s[MAX];
	bool flag = false;
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int l = 0, r = n-1, mid;
	while (l <= r) {
		bool check = false;
		mid = (l+r)/2;
		for (int i=0; i<m; ++i) {
			string t;
			for (int j=mid; j<n; ++j)
				t += s[j][i];

			if (dict[t])
				check = true;
			else
				dict[t]++;
		}
		if (check)
			r = mid - 1;
		else
			l = mid + 1;

		dict.clear();
		flag = check;
	}
	if (flag)
		cout << mid-1 << '\n';
	else
		cout << mid << '\n';

	return 0;
}
