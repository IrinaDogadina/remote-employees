#include <string>
using namespace std;
class Task{
	private:
		int laibourness;
		int deadline;
		bool active;
		int empolyee_id;
		int completness;
		string name;
		string description;
		Task* head;
		Task* next;
	public:
		Task();
		void add(Task t);
		ifstream& operator>>(ifstream &fin, Task &t);
};
