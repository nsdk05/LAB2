#include "Methods.h"

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// функции проверки ввода и функции вывода

// Если поток ввода закрыт, завершает программу
std::string ReadLine(const std::string& message) {
	std::cout << message;
	std::string line;
	if (!std::getline(std::cin, line)) {
		std::cout << "Ввод завершён \n";
		std::exit(0);
	}
	return line;
}

// Строка корректна, если в ней только целое число без лишних символов
int ReadInt(const std::string& message) {
	while (true) {
		std::istringstream stream(ReadLine(message));
		int value = 0;
		char extra = '\0';
		if (stream >> value && !(stream >> extra)) {
			return value;
		}
		std::cout << "Ошибка: нужно ввести целое число \n";
	}
}

// Повторяет ввод, пока число не попадёт в отрезок от min_value до max_value
int ReadIntInRange(const std::string& message, int min_value, int max_value) {
	while (true) {
		int value = ReadInt(message);
		if (value >= min_value && value <= max_value) {
			return value;
		}
		std::cout << "Ошибка: число должно быть от " << min_value << " до "
							<< max_value << " \n";
	}
}

// Функция формирования дека и проверки четности кол-ва. эл.
std::deque<int> ReadDeque() {
	int count = 0;
	while (count <= 0 || count % 2 != 0) {
		count = ReadInt("Введите четное количество элементов очереди :");
		if (count <= 0 || count % 2 != 0) {
			std::cout << "Ошибка: количество должно быть больше нуля "
								<< "и четным \n";
		}
	}
	std::vector<int> number;
	for (int i = 1; i <= count; ++i) {
		number.push_back(ReadInt("Число " + std::to_string(i) + ":"));
	}
	return std::deque<int>(number.begin(), number.end());
}

// Запрос кол-ва. элементов списка при need_even чётного и самих чисел
std::list<int> ReadList(const std::string& title, bool need_even) {
	int count = 0;
	while (count <= 0 || (need_even && count % 2 != 0)) {
		count = ReadInt("Количество элементов " + title + ": ");
		if (count <= 0 || (need_even && count % 2 != 0)) {
			std::cout << "Ошибка: количество должно быть положительным"
								<< (need_even ? " и чётным" : "") << "\n";
		}
	}
	std::vector<int> numbers;
	for (int i = 1; i <= count; ++i) {
		numbers.push_back(ReadInt("Число " + std::to_string(i) + ":"));
	}
	return std::list<int>(numbers.begin(), numbers.end());
}

// Запрос кол-ва. чисел для замены в дек. и запрос самих чисел
std::deque<int> ReadDequeAtLeast(int min_count) {
	const int count = ReadIntInRange(
			"Количество элементов дека (не меньше " +
			std::to_string(min_count) + ") :",
			min_count, std::numeric_limits<int>::max());

	std::vector<int> numbers;
	for (int i = 1; i <= count; ++i) {
		numbers.push_back(ReadInt("Число " + std::to_string(i) + ":"));
	}
	return std::deque<int>(numbers.begin(), numbers.end());
}

// Запрос кол-ва. чисел кратное трем и сами числа
std::vector<int> ReadThirds() {
	int count = 0;
	while (count <= 0 || count % 3 != 0) {
		count = ReadInt("Количество элементов кратное 3 :");
		if (count <= 0 || count % 3 != 0) {
			std::cout << "Кол-во. должно быть положительным "
								<< "и кратным 3 \n";
		}
	}
	const int third = count / 3;
	std::vector<int> numbers;
	for (int i = 0; i < count; ++i) {
		const std::string message = "Число " + std::to_string(i + 1) + ":";
		int value = ReadInt(message);
		while (i % third != 0 && value < numbers.back()) {
			std::cout << "Внутри трети числа идут по возрастанию \n";
			value = ReadInt(message);
		}
		numbers.push_back(value);
	}
	return numbers;
}

// Запрос кол-ва. чисел не меньше min_count и самих чисел
std::vector<int> ReadVectorAtLeast(const std::string& title, int min_count) {
	const int count = ReadIntInRange(
			"Количество элементов " + title + " (не меньше " +
			std::to_string(min_count) + ") :",
			min_count, std::numeric_limits<int>::max());
	std::vector<int> numbers;
	for (int i = 1; i <= count; ++i) {
		numbers.push_back(
				ReadInt(title + ", число " + std::to_string(i) + ":"));
	}
	return numbers;
}

// Запрос набора из count векторов в каждом не меньше min_size элементов
std::vector<std::vector<int>> ReadVectorSet(int count, int min_size) {
	std::vector<std::vector<int>> vectors;
	for (int i = 1; i <= count; ++i) {
		vectors.push_back(ReadVectorAtLeast("V" + std::to_string(i), min_size));
	}
	return vectors;
}

// Знак числа: -1, 0 или 1.
int Sign(int x) {
	return (x > 0) - (x < 0);
}

