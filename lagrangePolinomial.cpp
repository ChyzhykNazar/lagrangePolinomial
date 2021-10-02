/*Для функції f (x) = sin (x) + x скласти таблицю значень.
На основі складеної таблиці побудувати інтерполяційний поліном Лагранжа. Порівняти значення інтерполяційних
полінома в точках х = -7,7; -5,5; -2,2; зі значеннями точної функції, оцінити точність наближення.*/

/*For function f(x) = sin (x) + x entered table.
Lagrange interpolation polynomial are initiated on the basis of the compiled table. Compare the values ​​of interpolation
polinomial in dot's x = х = -7,7; -5,5; -2,2; with the values ​​of the exact function, estimate the accuracy of the approximation.*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

//function
double func(double x) {
	return sin(x) + x;
}

//output of vector elements for solved methods
void print(vector<double> vec, vector<double> x) {
	for (int i = 0; i < vec.size(); i++) {
		cout << "Solution in point: " << x[i] << " = " << vec[i] << endl;
	}
	cout << endl;
}

//output of vector elements
void print(vector<double> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

//output of error between the exact and found value
void eps(vector<double> vec, vector<double> x) {
	for (int i = 0; i < vec.size(); i++) {
		cout << "Precision in point: " << x[i] << " = " << setw(10) << abs(abs(vec[i]) - abs(func(x[i]))) << endl;
	}
}

//lagrange polinomial
void polinomLagrange(vector<double> x, vector<double> _x, vector<double> _y) {
	cout << "________Answer method of Lagrange multipliers________________" << endl;
	vector<double> result;
	for (int i = 0; i < x.size(); i++) {
		double sum = 0;
		for (int j = 0; j < _x.size(); j++) {
			double mul = 1;
			for (int k = 0; k < _x.size(); k++) {
				if (j != k) {
					mul *= (x[i] - _x[k]) / (_x[j] - _x[k]);
				}
			}
			sum += _y[j] * mul;
		}
		result.push_back(sum);
	}
	print(result, x);
	eps(result, x);
}

int main()
{
	double xTemp;
	double yTemp;
	vector<double> _x;
	vector<double> _y;
	vector<double> x;
	ifstream file("data.txt");
	while (!file.eof()) {
		file >> xTemp >> yTemp;
		_x.push_back(xTemp);
		_y.push_back(yTemp);
	}
	file.close();
	ifstream fileEx("lagrangePolinomial.txt");
	while (!fileEx.eof()) {
		fileEx >> xTemp;
		x.push_back(xTemp);
	}
	fileEx.close();
	cout << "x: ";
	print(_x);
	cout << "y: ";
	print(_y);
	cout << "Dots: ";
	print(x);
	cout << endl;
	polinomLagrange(x, _x, _y);
}