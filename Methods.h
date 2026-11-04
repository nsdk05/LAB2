/**
 * @file Methods.h
 * @brief Объявления функций лабораторной работы №2 (STL).
 *
 * Содержит функции десяти заданий, функции ввода с проверкой, вывода
 * и функции-обёртки Task1..Task10 для пунктов меню.
 */

#ifndef LAB2_METHODS_H_
#define LAB2_METHODS_H_

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

/**
 * @name Задание 1. Заполнение и доступ к элементам
 * @{
 */

/**
 * @brief Читает числа из файла в вектор и выводит их в исходном порядке.
 *
 * Вектор создаётся конструктором от пары istream_iterator.
 *
 * @param name Имя входного файла с целыми числами.
 * @note Если файл не открылся или в нём нет чисел, выводит сообщение.
 */
void MakeFileVector(const std::string& name);
/** @} */

/**
 * @name Задание 2. Вставка элементов
 * @{
 */

/**
 * @brief Вставляет число -1 перед каждым элементом первой половины дека.
 *
 * @param deq Дек для изменения.
 * @pre Количество элементов дека чётное.
 */
void InsertMinusOne(std::deque<int>& deq);
/** @} */

/**
 * @name Задание 3. Удаление элементов
 * @{
 */

/**
 * @brief Переносит первую половину списка list_two в начало списка list_one.
 *
 * Перенос выполняется одним вызовом splice, значения не копируются.
 *
 * @param list_one Список, в начало которого переносятся элементы.
 * @param list_two Список, из которого переносится первая половина.
 * @pre Количество элементов в list_two чётное.
 */
void InsertHalfList(std::list<int>& list_one, std::list<int>& list_two);
/** @} */

/**
 * @name Задание 4. Итераторы и алгоритмы
 * @{
 */

/**
 * @brief Записывает в файл первые number прописных латинских букв.
 *
 * Использует generate_n и ostream_iterator.
 *
 * @param name Имя выходного файла.
 * @param number Количество букв.
 * @pre 1 <= number <= 26.
 * @note Если файл не удалось создать, выводит сообщение об ошибке.
 */
void WriteLatineInFile(const std::string& name, int number);
/** @} */

/**
 * @name Задание 5. Алгоритмы поиска
 * @{
 */

/**
 * @brief Удаляет из списка первый и последний нулевой элемент.
 *
 * Если нулей нет, список не меняется. Если нуль один, удаляется только он.
 *
 * @param our_list Список для изменения.
 */
void DeleteZero(std::list<int>& our_list);
/** @} */

/**
 * @name Задание 6. Базовые модифицирующие алгоритмы
 * @{
 */

/**
 * @brief Заполняет начало и конец дека последовательностями 1..count
 * и count..1.
 *
 * В первые count элементов записывает 1, 2, ..., count, в последние
 * count элементов записывает count, ..., 2, 1.
 *
 * @param deq Дек для изменения.
 * @param count Длина каждой последовательности.
 * @pre count > 0 и размер дека не меньше 2 * count.
 */
void InsertNumbersInDeq(std::deque<int>& deq, int count);
/** @} */

/**
 * @name Задание 7. Сортировка и слияние
 * @{
 */

/**
 * @brief Возвращает знак числа.
 *
 * @param x Число.
 * @return -1, 0 или 1.
 */
int Sign(int x);

/**
 * @brief Переставляет элементы вектора: сначала отрицательные, затем
 * нулевые, затем положительные.
 *
 * Порядок внутри каждой группы сохраняется. Использует два вызова
 * inplace_merge.
 *
 * @param v Вектор для изменения.
 * @pre Размер вектора кратен 3, каждая треть упорядочена по возрастанию.
 */
void SortVectorBySign(std::vector<int>& v);
/** @} */

/**
 * @name Задание 8. Численные алгоритмы
 * @{
 */

/**
 * @brief Строит дек строк по парам соседних слов списка.
 *
 * К первой букве левого слова справа приписывается последняя буква правого.
 *
 * @param words Список слов.
 * @return Дек строк. Его размер на 1 меньше размера списка, для списка
 * из 0 или 1 слова дек пуст.
 */
std::deque<std::string> MakeWordPairs(const std::list<std::string>& words);
/** @} */

/**
 * @name Задание 9. Множества
 * @{
 */

/**
 * @brief Считает векторы набора, содержащие все элементы vec0 с учётом
 * повторений.
 *
 * @param vec0 Вектор V0.
 * @param vectors Набор векторов V1..VN.
 * @return Количество подходящих векторов.
 */
int CountVectorsWithAll(
		const std::vector<int>& vec0,
		const std::vector<std::vector<int>>& vectors);
