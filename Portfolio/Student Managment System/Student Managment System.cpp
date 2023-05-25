#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
	private:
		string Name;
		int Age;
		int Marks;
	public:
		void setName(string name){
			Name = name;
		}string getName(){
			return Name;
		}
		
		void setAge(int age){
			Age = age;
		}int getAge(){
			return Age;
		}
		
		void setMarks(int marks){
			Marks = marks;
		}int getMarks(){
			return Marks;
		}
		
		Student(string name, int age, int marks){
			Name = name;
			Age = age;
			Marks = marks;
		}
		void AskForStudentName(string name){
			cout<<"Enter the Student Name: ";cin>>name;
		}void AskForStudentAge(int age){
			cout<<"Enter the Student Age: ";cin>>age;
		}void AskForStudentMarks(int marks){
			cout<<"Enter the Student Latest Marks: ";cin>>marks;
		}
	virtual	void StudentEnrollment(string name,int age ,int marks){
		cout<<"Enter the Student Name: ";cin>>name;
		cout<<"Enter the Student Age: ";cin>>age;
		cout<<"Enter the Student Latest Marks(in Percentage): ";cin>>marks;
			string filename;
			filename = name + ".txt";
			ofstream file;
			file.open(filename.c_str());
			file<<"The Student Name is "<<name<<endl<<"The Student Age is "<<age<<endl<<"The Student Marks is "<<marks<<"%"<<endl;
			file.close();
}

};

class StudentReport:public Student{	
	int Position;
	string Behaviour;
	string ClassParticipation;
	public:
		void setBehaviour(string behaviour){
			Behaviour = behaviour;
		}string getBehaviour(){
			return Behaviour;
		}
		void setClassParticipation(string classParticipation){
			ClassParticipation = classParticipation;
		}string getClassParticipation(){
			return ClassParticipation;
		}
		void setPosition(int position){
			Position = position;
		}int getPosition(){
			return Position;
		}
		
		StudentReport(string name, int age, int marks,int position,string behaviour, string classParticipation):Student(name,age, marks){
			Position = position;
			Behaviour = behaviour;
			ClassParticipation = classParticipation;
		}
		virtual void StudentClassReport(string name, int age, int marks,int position,string behaviour, string classParticipation){
		cout<<"Enter the Student Name: ";cin>>name;
		cout<<"Enter the Student Age: ";cin>>age;
		cout<<"Enter the Student Latest Marks(in Percentage): ";cin>>marks;
		cout<<"Enter the Student Position in Class: ";cin>>position;
		cout<<"Enter the Student Behaviour in Class: ";cin>>behaviour;
		cout<<"Enter the Student Class Participation: ";cin>>classParticipation;
			string filename;
			filename = name + ".txt";
			ofstream file;
			file.open(filename.c_str());
			file<<"The Student Name is "<<name<<endl<<"The Student Age is "<<age<<endl<<"The Student Marks is "<<marks<<"%"<<endl<<"The Student Position is "<<position<<endl<<"The Student Behaviour in Class is "<<behaviour<<endl<<"The Student Class Participation is "<<classParticipation<<endl;
			file.close();
		}
		
		
		
};

class EnrollmentReader:public Student{
	public:
	string Namechecker;
	void setNameChecker(string nameChecker){
			Namechecker = nameChecker;
		}string getNamechecker(){
			return Namechecker;
		}
	EnrollmentReader(string name, int age, int marks,string nameChecker):Student(name,age,marks){
		Namechecker = nameChecker;
	}
	virtual void StudentEnrollmentReader(string name){
		string myText;
		cout<<"Enter the Student Name: ";cin>>name;
		string filename;
		filename = name + ".txt";
				ifstream file;
				file.open(filename.c_str());
				if(file) {	
					ifstream read(filename.c_str());
					while (getline (read, myText)) {
						cout<<myText<<"\n";}
					}else if(!file) {
						cout<<"file doesn't exist";
					}
		/*ifstream read(filename.c_str());
		while (getline (read, myText)) {
			cout<<myText<<"\n";
	}*/
}
};

