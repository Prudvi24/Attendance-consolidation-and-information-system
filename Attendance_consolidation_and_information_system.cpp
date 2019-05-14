#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

void roll_no();
void reg(int roll);
void login();
void logout();
void remove();
void view(char n[2]);
void takeatt();
void check();
int nol(char n[2]);
int chk(char c[]);
void record();
 // Login.
 // username and password.
int log=0;
string user="iiitk", pass="password";

int main()
{
      	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
      	cout<<"|                                                                                                   |"<<endl;
      	cout<<"|                                                                                                   |"<<endl;
      	cout<<"|                             ATTENDANCE CONSOLIDATION & INFORMATION SYSTEM                         |"<<endl;
      	cout<<"|                                                                                                   |"<<endl;
      	cout<<"|                                                                                                   |"<<endl;
      	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
      	
      	cout<<"Press any key to continue...."<<endl;
      	getchar();
menu:
	 
        cout<<"-----------------------------------MAIN MENU--------------------------------------------------------"<<endl;
        cout<<"|                                                                                                  |"<<endl;
        if(log==0)
        cout<<"|                              1.Login                                                             |"<<endl;
        else
        cout<<"|                              1.Logout                                                            |"<<endl;
        cout<<"|                              2.register                                                          |"<<endl;
        cout<<"|                              3.view candidate file information                                   |"<<endl;
        cout<<"|                              4.Taking attendance for the candidates                              |"<<endl;
        cout<<"|                              5.View registered candidates                                        |"<<endl;
        cout<<"|                              6.Check attendance on a particular day                              |"<<endl;
        cout<<"|                              7.Remove a student record                                           |"<<endl;
        cout<<"|                              8.Exit                                                              |"<<endl;
        cout<<"|                                                                                                  |"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        
        cout<<"Press any key to continue...."<<endl;
        getchar();
        
back:
	      int a,b,c;
	      char name[25];
	      char n[2];
	      
	      cout<<"Enter your option: ";
	      cin>>a;
	      
	      switch(a)
	      {
	      	case 1:
	      		cout<<"---------------------------------LOGIN PORTAL----------------------------------------------"<<endl;
	      		cout<<" "<<endl;
	      		if(log==0)
				login();
	      		else
		     	logout();
	      		getchar();
	      		goto menu;
	      		
	      		break;
	      		
	      	case 2:
	      		cout<<"--------------------------------Registration of the student---------------------------------"<<endl;
	      		cout<<" "<<endl;
	      		cout<<"Enter the Roll_No: ";
	      		cin>>c;
	      		reg(c);
	      		getchar();
	      		goto menu;
	      		break;
	      		
	      	case 3:
	      		  cout<<"-----------------------------------Candidate details---------------------------------------"<<endl;
	      		  cout<<"Enter the roll_no: ";
	      		  cin>>n;
	      		  view(n);
	      		  getchar();
	      		  goto menu;
	      		  break;
	      		  
	      	case 4:
	      		  if(log==0)
	      		  {
	      		  	cout<<"Please login to continue..."<<endl;
	      		  	getchar();
	      		  	goto menu;
					}
				else
				{
					cout<<"------------------------------------Attendance-------------------------------------------"<<endl;
					takeatt();
					getchar();
					goto menu;
		            break;
		        }
				    
			case 5:
				   cout<<"------------------------------------View registered candidates-------------------------------"<<endl;
				   record();
				   getchar();
				   goto menu;
				   break;
				    
			case 6:
				    if(log==0)
				    {
				    	cout<<"Please login to continue..."<<endl;
				    	getchar();
				    	goto menu;
					}
					else
					{
						cout<<"-----------------------------------------Check Attendance------------------------------"<<endl;
						check();
						getchar();
						goto menu;
						break;
					}
				
	        
	        case 7:
	        	if(log==0)
	        	{
	            	cout<<"Please login to continue...."<<endl;
	            	getchar();
	            	goto menu;
				}
	            else
	            {
	            	cout<<"--------------------------------Remove a student record--------------------------------------"<<endl;
	               	cout<<" "<<endl;
	               	remove();
	               	getchar();
	               	goto menu;
				}	
	      		
	      	case 8:
	      		  cout<<"Successfully Exit"<<endl;
	      		  exit(0);
	      		  break;
	      		  
	      	default:
	      		cout<<"Invalid input...Please try again"<<endl;
	      		
	      		goto back;
	      		break;
	      		
		  }
	      
	return 0;
}

void login()
{
	string uenter,penter;
	
	cout<<"Enter the username: ";
	cin>>uenter;
	
	cout<<"Enter the password: ";
	cin>>penter;
	
	if(uenter==user&&penter==pass)
	{
		log=1;
		cout<<"Logged_In ssuccessfully"<<endl;
	}
	else
	{
		cout<<"Check the username and password"<<endl;
	}
}

void logout()
{
	log=0;
	cout<<"Logged out successfully"<<endl;
}
void reg(int roll)
{

	char name[50];
	
	ofstream a;
	a.open("show.txt",ios::out|ios::app);
	cout<<"Enter the student_Name: ";
	cin>>name;
	a<<roll<<"\t\t"<<name<<endl;
	a.close();	
}

void record()
{
	string line;
	ifstream a;
	a.open("show.txt",ios::in);
	cout<<"Roll No        Student Name"<<endl;
	while(getline(a,line))
	cout<<line<<endl;
	a.close();
}

void remove()
{
	char roll[2];
	
	cout<<"Enter the Roll No: ";
	cin>>roll;
	remove(roll);
}

void view(char n[2])
{
	int i=0;
	string line;
	fstream a;
	a.open(n,ios::in);
	for(i=0;getline(a,line);i++)
	{
		cout<<"Day "<<i+1;
		if(line=="1")
		cout<<" present";
		else
		cout<<" absent";
		cout<<endl;
	}
}

void takeatt()
{
	int l;
	char dec,num[2];
	cout<<"Enter Roll.No: ";
	cin>>num;
	if(chk(num)==1)
{
	fstream a;
	a.open(num,ios::out|ios::app);
	l=nol(num);
	cout<<"Is Roll.No "<<num<<" present on day "<<l+1<<" ?(y/n): ";
	cin>>dec;
	if(dec=='y')
	a<<1<<endl;
	else
	a<<0<<endl;
}
	else
	cout<<"Roll no not registered..\n";
}

int chk(char c[])
{
	fstream a;
	a.open("show.txt",ios::in);
	char b[2];
	string line;
	while(a>>b)
	{
		getline(a,line);
		if(!strcmp(b,c))
		return 1;
	}
	return 0;
}

void check()
{
	int i,n;
	char d[2];
	string line;
	char nu[2];
	fstream a;
	cout<<"Enter roll.no:";
	cin>>nu;
	cout<<"Enter on which day you want the attendance for the roll no "<<nu<<" :";
	cin>>n;
	if(nol(nu)>=n)
{
	a.open(nu,ios::in);
	for(i=1;i<=n;i++)
	{
		getline(a,line);
	}
	if(line=="1")
	cout<<"Present\n";
	else
	cout<<"Absent\n";
	a.close();
}
	else 
	cout<<"Attendance is not taken yet...\n";
}


int nol(char n[2])
{	
	int nlines=0;
	string line;
	fstream a;
	a.open(n,ios::in);
	while(getline(a,line))
	nlines++;
	return nlines;
}


