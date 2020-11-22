#include <iostream>
#include <list>
using namespace std;

int n, t;
string s;

int main()
{
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		cin >> s;
		list<char> li;
		cout << "Simulation " << ++t << '\n';
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '!') {
				for (auto it=li.cbegin(); it!=li.cend(); ++it)
					cout << *it;
				cout << '\n';
			} else {
				bool flag = false;
				for (auto it=li.cbegin(); it!=li.cend(); ++it) {
					if (*it == s[i]) {
						li.erase(it);
						li.push_back(s[i]);
						flag = true;
						break;
					}
				}

				if (!flag) {
					if (li.size() == n)
						li.pop_front();
					li.push_back(s[i]);
				}
			}
		}
	}

	return 0;
}
