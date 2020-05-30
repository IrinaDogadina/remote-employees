#include "job.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Task::setT(string databaseT) {
	Task t;
	ofstream File(databaseT, ios::app);
	cout << "Введите трудоемкость задачи:" << endl;
	cin >> t.laboriousness;
	cout << "Введите срок выполнения задачи:" << endl;
	cin >> t.deadline;
	t.active = false;
	t.employee_id = 0;
	t.completness = 0;
	cout << "Введите название задачи:" << endl;
	getline (cin, t.name);
	cout << "Опишите задачу:" << endl;
	getline (cin, t.description);
	File << t.laboriousness << endl;
	File << t.deadline << endl;
	File << t.active << endl;
	File << t.employee_id << endl;
	File << t.completness << endl;
	File << t.name << endl;
	File << t.description << endl;
	File.close();
}

void Employees::setE(string databaseE) {
	Employees e;
  ofstream File(databaseE, ios::app);
	cout << "Введите имя сотрудника:" << endl;
	cin >> e.name;
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e.surname;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e.middlename;
	cout << "Введите id сотрудника:" << endl;
	cin >> e.id;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e.time;
  File << e.name << endl;
	File << e.surname << endl;
	File << e.middlename << endl;
	File << e.id << endl;
	File << e.time << endl;
  File.close();
}

void memAllocT(int sizeT, int *laboriousness, int *deadline, bool *active, int *employee_id, int *completness, string *name, string *description){
	laboriousness = new int[sizeT];
	deadline = new int[sizeT];
	active = new bool[sizeT];
	employee_id = new int[sizeT];
	completness = new int[sizeT];
	name = new string[sizeT];
	description = new string[sizeT];
}
void memAllocE(int sizeE, string *name, string *surname, string *middlename, int *id, int *time) {
	name = new string[sizeE];
	surname = new string[sizeE];
	middlename = new string[sizeE];
	id = new int[sizeE];
	time = new int[sizeE];
}
void memFreeT(int sizeT, int *laboriousness, int *deadline, bool *active, int *employee_id, int *completness, string *name, string *description) {
	delete[] laboriousness;
	delete[] deadline;
	delete[] active;
	delete[] employee_id;
	delete[] completness;
	delete[] name;
	delete[] description;
}
void memFreeE(int sizeE, string *name, string *surname, string *middlename, int *id, int *time) {
	delete[] name;
	delete[] surname;
	delete[] middlename;
	delete[] id;
	delete[] time;
}

void viewE(string databaseE, string databaseT) {
	fstream FileT;
	FileT.open(databaseT, ios::app | ios::in);
	fstream FileE;
	FileE.open(databaseT, ios::app | ios::in);
	Task* countT = new Task;
	Employees* countE = new Employees;
	int sizeT = countT->setSize(FileT);
	int sizeE = countE->setSize(FileE);
	cout << sizeT << ' ' << sizeE << endl;
	int i, j, *laboriousness, *deadline, *employee_id, *completness, *id, *time;
	bool *active;
	string *nameT, *description, *nameE, *surname, *middlename;
	memAllocT(sizeT, laboriousness, deadline, active, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time);
	FileT.clear();
	FileT.seekg(0);
	FileE.clear();
	FileE.seekg(0);
	for (i = 0; i < sizeT; i++) {
		Task* t = new Task;
		laboriousness[i] = t->getLab(FileT);
		deadline[i] = t->getDeadl(FileT);
		active[i] = t->getActive(FileT);
		employee_id[i] = t->getEmpId(FileT);
		completness[i] = t->getCompl(FileT);
		nameT[i].assign(t->getName(FileT));
		description[i].assign(t->getDescr(FileT));
		delete t;
	}
	for (i = 0; i < sizeE; i++) {
		Employees* e = new Employees;
		nameE[i].assign(e->getName(FileE));
		cout << nameE;
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		delete e;
	}
	for (i = 0; i < sizeE; i++) {
		cout << "какашка" << endl;
		cout << nameE[i] << ' ' << surname[i] << ' ' << middlename[i] << ' ' << "ID: " << id[i] << " Доступные часы работы: " << time[i] << endl;
		for (j = 0; j < sizeT; j++){
			if (employee_id[j] = id[i]) {
				cout << "Задача сотрудника:" << endl;
				cout << "Трудоемкость: " << laboriousness[j] << " суток" << endl;
				cout << "Срок выполнения: " << deadline [j] << " суток" << endl;
				cout << "Степень готовности: " << completness[j] << "%" << endl;
				cout << "Название задачи: " << nameT[j] << endl;
				cout << "Описание задачи: " << description[j] << endl;
			}
		}
	}
	memFreeT(sizeT, laboriousness, deadline, active, employee_id, completness, nameT, description);
	memFreeE(sizeE, nameE, surname, middlename, id, time);
}
