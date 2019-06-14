#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	map<string, float> dict = {{"A+",4.3}, {"A0",4.0}, {"A-",3.7}, {"B+",3.3}, {"B0",3.0}, {"B-",2.7}, {"C+",2.3}, {"C0",2.0}, {"C-",1.7}, {"D+",1.3}, {"D0",1.0}, {"D-",0.7}, {"F",0.0}};
	string a, c;
	int t, b;

	int credit = 0;
	float grade = 0.0;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		credit += b;
		grade += float(b) * dict[c];
	}
	cout << fixed << setprecision(2) << grade/credit << '\n';

	return 0;
}
