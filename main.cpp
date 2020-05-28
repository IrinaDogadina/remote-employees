#include <iostream>
#include <fstream>
#include "job.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "Неверное количество параметров" << endl;
		return 1;
	}
	string databaseT = argv[1];
	string databaseE = argv[2];
	int Menu = 0;
	for (;;) {
		cout << "1. Добавление" << endl;
		cout << "2. Просмотр" << endl;
		cout << "3. Вывод задач" << endl;
		cout << "4. Присвоить задачу" << endl;
		cout << "5. Удаление сотрудника" << endl;
		cout << "6. Выход" << endl;
		cin >> Menu;
		switch(Menu){
			case 1: {
				int MenuAdd = 0;
				cout << "1. Добавить работника" << endl;
				cout << "2. Добавить задачу" << endl;
				cout << "3. Вернуться" << endl;
				cin >> MenuAdd;
				switch(MenuAdd) {
					case 1: {
						Employees* e = new Employees;
						e->setE(databaseE);
						delete e;
						break;
					}
					case 2: {
						Task* t = new Task;
						t->setT(databaseT);
						delete t;
						break;
					}
					case 3:
						break;
					default: {
						cout << "Ошибка выбора меню" << endl;
						break;
					}
				}
			break;
			}
			case 2: {
	      int MenuView = 0;
	      cout << "1. Просмотр работников их их задачи" << endl;
				cout << "2. Просмотр свободынх задач" << endl;
				cout << "3. Вернуться" << endl;
	      cin >> MenuView;
	      switch(MenuView) {
	      	case 1:
						break;
	      	case 2:
						break;
					case 3:
						break;
					default: {
						cout << "Ошибка выбора меню" << endl;
						break;
					}
	    	break;
				}
			break;
			}
			case 3:
				break;
			case 4:
	//			assign(databaseT, databaseE);
				break;
			case 5:
	      break;
			case 6:
				return 0;
			default:
				cout << "Ошибка выбора меню" << endl;
				break;
		}
	}
}
