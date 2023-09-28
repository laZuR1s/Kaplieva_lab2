#include<iostream>
#include<Windows.h>
#include<iomanip>

int main()
{
	SetConsoleOutputCP(1251);

	short choice;
	do
	{
		std::cout << "\n1. Сумма заданного количества слагаемых\n";
		std::cout << "2. Сумма с заданной точностью\n";
		std::cout << "3. Завершение работы\n";
		bool isError = false;
		do
		{
			isError = false;
			std::cout << "->";

			if (!(std::cin >> choice && choice >= 1 && choice <= 3))
			{
				std::cout << "\nInput error\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				isError = true;
			}
		} while (isError);
		if (choice != 3)
		{
			
			double x;
			bool isError = false;
			do
			{
				isError = false;
				std::cout << "\nВведите значение x: ";

				if (!(std::cin >> x))
				{
					std::cout << "\nInput error\n";
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					isError = true;
				}
			} while (isError);


			//std::cout << std::setw(26) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << asin(x) << '\n';

			if (choice == 1)
			{
				//std::cout << "Задача 1\n";
				int n;
				std::cout << "Введите количество слагаемых: ";
				std::cin >> n;
				double res = 1;
				double fact = 1;
				double term = 1;
				for (int i = 1; i <= n; i++)
				{
						
						term = (term * x * x) / (fact * (fact + 1));
						res = res + term;
						fact = fact + 2;
					
					
				}
				std::cout << '\n' << std::setw(28) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << cosh(x) << '\n';
				std::cout << std::setw(28) << std::left << "Приближенное значение" << " = " << std::fixed << std::setprecision(11) << res << '\n';

			}
			else
			{
				//std::cout << "Задача 2\n";
				double eps;
				std::cout << "\nВведите точность вычисления: ";
				std::cin >> eps;
				double term = 1;
				double fact = 1;
				double res = 1;
				int count = 0;
				bool isCalculated = true;
				while (term>eps/10)
				{
					
					term = (term * x * x) / (fact * (fact + 1));
					res = res + term;
					fact = fact + 2;
					count++;
					if (term < eps && isCalculated)
					{
						std::cout << std::setw(28) << std::left << "\nПриближенное значение" << " = " << std::fixed << std::setprecision(11) << res << '\n';
						isCalculated = false;

					}
				}
				std::cout << std::setw(28) << std::left << "Значение c большей точностью" << " = " << std::fixed << std::setprecision(11) << res << '\n';
				std::cout << std::setw(28) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << cosh(x) << '\n';
				std::cout << "Количество слагаемых: " << count<<'\n';
			}
			// вывод результата
			//std::cout << std::setw(26) << std::left << "Приближенное значение" << " = " << std::fixed << std::setprecision(11) << asin(x) << '\n';


			std::cout << "\nЗавершить работу? (Y/любая клавиша): ";

			char isExit;
			std::cin >> isExit;

			if (isExit == 'Y' || isExit == 'y')
				choice = 3;
		}

	} while (choice != 3);

}
