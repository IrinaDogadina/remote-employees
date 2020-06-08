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
	string str;
	Task t;
	fstream File;
	File.open(databaseT, ios::app | ios::in);
	if (!(File.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	getline(cin,str);
	cout << "Введите название задачи:" << endl;
	getline (cin, t.name);
	cout << "Опишите задачу:" << endl;
	getline (cin, t.description);
	cout << "Введите трудоемкость задачи:" << endl;
	cin >> t.laboriousness;
	cout << "Введите срок выполнения задачи:" << endl;
	cin >> t.deadline;

	t.employee_id = 0;
	t.completness = 0;


	File << t.laboriousness << endl;
	File << t.deadline << endl;
	File << t.employee_id << endl;
	File << t.completness << endl;
	File << t.name << endl;
	File << t.description << endl;
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
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e->surname;
	cout << "Введите имя сотрудника:" << endl;
	cin >> e->name;
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

void viewE(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& nameT, string*& description,int sizeE, string*& nameE, string*& surname, string*& middlename, int*& id, int*& time, int*& tasks)
{
	int i,j;
	for (i = 0; i < sizeE; i++) {
		cout << endl << nameE[i] << ' ' << surname[i] << ' ' << middlename[i] << ' ' << "ID: " << id[i] << " Часы работы в неделю: " << time[i] << endl;
		for (j = 0; j < sizeT; j++){
			if (employee_id[j] == id[i]) {
				cout << endl;
				cout << "Задача сотрудника:" << endl;
				cout << endl;
				cout << "Название задачи: "<< nameT[j]<< endl;
				cout << "Описание задачи: " << description[j] << endl;
				cout << "Трудоемкость: " << laboriousness[j] << " часов" << endl;
				cout << "Срок выполнения: " << deadline [j] << " часов" << endl;
				cout << "Степень готовности: " << completness[j] << "%" << endl;
			}
		}
	}
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memFreeE(sizeE, nameE, surname, middlename, id, time, tasks);
}

void viewT(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& nameT, string*& description){

	int i,j;
	cout << "Свободные задачи:" << endl;
	for (i = 0; i < sizeT; i++) {
			if (employee_id[i] == 0) {
				cout << "Название задачи: " << nameT[i] << endl;
				cout << "Описание задачи: " << description[i] << endl;
				cout << endl << "Трудоемкость: " << laboriousness[i] << " суток" << endl;
				cout << "Срок выполнения: " << deadline [i] << " суток" << endl;
				cout << "Степень готовности: " << completness[i] << "%" << endl;
				cout<<"-----------"<<endl;
			}
		}
	memFreeT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
}

void assign(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& nameT, string*& description,int sizeE, string*& nameE, string*& surname, string*& middlename, int*& id, int*& time, int*& tasks,string databaseE,string databaseT)
 {
	string temp; int temp_id;
	int i, j, k;

	for (i = 0; i < sizeT; i++) {
			if (employee_id[i] == 0) {
				cout << "Название задачи: " << nameT[i] << endl;
				cout << "Описание задачи: " << description[i] << endl;
				cout << endl << "Трудоемкость: " << laboriousness[i] << " часов" << endl;
				cout << "Срок выполнения: " << deadline [i] << " часов" << endl;
				cout << "Степень готовности: " << completness[i] << "%" << endl;
				cout<<"---------------"<<endl;
			}
		}
	cout << "Введите наименование задачи для присвоения сотруднику: " << endl;
	cin >> temp;
	for (i = 0; i < sizeT; i++) {
		if (temp==nameT[i] && employee_id[i] == 0){
			for (k = 0; k < sizeE; k++) {
				cout << endl <<"ID: " << id[k]<<' '<<  nameE[k] << ' ' << surname[k] << ' ' << middlename[k] << ' ' << " Часы работы в неделю: " << time[k] << endl;
				cout<<"---------------"<<endl;
			}
		}
	}
	cout << "Выберите задачу для присвоения сотруднику: " << endl;
	cin >> temp;
	for (i = 0; i < sizeT; i++) {
		if (temp==nameT[i] && employee_id[i] == 0){
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
	fstream FileTO;
	FileTO.open(databaseT, ios::trunc | ios::out);
	fstream FileT1;
	FileT1.open(databaseE, ios::trunc | ios::out);
	for (i = 0; i < sizeT; i++){
		FileTO << laboriousness[i] << endl;
		FileTO << deadline[i] << endl;
		FileTO << employee_id[i] << endl;
		FileTO << completness[i] << endl;
		FileTO << nameT[i] << endl;
		FileTO << description[i] << endl;
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

void Time_F(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& nameT, string*& description,int sizeE, string*& nameE, string*& surname, string*& middlename, int*& id, int*& time, int*& tasks,string databaseE,string databaseT){
	int week = 168;
	cout << "Прошла неделя" << endl;
	int i,j;
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


void Read_f(string databaseT, string databaseE, int Menu){
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
		nameT[i].assign(t->getName(FileT));
		description[i].assign(t->getDescr(FileT));
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
	if(Menu==4){assign(sizeT, laboriousness, deadline, employee_id, completness, nameT, description, sizeE, nameE, surname, middlename, id, time, tasks,databaseE,databaseT);}
	if(Menu==7){viewE(sizeT, laboriousness, deadline, employee_id, completness, nameT, description, sizeE, nameE, surname, middlename, id, time, tasks);}
	if(Menu==8){viewT(sizeT, laboriousness, deadline, employee_id, completness, nameT,description);}
	if(Menu==3){Time_F(sizeT, laboriousness, deadline, employee_id, completness, nameT, description, sizeE, nameE, surname, middlename, id, time, tasks,databaseE,databaseT);}
	FileE.close();
	FileT.close();
}
