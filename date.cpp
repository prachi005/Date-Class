
#include <iostream>
#include <exception>
# include <string.h>
#include <ctime>
#include <stdexcept>
#include <stdlib.h>  
#include <iomanip>
using namespace std;
int monthvalue[13]={-1,6,2,2,5,0,3,5,1,4,6,2,4};
char* monthname[13]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char* weekname[8]={"","Monday","Tuesday","Wednesday","Friday","Saturday","Sunday"};
enum Day{
D01=1,D02=2,D03=3,D04=4,D05=5,D06=6,
D07=7,D08=8,D09=9,D10=10,D11=11,D12=12,
D13=13,D14=14,D15=15,D16=16,D17=17,D18=18,
D19=19,D20=20,D21=21,D22=22,D23=23,D24=24,
D25=25,D26=26,D27=27,D28=28,D29=29,D30=30,
D31=31,
};
Day operator+(const Day& a, const Day& b) {
unsigned int uia = a, uib = b;
unsigned int t = (uia + uib) % 31;

return (Day)((t==0)?31:t);
}
Day operator+(const Day& a,int  b) {
unsigned int uia = a, uib = b;
unsigned int t = (uia + uib) % 31;

return (Day) ((t==0)?31:t);
}


enum WeekDay {
Mon = 1, Tue = 2, Wed = 3, Thr = 4, Fri = 5, Sat = 6, Sun = 7 };
WeekDay operator+(const WeekDay& a, const WeekDay& b) {
unsigned int uia = a, uib = b;
unsigned int t = (uia + uib) % 31;

return (WeekDay) t;
}

typedef unsigned int Year;
// A week starts on Monday and ends on Sunday. Weeks are numbered in a year from 1 to 52
// (or 53). Week 1 (W01) of a year starts contains the first Thursday of the year. Hence
// W01 of 2016 starts on 04/Jan and ends on 10/Jan as 07/Jan is the first Thursday.
// 01/Jan, 02/Jan, and 03/Jan therefore belongs to the last week of 2015.
enum WeekNumber {
W01 = 1, W02 = 2, W03 = 3, W04 = 4, W05 = 5,
W06 = 6, W07 = 7, W08 = 8, W09 = 9, W10 = 10,
W11 = 11, W12 = 12, W13 = 13, W14 = 14, W15 = 15,
W16 = 16, W17 = 17, W18 = 18, W19 = 19, W20 = 20,
W21 = 21, W22 = 22, W23 = 23, W24 = 24, W25 = 25,
W26 = 26, W27 = 27, W28 = 28, W29 = 29, W30 = 30,
W31 = 31, W32 = 32, W33 = 33, W34 = 34, W35 = 35,
W36 = 36, W37 = 37, W38 = 38, W39 = 39, W40 = 40,
W41 = 41, W42 = 42, W43 = 43, W44 = 44, W45 = 45,
W46 = 46, W47 = 47, W48 = 48, W49 = 49, W50 = 50,
W51 = 51, W52 = 52, W53 = 53 };
enum Month {
Jan = 1, Feb = 2, Mar =3, Apr = 4, May = 5, Jun = 6,
Jul = 7, Aug = 8, Sep =9, Oct = 10, Nov = 11, Dec = 12 };
Month operator+(const Month& a, const Month& b) {
unsigned int uia = a, uib = b;
unsigned int t = (uia + uib) % 12;

return (Month) ((t==0)?12:t);
}


Month operator+(const Month& a,int b) {
	unsigned int uia = a, uib = b;
	unsigned int t = (uia + uib) % 12;
	return (Month)((t==0)?12:t);
}
bool isleapYear(unsigned int y){
	bool leap=false;
	if(y%4==0){
		leap=true;
		if(y%100==0){
			leap=false;
			if(y%400==0)
			leap=true;
		}
	}
	return leap;
}

