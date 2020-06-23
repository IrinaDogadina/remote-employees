#include "interface.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Interface::viewE(int sizeT, int sizeE) {
	int i, j;
	for (i = 0; i < sizeE; i++) {
		cout << endl << e[i].getName() << ' ' << e[i].getSurname() << ' ' << e[i].getMiddName() << ' ' << "ID: " << e[i].getId() << " Часы работы в неделю: " << e[i].getTime() << endl;
		for (j = 0; j < sizeT; j++){
			if (t[j].getEmpId() == e[i].getId()) {
				cout << endl;
				cout << "Задача сотрудника:" << endl;
				cout << endl;
				cout << "Название задачи: "<< t[j].getName() << endl;
				cout << "Описание задачи: " << t[j].getDescr() << endl;
				cout << "Трудоемкость: " << t[j].getLab() << " часов" << endl;
				cout << "Срок выполнения: " << t[j].getDeadl() << " часов" << endl;
				cout << "Степень готовности: " << t[j].getCompl() << "%" << endl;
			}
		}
	}
}

void Interface::assign(int sizeT, int sizeE, string databaseT, string databaseE){
	string temp;
	int temp_id;
	int i, j, k;
	for (i = 0; i < sizeT; i++) {
			if (t[i].getEmpId() == 0) {
				cout << "Название задачи: " << t[i].getName() << endl;
				cout << "Описание задачи: " << t[i].getDescr() << endl;
				cout << endl << "Трудоемкость: " << t[i].getLab() << " часов" << endl;
				cout << "Срок выполнения: " << t[i].getDeadl() << " часов" << endl;
				cout << "Степень готовности: " << t[i].getCompl() << "%" << endl;
				cout<<"---------------"<<endl;
			}
		}
	cin.ignore(32767,'\n');
	cout << "Введите наименование задачи для присвоения сотруднику: " << endl;
	getline(cin, temp);
	for (k = 0; k < sizeE; k++) {
		cout << endl << "ID: " << e[k].getId() << ' ' <<  e[k].getName() << ' ' << e[k].getSurname() << ' ' << e[k].getMiddName() << ' ' << " Часы работы в неделю: " << e[k].getTime() << endl;
		cout << "---------------" << endl;
	}
	for (i = 0; i < sizeT; i++) {
		if (temp == t[i].getName() && t[i].getEmpId() == 0){
			cout << "Выберите id сотрудника: " << endl;
			cin >> temp_id;
			for (j = 0; j < sizeE; j++){
				if (temp_id == e[j].getId()){
					/*!
					@brief проверка возможности выполнения задачи сотрудником
					@brief если срок и трудоемкость задачи превышает одну неделю,
					@brief то из обоих переменных вычитается количество недель, а также ведется счетчик недель
					*/
					int count = 0;
					int ddl = t[i].getDeadl();
					if (ddl > 168 && t[i].getLab() > e[j].getTime()){
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
					if (ddl >= (t[i].getLab()-((e[j].getTime()*count)/(e[j].getTasks()+1))) && ((t[i].getLab()-((e[j].getTime()*count)/(e[j].getTasks()+1))) <= 0)){
						int a = 0;
						/*!
						@brief если сотрудник успеет выполнить назначаемую задачу,
						@brief то проверяется возможность выполнения уже назначенных задач по той же схеме
						@brief если сотрудник не успеет выполнить уже назначенные задачи, то назначаемая задача не назначается
						*/
						if (e[j].getTasks() != 0){
							for (k = 0; k < sizeT; k++){
								if (t[k].getEmpId() == temp_id) {
									count = 0;
									ddl = t[k].getDeadl();
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
								if (ddl < (t[k].getLab()-((e[j].getTime()*count)/(e[j].getTasks()+1))) && ((t[k].getLab()-((e[j].getTime()*count)/(e[j].getTasks()+1)))) > 0){
									a++;
									cout << "Невозможно присвоить задачу, сотрудник не успеет выполнить другие свои задачи." << endl;
									break;
								}
							}
						}
						if (a == 0){
							int b = e[j].getTasks();
							b++;
							t[i].setEmpId(temp_id);
							e[j].setTasks(b);
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
		FileTO << t[i].getLab() << endl;
		FileTO << t[i].getDeadl() << endl;
		FileTO << t[i].getEmpId() << endl;
		FileTO << t[i].getCompl() << endl;
		FileTO << t[i].getName() << endl;
		FileTO << t[i].getDescr() << endl;
	}
	for (j = 0; j < sizeE; j++){
		FileT1 << e[j].getName() << endl;
		FileT1 << e[j].getSurname() << endl;
		FileT1 << e[j].getMiddName() << endl;
		FileT1 << e[j].getId() << endl;
		FileT1 << e[j].getTime() << endl;
		FileT1 << e[j].getTasks() << endl;
	}
	FileTO.close();
	FileT1.close();
	delete[] e;
	delete[] t;
}

void Interface::Time_F(int sizeT, int sizeE, string databaseT, string databaseE){
	cout << "Прошла неделя" << endl;
	int i, j;
	for (i = 0; i < sizeE; i++){
		if (e[i].getTasks() != 0){
			for (j = 0; j < sizeT; j++){
				/*!
				@brief перерасчет степени готовности, срока, трудоемкости задач спустя неделю
				@brief из трудоемкости вычитается рабочее время работника деленное на количество задач сотрудника
				@brief из срока вычитается неделя
				@brief степень готовности считается от вычтенной трудоемкости к первоначальной
				@brief при завершении задач задачам присваивается нулевой срок, трудоемкость, уменьшается количество задач на сотруднике
				*/
				 if (t[j].getEmpId() != 0 && t[j].getEmpId() == e[i].getId() && t[j].getCompl() != 100 && t[j].getLab() != 0){
					int count = t[j].getLab()-((e[i].getTime())/(e[i].getTasks()));
					int cmpl = ((count*100)/(t[j].getLab()));
					t[j].setCompl(cmpl);
					t[j].setLab(count);
					int deadl = t[j].getDeadl()-168;
					t[j].setDeadl(deadl);
					if (t[j].getLab() <= 0){
						t[j].setLab(0);
						t[j].setCompl(100);
						int tsk = e[i].getTasks()-1;
						e[i].setTasks(tsk);
					}
					if (t[j].getDeadl() < 0){
						t[j].setDeadl(0);
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
		FileTO << t[i].getLab() << endl;
		FileTO << t[i].getDeadl() << endl;
		FileTO << t[i].getEmpId() << endl;
		FileTO << t[i].getCompl() << endl;
		FileTO << t[i].getName() << endl;
		FileTO << t[i].getDescr() << endl;
	}
	for (j = 0; j < sizeE; j++){
		FileT1 << e[j].getName() << endl;
		FileT1 << e[j].getSurname() << endl;
		FileT1 << e[j].getMiddName() << endl;
		FileT1 << e[j].getId() << endl;
		FileT1 << e[j].getTime() << endl;
		FileT1 << e[j].getTasks() << endl;
	}
	FileTO.close();
	FileT1.close();
	delete[] e;
	delete[] t;
}

void Interface::Delete_E(int sizeT, int sizeE, string databaseT, string databaseE) {
	string surname_del, name_del;
	cout << "Введите фамилию работника" << endl;
	cin >> surname_del;
	cout << "Введите имя работника" << endl;
	cin >> name_del;
	int i, j, id_del;
	for (i = 0; i < sizeE; i++) {
		if (surname_del == e[i].getSurname() && name_del == e[i].getName()) {
			id_del = e[i].getId();
			for (j = 0; j < sizeT; j++) {
				if (t[j].getEmpId() == id_del) {
					t[j].setEmpId(0);
				}
			}
		}
	}
	fstream FileTO;
	FileTO.open(databaseT, ios::trunc | ios::out);
	fstream FileT1;
	FileT1.open(databaseE, ios::trunc | ios::out);
	for (i = 0; i < sizeT; i++){
		if (t[i].getCompl() != 100){
			FileTO << t[i].getLab() << endl;
			FileTO << t[i].getDeadl() << endl;
			FileTO << t[i].getEmpId() << endl;
			FileTO << t[i].getCompl() << endl;
			FileTO << t[i].getName() << endl;
			FileTO << t[i].getDescr() << endl;
		}
	}
	for (j = 0; j < sizeE; j++){
		if (id_del != e[j].getId()) {
			FileT1 << e[j].getName() << endl;
			FileT1 << e[j].getSurname() << endl;
			FileT1 << e[j].getMiddName() << endl;
			FileT1 << e[j].getId() << endl;
			FileT1 << e[j].getTime() << endl;
			FileT1 << e[j].getTasks() << endl;
		}
	}
	FileTO.close();
	FileT1.close();
	delete[] e;
	delete[] t;
}

void Interface::Read_f(string databaseT, string databaseE, int Menu){
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
	int lab_t = 0, deadl_t = 0, emp_id_t = 0, compl_t = 0, id_e = 0, time_e = 0, tasks_e = 0;
	string name_task = {}, descr_task = {}, name_e = {}, surname_e = {}, middlename_e = {};
	Task* countT = new Task;
	int sizeT = countT->setSize(FileT);
  sizeT--;
	delete countT;
  FileT.clear();
  FileT.seekg(0);
  int i;
  t = new Task[sizeT];
  for (i = 0; i < sizeT; i++){
		FileT >> lab_t;
		t[i].setLab(lab_t);
    FileT >> deadl_t;
		t[i].setDeadl(deadl_t);
		FileT >> emp_id_t;
		t[i].setEmpId(emp_id_t);
		FileT >> compl_t;
		t[i].setCompl(compl_t);
		FileT.ignore(32767,'\n');
    getline(FileT, name_task, '\n');
		t[i].setName(name_task);
		getline(FileT, descr_task, '\n');
		t[i].setDescr(descr_task);
  }
	FileT.close();
	Employees* countE = new Employees;
	int sizeE = countE->setSize(FileE);
  sizeE--;
	delete countE;
  FileE.clear();
  FileE.seekg(0);
  e = new Employees[sizeE];
	for (i = 0; i < sizeE; i++){
		FileE >> name_e;
		e[i].setName(name_e);
		FileE >> surname_e;
		e[i].setSurname(surname_e);
		FileE >> middlename_e;
		e[i].setMiddName(middlename_e);
		FileE >> id_e;
		e[i].setId(id_e);
		FileE >> time_e;
		e[i].setTime(time_e);
		FileE >> tasks_e;
		e[i].setTasks(tasks_e);
	}
	FileE.close();
	if(Menu==4){assign(sizeT, sizeE, databaseT, databaseE);}
	if(Menu==7){viewE(sizeT, sizeE);}
	if(Menu==3){Time_F(sizeT, sizeE, databaseT, databaseE);}
	if(Menu==5){Delete_E(sizeT, sizeE, databaseT, databaseE);}
}
