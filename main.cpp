﻿#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double series_sum_frw(double Q)
{
	double s = 0;
	double q = 1;
	while ((s + q > s)||(s+q<s))
	{
		s = s + q;
		q = q * Q;
	}
	return s;
}
double series_sum_back(double Q)
{
	Q = 1 / Q;
	double s = 0;
	double q = 1e-6;
	while (q <= 1)
	{
		s = s + q;
		q = q * Q;
	}
	return s;
}
double tail_series(double x, int N)
{
	double s = 1;
	double X = x;
	for (double i = 1; i < N; i++)
	{
		s = s + X;
		X = X * x / (i+1);
	}
	return s;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	// Машинный эпсилон 
	cout << "Машинный эпсилон" << '\n';
	double eps = 1;
	while (((1 + eps) > 1)||((1 + eps) < 1))
	{
		eps = eps / 2;
	}
	cout << eps << '\n';

	// посчитать ряд 
	cout << "Считаем прогрессию" << '\n';
	cout << "Прямо" << '\n';
	cout << "q = 2    " << series_sum_frw(0.5) << '\n';
	cout << "q = 3    " << series_sum_frw(0.33) << '\n';
	cout << "q = 1/0.99    " << series_sum_frw(0.99) << '\n';
	cout << "Обратно" << '\n';
	cout <<	"q = 2    " << series_sum_back(0.5) << '\n';
	cout << "q = 3    " << series_sum_back(0.3333) << '\n';
	cout << "q = 1/0.99    " << series_sum_back(0.99) << '\n';

	// Считаем экспоненту через ряд
	cout <<  '\n' << "Считаем экспоненту" << '\n';
	cout << "x = 0.5   e=" << exp(0.5) << "    " << tail_series(0.5, 20) << '\n';
	cout << "В лоб  x = -10   e=" << exp(-10) << "    " << tail_series(-10, 20) << '\n';
	cout << "Хитро  x = 0.5   e=" << exp(-10) << "    " << 1/tail_series(10, 20) << '\n';

	// Прверка производной 
	cout << '\n' << "Погрешность в произовдной" << '\n';
	for (double h = 0.1; h > 1e-15; h = h / 10)
	{
		cout << "h = " << h;
		cout << "  err = " << abs((tail_series(2 + h, 20) - tail_series(2, 20)) / h - tail_series(2, 20)) << '\n';
	}
}