// This class defines the format in which a date is output or input
class DateFormat {
public:

DateFormat(char* dateformat,  char* monthFormat,  char* yearFormat){
	this->dateformat=new char[5];
	
	this->monthFormat=new char[5];
	
	
	this->yearFormat= new char[5];
	strcpy(this->dateformat,dateformat);
	strcpy(this->yearFormat,yearFormat);
	strcpy(this->monthFormat,monthFormat);                                                                   //check if space is being alloted or not
}
DateFormat(const DateFormat& base){
	this->dateformat=new char[5];
	
	this->monthFormat=new char[5];
	
	
	this->yearFormat= new char[5];
	strcpy(this->dateformat,base.dateformat);
	strcpy(this->yearFormat,base.yearFormat);
	strcpy(this->monthFormat,base.monthFormat);
}
// Single C-string format where dateFormat, monthFormat, and yearFormat are separated by ’-’
// Example: "dd-mmm-yy", "d-mm-yyyy", etc
DateFormat(const char* format){
	int i=0,count=0;
	dateformat=new char[5];
	monthFormat=new char[5];
	yearFormat= new char[5];
	while(format[count]!='-'){
	dateformat[i]=format[count];
	i++; count++;
	}
	dateformat[i]='\0';
	i=0; 
	count++;
	while(format[count]!='-'){
	monthFormat[i]=format[count];
	i++; count++;
	}
	monthFormat[i]='\0';
	i=0;count++;
	while(format[count]!='\0'){
	yearFormat[i]=format[count];
	i++; count++;
	}
	yearFormat[i]='\0';
}
// Default DateFormat created as "dd-mmm-yy"
DateFormat(){
	//char d[]="dd";
	//char m[]="mmm";
	//char y[]="yy";
	
	dateformat=new char[5];
	dateformat="dd";
	monthFormat=new char[5];
	
	monthFormat="mmm";
	yearFormat= new char[5];
	yearFormat="yy";
}

DateFormat& operator=(const DateFormat& base){
	//free(this->dateformat);
	//free(this->monthFormat);
	//free(this->yearFormat);
	this->dateformat=new char[5];
	
	this->monthFormat=new char[5];
	
	
	this->yearFormat= new char[5];
	strcpy(this->dateformat,base.dateformat);
	strcpy(this->yearFormat,base.yearFormat);
	strcpy(this->monthFormat,base.monthFormat);
}

friend ostream& operator<<(ostream&, const DateFormat&);
~DateFormat(){}
char* getdateformat(){
	return dateformat;
}
char* getmonthFormat(){
	return monthFormat;
}
char* getyearFormat(){
	return yearFormat;
}

void setdateformat(char* newformat){
	free(dateformat);
	dateformat=new char[5];
	strcpy(dateformat,newformat);
}
void setmonthFormat(char* newformat){
	free(monthFormat);
	monthFormat=new char[5];
	strcpy(monthFormat,newformat);
}

void setyearFormat(char* newformat){
	free(yearFormat);
	yearFormat=new char[5];
	strcpy(yearFormat,newformat);


}
private:
char* dateformat;
char* monthFormat;
char* yearFormat;
};


ostream& operator<<(ostream& os, const DateFormat& form ){
	os<<form.dateformat<<"-"<<form.monthFormat<<"-"<<form.yearFormat;
	return os;
}


class Date {
public:
// CONSTRUCTORS
Date(Day d, Month m, Year y){//throw(domain_error, out_of_range)
	if(y/100==0){
		if(y>=50)y=1900+y;
		else y=2000+y;
	}
	else if(((y/100==19)&&(y%100>=50))||((y/100==20)&&(y%100<50))) { }
	else throw out_of_range("out of range");
	if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<=31)){}
	else if((m==4||m==6||m==9||m==11)&&(d<=30)){}
	else if((m==2)&&isleapYear(y)&&(d<=29)){}
	else if((m==2)&&(!isleapYear(y))&&(d<=28)){}
	else throw domain_error("domain error");
	

	day=d;
	month=m;
	year=y;
}