class ReportReader:public Student{
	public:
		string ReportChecker;
		void setReportChecker(string reportChecker){
			ReportChecker = reportChecker;
		}string getReportChecker(){
			return ReportChecker;
		}
	ReportReader(string name, int age, int marks,string reportChecker):Student(name,age,marks){
		ReportChecker = reportChecker;
	}
	virtual void ReportReading(string name){
		string myText;
		cout<<"Enter the Student Name whose Report you want to check: ";cin>>name;
		string filename;
		filename = name + ".txt";
		ifstream file;
		file.open(filename.c_str());
		if(file) {
			ifstream read(filename.c_str());
			while (getline (read, myText)) {
			cout<<myText<<"\n";}
			}else if(!file) {
				cout<<"file doesn't exist";
			}
		/*ifstream read(filename.c_str());
		while (getline (read, myText)) {
			cout<<myText<<"\n";
	}*/
}
};

int main(){
	string name, behaviour, classParticipation, myText;
	int age , marks, position;
	Student s1("Testing", 0 , 1);
	StudentReport r1("testing", 0, 1, 2,"okay", "good");
	EnrollmentReader e1("testing", 0,1,"good");
	ReportReader r2("testing", 0,1,"good");
	Student *s2 = &r1;
	int Option;
	cout<<"Welcome to STUDENT MANAGMENT SYSTEM"<<endl;
	cout<<"Choose an Option from Below:"<<endl;
	cout<<"1.Student Enrollment\n2.Making Student Report\n3.Do you want to check an Enrollment?\n4.Do you want to check a Student Report?\n Select Your Choice: ";cin>>Option;
	if(Option == 1){
		/*cout<<"Enter the Student Name: ";cin>>name;
		cout<<"Enter the Student Age: ";cin>>age;
		cout<<"Enter the Student Latest Marks: ";cin>>marks;
			string filename;
			filename = name + ".txt";
			ofstream file;
			file.open(filename.c_str());
			file<<name<<endl<<age<<endl<<marks<<endl;
			file.close();
			main();*/
			s1.StudentEnrollment(name, age,marks);
			
		
	}else if(Option == 2){
		/*cout<<"Enter the Student Name: ";cin>>name;
		cout<<"Enter the Student Age: ";cin>>age;
		cout<<"Enter the Student Latest Marks: ";cin>>marks;
		cout<<"Enter the Student Position in Class: ";cin>>position;
		cout<<"Enter the Student Behaviour in Class: ";cin>>behaviour;
		cout<<"Enter the Student Class Participation: ";cin>>classParticipation;
			string filename;
			filename = name + ".txt";
			ofstream file;
			file.open(filename.c_str());
			file<<"The Student Name is "<<name<<endl<<"The Student Age is "<<age<<endl<<"The Student Marks is "<<marks<<endl<<"The Student Position is "<<position<<endl<<"The Student Behaviour in Class is "<<behaviour<<endl<<"The Student Class Participation is "<<classParticipation<<endl;
			file.close();
			main();*/
			r1.StudentClassReport(name,age,marks,position,behaviour,classParticipation);
	}else if(Option == 3){
		/*cout<<"Enter the Student Name: ";cin>>name;
		string filename;
		filename = name + ".txt";
		ifstream read(filename.c_str());
		while (getline (read, myText)) {
			cout<<myText;
	}*/
	e1.StudentEnrollmentReader(name);
	}else if(Option == 4){
		/*cout<<"Enter the Student Name whose Report you want to check: ";cin>>name;
		string filename;
		filename = name + ".txt";
		ifstream read(filename.c_str());
		while (getline (read, myText)) {
			cout<<myText;
	}*/
	r2.ReportReading(name);
	}else{
		cout<<"Plz input right Option"<<endl;
	}
}

