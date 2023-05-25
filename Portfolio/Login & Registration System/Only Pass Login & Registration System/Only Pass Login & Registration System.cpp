#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int LoggedInSatus(){
	string pass,pass2,filename;
	cout<<"Enter Your Password: "<<pass;cin>>pass;
	filename ="Wrong.txt";
	ifstream file;
	file.open(filename.c_str());
	ifstream read(filename.c_str());
	getline (read, pass2);
	if(pass == pass2){	
		return 1;}
	else if(pass != pass2){
		cout<<"Wrong Password\n";
		return 0;}
}

int main(){
	int status;
	int Option;
	cout<<"1.Registration\n2.Login\n Your Choice: ";cin>> Option;
	if(Option == 1){
		string pass,filename;
		cout<<"Select a Password: "<<pass;cin>>pass;
		filename ="Wrong.txt";
		ofstream file;
		file.open(filename.c_str());//opening File
		file<<pass;//Writing File
		file.close();//Closing File
		main();
	}else if(Option == 2){
		status = LoggedInSatus();
		cout<<"Status = "<<status<<endl;
		if(status == 1){
			cout<<"Successfully Logged In!"<<endl;
			return 1;
		}else if(status == 0){
			cout<<"Failed to Log In"<<endl;
			return 0;
		}
	}else{
		cout<<"Select the Right Option"<<endl;
	}
}
