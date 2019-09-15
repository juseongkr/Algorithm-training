#include <iostream>
#include <vector>
using namespace std;

int n;
string s;
vector<int> vec;

bool check(int m)
{
	int last = vec[vec.size()-m];
	int x = 0 , y = 0 , z = 0;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'J') {
			x++;
		} else if (s[i] == 'I' && i < last) {
			x++;
		} else if (s[i] == 'O' && x > 0) {
			x--;
			y++;
		} else if (s[i] == 'I' && y > 0 && i >= last) {
			y--;
			z++;
		}
	}
	if (m == z)
		return true;
	return false;
}

int main()
{
	cin >> n >> s;
	for (int i=0; i<n; ++i)
		if (s[i] == 'I')
			vec.push_back(i);

	int ans = 0;
	int l = 1, r = vec.size();
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) {
			l = mid+1;
			ans = mid;
		} else {
			r = mid-1;
		}
	}
	cout << ans << '\n';

	return 0;
}
