//start date: Jan 6, 2023.
//end date: pending

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

using namespace std;
using std::ios;

//valuable strings
string CurUser = " ";
string VInput[11] = {"h","c","q","nu","lu","nn","on","dn","lo","du"};
string help = "This are the commands: \nh				for help \nc				for credits \nq				to quit \nnnu			create new user(public,no password) \nnu			create new user \nlu			loginto existing user \nn			create new note \non			open a note (only works if you are logged in) \ndn			delete o note (only works if are logged in)\nlo 			to logout of current user\ndu			delete current user\n \n";
string credit = "Preetom Boro, Pulldeep Boro Gogoi, Pranjit Boro, Manash Boro\n\n";

//function declarations
int check(string a);
void Display(string a);
int verify(string a, string b);
int verify(string a);

//Class defination
class User{
    private:
    string name, password;

    public:

    //User Creation
    User(){
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter Password:";
        cin>>password;
        
        //create file
        fstream file;
        file.open(name+".txt", std::ios::out );
        file<<password<<"\n";
        file<<"Notes authored:";
        file.close();
        CurUser = name;
    }

    //loging in (don't call if not verified)
    User(string a,string b){
        name = a;
        password = b;
        CurUser = name;
    }

    //dummy object to access different member function
    User(string a){
        name = a;
    }

    //new note (takes note name as argument)
    void newNote(string a){
        string line="";
        fstream file;
        file.open(a+".txt",std::ios::out);
        cout<<"enter -1 to exit";
        while(file){
            getline(cin, line);

            if(line=="-1")
                break;
            
            file<<line<<endl;
        }
        file.close();
        return;
    }

    //open a note(takes in esisting note name)
    void openNote(string a){
        string line;
        disNote(a);
        fstream file;
        file.open(a+".txt", std::ios::in);
        cout<<"enter -1 to exit";
        while(file){
            getline(cin, line);
            if(line=="-1")
                break;
            
            file<<line<<endl;
        }
        file.close();       
        return;
    }

    //display a note(takes note name as argument)
    void disNote(string a){
        string line="";
        fstream file;
        file.open(a+".txt", std::ios::in);
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
        return;
    }

    //delete user (don't call without verification).
    //returns 1 if user is deleted.
    int delUser(){
        int n;
        char filename[20];
        strcpy(filename, CurUser.c_str());
        n = remove(filename);
        if(n==0){
            cout<<"User not deleted.\n\n";
        }
        else{
            cout<<"User deleted.\n\n";
            n=1;
        }
        return n;
    }
    
};

//-----------------------------------------------------------------------
//validates input
int check(string a)
{
	int n =0;
	for(int i =0; i<11;i++){
		if (a==VInput[i])
			n+=1;
	}
	return n;
}

//takes actions according to the input
void Display(string a){
	string nam="";
    string pass="";

    //view help with "h"
	if (a=="h"){
		cout<<help;
    }

    //loginto a user with "lu"
	else if (a=="lu"){
		cout<<"Enter username(case sensitive):";
		cin>>nam;
        cout<<"Enter the password:";
        cin>>pass;
        if(verify(nam,pass)){
		    User a(nam,pass);
        }
        else{
            cout<<"wrong set of User and Password\n\n";
	    }
    }

    //create new user with "nu"
	else if (a=="nu"){
		User a;
	}

    //delete current user with "du"
	else if (a=="du"){
		cout<<"Enter username(case sensitive):";
		cin>>nam;
        cout<<"Enter the password:";
        cin>>pass;
        if(CurUser!=" "){
            User a(CurUser);
            a.delUser();
            
        }
        else
            cout<<"wrong set of User and Password.\n\n";
	}

    //logout from current user "lo"
    else if (a=="lo"){
        if(verify(nam)){
            CurUser =" ";
        }
        else{
            cout<<"You are not logged in";
        }
    }

    //create new note(for a user)
    else if(a=="nn"){
        if(CurUser !=" "){
            string b="";
            User a(CurUser);
            cout<<"Enter the name of your note:";
            cin>>b;
            a.newNote(b);
        }
        else {
            cout<<"You are not logged in.\ntype 'lu' to log in or 'nu' to create new user\n";
        }
    }

    //open an existing note with "on"
    else if(a=="on"){
        string note_name;
        cout<<"Enter Note name:";
        cin>>note_name;
        verify(note_name);
    }

	return;
}

//verify if the user name and password is valid
int verify(string a, string b){
    int n;
    fstream file;
    file.open(a+".txt", std::ios::in );
    file.seekg(0);
    if(file){
        string c;
        getline(file,c);
        if (b==c){
            n=1;
        }
        else{
            cout<<"worng password.\n";
        }
    }
    else{
        cout<<a<<" username not found\n\n";
    }
    return n;
}

//verify if user exists
int verify(string a){
    int n=0;
    fstream file;
    file.open(a+".dat", std::ios::in );
    file.seekg(0);
    if(file){
        n=1;
    }
    return n;
}

//--------------------------------------------------------------

int main(){
    string input;
    input ="";
    cout<<"welcome";
    for(int i =0; i<1;)
    {
        input = "";


		cout<<"(EnterCommand"<<CurUser<<")";
		cin>>input;
		//system("cls");
		
		if (input =="q"){
			cout<<"quitting program\n";
			break;
		}
		else if ((check(input))){
			Display(input);
			//cout<<"nice command:) \n \n";
		}
		else
		{
			cout<<input<<" is not a valid input\nenter 'h' for help\n\n";
		}

    }

    return 0;
}
