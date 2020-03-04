#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

string s;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s;
	int l = 0, r = s.length()-1;
	while (l < r) {
		if (s[l] != '(') {
			l++;
		} else if (s[r] != ')') {
			r--;
		} else {
			vec.push_back(l);
			vec.push_back(r);
			l++;
			r--;
		}
	}

	if (vec.size()) {
		sort(vec.begin(), vec.end());
		cout << "1\n";
		cout << vec.size() << '\n';
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] + 1 << " ";
	} else {
		cout << "0\n";
	}

	return 0;
}
