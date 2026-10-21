#ifndef LAB2_METHODS_H_
#define LAB2_METHODS_H_

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

// Задание 1 Заполнение и доступ к элементам

// Читает числа из файла name в вектор и выводит их в исходном порядке
// Если файл не открылся или в нём нет чисел, выводит сообщение
void MakeFileVector(const std::string& name);

// Задание 2 Вставка элементов

// Вставляет число -1 перед каждым элементом первой половины дека
// Требуется чётное количество элементов
void InsertMinusOne(std::deque<int>& deq);

// Задание 3 Удаление элементов

// Переносит первую половину списка list_two в начало списка list_one
// Требуется чётное количество элементов в list_two
void InsertHalfList(std::list<int>& list_one, std::list<int>& list_two);

// Задание 4 Итераторы и алгоритмы

// Записывает в файл name первые number прописных латинских букв
// Требуется 1 <= number <= 26
void WriteLatineInFile(const std::string& name, int number);

// Задание 5 Алгоритмы поиска

// Удаляет из списка первый и последний нулевой элемент
// Если нулей нет, список не меняется, если нуль один, удаляется только он
void DeleteZero(std::list<int>& our_list);

// Задание 6 Базовые модифицирующие алгоритмы

// Записывает в первые count элементов дека числа 1, 2, ..., count,
// а в последние count элементов числа count, ..., 2, 1
// Требуется count > 0 и размер дека не меньше 2 * count
void InsertNumbersInDeq(std::deque<int>& deq, int count);

// Задание 7 Сортировка и слияние

// Возвращает знак числа: -1, 0 или 1
int Sign(int x);

// Переставляет элементы вектора: сначала отрицательные, затем нулевые,
// затем положительные, порядок внутри каждой группы сохраняется
// Требуется размер, кратный 3, и порядок по возрастанию внутри каждой трети
void SortVectorBySign(std::vector<int>& v);

// Задание 8 Численные алгоритмы

// Строит дек строк по парам соседних слов списка: к первой букве левого
// слова справа приписывается последняя буква правого слова
// Размер дека на 1 меньше размера списка (для списка из 0 или 1 слова пуст)
std::deque<std::string> MakeWordPairs(const std::list<std::string>& words);

// Задание 9 Множества

// Возвращает количество векторов набора, в которых содержатся все элементы
// vec0 с учётом повторений
int CountVectorsWithAll(
		const std::vector<int>& vec0,
		const std::vector<std::vector<int>>& vectors);

// Задание 10 Отображения

// Группирует элементы вектора по последней цифре (по модулю), порядок
// элементов внутри группы совпадает с исходным
std::multimap<int, int> GroupByLastDigit(const std::vector<int>& vec);

// Ввод с проверкой и вывод

// Выводит приглашение и считывает строку целиком
std::string ReadLine(const std::string& message);

// Запрашивает целое число до тех пор, пока ввод не будет корректным
int ReadInt(const std::string& message);

// Запрашивает целое число из отрезка [min_value, max_value]
int ReadIntInRange(const std::string& message, int min_value, int max_value);

// Запрашивает положительное чётное количество чисел и сами числа,
// возвращает их в деке
std::deque<int> ReadDeque();

// Запрашивает количество чисел (не меньше min_count) и сами числа,
// возвращает их в деке
std::deque<int> ReadDequeAtLeast(int min_count);

// Запрашивает положительное количество чисел (при need_even чётное)
// и сами числа, возвращает их в списке; title показывается в приглашении
std::list<int> ReadList(const std::string& title, bool need_even);

// Запрашивает положительное количество чисел, кратное 3, и сами числа,
// внутри каждой трети числа вводятся по возрастанию
std::vector<int> ReadThirds();

// Запрашивает количество чисел (не меньше min_count) и сами числа,
// возвращает их в векторе; title показывается в приглашении
std::vector<int> ReadVectorAtLeast(const std::string& title, int min_count);

// Запрашивает count векторов, в каждом не меньше min_size элементов
std::vector<std::vector<int>> ReadVectorSet(int count, int min_size);

// Возвращает true, если слово непустое и состоит только из латинских букв
bool IsEnglishWord(const std::string& word);

// Запрашивает положительное количество слов и сами слова, каждое слово
// должно состоять только из латинских букв, возвращает их в списке
std::list<std::string> ReadWords();

// Выводит элементы любого контейнера через пробел и переводит строку
// Подходит для vector, deque, list, set, multiset и т. д., но не для map
// и multimap (их элементы являются парами)
// Тип элементов должен поддерживать вывод через <<
template <typename Container>
void PrintContainer(const Container& container) {
	for (typename Container::const_iterator it = container.begin();
			 it != container.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << "\n";
}

// Выводит мультиотображение: в каждой строке ключ, затем значение
void PrintMultimap(const std::multimap<int, int>& groups);

// Работа с файлами

// Запрашивает имя файла, количество чисел и сами числа, записывает их
// в файл через пробел
// Возвращает имя файла, при ошибке создания возвращает пустую строку
std::string CreateNumbersFile();

// Выполнение заданий

void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();
void Task8();
void Task9();
void Task10();

#endif  // LAB2_METHODS_H_
