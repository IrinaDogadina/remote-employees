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
    @param e - массив класса сотрудников
    @param t - массив класса задач
    @param sizeT - параметр с количеством классов в файле
    @param sizeE - параметр с количеством классов в файле
    */
    void getviewE(Employees*& e, Task*& t, int sizeT, int sizeE);

    /*!
    @brief assign - метод назначения задачи сотруднику. Выполняет проверку возможности сотрудника выполнить задачу
    @param e - массив класса сотрудников
    @param t - массив класса задач
    @param sizeT - параметр с количеством классов в файле
    @param sizeE - параметр с количеством классов в файле
    @param databaseT - параметр с названием файла с задачами
    @param databaseE - параметр с названием файла с сотрудниками
    */
    void getassign(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE);

    /*!
    @brief Time_F - метод пересчета степени готовности задач на сотрудниках спустя неделю
    @param e - массив класса сотрудников
    @param t - массив класса задач
    @param sizeT - параметр с количеством классов в файле
    @param sizeE - параметр с количеством классов в файле
    @param databaseT - параметр с названием файла с задачами
    @param databaseE - параметр с названием файла с сотрудниками
    */
    void getTime_F(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE);

    /*!
    @brief Delete_E - метод удаления определенного сотрудника из файла с сотрудниками
    @param e - массив класса сотрудников
    @param t - массив класса задач
    @param sizeT - параметр с количеством классов в файле
    @param sizeE - параметр с количеством классов в файле
    @param databaseT - параметр с названием файла с задачами
    @param databaseE - параметр с названием файла с сотрудниками
    */
    void getDelete_E(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE);

    /*!
    @brief Read_f - метод предварительных операций: открывает файлы, читает данные из них в классы, вызывает дальнейшую функцию
    @param databaseE - параметр с названием файла с сотрудниками
    @param databaseT - параметр с названием файла с задачами
    @param Menu - целочисленная переменная выбора меню для вызова дальнейшей функции
    @param databaseT - параметр с названием файла с задачами
    @param databaseE - параметр с названием файла с сотрудниками
    */
    void setRead_f(string databaseT, string databaseE, int Menu);
};
