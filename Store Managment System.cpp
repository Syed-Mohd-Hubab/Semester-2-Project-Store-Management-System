
#include <windows.h>
#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

void closer()
{
	system("cls");
	system("color AF");
    Sleep(200);
    system("color BF");
    Sleep(200);                   
    system("color CF");
    Sleep(200);
    system("color DF");
    Sleep(200);
    system("color EF");
    Sleep(200);
    system("color 6F");
    Sleep(200);
    system("color 0F");
    Sleep(200);
    system("color 6");
	printf("\n\n\t\t\t\t Thank You !!!\n\n\n\n\n");
    exit(0);	
}

ifstream fin;
ofstream fout;

void callstockfn(char i);
void menu();

class stock{
	private:
		string sname; int quantity;	float price;
	public:
		string getsnm()
		{	return sname;	}
		int getqt()
		{	return quantity;	}
		float getpr()
		{	return price;	}  
		
		void setdata()
		{
			cout<<"\n\n\n\t\tEnter Product's Name:";
			cin>>sname;
			cin.ignore();
			cout<<"\n\n\n\t\tEnter quantity:";
			cin>>quantity;
			cout<<"\n\n\n\t\tEnter price:";
			cin>>price;
		}
		void read()
		{	fin>>sname;		fin>>quantity;		fin>>price;		}	
		void write()
		{	fout<<sname<<" ";	fout<<quantity<<" ";	fout<<price<<"\n";	}
		void addnew();
		void removepro();
		void show();
		void addstock();
		void displaypro();    
		void buy();
};

void stock::displaypro()
{	cout<<"\n\t\t\t  "<<sname<<"\t\t"<<quantity<<"\t\t\t"<<price;		}
void stock::addnew()
{
	system("cls");
	setdata();
	fout.open("stock1.txt", ios::app);
	write();
	fout.close();
    cout<<"\n\n\t\t PRODUCT ADDED !!!";
    cin.get();
    cin.get();
}

void stock::removepro()
{
	system("cls");
	int i=0;
    string findthis;
    cout<<"\n\t\t\t\t REMOVE STOCK ";
    cout<<"\n\nEnter the name of the product:";
    cin>>findthis;
    fout.open("tempstock.txt");
    fin.open("stock1.txt");
    while(!fin.eof())
    {
    read();
	if(!fin.eof())
	if(sname==findthis)
    {
    	cout<<"\n\n\t\t\t PRODUCT REMOVED";
		cout<<"\n\n\t\t\tName:"<<sname<<"\n\n\t\t\tQuantity:"<<quantity<<"\n\n\t\t\tPrice:"<<price<<endl;
		i++;
    }
    else
    write();
    }
    if(i==0)
	cout<<"\n\n   PRODUCT NOT FOUND !!!";
    fin.close();
    fout.close();
    remove("stock1.txt");
    rename("tempstock.txt","stock1.txt");
	cin.get();
	cin.get();
}

void stock::show()
{
	int i=1;
	system("cls");
	cout<<"\n\t\t_________________________________________________________________________";
	cout<<"\n\n\t\t_________________________   List Of Products   _________________________";
	cout<<"\n\n\t\t_________________________________________________________________________\n";
	cout<<"\n\n\t\t\t  NAME\t\t\t QUANTITY\t\t PRICE";
	fin.open("stock1.txt");
    while(!fin.eof())
    {	
		read();
	 	if(!fin.eof())
	 	{
	    if(fin.tellg()<0)	{	i=0; break;		}
	  	displaypro();
	  	}
    }
 	
    if(i==0)
    {	
		cout<<"\n\n\t\t\t EMPTY RECORD ROOM !!!";
		cin.get();
    }
    fin.close();
	cout<<"\n\n\t\t_________________________________________________________________________\n";
	cin.get();
	cin.get();
}

