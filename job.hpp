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
			getline(FileT, name,'\n');
		}
		string getName(fstream& FileT) {
			setName(FileT);
			return name;
		}
		void setDescr(fstream& FileT) {
			getline(FileT, description,'\n');
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
				FileT.ignore(32767,'\n');
				getline(FileT,name,'\n');
				getline(FileT,description,'\n');
				size++;
			}
			return size;
		}
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
				FileE >> tasks;
				size++;
			}
			return size;
		}
		void setE(string databaseE);
};
void Read_f(string databaseT, string databaseE, int Menu);
