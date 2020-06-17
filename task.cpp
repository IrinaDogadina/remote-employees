#include <iostream>
#include <fstream>
#include <string>
#include "task.hpp"
using namespace std;

Task::Task(){
  laboriousness = 0;
    deadline = 0;
    employee_id = 0;
    completness = 0;
    name = {};
    description = {};
}

int Task::setSize(fstream& FileT){
  int size = 0;
  while(!FileT.eof()) {
    FileT >> laboriousness;
    FileT >> deadline;
    FileT >> employee_id;
    FileT >> completness;
    FileT.ignore(32767,'\n');
    getline(FileT,name,'\n');
    getline(FileT,description,'\n');
    size++;
  }
  return size;
}

void Task::setT(string databaseT){
  Task t;
	fstream File;
	File.open(databaseT, ios::app | ios::in);
	if (!(File.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	cin.ignore(32767,'\n');
	cout << "Введите название задачи:" << endl;
	getline (cin, t.name);
	cout << "Опишите задачу:" << endl;
	getline (cin, t.description);
	cout << "Введите трудоемкость задачи:" << endl;
	cin >> t.laboriousness;
	cout << "Введите срок выполнения задачи:" << endl;
	cin >> t.deadline;
  File << t.laboriousness << endl;
  File << t.deadline << endl;
  File << '0' << endl;
  File << '0' << endl;
  File << t.name << endl;
  File << t.description << endl;
  File.close();
  //delete t;
}

void Task::viewT(string databaseT){
  fstream FileT;
  FileT.open(databaseT, ios::app | ios::in);
  if (!(FileT.is_open())){
    cout << "Ошибка открытия файла" << endl;
    exit(0);
  }
  //Task* t = new Task[sizeT];
  int i;
  //использовать сетсайз для размера
  string str;
	int sizeT=0;
	while(getline(FileT,str)){sizeT++;}
  sizeT=(sizeT)/5;
  Task* t = new Task[sizeT];
	FileT.clear();
	FileT.seekg(0);
  //написать функцию ввода из файла
  for(i=0;i<sizeT;i++){
    FileT>>t[i].laboriousness;
    FileT>>t[i].deadline;
    FileT>>t[i].employee_id;
    FileT>>t[i].completness;
    FileT>>t[i].name;
    FileT>>t[i].description;
  }
  cout << "Свободные задачи:" << endl;
  for (i = 0; i < sizeT; i++) {
      if (t[i].employee_id == 0) {
        cout << "Название задачи: " << t[i].name << endl;
        cout << "Описание задачи: " << t[i].description << endl;
        cout << endl << "Трудоемкость: " << t[i].laboriousness << " часов" << endl;
        cout << "Срок выполнения: " << t[i].deadline << " часов" << endl;
        cout << "Степень готовности: " << t[i].completness << "%" << endl;
        cout << "-----------" << endl;
      }
  }
  delete[] t;
}