// Проверка английское ли слово
bool IsEnglishWord(const std::string& word) {
	if (word.empty()) {
		return false;
	}
	for (std::string::const_iterator it = word.begin(); it != word.end();
			 ++it) {
		const bool is_letter = (*it >= 'A' && *it <= 'Z') ||
													 (*it >= 'a' && *it <= 'z');
		if (!is_letter) {
			return false;
		}
	}
	return true;
}

// Запрос кол-ва. слов и самих слов только латинские буквы
std::list<std::string> ReadWords() {
	int count = 0;
	while (count <= 0) {
		count = ReadInt("Количество слов :");
		if (count <= 0) {
			std::cout << "Ошибка: количество должно быть больше нуля \n";
		}
	}
	std::vector<std::string> words;
	for (int i = 1; i <= count; ++i) {
		std::string word = ReadLine("Слово " + std::to_string(i) + ":");
		while (!IsEnglishWord(word)) {
			std::cout << "Ошибка: нужно слово из латинских букв \n";
			word = ReadLine("Слово " + std::to_string(i) + ":");
		}
		words.push_back(word);
	}
	return std::list<std::string>(words.begin(), words.end());
}

// Вывод мультиотображения ключ затем значение
void PrintMultimap(const std::multimap<int, int>& groups) {
	for (std::multimap<int, int>::const_iterator it = groups.begin();
			 it != groups.end(); ++it) {
		std::cout << it->first << ' ' << it->second << "\n";
	}
}

// Работа с файлами

// Создает файл с именем name, размер задется
// вводом с клавиатуры и возвращает его имя
std::string CreateNumbersFile() {
	std::string name = ReadLine("Введите имя файла :");
	std::ofstream out(name);
	if (!out) {
		std::cout << "Не удалось создать файл " << name << "\n";
		return "";
	}
	int count = 0;
	while (count <= 0) {
		count = ReadInt("Сколько чисел записать в файл :");
		if (count <= 0) {
			std::cout << "Кол-во. чисел должно быть больше нуля \n";
		}
	}
	for (int i = 1; i <= count; ++i) {
		out << ReadInt("Число " + std::to_string(i) + ":") << ' ';
	}
	return name;
}

// Задания

// Задание 1.1 Создать вектор и заполнить числами из файла
void MakeFileVector(const std::string& name) {
	std::ifstream in(name);
	if (!in) {
		std::cout << "Не удалось открыть файл :" << name << "\n";
		return;
	}
	std::vector<int> v((std::istream_iterator<int>(in)),
										 std::istream_iterator<int>());
	if (!in.eof()) {
		std::cout << "Чтение завершилось не на числе \n";
	}
	if (v.empty()) {
		std::cout << "Файл пуст \n";
		return;
	}
	PrintContainer(v);
}

// Задание 2.8 Вставить -1 перед каждым
// эл. дека с четным кол-вом. эл.
void InsertMinusOne(std::deque<int>& deq) {
	const std::size_t size_deq = deq.size();
	std::deque<int>::iterator it = deq.begin() + size_deq / 2;
	for (std::size_t i = 0; i < size_deq / 2; ++i) {
		it = deq.insert(--it, -1);
	}
}

// Задание 3.6 Перенести первую половину списка L2 в начало списка L1
void InsertHalfList(std::list<int>& list_one, std::list<int>& list_two) {
	std::list<int>::iterator middle = list_two.begin();
	std::advance(middle, list_two.size() / 2);
	list_one.splice(list_one.begin(), list_two, list_two.begin(), middle);
}

// Задание 4.9 Записать в файл N латинских букв
void WriteLatineInFile(const std::string& name, int number) {
	std::ofstream out(name);
	if (!out) {
		std::cout << "Ошибка: не удалось создать файл " << name << "\n";
		return;
	}
	char letter = 'A';
	std::generate_n(std::ostream_iterator<char>(out), number,
									[&letter]() { return letter++; });
}

// Задание 5.3 Удаление первого и последнего нулевого эл. списка
void DeleteZero(std::list<int>& our_list) {
	std::list<int>::iterator first_zero =
			std::find(our_list.begin(), our_list.end(), 0);
	if (first_zero == our_list.end()) {
		return;
	}
	std::list<int>::reverse_iterator rev =
			std::find(our_list.rbegin(), our_list.rend(), 0);
	std::list<int>::iterator last_zero = (++rev).base();
	our_list.erase(last_zero);
	if (first_zero != last_zero) {
		our_list.erase(first_zero);
	}
}

// Задание 6.3 Перезаписывает N эл. дек с начала и конца
void InsertNumbersInDeq(std::deque<int>& deq, int count) {
	int start = 0;
	auto next = [start]() mutable { return ++start; };
	std::generate(deq.begin(), deq.begin() + count, next);
	std::generate(deq.rbegin(), deq.rbegin() + count, next);
}

