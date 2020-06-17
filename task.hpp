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
		void setLab(int param) {
			laboriousness = param;
		}

		/*!
		@brief getLab - метод возвращающий переменную трудоемкости
		@return laboriousness - переменная трудоемкости
		*/
		int getLab() {
			return laboriousness;
		}

		/*!
		@brief setDeadl - метод считывающий из файла переменную срока задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setDeadl(int param) {
			deadline = param;
		}

		/*!
		@brief getDeadl - метод возвращающий переменную срока задачи
		@return deadline - переменная срока задачи
		*/
		int getDeadl() {
			return deadline;
		}

		/*!
		@brief setEmpId - метод считывающий из файла переменную ID сотрудника, который выполняет задачу из файла в класс
		@param FileT - поток файла задач
		*/
		void setEmpId(int param) {
			employee_id = param;
		}

		/*!
		@brief getEmpId - метод возвращающий переменную ID сотрудника, который выполняет задачу
		@return employee_id - переменная ID сотрудника, который выполняет задачу
		*/
		int getEmpId() {
			return employee_id;
		}

		/*!
		@brief setCompl - метод считывающий из файла переменную степени готовности задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setCompl(int param) {
			completness = param;
		}

		/*!
		@brief getCompl - метод возвращающий переменную степени готовности задачи
		@return completness - переменная степени готовности задачи
		*/
		int getCompl() {
			return completness;
		}

		/*!
		@brief setName - метод считывающий из файла переменную названия задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setName(string param) {
			name = param;
		}

		/*!
		@brief getName - метод возвращающий переменную названия задачи
		@return name - переменная названия задачи
		*/
		string getName() {
			return name;
		}

		/*!
		@brief setDescr - метод считывающий из файла переменную описания задачи из файла в класс
		@param FileT - поток файла задач
		*/
		void setDescr(string param) {
			description = param;
		}

		/*!
		@brief getDescr - метод возвращающий переменную описания задачи
		@return description - переменная описания задачи
		*/
		string getDescr() {
			return description;
		}

		/*!
		@brief setSize - метод возвращающий количество классов задач в файле
		@param FileT - поток файла задач
		@return size - переменная количества классов в файле
		*/
		int setSize(fstream& FileT);

};
