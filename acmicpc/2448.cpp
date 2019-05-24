#include <iostream>
using namespace std;
#define MAX 4000

int main()
{
	string star[MAX] = {"  *  ", " * * ", "*****", };
	string t = "   ";
	int n, k = 1;

	cin >> n;
	for (int i=3; i<n; i*=2) {
		for (int j=0; j<i; ++j) {
			star[i+j] = star[j] + " " + star[j];
			star[j] = t + star[j] + t;
		}
		for (int j=0; j<k; ++j)
			t += "   ";
		k *= 2;
	}

	for (int i=0; i<n; ++i)
		cout << star[i] << '\n';

	return 0;
}
