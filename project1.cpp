//start date: Jan 6, 2023.
//end date: Jan 20, 2023

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

using namespace std;
using std::ios;

//valuable strings
string CurUser = " ";
string VInput[11] = {"h","c","q","nu","lu","nn","on","dn","lo","du","en"};
string help = "This are the commands: \nh				for help \nc				for credits \nq				to quit \nen			edit an existing note\nnu			create new user \nlu			loginto existing user \nn			create new note \non			open a note (only works if you are logged in) \ndn			delete a note (only works if are logged in)\nlo 			to logout of current user\ndu			delete current user\n \n";
string credit = "Preetom Boro, Pulldeep Boro Gogoi, Pranjit Boro, Manash Boro\n\n";

//function declarations
int check(string a);
void Display(string a);
int belong(string a, string b);
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
        
        fstream test;
        test.open(name+".txt", std::ios::in);
        if(test.is_open()){
            cout<<"This User already exists.\n\n";
            return;
        }
        
        //create file
        fstream file;
        file.open(name+".txt", std::ios::out );
        file<<password<<"\n";
        file<<"Notes authored:";
        file.close();
        CurUser = name;

        cout<<"User created.\n\n";
    }

    //loging in (don't call if not verified)
    User(string a,string b){
        name = a;
        password = b;
        CurUser = name;
    }

    //dummy object to access different member function
    //takes in username as argument.
    User(string a){
        name = a;
    }

    //new note (takes note name as argument)
    void newNote(string a){
        string line="";

        fstream test;
        test.open(a+".txt", std::ios::in);
        if(test.is_open()){
            cout<<"This note already exists.(try different note name)\n\n";
            return;
        }

        fstream file;
        file.open(a+".txt",std::ios::out);
        cout<<"enter -1 to exit";
        while(file){
            getline(cin, line);
            if(line=="-1"){
                cout<<"\n\n";
                break;
            }
            file<<line<<endl;
        }
        file.close();

        //adding note to the list in User profile
        file.open(name+".txt",std::ios::app);
        file.seekg(0, std::ios::end);
        file<<"\n"<<a;
        file.close();
        
        return;
    }

    //open a note(takes in esisting note name)
    int editNote(string a){
        string line;
        disNote(a);
        if(verify(a)){
            if(belong(a ,CurUser)){
                //edit note
                fstream file;
                file.open(a+".txt",std::ios::app);
                cout<<"enter -1 to exit";
                while(file){
                    getline(cin, line);
                    if(line=="-1"){
                        cout<<"\n\n";
                        break;
                    }
                file<<line<<endl;
                }
                file.close();
                return 0;    
            }
            else{
                cout<<"This Note doesn't belong to the current User.\n\n";
                return 1;
            }
        }
        else{
            cout<<"There is no such note.\n\n";
            return 1;
        }      
        return 0;
    }

    //display a note(takes note name as argument)
    int disNote(string a){
        if(verify(a)){
            if(belong(a ,CurUser)){
            //display work
            string line="";
            fstream file;
            file.open(a+".txt", std::ios::in);
            while(getline(file,line)){
                cout<<line<<endl;
            }
            file.close();
            return 0;        
            }
            else{
                cout<<"This Note doesn't belong to the current User.\n\n";
                return 1;
            }
        }
        else{
            cout<<"There is no such note.\n\n";
            return 1;
        }      
        
    }

    //useing note_name as argument
    int delNote(string a){
        if(verify(a)){
            if(belong(a,CurUser)){
                char filename[20];
                string dummy;
                dummy = a + ".txt";
                strcpy(filename,dummy.c_str());
                remove(filename);
                cout<<"Successfully deleted note " << a;
                cout<<".\n\n";
                return 0;
            }
            else{
                cout<<"This Note doesn't belong to the current User.\n\n";
                return 1;
            }
        }
    return 0;
    }

    //delete user (don't call without verification).
    //returns 1 if user is deleted.
    int delUser(){
        int n =0;
        char filename[20];
        string dummy;
        dummy = name + ".txt";
        strcpy(filename, dummy.c_str());
        if(remove(filename)){
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
    return;
    }

    //loginto a user with "lu"
	else if (a=="lu"){
        cout<<"\nLog in.\n";
		cout<<"Enter username(case sensitive):";
		cin>>nam;
        cout<<"Enter the password:";
        cin>>pass;
        if(verify(nam,pass)){
		    User b(nam,pass);
            CurUser = nam;
            cout<<"Logged in.\n\n";
        }
        return;
    }

    //create new user with "nu"
	else if (a=="nu"){
        cout<<"\nCreate New User.\n";
		User a;
        return;
	}

    //delete user with "du"
	else if (a=="du"){
        cout<<"\nDelete User.\n";
		cout<<"Enter username(case sensitive):";
		cin>>nam;
        cout<<"Enter the password:";
        cin>>pass;
        if(verify(nam,pass)){
            User b(nam);
            b.delUser();
            
        }
        return;
	}

    //logout from current user "lo"
    else if (a=="lo"){
        if(CurUser != " "){
            CurUser =" ";
            cout<<"\nYou are now logged out.\n\n";
        }
        else{
            cout<<"\nYou are not logged in.\n\n";
        }
        return;
    }

    //create new note(for a user)
    else if(a=="nn"){
        cout<<"\nCreate note:\n";
        if(CurUser !=" "){
            string b="";
            User a(CurUser);
            cout<<"Enter the name of your note:";
            cin>>b;
            a.newNote(b);
        }
        else {
            cout<<"You are not logged in.\ntype 'lu' to log in or 'nu' to create new user\n\n";
        }
        return;
    }

    //open an existing note with "on"
    else if(a=="on"){
        string note_name;
        cout<<"\nOpen a note.\n";
        cout<<"Enter Note name:";
        cin>>note_name;
        User b;
        b.disNote(note_name);
        return;
    }

    //edit an existing note with "en"
    else if(a=="en"){
        string note_name;
        cout<<"Editing a note.\n";
        cout<<"Enter the note name:";
        cin>>note_name;
        User b(CurUser);
        b.editNote(note_name);
        return;
    }

    //delete an existing note with "dn"
    else if(a=="dn"){
        string note_name;
        cout<<"Delete a note.\n";
        cout<<"Enter Note name:";
        cin>>note_name;
        User b(CurUser);
        b.disNote(note_name);
        return;
    }

	return;
}

//only call after verify()
//checks if string "a" note belongs to string "b" user.
int belong(string a, string b){
    int n=0;
    User h(b);
    fstream file;

    file.open(b+".txt", ios::in);
    
    if(file.is_open()){
        string notnam;

        while(!file.eof()){
            getline(file,notnam);
            if(notnam==a){
                n=1;
                break;
            }
        }
    }
    file.close();
    return n;
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
            cout<<"worng password.\n\n";
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
    file.open(a+".txt", std::ios::in );
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
    cout<<"(This project has quite a few bug, please read bug report.)\n\n";
    for(int i =0; i<1;)
    {
        input = "";
		cout<<"(EnterCommand  "<<CurUser<<" )";
		cin>>input;
		//system("cls");
		
		if (input =="q"){
			cout<<"quitting program\n";
			break;
		}
        else if(input =="c"){
            cout<<credit;
            continue;
        }
		else if ((check(input))){
			Display(input);
            continue;
			//cout<<"nice command:) \n \n";
		}
		else
		{
			cout<<"\n'"<<input<<"' is not a valid input\nenter 'h' for help\n\n";
		}
    }
    return 0;
}
