#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	set<int> st;
	vector<int> vec;
	int n, k;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i) {
		if (!st.count(vec[i]-1) && vec[i] > 1) {
			st.insert(vec[i]-1);
		} else if (!st.count(vec[i])) {
			st.insert(vec[i]);
		} else {
			st.insert(vec[i]+1);
		}
	}
	cout << st.size() << '\n';

	return 0;
}
