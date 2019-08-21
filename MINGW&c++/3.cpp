#include<iostream>
#include <iomanip> 
using namespace std;

int main() 
{
	double dl,df;
	cin >> dl;
	if (dl <= 150)
		df = dl * 0.4463;
	else if (dl > 150 && dl <= 400)
		df = 150 * 0.4463 + (dl - 150)*0.4663;
	else
		df = 150 * 0.4463 + 250 * 0.4663 + (dl - 400)*0.5663;

	cout << setprecision(1) << fixed << df;
	return 0;
}