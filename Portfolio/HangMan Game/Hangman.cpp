#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>

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
			ifstream file7;
			file7.open("YouWin.txt");
			while(getline(file7, Text)){
				cout<<Text<<endl;
			}
			file7.close();
			break;}
		case 8:
			{
			ifstream file8;
			file8.open("DUMB.txt");
			while(getline(file8, Text)){
				cout<<Text<<endl;
			}
			file8.close();
			break;}
		case 9:
			{
			ifstream file9;
			file9.open("HANGMAN.txt");
			while(getline(file9, Text)){
				cout<<Text<<endl;
			}
			file9.close();
			break;}
        case 10:
			{
			ifstream file10;
			file10.open("Congratulations.txt");
			while(getline(file10, Text)){
				cout<<Text<<endl;
			}
			file10.close();
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
	Drawing(9);
	string Word;
	srand(time(NULL));
    int number = (rand() % (9 - 0 + 1)) + 0;
    //cout<<number<<endl;
	Word = GuessWord(number);
	int length = Word.length();
	cout<<"The Number of Letter in Word is: "<<length<<endl;
	//cout<<"The Word is: "<<Word<<endl;
	char user;
	int count =0;
	if(length == 5){
		int counter = 0;
		int Guess = 15;
		int j = 1;
		string Hide = "_____";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			cout<<Hide<<endl;
			counter+=1;
		}else if(position >= 0 && position <= length){
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
			for(int i =0; i <= length;i++){
				if(Word[i] == user){
					Hide[i] = user;
				}
			}
			cout<<Hide<<endl;
			int count = 0;
			for(int j =1;j<=5;j++){
			if(Word[j] == Hide[j]){
					count++;
				}
		}
        //cout<<"Count = "<<count<<endl;
		if(count == 5){
			Drawing(10);
			Drawing(7);
			break;
			}
		}
		j++;
		if(counter == 1){
			Drawing(1);
		}else if(counter == 2){
			Drawing(2);
		}else if(counter == 3){
			Drawing(3);
		}else if(counter == 4){
			Drawing(4);
		}else if(counter == 5){
			Drawing(5);
		}else if(counter == 6){
			Drawing(6);
			Drawing(8);
			break;
		}
		}
	}
	if(length == 6){
		int j = 1;
		int Guess = 15;
		string Hide = "______";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			cout<<Hide<<endl;
			count++;
		}else if(position >= 0 && position <= length){
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
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}*/
			for(int i =0; i <= length;i++){
				if(Word[i] == user){
					Hide[i] = user;
				}
			}
			cout<<Hide<<endl;
			int counter = 0;
			for(int j =1;j<=6;j++){
			if(Word[j] == Hide[j]){
					counter++;
				}
		}
        //cout<<"Count = "<<counter<<endl;
		if(counter == 6){
			Drawing(10);
			Drawing(7);
			break;
			}
		}
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
			Drawing(8);
			break;
		}
	}
	}
	if(length == 7){
		int j = 1;
		int Guess = 15;
		string Hide = "_______";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			cout<<Hide<<endl;
			count++;
		}else if(position >= 0 && position <= length){
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
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}else if(position == 6){
				Hide[6] = user;
				cout<<Hide<<endl;
			}*/
			for(int i =0; i <= length;i++){
				if(Word[i] == user){
					Hide[i] = user;
				}
			}
			cout<<Hide<<endl;
			int counter = 0;
			for(int j =1;j<=7;j++){
			if(Word[j] == Hide[j]){
					counter++;
				}
		}
        //cout<<"Count = "<<counter<<endl;
		if(counter == 7){
			Drawing(10);
			Drawing(7);
			break;
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
			Drawing(8);
			break;
		}
	}
	}
	if(length == 8){
		int j = 1;
		int Guess = 15;
		string Hide = "________";
		for(int i = 0; i < Guess; i++){
		cout<<"Guess a Letter: ";cin>>user;
		int position = Word.find(user);
		cout<<"Positon = "<<position<<endl;
		if(position == -1){
			cout<<"This Letter is Not Present in Word"<<endl;
			cout<<Hide<<endl;
			count++;
		}else if(position >= 0 && position <= length){
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
			}else if(position == 5){
				Hide[5] = user;
				cout<<Hide<<endl;
			}else if(position == 6){
				Hide[7] = user;
				cout<<Hide<<endl;
			}else if(position == 7){
				Hide[7] = user;
				cout<<Hide<<endl;
			}*/
			for(int i =0; i <= length;i++){
				if(Word[i] == user){
					Hide[i] = user;
				}
			}
			cout<<Hide<<endl;
			int count = 0;
			for(int j =1;j<=8;j++){
			if(Word[j] == Hide[j]){
					count++;
				}
		}
        //cout<<"Count = "<<count<<endl;
		if(count == 8){
			Drawing(10);
			Drawing(7);
			break;
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
			Drawing(8);
			break;
		}
	}
	}
	return 0;
}
