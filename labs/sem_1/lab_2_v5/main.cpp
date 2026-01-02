#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short flag;
	std::cout << "Меню: " << std::endl << "Пункт 1: 1" << std::endl << "Пункт 2: 2" << std::endl;
	std::cin >> flag;
	if (flag == 1) {
		short a, i;
		std::cout << std::endl << "Число: ";
		std::cin >> a; 
		std::cin.clear(); // в условии проверка числа A не упоминается
		std::cin.ignore(1024, '\n');
		std::cout << "Номер бита (0-7): "; // нумерация битов с нуля
		while(!(std::cin >> i) || i > 7 || i < 0)
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Неправильно введено. Число (1-8): "; 
		}

		unsigned char ibit = ((1 << i) & a) >> i;
		a = ibit ? a : (((a & 1) << i) | a) & (~1);
		std::cout << (a & 255) << " = ";
		for(int i = 7; i >= 0; --i)
		{
			std::cout << ((a >> i) & 1);
		}
	}
	else if (flag == 2) {
		unsigned short n;
		std::cout << std::endl << "Введите номер региона: ";
		while(!(std::cin >> n))
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Неправильно введено. Введите номер региона: "; 
		}
		switch(n)
		{
			case 102:
				std::cout << "Республика Башкортостан";
				break;
			case 11:
				std::cout << "Республика Коми";
				break;
			case 13:
				std::cout << "Республика Мордовия";
				break;
			case 15:
				std::cout << "Республика Северная Осетия";
				break;
			case 116: case 716:
				std::cout << "Республика Татарстан";
				break;
			default:
				std::cout << "Информация временно недоступна";
		};
	}

	return 0;
}