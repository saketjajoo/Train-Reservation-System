#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include<graphics.h>

void time()
{
	gotoxy(55,6);
	struct dostime_t t;
	_dos_gettime(&t);
	printf(" TIME : %2d : %02d : %02d", t.hour, t.minute,t.second);
}

void date()
{
	gotoxy(55,5);
	struct dosdate_t d;
	_dos_getdate(&d);
	printf("DATE : %d / %d / %d",d.day,d.month,d.year);
}

void end()
{
   int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "\\bgi");
	cleardevice();
       settextstyle(0,HORIZ_DIR,2);
       setcolor(LIGHTRED);
       outtextxy(20,75,"   P r e s e n t e d    B y  :-");
       settextstyle(0,HORIZ_DIR,2);
       setcolor(WHITE);
       outtextxy(20,208,"N a m e       : Saket Jajoo");
       outtextxy(330,240," & ");
       outtextxy(270,280,"Adarsh Misra");
       outtextxy(20,320,"C l a s s     : XII - A");
       outtextxy(20,360,"R o l l  n o. : 7 , 8");
       delay(3000);
	cleardevice();
	int x=getmaxx();
	int y=getmaxy();
	rectangle(0,0,x,y);
	int t=476;
	for(int j=5;j<640;j+=4)
	{
			setcolor(j);
			line(j,0,j,t);
			delay(30);
	}
	setcolor(WHITE);
	settextstyle(0,HORIZ_DIR,3);
	outtextxy(20,230,"   T H A N K   Y O U  ");
	delay(2000);
       closegraph();
       exit(0);
}

void pass()
{
	password :
	clrscr();
	char ch;
	char *pass="computer123";
	char *pass1;
	cout<<"\n\n Enter password : ";
	gets(pass1);
	int x;
	x=strcmp(pass,pass1);
	if(x==0)
	{
		cout<<"\n\n Access Granted";
		delay(1000);
		clrscr();
	}
	else
	{
		cout<<"\n\n Access Denied";
		delay(1000);
		goto password;
	}
}

int ticketno;
int emp_no;
int no,no1;
class control
{
	private:
	void MENU_EDIT();
	public:
	void MAIN_SCREEN();
	void EMP_SCREEN();
}c,obj;

class passenger
{
	long tno;
	long ticketno;
	char name[30],des[30],brd[30];
	int d,m,y;
     public:
	int getno()
	{
		return tno;
	}
	void getticket();
	void displayticket();
};

void passenger::getticket()
{
	  cout<<"TICKET NO :"<<++ticketno<<endl;
	  cout<<"Enter train number : ";
	  cin>>tno;
	  cout<<endl;
	  cout<<"\nEnter your name : ";
	  gets(name);
	  cout<<"\nEnter boarding station : ";
	  gets(brd);
	  cout<<"Enter destination : ";
	  gets(des);
	  cout<<"\n Enter date of journey : \n";
	  cout<<"\n Enter day : ";
	  cin>>d;
	  cout<<"\nEnter  month : ";
	  cin>>m;
	  cout<<"\n Enter year : ";
	  cin>>y;
}

void passenger::displayticket()
{
	clrscr();
	cout<<"\n\n\n\nTICKET NO :\t"<<ticketno;
	cout<<"\n\nTrain Number : \t"<<tno;
	cout<<"\n\nName : \t"<<name;
	cout<<"\n\n Boarding station :"<<brd;
	cout<<"\n\n Destination : "<<des;
	cout<<"\n\n Date : "<<d<<" / "<<m<<" / "<<y;
}

//non member functions

void reserve(passenger p1)
{
//	 fstream fout("ticket.txt",ios::in|ios::out);
	fstream fout("ticket.txt",ios::app);
	 if(!fout)
	 cout<<"error in opening file";
//	 fout.seekp((ticketno-1)*sizeof(passenger),ios::beg);
	 fout.write((char*)&p1,sizeof(p1));
	 cout<<"\nticket is added to the list";
	 getch();
	 fout.close();
	 getch();
	 c.MAIN_SCREEN();
}

