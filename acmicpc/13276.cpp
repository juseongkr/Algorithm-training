#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string s, a, b;
unordered_set<string> st;

class KMP {
public:
	vector<int> fail;
	string a, b;

	KMP(const string s1, const string s2) : a(s1), b(s2)
	{
		fail.resize(max(s1.length(), s2.length()));
	}

	vector<int> find()
	{
		vector<int> ret;
		for (int i=1, j=0; i<b.length(); ++i) {
			while (j && b[i] != b[j])
				j = fail[j-1];

			if (b[i] == b[j])
				fail[i] = ++j;
		}

		for (int i=0, j=0; i<a.length(); ++i) {
			while (j && a[i] != b[j])
				j = fail[j-1];

			if (a[i] == b[j]) {
				if (j == b.length()-1) {
					ret.push_back(i - j);
					j = fail[j];
				} else {
					j++;
				}
			}
		}

		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s >> a >> b;

	KMP prefix(s, a);
	KMP suffix(s, b);

	int alen = a.length();
	int blen = b.length();
	for (auto pref : prefix.find()) {
		for (auto suff : suffix.find()) {
			int len = suff - pref + blen;
			if (alen <= len && blen <= len) {
				string str = s.substr(pref, len);
				st.insert(str);
			}
		}
	}

	cout << st.size() << '\n';

	return 0;
}
