#include "job.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Task::setT(string databaseT) {
	Task t;
	ofstream File(databaseT, ios::app);
	cin >> t;
	File << t.laboriousness << t.deadline << t.active << t.employee_id << t.completness << t.name << t.description << endl;
	File.close();
}

void Employees::setE(string databaseE) {
	Employees e;
  ofstream File(databaseE, ios::app);
  cin >> e;
  File << e.name << e.surname << e.middlename << e.id << e.time << endl;
  File.close();
}

/*void assign(string databaseT, string databaseE) {
	fstream fileT(databaseT, ios::app | ios::in);
	fstream fileE(databaseE, ios::app | ios::in);
	Task *t = new Task;
	Task::readT(databaseT);
	я хз чесн че тут дальше писать, нужно чтобы в эту функцию передался и массив класса с сотрудниками и массив класса с задачами
}

*я хз какой типа данных передавать* Task::readT(string databaseT){
	Task count;
	while (databaseT >> count){
		size++;
	}
	delete count;
	Task *t = new Task[size];
	int i;
	for (i = 0; i < size; i++){
		file >> t[size];
	}
	return хз???;
}
чисто теоретически можно спросить у аллы, есть ли вообще возможность сделать такую функцию, которая бы имела доступ к обоим классам*/