void readticket(no)
{
	 int flag=0;
	 passenger p1;
	 fstream fin("ticket.txt",ios::in|ios::out);
	 if(!fin)
	 cout<<"errror in opening file";
	 while(!fin.eof())
	 {
		 fin.read((char *)&p1,sizeof(p1));
		 if(no==p1.getno())
		 {
			   flag=1;
			   cout<<"\n  record is found";
			   p1.displayticket();
			   break;
		 }
	 }
	 if(flag==0)
	 cout<<"\n\nThis ticket does not exist\n";
	 getch();
	 fin.close();
	 c.MAIN_SCREEN();
}

void delticket(no)
{
	passenger p1;
	int flag=0;
	fstream fin("ticket.txt",ios::in|ios::binary|ios::out);
	if(!fin)
	cout<<"errror in opening file";
	fstream fout("temp.txt",ios::in|ios::binary|ios::out);
	while(fin.read((char*)&p1,sizeof(passenger)))
	{
		if(no!=p1.getno())
		fout.write((char*)&p1,sizeof(passenger));
		else
		{
			cout<<"Record is found:";
			p1.displayticket();
			flag=1;
		}
	}
	fin.close();
	fout.close();
	if(flag==0)
	{
		cout<<"Ticket does not exist";
		getch();
	}
	else
	{
		char ch;
		cout<<"\n\nAre you sure you want to delete the ticket ( y / n ) ?  ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		cout<<"\n\nTicket Deleted";
		getch();
	}
	remove("ticket.txt") ;
	rename("temp.txt","ticket.txt");
	c.MAIN_SCREEN();
}

class employee
{


	int age,experience;
	int dd, mm, yy;
	char grade[2];
	char name[30];
	char quali[15];
	char desig[12];
	double salary;
	int deptno;
	int ddb, mmb, yyb;
	int ddj,mmj,yyj;
	int empid;

	public:

	int getno()
	{
		return empid;
	}
	void modify();
	void new_employee();
	void display();
	void display_month_sal();
};

void employee::new_employee()
{
	int i, valid;
	clrscr();
	gotoxy(65, 4);
	cout << "<0>=Exit";
	gotoxy(30, 4);
	cprintf("Open New Employee");
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(5, 4);
	cout << "Date: " << d1 << '-' << m1 << '-' << y1;
	gotoxy(31, 6);
	cprintf("EMPLOYEE ID :-  ");
	gotoxy(5,8);
	cprintf( "Name                : ");
	gotoxy(5,10);
	cprintf( "Date of Birth       : ");
	gotoxy(5,12);
	cprintf( "Designation         : ");
	gotoxy(5,14);
	cprintf( "Qualification       : ");
	gotoxy(5, 16);
	cprintf( "Date of Joining     : ");
	gotoxy(5, 18);
	cprintf( "Department no.      : ");
	gotoxy(5, 20);
	cprintf( "Basic Salary        : ");
	gotoxy(5, 22);
	cprintf( "Grade               : ");
	do
	{
		valid=1;
		gotoxy(46,6);
		cin>>empid;
		if(empid=='0')
		c.EMP_SCREEN();
	}while(!valid);
	do
	{
		valid = 1;
		gotoxy(27, 8);
		gets(name);
		strupr(name);
		if (name[0] == '0')
		c.EMP_SCREEN();
	} while (!valid);
	gotoxy(27, 10);
	cin >>ddb;
	gotoxy(29, 10);
	cprintf( "/");
	gotoxy(30, 10);
	cin >>mmb;
	gotoxy(32, 10);
	cprintf( "/");
	gotoxy(33, 10);
	cin >>yyb;
	do
	{
		valid = 1;
		gotoxy(27, 12);
		gets(desig);
		strupr(desig);
		if (desig[0] == '0')
		return;
	} while (!valid);
	do
	{
		valid = 1;
		gotoxy(27, 14);
		gets(quali);
		strupr(quali);
		if (quali[0] == '0')
		return;
	} while (!valid);
	gotoxy(27, 16);
	cin >>ddj;
	gotoxy(29, 16);
	cprintf( "/");
	gotoxy(30, 16);
	cin >> mmj;
	gotoxy(32, 16);
	cprintf( "/");
	gotoxy(33, 16);
	cin >> yyj;
	gotoxy(27, 18);
	cin >> deptno;
	do
	{
		valid = 1;
		char t[10];
		gotoxy(27, 20);
		gets(t);
		salary = atof(t);
	} while(!valid);
	if (salary >= 2500 && salary <= 3000)
	{
		strcpy(grade, "C");
	}
	else if (salary >= 3001 && salary <= 4000)
	{
		strcpy(grade, "B");
	}
	else if (salary >= 4001 && salary <= 5000)
	{
		strcpy(grade, "A");
	}
	else if (salary > 5000)
	{
		strcpy(grade, "O");
	}
	else
	return;
	gotoxy(27, 22);
	cprintf("%s",grade);
	getch();
}

