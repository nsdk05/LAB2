#include <iostream>

#include "Methods.h"

// Выбор задания
void Menu() {
	while (true) {
		std::cout << "\nВыберите Задание \n";
		std::cout << "Задание 1: Заполнить вектор числами из файла \n";
		std::cout << "Задание 2: Вставить -1 перед первой половиной дека \n";
		std::cout << "Задание 3: Перенести половину списка L2 в начало L1 \n";
		std::cout << "Задание 4: Записать в файл N прописных латинских букв \n";
		std::cout << "Задание 5: Удалить первый и последний нулевой элемент \n";
		std::cout << "Задание 6: Заполнить дек числами 1..N и N..1 \n";
		std::cout << "Задание 7: Отрицательные, нули, положительные \n";
		std::cout << "Задание 8: Дек строк по парам соседних слов \n";
		std::cout << "Задание 9: Векторы, содержащие все элементы V0 \n";
		std::cout << "Задание 10: Группировка элементов по последней цифре \n";
		std::cout << "Задание 0: Выход \n";
		int choise_task = ReadIntInRange("Ваш выбор :", 0, 10);

		switch (choise_task) {
			case 1: {
				Task1();
				break;
			}
			case 2: {
				Task2();
				break;
			}
			case 3: {
				Task3();
				break;
			}
			case 4: {
				Task4();
				break;
			}
			case 5: {
				Task5();
				break;
			}
			case 6: {
				Task6();
				break;
			}
			case 7: {
				Task7();
				break;
			}
			case 8: {
				Task8();
				break;
			}
			case 9: {
				Task9();
				break;
			}
			case 10: {
				Task10();
				break;
			}
			default: {
				return;
			}
		}
	}
}

int main() {
	Menu();
	return 0;
}
