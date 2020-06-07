#include "job.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void memAllocT(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& name, string*& description){
	laboriousness = new int[sizeT];
	deadline = new int[sizeT];
	employee_id = new int[sizeT];
	completness = new int[sizeT];
	name = new string[sizeT];
	description = new string[sizeT];
}
void memAllocE(int sizeE, string*& name, string*& surname, string*& middlename, int*& id, int*& time, int*& tasks) {
	name = new string[sizeE];
	surname = new string[sizeE];
	middlename = new string[sizeE];
	id = new int[sizeE];
	time = new int[sizeE];
	tasks = new int[sizeE];
}
void memFreeT(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& name, string*& description) {
	delete[] laboriousness;
	delete[] deadline;
	delete[] employee_id;
	delete[] completness;
	delete[] name;
	delete[] description;
}
void memFreeE(int sizeE, string*& name, string*& surname, string*& middlename, int*& id, int*& time, int*& tasks) {
	delete[] name;
	delete[] surname;
	delete[] middlename;
	delete[] id;
	delete[] time;
	delete[] tasks;
}

void Task::setT(string databaseT) {
	Task t;
	fstream File;
	File.open(databaseT, ios::app | ios::in);
	if (!(File.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	cout << "Введите трудоемкость задачи:" << endl;
	cin >> t.laboriousness;
	cout << "Введите срок выполнения задачи:" << endl;
	cin >> t.deadline;
	t.employee_id = 0;
	t.completness = 0;
	//cout << "Введите название задачи:" << endl;
	//getline (cin, t.name);
	//cout << "Опишите задачу:" << endl;
	//getline (cin, t.description);
	File << t.laboriousness << endl;
	File << t.deadline << endl;
	File << t.employee_id << endl;
	File << t.completness << endl;
	//File << t.name << endl;
	//File << t.description << endl;
	File.close();
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
	int i, *id = 0, *time = 0, *tasks = 0;
	string *nameE = {}, *surname = {}, *middlename = {};
	memAllocE(size, nameE, surname, middlename, id, time, tasks);
	size--;
	FileE.clear();
	FileE.seekg(0);
	Employees* e = new Employees;
	for (i = 0; i < size; i++) {
		nameE[i].assign(e->getName(FileE));
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		tasks[i] = e->getTasks(FileE);
	}
	cout << "Введите имя сотрудника:" << endl;
	cin >> e->name;
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e->surname;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e->middlename;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e->time;
	if (size == 0){
		FileE << e->name << endl;
		FileE << e->surname << endl;
		FileE << e->middlename << endl;
		FileE << '1' << endl;
		FileE << e->time << endl;
		FileE << '0' << endl;
	}
	else {
		id[size-1]++;
		e->id = id[size-1];
		FileE << e->name << endl;
		FileE << e->surname << endl;
		FileE << e->middlename << endl;
		FileE << e->id << endl;
		FileE << e->time << endl;
		FileE << '0' << endl;
	}
	delete e;
  FileE.close();
	memFreeE(size, nameE, surname, middlename, id, time, tasks);
}

void viewE(string databaseE, string databaseT) {
	fstream FileE;
	FileE.open(databaseE, ios::in);
	fstream FileT;
	FileT.open(databaseT, ios::in | ios::app);
	if (!(FileT.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Task* countT = new Task;
	Employees* countE = new Employees;
	int sizeT = countT->setSize(FileT);
	int sizeE = countE->setSize(FileE);
	sizeT--;
	sizeE--;
	delete countT;
	delete countE;
	int i, j, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0, *tasks = 0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time, tasks);
	FileT.clear();
	FileT.seekg(0);
	FileE.clear();
	FileE.seekg(0);
	for (i = 0; i < sizeT; i++) {
		Task* t = new Task;
		laboriousness[i] = t->getLab(FileT);
		deadline[i] = t->getDeadl(FileT);
		employee_id[i] = t->getEmpId(FileT);
		completness[i] = t->getCompl(FileT);
		//nameT[i].assign(t->getName(FileT));
		//description[i].assign(t->getDescr(FileT));
		delete t;
	}
	for (i = 0; i < sizeE; i++) {
		Employees* e = new Employees;
		nameE[i].assign(e->getName(FileE));
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		tasks[i] = e->getTasks(FileE);
		delete e;
	}
	for (i = 0; i < sizeE; i++) {
		cout << endl << nameE[i] << ' ' << surname[i] << ' ' << middlename[i] << ' ' << "ID: " << id[i] << " Часы работы в неделю: " << time[i] << endl;
		for (j = 0; j < sizeT; j++){
			if (employee_id[j] == id[i]) {
				cout << endl;
				cout << "Задача сотрудника:" << endl;
				cout << endl;
				cout << "Трудоемкость: " << laboriousness[j] << " суток" << endl;
				cout << "Срок выполнения: " << deadline [j] << " суток" << endl;
				cout << "Степень готовности: " << completness[j] << "%" << endl;
				cout << "Название задачи: " /*<< nameT[j]*/ << endl;
				cout << "Описание задачи: " /*<< description[j]*/ << endl;
			}
		}
	}
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memFreeE(sizeE, nameE, surname, middlename, id, time, tasks);
	FileE.close();
	FileT.close();
}

void viewT(string databaseT){
	fstream FileT;
	FileT.open(databaseT, ios::in);
	if (!(FileT.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Task* countT = new Task;
	int sizeT = countT->setSize(FileT);
	sizeT--;
	delete countT;
	int i, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0;
	string *nameT = {}, *description = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	FileT.clear();
	FileT.seekg(0);
	for (i = 0; i < sizeT; i++) {
		Task* t = new Task;
		laboriousness[i] = t->getLab(FileT);
		deadline[i] = t->getDeadl(FileT);
		employee_id[i] = t->getEmpId(FileT);
		completness[i] = t->getCompl(FileT);
		//nameT[i].assign(t->getName(FileT));
		//description[i].assign(t->getDescr(FileT));
		delete t;
	}
	cout << "Свободные задачи:" << endl;
	for (i = 0; i < sizeT; i++) {
			if (employee_id[i] == 0) {
				cout << endl << "Трудоемкость: " << laboriousness[i] << " суток" << endl;
				cout << "Срок выполнения: " << deadline [i] << " суток" << endl;
				cout << "Степень готовности: " << completness[i] << "%" << endl;
				cout << "Название задачи: " /*<< nameT[j]*/ << endl;
				cout << "Описание задачи: " /*<< description[j]*/ << endl;
			}
		}
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	FileT.close();
}

void assign(string databaseT, string databaseE) {
	fstream FileT;
	FileT.open(databaseT, ios::app | ios::in);
	fstream FileE;
	FileE.open(databaseE, ios::app | ios::in);
	if (!(FileT.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Task* countT = new Task;
	Employees* countE = new Employees;
	int sizeT = countT->setSize(FileT);
	int sizeE = countE->setSize(FileE);
	sizeT--;
	sizeE--;
	delete countT;
	delete countE;
	int i, j, k, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0, *tasks=0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time, tasks);
	FileT.clear();
	FileT.seekg(0);
	FileE.clear();
	FileE.seekg(0);
	for (i = 0; i < sizeT; i++) {
		Task* t = new Task;
		laboriousness[i] = t->getLab(FileT);
		deadline[i] = t->getDeadl(FileT);
		employee_id[i] = t->getEmpId(FileT);
		completness[i] = t->getCompl(FileT);
		//nameT[i].assign(t->getName(FileT));
		//description[i].assign(t->getDescr(FileT));
		delete t;
	}
	for (i = 0; i < sizeE; i++) {
		Employees* e = new Employees;
		nameE[i].assign(e->getName(FileE));
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		tasks[i] = e->getTime(FileE);
		delete e;
	}
	int temp, temp_id;
	cout << "Выберите задачу для присвоения сотруднику: " << endl;
	cin >> temp;
	for (i = 0; i < sizeT; i++) {
		if (temp == deadline[i] && employee_id[i] == 0){
			cout << "Выберите id сотрудника: " << endl;
			cin >> temp_id;
			for (j = 0; j < sizeE; j++){
				if (temp_id == id[j]){
					int count = 0;
					int ddl = deadline[i];
					if (ddl > 168){
						while (ddl > 0){
							ddl = ddl-168;
							count++;
						}
					}
					else {
						count = 1;
					}
					if (ddl >= (laboriousness[i]-((time[j]*count)/(tasks[j]+1))) && ((laboriousness[i]-((time[j]*count)/(tasks[j]+1))) <= 0)){
						int a = 0;
						if (tasks[j] != 0){
							for (k = 0; k < sizeT; k++){
								if (employee_id[k] == temp_id) {
									count = 0;
									ddl = deadline[k];
									if (ddl > 168){
										while (ddl > 0) {
											ddl = ddl-168;
											count++;
										}
									}
									else {
										count = 1;
									}
								}
								if (ddl < (laboriousness[k]-((time[j]*count)/(tasks[j]+1))) && (laboriousness[k]-((time[j]*count)/(tasks[j]+1))) > 0){
									a++;
									cout << "Невозможно присвоить задачу, сотрудник не успеет выполнить другие свои задачи." << endl;
									break;
								}
							}
						}
						if (a == 0){
							employee_id[i] = temp_id;
							tasks[j]++;
						}
					}
					else {
						cout << "Невозможно присвоить задачу, сотрудник не успеет ее выполнить." << endl;
					}
				}
			}
		}
	}
	FileE.close();
	FileT.close();
	fstream FileTO;
	FileTO.open(databaseT, ios::trunc | ios::out);
	fstream FileT1;
	FileT1.open(databaseE, ios::trunc | ios::out);
	for (i = 0; i < sizeT; i++){
		FileTO << laboriousness[i] << endl;
		FileTO << deadline[i] << endl;
		FileTO << employee_id[i] << endl;
		FileTO << completness[i] << endl;
	}
	for (j = 0; j < sizeE; j++){
		FileT1 << nameE[j] << endl;
		FileT1 << surname[j] << endl;
		FileT1 << middlename[j] << endl;
		FileT1 << id[j] << endl;
		FileT1 << time[j] << endl;
		FileT1 << tasks[j] << endl;
	}
	FileTO.close();
	FileT1.close();
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memFreeE(sizeE, nameE, surname, middlename, id, time, tasks);
}

void Time_F(string databaseT, string databaseE){
	int week = 168;
	cout << "Прошла неделя" << endl;
	fstream FileT;
	FileT.open(databaseT, ios::app | ios::in);
	fstream FileE;
	FileE.open(databaseE, ios::app | ios::in);
	if (!(FileT.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Task* countT = new Task;
	Employees* countE = new Employees;
	int sizeT = countT->setSize(FileT);
	int sizeE = countE->setSize(FileE);
	sizeT--;
	sizeE--;
	delete countT;
	delete countE;
	int i, j, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0, *tasks = 0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time, tasks);
	FileT.clear();
	FileT.seekg(0);
	FileE.clear();
	FileE.seekg(0);
	for (i = 0; i < sizeT; i++) {
		Task* t = new Task;
		laboriousness[i] = t->getLab(FileT);
		deadline[i] = t->getDeadl(FileT);
		employee_id[i] = t->getEmpId(FileT);
		completness[i] = t->getCompl(FileT);
		//nameT[i].assign(t->getName(FileT));
		//description[i].assign(t->getDescr(FileT));
		delete t;
	}
	for (i = 0; i < sizeE; i++) {
		Employees* e = new Employees;
		nameE[i].assign(e->getName(FileE));
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		tasks[i] = e->getTasks(FileE);
		delete e;
	}
	for (i = 0; i < sizeE; i++){
		if (tasks[i] != 0){
			for (j = 0; j < sizeT; j++){
				 if (employee_id[j] != 0 && employee_id[j] == id[i] && completness[j] != 100 && laboriousness != 0){
					int count = laboriousness[j]-(time[i]/tasks[i]);
					completness[j] += (count*100)/laboriousness[j];
					laboriousness[j] = count;
					deadline[j] = deadline[j]-168;
					if (laboriousness[j] <= 0){
						laboriousness[j] = 0;
						completness[j] = 100;
						tasks[i]--;
					}
					if (deadline[j] < 0){
						deadline[j] = 0;
					}
				}
			}
		}
	}
	FileE.close();
	FileT.close();
	fstream FileT0;
	FileT0.open(databaseT, ios::trunc | ios::out);
	fstream FileT1;
	FileT1.open(databaseE, ios::trunc | ios::out);
	for (i = 0; i < sizeT; i++){
		FileT0 << laboriousness[i] << endl;
		FileT0 << deadline[i] << endl;
		FileT0 << employee_id[i] << endl;
		FileT0 << completness[i] << endl;
	}
	for (j = 0; j < sizeE; j++){
		FileT1 << nameE[j] << endl;
		FileT1 << surname[j] << endl;
		FileT1 << middlename[j] << endl;
		FileT1 << id[j] << endl;
		FileT1 << time[j] << endl;
		FileT1 << tasks[j] << endl;
	}
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memFreeE(sizeE, nameE, surname, middlename, id, time, tasks);
	FileT0.close();
	FileT1.close();
}
