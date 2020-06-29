#include <iostream>
#include <fstream>
#include <string>
#include "task.hpp"
#include "employees.hpp"
using namespace std;

/*!
   @brief Класс с методами программы.
 */

class Interface {
private:
///массив класса сотрудников
Employees *e;

///массив класса задач
Task *t;

public:
/*!
   @brief viewE - метод вывода в консоль всех сотрудников и задач, которые они выполняют
   @param sizeT - параметр с количеством классов в файле
   @param sizeE - параметр с количеством классов в файле
 */
void viewE(int sizeT, int sizeE);

/*!
   @brief assign - метод назначения задачи сотруднику. Выполняет проверку возможности сотрудника выполнить задачу
   @param sizeT - параметр с количеством классов в файле
   @param sizeE - параметр с количеством классов в файле
   @param databaseT - параметр с названием файла с задачами
   @param databaseE - параметр с названием файла с сотрудниками
 */
void assign(int sizeT, int sizeE, string databaseT, string databaseE);

/*!
   @brief Time_F - метод пересчета степени готовности задач на сотрудниках спустя неделю
   @param sizeT - параметр с количеством классов в файле
   @param sizeE - параметр с количеством классов в файле
   @param databaseT - параметр с названием файла с задачами
   @param databaseE - параметр с названием файла с сотрудниками
 */
void Time_F(int sizeT, int sizeE, string databaseT, string databaseE);

/*!
   @brief Delete_E - метод удаления определенного сотрудника из файла с сотрудниками
   @param sizeT - параметр с количеством классов в файле
   @param sizeE - параметр с количеством классов в файле
   @param databaseT - параметр с названием файла с задачами
   @param databaseE - параметр с названием файла с сотрудниками
 */
void Delete_E(int sizeT, int sizeE, string databaseT, string databaseE);

/*!
   @brief Read_f - метод предварительных операций: открывает файлы, читает данные из них в классы, вызывает дальнейшую функцию
   @param databaseE - параметр с названием файла с сотрудниками
   @param databaseT - параметр с названием файла с задачами
   @param Menu - целочисленная переменная выбора меню для вызова дальнейшей функции
 */
void Read_f(string databaseT, string databaseE, int Menu);
};