// date in string format -- to be parsed as static format member
// "13-03-77" for "dd-mm-yy"
// "2-7-2018" for "d-m-yyyy"
explicit Date(const char* date) throw(invalid_argument, domain_error, out_of_range){
	int i=0,count=0;
	char* dat=new char[5];
	char* mon=new char[5];
	char* yr= new char[5];
	while(date[count]!='-'){
	dat[i]=date[count];
	i++; count++;
	}
	dat[i]='\0';
	i=0; 
	count++;
	while(date[count]!='-'){
	mon[i]=date[count];
	i++; count++;
	}
	mon[i]='\0';
	i=0;count++;
	while(date[count]!='\0'){
	yr[i]=date[count];
	i++; count++;
	}
	yr[i]='\0';
int d,m,y;
try{
d=atoi(dat);
m=atoi(mon);
y=atoi(yr);
}
catch(exception){throw invalid_argument("invalid argument");};
if((d<1)||(d>31)||(m>12)||(m<1)||(y<0))
	throw invalid_argument("invalid argument");

if(y/100==0){
		if(y>=50)y=1900+y;
		else y=2000+y;
	}
else if(((y/100==19)&&(y%100>=50))||((y/100==20)&&(y%100<50))){ }
else {throw out_of_range("out of range");}

if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<=31)){}
else if((m==4||m==6||m==9||m==11)&&(d<=30)){}
else if((m==2)&&isleapYear(y)&&(d<=29)){}
else if((m==2)&&(!isleapYear(y))&&(d<=28)){}
else throw domain_error("domain error");
			
day=(Day)d;
month=(Month)m;
year= y;


}


Date() throw(domain_error, out_of_range){
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    year=(now->tm_year + 1900);
    if(((year/100==19)&&(year%100>=50))||((year/100==20)&&(year%100<50))){}
    	else throw out_of_range("out of range");
    day=Day(now->tm_mday);
    month=(Month)(now->tm_mon+1);
}
// Default Constructor - construct ’today’ (get from system)


Date(const Date& otherDate){
	day=otherDate.day;
	month=otherDate.month;
	year=otherDate.year;
}
// DESTRUCTOR
~Date(){

} // No virtual destructor needed
// BASIC ASSIGNMENT OPERATOR
Date& operator=(const Date& base){
	this->day=base.day;
	this->month=base.month;
	this->year=base.year;
	return *this;
}
// UNARY ARITHMETIC OPERATORS
Date& operator++(){
	int n=daysinMonth(*this);
	if(this->day==n){
		this->day=(Day)1;
		if(this->month==12) year++;
		this->month=this->month+(Month)1;

	}
	else this->day=this->day+(Day)1;
	return *this;
}
// Next day
Date& operator++(int){
	int n=daysinMonth(*this);
	if(this->day+7>n){
		this->day=(Day)((int)this->day-n+7);
		if(this->month==12) year++;
		this->month=this->month+(Month)1;

	}
	else this->day=this->day+(Day)7;
	return *this;
}
// Same day next week
Date& operator--(){
	if(this->day==1){
		if(this->month==1){
			this->year=this->year-1;
			this->month=Month(12);
			this->day=Day(31);

		}
		else {
				this->month=(Month)(this->month-1);
				this->day= (Day)daysinMonth(*this);
			}
	}
	else this->day= (Day)(this->day-1);
		return *this;
}
// Previous day
Date& operator--(int){
	if(this->day-7<1){
		if(this->month==1){
			this->year--;
			this->month=Month(12);
			this->day=Day(daysinMonth(*this)+this->day-7);

		}
		else {
				this->month=(Month)(this->month-1);
				this->day= (Day)(daysinMonth(*this)+this->day-7);
			}
	}
	else this->day= (Day)(this->day-7);
	return *this;
}
// Same day previous week
// BINARY ARITHMETIC OPERATORS
unsigned int operator-(const Date& otherDate){
	int c= Date::totaldays(*this) - Date::totaldays(otherDate);
	return (c<0)?(0-c):c;
}

//days passed in year
int dayspassed(const Date base){
	int m,count=0;
	for(m=1;m<(base.month);m++){
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			count+=31;
		else if(m==2){
			if(base.leapYear()==true)count+=29;
			else count+=28;
		}
		else count+=30;
	}
	count+=base.day;
	return count;
}

//total days passed from 1950
unsigned int totaldays(const Date& base){
	unsigned int c=dayspassed(base);
	if(base.year>1950){
		c+=(base.year-1-1949)*365;
		if(base.year>1952){
			c=c+(base.year-1-1952)/4 +1;
		}
	}
	return c;
}

