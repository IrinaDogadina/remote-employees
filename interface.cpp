#include "interface.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Interface::getviewE(Employees*& e, Task*& t, int sizeT, int sizeE){
	int i, j;
	for (i = 0; i < sizeE; i++) {
		cout << endl << e[i].name << ' ' << e[i].surname << ' ' << e[i].middlename << ' ' << "ID: " << e[i].id << " Часы работы в неделю: " << e[i].time << endl;
		for (j = 0; j < sizeT; j++){
			if (t[j].employee_id == e[i].id) {
				cout << endl;
				cout << "Задача сотрудника:" << endl;
				cout << endl;
				cout << "Название задачи: "<< t[j].name << endl;
				cout << "Описание задачи: " << t[j].description << endl;
				cout << "Трудоемкость: " << t[j].laboriousness << " часов" << endl;
				cout << "Срок выполнения: " << t[j].deadline << " часов" << endl;
				cout << "Степень готовности: " << t[j].completness << "%" << endl;
			}
		}
	}
	delete[] t;
	delete[] e;
}

void Interface::getassign(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE){
	string temp;
	int temp_id;
	int i, j, k;
	for (i = 0; i < sizeT; i++) {
			if (t[i].employee_id == 0) {
				cout << "Название задачи: " << t[i].name << endl;
				cout << "Описание задачи: " << t[i].description << endl;
				cout << endl << "Трудоемкость: " << t[i].laboriousness << " часов" << endl;
				cout << "Срок выполнения: " << t[i].deadline << " часов" << endl;
				cout << "Степень готовности: " << t[i].completness << "%" << endl;
				cout<<"---------------"<<endl;
			}
		}
	cin.ignore(32767,'\n');
	cout << "Введите наименование задачи для присвоения сотруднику: " << endl;
	getline(cin, temp);
	for (k = 0; k < sizeE; k++) {
		cout << endl << "ID: " << e[k].id << ' ' <<  e[k].nameE << ' ' << e[k].surname << ' ' << e[k].middlename << ' ' << " Часы работы в неделю: " << e[k]->time << endl;
		cout << "---------------" << endl;
	}
	for (i = 0; i < sizeT; i++) {
		if (temp == t[i].name && t[i].employee_id == 0){
			cout << "Выберите id сотрудника: " << endl;
			cin >> temp_id;
			for (j = 0; j < sizeE; j++){
				if (temp_id == e[j].id){
					/*!
					@brief проверка возможности выполнения задачи сотрудником
					@brief если срок и трудоемкость задачи превышает одну неделю,
					@brief то из обоих переменных вычитается количество недель, а также ведется счетчик недель
					*/
					int count = 0;
					int ddl = t[i].deadline;
					if (ddl > 168 && t[i].laboriousness > e[j].time){
						while (ddl > 0){
							ddl = ddl-168;
							count++;
						}
					}
					else {
						count = 1;
					}
					/*!
					@brief если срок задачи больше или равно, чем трудоемкость задачи после выполнения ее сотрудником спустя n количество недель
					@brief и если трудоемкость задачи после выполнения ее сотрудником спустя n количество недель меньше или равна нулю
					@brief то задача не назначается
					*/
					if (ddl >= (t[i].laboriousness-((e[j].time*count)/(e[j].tasks+1))) && ((t[i].laboriousness-((e[j].time*count)/(e[j].tasks+1))) <= 0)){
						int a = 0;
						/*!
						@brief если сотрудник успеет выполнить назначаемую задачу,
						@brief то проверяется возможность выполнения уже назначенных задач по той же схеме
						@brief если сотрудник не успеет выполнить уже назначенные задачи, то назначаемая задача не назначается
						*/
						if (e[j].tasks != 0){
							for (k = 0; k < sizeT; k++){
								if (t[k].employee_id == temp_id) {
									count = 0;
									ddl = t[k].deadline;
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
								if (ddl < (t[k].laboriousness-((e[j].time*count)/(e[j].tasks+1))) && ((t[k].laboriousness-((e[j].time*count)/(e[j].tasks+1)))) > 0){
									a++;
									cout << "Невозможно присвоить задачу, сотрудник не успеет выполнить другие свои задачи." << endl;
									break;
								}
							}
						}
						if (a == 0){
							t[i].employee_id = temp_id;
							e[j].tasks++;
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
		FileTO << t[i].laboriousness << endl;
		FileTO << t[i].deadline << endl;
		FileTO << t[i].employee_id << endl;
		FileTO << t[i].completness << endl;
		FileTO << t[i].name << endl;
		FileTO << t[i].description << endl;
	}
	for (j = 0; j < sizeE; j++){
		FileT1 << e[j].name << endl;
		FileT1 << e[j].surname << endl;
		FileT1 << e[j].middlename << endl;
		FileT1 << e[j].id << endl;
		FileT1 << e[j].time << endl;
		FileT1 << e[j].tasks << endl;
	}
	FileTO.close();
	FileT1.close();
	delete[] e;
	delete[] t;
}

void Interface::getTime_F(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE){
	cout << "Прошла неделя" << endl;
	int i, j;
	for (i = 0; i < sizeE; i++){
		if (e[i].tasks != 0){
			for (j = 0; j < sizeT; j++){
				/*!
				@brief перерасчет степени готовности, срока, трудоемкости задач спустя неделю
				@brief из трудоемкости вычитается рабочее время работника деленное на количество задач сотрудника
				@brief из срока вычитается неделя
				@brief степень готовности считается от вычтенной трудоемкости к первоначальной
				@brief при завершении задач задачам присваивается нулевой срок, трудоемкость, уменьшается количество задач на сотруднике
				*/
				 if (t[j].employee_id != 0 && t[j].employee_id == e[i].id && t[j].completness != 100 && t[j].laboriousness != 0){
					int count = t[j].laboriousness-((e[i].time)/(e[i].tasks));
					t[j].completness += (count*100)/t[j].laboriousness;
					t[j].laboriousness = count;
					t[j].deadline -= 168;
					if (t[j].laboriousness <= 0){
						t[j].laboriousness = 0;
						t[j].completness = 100;
						e[i].tasks--;
					}
					if (t[j].deadline < 0){
						t[j].deadline = 0;
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
		FileT0 << t[i].laboriousness << endl;
		FileT0 << t[i].deadline << endl;
		FileT0 << t[i].employee_id << endl;
		FileT0 << t[i].completness << endl;
		FileT0 << t[i].name << endl;
		FileT0 << t[i].description << endl;

	}
	for (j = 0; j < sizeE; j++){
		FileT1 << e[j].name << endl;
		FileT1 << e[j].surname << endl;
		FileT1 << e[j].middlename << endl;
		FileT1 << e[j].id << endl;
		FileT1 << e[j].time << endl;
		FileT1 << e[j].tasks << endl;
	}
	delete[] t;
	delete[] e;
	FileT0.close();
	FileT1.close();
}

void Interface::getDelete_E(Employees*& e, Task*& t, int sizeT, int sizeE, string databaseT, string databaseE) {
	string surname_del, name_del;
	cout << "Введите фамилию работника" << endl;
	cin >> surname_del;
	cout << "Введите имя работника" << endl;
	cin >> name_del;
	int i, j, id_del;
	for (i = 0; i < sizeE; i++) {
		if (surname_del == e[i].surname && name_del == e[i].name) {
			id_del = e[i].id;
			for (j = 0; j < sizeT; j++) {
				if (t[j].employee_id == id_del) {
					t[j].employee_id = 0;
				}
			}
		}
	}
	fstream FileTO;
	FileTO.open(databaseT, ios::trunc | ios::out);
	fstream FileT1;
	FileT1.open(databaseE, ios::trunc | ios::out);
	for (i = 0; i < sizeT; i++){
		if (t[i].completness != 100){
			FileTO << t[i].laboriousness << endl;
			FileTO << t[i].deadline << endl;
			FileTO << t[i].employee_id << endl;
			FileTO << t[i].completness << endl;
			FileTO << t[i].name << endl;
			FileTO << t[i].description << endl;
		}
	}
	for (j = 0; j < sizeE; j++){
		if (id_del != e[j].id) {
			FileT1 << e[j].name << endl;
			FileT1 << e[j].surname << endl;
			FileT1 << e[j].middlename << endl;
			FileT1 << e[j].id << endl;
			FileT1 << e[j].time << endl;
			FileT1 << e[j].tasks << endl;
		}
	}
	FileTO.close();
	FileT1.close();
	delete[] e;
	delete[] t;
}

void Interface::setRead_f(string databaseT, string databaseE, int Menu){
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
	e = new Employees[sizeT];
	t = new Task[sizeE];
	FileT.clear();
	FileT.seekg(0);
	FileE.clear();
	FileE.seekg(0);
	for (int i = 0; i < sizeT; i++) {
		FileT >> t[i].laboriousness;
		FileT >> t[i].deadline;
		FileT >> t[i].employee_id;
		FileT >> t[i].completness;
		FileT.ignore(32767,'\n');
		FileT >> t[i].name;
		FileT >> t[i].description;
	}
	for (int i = 0; i < sizeE; i++) {
		FileE >> e[i].name;
		FileE >> e[i].surname;
		FileE >> e[i].middlename;
		FileE >> e[i].id;
		FileE >> e[i].time;
		FileE >> e[i].tasks;
	}
	Interface in;
	if(Menu==4){in.getassign(e, t, sizeT, sizeE, databaseT, databaseE);}
	if(Menu==7){in.getviewE(e, t, sizeT, sizeE);}
	if(Menu==3){in.getTime_F(e, t, sizeT, sizeE, databaseT, databaseE);}
	if(Menu==5){in.getDelete_E(e, t, sizeT, sizeE, databaseT, databaseE);}
	FileE.close();
	FileT.close();
}
