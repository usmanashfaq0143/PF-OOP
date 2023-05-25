#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Diary{
	protected:
	string Name;
	public:
	void setName(string name){
		Name = name;
	}string getName(){
		return Name;
	}
	Diary(string name){
		Name = name;
	}
	void AskNameOfDiary(string name){
		cout<<"Enter the name of Your Diary: ";cin>>name;
		string filename;
		filename = name + ".txt";
		ofstream file;
		file.open(filename.c_str());
		file<<"Diary:                         "<<name<<endl;
		file.close();
	}		
};

class Note:public Diary{
	string Name2;
	string Noote;
	public:
	void setNote(string note){
		Noote = note;
	}string getNoote(){
		return Noote;
	}
	void setName2(string name2){
		Name2 = name2;
	}string getName2(){
		return Name2;
	}
	Note(string name, string note, string name2):Diary(name){
		Noote = note;
		Name2 = name2;
	}
	virtual void AskingToWriteNote(string name, string note, string name2){
		cout<<"Enter the name of Your Diary: ";cin>>name2;
		string filename;
		filename = name2 + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file){
			cout<<"Diary name: "<<name2<<endl;
			cout<<"Please input your Note: ";//cin>>note;
			ofstream fileout;
			ifstream filein;
			filein.open(filename.c_str());
			fileout.open(filename.c_str(),std::ios_base::app);
			cin.ignore();
			getline(cin, note);
			//cout<<note<<endl;
			fileout<<""<<note<<endl;
			filein.close();
			fileout.close();
		}
		else if(!file){
			cout<<"You Entered Wrong Diary Name"<<endl;
		}
	}
}; 
class NoteReader:public Diary{
	string Reader1;
	string Name3;
	public:
	void setReader1(string reader1){
		Reader1 = reader1;
	}string getReader1(){
		return Reader1;
	}
	NoteReader(string name, string reader1, string name3):Diary(name){
		Reader1 = reader1;
		Name3 = name3;
	}
	void DiaryNoteReader(string name, string reader1, string name3){
		cout<<"Enter the Name of Your Diary: ";cin>>name3;
		string filename;
		string MyText;
		filename = name3 + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file){
			cout<<"Diary name: "<<name3<<endl;
			cout<<"The Note is: ";
			ifstream read(filename.c_str());
			while (getline (read, MyText)) {
						cout<<MyText<<"\n";}
					}else if(!file) {
						cout<<"No Such Diary Existed";
					}	
	}
	
};
class FeelWrite:public Diary{
	string Feel;
	string Write;
	public:
		void setFeel(string feel){
		Feel = feel;
	}string getFeel(){
		return Feel;
	}
	void setWrite(string write){
		Write = write;
	}string getWrite(){
		return Write;
	}	
	FeelWrite(string name,string feel, string write):Diary(name){
		Feel = feel;
		Write = write;
	}
	virtual void FeelWriting(string name,string feel, string write){
		cout<<"How are You Feeling: ";cin>>feel;
		string filename;
		filename = feel + ".txt";
		ofstream file;
		file.open(filename.c_str());
		file.close();
			ofstream fileout;
			ifstream filein;
			filein.open(filename.c_str());
			fileout.open(filename.c_str(),std::ios_base::app);
			//cout<<note<<endl;
			cout<<"What do You want to Write about it?"<<endl;
			cin.ignore();
			getline(cin, write);
			cout<<write<<endl;
			fileout<<""<<write<<endl;
			filein.close();
			fileout.close();
	}
};
class ReadFeel:public Diary{
	string Read;
	string Feel1;
	public:
		void setRead(string read){
		Read = read;
	}string getRead(){
		return Read;
	}
	void setFeel1(string feel1){
		Feel1 = feel1;
	}string getFeel1(){
		return Feel1;
	}
	ReadFeel(string name, string read, string feel1):Diary(name){
		Read = read;
		Feel1 = feel1;
	}
	virtual void ReadFelt(string name, string read, string feel1){
		cout<<"About which feeling you want to READ about?"<<endl;
		cout<<"Input Feeling: ";cin>>feel1;
		string filename;
		string reader;
		filename = feel1 + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file){
			cout<<"Feeling: "<<feel1<<endl;
			cout<<"You Wrote:\n";
			ifstream read(filename.c_str());
			while (getline (read, reader)) {
						cout<<reader<<"\n";}
					}else if(!file) {
						cout<<"You Haven't Wrote about this FEELING";
					}
		
	}
};
class EditFeel{
	string Feel2;
	string Write2;
	public:
		void setWrite2(string write2){
		Write2 = write2;
	}string getWrite2(){
		return Write2;
	}
	void setFeel2(string feel2){
		Feel2 = feel2;
	}string getFeel2(){
		return Feel2;
	}
	EditFeel(string feel2, string write2){
		Feel2 = feel2;
		Write2 = write2;
	}
	virtual void EditFeeling(string feel2, string write2){
		cout<<"Which FEELING would you Like to Edit?"<<endl;
		cout<<"Input Feeling: ";cin>>feel2;
		string filename;
		filename = feel2 + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file){
			cout<<"FEELING: "<<feel2<<endl;
			cout<<"Please input your Feeling: ";//cin>>note;
			ofstream fileout;
			ifstream filein;
			filein.open(filename.c_str());
			fileout.open(filename.c_str(),std::ios_base::app);
			cin.ignore();
			getline(cin, write2);
			//cout<<note<<endl;
			fileout<<""<<write2<<endl;
			filein.close();
			fileout.close();
		}
		else if(!file){
			cout<<"You Haven't Wrote About this FEELING"<<endl;
		}
		
	}
};
int LoggedInSatus(){
	string username,pass,userid,pass2,filename;
	cout<<"Enter Your Usernmae: "<<username;cin>>username;
	cout<<"Enter Your Password: "<<pass;cin>>pass;
	filename = username + ".txt";
	ifstream file;
	file.open(filename.c_str());
	if(file) {	
		ifstream read(filename.c_str());
		getline (read, userid);
		getline (read, pass2);
			if(username == userid && pass == pass2){	
				return 1;}
			else if(username == userid && pass != pass2){
					return 0;}}
	else if(!file) {
		cout<<"Wrong Username\n";
		return 0;}
}

