#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n;
int num[129];
set<int> st;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int x = num[n-1];
	for (int i=1; i<=x; ++i)
		if (x % i == 0)
			st.insert(i);

	int y = 0;
	for (int i=0; i<n; ++i) {
		if (st.count(num[i]))
			st.erase(num[i]);
		else
			y = num[i];
	}

	cout << x << " " << y << '\n';

	return 0;
}