void employee::display()
{
	clrscr();
	cout<<"\n\n\n\nEMPLOYEE ID :- "<<empid;
	cout<<"\n\n\nName                : "<<name;
	cout<<"\n\nDate of Birth       : "<<ddb<<"/"<<mmb<<"/"<<yyb;
	cout<<"\n\nDesignation         : "<<desig;
	cout<<"\n\nQualification       : "<<quali;
	cout<<"\n\nDate of Joining     : "<<ddj<<"/"<<mmj<<"/"<<yyj;
	cout<<"\n\nDepartment no.      : "<<deptno;
	cout<<"\n\nBasic Salary        : "<<salary;
	cout<<"\n\nGrade               : "<<grade;
	getch();
}

void employee::modify()
{
	clrscr();
	char t_name[20],t_desig[20],t_quali[20],t_grade[2];
	int tmmb,tyyb,tddb,tddj,tmmj,tyyj,t_deptno,t_salary,t_empid;
	gotoxy(72, 1);
	cout << "<0>=Exit";
	gotoxy(30, 3);
	cprintf("Modify Employee's Record");
	cout<<"\n\nEmployee Id    : ";
	cin>>t_empid;
	cout <<"\nName            : ";
	cin>>t_name;
	cout <<"\nDate of Birth   :   /  / ";
	gotoxy(19,9);cin>>tddb;
	gotoxy(22,9);cin>>tmmb;
	gotoxy(25,9);cin>>tyyb;
	cout <<"\nDesignation     : ";
	cin>>t_desig;
	cout <<"\nQualification   : ";
	cin>>t_quali;
	cout <<"\nDate of Joining :    /    /  ";
	gotoxy(19,15);cin>>tddj;
	gotoxy(22,15);cin>>tmmj;
	gotoxy(25,15);cin>>tyyj;
	cout <<"\n\nDepartment no.  : ";
	cin>>t_deptno;
	cout <<"\n\nBasic Salary    : ";
	cin>>t_salary;
	if(t_salary >= 2500 && t_salary <= 3000)
	{
		strcpy(t_grade, "C");
	}
	else if (t_salary >= 3001 && t_salary <= 4000)
	{
		strcpy(t_grade, "B");
	}
	else if (t_salary >= 4001 && t_salary <= 5000)
	{
		strcpy(t_grade, "A");
	}
	else if (t_salary > 5000)
	{
		strcpy(t_grade, "O");
	}
	else
		return;
	cout <<"\n\nGrade           : "<<t_grade;
	cout<<"\n\n Press any key to continue...";
	getch();
	strcpy(name,t_name);
	strcpy(desig,t_desig);
	strcpy(quali,t_quali);
	strcpy(grade,t_grade);
	deptno=t_deptno;
	salary=t_salary;
	empid=t_empid;
	ddb=tddb; mmb=tmmb; yyb=tyyb;
	ddj=tddj; mmj=tmmj; yyj=tyyj;
	cout <<"\nRecord modified";
	cout<<"\nPress any key to continue...";
	getch();
}