int main(){
	string name, note;
	int status;
	int Option;
	int option;
	cout<<"1.Registration\n2.Login\n Your Choice: ";cin>> Option;
	if(Option == 1){
		string username,pass,filename;
		cout<<"Select a Usernmae: "<<username;cin>>username;
		cout<<"Select a Password: "<<pass;cin>>pass;
		filename = username + ".txt";
		ofstream file;
		file.open(filename.c_str());//opening File
		file<<"userid = "<<username<<endl<<"pass2 = "<<pass;//Writing File
		file.close();//Closing File
		main();
	}else if(Option == 2){
		status = LoggedInSatus();
		cout<<"Status = "<<status<<endl;
		if(status == 1){
			cout<<"Successfully Logged In!"<<endl;
			cout<<"Welcome To Your Secret & Personal Diary"<<endl;
			cout<<"Choose an Option from Below:"<<endl;
			cout<<"1.Would you like to name the DIARY?"<<endl;
			cout<<"2.Would you like to Write a Note in Your Diary? OR Add to Previous one?\n3.Would You like to see Notes?"<<endl;
			cout<<"4.Would you Like to Write How you are FEELING?\n5.Would you Like to see about something you wrote earlier about feelings?"<<endl;
			cout<<"6.Would like to ADD something in one of Already Writtern FEELING?\nYour Choice: ";
			cin>>option;
			if(option == 1){
				Diary d1("Testing");
				d1.AskNameOfDiary("tested");
			}else if(option == 2){
				Note n1("Test","Testing", "Tested");
				n1.AskingToWriteNote("test","testing","tested");
			}else if(option == 4){
				FeelWrite fw1("Test","Testing","Tested");
				fw1.FeelWriting("test","testing","tested");
			}else if(option == 3){
				NoteReader nr1("Test","Testing","Tested");
				nr1.DiaryNoteReader("test","testing","tested");
			}else if(option == 5){
				ReadFeel rf1("Test","Testing","Tested");
				rf1.ReadFelt("test","testing","tested");
			}else if(option == 6){
				EditFeel ef1("Testing","Tested");
				ef1.EditFeeling("testing","tested");
			}
			return 1;
		}else if(status == 0){
			cout<<"Wrong Password"<<endl;
			cout<<"Failed to Log In"<<endl;
			main();
			return 0;
		}else{
			cout<<"Select the Right Option"<<endl;
			main();
		}
	}else{
		cout<<"Select the Right Option"<<endl;
		main();
	}
}
