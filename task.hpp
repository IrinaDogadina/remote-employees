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
		/*!
		@brief Конструктор класса, инициализирующий переменные
		*/
		Task();

		/*!
		@brief setT - метод добавляющий в класс задачу и записывающий класс в файл
		@param databaseT - параметр с названием файла с задачами
		*/
		void setT(string databaseT);

		/*!
		@brief viewT - метод вывода в консоль всех свободных задач
		@param databaseT - строка названия файла
		*/
		void viewT(string databaseT);

		/*!
		@brief setLab - метод считывающий из файла переменную трудоемкости из файла в класс
		@param FileT - поток файла задач
		*/
		void setLab(fstream& FileT) {
			FileT >> laboriousness;
		}

		/*!
		@brief getLab - метод возвращающий переменную трудоемкости
		@param FileT - поток файла задач
		@return laboriousness - переменная трудоемкости
		*/
		int getLab(fstream& FileT) {
			setLab(FileT);
			return laboriousness;
		}

		/*!
		@brief setDeadl - метод считывающий из файла переменную срока задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setDeadl(fstream& FileT) {
			FileT >> deadline;
		}

		/*!
		@brief getDeadl - метод возвращающий переменную срока задачи
		@param FileT - поток файла задач
		@return deadline - переменная срока задачи
		*/
		int getDeadl(fstream& FileT) {
			setDeadl(FileT);
			return deadline;
		}

		/*!
		@brief setEmpId - метод считывающий из файла переменную ID сотрудника, который выполняет задачу из файла в класс
		@param FileT - поток файла задач
		*/
		void setEmpId(fstream& FileT) {
			FileT >> employee_id;
		}

		/*!
		@brief getEmpId - метод возвращающий переменную ID сотрудника, который выполняет задачу
		@param FileT - поток файла задач
		@return employee_id - переменная ID сотрудника, который выполняет задачу
		*/
		int getEmpId(fstream& FileT) {
			setEmpId(FileT);
			return employee_id;
		}

		/*!
		@brief setCompl - метод считывающий из файла переменную степени готовности задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setCompl(fstream& FileT) {
			FileT >> completness;
		}

		/*!
		@brief getCompl - метод возвращающий переменную степени готовности задачи
		@param FileT - поток файла задач
		@return completness - переменная степени готовности задачи
		*/
		int getCompl(fstream& FileT) {
			setCompl(FileT);
			return completness;
		}

		/*!
		@brief setName - метод считывающий из файла переменную названия задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setName(fstream& FileT) {
			getline(FileT, name,'\n');
		}

		/*!
		@brief getName - метод возвращающий переменную названия задачи
		@param FileT - поток файла задач
		@return name - переменная названия задачи
		*/
		string getName(fstream& FileT) {
			setName(FileT);
			return name;
		}

		/*!
		@brief setDescr - метод считывающий из файла переменную описания задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setDescr(fstream& FileT) {
			getline(FileT, description,'\n');
		}

		/*!
		@brief getDescr - метод возвращающий переменную описания задачи
		@param FileT - поток файла задач
		@return description - переменная описания задачи
		*/
		string getDescr(fstream& FileT) {
			setDescr(FileT);
			return description;
		}

		/*!
		@brief setSize - метод возвращающий количество классов задач в файле
		@param FileT - поток файла задач
		@return size - переменная количества классов в файле
		*/
		int setSize(fstream& FileT);
};
