#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*!
@brief Класс с задачами фирмы. Содержит в себе переменные задач и методы.
*/

class Task {
	private:
		///целочисленная переменная трудоемкости задачи в часах
		int laboriousness;

		///целочисленная переменная срока задачи в часах
		int deadline;

		///целочисленная переменная ID сотрудника, который выполняет задачу
		int employee_id;

		///целочисленная переменная степени готовности задачи в процентах
		int completness;

		///строка с кратким названием задачи
		string name;

		///строка с описанием задачи
		string description;

	public:
		///@brief setT - метод добавляющий в класс задачу и записывающий класс в файл
		///@param databaseT - параметр с названием файла с задачами
		void setT(string databaseT);

		///@brief setLab - метод считывающий из файла переменную трудоемкости из файла в класс
		///@param FileT - поток файла задач
		void setLab(fstream& FileT) {
			FileT >> laboriousness;
		}

		///@brief getLab - метод возвращающий переменную трудоемкости
		///@param FileT - поток файла задач
		///@return laboriousness - переменная трудоемкости
		int getLab(fstream& FileT) {
			setLab(FileT);
			return laboriousness;
		}

		///@brief setDeadl - метод считывающий из файла переменную срока задачи из файла в класс
		///@param FileT - поток файла задач
		void setDeadl(fstream& FileT) {
			FileT >> deadline;
		}

		///@brief getDeadl - метод возвращающий переменную срока задачи
		///@param FileT - поток файла задач
		///@return deadline - переменная срока задачи
		int getDeadl(fstream& FileT) {
			setDeadl(FileT);
			return deadline;
		}

		///@brief setEmpId - метод считывающий из файла переменную ID сотрудника, который выполняет задачу из файла в класс
		///@param FileT - поток файла задач
		void setEmpId(fstream& FileT) {
			FileT >> employee_id;
		}

		///@brief getEmpId - метод возвращающий переменную ID сотрудника, который выполняет задачу
		///@param FileT - поток файла задач
		///@return employee_id - переменная ID сотрудника, который выполняет задачу
		int getEmpId(fstream& FileT) {
			setEmpId(FileT);
			return employee_id;
		}

		///@brief setCompl - метод считывающий из файла переменную степени готовности задачи из файла в класс
		///@param FileT - поток файла задач
		void setCompl(fstream& FileT) {
			FileT >> completness;
		}

		///@brief getCompl - метод возвращающий переменную степени готовности задачи
		///@param FileT - поток файла задач
		///@return completness - переменная степени готовности задачи
		int getCompl(fstream& FileT) {
			setCompl(FileT);
			return completness;
		}

		///@brief setName - метод считывающий из файла переменную названия задачи из файла в класс
		///@param FileT - поток файла задач
		void setName(fstream& FileT) {
			getline(FileT, name,'\n');
		}

		///@brief getName - метод возвращающий переменную названия задачи
		///@param FileT - поток файла задач
		///@return name - переменная названия задачи
		string getName(fstream& FileT) {
			setName(FileT);
			return name;
		}

		///@brief setDescr - метод считывающий из файла переменную описания задачи из файла в класс
		///@param FileT - поток файла задач
		void setDescr(fstream& FileT) {
			getline(FileT, description,'\n');
		}

		///@brief getDescr - метод возвращающий переменную описания задачи
		///@param FileT - поток файла задач
		///@return description - переменная описания задачи
		string getDescr(fstream& FileT) {
			setDescr(FileT);
			return description;
		}

		///@brief setSize - метод возвращающий количество классов задач в файле
		///@param FileT - поток файла задач
		///@return size - переменная количества классов в файле
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

/*!
@brief Класс с сотрудниками фирмы. Содержит в себе переменные сотрудника и методы.
*/

class Employees {
	private:
		///строка имени сотрудника
		string name;

		///строка фамилии сотрудника
		string surname;

		///строка отчества сотрудника
		string middlename;

		///целочисленная переменная ID сотрудника
		int id;

		///целочисленная переменная времени работы сотрудника в часах в неделю
		int time;

		///целочисленная переменная количества задач на сотруднике
		int tasks;

	public:

		///@brief setName - метод считывающий из файла переменную имени сотрудника из файла в класс
		///@param FileE - поток файла сотрудников
		void setName(fstream& FileE) {
			FileE >> name;
		}

		///@brief getName - метод возвращающий переменную имени сотрудника
		///@param FileE - поток файла сотрудников
		///@return description - переменная имени сотрудника
		string getName(fstream& FileE) {
			setName(FileE);
			return name;
		}

		///@brief setSurname - метод считывающий из файла переменную фамилии сотрудника из файла в класс
		///@param FileE - поток файла сотрудников
		void setSurname(fstream& FileE) {
			FileE >> surname;
		}

		///@brief getSurname - метод возвращающий переменную фамилии сотрудника
		///@param FileE - поток файла сотрудников
		///@return description - переменная фамилии сотрудника
		string getSurname(fstream& FileE) {
			setSurname(FileE);
			return surname;
		}

		///@brief setMiddName - метод считывающий из файла переменную отчества сотрудника из файла в класс
		///@param FileE - поток файла сотрудников
		void setMiddName(fstream& FileE) {
			FileE >> middlename;
		}

		///@brief getMiddName - метод возвращающий переменную отчества сотрудника
		///@param FileE - поток файла сотрудников
		///@return description - переменная отчества сотрудника
		string getMiddName(fstream& FileE) {
			setMiddName(FileE);
			return middlename;
		}

		///@brief setId - метод считывающий из файла переменную ID сотрудника из файла в класс
		///@param FileE - поток файла сотрудников
		void setId(fstream& FileE) {
			FileE >> id;
		}

		///@brief getId - метод возвращающий переменную ID сотрудника
		///@param FileE - поток файла сотрудников
		///@return description - переменная ID сотрудника
		int getId(fstream& FileE) {
			setId(FileE);
			return id;
		}

		///@brief setTime - метод считывающий из файла переменную рабочего времени сотрудника из файла в класс
		///@param FileE - поток файла сотрудников
		void setTime(fstream& FileE) {
			FileE >> time;
		}

		///@brief getTime - метод возвращающий переменную рабочего времени сотрудника
		///@param FileE - поток файла сотрудников
		///@return description - переменная рабочего времени сотрудника
		int getTime(fstream& FileE) {
			setTime(FileE);
			return time;
		}

		///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setTasks(fstream& FileE) {
			FileE >> tasks;
		}

		///@brief getTasks - метод возвращающий переменную количества задач на сотруднике
		///@param FileE - поток файла сотрудников
		///@return description - переменная количества задач на сотруднике
		int getTasks(fstream& FileE) {
			setTasks(FileE);
			return tasks;
		}

		///@brief setSize - метод возвращающий количество классов сотрудников в файле
		///@param FileE - поток файла задач
		///@return size - переменная количества классов в файле
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

		///@brief setE - метод добавляющий в класс сотрудника и записывающий класс в файл
		///@param databaseE - параметр с названием файла с сотрудниками
		void setE(string databaseE);
};
