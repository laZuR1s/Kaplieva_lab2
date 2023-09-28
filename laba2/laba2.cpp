#include<iostream>
#include<Windows.h>
#include<iomanip>

int main()
{
	SetConsoleOutputCP(1251);

	short choice;
	do
	{
		std::cout << "\n1. ����� ��������� ���������� ���������\n";
		std::cout << "2. ����� � �������� ���������\n";
		std::cout << "3. ���������� ������\n";
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
				std::cout << "\n������� �������� x: ";

				if (!(std::cin >> x))
				{
					std::cout << "\nInput error\n";
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					isError = true;
				}
			} while (isError);


			//std::cout << std::setw(26) << std::left << "������ ��������" << " = " << std::fixed << std::setprecision(11) << asin(x) << '\n';

			if (choice == 1)
			{
				//std::cout << "������ 1\n";
				int n;
				std::cout << "������� ���������� ���������: ";
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
				std::cout << '\n' << std::setw(28) << std::left << "������ ��������" << " = " << std::fixed << std::setprecision(11) << cosh(x) << '\n';
				std::cout << std::setw(28) << std::left << "������������ ��������" << " = " << std::fixed << std::setprecision(11) << res << '\n';

			}
			else
			{
				//std::cout << "������ 2\n";
				double eps;
				std::cout << "\n������� �������� ����������: ";
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
						std::cout << std::setw(28) << std::left << "\n������������ ��������" << " = " << std::fixed << std::setprecision(11) << res << '\n';
						isCalculated = false;

					}
				}
				std::cout << std::setw(28) << std::left << "�������� c ������� ���������" << " = " << std::fixed << std::setprecision(11) << res << '\n';
				std::cout << std::setw(28) << std::left << "������ ��������" << " = " << std::fixed << std::setprecision(11) << cosh(x) << '\n';
				std::cout << "���������� ���������: " << count<<'\n';
			}
			// ����� ����������
			//std::cout << std::setw(26) << std::left << "������������ ��������" << " = " << std::fixed << std::setprecision(11) << asin(x) << '\n';


			std::cout << "\n��������� ������? (Y/����� �������): ";

			char isExit;
			std::cin >> isExit;

			if (isExit == 'Y' || isExit == 'y')
				choice = 3;
		}

	} while (choice != 3);

}
