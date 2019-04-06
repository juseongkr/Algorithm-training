#include <iostream>
#include <algorithm>
using namespace std;

struct student {
	int year;
	int month;
	int day;
	string name;
};

bool cmp(struct student a, struct student b)
{
	if (a.year != b.year)
		return a.year > b.year;
	else if (a.month != b.month)
		return a.month > b.month;
	else
		return a.day > b.day;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	struct student t, list[100] = {0, };
	int n, year, month, day;
	string name;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t.name >> t.day >> t.month >> t.year;
		list[i] = t;
	}
	sort(list, list + n, cmp);

	cout << list[0].name << '\n' << list[n-1].name << '\n';

	return 0;
}
