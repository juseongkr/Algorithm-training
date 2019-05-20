#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

int fail[MAX];

int main()
{
	vector<int> ans;
	string a, b;

	getline(cin, a);
	getline(cin, b);
	for (int i=1, j=0; i<b.length(); ++i) {
		while (j && b[i] != b[j])
			j = fail[j-1];

		if (b[i] == b[j])
			fail[i] = ++j;
	}

	for (int i=0, j=0; i<a.length(); ++i) {
		while (j && a[i] != b[j])
			j = fail[j-1];

		if (a[i] == b[j]) {
			if (j == b.length()-1) {
				ans.push_back(i - b.length() + 2);
				j = fail[j];
			} else {
				j++;
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}
