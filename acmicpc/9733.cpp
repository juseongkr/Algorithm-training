#include <iostream>
#include <iomanip>
using namespace std;

int cnt;
int ans[10];
string x;
string s[] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};

int main()
{
	while (cin >> x) {
		cnt++;
		for (int i=0; i<7; ++i)
			if (x == s[i])
				ans[i]++;
	}

	for (int i=0; i<7; ++i)
		cout << fixed << setprecision(2) << s[i] << " " << ans[i] << " " <<  ans[i]/(double)cnt << '\n';

	cout << "Total " << cnt << " 1.00\n";
	
	return 0;
}
