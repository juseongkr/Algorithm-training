#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pii;
map<int, pii> m;
int n, k, t;

int main()
{
	cin >> n >> k;
	for (int i=0; i<k; ++i) {
		cin >> t;
		if (m.count(t)) {
			m[t].first++;
		} else {
			if (m.size() < n) {
				m[t] = {1, i};
			} else {
				auto it = m.begin()->first;
				auto val = m.begin()->second;
				for (auto i : m) {
					if (i.second < val) {
						val = i.second;
						it = i.first;
					}
				}
				m.erase(it);
				m[t] = {1, i};
			}
		}
	}

	for (auto i : m)
		cout << i.first << " ";

	return 0;
}