void employee::display_month_sal()
{
	clrscr();
	char t_acc[10];
	char *cmonth;
	int j;
	int t, t_emp_id;
	gotoxy(71, 1);
	cout << "<0>=Exit";
	gotoxy(30, 3);
	cout << "Salary Slip";
	gotoxy(30, 4);
	cout << "===========";
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(10, 5);
	cout << "Employee ID : "<<empid;
	switch (m1)
	{
		case 1  : strcpy( cmonth, "January"  );break;
		case 2  : strcpy( cmonth, "February" ); break;
		case 3  : strcpy( cmonth, "March"    ); break;
		case 4  : strcpy( cmonth, "April"    ); break;
		case 5  : strcpy( cmonth, "May"      ); break;
		case 6  : strcpy( cmonth, "June"     ); break;
		case 7  : strcpy( cmonth, "July"     ); break;
		case 8  : strcpy( cmonth, "August"   ); break;
		case 9  : strcpy( cmonth, "September"); break;
		case 10 : strcpy( cmonth, "October"  ); break;
		case 11 : strcpy( cmonth, "November"); break;
		case 12 : strcpy( cmonth, "December" ); break;
	}
	gotoxy(45,5);
	cout<<cmonth;
	gotoxy(8,6);
	for (int i=0;i<=64;i++)
	cout << "=";
	ifstream file;
	file.open("emp", ios::in|ios::binary);
  //	if (emp_no == t_emp_no)
//	{
		gotoxy(30, 7);
		cout << "Date of Joining : " << ddj << "-" << mmj << "-" << yyj;
		gotoxy(30, 8);
		cout << "Designation : " <<desig;
		gotoxy(30, 9);
		cout << "Qualification : " <<quali;
		gotoxy(30,10);
		cout << "Department No. : " <<deptno;
		gotoxy(30, 11);
		cout << "Grade : " <<grade;
		delay(2);
  //	}
	file.close();
	gotoxy(8,12);
	for (i = 0; i <= 64; i++)
	cout << "-";
	gotoxy(10,13);
	cout << "Salary";
	gotoxy(35,13);
	cout<<"Earnings";
	gotoxy(62,13);
	cout << "Deduction";
	gotoxy(8,14);
	for (i = 0; i <= 64; i++)
	cout << "-";
	float EPF = 0.0;
	float DA = 0.0;
	float ESI = 0.0;
	float HRA = 0.0;
	float CANTEEN = 0.0;
	float CONV = 0.0;
	float ANN_GROSS = 0.0;
	float ITAX = 0.0;
	float NET_INCOME = 0.0;
	float TOTAL_EARN = 0.0;
	float TOTAL_DEDU = 0.0;
	float PFTAX = 0.0;
	float TAXABLE = 0.0;
	if (salary >= 2500 && salary <= 3000)
	{
		DA = salary * 0.9;
		HRA = salary * 0.2;
		CONV = salary * 0.1;
	}
	else if (salary >= 3001 && salary <= 4000)
	{
		DA = salary * 0.12;
		HRA = salary * 0.3;
		CONV = salary * 0.15;
	}
	else if (salary >= 4001 && salary <= 5000)
	{
		DA = salary * 0.14;
		HRA = salary * 0.35;
		CONV = salary * 0.2;
	}
	else if (salary >= 5001)
	{
		DA = salary * 0.16;
		HRA = salary * 0.4;
		CONV = salary * 0.25;
	}
	TOTAL_EARN = salary + DA + HRA + CONV;
	ANN_GROSS = TOTAL_EARN * 12;
	EPF = (salary+DA) * 0.12;
	ESI = salary * 0.07;
	CANTEEN = 350;
	PFTAX = ((salary + DA) * 0.2) * 12;
	ANN_GROSS = ANN_GROSS + PFTAX;
	if (ANN_GROSS <= 60000)
	ANN_GROSS = 40000 - 20000;
	else
	ANN_GROSS = ANN_GROSS - 20000;
	if (ANN_GROSS > 40000)
	TAXABLE = ANN_GROSS - 40000;
	else
	TAXABLE = 0;
	if (TAXABLE <= 20000)
	ITAX = TAXABLE * 0.1;
	else if (TAXABLE > 20000 && TAXABLE <= 110000)
	ITAX = 2000 + ((TAXABLE-20000) * 0.2);
	else if (TAXABLE > 110000)
	ITAX = 20000 + ((TAXABLE-110000) * 0.3);
	ITAX = ITAX / 12;
	TOTAL_DEDU = EPF + ESI + CANTEEN + ITAX;
	NET_INCOME = TOTAL_EARN - TOTAL_DEDU;
	gotoxy(11, 15);
	cout << "Basic:" ;
	gotoxy(22, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< salary;
	gotoxy(35, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< salary;
	gotoxy(50, 15);
	cout << "E.P.F.:" ;
	gotoxy(63, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< EPF ;
	gotoxy(11, 16);
	cout << "D.A.:" ;
	gotoxy(22, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< DA;
	gotoxy(35, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< DA;
	gotoxy(50, 16);
	cout << "E.S.I.:";
	gotoxy(63, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< ESI;
	gotoxy(11, 17);
	cout << "H.R.A.:" ;
	gotoxy(22, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< HRA;
	gotoxy(35, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< HRA;
	gotoxy(50, 17);
	cout << "CANTEEN:" ;
	gotoxy(63, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CANTEEN ;
	gotoxy(11, 18);
	cout << "CONV.:" ;
	gotoxy(22, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CONV;
	gotoxy(35, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CONV;
	gotoxy(50, 18);
	cout << "INCOME TAX:" ;
	gotoxy(63, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< ITAX ;
	gotoxy(8, 19);
	for (i = 0; i <= 64; i++)
	cout << "-";
	gotoxy(11, 20);
	cout << "Total Earnings: ";
	gotoxy(34, 20);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< TOTAL_EARN;
	gotoxy(48, 20);
	cout << "Total Deduct: ";
	gotoxy(63, 20);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< TOTAL_DEDU;
	gotoxy(8, 21);
	for (i = 0; i <= 64; i++)
	cout << "=";
	gotoxy(11, 22);
	cout << "Net Pay: ";
	gotoxy(34, 22);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< NET_INCOME;
	gotoxy(10, 24);
	cout << "Press any key to Continue ...";
	getch();
	c.EMP_SCREEN();
}

void add_employee_e(employee e1)
{
	 clrscr();
	 fstream fout("emp.txt",ios::app);
	 if(!fout)
	 cout<<"error in opening file";
	 fout.write((char *)&e1,sizeof(e1));
	 cout<<"\nEmployee successfully added";
	 getch();
	 fout.close();
	 getch();
	 c.EMP_SCREEN();
}

void disp_emp_e(no1)
{
	int flag=0;
	 employee e1;
	 fstream fin("emp.txt",ios::in|ios::out);
	 if(!fin)
	 cout<<"Error in opening file";
	 while(!fin.eof())
	 {
		 fin.read((char *)&e1,sizeof(e1));
		 if(no1==e1.getno())
		 {
			   flag=1;
			   cout<<"\n  record is found";
			   e1.display();
			   getch();
			   break;
		 }
	 }
	 if(flag==0)
	 cout<<"\nEmployee does not exist.";
	 getch();
	 fin.close();
	 c.EMP_SCREEN();
}

void delete_employee_e(no1)
{
	employee e1;
	int flag=0;
	fstream fin("emp.txt",ios::in|ios::binary|ios::out);
	if(!fin)
	cout<<"Error in opening file";
	fstream fout("tempe.txt",ios::in|ios::binary|ios::out);
	while(fin.read((char*)&e1,sizeof(employee)))
	{
	      if(no1!=e1.getno())
	      fout.write((char*)&e1,sizeof(employee));
	      else
	      {
		      cout<<"Record is found:";
		      e1.display();
		      flag=1;
	      }
	 }
      fin.close();
      fout.close();
      if(flag==0)
      {
	      cout<<"Employee does not exist";
	      getch();
      }
      else
      {
	      char ch;
	      cout<<"\n\nAre you sure you want to delete the employee (y/n) ? : ";
	      cin>>ch;
	      if(ch=='y'||ch=='Y')
	      cout<<"\n\nEmployee deleted";
	      getch();
      }
      remove("emp.txt") ;
      rename("tempe.txt","emp.txt");
      c.EMP_SCREEN();
}

void modify_e(int no1)
{
	 employee e1;
	 int flag=0;
	 fstream fin("emp.txt",ios::in|ios::binary|ios::out);
	 if(!fin)
	 cout<<"Error in opening file";
	 char ans;
	 long pos;
	 while(fin.read((char*)&e1,sizeof(employee)))
	 {
		  pos=fin.tellg();
		  if(no1==e1.getno())
		  {
			  cout<<"\nrecord is found";
			  e1.display();
			  flag=1;
			  cout<<"\n\nModify this employee ? ";
			  cin>>ans;
			  if(ans=='y'||ans=='Y')
			  {
				  cout<<"\nEnter new details : ";
				  e1.modify();
				  fin.seekp(pos-sizeof(employee),ios::beg);
				  fin.write((char*)&e1,sizeof(employee));
			  }
			  getch();
			  break;
		  }
	 }
	 if(flag==0)
	 {
		 cout<<"\n Employee does not exist.";
		 getch();
	 }
	 fin.close();
	 c.EMP_SCREEN();
}

void month_salary_e(no1)
{
	int flag=0;
	employee e1;
	fstream fin("emp.txt",ios::in);
	if(!fin)
	cout<<"Error in opening file";
       while(fin.read((char *)&e1,sizeof(employee)))
       {
	     // fin.read((char *)&e1,sizeof(employee));
	      if(no1==e1.getno())
		{
		      clrscr();
		      cout<<"Record is found.";
		      e1.display_month_sal();
		      flag=1;
		      break;
	       }
       }
       fin.close();
       c.EMP_SCREEN();
}

void control::MAIN_SCREEN()
{       passenger p1;
	employee e1;
	fstream f1;
	f1.open("ticket.txt",ios::in);
	f1.seekp(0,ios::end);
	ticketno=(f1.tellp()/sizeof(passenger));
	f1.close();
	fstream f2;
	f2.open("emp.txt",ios::in);
	f2.seekp(0,ios::end);
	emp_no=(f2.tellp()/sizeof(employee));
	f2.close();
	int ch;
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "\\bgi");
	cleardevice();
	settextstyle(0, HORIZ_DIR, 4);
	setcolor(BLUE);
	outtextxy(100,80,"MAIN MENU");
	date();
	time();
	setcolor(CYAN);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(120,140, "1. Book a ticket");
	outtextxy(120,160, "2. Display Ticket");
	outtextxy(120,180, "3. Delete ticket");
	outtextxy(120,200, "4. Employee section");
	outtextxy(120,220, "5. EXIT");
	outtextxy(120,300,"Enter Your Choice ");
	setcolor(GREEN);
	line(430,315,480,315);
	ch = getch();
	closegraph();
	switch (ch)
	{
		case '1':
		{
			p1.getticket();
			reserve(p1);
			c.MAIN_SCREEN();
			break;
		}
		case '2':
		{
		     cout<<"\nEnter ticket number to be displayed : ";
		     cin>>no;
		     readticket(no);
		     c.MAIN_SCREEN();
		     break;
		}
		case '3':
		{
			pass();
			cout<<"Enter ticket number you want to  delete : ";
			cin>>no;
			delticket(no);
			c.MAIN_SCREEN();
			break;
		}
		case '4':
		{
			c.EMP_SCREEN();
			break;
		}
		case '5':
		{
			end();
		}
		default:
		{
			cout<<"\n\n Incorret choice";
			exit(0);
		}
	}
}

void control::EMP_SCREEN()
{
	int ch;
	employee e1;
	int no;
	fstream f1;
	f1.open("emp.txt",ios::in);
	f1.seekp(0,ios::end);
	emp_no=(f1.tellp()/sizeof(employee));
	f1.close();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "\\bgi");
	cleardevice();
	settextstyle(0, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(100,120,"EMPLOYEE  MENU");
	setcolor(CYAN);
	date();
	time();
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(120,180, "1. Add New Employee");
	outtextxy(120,200, "2. See Individual Employee");
	outtextxy(120,220, "3. Modify Employee's Records");
	outtextxy(120,240, "4. Delete Employee's Records");
	outtextxy(120,260, "5. Salary Slip");
	outtextxy(120,280, "6. Back");
	outtextxy(120,340,"Enter Your Choice ");
	setcolor(GREEN);
	line(430,360,480,360);
	ch = getch();
	closegraph();
	switch (ch)
	{
		case '1':
		{       e1.new_employee();
			add_employee_e(e1);
			c.EMP_SCREEN();
			break;
		}
		case '2':
		{	cout<<"\nEnter employee ID whose records are to be displayed : ";
		       cin>>no1;
			disp_emp_e(no1);
			c.EMP_SCREEN();
			break;
		}
		case '3':
		{       pass();
			 cout<<"\nEnter employee ID whose records are to be  modified : ";
			 cin>>no1;
			modify_e(no1);
			c.EMP_SCREEN();
			break;
		}

		case '4':
		{       pass();
			cout<<"Enter employee ID whose records are to be deleted : ";
			cin>>no1;
			delete_employee_e(no1);
			c.EMP_SCREEN();
			break;
		}
		case '5':
		{       pass();
			cout<<"\nEnter employee ID : ";
			 cin>>no1;
			month_salary_e(no1);
			c.EMP_SCREEN();
			break;
		}
		case '6':
		{
			c.MAIN_SCREEN();
			break;
		}
		default:
		{
			cout<<"\n\n Incorret choice";
			exit(0);
		}
	}
}

void welcome1()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver,&gmode, "\\bgi");
	cleardevice();
	setbkcolor(2);
	settextstyle(0,HORIZ_DIR,2);
	rectangle(25,55,150,80);
	outtextxy(30,60,"W");delay(70);gotoxy(7,5);cout<<" E";delay(70);cout<<" L";delay(70);cout<<" C";delay(70);cout<<" O";delay(70);cout<<" M";delay(70);cout<<" E";delay(70);
	rectangle(115,120,149,146);
	outtextxy(120,125,"T");delay(70);gotoxy(17,9);cout<<" O";
	rectangle(220,185,340,212);
	outtextxy(210,190," R");delay(70);gotoxy(31,13);cout<<" A";delay(70);cout<<" I";delay(70);cout<<" L";delay(70);cout<<" W";delay(70);cout<<" A";delay(70);cout<<" Y";
	rectangle(310,250,502,275);
	outtextxy(300,255," R");delay(80);gotoxy(43,17);cout<<" E";delay(80);cout<<" S";delay(80);cout<<" E";delay(80);cout<<" R";delay(80);cout<<" V";delay(80);cout<<" A";delay(80);cout<<" T";delay(80);cout<<" I";delay(80);cout<<" O";delay(80);cout<<" N";
	ellipse(260,360,0,360,160,20);
	gotoxy(16,23);cout<<"  Press any key to continue.....  ";
	getch();
	closegraph();
}


void openingscreen()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "\\bgi");
	cleardevice();
	int p=getmaxx();
	int t=478;
	int x=0;
	for(int m=p;m>0;m--)
	{
		setcolor(m);
		line(x,0,x,t);  x+=5;
	}
	delay(3);
	for(int i=p;i>0;i-=2)
	{
		bar(i-2,0,i,t);
		setbkcolor(BLACK);
		delay(20);
	}
	closegraph();
}

void loading()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "\\bgi");
	setbkcolor(CYAN);
	char lb=177;
	gotoxy(20,13);cout<<lb;delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<" ";delay(70);cout<<" ";delay(70);
	cout<<" L";delay(70);cout<<" O";delay(70);cout<<" A";delay(70);cout<<" D";delay(70);cout<<" I";delay(70);cout<<" N";delay(70);cout<<" G ";
	gotoxy(49,13);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<".";delay(70);cout<<lb;delay(1000);
}

void main()
{
	clrscr();
	openingscreen();
	welcome1();
	loading();
	c.MAIN_SCREEN();
}