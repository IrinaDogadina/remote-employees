#include "job.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Task::setAddT(string FileName){
	//AddMain(Task& t)
	Task t;
	ofstream File(FileName, ios::app);
	cin >> t;
	cout<< "Введите имя задачи:" << endl;
	getline(cin,t.name);
        cout << t.name;
        cout << "Опишите задачу:" << endl;
        getline(cin,t.description);
	cout<<t.description;
        File <<t.deadline<<endl;
	File.close();
}

void Employees::setAddE(string FileName){
	//AddMain(Employees& e);
	Employees s;
        ofstream File(FileName, ios::app);
        cin >> s;
        File << s.name<<endl;
        File.close();
}
//void AddMain(Object& o){
//ofstream File("test.txt", ios::app);
//File << o;
//File.close();/
//cout<<"tyt";
//}
