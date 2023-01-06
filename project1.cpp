//start date: Jan 6, 2023.
//end date: pending

#include<iostream>
#include<fstream.h>
#include<string.h>

using namespace std;

//---------------------------------------------------------------
//start of inline documentation

string sdoc;
sdoc = "2023 computer project. St.John's H.S. School\n
(an atempt to mimick working MySql commandline)\n
for help- h \n
for credit- c "

string credit;
credit = "Group Member:\n
Preetom Boro\n
Pulldeep Bora Gogoi\n
Pranjit Thakur\n
Manash Boro"

string help;
help="Following are the available commands:\n
nuser 				to create new user\n
duser 				to delete user\n
ndata 				to create new data base\n
ddata 				to delete database\n
ntable				to create new table\n
dtable				to delete new table\n
showu					to show list of all users\n
showd					to show list of databases of current user\n
showt					to show list of all tables of current database\n
displayt			to show the contents of a table\n
displayd			to show current user,databse and table\n
lin						to loginto/use a different user/database"

//end of inline documentation
//--------------------------------------------------------------


//some global variables
int n=13; //number of valid inputs

//start of useful function defination(may or maynot be member function of any class)
//--------------------------------------------------------------

int UserSiNo(){
	return 0;
}

int DatabaseSiNo(){
	return 0;
}

int InputValidity(string a){
	int validity=0;
	for(int i =0; i>=n)
	return validity;
}

void Display(int a){
	int type =0;
	switch(a)
	case 1:
		DisUser();
		break;
	case 2:
		DisData();
		break;
	case 3:
		DisTable();
		break;
	default:
		return;
	return;
}

void DisUser(){

}
void DisData(){

}
void DisTable(){

}

int IdentifyType(string a){
	//1 for user, 2 for data base;
	int tpe;
	
	return tpe;
}



//start of class definations
//---------------------------------------------------------------
class User{
	private:
		int siNo;
		string name;
	public:
		User(){
			cout<<"Enter User name:";
			cin>>name;
		}
		~User(){
			cout<<"User "<<name<<" deleted succefully";
		}
}


class table{
	private:
		int rowno=0 ,colno =0;
		string name;
	public:
		table(){
			cout<<"Enter table name:";
			cin>>name;
			cout<<"\nEnter colomn number:";
			cin>>colno;
			cout<<"\nEnter the number of rows:";
			cin>>rowno;
		}
		~table(){
			cout<<"table "<<name<<" deleted successfully\n";
		}
}

class Database{
	private:
		int siNo, noTable;
		string name;
		
	public:
		Database(){
			cout<<:"Enter the name of the database:";
			cin>>name;
		}
		~Database(){
			cout<<"database deleted sucessfully";
		}
}

//---------------------------------------------------------------
//end of class defination


string validinput[n];
validinput = {"h","c","q","nuser","duser","ndata","ddata",
"ntable","dtabe","listu","listd","listt","showt","showdu",
"lin"};

int main(){
	Display();
	string inpu = "";
	cout<<sdoc;
	
	for(int i=0;;){
		
		system("cls");
		cin>>inpu;
		system("cls");
		if InputValidity(inpu);
		{
			display(IdentifyInput(inpu));
		}
	}
	cout<<"program runned sucessfully";
	system("pause");
	return 0;
}
