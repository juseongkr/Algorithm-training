#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> st;
	int a, b, j;

	for (int i=1; ; ++i) {
		st.clear();
		bool flag = false;

		for (j=0; ; ++j) {
			cin >> a >> b;
			if (a == 0 && b == 0)
				break;

			if (a < 0 && b < 0) {
				flag = true;
				break;
			}

			st.insert(a);
			st.insert(b);
		}
		if (flag)
			break;

		if (j == 0 || j == st.size()-1)
			cout << "Case " << i << " is a tree.\n";
		else
			cout << "Case " << i << " is not a tree.\n";
	}

	return 0;
}