void stock::addstock()
{
	system("cls");
	int i=0;
    string findthis;	int quan;	float pri;
    cout<<"\n\t\t\t\t UPDATE STOCK";
    cout<<"\n\nEnter the name of the product whose stock you want to update:";
    cin>>findthis;
    fout.open("tempstock.txt");
    fin.open("stock1.txt");
    while(!fin.eof())
    {
    read();
	if(!fin.eof())
	if(sname==findthis)
    {
    	cout<<"Enter new quantity and price:";
    	cin>>quan>>pri;
    	cout<<"\n\n\t\t\t UPDATING  PRODUCT...";
		cout<<"\n\n\t\t\tName:"<<sname<<"\n\n\t\t\tQuantity:"<<quantity<<"\n\n\t\t\tPrice:"<<price<<endl;
		quantity=quan;	price=pri;
		write();
		cout<<"\n\n\t\t\t PRODUCT UPDATED !!!";
		cout<<"\n\n\t\t\tName:"<<sname<<"\n\n\t\t\tQuantity:"<<quantity<<"\n\n\t\t\tPrice:"<<price<<endl;
		i++;
    }
    else
    write();
    }
    if(i==0)
	cout<<"\n\n   PRODUCT NOT FOUND !!!";
    fin.close();
    fout.close();
    remove("stock1.txt");
    rename("tempstock.txt","stock1.txt");
	cin.get();
	cin.get();
}
void stock::buy()
{
	system("cls");
	int i=0;
    string findthis;	int quan;	float pri;
    cout<<"\n\t\t\t\t BUY ITEMS ";
    cout<<"\n\n Enter the name of the product:";
    cin>>findthis;
    fout.open("tempstock.txt");
    fin.open("stock1.txt");
    while(!fin.eof())
    {
    read();
	if(!fin.eof())
	if(sname==findthis)
    {
    	i++;
    	cout<<"\n Enter quantity:";
    	cin>>quan;
    	if(quantity>=quan)
    	{
		quantity=quantity-quan;
		pri=price*quan;
		write();
		cout<<"\n\n\t\t\t -< RECIEPT >-";
		cout<<"\n\n\t\t\tName:"<<sname<<"\n\n\t\t\tQuantity:"<<quan<<"\n\n\t\t\tPrice:"<<pri<<endl;
		}
		else
		{
			cout<<"\t\t SORRY...Insufficient quantity !!!";
			write();
		}
    }
    else
    write();
    }
    if(i==0)
	cout<<"\n\n   PRODUCT NOT FOUND !!!";
    fin.close();
    fout.close();
    remove("stock1.txt");
    rename("tempstock.txt","stock1.txt");
	cin.get();
	cin.get();
}

void customermenu()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t CUSTOMER MENU";
	cout<<"\n\n\t\t\t\t\t   1. Show Products List\n\n\t\t\t\t\t   2. Buy Item\n\n\t\t\t\t\t   3. Go Back\n\n\t\t\t\t\t   4. Exit ";
	char i;
	cout<<"\n\t\t\t\t\tEnter:";		cin>>i;
	if(i=='1')
	{
		stock s;
		s.show();
		customermenu();
	}
	else if(i=='2')
	{
		stock s;
		s.buy();
		customermenu();
	}
	else if(i=='3')
	{
		menu();
	}
	else if(i=='4')
	{
		closer();
	}
	else
	{
		cout<<"\n\n\t\t WRONG KEY PRESSED !!!";
		cin.get();
		cin.get();
		customermenu();
	}
}

class workersdata{
	private:
		string username,password,NAME;
	public:
		workersdata(string u,string p,string n)
		{
			username=u;
			password=p;
			NAME=n;
		}
		string getus()
		{	return username;	}
		string getpw()
		{	return password;	}
		string getnm()
		{	return NAME;		}
		
		void setupn(string u,string p,string fn, string ln)
		{
			username=u;
			password=p;
			NAME=fn+" "+ln;
		}
		void setdata()
		{
			cout<<"\n\n\n\t\t Enter Username:";
			cin>>username;
			cout<<"\n\n\n\t\t Enter Password:";
			cin>>password;
			fflush(stdin);
			cout<<"\n\n\n\t\t Enter Name:";
			getline(cin,NAME);
		}
};
class boss:public workersdata
{
	public:
		boss():workersdata("labuser","lab6","Ali & Hubab")	{};
		void bossmenu();
		void bosslogin();
		void addemployee();
		void removeemployee();
		void employeelist();
		void employeesection();
};

class employee:public workersdata
{
	private:
		string id;
	public:
		employee():workersdata("","",""){
		id="";
		}

		bool checker(string name);
		void displayacc();
		void employeelogin();
		void employeemenu();
		void read()
		{
			string u,p,fn,ln;
			fin>>u;		fin>>p;		fin>>fn; fin >> ln ;		fin>>id;
			setupn(u,p,fn,ln);	
		}
		
