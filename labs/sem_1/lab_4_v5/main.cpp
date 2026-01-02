#include <iostream>

#define VARIANT 5

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short flag;
	std::cout << "Пункт 1: 1" << std::endl << "Пункт 2: 2" << std::endl;
	std::cin >> flag;

	if (flag == 1) {
		int arr[VARIANT+3];
		unsigned char cnt;

		std::cout << "Введите массив int длиной " << VARIANT+3 << ": ";
		for (int i = 0; i < VARIANT + 3; ++i) {
			std::cin >> arr[i];
			cnt += arr[i] == 25 ? 1 : 0;
		}

		if (cnt > 2) {
			int j, temp, i = 1;
			for (; i < VARIANT + 3; ++i) { // insertion asc
				j = i - 1;
				while (j >= 0 && arr[j + 1] < arr[j]) {
					temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
					--j;
				}
			}
		}

		std::cout << "{ ";
		for (auto& e : arr) {
			std::cout << e << " ";
		}
		std::cout << "}";
	}
	else if (flag == 2) {
		int arr[3][4];
		int cnt, max_cnt = 0, l = 0;

		std::cout << "Введите матрицу int размерностью 3 стр. на 4 столб.:" << std::endl;
		for (int i = 0; i < 3; ++i) {
			cnt = 0;
			for (int j = 0; j < 4; ++j) {
				std::cin >> arr[i][j];
				cnt += arr[i][j] ? 0 : 1;
			}
			if (max_cnt < cnt) {
				max_cnt = cnt;
				l = i;
			}
		}
		
		for (int j = 0; j < 4; ++j)
			arr[l][j] = arr[l][j] ? arr[l][j] : 888;

		std::cout << "{" << std::endl;
		for (auto& row : arr) {
			std::cout << "{ ";
			for (auto& e : row)
				std::cout << e << " ";
			std::cout << "}" << std::endl;
		}
		std::cout << "}";
	}

	return 0;
}