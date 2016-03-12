#include "date.cpp"
#include <iostream>
#include <exception>
# include <string.h>
#include <ctime>
#include <stdexcept>
#include <stdlib.h>  
#include <iomanip>
using namespace std;

void Testdate(){
	Day d=D03;
	Month m= Jan;
	Year y=2015;

	cout<<"Intialising Date using Date(Day d, Month m, Year y) with d=D03,m=Jan,y=2015"<<endl;
	try{
	Date d1(d,m,y);
	}
	catch(domain_error e){cout<<"domain error";}
	catch(out_of_range a){cout<<"out_of_range error";};
	d=D29; m=Feb;
	cout<<"Intialising Date using Date(Day d, Month m, Year y)with d=D29,m=Feb,y=2015"<<endl;
	try{
	Date d1(d,m,y);
	}
	catch(domain_error e){cout<<"domain error"<<endl<<endl;}
	catch(out_of_range a){cout<<"out_of_range error"<<endl<<endl;};

	cout<<"Intialising Date using Date(Day d, Month m, Year y)with d=D29,m=Jan,y=1820"<<endl;
	try{
		d=D29; m=Jan; y=1920;
	Date d1(d,m,y);
	}
	catch(domain_error e){cout<<"domain error"<<endl<<endl;}
	catch(out_of_range a){cout<<"out_of_range error"<<endl<<endl;};


	cout<<"Intialising Date using explicit Date(const char* date)"<<endl;
	try{
	Date d2("4-5-89");
	}
	catch(domain_error e){cout<<"domain error"<<endl<<endl;}
	catch(out_of_range a){cout<<"out_of_range error"<<endl<<endl;};

	cout<<"Intialising Date using default construstor"<<endl;
	Date tod;
	cout<<"today is "<<tod<<endl<<endl;
	
	Date d4("5-10-2015");
	Date d5("31-12-2016");
	cout<<"testing unary operators"<<endl;

	
	cout<<" ++("<<d4<<") = ";
	++d4;
	cout<<d4<<endl;
	cout<<" ++("<<d5<<") = ";
	++d5;
	cout<<d5<<endl;
	--d5;
	cout <<"("<< d4<<")++ = ";
	d4++;
	cout<< d4 <<endl; 
	cout <<"("<< d5<<")++ = ";
	d5++;
	cout<< d5 <<endl; 
	Date d3("1-3-2016");
	cout<<" --("<<d3<<") = ";
	--d3;
	cout<<d3<<endl;
	cout <<"("<< d5<<")-- = ";
	d5--;
	cout<< d5 <<endl<<endl; 

	DateFormat df1("d-mm-yyyy");
	DateFormat df2("0-m-yy");
	DateFormat df3("dd-0-yyyy");
	DateFormat df4("dd-mm-yyyy");
	cout<<"Printing dates in different format"<<endl;
	cout<<"d-mmm-yyyy : "<<d3<<endl;
	Date::setFormat(df1);
	cout<<"d-mm-yyyy :  "<<d3<<endl;
	Date::setFormat(df2);
	cout<<"0-m-yy :   "<<d3<<endl;
	Date::setFormat(df3);
	cout<<"dd-0-yyyy :  "<<d3<<endl<<endl;
	Date::setFormat(df4);
	cout<<"dd-mm-yyyy :  "<<d3<<endl<<endl;


	cout<<"BINARY ARITHMETIC OPERATORS"<<endl;
	cout<<d3<<" - "<<d4<<" = "<<(d3-d4)<<endl;
	cout<<d3<<" +66 days = "<<(d3+66)<<endl;
	cout<<d3<<" -95 days = "<<(d3+(-95))<<endl;
	Date a1("7-10-2049");
	try{
	cout<<a1<<" + 300 = "<<(a1+300);
	}
	catch(domain_error e){cout<<"domain error"<<endl<<endl;}
	catch(out_of_range a){cout<<a1<<" + 300 is out_of_range "<<endl<<endl;};
	Date a2("7-10-1951");
	try{
	cout<<a2<<" -900 = "<<(a2+(-900));
	}
	catch(domain_error e){cout<<"domain error"<<endl<<endl;}
	catch(out_of_range a){cout<<a2<<" - 900 is out_of_range "<<endl<<endl;};
	

	cout<<"CAST OPERATORS"<<endl;
	cout<<"WeekDay("<<d3<<") = "<<weekname[WeekDay(d3)]<<endl;
	cout<<"WeekNumber("<<d3<<") = "<<"W"<<setw(2)<<WeekNumber(d3)<<endl;
	cout<<"Month("<<d3<<") = "<<monthname[Month(d3)]<<endl<<endl;

	cout<<"is "<<d3<<" leap year = "<<d3.leapYear()<<endl<<endl;
	cout<<"is "<<d4<<" leap year = "<<d4.leapYear()<<endl<<endl;

	cout<<"BINARY RELATIONAL OPERATORS"<<endl;
	Date d9=d3;
	Date d6("5-10-2017");
	
	cout<<"("<<d9<<" == "<<d3<<") = "<<(d9==d3)<<endl;
	cout<<"("<<d3<<" < "<<d4<<") = "<<(d3<d4)<<endl;
	cout<<"("<<d9<<" <= "<<d6<<") = "<<(d9<=d6)<<endl;
	cout<<"("<<d6<<" > "<<d3<<") = "<<(d6>d3)<<endl;
	cout<<"("<<d9<<" >= "<<d3<<") = "<<(d9>=d3)<<endl;



}
DateFormat Date::format;
//Date::format="dd-mm-yy"
int main(int argc, char const *argv[])
{
	DateFormat form("d-mmm-yyyy");
	Date::setFormat(form);
	
	Testdate();
}