Date operator+(int noOfDays){
	Date ndate(*this);
	int k;
	if(noOfDays==0)return ndate;
	if(noOfDays>0){
		
		k= noOfDays- (daysinMonth(ndate)-ndate.day);

		if(k<=0){ndate.day=(Day)(ndate.day+noOfDays); }
		else{
			
			noOfDays-=(daysinMonth(ndate)-ndate.day);
			ndate.day=Day(daysinMonth(ndate));
			k=daysinNextMonth(ndate);
			while(noOfDays>=k){
				//cout<<"inloop"<<ndate.month<<endl;
				ndate.day=Day(k);
				if(ndate.month==12){
					
					ndate.month=(Month)1;
					ndate.year=ndate.year+1;
				}
				else { ndate.month=(Month)(ndate.month+1);}
				noOfDays-=k;
				k=daysinNextMonth(ndate);
			}
			if(noOfDays>0){
				
				ndate.day=(Day)noOfDays;
				if(ndate.month==12){
					ndate.month=(Month)1;
					ndate.year=ndate.year+1;
				}
				else ndate.month=(Month)(ndate.month+1);

			}
		}
	}
	else{
		noOfDays=0- noOfDays;
		k= noOfDays- ndate.day;

		if(k<0){ndate.day=(Day)(ndate.day-noOfDays); }
		else{
			
			noOfDays-=(ndate.day);
			if(ndate.month==1){ndate.month=(Month)12;ndate.year=ndate.year-1;}
			else ndate.month=(Month)(ndate.month-1);
			ndate.day=Day(daysinMonth(ndate));
			k=daysinMonth(ndate);
			while(noOfDays>=k){
				
				if(ndate.month==1){ndate.month=(Month)12;ndate.year=ndate.year-1;}
				else ndate.month=(Month)(ndate.month-1);
				ndate.day=Day(daysinMonth(ndate));

				
				noOfDays-=k;
				k=daysinMonth(ndate);
			}
			if(noOfDays>0){
				
				ndate.day=(Day)(ndate.day-noOfDays);
				/*if(ndate.month==1){
					ndate.month=(Month)12;
					ndate.year=ndate.year-1;
				}
				else ndate.month=(Month)(ndate.month-1);
				*/
			}
		}

		

		
	}
  if(((ndate.year/100==19)&&(ndate.year%100>=50))||((ndate.year/100==20)&&(ndate.year%100<50))){ }
		else {throw out_of_range("out of range");}

	if((ndate.month==1||ndate.month==3||ndate.month==5||ndate.month==7||ndate.month==8||ndate.month==10||ndate.month==12)&&(ndate.day<=31)){}
	else if((ndate.month==4||ndate.month==6||ndate.month==9||ndate.month==11)&&(ndate.day<=30)){}
	else if((ndate.month==2)&&isleapYear(ndate.year)&&(ndate.day<=29)){}
	else if((ndate.month==2)&&(!isleapYear(ndate.year))&&(ndate.day<=28)){}
	else throw domain_error("domain error");
	return ndate;
}

// Number of days between otherDate and current date
// Day noOfDays after (before) the current date
// (sign of noOfDays decides ahead or behind)
//throw(domain_error, out_of_range);

