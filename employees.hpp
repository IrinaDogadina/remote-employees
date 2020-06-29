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
<<<<<<< HEAD
        name = param;
=======
								name = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getName - метод возвращающий переменную имени сотрудника
   @return name - переменная имени сотрудника
 */
string getName() {
<<<<<<< HEAD
        return name;
=======
								return name;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setSurname - метод присваивающий переменной фамилии сотрудника переданное значение
   @param param - строковая передаваемая переменная
 */
void setSurname(string param) {
<<<<<<< HEAD
        surname = param;
=======
								surname = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getSurname - метод возвращающий переменную фамилии сотрудника
   @return surname - переменная фамилии сотрудника
 */
string getSurname() {
<<<<<<< HEAD
        return surname;
=======
								return surname;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setMiddName - метод присваивающий переменной отчества сотрудника переданное значение
   @param param - строковая передаваемая переменная
 */
void setMiddName(string param) {
<<<<<<< HEAD
        middlename = param;
=======
								middlename = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getMiddName - метод возвращающий переменную отчества сотрудника
   @return middlename - переменная отчества сотрудника
 */
string getMiddName() {
<<<<<<< HEAD
        return middlename;
=======
								return middlename;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setId - метод присваивающий переменной ID сотрудника переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setId(int param) {
<<<<<<< HEAD
        id = param;
=======
								id = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getId - метод возвращающий переменную ID сотрудника
   @return id - переменная ID сотрудника
 */
int getId() {
<<<<<<< HEAD
        return id;
=======
								return id;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setTime - метод присваивающий переменной рабочего времени сотрудника переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setTime(int param) {
<<<<<<< HEAD
        time = param;
=======
								time = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getTime - метод возвращающий переменную рабочего времени сотрудника
   @return time - переменная рабочего времени сотрудника
 */
int getTime() {
<<<<<<< HEAD
        return time;
=======
								return time;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setTasks - метод присваивающий переменной количества задач на сотруднике переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setTasks(int param) {
<<<<<<< HEAD
        tasks = param;
=======
								tasks = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getTasks - метод возвращающий переменную количества задач на сотруднике
   @return tasks - переменная количества задач на сотруднике
 */
int getTasks() {
<<<<<<< HEAD
        return tasks;
=======
								return tasks;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setSize - метод возвращающий количество классов сотрудников в файле
   @param FileE - поток файла задач
   @return size - переменная количества классов в файле
 */
int setSize(fstream& FileE);
};
