#include <iostream>
#include <set>
using namespace std;

int main()
{
	int t;
	string s;

	cin >> t;
	for (int T=1; T<=t; ++T) {
		set<char> st;
		cin >> s;
		for (int i=0; i<s.length(); ++i) {
			if (st.count(s[i]))
				st.erase(s[i]);
			else
				st.insert(s[i]);
		}
		cout << "#" << T << " " << st.size() << '\n';
	}

	return 0;
}
