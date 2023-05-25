#include<iostream>
#include<fstream>
#include<string>

using namespace std;


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
	int status;
	int Option;
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
					cout<<status<<endl;
			cout<<"Successfully Logged In!"<<endl;
			return 1;
		}else if(status == 0){
			cout<<"Failed to Log In"<<endl;
			return 0;
		}
	}
}
