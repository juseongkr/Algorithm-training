#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, string> dict;
	string s, k;
	int n, p, w, l, g, point = 0;

	cin >> n >> p >> w >> l >> g;
	for (int i=0; i<p; ++i) {
		cin >> s >> k;
		dict[s] = k;
	}

	for (int i=0; i<n; ++i) {
		cin >> s;
		if (dict.count(s)) {
			if (dict[s] == "W")
				point += w;
			else if (dict[s] == "L") {
				if (point - l < 0)
					point = 0;
				else
					point -= l;
			}
		} else {
			point -= l;
		}

		if (point >= g) {
			cout << "I AM NOT IRONMAN!!\n";
			return 0;
		}
	}
	cout << "I AM IRONMAN!!\n";

	return 0;
}
