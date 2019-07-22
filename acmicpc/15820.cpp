#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b;
	bool wa = false, why = false;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		if (a != b)
			wa = true;
	}

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		if (a != b)
			why = true;
	}

	if (wa)
		cout << "Wrong Answer\n";
	else if (why)
		cout << "Why Wrong!!!\n";
	else
		cout << "Accepted\n";

	return 0;
}
