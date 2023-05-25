#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;

int main(){
	string phrase1 = "Sfesbhpo!HT671Bejfnvt!Hbnjoh!Tpvoecbs!Tqfblfs";
	string d;
	string e;
	int b[20];
	int c = 0;
    /*for(int j=0;j<a.length();j++){
    	b[c] = a[c];
    	c++;
	}
	for (int i = 0; i < a.length(); i++)
    {
        cout <<b[i]<<endl; 
    }for (int i = 0; i < a.length(); i++)
    {
    	d[i] = b[i] - 1;
    	e = d[i];
        cout <<e; 
    }*/
    /*char phrase2[10000];
    int ascii[100000];
		int count = 0;
		for(int j=0;j<a.length();j++){
    	ascii[count] = a[count];
    	count++;}
    	for (int i = 0; i < a.length(); i++){
        cout <<"The ASCII Values are: "<<ascii[i]<<endl; 
    }
	for (int i = 0; i < a.length(); i++){
    	phrase2[i] = ascii[i] - 1;
    }
    cout<<"This is Phrase 2 Variable:  "<<phrase2<<endl;*/
    ofstream file;
			file.open("Decrypted File.txt");
			if(file){
				char phrase2[10000];
    			int ascii[100000];
				int count = 0;
				for(int j=0;j<phrase1.length();j++){
    				ascii[count] = phrase1[count];
    				count++;}
    			for (int i = 0; i < phrase1.length(); i++){
			        cout <<"The ASCII Values are: "<<ascii[i]<<endl; 
			    }
				for (int i = 0; i < phrase1.length(); i++){
    				phrase2[i] = ascii[i] - 1;
   				}
    	cout<<"This is the Phrase2 Variable: "<<phrase2<<endl;
    	file<<phrase2;
    	file.close();}
	return 0;
}
