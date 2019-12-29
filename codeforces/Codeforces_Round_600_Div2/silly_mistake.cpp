#include <iostream>
#include <set>
using namespace std;
#define MAX 100001

int n, cnt, last;
int num[MAX], ans[MAX];
set<int> out, enter;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		if (num[i] < 0) {
			if (out.count(-num[i])) {
				out.erase(-num[i]);
			} else {
				cout << "-1\n";
				return 0;
			}
		} else {
			if (!enter.count(num[i])) {
				enter.insert(num[i]);
				out.insert(num[i]);
			} else {
				cout << "-1\n";
				return 0;
			}
		}
		if (!out.size()) {
			ans[++cnt] = i+1 - last;
			last = i+1;
			enter.clear();
		}
	}

	if (cnt == 0 || out.size()) {
		cout << "-1\n";
		return 0;
	}

	cout << cnt << '\n';
	for (int i=1; i<=cnt; ++i)
		cout << ans[i] << ' ';

	return 0;
}
