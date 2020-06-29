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
   @brief setLab - метод присваивающий переменной трудоемкости переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setLab(int param) {
<<<<<<< HEAD
        laboriousness = param;
=======
								laboriousness = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getLab - метод возвращающий переменную трудоемкости
   @return laboriousness - переменная трудоемкости
 */
int getLab() {
<<<<<<< HEAD
        return laboriousness;
=======
								return laboriousness;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setDeadl - метод присваивающий переменной срока переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setDeadl(int param) {
<<<<<<< HEAD
        deadline = param;
=======
								deadline = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getDeadl - метод возвращающий переменную срока задачи
   @return deadline - переменная срока задачи
 */
int getDeadl() {
<<<<<<< HEAD
        return deadline;
=======
								return deadline;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setEmpId - метод присваивающий переменной ID сотрудника, выполняющего задачу переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setEmpId(int param) {
<<<<<<< HEAD
        employee_id = param;
=======
								employee_id = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getEmpId - метод возвращающий переменную ID сотрудника, который выполняет задачу
   @return employee_id - переменная ID сотрудника, который выполняет задачу
 */
int getEmpId() {
<<<<<<< HEAD
        return employee_id;
=======
								return employee_id;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setCompl - метод присваивающий переменной степени готовности переданное значение
   @param param - целочисленная передаваемая переменная
 */
void setCompl(int param) {
<<<<<<< HEAD
        completness = param;
=======
								completness = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getCompl - метод возвращающий переменную степени готовности задачи
   @return completness - переменная степени готовности задачи
 */
int getCompl() {
<<<<<<< HEAD
        return completness;
=======
								return completness;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setName - метод присваивающий переменной названия задачи переданное значение
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
   @brief getName - метод возвращающий переменную названия задачи
   @return name - переменная названия задачи
 */
string getName() {
<<<<<<< HEAD
        return name;
=======
								return name;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setDescr - метод присваивающий переменной описания задачи переданное значение
   @param param - строковая передаваемая переменная
 */
void setDescr(string param) {
<<<<<<< HEAD
        description = param;
=======
								description = param;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief getDescr - метод возвращающий переменную описания задачи
   @return description - переменная описания задачи
 */
string getDescr() {
<<<<<<< HEAD
        return description;
=======
								return description;
>>>>>>> 624e630676ad65d999c90a2ddb3c461356f97cc0
}

/*!
   @brief setSize - метод возвращающий количество классов задач в файле
   @param FileT - поток файла задач
   @return size - переменная количества классов в файле
 */
int setSize(fstream& FileT);

};
