#include <iostream>
#include <vector>
#include <array>
#include <ctime>

#define VARIANT 5
#define ARR_SIZE 10

template<typename T>
void printVec(std::vector<T>& vec)
{
	std::cout << std::endl;
	for (T& e : vec) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void pushFrontVec(std::vector<T>& vec)
{
	T tmp;
	std::cout << "Введите элемент: ";
	std::cin >> tmp;
	vec.insert(vec.begin(), tmp);
}

template<typename T>
void pushBackVec(std::vector<T>& vec)
{
	T tmp;
	std::cout << "Введите элемент: ";
	std::cin >> tmp;
	vec.insert(vec.end(), tmp);
}

template<typename T>
void findInVec(std::vector<T>& vec)
{
	T tmp;
	std::cout << "Введите элемент: ";
	std::cin >> tmp;
	unsigned long long index = 0;
	for (T& e : vec) // сделаем вид, что не знаем про <algorithm>
	{
		index++;
		if (e == tmp) break;
		index++;
	}
	if (index % 2 == 0)
		std::cout << "Такого элемента нет в массиве" << std::endl;
	else {
		std::cout << "[" << (index - 1)/2 << "]" << std::endl;
	}
}


void specialEx(std::vector<long>& vec)
{
	printVec(vec);
	long long k, last = 1, sum = 0;
	std::cout << "Введите число K: ";
	std::cin >> k;

	while (sum < k) {
		sum += last++;
	}
	if (sum == k) {
		for (unsigned long long i = 1; i < last; ++i) {
			vec.push_back(i);
		}
	}
	else {
		for (unsigned long long i = 0; i < vec.size(); i += 3) {
			vec.insert(vec.begin() + i, vec[i]);
		} // будем считать позиции с нуля (чётные: 0, 2...)
	}
	printVec(vec);
}

void firstClause()
{
	std::vector<long> vec;
	uint16_t flag;
	for (;;) {
		std::cout << std::endl << "0: Выход" << std::endl << "1: Просмотр массива" << std::endl << "2: Добавить элемент в начало" << std::endl << "3: Добавить элемент в конец" << std::endl << "4: Очистка массива" << std::endl << "5: Поиск элемента" << std::endl << "6. Задание варианта" << std::endl;
		std::cin >> flag;
		if (!flag) break; 
		if (flag == 1)
			printVec(vec);
		else if (flag == 2)
			pushFrontVec(vec);
		else if (flag == 3)
			pushBackVec(vec);
		else if (flag == 4)
			vec.clear();
		else if (flag == 5)
			findInVec(vec);
		else if (flag == 6)
			specialEx(vec);
	}
}

template<long S>
std::array<long, S> valSort(std::array<long, S> arr, std::string order = "asc")
{
	for (unsigned long long i = 1; i < S; ++i) {
		for (unsigned long long j = i; j > 0; --j) {
			if ((order == "asc" && arr[j - 1] <= arr[j]) || (order == "desc" && arr[j - 1] >= arr[j])) break;
			std::swap(arr[j - 1], arr[j]);
		}
	}
	return arr;
}

template<long S>
void ptrSort(std::array<long, S>* arr, std::string order = "asc")
{
	for (unsigned long long i = 1; i < S; ++i) {
		for (unsigned long long j = i; j > 0; --j) {
			if ((order == "asc" && (*arr)[j - 1] <= (*arr)[j]) || (order == "desc" && (*arr)[j - 1] >= (*arr)[j])) break;
			std::swap((*arr)[j - 1], (*arr)[j]);
		}
	}
}

template<long S>
void refSort(std::array<long, S>& arr, std::string order = "asc")
{
	for (unsigned long long i = 1; i < S; ++i) {
		for (unsigned long long j = i; j > 0; --j) {
			if ((order == "asc" && arr[j - 1] <= arr[j]) || (order == "desc" && arr[j - 1] >= arr[j])) break;
			std::swap(arr[j - 1], arr[j]);
		}
	}
}

void secondClause()
{
	std::array<long, ARR_SIZE> init_arr;
	
	std::srand(std::time(nullptr));
	for (unsigned long long i = 0; i < init_arr.size(); ++i) {
		init_arr[i] = (rand() % 21) - 10; // [-10; 10]
	}

	std::array<long, 10> arr = init_arr;

	std::cout << "Исходный массив: " << std::endl;
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";

	std::cout << std::endl << "Для сортировки с передачей по значению присваиваем нашему вектору результат функции: " << std::endl;
	arr = valSort<ARR_SIZE>(arr, "asc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	arr = valSort<ARR_SIZE>(arr, "desc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
	arr = init_arr;
	
	std::cout << std::endl << "Для сортировки по указателю передаём в функцию указатель, но присваивать результат не требуется: " << std::endl;
	ptrSort<ARR_SIZE>(&arr, "asc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	ptrSort<ARR_SIZE>(&arr, "desc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
	arr = init_arr;

	std::cout << std::endl << "Для сортировки по ссылке передаём в функцию переменную, на которую создаётся ссылка, присваивать результат не требуется: " << std::endl;
	refSort<ARR_SIZE>(arr, "asc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	refSort<ARR_SIZE>(arr, "desc");
	for (unsigned long long i = 0; i < ARR_SIZE; ++i)
		std::cout << arr[i] << " ";
}

void thirdClause()
{
	std::cout << "В п1 я выбрал вектор (то есть динамический массив), так как его размер удобно менять => удобно/удалять вставлять элементы" << std::endl;
	std::cout << "В п2 я выбрал статический массив (а точнее его обёртку), так как размер массива не изменяется" << std::endl;
	std::cout << "Выбора не было вследствие смысла используемых типов. В первом пункте базового функционала std::array недостаточно, во втором - использование вектора избыточно" << std::endl;
	std::cout << "Одинаковую роль по сути играют во втором пункте, когда не требуется вставка/удаление, то есть операции, меняющие размер массива";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	uint16_t flag;
	std::cout << "Пункт 1: 1" << std::endl << "Пункт 2: 2" << std::endl << "Пункт 3: 3" << std::endl;
	std::cin >> flag;
	if (flag == 1) 
		firstClause();
	else if (flag == 2)
		secondClause();
	else if (flag == 3)
		thirdClause();
	return 0;
}