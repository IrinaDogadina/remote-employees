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
        while (!FileE.eof()) {
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
        if (!(FileE.is_open())) {
                cout << "Ошибка открытия файла" << endl;
                exit(0);
        }
        Employees* countE = new Employees;
        int sizeE = countE->setSize(FileE);
        delete countE;
        FileE.clear();
        FileE.seekg(0);
        int i;
        Employees* e = new Employees[sizeE];
        if (sizeE != 0) {
                for (i = 0; i < sizeE-1; i++) {
                        FileE >> e[i].surname;
                        FileE >> e[i].name;
                        FileE >> e[i].middlename;
                        FileE >> e[i].id;
                        FileE >> e[i].time;
                        FileE >> e[i].tasks;
                }
                sizeE--;
        }
        cout << "Введите фамилию сотрудника:" << endl;
        cin >> e[sizeE].surname;
        cout << "Введите имя сотрудника:" << endl;
        cin >> e[sizeE].name;
        cout << "Введите отчество сотрудника:" << endl;
        cin >> e[sizeE].middlename;
        cout << "Введите время, которое может отработать сотрудник за неделю:" << endl;
        cin >> e[sizeE].time;
        if (sizeE == 0) {
                FileE << e[sizeE].name << endl;
                FileE << e[sizeE].surname << endl;
                FileE << e[sizeE].middlename << endl;
                FileE << '1' << endl;
                FileE << e[sizeE].time << endl;
                FileE << '0' << endl;
        }
        else {
                FileE << e[sizeE].name << endl;
                FileE << e[sizeE].surname << endl;
                FileE << e[sizeE].middlename << endl;
                e[sizeE].id = e[sizeE-1].id+1;
                FileE << e[sizeE].id << endl;
                FileE << e[sizeE].time << endl;
                FileE << '0' << endl;
        }
        FileE.close();
        delete[] e;
}