		void write()
		{
			string u,p,n;
			u=getus();	p=getpw();	n=getnm();
			
			fout<<u<<" ";	fout<<p<<" ";	fout<<n<<" ";	fout<<id<<"\n";
		}
		void setdata()
		{
			system("cls");
			cout<<"\n\n\n\t\t Enter employee ID:";
			cin>>id;
			workersdata::setdata();
		}
};
bool employee::checker(string usrname)
{
	string u;
	u=getus();
	if(usrname==u)
	return 0;
	else
	return 1;
}
void employee::displayacc()
{
	string u,n,p;
	u=getus();	p=getpw();	n=getnm();
	cout<<"\n\t\t  "<<u<<"\t\t\t  "<<p<<"\t\t  "<<n<<"\t\t  "<<id;
}
void employee::employeelogin()
{
	string name,pass,u,p;	static	int i=1;
	system("cls");
	cin.ignore();
	if(i<=4)
	{
	cout<<"\n\n\t\t\t Enter employee username:";
	cin>>name;
	cout<<"\n\n\t\t\t Enter employee password:";
	cin>>pass;
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t TOO MANY WRONG ATTEMPTS !!!";
		exit(0);
	}
	fin.open("emp1.txt");
	
	while(!fin.eof())
	{
		read();
		u=getus();	p=getpw();
		if(name==u && p==pass)
		{
			cout<<"\n\n Signed in successfully !!!\n Press enter to continue: ";
			cin.get();
			cin.get();	i=0;
			fin.close();
			employeemenu();
		}
	}
	if(i!=0)
	{
		i++;
		fin.close();
		employeelogin();
	}
}
void employee::employeemenu()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t EMPLOYEE MENU";
	cout<<"\n\n\t\t\t\t\t1. Add a product\n\n\t\t\t\t\t2. Remove a product\n\n\t\t\t\t\t3. Show Products List\n\n\t\t\t\t\t4. Add stock\n\n\t\t\t\t\t5. Go Back\n\n\t\t\t\t\t6. Exit"<<endl;
	cout<<"\n\n\t\t\t\t\tEnter your choice:";
	char i;
	cin>>i;
	if(i>='1' && i<='4')
	{
		callstockfn(i);
		employeemenu();
	}
	else if(i=='5')
	{
		menu();
	}
	else if(i=='6')
	{
		closer();
	}
	else{
		cout<<"\n\n\t\t WRONG KEY PRESSED !!!";
		cin.get();
		employeemenu();
	}
}
void boss::bosslogin()
{
	string name,u,pass,p;	char ch;	static int i=1;
	u=getus();
	p=getpw();
	cin.ignore();
	system("cls");
	cout<<"\n\n\t\t\t Enter username:";
	cin>>name;
	cout<<"\n\n\t\t\t Enter password:";
	cin>>pass;

	if(u==name && p==pass) 
	{
		i=0;
		system("cls");
		bossmenu();
	}
	else if(i<=3)
	{
		i++;
		bosslogin();
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t TOO MANY WRONG ATTEMPTS !!!";
		exit(0);
	}
}

