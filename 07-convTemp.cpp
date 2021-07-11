#include <iostream>

using namespace std;

int main(){

	long segundos=0, minutos=0, horas=0;

	cin >> segundos;

	horas    = segundos / 3600;
	segundos = segundos % 3600;
	minutos  = segundos / 60;
	segundos = segundos % 60;

	cout << horas << ":" << minutos << ":" << segundos << "\n";

	return 0;
}