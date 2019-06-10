#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> s;
	int t, n, k;
	char c;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> c >> k;
			if (c == 'I') {
				s.insert(k);
			} else if (c == 'D' && s.size()) {
				if (k == 1) {
					auto it = s.end();
					s.erase(--it);
				} else {
					auto it = s.begin();
					s.erase(it);
				}
			}
		}
		if (s.size()) {
			auto x = s.end();
			auto y = s.begin();
			cout << *(--x) << " " << *y << '\n';
		} else {
			cout << "EMPTY\n";
		}
		s.clear();
	}

	return 0;
}
