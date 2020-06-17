#include <iostream>
#include <fstream>
#include <string>
#include "employees.hpp"
using namespace std;

Employees::Employees(){
  name = {};
  surname = {};
  middlename = {};
  id = 0;
  time = 0;
  tasks = 0;
}

int Employees::setSize(fstream& FileE){
  int size = 0;
  while(!FileE.eof()) {
    FileE >> name;
    FileE >> surname;
    FileE >> middlename;
    FileE >> id;
    FileE >> time;
    FileE >> tasks;
    size++;
  }
  return size;
}

void Employees::setE(string databaseE) {
	fstream FileE;
	FileE.open(databaseE, ios::app | ios::in);
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Employees* countE = new Employees;
	int size = countE->setSize(FileE);
	delete countE;
  Employees* e = new Employees[size];
	FileE.clear();
	FileE.seekg(0);
	for (int i = 0; i < size-1; i++) {
		e[i].name = e->getName(FileE);
		e[i].surname = e->getSurname(FileE);
		e[i].middlename = e->getMiddName(FileE);
		e[i].id = e->getId(FileE);
		e[i].time = e->getTime(FileE);
		e[i].tasks = e->getTasks(FileE);
	}
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e[size-1].surname;
	cout << "Введите имя сотрудника:" << endl;
	cin >> e[size-1].name;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e[size-1].middlename;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e[size-1].time;
	if (size == 0){
		FileE << e[size-1].name << endl;
		FileE << e[size-1].surname << endl;
		FileE << e[size-1].middlename << endl;
		FileE << '1' << endl;
		FileE << e[size-1].time << endl;
		FileE << '0' << endl;
	}
	else {
		e[size-1].id++;
		FileE << e[size-1].name << endl;
		FileE << e[size-1].surname << endl;
		FileE << e[size-1].middlename << endl;
		FileE << e[size-1].id << endl;
		FileE << e[size-1].time << endl;
		FileE << '0' << endl;
	}
	delete[] e;
  FileE.close();
}
