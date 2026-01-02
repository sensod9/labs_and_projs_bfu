#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short flag;
	std::cout << "Меню: " << std::endl << "Пункт 1: 1" << std::endl << "Пункт 2: 2" << std::endl;
	std::cin >> flag;

	if (flag == 1) {
		unsigned int n, l;
		double e, le, sum = 0;
		bool is_found = false;
		
		std::cout << "Введите кол-во чисел: ";
		std::cin >> n;
		std::cout << "Введите последовательность: " << std::endl;

		for(int i = 0; i < n; ++i) {
			std::cin >> e;
			sum += e <= 10.12 ? is_found = true, e : 0;
			if (e < le) {
				l = i;
				le = e;
			}
		}

		if (is_found)
			std::cout << "Сумма: " << sum << std::endl << "Наименьший, удовл. усл.: " << le << std::endl << "Номер наим. (считая от нуля): " << l; 
		else
			std::cout << "Чисел, удовл. усл. нет";
	}
	else if (flag == 2) {
		short x, i, l = -1;
		
		std::cout << "Введите X: ";
		std::cin >> x;
		i = x <= 0 ? 11 : 0;
		x = abs(x);

		while (x > 0) {
			if (l == -1 && x % 10 == 3) {
				l = i;
			}
			x /= 10;
			++i;
		};

		if (l != -1) {
			l = i < 10 ? (i - 1) - l : i - l;
			std::cout << "Индекс последней '3' (с нуля + слева направо + учитывая минус): " << l;
		}
		else {
			std::cout << "Цифры '3' нет в записи";
		}
		
		/* скучный путь
		char formatted[7];
		sprintf(formatted, "%d", x);
		for (int i = 0; formatted[i] != '\0'; ++i) {
			l = formatted[i] == '3' ? i : l;
		}
		if (l >= 0)
			std::cout << "Индекс последней '3' (с нуля + учитывая минус, если есть): " << l;
		else
			std::cout << "Цифры '3' нет в записи";
		*/
	}

	return 0;
}