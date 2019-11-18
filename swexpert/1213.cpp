#include <iostream>
#include <vector>
using namespace std;

class KMP {
public:
	vector<int> fail;
	string a, b;

	KMP(string s1, string s2) : a(s1), b(s2)
	{
		fail.resize(max(s1.length(), s2.length()));
	}

	vector<int> find()
	{
		vector<int> ret;
		for (int i=1, j=0; i<=b.length(); ++i) {
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
					ret.push_back(i - b.length() + 2);
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
	string s, p;
	int d;

	for (int t=1; t<=10; ++t) {
		cin >> d >> p >> s;
		KMP k = KMP(s, p);
		vector<int> ans = k.find();
		cout << "#" << t << " " << ans.size() << '\n';
	}

	return 0;
}