// Задание 7.13 сортировка вектора по третям
void SortVectorBySign(std::vector<int>& v) {
	const std::size_t third = v.size() / 3;
	auto by_sign = [](int a, int b) { return Sign(a) < Sign(b); };
	std::inplace_merge(v.begin(), v.begin() + third, v.begin() + 2 * third,
										 by_sign);
	std::inplace_merge(v.begin(), v.begin() + 2 * third, v.end(), by_sign);
}

// Задание 8.2 Построить дек строк по парам соседних слов списка
std::deque<std::string> MakeWordPairs(const std::list<std::string>& words) {
	std::deque<std::string> pairs;
	std::adjacent_difference(
			words.begin(), words.end(), std::back_inserter(pairs),
			[](const std::string& right, const std::string& left) {
				return std::string(1, left.front()) + right.back();
			});
	if (!pairs.empty()) {
		pairs.erase(pairs.begin());
	}
	return pairs;
}

// Задание 9.2 Кол-ва. векторов содержащих все элементы V0 с повторениями
int CountVectorsWithAll(
		const std::vector<int>& vec0,
		const std::vector<std::vector<int>>& vectors) {
	const std::multiset<int> set0(vec0.begin(), vec0.end());
	int count = 0;
	for (std::vector<std::vector<int>>::const_iterator it = vectors.begin();
			 it != vectors.end(); ++it) {
		const std::multiset<int> current(it->begin(), it->end());
		if (std::includes(current.begin(), current.end(),
											set0.begin(), set0.end())) {
			++count;
		}
	}
	return count;
}

// Задание 10.3 Группировка эл. вектора по последней цифре
std::multimap<int, int> GroupByLastDigit(const std::vector<int>& vec) {
	std::multimap<int, int> groups;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();
			 ++it) {
		groups.insert(std::make_pair(std::abs(*it % 10), *it));
	}
	return groups;
}

// Выполнение заданий

// Задание первое
void Task1() {
	std::string name = CreateNumbersFile();
	if (!name.empty()) {
		std::cout << "Вектор из файла : \n";
		MakeFileVector(name);
	}
}

// Задание второе
void Task2() {
	std::deque<int> deq = ReadDeque();
	std::cout << "Исходный дек :";
	PrintContainer(deq);
	InsertMinusOne(deq);
	std::cout << "Результат :";
	PrintContainer(deq);
}

// Задание третье
void Task3() {
	std::list<int> list_one = ReadList("L1", false);
	std::list<int> list_two = ReadList("L2", true);
	std::cout << "L1 до :";
	PrintContainer(list_one);
	std::cout << "L2 до :";
	PrintContainer(list_two);
	InsertHalfList(list_one, list_two);
	std::cout << "L1 после :";
	PrintContainer(list_one);
	std::cout << "L2 после :";
	PrintContainer(list_two);
}

// Задание четвертое
void Task4() {
	std::string name = ReadLine("Введите имя файла :");
	int number = ReadIntInRange("Введите N от 1 до 26 :", 1, 26);
	WriteLatineInFile(name, number);
	std::ifstream in(name);
	std::string letters;
	if (in >> letters) {
		std::cout << "Содержимое файла :" << letters << "\n";
	}
}

// Задание пятое
void Task5() {
	std::list<int> our_list = ReadList("L", false);
	std::cout << "Исходный список :";
	PrintContainer(our_list);
	DeleteZero(our_list);
	std::cout << "Результат :";
	PrintContainer(our_list);
}

// Задание шестое
void Task6() {
	int count = ReadIntInRange("Введите N (N > 0) :", 1,
			std::numeric_limits<int>::max() / 2);
	std::deque<int> deq = ReadDequeAtLeast(2 * count);
	std::cout << "Исходный дек :";
	PrintContainer(deq);
	InsertNumbersInDeq(deq, count);
	std::cout << "Результат :";
	PrintContainer(deq);
}

// Задание седьмое
void Task7() {
	std::vector<int> vec = ReadThirds();
	std::cout << "Исходный вектор :";
	PrintContainer(vec);
	SortVectorBySign(vec);
	std::cout << "Результат :";
	PrintContainer(vec);
}

// Задание восьмое
void Task8() {
	std::list<std::string> words = ReadWords();
	std::deque<std::string> pairs = MakeWordPairs(words);
	if (pairs.empty()) {
		std::cout << "Дек пуст: в списке меньше двух слов \n";
	} else {
		std::cout << "Дек :";
		PrintContainer(pairs);
	}
}

// Задание девятое
void Task9() {
	std::vector<int> vec0 = ReadVectorAtLeast("V0", 1);
	int count = ReadIntInRange("Введите N (N > 0) :", 1,
			std::numeric_limits<int>::max());
	std::vector<std::vector<int>> vectors =
			ReadVectorSet(count, static_cast<int>(vec0.size()));
	std::cout << "Подходящих векторов :"
		<< CountVectorsWithAll(vec0, vectors) << "\n";
}

// Задание десятое
void Task10() {
	std::vector<int> vec = ReadVectorAtLeast("V", 1);
	std::cout << "Группы (ключ и число) : \n";
	PrintMultimap(GroupByLastDigit(vec));
}