int dayspassed() const{
	int m,count=0;
	for(m=1;m<(month);m++){
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			count+=31;
		else if(m==2){
			if(this->leapYear()==true)count+=29;
			else count+=28;
		}
		else count+=30;
	}
	count+=day;
	return count;
}
// CAST OPERATORS
operator WeekNumber() const{
	Date d((Day)1,(Month)1,this->year);
	int s= WeekDay(d);
	int c;
	
	if(s<=4){
		c=this->dayspassed();
		c=c+(s-1);
		return(WeekNumber)(c/7);
	}
	else{
		if(this->day <= (8-s)){
			if(s==5){
				return (WeekNumber)53;
			}
			else if(s==6){
				if(isleapYear(this->year-1)==1) return (WeekNumber)53;
				else return (WeekNumber)52;
			}
			else return (WeekNumber)52;
		}
		else{
			c=this->dayspassed();
		c=c-(8-s)+6;
		return(WeekNumber)(c/7);

		}
	}
	

}
operator Month() const{
	return this->month;
}
operator WeekDay() const{
	int c1=((int)this->day + monthvalue[this->month])%7;
	int c2= (((this->year)%100)%28 + (((this->year)%100)%28)/4)%7 +((this->year/100 ==19)?1:0) ;
	if((this->month<=2)&&this->leapYear()) c2--;
	return WeekDay(((c1+c2)%7)?(c1+c2)%7:7);
} 
// True if the year of the current date is a leap year
bool leapYear() const{
	bool leap=false;
	if(year%4==0){
		leap=true;
		if(year%100==0){
			leap=false;
			if(year%400==0)
			leap=true;
		}
	}
	return leap;
}
int daysinMonth(const Date& date){
	int m=date.month;
	if(m==2){
		if(date.leapYear()==true)
			 return 29;
		else return 28;
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	else return 30;
}

int daysinNextMonth(const Date& date){
	int m=(int)date.month+1;
	if(m==13)m=1;
	if(m==2){
		if(date.leapYear()==true)
			 return 29;
		else return 28;
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	else return 30;
}


// BINARY RELATIONAL OPERATORS
bool operator==(const Date& otherDate){
	return((day==otherDate.day)&&(month==otherDate.month)&&(year==otherDate.year));
}
bool operator!=(const Date& otherDate){
	return((day!=otherDate.day)||(month!=otherDate.month)||(year!=otherDate.year));
}
bool operator<(const Date& otherDate){
	if(year!=otherDate.year){
		if(year<otherDate.year)return true;
		else return false;
	}
	else if(month!=otherDate.month){
		if(month<otherDate.month)return true;
		else return false;
	}
	else if(day<otherDate.day)return true;
	else return false;
}
bool operator<=(const Date& otherDate){
	if(year==otherDate.year){
		if(month==otherDate.month){
			if(day<=otherDate.day){
				return true;
			}
		else return false;
	}
	else if(month<otherDate.month)return true;
	else return false;
	}
	else if(year<otherDate.year)return true;
	else return false;
}
bool operator>(const Date& otherDate){
	if(year!=otherDate.year){
		if(year>otherDate.year)return true;
		else return false;
	}
	else if(month!=otherDate.month){
		if(month>otherDate.month)return true;
		else return false;
	}
	else if(day>otherDate.day)return true;
	else return false;
}
bool operator>=(const Date& otherDate){
	if(year==otherDate.year){
		if(month==otherDate.month){
			if(day>=otherDate.day){
				return true;
			}
		else return false;
	}
	else if(month>otherDate.month)return true;
	else return false;
	}
	else if(year>otherDate.year)return true;
	else return false;
}
// BASIC I/O using FRIEND FUNCTIONS
// These functions use Date::format to write or read
friend ostream& operator<<(ostream& os, const Date& date);
friend istream& operator>>(istream& is, Date& date);
// Format Function
static void setFormat(DateFormat& form){
	format=form;
}
static DateFormat& getFormat(){
	return format;                                                 // check why refrence is returned
}
private:
// Format to represent Date
static DateFormat format;
// Data members for Date

Day day;
Month month;
unsigned int year;

};
ostream& operator<<(ostream& os, const Date& date){
	if(strcmp((Date::format).getdateformat(),"dd")==0){
		os<< setfill('0') << setw(2) << date.day<<"-";
	}
	else if(strcmp((Date::format).getdateformat(),"d")==0){
		os<<date.day<<"-";
	}
	else{}
	if(strcmp((Date::format).getmonthFormat(),"mm")==0){
		os<< setfill('0') << setw(2) << date.month<<"-";
	}
	else if(strcmp((Date::format).getmonthFormat(),"m")==0){
		os<<date.month<<"-";
	}
	else if(strcmp((Date::format).getmonthFormat(),"mmm")==0){
		os<<monthname[date.month]<<"-";
	}
	else{}

	if(strcmp((Date::format).getyearFormat(),"yy")==0){
		os<<(date.year%100);
	}
	else if(strcmp((Date::format).getyearFormat(),"yyyy")==0){
		os<<date.year;
	}
	else{}

	//os<<date.day<<"-"<<date.month<<"-"<<date.year;
	return os;
}
istream& operator>>(istream& is, Date& date){
	unsigned int d,m,y;
	is >> d>>m;
	is>>y;
	date.day=(Day)d;
	date.month=(Month)m;
	date.year=y;
	return is;
} 
