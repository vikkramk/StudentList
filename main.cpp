/*Student List*/

#include <iostream>
#include <iomanip>
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

//Main
int main() {
	char* command;
	bool done = false;
	vector<Student*> list; //

	//Loop taking commands and executing until quit command given
	while (!done) {
		switch(getCommand()) {
			case QUIT: done = true; 	break;
			case PRINT: print(&list);	break;
			case ADD: add(&list);		break;
			case DELETE: remove(&list);	break;
		}
	}

	return 0;
}

//Get Command, returns command code of command that is entered
int getCommand(){
	bool valid = false;
	char command[80];
	char* commands[4] = {"QUIT", "PRINT", "ADD", "DELETE"};
	int code;

	cout << "Enter command:" << flush;
	while(!valid) {
		cin >> command;
	
		if (cin.fail()	|| cin.peek()!=10) {
			cout << cin.peek();
			cin.ignore(1000,'\n');
			cin.clear();
		}
		else {
			for (int i = 0; i < 4; i++) {
				//cout << commands[i] << flush;
				if (0==strcmp(command, commands[i])) {
				       	code = i;
					valid = true;
				}
			}
		}
		if (!valid) cout << "Enter valid command:" << flush;
	}

	return code;
}

//Print all the information for each student in list
void print(vector<Student*>* list) {
	if (list->size()==0)
		cout << "List is empty\n" << flush;
	for (int i = 0; i < list->size(); i++)
		cout << list->at(i)->fname << ", " << list->at(i)->lname << ", " << list->at(i)->id
			<< ", " << setprecision(2) << fixed << list->at(i)->gpa << '\n' << flush;
}

//Add a new student to list, prompting user for information
void add(vector<Student*>* list) {
	bool valid;
	Student* s = new Student();

	cout << "Enter first name:" << flush;
	valid = false;
	while (!valid) {
		cin >> s->fname;
		if (!(cin.fail() || cin.peek()!=10))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on name. Enter again:" << flush;
		}
	}

	cout << "Enter last name:" << flush;
	valid = false;
	while (!valid) {
		cin >> s->lname;
		if (!(cin.fail() || cin.peek()!=10))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on name. Enter again:" << flush;
		}
	}


	cout << "Enter id #:" << flush;
	valid = false;
	while(!valid) {
		cin >> s->id;
		if (!(cin.fail() || s->id > 999999 || s->id < 0 || (cin.peek() && cin.peek()!='\n'))) {
			valid = true;
		}
		else {
			cout << cin.peek();
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on id. Enter again:" << flush;
		}
	}

	cout << "Enter GPA:" << flush;
	valid = false;
	while(!valid) {
		cin >> s->gpa;
		if (!(cin.fail() || s->gpa > 5.0 || s->gpa < 0.0 || cin.peek()))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on GPA. Enter again:" << flush;
		}
	}

	cout << "Student added\n" << flush;

	list->push_back(s);
}


/*Remove a student from list as identified by id number
**Note: No error collection*/
void remove(vector<Student*>* list) {
	int id;
	bool valid = false;

	cout << "Enter id:" << flush;
	cin >> id;
	if (!(cin.fail() || id > 999999)) {
		for (int i = 0; i < list->size(); i++) {
			if (list->at(i)->id == id) {
				list->erase(list->begin() + i);
				valid = true;
			}
		}
	}
	else {
		cin.clear();
		cin.ignore(1000,'\n');
	}

	if (!valid) cout << "Error on id\n" << flush;
}