/** @} */

/**
 * @name Задание 10. Отображения
 * @{
 */

/**
 * @brief Группирует элементы вектора по последней цифре (по модулю).
 *
 * Порядок элементов внутри группы совпадает с исходным.
 *
 * @param vec Вектор чисел.
 * @return Мультиотображение: ключ - последняя цифра, значение - элемент.
 */
std::multimap<int, int> GroupByLastDigit(const std::vector<int>& vec);
/** @} */

/**
 * @name Ввод с проверкой и вывод
 * @{
 */

/**
 * @brief Выводит приглашение и считывает строку целиком.
 *
 * @param message Приглашение к вводу.
 * @return Введённая строка.
 * @note Если поток ввода закрыт, завершает программу.
 */
std::string ReadLine(const std::string& message);

/**
 * @brief Запрашивает целое число, пока ввод не будет корректным.
 *
 * @param message Приглашение к вводу.
 * @return Введённое число.
 */
int ReadInt(const std::string& message);

/**
 * @brief Запрашивает целое число из отрезка [min_value, max_value].
 *
 * @param message Приглашение к вводу.
 * @param min_value Нижняя граница.
 * @param max_value Верхняя граница.
 * @return Введённое число.
 */
int ReadIntInRange(const std::string& message, int min_value, int max_value);

/**
 * @brief Запрашивает положительное чётное количество чисел и сами числа.
 *
 * @return Введённые числа в деке.
 */
std::deque<int> ReadDeque();

/**
 * @brief Запрашивает количество чисел и сами числа.
 *
 * @param min_count Минимально допустимое количество чисел.
 * @return Введённые числа в деке.
 */
std::deque<int> ReadDequeAtLeast(int min_count);

/**
 * @brief Запрашивает положительное количество чисел и сами числа.
 *
 * @param title Название списка, показывается в приглашении.
 * @param need_even Если true, количество чисел должно быть чётным.
 * @return Введённые числа в списке.
 */
std::list<int> ReadList(const std::string& title, bool need_even);

/**
 * @brief Запрашивает положительное количество чисел, кратное 3, и сами числа.
 *
 * Внутри каждой трети числа вводятся по возрастанию.
 *
 * @return Введённые числа в векторе.
 */
std::vector<int> ReadThirds();

/**
 * @brief Запрашивает количество чисел и сами числа.
 *
 * @param title Название вектора, показывается в приглашении.
 * @param min_count Минимально допустимое количество чисел.
 * @return Введённые числа в векторе.
 */
std::vector<int> ReadVectorAtLeast(const std::string& title, int min_count);

/**
 * @brief Запрашивает набор векторов.
 *
 * @param count Количество векторов.
 * @param min_size Минимальный размер каждого вектора.
 * @return Набор введённых векторов.
 */
std::vector<std::vector<int>> ReadVectorSet(int count, int min_size);

/**
 * @brief Проверяет, что слово непустое и состоит только из латинских букв.
 *
 * @param word Проверяемое слово.
 * @return true, если слово подходит.
 */
bool IsEnglishWord(const std::string& word);

/**
 * @brief Запрашивает положительное количество слов и сами слова.
 *
 * Каждое слово должно состоять только из латинских букв.
 *
 * @return Введённые слова в списке.
 */
std::list<std::string> ReadWords();

/**
 * @brief Выводит элементы контейнера через пробел и переводит строку.
 *
 * Подходит для vector, deque, list, set, multiset и т. д., но не для map
 * и multimap (их элементы являются парами).
 *
 * @tparam Container Тип контейнера.
 * @param container Выводимый контейнер.
 * @pre Тип элементов поддерживает вывод через operator<<.
 */
template <typename Container>
void PrintContainer(const Container& container) {
	for (typename Container::const_iterator it = container.begin();
			 it != container.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << "\n";
}

/**
 * @brief Выводит мультиотображение: в каждой строке ключ, затем значение.
 *
 * @param groups Выводимое мультиотображение.
 */
void PrintMultimap(const std::multimap<int, int>& groups);
/** @} */

/**
 * @name Работа с файлами
 * @{
 */

/**
 * @brief Запрашивает имя файла, количество чисел и сами числа, записывает
 * их в файл через пробел.
 *
 * @return Имя файла, при ошибке создания пустая строка.
 */
std::string CreateNumbersFile();
/** @} */

/**
 * @name Выполнение заданий
 * @brief Функции пунктов меню: запрашивают данные, вызывают функцию
 * задания и выводят результат.
 * @{
 */
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
/** @} */

#endif  // LAB2_METHODS_H_
