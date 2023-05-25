#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

class File{
	protected:
		string Name, Text;
	public:
		string filename,MyText;
	void setName(string name){
		Name = name;
	}string getName(){
		return Name;
	}
	void setText(string text){
		Text = text;
	}string getText(){
		return Text;
	}
	File(string name, string text){
		Name = name;
		Text = text;
	}
	void FileReader(string name, string text,string Filename){ 
		cout<<"Enter the Name of File: ";cin>>name;
	filename = name +".txt";
	ofstream fileout;
	ifstream file;
	fileout.open("TEMP.txt",std::ios_base::app);
	file.open(filename.c_str());
	if(file && fileout){
		ifstream read(filename.c_str());
		while(getline(read, Text)){
			fileout<<""<<Text<<endl;
		}
		file.close();
		fileout.close();
	}else if(!file){
		cout<<"File do NOT Exist"<<endl;
	}
	}	

	/*void FileCreator(string name, string text,string Filename,string MyText){
		ofstream fileout;
		ifstream filein;
		fileout.open("TEMP.txt",std::ios_base::app);
		filein.open(filename.c_str());
		if(fileout){
			while(getline(filein, Text)){
			}
		fileout<<""<<Text<<endl;
		filein.close();
		fileout.close();
		cout<<"This is Text Variable : "<<Text<<endl;
		}
		else if(!fileout){
			cout<<"ERROR Creating File"<<endl;
		}
	}*/
	};
class Encryptor:public File{
	public:
		string phrase[100], phrase1, phrase3, reader;
		char phrase2[10000];
		int count1 = 0;
	Encryptor(string name, string text):File(name, text){
	}
	void Encryption(string name, string phrase){
		ofstream fileout;
		ifstream filein;
		fileout.open("EncryptedFile.txt");
		filein.open("TEMP.txt");
		while(getline(filein, phrase)){
			phrase1 = phrase1 + "\n" + phrase;
		}//DecryptedFile
		cout<<"The Phrase in Your File:"<<phrase1<<endl;
		/*while(getline(filein, phrase)){
        	count1++;
			}
			cout<<"Number of Lines in File = "<<count1<<endl;*/ // Lines Counter in File
		int ascii[100000];
		int count = 0;
		for(int j=0;j<phrase1.length();j++){
    	ascii[count] = phrase1[count];
    	count++;
	}for (int i = 0; i < phrase1.length(); i++){
    	phrase2[i] = ascii[i] + 1;
    }
		fileout<<""<<phrase2<<endl;
		fileout.close();
		filein.close();
		ifstream file;
		file.open("EncryptedFile.txt");
		while(getline(file, phrase3)){
			cout<<"The Encrpyted Phrase: \n"<<phrase3<<endl;
			cout<<"Encryption Succesfull"<<endl;
		}
		file.close();
	}
};
int main(){
	File f1("Testing", "Tested");
	f1.FileReader("test","testing", "tested");
	//f1.FileCreator("test","testing", "tested","t");
	string e0,e00;
	Encryptor e1("Testing", "Tested");
	e1.Encryption("testing", "tested");
	return 0;
}
