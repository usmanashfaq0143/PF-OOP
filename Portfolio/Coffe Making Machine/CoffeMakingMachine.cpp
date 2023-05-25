#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void Drawing(int num){
	string Text;
	switch(num){
		case 1:
			{
			ifstream file;
			file.open("Coffe.txt");
			while(getline(file, Text)){
				cout<<Text<<endl;
			}
			file.close();
			break;}
		case 2:
			{
			ifstream file2;
			file2.open("CoffeMachine.txt");
			while(getline(file2, Text)){
				cout<<Text<<endl;
			}
			file2.close();
			break;}
		case 3:
			{
			ifstream file3;
			file3.open("Sad.txt");
			while(getline(file3, Text)){
				cout<<Text<<endl;
			}
			file3.close();
			break;}
		case 4:
			{
			ifstream file4;
			file4.open("Sun.txt");
			while(getline(file4, Text)){
				cout<<Text<<endl;
			}
			file4.close();
			break;}
		}
	}	
int AskingCoffeeChoice(string name){
		int user;
		cout<<"We Have 3 Kinds of Coffee Which are:\n1.Espresso\n2.Latte\n3.Cappuccino"<<endl;
		cout<<"What would You like to take?\nYour Choice: "<<endl;cin>>user;
		return user;
}
int CurrencySystem(int num){
	int user1;
	int user2;
	int user3;
	int total;
	int RequiredCurrency = 100;
	cout<<"Plz Insert Money Only in form of Paper(No Coins)"<<endl;
	cout<<"How many 10's would you like to give: ";cin>>user1;
	cout<<"How many 50's would you like to give: ";cin>>user2;
	cout<<"How many 100's would you like to give: ";cin>>user3;
	total = 10*user1 + 50*user2 + 100*user3;
	if(total >= RequiredCurrency){
		if(total > RequiredCurrency){
			total = total - RequiredCurrency;
			cout<<"Here's Your Change = "<<total<<" Rs"<<endl;
		}
		cout<<"Transaction Succesfull"<<endl;
		cout<<"Enjouy Your Coffee"<<endl;
		Drawing(1);
		return 1;
	}else if(total < RequiredCurrency){
		cout<<"Sorry You have Insufficent Funds"<<endl;
		Drawing(3);
		return 0;
	}
}
void ELC(int num){
	if(num == 1){
		cout<<"You Chose Espresso"<<endl;
	}else if(num == 2){
		cout<<"You Chose Latte"<<endl;
	}else if(num == 3){
		cout<<"You Chose Cappuccino"<<endl;
	}
		int ResultMilk = 200;
		int ResultWater = 200;
		int ResultCoffee = 100;
		int Water = 200;
		int Coffee = 100; 
		int Milk = 200;
		int RequiredWater = 50;
		int RequiredCoffee = 10;
		int RequiredMilk = 40;
		for(int i =0; i<=ResultWater;i++){
			if(i > 0){
				int user;
			cout<<"We Have 3 Kinds of Coffee Which are:\n1.Espresso\n2.Latte\n3.Cappuccino\n4.Report of Ingridients"<<endl;
			cout<<"What would You like to take?\nYour Choice: ";cin>>user;
			if(user == 1){
				cout<<"You Chose Espresso"<<endl;
			}else if(user == 2){
				cout<<"You Chose Latte"<<endl;
			}else if(user == 3){
				cout<<"You Chose Cappuccino"<<endl;
			}else if(user == 4){
			cout<<"You Chose Report"<<endl;
			cout<<"REPORT AT THE END OF DAY\n"<<endl;
	cout<<"Total Water at Start of Day = "<<Water<<" ml"<<endl;
	cout<<"Total Coffee at Start of Day = "<<Coffee<<" grams"<<endl;
	cout<<"Total Milk at Start of Day = "<<Milk<<" ml"<<endl;
	cout<<"Water Left = "<<ResultWater<<" ml"<<endl;
	cout<<"Coffee Left = "<<ResultCoffee<<" grams"<<endl;
	cout<<"Milk Left = "<<ResultMilk<<" ml"<<endl;
	cout<<"STARTING NEW DAY"<<endl;
	Drawing(4);
	break;
		}
		}
		if(Water >=RequiredWater){
			ResultWater -= RequiredWater;
			cout<<"Water Left = "<<ResultWater<< " ml"<<endl;
			if(Coffee >= RequiredCoffee){
					ResultCoffee -= RequiredCoffee;
					cout<<"Coffee Left = "<<ResultCoffee<<" grams"<<endl;
				}if(Milk >= RequiredMilk){
					ResultMilk -= RequiredMilk;
					cout<<"Milk Left = "<<ResultMilk<<" ml"<<endl;
				}
				if(ResultWater < RequiredWater){
			cout<<"Not Enough Water"<<endl;
			Drawing(3);
			break;
		}else if(Coffee < RequiredCoffee){
			cout<<"Not Enough Coffee"<<endl;
			Drawing(3);
			break;
		}else if(Milk < RequiredMilk){
			cout<<"Not Enough Milk"<<endl;
			Drawing(3);
			break;
		}
				int value = CurrencySystem(1);	
			}
		}
		//int num1, int num2, int num3, int num4, int num5, int num6
		//ResultWater, ResultCoffee,ResultMilk,Water,Coffee, Milk
		
	}

int main(){
	Drawing(2);
	int status;
	int option;
	cout<<"What would you like to do?\n1.ON the Machine\n2.OFF the Machine\nYour Choice(1 or 2): ";cin>>option;
	if(option == 2){
		cout<<"Machine Turned OFF"<<endl;
	}else if(option == 1){
		status = AskingCoffeeChoice("test");
		if(status == 1){
			ELC(status);
			main();
		}else if(status == 2){
			ELC(status);
			main();
		}else if(status == 3){
			ELC(status);
			main();
		}
		
	}
}
