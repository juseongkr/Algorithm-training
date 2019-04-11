#include <iostream>
#include <algorithm>
using namespace std;

struct score {
	int ko;
	int en;
	int ma;
	string name;
};

bool cmp(struct score x, struct score y)
{
	if (x.ko > y.ko) {
		return true;
	} else if (x.ko == y.ko) {
		if (x.en < y.en) {
			return true;
		} else if (x.en == y.en) {
			if (x.ma > y.ma)
				return true;
			else if (x.ma == y.ma)
				return x.name < y.name;
		}
	}
	return false;
}

struct score s[100001];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		cin >> s[i].name >> s[i].ko >> s[i].en >> s[i].ma;

	sort(s, s+n, cmp);

	for (int i=0; i<n; ++i)
		cout << s[i].name << '\n';

	return 0;
}
