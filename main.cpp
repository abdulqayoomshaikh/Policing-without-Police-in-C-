#include <iostream>
#include<windows.h>
#include<mmsystem.h>
#include<string.h>
#include<fstream>
using namespace std;

void form()
{
	string name, contact_num, address, sop, Message_genrator;
	string CNIC;
	int Complaint_No;
	ofstream data;
	cout<<endl<<"\t\t\t Please Fill The Below Details"<<endl<<endl<<endl;
	data.open ("form.txt", ios::out | ios::app | ios::binary);
	cout<<"\t\tYour Name : ";
	cin.ignore();
	getline (cin, name);
	data<<"\t\t\t**Form of "<<name<<"*"<<endl;
	data<<"Name : "<<name<<endl;
	//cout<<endl<<endl;
	label:
 	cout<<"\t\tYour C N I C (with hifins like 12345-6789012-3  ): ";
 	cin>>CNIC;
 	if(CNIC.length()!=15)
	{
 		goto label;
 	}
 	else
 	{
 		data<<"CNIC Number: "<<CNIC<<endl;
	}
	//cout<<endl<<endl;
	cout<<"\t\tContact Number : ";
	cin>>contact_num;
	data<<"Contact Number : "<<contact_num<<endl;
	//cout<<endl<<endl;
	cout<<"\t\tYour Address : ";
	cin.ignore();
	getline (cin, address);
	data<<"Address : "<<address<<endl;
	cout<<endl<<endl;
	cout<<"\t\tPlease Write Your Statement of Purpose :\n";
	getline (cin,sop);
	data<<"Statement of Purpose : "<<sop<<endl<<"status:\t\n";
	cout<<endl<<endl;
	cout<<"Your Data has been Stored in our System "<<endl<<endl;
	data.close();
}

void start(string adminID, string adminPASS);

string search(string id)
{
	string line;
	ifstream myfile ("form.txt",ios::out | ios::app | ios::binary);
    string data = "";
    int count = 1;
    bool check = false;
	while ( getline (myfile,line) )
    {
    	data += line + "\n";
      	if(count == 3)
      	{
    		string substr = line.substr(13,15);
    		if(substr == id)
    		{
    			check = true;
			}
	  	}
	  	if(count == 7)
	  	{
	  		if(check)
	  		{
	  			return data;
			}
			else
			{
				data = "";
				count = 0;
			}
		}
		count++;
    }
    myfile.close();
	return "";
}

void userMenue(string adminID, string adminPASS)
{
	int num;
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t**      **  ** * *  **    *  *    *"<<endl;
	cout<<"\t\t\t\t\t* *    * *  *       * *   *  *    *"<<endl;
	cout<<"\t\t\t\t\t*  *  *  *  ** * *  *  *  *  *    *"<<endl;
	cout<<"\t\t\t\t\t*   *    *  *       *   * *  *    *"<<endl;
	cout<<"\t\t\t\t\t*   *    *  ** * *  *    **  ******"<<endl;
	
	
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t __________________"<<endl;
	cout<<"\t\t\t\t\t| 1- File a report:|"<<endl;
	cout<<"\t\t\t\t\t|__________________|"<<endl;
	cout<<"\t\t\t\t\t ___________________"<<endl;
	cout<<"\t\t\t\t\t|2- Report checking:|"<<endl;
	cout<<"\t\t\t\t\t|___________________|"<<endl;
	cout<<"\t\t\t\t\t ___________________"<<endl;
	cout<<"\t\t\t\t\t|___________________|"<<endl;
	cout<<"\t\t\t\t\t __________________________________"<<endl;
	cout<<"\t\t\t\t\t|Please enter your options 0,1 or 2|"<<endl;
	cout<<"\t\t\t\t\t|__________________________________|"<<endl;
	cin>>num;
	switch(num)
	{
		case 1:
		{
			form();
			break;
		}
		case 2:
		{
			string id;
			cout<<"Enter the CNIC Number:\t";
			cin>>id;
			cout<<search(id);
			break;
		}
		case 0:
		{
			system("cls");
			start(adminID, adminPASS);
			break;
		}
	}
}

