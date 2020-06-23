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

    /*!
		@brief setE - метод добавляющий в класс сотрудника и записывающий класс в файл
		@param databaseE - параметр с названием файла с сотрудниками
		*/
		void setE(string databaseE);

    /*!
		@brief setName - метод присваивающий переменной имени сотрудника переданное значение
		@param param - строковая передаваемая переменная
		*/
		void setName(string param) {
			name = param;
		}

    /*!
		@brief getName - метод возвращающий переменную имени сотрудника
		@return name - переменная имени сотрудника
		*/
		string getName() {
      return name;
		}

    /*!
		@brief setSurname - метод присваивающий переменной фамилии сотрудника переданное значение
		@param param - строковая передаваемая переменная
		*/
		void setSurname(string param) {
			surname = param;
		}

    /*!
		@brief getSurname - метод возвращающий переменную фамилии сотрудника
		@return surname - переменная фамилии сотрудника
		*/
		string getSurname() {
      return surname;
		}

    /*!
		@brief setMiddName - метод присваивающий переменной отчества сотрудника переданное значение
		@param param - строковая передаваемая переменная
		*/
		void setMiddName(string param) {
			middlename = param;
		}

    /*!
		@brief getMiddName - метод возвращающий переменную отчества сотрудника
		@return middlename - переменная отчества сотрудника
		*/
		string getMiddName() {
      return middlename;
		}

    /*!
		@brief setId - метод присваивающий переменной ID сотрудника переданное значение
		@param param - целочисленная передаваемая переменная
		*/
		void setId(int param) {
			id = param;
		}

    /*!
		@brief getId - метод возвращающий переменную ID сотрудника
		@return id - переменная ID сотрудника
		*/
		int getId() {
      return id;
		}

    /*!
		@brief setTime - метод присваивающий переменной рабочего времени сотрудника переданное значение
		@param param - целочисленная передаваемая переменная
		*/
		void setTime(int param) {
			time = param;
		}

    /*!
		@brief getTime - метод возвращающий переменную рабочего времени сотрудника
		@return time - переменная рабочего времени сотрудника
		*/
		int getTime() {
      return time;
		}

		/*!
		@brief setTasks - метод присваивающий переменной количества задач на сотруднике переданное значение
		@param param - целочисленная передаваемая переменная
		*/
		void setTasks(int param) {
			tasks = param;
		}

    /*!
		@brief getTasks - метод возвращающий переменную количества задач на сотруднике
		@return tasks - переменная количества задач на сотруднике
		*/
		int getTasks() {
      return tasks;
		}

		/*!
		@brief setSize - метод возвращающий количество классов сотрудников в файле
		@param FileE - поток файла задач
		@return size - переменная количества классов в файле
		*/
		int setSize(fstream& FileE);
};
