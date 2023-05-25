#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
int main(){
	string phrase2 = "Hloo World";
ofstream fileout;
			fileout.open("Decrypted File.txt");
			if(fileout){
    			fileout<<"Decrpyted Text:\n"<<phrase2<<endl;
    			fileout.close();
				}
    		else if(!fileout){
				cout<<"Fail To Create Decryption File"<<endl;
			}
		return 0;
	}
