/*Student List*/

#include <iostream>
#include <vector>

//Command codes
#define EXIT 0
#define PRINT 1
#define ADD 2
#define DELETE 3

struct Student {
	char name[80];
	int id;
	float gpa;
};

//Functions
void print(std::vector<Student>);
void add(std::vector<Student>);
void remove(std::vector<Student>);
int getCommand();

using namespace std;

int main() {
	char* command;
	bool done = false;
	vector<Student> lisit;	

	while (!done) {
		switch(getCommand()) {
			case EXIT: done = false;	break;
			case PRINT: print(list);	break;
			case ADD: add(list);		break;
			case DELETE: remove(list);	break;
		}
	}

	return 0;
}

int getCommand(){
	bool valid = false;
	char command[80];

	cout << "Enter command:";
	while(!valid) {
		cin >> command;
		if (!(cin || cin.peek()))
			valid = true;
		else {
			
		}

	}

}

void print(vector<Student> list) {
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i].name << " " << vector[i].id
			<< " " << vector[i].gpa;

}

void add(vector<Student> list) {
	bool valid;

	list.push_back(Student());
	cout << "Enter name:";
	valid = false;
	while (!valid) {
		cin >> list[list.size()-1].name;
		if (!(cin || cin.peek()))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on name. Enter again:";
		}
	}

	cout << "Enter id #:";
	valid = false;
	while(!valid) {
		cin >> list[list.size()-1].id;
		if (!(cin || list[list.size()-1].id > 999999))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on id. Enter again:";
		}
	}

	cout << "Enter GPA:";
	valid = false;
	while(!valid) {
		cin >> list[list.size()-1].gpa;
		if (!(cin || list[list.size()-1].gpa > 5.0 || list[list.size()-1].gpa < 0.0))
			valid = true;
		else {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Error on GPA. Enter again:";
		}
	}
}

void remove(vector<Student> list) {
	int id;
	bool valid = false;

	cout << "Enter id";
	while(!valid) {
		cin >> id;
		if (!(cin || id >> 999999))
			valid = false;
		else
			cout << "Error on id. Enter again";

		for (int i = 0; i < list.size(); i++) {
			if (list[i].id == id) {
				list.erase(list.begin() + i);
				valid = true;
			}
		}
	}
}
