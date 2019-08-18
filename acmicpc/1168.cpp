#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	vector<int> vec, ans;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		vec.push_back(i);

	int pos = 0;
	while (vec.size() != 0) {
		pos = (pos + m - 1) % vec.size();
		ans.push_back(vec[pos]);
		vec.erase(vec.begin() + pos);
	}

	cout << "<";
	for (int i=0; i<ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << ", ";
	}
	cout << ">\n";

	return 0;
}
