#include <iostream>
#include <string>
#define SIZE 10               // max child a node (person) can have
using namespace std;
string pname;
class node{
public:
	string name;     // person name
	int num;       // ID num
	node* chArr[SIZE];      // child Array
	node(){                    // default constructor
		name = "no_name";
		num = -1;
		for (int i = 0; i < SIZE; i++)
			chArr[i] = NULL;
	}

};
void search_ID(int num, node* ptr);      // prototype
class N_ARY_TREE{
public:
	node* root;
	N_ARY_TREE(){
		root = new node();
	}
	int getInverted(int num){               // it actually invert the num i-e 123 -> 321 . 
		int num2 = 0;
		while (num != 0){
			num2 = num2 * 10 + num % 10;
			num = num / 10;
		}
		return num2;
	}

	void insertUtil(int &num, int ID, string name, node* next){
		int digit = num % 10;
		num = num / 10;

		if (num == 0){
			if (next == NULL)
				next = new node();
			next->name = name;
			next->num = ID;
			return;
		}

		if (next->chArr[digit] == NULL){
			next->chArr[digit] = new node();
			next->chArr[digit]->name = "no_name";
			next->chArr[digit]->num = -1;
		}
		insertUtil(num, ID, name, next->chArr[digit]);
	}

	void insert(int num, string name){
		int num2 = getInverted(num);
		insertUtil(num2, num, name, root);
	}
	void display(node* ptr){

		cout << endl << "  ID Number : " << ptr->num << endl;
		cout << "  Name of the person : " << ptr->name << endl;
		cout << " Father ID :" << ptr->num / 10 << endl;
		cout << " Father Name : " << pname << endl;
		cout << " Children :" << endl;
		int c = 0;
		for (int i = 0; i < 10; i++)
		{
			if (ptr->chArr[i] != NULL){
				cout << endl << " child ID :" << ptr->chArr[i]->num << endl;
				cout << " Child Name : " << ptr->chArr[i]->name << endl;
				c++;
			}
		}
		if (c == 0)
		{
			cout << " No child ";
		}
	}
	void searching(int num, node* ptr){
		int number = 0;
		int digit = num % 10;
		num = num / 10;
		if (num == 0)
		{
			display(ptr);
			return;
		}
		else{
			pname = ptr->name;
			searching(num, ptr->chArr[digit]);
		}
	}
	void search_ID(int num, node* ptr){
		int num2 = getInverted(num);
		searching(num2, ptr);
	}
	void search_name(string name, node* ptr){
		for (int i = 0; i < SIZE; i++)
		{
			if (ptr->chArr[i]->name.compare(name)==0){
				search_ID(ptr->chArr[i]->num, root);
				return;
			}
		}
		for (int j = 0; j < SIZE; j++)
		{
			search_name(name, ptr->chArr[j]);
		}
	}
	void removing(int num, node* ptr){

		int digit = num % 10;
		num = num / 10;
		if (num == 0)
		{
			if (ptr->name == "no_name")
			{
				cout << "No record found for this ID " << endl;
			}
			else
			{
				cout << "Registration of person named " << ptr->name << " is deleted " << endl;
				ptr->name = "no_name";
			}
		}
		else{
			removing(num, ptr->chArr[digit]);
		}
	}
	void remove(int num, node* ptr){
		int num2 = getInverted(num);
		removing(num2, ptr);
	}
};

int main(){
	N_ARY_TREE NADRA;
	string name;
	int ID;
	int choice;
	cout << endl << "         **********************************************";
	cout << endl << "                         Welcome  " << endl;
	cout << endl << "          DATABASE containing information about person ";
	cout << endl << "         **********************************************" << endl << endl;
	while (1)
	{

		cout << endl << " Press the keys to perform the following functions " << endl << endl;
		cout << "  1.Registering a person in database" << endl;
		cout << "  2.Search the person using Name" << endl;
		cout << "  3.Search the person using ID Number " << endl;
		cout << "  4.Delete the person's Registration " << endl;
		cout << "  5.Exit " << endl;
		cout << endl << "*********************************" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "*********************************" << endl;
			cout << " Registering the person : " << endl;
			cout << "Enter the Person's ID Number : ";
			cin >> ID;
			cout << "Enter the Person's Name : ";
			cin >> name;
			NADRA.insert(ID, name);
			cout << endl;
			break;

		case 2:
			cout << "*********************************" << endl;
			cout << "Enter the Person's Name : ";
			cin >> name;
			NADRA.search_name(name, NADRA.root);
			cout << endl;
			break;
		case 3:
			cout << "*********************************" << endl;
			cout << " Searching the person using ID number  " << endl;
			cout << "Enter the Person's ID : ";
			cin >> ID;
			NADRA.search_ID(ID, NADRA.root);

			break;
		case 4:
			cout << "*********************************" << endl;
			cout << " Removing the person's registration  " << endl;
			cout << "Enter the Person's ID : ";
			cin >> ID;
			NADRA.remove(ID, NADRA.root);
			cout << endl;
			break;

		case 5:
			cout << "*********************************" << endl;
			cout << "Exiting..." << endl;
			exit(1);
			break;
		default:
			cout << "Wrong choice" << endl;
		}

	}



	system("pause");
}


