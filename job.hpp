#include <iostream>
#include <string>
using namespace std;

class Task {
	private:
		int laboriousness = 0; //трудоемкость
		int deadline = 0; //дедлаин
		bool active; //есть ли сотрудник который выполянет задачу
		int empolyee_id; //айди сотрудника который выполняет
		int completness; //степень готовности
		string name; //краткое название
		string description; //описание задачи
	public:
		void addT();
		friend ifstream& operator>>(ifstream &fin, Task &t) {
			cout << "Введите трудоемкость задачи:" << endl;
			fin >> laibourness;
			cout << "Введите срок выполнения задачи:" << endl;
			fin >> deadline;
			active = false;
			employee_id = 0;
			completness = 0;
			cout << "Введите название задачи:" << endl;
			fin >> name;
			cout << "Опишите задачу:" << endl;
			fin >> description;
			return fin;
		}
};

class Employees {
	private:
		string name; //имя
  	string surname; //фамилия
  	string middlename; //отчество
  	int id; //айди
  	int time; //время
	public:
		void addE();
		friend ifstream& operator>>(ifstream &fin, Employees &E){
			cout << "Введите имя сотрудника:" << endl;
			fin >> name;
			cout << "Введите фамилию сотрудника:" << endl;
			fin >> surname;
			cout << "Введите отчество сотрудника:" << endl;
			fin >> middlename;
			cout << "Введите id сотрудника:" << endl;
			fin >> id;
			cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
			fin >> time;
		}
};
