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
		void setAddT(string FileName);
		friend istream& operator>>(istream &fin, Task &t) {
			cout << "Введите трудоемкость задачи:" << endl;
			fin >> t.laboriousness;
			cout << "Введите срок выполнения задачи:" << endl;
			fin >> t.deadline;
			t.active = false;
			t.empolyee_id = 0;
			t.completness = 0;
			//cout << "Введите название задачи:" << endl;
			//fin >> t.name;
			//cout<<t.name;
			//cout << "Опишите задачу:" << endl;
			//fin >> t.description;
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
		void setAddE(string FileName);
		friend istream& operator>>(istream &fin, Employees &e){
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


