#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double h, l;

	cin >> h >> l;

	cout << fixed << setprecision(10) << (l*l-h*h)/(2.0*h) << '\n';

	return 0;
}
