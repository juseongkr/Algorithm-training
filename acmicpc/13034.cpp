#include <iostream>
#include <set>
using namespace std;
#define MAX 1001

int n;
int group[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<=n; ++i) {
		set<int> st;
		for (int j=0; j<=i-2; ++j)
			st.insert(group[j] ^ group[i-j-2]);

		for (int j=0; ; ++j) {
			if (!st.count(j)) {
				group[i] = j;
				break;
			}
		}
	}

	if (group[n])
		cout << "1\n";
	else
		cout << "2\n";

	return 0;
}
