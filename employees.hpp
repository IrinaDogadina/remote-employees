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
		int setSize(fstream& FileE);
};
