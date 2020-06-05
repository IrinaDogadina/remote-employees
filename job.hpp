#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Task {
	private:
		int laboriousness; //трудоемкость
		int deadline; //дедлаин
		int employee_id; //айди сотрудника который выполняет
		int completness; //степень готовности
		string name; //краткое название
		string description; //описание задачи
	public:
		void setT(string databaseT);
		void setLab(fstream& FileT) {
			FileT >> laboriousness;
		}
		int getLab(fstream& FileT) {
			setLab(FileT);
			return laboriousness;
		}
		void setDeadl(fstream& FileT) {
			FileT >> deadline;
		}
		int getDeadl(fstream& FileT) {
			setDeadl(FileT);
			return deadline;
		}
		void setEmpId(fstream& FileT) {
			FileT >> employee_id;
		}
		int getEmpId(fstream& FileT) {
			setEmpId(FileT);
			return employee_id;
		}
		void setCompl(fstream& FileT) {
			FileT >> completness;
		}
		int getCompl(fstream& FileT) {
			setCompl(FileT);
			return completness;
		}
		void setName(fstream& FileT) {
			getline(FileT, name);
		}
		string getName(fstream& FileT) {
			setName(FileT);
			return name;
		}
		void setDescr(fstream& FileT) {
			getline(FileT, description);
		}
		string getDescr(fstream& FileT) {
			setDescr(FileT);
			return description;
		}
		int setSize(fstream& FileT){
			int size = 0;
			while(!FileT.eof()) {
				FileT >> laboriousness;
				FileT >> deadline;
				FileT >> employee_id;
				FileT >> completness;
				//FileT >> name;
				//FileT >> description;
				size++;
			}
			return size;
		}
/*		friend istream& operator>> (istream &fin, Task &t) {
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
			fin >> t.description;
			return fin;
		}*/
};

class Employees {
	private:
		string name; //имя
  	string surname; //фамилия
  	string middlename; //отчество
  	int id; //айди
  	int time; //время
		int tasks; //колво задач на сотрдунике
	public:
		void setName(fstream& FileE) {
			FileE >> name;
		}
		string getName(fstream& FileE) {
			setName(FileE);
			return name;
		}
		void setSurname(fstream& FileE) {
			FileE >> surname;
		}
		string getSurname(fstream& FileE) {
			setSurname(FileE);
			return surname;
		}
		void setMiddName(fstream& FileE) {
			FileE >> middlename;
		}
		string getMiddName(fstream& FileE) {
			setMiddName(FileE);
			return middlename;
		}
		void setId(fstream& FileE) {
			FileE >> id;
		}
		int getId(fstream& FileE) {
			setId(FileE);
			return id;
		}
		void setTime(fstream& FileE) {
			FileE >> time;
		}
		int getTime(fstream& FileE) {
			setTime(FileE);
			return time;
		}
		void setTasks(fstream& FileE) {
			FileE >> tasks;
		}
		int getTasks(fstream& FileE) {
			setTasks(FileE);
			return tasks;
		}
		int setSize(fstream& FileE){
			int size = 0;
			while(!FileE.eof()) {
				FileE >> name;
				FileE >> surname;
				FileE >> middlename;
				FileE >> id;
				FileE >> time;
				size++;
			}
			return size;
		}
		void setE(string databaseE);
/*		friend istream& operator>> (istream &fin, Employees &e){
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
		}*/
};
