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
  Employees* e;
	fstream FileE;
	FileE.open(databaseE, ios::app | ios::in);
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
  //использовать сетсайз для размера
  //написать функцию ввода из файла
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e[size].setSurname;
	cout << "Введите имя сотрудника:" << endl;
	cin >> e[size].name;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e[size].middlename;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e[size].time;
  FileE.close();
  fstream File2;
	File2.open(databaseE, ios::app | ios::in | ios::trunc);
  if (size == 0){
    FileE << e[size].name << endl;
		FileE << e[size].surname << endl;
		FileE << e[size].middlename << endl;
		FileE << '1' << endl;
		FileE << e[size].time << endl;
		FileE << '0' << endl;
  }
  else {
    FileE << size;
    for (int i; i < size++; i++){
  		FileE << e[i].name << endl;
  		FileE << e[i].surname << endl;
  		FileE << e[i].middlename << endl;
      if (i == size){
        e[i].id = e[i-1].id++;
        FileE << e[i].id << endl;
      }
  		else {
        FileE << e[i].id << endl;
      }
  		FileE << e[i].time << endl;
  		FileE << '0' << endl;
    }
  }
	delete[] e;
  FileE.close();
}
