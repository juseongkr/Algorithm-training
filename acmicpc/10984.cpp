#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, n, a;
	double b;

	cin >> t;
	while (t--) {
		cin >> n;
		int credit = 0;
		double gpa = 0.0;
		for (int i=0; i<n; ++i) {
			cin >> a >> b;
			credit += a;
			gpa += a*b;
		}
		cout << credit << " " << round(gpa/credit*10)/10 << '\n';
	}

	return 0;
}
