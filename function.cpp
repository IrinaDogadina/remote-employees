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
void memAllocE(int sizeE, string*& name, string*& surname, string*& middlename, int*& id, int*& time,int*& timeF) {
	name = new string[sizeE];
	surname = new string[sizeE];
	middlename = new string[sizeE];
	id = new int[sizeE];
	time = new int[sizeE];
	timeF = new int[sizeE];
}
void memFreeT(int sizeT, int*& laboriousness, int*& deadline, int*& employee_id, int*& completness, string*& name, string*& description) {
	delete[] laboriousness;
	delete[] deadline;
	delete[] employee_id;
	delete[] completness;
	delete[] name;
	delete[] description;
}
void memFreeE(int sizeE, string*& name, string*& surname, string*& middlename, int*& id, int*& time, int*& timeF) {
	delete[] name;
	delete[] surname;
	delete[] middlename;
	delete[] id;
	delete[] time;
	delete[] timeF;
}

void Task::setT(string databaseT) {
	Task t;
	fstream File;
	File.open(databaseT, ios::app);
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
	FileE.open(databaseE, ios:: app | ios::in);
	if (!(FileE.is_open())){
		cout << "Ошибка открытия файла" << endl;
		exit(0);
	}
	Employees* e = new Employees;
	Employees* countE = new Employees;
	int size = countE->setSize(FileE);
	delete countE;
	int i, *id = 0, *time = 0, *timeF=0;
	string *nameE = {}, *surname = {}, *middlename = {};
	memAllocE(size, nameE, surname, middlename, id, time, timeF);
	size--;
	FileE.clear();
	FileE.seekg(0);
	for (i = 0; i < size; i++) {
		nameE[i].assign(e->getName(FileE));
		surname[i].assign(e->getSurname(FileE));
		middlename[i].assign(e->getMiddName(FileE));
		id[i] = e->getId(FileE);
		time[i] = e->getTime(FileE);
		timeF[i]=e->getTimeF(FileE);
	}
	FileE.close();
	fstream FileE2;
	FileE2.open(databaseE, ios::app);
	cout << "Введите имя сотрудника:" << endl;
	cin >> e->name;
	cout << "Введите фамилию сотрудника:" << endl;
	cin >> e->surname;
	cout << "Введите отчество сотрудника:" << endl;
	cin >> e->middlename;
	cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
	cin >> e->time;
	if (size == 0){
		FileE2 << e->name << endl;
		FileE2 << e->surname << endl;
		FileE2 << e->middlename << endl;
		FileE2 << '1' << endl;
		FileE2 << e->time << endl;
		FileE2 << e->time << endl;
	}
	else {
		id[size-1]++;
		e->id = id[size-1];
		FileE2 << e->name << endl;
		FileE2 << e->surname << endl;
		FileE2 << e->middlename << endl;
		FileE2 << e->id << endl;
		FileE2 << e->time << endl;
		FileE2 << e->time << endl;
	}
	delete e;
  FileE2.close();
	memFreeE(size, nameE, surname, middlename, id, time, timeF);
}

void viewE(string databaseE, string databaseT) {
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
	int i, j, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0, *timeF=0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time, timeF);
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
		timeF[i]=e->getTimeF(FileE);
		delete e;
	}
	for (i = 0; i < sizeE; i++) {
		cout << endl << nameE[i] << ' ' << surname[i] << ' ' << middlename[i] << ' ' << "ID: " << id[i] << "Часы работы в неделю: " << time[i]<<"Доступные часы работы в неделю " <<  timeF[i] << endl;
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
	memFreeE(sizeE, nameE, surname, middlename, id, time,timeF);
	FileE.close();
	FileT.close();
}

void viewT(string databaseT){
	fstream FileT;
	FileT.open(databaseT, ios::app | ios::in);
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
	int i, j, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0, *timeF=0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time, timeF);
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
		timeF[i]=e->getTimeF(FileE);
		delete e;
	}
	int temp, temp_id;
	cout << "Выберите задачу для присвоения сотруднику: " << endl;
	cin >> temp;
	for(i=0;i<sizeT;i++)
	{
		if(temp==deadline[i]){
			cout << deadline[i]<< employee_id[i]<<endl;
			cout << "Выберите id сотрудника: " << endl;
			cin >> temp_id;
			for(int j=0;j<sizeE;j++){
				if(temp_id==id[j]){
					//добавить функцию расчета трудоемкости
					employee_id[i]=temp_id;
				}
			}
			cout << deadline[i]<< employee_id[i]<<endl;
		}
	}
	FileE.close();
	FileT.close();
	fstream FileTO;
	FileTO.open(databaseT, ios::trunc | ios::out);
	for(i=0;i<sizeT;i++){
		FileTO << laboriousness[i] <<endl;
		FileTO << deadline[i] << endl;
		FileTO << employee_id[i] << endl;
		FileTO << completness[i] << endl;
	}
	FileTO.close();
}

void Time_F(){
	int Time=0;//сюда забираем сутки которые прошли
	cout << "Введите количество прошедших суток" <<endl;
	cin >> Time;
	int count=0;//сюда считаем сколько уже прошло
	int week=0;//показатель пошедших дней для обнуления свободного времени
	fstream FileTime;
	FileTime.open("Time.txt",ios::in | ios::app);
  if(!FileTime.eof())
	{
		FileTime >> count;
		FileTime >> week;
	}
	else{
		FileTime << '0'<<endl;
		FileTime << '0'<<endl;
	}
	count+=Time;
	FileT.close();
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
	int i, j, *laboriousness = 0, *deadline = 0, *employee_id = 0, *completness = 0, *id = 0, *time = 0;
	string *nameT = {}, *description = {}, *nameE = {}, *surname = {}, *middlename = {};
	memAllocT(sizeT, laboriousness, deadline, employee_id, completness, nameT, description);
	memAllocE(sizeE, nameE, surname, middlename, id, time);
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
		delete e;
	}
	/*for(i=0;i<sizeE;i++){
		for(int j=0;j<sizeT;j++){
			if(employee_id[j]!=0 && employee_id[j]==id[i]){
				timeF[i]-=Time;
					cout << "" <<endl;

			}
		}
	}*/
}
