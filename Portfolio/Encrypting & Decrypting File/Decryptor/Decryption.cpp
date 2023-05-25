#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>

using namespace std;

class Decryptor{
	protected:
		string Name, Phrase;
	public:
	void setName(string name){
		Name = name;
	}string getName(){
		return Name;
	}
	void setPhrase(string phrase){
		Phrase = phrase;
	}string getPhrase(){
		return Phrase;
	}
	Decryptor(string name, string phrase){
		Name = name;
		Phrase = phrase;
	}
	string phrase1;
	virtual void Reading(string name, string phrase){
		cout<<"Enter the name of File you Want to Decrypt: ";cin>>name;
		string filename;
		filename =name + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file){
			while(getline(file, phrase)){
				phrase1 = phrase1 + phrase;
				file.close();}
		}else if(!file){
			cout<<"File Do Not Exist!"<<endl;
		}
		cout<<"This is the Encrypted Phrase: \n"<<phrase1<<endl;	
		}
		void Decryption(string name, string phrase){
			char phrase2[10000];
    		int ascii[100000];
			int count = 0;
			for(int j=0;j<phrase1.length();j++){
    			ascii[count] = phrase1[count];
    			count++;}
    		/*for (int i = 0; i < phrase1.length(); i++){
			    cout <<"The ASCII Values are: "<<ascii[i]<<endl; 
			}*/
			for (int i = 0; i < phrase1.length(); i++){
    			phrase2[i] = ascii[i] - 1;
   			}
    		cout<<"This is the Decrypted Phrase: "<<phrase2<<endl;
			ofstream fileout;
			fileout.open("DecryptedFile.txt");
			fileout<<phrase2;
			fileout.close();
    }
    
    	void FileReading(string name){
    		string Read;
    	ifstream filein;
		filein.open("DecryptedFile.txt");
		if(filein){
		while(getline(filein, Read)){
			//cout<<Read<<endl;
			cout<<"Decryption Succesfull"<<endl;
			filein.close();}
		}else if(!filein){
			cout<<"Decrypted File Not Found"<<endl;
		}
		//cout<<"This is Read Variable: "<<Read<<endl;
		}
};
int main(){
	Decryptor d1("Test","Testing");
	d1.Reading("test","testing");
	d1.Decryption("test","testing");
	d1.FileReading("test");
	
	
	return 0;
}
