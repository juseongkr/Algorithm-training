#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

string a, b;

int main()
{
	cin >> a >> b;
	int len = min(a.length(), b.length());
	for (int k=len; k>0; k--) {
		vector<int> dict(26, 0);
		set<vector<int>> st;

		for (int i=0; i<k; ++i)
			dict[a[i]-'a']++;

		st.insert(dict);

		for (int i=k; i<a.length(); ++i) {
			dict[a[i]-'a']++;
			dict[a[i-k]-'a']--;
			st.insert(dict);
		}

		fill(dict.begin(), dict.end(), 0);

		for (int i=0; i<k; ++i)
			dict[b[i]-'a']++;

		if (st.count(dict)) {
			cout << k << '\n';
			return 0;
		}

		for (int i=k; i<b.length(); ++i) {
			dict[b[i]-'a']++;
			dict[b[i-k]-'a']--;

			if (st.count(dict)) {
				cout << k << '\n';
				return 0;
			}
		}
	}
	cout << "0\n";

	return  0;
}
