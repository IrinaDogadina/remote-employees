#include "job.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Task::setAddT(){
	//AddMain(Task& t)
	Task t;
	ofstream File("test.txt", ios::app);
	cin >> t;
	File <<t.deadline<<endl;
	File.close();
}

void Employees::setAddE(){
	//AddMain(Employees& e);
	Employees s;
        ofstream File("test.txt", ios::app);
        cin >> s;
        File << s.name<<endl;
        File.close();
}
//void AddMain(Object& o){
//ofstream File("test.txt", ios::app);
//File << o;
//File.close();
//}
