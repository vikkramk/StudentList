/*Student List*/

#include <iostream>
#include <vector>
#include <cstring>

//Command codes
#define QUIT 0
#define PRINT 1
#define ADD 2
#define DELETE 3

using namespace std;

struct Student {
	char fname[80];
	char lname[80];
	int id;
	float gpa;
};

//Functions
void print(vector<Student*>* list);
void add(vector<Student*>* list);
void remove(vector<Student*>* list);
int getCommand();


int main() {
	char* command;
	bool done = false;
	vector<Student*> list;

	while (!done) {
		switch(getCommand()) {
			case QUIT: done = false;	break;
			case PRINT: print(&list);	break;
			case ADD: add(&list);		break;
			case DELETE: remove(&list);	break;
		}
	}

	return 0;
}

int getCommand(){
	bool valid = false;
	char command[80];
	char* commands[4] = {"QUIT", "PRINT", "ADD", "DELETE"};
	int code;

	cout << "Enter command:" << endl;
	while(!valid) {
		cin >> command;
	
		if (cin || cin.peek()) {
			cin.ignore(1000,'\n');
			cin.clear();
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (strcmp(command, commands[i])) {
				       	code = i;
					valid = true;
				}
			}
		}
		if (!valid) cout << "Enter valid command:" << endl;
	}
}

void print(vector<Student*>* list) {
	for (int i = 0; i < list->size(); i++)
		cout << list->at(i)->fname << " " << list->at(i)->lname << " " << list->at(i)->id
			<< " " << list->at(i)->gpa << '\n' << endl;
}

void add(vector<Student*>* list) {
	bool valid;

	list->push_back(&Student()):;
	cout << "Enter first name:" << endl;
	valid = false;
	while (!valid) {
		cin >> list->at(list->size()-1)->fname;
		if (!(cin || cin.peek()))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on name. Enter again:" << endl;
		}
	}

	cout << "Enter last name:" << endl;
	valid = false;
	while (!valid) {
		cin >> list->at(list->size()-1)->lname;
		if (!(cin || cin.peek()))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on name. Enter again:" << endl;
		}
	}


	cout << "Enter id #:" << endl;
	valid = false;
	while(!valid) {
		cin >> list->at(list->size()-1)->id;
		if (!(cin || list[list->size()-1]->id > 999999))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on id. Enter again:" << endl;
		}
	}

	cout << "Enter GPA:" << endl;
	valid = false;
	while(!valid) {
		cin >> list->at(list->size()-1)->gpa;
		if (!(cin || list->at(list->size()-1)->gpa > 5.0 || list->at(list->size()-1)->gpa < 0.0))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on GPA. Enter again:" << endl;
		}
	}
}

void remove(vector<Student*>* list) {
	int id;
	bool valid = false;

	cout << "Enter id" << endl;
	while(!valid) {
		cin >> id;
		if (!(cin || id > 999999))
			valid = false;
		else
			cout << "Error on id. Enter again" << endl;

		for (int i = 0; i < list->size(); i++) {
			if (list[i]->id == id) {
				list->erase(list->begin() + i);
				valid = true;
			}
		}
	}
}
