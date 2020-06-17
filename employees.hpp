#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
    /*!
		@brief Конструктор класса, инициализирующий переменные
		*/
    Employees();

    ///@brief setE - метод добавляющий в класс сотрудника и записывающий класс в файл
		///@param databaseE - параметр с названием файла с сотрудниками
		void setE(string databaseE);

    ///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setName(string param) {
			name = param;
		}

    ///@brief getName - метод возвращающий переменную имени сотрудника
		///@return description - переменная имени сотрудника
    string getName() {
      return name;
		}

    ///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setSurname(string param) {
			surname = param;
		}

    ///@brief getSurname - метод возвращающий переменную фамилии сотрудника
		///@return description - переменная фамилии сотрудника
		string getSurname() {
      return surname;
		}

    ///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setMiddName(string param) {
			middlename = param;
		}

    ///@brief getMiddName - метод возвращающий переменную отчества сотрудника
		///@return description - переменная отчества сотрудника
		string getMiddName() {
      return middlename;
		}

    ///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setId(int param) {
			id = param;
		}

    ///@brief getId - метод возвращающий переменную ID сотрудника
		///@return description - переменная ID сотрудника
		int getId() {
      return id;
		}

    ///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setTime(int param) {
			time = param;
		}

    ///@brief getTime - метод возвращающий переменную рабочего времени сотрудника
		///@return description - переменная рабочего времени сотрудника
		int getTime() {
      return time;
		}

		///@brief setTasks - метод считывающий из файла переменную количества задач на сотруднике из файла в класс
		///@param FileE - поток файла сотрудников
		void setTasks(int param) {
			tasks = param;
		}

    ///@brief getTasks - метод возвращающий переменную количества задач на сотруднике
		///@return description - переменная количества задач на сотруднике
		int getTasks() {
      return tasks;
		}

		///@brief setSize - метод возвращающий количество классов сотрудников в файле
		///@param FileE - поток файла задач
		///@return size - переменная количества классов в файле
		int setSize(fstream& FileE);
};
