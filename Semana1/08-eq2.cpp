#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

	double a, b, c, delta, raiz1, raiz2;

	cin >> a >> b >> c;

	delta = sqrt(pow(b, 2) - 4*a*c);
	raiz1 = (-b+delta)/(2*a);
	raiz2 = (-b-delta)/(2*a);;

	cout << fixed  << setprecision(4) << raiz1 << " " << raiz2 << endl;

	return 0;
}