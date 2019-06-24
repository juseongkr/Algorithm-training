#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;
	string id;
	int n, num, verdict, mem, time, lang, len;
	int ac = 0, wa = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num >> id >> verdict >> mem >> time >> lang >> len;
		if (id == "megalusion")
			continue;

		if (verdict == 4) {
			if (m[id] != -1) {
				ac++;
				wa += m[id];
				m[id] = -1;
			}
			continue;
		}
		if (m[id] != -1)
			m[id]++;
	}

	if (ac) {
		double ans = 100 * (ac / double(ac + wa));
		cout << fixed << setprecision(9) <<  ans << '\n';
	} else {
		cout << "0\n";
	}

	return 0;
}