void boss::bossmenu()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t BOSS MENU";
	cout<<"\n\n\t\t\t\t\t1. Add a product\n\n\t\t\t\t\t2. Remove a product\n\n\t\t\t\t\t3. Show Products List\n\n\t\t\t\t\t4. Add stock\n\n\t\t\t\t\t5. Employee Section\n\n\t\t\t\t\t6. Go Back\n\n\t\t\t\t\t 7. Exit"<<endl;
	cout<<"\n\n\t\t\t\t\tEnter your choice:";
	char i;
	cin>>i;
	if(i>='1' && i<='4')
	{
		callstockfn(i);
		bossmenu();
	}
	else if(i=='5')
	{
		employeesection();
	}
	else if(i=='6')
	{
		menu();
	}
	else if(i=='7')
	{
		closer();
	}
	else{
		cout<<"\n\n\t\t WRONG KEY PRESSED !!!";
		cin.get();
		bossmenu();
	}
}
void boss::addemployee()
{
	system("cls");
	employee emp;
	emp.setdata();
	fout.open("emp1.txt", ios::app);
	emp.write();
	fout.close();
    cout<<"\n\n\t\t Employee Added !!!";
    cin.get();
    bossmenu();
}
void boss::removeemployee()
{
	system("cls");
	int i=0;
    string findthis;
    cout<<"\n\t\t\t\t DELETE RECORD";
    cout<<"\n\nEnter the username of the employee:";
    cin>>findthis;
    fout.open("temp.txt");
    fin.open("emp1.txt");
    employee emp;
    while(!fin.eof())
    {
    emp.read();
	if(!fin.eof())	
	if(emp.checker(findthis)==0)
    {
    	cout<<"\n\n\t\t\t EMPLOYEE REMOVED";
		emp.displayacc();
		i++;
    }
    else
    emp.write();
    }
    if(i==0)
	cout<<"\n\n NO SUCH EMPLOYEE FOUND !!!";
	cin.get();
	cin.get();
    fin.close();
    fout.close();
    remove("emp1.txt");
    rename("temp.txt","emp1.txt");
    bossmenu();
}		
void boss::employeelist()
{
	int i=1;
	system("cls");
	cout<<"\n\t\t_________________________________________________________________________";
	cout<<"\n\n\t\t_________________________   LIST OF EMPLOYEES:  _________________________";
	cout<<"\n\n\t\t_________________________________________________________________________\n";
	cout<<"\n\n\t\t  USERNAME\t\tPASSWORD\tNAME\t\t\tID";
	fin.open("emp1.txt");
	employee emp;
	
    while(!fin.eof())
    {	
		emp.read();
	 	if(!fin.eof())
	 	{
		    if(fin.tellg()<0)	{	i=0; break;		}
		  	emp.displayacc();
	  	}
    }
 	
    fin.close();
	cout<<"\n\n\t\t_________________________________________________________________________\n";
	cin.get();
	cin.get();
	bossmenu();
}
void boss::employeesection()
{
	system("cls");
	cout<<"\n\t\t\t\t\t   EMPLOYEE SECTION\n";
	cout<<"\t\t\t____________________________________________________________";
	cout<<"\n\n\t\t\t\t\t   1. Add Employee\n\n\t\t\t\t\t   2. Remove Employee\n\n\t\t\t\t\t   3. Employee List\n\n\t\t\t\t\t   4. Back to Boss Menu\n\n\t\t\t\t\t   5. Exit";
	cout<<"\n\n\t\t\t____________________________________________________________\n";
	cout<<"\n\n\t\t\t\t Enter Your Choice:";
	char ch;
	cin>>ch;
	if(ch=='1')
	{
		addemployee();
	}
	else if(ch=='2')
	{
		removeemployee();
	}
	else if(ch=='3')
	{
		employeelist();
	}
	else if(ch=='4')
	{
		bossmenu();
	}
	else if(ch=='5')
	{
		closer();
	}
	else
	{
		cout<<"\n\n WRONG KEY ENTERED !!!";
		this->employeesection();
	}
}
void callstockfn(char i)
{
	stock s;
	if(i=='1')
	{
		s.addnew();
	}
	else if(i=='2')
	{
		s.removepro();
	}
	else if(i=='3')
	{
		s.show();
	}
	else if(i=='4')
	{
		s.addstock();
	}
}

int main()
{
	int i;
	char ch;
	system("color AF");
    Sleep(500);
    system("color 4F");
    Sleep(500);
    system("color DF");
    Sleep(500);
    system("color 0F");
    Sleep(500);
    system("color 6");
	cout<<"\n\n\n\n\n\n\n\n\n\n \t\t\t|_____________ STORE MANAGEMENT SYSTEM _____________|";
	cout<<"\n\n										by - Ali & Hubab";
	cin.get();
	menu();
}

void menu()
{
	char ch;
	system("cls");
	fout.open("emp1.txt",ios::app);		fout.close();
	fout.open("stock1.txt", ios::app);	fout.close();
	cout<<"\n\t\t\t\t\t   STORE MANAGEMENT SYSTEM\n";
	cout<<"\t\t\t________________________________________________________________";
	cout<<"\n\t\t\t|\t\t\t\t\t\t\t\t|\n\t\t\t|\t\t   1. Boss Menu\t\t\t\t\t|\n\t\t\t|\t\t\t\t\t\t\t\t|\n\t\t\t|\t\t   2. Employee Menu\t\t\t\t|\n\t\t\t|\t\t\t\t\t\t\t\t|\n\t\t\t|\t\t   3. Customer Menu\t\t\t\t|\n\t\t\t|\t\t\t\t\t\t\t\t|\n\t\t\t|\t\t   4. Exit\t\t\t\t\t|";
	cout<<"\n\t\t\t|\t\t\t\t\t\t\t\t|\n\t\t\t|_______________________________________________________________|\n";
	cout<<"\n\n\t\t\t Enter Your Choice:";
	cin>>ch;
	if(ch=='1')
	{
		boss B1;
		B1.bosslogin();		
	}
	else if(ch=='2')
	{
		employee E1;
		E1.employeelogin();
	}
	else if(ch=='3')
	{
		customermenu();
	}
	else if(ch=='4')
	{
		closer();
	}
	else{
		cout<<"\n\n WRONG KEY ENTERED !!!";
		cin.get();
		system("cls");
		menu();
	}
}


