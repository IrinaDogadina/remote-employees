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
  //Employees* e;
	fstream FileE;
	FileE.open(databaseE, ios::app | ios::in);
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
  //использовать сетсайз для размера
  string str;
	int sizeE=0; int i=0;
	while(getline(FileE,str)){sizeE++;}
  sizeE=(sizeE)/6;
  cout<<sizeE;
  FileE.clear();
  FileE.seekg(0);
  Employees* e= new Employees[sizeE+1];
  //написать функцию ввода из файла
  for(i=0;i<sizeE;i++){
    FileE>>e[i].surname;
    FileE>>e[i].name;
    FileE>>e[i].middlename;
    FileE>>e[i].id;
    FileE>>e[i].time;
    FileE>>e[i].tasks;
  }

	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e[sizeE].surname;
	cout << "Введите имя сотрудника:" << endl;
	cin >> e[sizeE].name;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e[sizeE].middlename;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e[sizeE].time;
  FileE.close();
  fstream File2;
	File2.open(databaseE,  ios::out |ios::trunc);
  if (sizeE == 0){
    File2 << e[sizeE].name << endl;
		File2 << e[sizeE].surname << endl;
		File2 << e[sizeE].middlename << endl;
		File2 << '1' << endl;
		File2 << e[sizeE].time << endl;
		File2 << '0' << endl;
  }
  else {
    //File2 << sizeE;
    for (i=0; i < sizeE+1; i++){
  		File2 << e[i].name << endl;
  		File2 << e[i].surname << endl;
  		File2 << e[i].middlename << endl;
      if (i == sizeE){
        e[i].id = e[i-1].id++;
        File2 << e[i].id << endl;
      }
  		else {
        File2 << e[i].id << endl;
      }
  		File2 << e[i].time << endl;
  		File2 << '0' << endl;
    }
  }
  File2.close();
	delete[] e;
}
