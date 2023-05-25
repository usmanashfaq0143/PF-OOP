#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <algorithm>

using namespace std;

void Drawing(int num){
	string Text;
	switch(num){
		case 1:
			{
			ifstream file;
			file.open("Hangman1.txt");
			while(getline(file, Text)){
				cout<<Text<<endl;
			}
			file.close();
			break;}
		case 2:
			{
			ifstream file2;
			file2.open("Hangman2.txt");
			while(getline(file2, Text)){
				cout<<Text<<endl;
			}
			file2.close();
			break;}
		case 3:
			{
			ifstream file3;
			file3.open("Hangman3.txt");
			while(getline(file3, Text)){
				cout<<Text<<endl;
			}
			file3.close();
			break;}
		case 4:
			{
			ifstream file4;
			file4.open("Hangman4.txt");
			while(getline(file4, Text)){
				cout<<Text<<endl;
			}
			file4.close();
			break;}
		case 5:
			{
			ifstream file5;
			file5.open("Hangman5.txt");
			while(getline(file5, Text)){
				cout<<Text<<endl;
			}
			file5.close();
			break;}
		case 6:
			{
			ifstream file6;
			file6.open("Hangman6.txt");
			while(getline(file6, Text)){
				cout<<Text<<endl;
			}
			file6.close();
			break;}
		case 7:
			{
			ifstream file6;
			file6.open("CONGRATULATIONS.txt");
			while(getline(file6, Text)){
				cout<<Text<<endl;
			}
			file6.close();
			break;}
		case 8:
			{
			ifstream file6;
			file6.open("DUMB.txt");
			while(getline(file6, Text)){
				cout<<Text<<endl;
			}
			file6.close();
			break;}
		case 9:
			{
			ifstream file6;
			file6.open("HANGMAN.txt");
			while(getline(file6, Text)){
				cout<<Text<<endl;
			}
			file6.close();
			break;}
	}
}


string GuessWord(int num){
	string a,b,c,d,e,f,g,h,i,j;
	switch(num){
		case 1:
			a = "awais";
			return a;
			break;
		case 2:
			b = "abdullah";
			return b;
			break;
		case 3:
			c = "arfha";
			return c;
			break;
		case 4:
			d = "fahad";
			return d;
			break;
		case 5:
			e = "hamza";
			return e;
			break;
		case 6:
			f = "haroon";
			return f;
			break;
		case 7:
			g = "khadija";
			return g;
			break;
		case 8:
			h = "namra";
			return h;
			break;
		case 9:
			i = "usman";
			return i;
			break;
		case 0:
			j = "zainab";
			return j;
			break;
	}
}

int main(){
	string Word;
	//srand(time(NULL));
    //int number = (rand() % (9 - 0 + 1)) + 0;
    //cout<<number<<endl;
	Word = "fahad";
	int length = Word.length();
	cout<<"The Number of Letter in Word is: "<<length<<endl;
	cout<<"The Word is: "<<Word<<endl;
	int count = 0;
	char user;
	if(length == 5){
		int Guess = 6;
		int j = 1;
		string Hide = "_____";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			count++;
		}else{
			cout<<"Letter is present in Word"<<endl;
			/*if(position == 0){
				Hide[0] = user;
				cout<<Hide<<endl;
			}else if(position == 1){
				Hide[1] = user;
				cout<<Hide<<endl;
			}else if(position == 2){
				Hide[2] = user;
				cout<<Hide<<endl;
			}else if(position == 3){
				Hide[3] = user;
				cout<<Hide<<endl;
			}else if(position == 4){
				Hide[4] = user;
				cout<<Hide<<endl;
			}*/
			if(Hide == Word){
				Drawing(7);
			}
			for(int i =0; i <= length;i++){
				if(Word[i] == user){
					Hide[i] = user;
				}
			}
			}
		}
		
		j++;
		if(count == 1){
			Drawing(1);
		}else if(count == 2){
			Drawing(2);
		}else if(count == 3){
			Drawing(3);
		}else if(count == 4){
			Drawing(4);
		}else if(count == 5){
			Drawing(5);
		}else if(count == 6){
			Drawing(6);
		}if( j == 7){
				Drawing(8);
		}
	}
	/*if(length == 6){
		int j = 1;
		int Guess = 7;
		string Hide = "______";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			count++;
		}else if(position >= 0 && position <= length){
			cout<<"Letter is present in Word"<<endl;
			if(position == 0){
				Hide[0] = user;
				cout<<Hide<<endl;
			}else if(position == 1){
				Hide[1] = user;
			cout<<Hide<<endl;
			}else if(position == 2){
				Hide[2] = user;
				cout<<Hide<<endl;
			}else if(position == 3){
				Hide[3] = user;
				cout<<Hide<<endl;
			}else if(position == 4){
				Hide[4] = user;
				cout<<Hide<<endl;
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}
		}
		j++;
		if(count == 1){
			Drawing(1);
		}else if(count == 2){
			Drawing(2);
		}else if(count == 3){
			Drawing(3);
		}else if(count == 4){
			Drawing(4);
		}else if(count == 5){
			Drawing(5);
		}else if(count == 6){
			Drawing(6);
		}if( j == 8){
				Drawing(8);
			}
	}
	}
	if(length == 7){
		int j = 1;
		int Guess = 8;
		string Hide = "_______";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			count++;
		}else if(position >= 0 && position <= length){
			cout<<"Letter is present in Word"<<endl;
			if(position == 0){
				Hide[0] = user;
				cout<<Hide<<endl;
			}else if(position == 1){
				Hide[1] = user;
				cout<<Hide<<endl;
			}else if(position == 2){
				Hide[2] = user;
				cout<<Hide<<endl;
			}else if(position == 3){
				Hide[3] = user;
				cout<<Hide<<endl;
			}else if(position == 4){
				Hide[4] = user;
				cout<<Hide<<endl;
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}else if(position == 6){
				Hide[6] = user;
				cout<<Hide<<endl;
			}
			
		}
		j++;
		if(count == 1){
			Drawing(1);
		}else if(count == 2){
			Drawing(2);
		}else if(count == 3){
			Drawing(3);
		}else if(count == 4){
			Drawing(4);
		}else if(count == 5){
			Drawing(5);
		}else if(count == 6){
			Drawing(6);
		}if( j == 9){
				Drawing(8);
			}
	}
	}
	if(length == 8){
		int j = 1;
		int Guess = 9;
		string Hide = "________";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			count++;
		}else if(position >= 0 && position <= length){
			cout<<"Letter is present in Word"<<endl;
			if(position == 0){
				Hide[0] = user;
				cout<<Hide<<endl;
			}else if(position == 1){
				Hide[1] = user;
				cout<<Hide<<endl;
			}else if(position == 2){
				Hide[2] = user;
				cout<<Hide<<endl;
			}else if(position == 3){
				Hide[3] = user;
				cout<<Hide<<endl;
			}else if(position == 4){
				Hide[4] = user;
				cout<<Hide<<endl;
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}else if(position == 6){
				Hide[7] = user;
				cout<<Hide<<endl;
			}else if(position == 7){
				Hide[7] = user;
				cout<<Hide<<endl;
			}
			
		}
		j++;
		if(count == 1){
			Drawing(1);
		}else if(count == 2){
			Drawing(2);
		}else if(count == 3){
			Drawing(3);
		}else if(count == 4){
			Drawing(4);
		}else if(count == 5){
			Drawing(5);
		}else if(count == 6){
			Drawing(6);
		}if( j == 10){
				Drawing(8);
			}
	}
	}*/
	return 0;
	
}
