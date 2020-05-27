#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Task {
	private:
		int laboriousness = 0; //трудоемкость
		int deadline = 0; //дедлаин
		bool active; //есть ли сотрудник который выполянет задачу
		int employee_id; //айди сотрудника который выполняет
		int completness; //степень готовности
		string name; //краткое название
		string description; //описание задачи
	public:
		void setT(string databaseT);
		friend istream& operator>> (istream &fin, Task &t) {
			cout << "Введите трудоемкость задачи:" << endl;
			fin >> t.laboriousness;
			cout << "Введите срок выполнения задачи:" << endl;
			fin >> t.deadline;
			t.active = false;
			t.employee_id = 0;
			t.completness = 0;
			cout << "Введите название задачи:" << endl;
			fin >> t.name;
			cout << "Опишите задачу:" << endl;
			char mass[1000]; //здесь надо сделать так, чтобы можно было вводить
			fin >> mass[1000]; //строки с пробелами, и это все записывалось в стринг
			t.description = string(mass); //getline тут если что не работает...
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
		void setE(string databaseE);
		friend istream& operator>> (istream &fin, Employees &e){
			cout << "Введите имя сотрудника:" << endl;
			fin >> e.name;
			cout << "Введите фамилию сотрудника:" << endl;
			fin >> e.surname;
			cout << "Введите отчество сотрудника:" << endl;
			fin >> e.middlename;
			cout << "Введите id сотрудника:" << endl;
			fin >> e.id;
			cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
			fin >> e.time;
			return fin;
		}
};