void adminmenue(string adminID, string adminPASS);

void start(string adminID, string adminPASS)
{
	int num;
	cout<<endl<<endl<<"\t\t\tW E L C O M E    TO    P O L I C I N G    W I T H-O U T    P O L I C E "<<endl<<endl<<endl;
	cout<<"\t\t\t1-User"<<endl;
	cout<<"\t\t\t2-Admin:"<<endl;
	cout<<"\t\t\tPlease enter 1 to 2 options:";
	cin>>num;
	switch(num)
	{
		case 1:
		{
			system("cls");
			userMenue(adminID, adminPASS);
			break;
		}
		case 2:
		{
			string id, pass;
			cout<<"\nEnter the Admin ID:\t";
			cin>>id;
			cout<<"Enter the Admin pass:\t";
			cin>>pass;
			if(id == adminID && pass == adminPASS)
			{
				system("cls");
				adminmenue(adminID, adminPASS);
			}
			//filreading();
			break;
		}
	}
}

void displayRecords()
{
	string line;
	cout<<endl<<endl;
	cout<<" \t-----------------Stored Form In Our System---------------"<<endl<<endl<<endl;
  	ifstream myfile ("form.txt",ios::out | ios::app | ios::binary);
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    
    myfile.close();
}

string status()
{
	string line;
	ifstream myfile ("form.txt",ios::out | ios::app | ios::binary);
    string data = "";
    string dum = "";
    int count = 1;
	while ( getline (myfile,line) )
    {
    	if(count != 7)
    	{
    		data += line + "\n";
    		dum += line + "\n";
		}
    	else
	  	{
	  		data += line;
    		dum += line;
	  		if(line == "status:	")
	  		{
	  			string statusdata;
	  			cout<<dum;
				cin.ignore();
	  			getline (cin, statusdata);
	  			cin>>statusdata;
				data += statusdata + "\n";
			}
			else
			{
				data += "\n";
			}
			dum = "";
			count = 0;
		}
		count++;
    }
    myfile.close();
	return data;
}


void adminmenue(string adminID, string adminPASS)
{
	int num;
	cout<<"\t\t\tMENU:"<<endl<<endl<<endl;
	cout<<"\t\t\t1- View All Records:"<<endl;
	cout<<"\t\t\t2- View un-updated status Records:"<<endl;
	cout<<"\t\t\t3- Search with CNIC Number:"<<endl;
	cout<<"\t\t\t0- Logout:"<<endl;
	cout<<"\t\t\tPlease Enter Choice:\t";
	cin>>num;
	switch(num)
	{
		case 1:
		{
			system("cls");
			displayRecords();
			cin.get();
			cin.get();
			system("cls");
			adminmenue(adminID, adminPASS);
			break;
		}
		case 2:
		{
			system("cls");
			string filedata = status();
			ofstream data;
			data.open ("form.txt", ios::out | ios::ate | ios::binary);
			if(filedata != "")
			{
				data<<filedata;
			}
			data.close();
			cin.get();
			cin.get();
			system("cls");
			adminmenue(adminID, adminPASS);
			break;
		}
		case 3:
		{
			string id;
			cout<<"Enter the CNIC Number:\t";
			cin>>id;
			cout<<search(id);
			cin.get();
			cin.get();
			system("cls");
			adminmenue(adminID, adminPASS);
			break;
		}
		case 0:
		{
			system("cls");
			start(adminID, adminPASS);
			break;
		}
	}
}

int main() {
		
		
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"\t\t\tW E L C O M E   T O   P O L I C I N G   W I T H-O U T   P O L I C E";
		PlaySound(TEXT("Voice.wAV"),NULL,SND_SYNC);
		Sleep(120);
		system("cls");

	string adminID = "023-19-0127";
	string adminPASS = "Dinkey";
	while(true)
	{
		start(adminID, adminPASS);
		cout<<endl<<endl;
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}
