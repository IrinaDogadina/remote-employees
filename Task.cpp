#include "Task.hpp"
using namespace std;
Task::Task(){
	laibourness = 0;
	deadline = 0;
	active = false;
	employee_id = 0;
	completeness = 0;
	name = "";
	description = "";
	next = NULL;
}
Task::add(Task t){
	t->next = head;
	head = temp;
}
ifstream& operator>>(ifstream &fin, Task &t){
		Task* temp = new Task;
		fin >> laibourness;
		fin >> deadline;
		fin >> active;
		fin >> employee_id;
		fin >> completeness;
		fin >> name;
		fin >> description;
}
