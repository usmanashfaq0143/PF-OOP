#include <iostream>
using namespace std;
using std::string;
/*OOP Topics Covered
1. Classes
2.Objects
3.Access Modifiers 
3.0 They are of 3 types 
3.1 Private(By Default) 
3.2 Public 
3.3 Protected(Between Private and Public) related to Inheritance
4.Constructors
4.1 3 Rules for Constructor
4.2 1. It does Not have a return type
4.3 2. Its Name will be same as Class
4.4 3. It must be Public Attribute
4.5 4. Its Parameters will be the members of Class defined by us that is the variable which is equal to that particular member 
EXTRA
5. Method
5.1 Method is how the members in class will print its a shortcut to writting again and again cout 
5.2 ITs a Function inside the Class
	****4 MOST Important Pillars of OOP****
5. Encapsulation 
5.1 i.e Bundling or combinig data together in a Class
5.2 Setters and Getters
5.3 In Encapsulation data is in Private access modifier but access through method known as  Setter/Getter
    It help us modify data and use it outside the class.
6.Abstraction
6.1 Hiding a complex code behind a simpler code for user
6.2 Making Abstract Class, its more of a like  contract when signed by any other class it will be obligatory to do implementation
6.3 Making the fucntion in Abstract Class Obligatory by using Virtual.
6.4 Implementing code in Other class which signed the Abstract Class. 
7. Inheritance
7.1 It is method in which A derive class or child Class INHERIT whole class from Parent or Base class
7.2 First make derived class and inherit parent class
7.3 Make your new class constructor and inherit constructor for the parent members
7.4 Make your class method which will give the output
7.5 Protected Modifiers are use in base Class to Use the members directly by the Inherit class or Derive Class
7.6 For the Access of Abstract class of Function such As AskForNewCar is we have to make the by defualt Private Parent Class to Public 
7.7 IT can be done by adding public behind the Parent class when inheriting 
8. Polymorphism
8.1 Polymorphism means "many forms"
8.2 Parent Class refrence is used to refer to a Child Object
8.3 U use refrence(POINTER???????) u gave a Parent pointer refrence to Obejct of Child class
8.4 Using polymorphism to make many forms of single Function or Method in classes 
8.5 Without Refrence By Default the Specific class function will be used other than Parent But when using refrence of Parent it will use the Parent Function
8.6 To use the Class specified Function we use Parent Function as Virtual Function 
8.7 Virtual Function means that it will check if the same function is present in other class if YES then it will excecute it And if NO then Parent Function

*/
class AbstractCar{//ABSTRACT CLASS
	virtual void AskForNewCar()=0;//Making it obligatory i.e  whenver use function it is must situation to do implementation
};



class Car:AbstractCar{//POINT 6. Class signing Abstract Class 
	private://access Modifier Type 1 i.e by default private
		string Model;
		int Year;
	protected://access Modifier no. 3 i.e use in Inheritance to access member directly other than getName()
		string Name;
	public:// access modifier no. 2 i.e public which can be accessed outside class
		void setName(string name){//Setters
			Name = name;
		}string getName(){//getter
			return Name;
		}
		
		void setYear(int year){//setter
			if(year>15)
			Year = year;
		}int getYear(){//getter
			return Year;
		}
		void setModel(string model){//setter
			Model = model;
		}string getModel(){//getter
			return Model;
		}

void CarDescription(){//Function to print out detials of a car(Better than to type whole thing in cout) AKA Method
	cout<<"Name: "<< Name << endl;
	cout<<"Model: "<< Model << endl;
	cout<<"Year: "<< Year << endl;
}

Car(string name,string model,int year){//Constructor defined by us 
	Name = name;
	Model = model;
	Year = year;
}
void AskForNewCar(){//Implementation of Function of Abstract Class or Contract that above Class signed 
	if (Year>20)
	cout<<"You can buy this "<<Name<<" Car"<<endl;
	else
	cout<<"Nah You can't buy this "<< Name<<" Car"<<endl;
}
virtual void CarReview(){//1st FORM of CarReview //Using Virtual coz see 8.7
	cout<<Name<<" is a good Car"<<endl;
}
};



class ElectricCar:public Car{//The Derived class inherit all the code from Parent Class i.e Car // Public behind parent class to access its Functions such as AskForNewCar By default they Are Private and unable to access
	// now constructor of this Derived Class // It can also inherit the Constructor but within its own constructor
	public:
		string BatteryStatus;
			ElectricCar(string name, string model,int year,string batteryStatus):Car(name,model,year){// It have its own constructor for its member only the other members constructor is inherited from Parent Class
		BatteryStatus = batteryStatus;
	}
		//Method for this Class
		void CarDescribe(){
			//cout<<getName()<<" Battery is "<<BatteryStatus<<endl;  //It uses getName() when the members of Above class is Private
			cout<<Name<<" Battery is "<<BatteryStatus<<endl; // You can access directly when the member is inside Protected MOdifier
	}
	void CarReview(){//2nd FORM of CarReview Function
	cout<<Name<<" is a Great Car"<<endl;
}
		
};



class EngineType:public Car{//Second Derived clas inheriting from Parent Class
public:
	string Engine;
	EngineType(string name, string model,int year,string engine):Car(name,model,year){//Constructor For Second DeriveClass
		Engine = engine;
	}
	void CarDescription2(){
		cout<<"The Car "<<Name<<" have a "<<Engine<<" in it"<<endl;
	}
	void CarReview(){//3rd FORM of CarReview Function
	cout<<Name<<" is a Greatest Car"<<endl;
	}
};



int main(){
	//Basic CLass CONSTRUCTOR FUNCTION OUTPUTS also using in ABSTRACTION OUTPUT ONLY OBJECT AREA
	/*Car car1("Honda", "Civic", 21);//using constructor
	car1.CarDescription();//calling function
	Car car2("Toyota", "Grande", 19);
	car2.CarDescription();*/
	
	
	//ENCAPSULATION GETTERS SETTERS OUPUTS For this u have to remove Comments from OBJECTS IN MAIN FUNCTION I.E car1
	/*car1.setYear(14);//using Setter to set new Year 
	cout<<car1.getName()<<" is "<<car1.getYear()<<" Year Model"<<endl;//calling by cout*/ // Had to add comment to check the Abstract Class POINT 6 
	
	
	
	
	//ABSTRACTION OUTPUTS for this remove upper Comments of Objects
	/*car1.AskForNewCar();//Checking wether the contract signed is working and YES it is
	car2.AskForNewCar();*/
	
	
	
	//INHERITANCE OUTPUTS
	ElectricCar e("Tesla", "Model X", 21, "Full");//Derived Class Constructor
	//e.CarDescribe();//Derived Method
	//e.AskForNewCar();//using the inherited method or inherited Abstract class from parent class by making it public when inheriting(By Default it is Private you cant access its functions)
	
	EngineType t("Tesla", "Model X", 21, "Electric Engine");
	//t.CarDescription2();
	//t.AskForNewCar();
	
	
	
	//OUTPUTS FOR POLYMORPHISM U Need to Remove COmments from Inheritance Output(just Object ones)
	//e.CarReview();
	//t.CarReview();
	Car *c1 = &e;//Parent Class refrence is used to refer to a Child Object
	Car *c2 = &t;
	c1->CarReview();//Parent Class refrence is used to refer to a Child Object
	c2->CarReview();
	return 0;
}
