#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

class shopping {
	private:
	    int pcode;
	    float price;
	    float dis;
	    string pname;
	
	public:
	    void menu();
	    void administrator();
	    void buyer();
	    void add();
	    void edit();
	    void remove();
	    void list();
	    void receipt();
	    void remove(const char* filename);
};


void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t-----------------------------------------------------------\n";
	cout<<"\t\t\t\t																 \n";
	cout<<"\t					 Supermarket Billing System					 \n";
	cout<<"\t\t\t\t																 \n";
	cout<<"\t\t\t\t-----------------------------------------------------------\n";
	cout<<"\t\t\t\t																 \n";
	cout<<"\t\t\t\t|		1. Administrator		|\n";
	cout<<"\t\t\t\t|		     				|\n";
	cout<<"\t\t\t\t|		2. Buyer			|\n";
	cout<<"\t\t\t\t|		     				|\n";
	cout<<"\t\t\t\t|		3. Exit				|\n";
	cout<<"\t\t\t\t|		     				|\n";
	cout<<"\n\t\t\t\tPlease Select an option!"<<endl;
	cout<<"\t\t\t\tOption : ";
	cin>>choice;
	
	switch(choice){
		case 1:{
		
			cout<<"\n\n\n\t\t\t\tPlease Login!"<<endl;
			cout<<"\t\t\t\tEnter your email : ";
			cin>>email;
			cout<<"\t\t\t\tEnter your password : ";
			cin>>password;
			
//			if((email =="admin@email.com") && (password=="admin"))
			if((email =="admin") && (password=="admin"))
			{
				administrator();
			}
			else
			{
				cout<<"\n\t\t\t\tInvalid Email and Password\n\n";
			}
			break;
		}
		
		case 2:{
			buyer();
			break;
		}
		
		case 3:{
			exit(0);
			break;
		}
			
		default:{
			cout<<"\t\t\t\tPlease select from the given options!!!";
			break;
		}
	}
	goto m;
}

void shopping :: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\n\t\t\t\t|           Administrator Menu           |"<<endl;
	
	cout<<"\t\t\t\t|_____________1. Add Product_____________|\n";
	cout<<"\t\t\t\t|		     							\n";
	cout<<"\t\t\t\t|___________2. Modify Product____________|\n";
	cout<<"\t\t\t\t|		     							\n";
	cout<<"\t\t\t\t|___________3. Delete Product____________|\n";
	cout<<"\t\t\t\t|		     							\n";
	cout<<"\t\t\t\t|___________4. Return to main____________|\n";
	cout<<"\n\n\n\t\t\t\tPlease Enter your Choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			remove();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"\t\t\t\tInvalid Choice";
	}
	goto m;
}

void shopping :: buyer()
{
	m:
	int choice;
	
	cout<<"\n\n\n\t\t\t\t\t\tBuyer Menu\n";
	cout<<"\t\t\t\t|____________1. Buy Product______________|\n";
	cout<<"\t\t\t\t|		     							|\n";
	cout<<"\t\t\t\t|______________2. Go back________________|\n";
	cout<<"\n\n\n\t\t\t\tPlease Enter your Choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"\t\t\t\tInvalid Choice";
	}
	goto m;
}

void shopping :: add()
{	
	m:
	fstream data;
	int c, token = 0;
	float p, d;
	string n;
	
	cout<<"\n\n\n\t\t\t\t\t\tAdd Menu\n";
	cout<<"\n\t\t\t\tPlease Enter the Product Code : ";
	cin>>pcode;
	cout<<"\n\t\t\t\tPlease Enter the Product Name : ";
	cin>>pname;
	cout<<"\n\t\t\t\tPlease Enter the Product Price : ";
	cin>>price;
	cout<<"\n\t\t\t\tPlease Enter the Discount on the Product: ";
	cin>>dis;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	if(token == 1)
		goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	cout<<"\t\t\t\tRecord Inserted!"<<endl;
}

void shopping :: edit()
{
	fstream data, data1;
	int pkey, token = 0, c;
	float p, d;
	string n;
	
	cout<<"\t\t\t\t\t\t\Edit Menu"<<endl;
	cout<<"\nt\t\t\tPlease Enter the Product Code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\t\t\t\tFile does not exist!";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout<<"\n\t\t\t\tNew Code for the Product : ";
				cin>>c;
				cout<<"\n\t\t\t\tNew Name for the Product : ";
				cin>>n;
				cout<<"\n\t\t\t\tNew Price for the Product : ";
				cin>>p;
				cout<<"\n\t\t\t\tNew Discount on the Product : ";
				cin>>d;
				
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t\t\tRecord Edited!!"<<endl;
				token++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout<<"\t\t\t\tRecord Not Found!!";
		}
	}
}

void shopping :: remove()
{
	fstream data, data1;
	int pkey, token = 0;
	
	cout<<"\t\t\t\t\t\tDelete Menu"<<endl;
	cout<<"\nt\t\t\tPlease Enter the Product Code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\t\t\t\tFile does not exist!";
	}
	else
	{
		data1.open("database1.txt", ios::in|ios::app);
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof())
		{
			if(pcode == pkey)
			{
				cout<<"\t\t\t\tProduct Deleted Successfully";
				token++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout<<"\t\t\t\tRecord not Found!!";	
		}	
	}
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	
	cout<<"\t\t\t\t\t\t\tItem List"<<endl;
	
	cout<<"\t\t\t\t|_______________________________________________|\n";
	cout<<"\tProduct No.\t\tName\t\tPrice";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<endl;
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping :: receipt()
{
	fstream data;
	
	int arrc[100], arrq[100], c=0;
	char choice;
	float amount=0, dis=0, total=0;
	
	cout<<"\t\t\t\t|__________________________Order___________________________|\n";
	cout<<"\t\t\t\t|__________________________________________________________|\n";
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout<<"\n\n\n\t\t\t\tEMPTY DATABASE";
	}
	else
	{
		data.close();
		
		list();
		cout<<"\n\n";
		cout<<"\t\t\t\t|__________________________________________________________|\n";
		cout<<"\t\t\t\t|														  |\n";
		cout<<"\t\t\t\t|														  |\n";
		cout<<"\t\t\t\t|				Please Place the order					  |\n";
		cout<<"\t\t\t\t|														  |\n";
		cout<<"\t\t\t\t|__________________________________________________________|\n";
		
		do{
			m:
			cout<<"\n\n\t\t\t\tEnter Product Code : ";
			cin>>arrc[c];
			cout<<"\n\n\t\t\t\tEnter Product Quantity : ";
			cin>>arrq[c];
			
			for(int i = 0; i<c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout<<"\t\t\t\tDuplicate Product Code!! Please try again."<<endl;
					goto m;
				}
			}
			c++;
			
			cout<<"\n\t\t\t\tDo you want to buy another product? If yes please input 'y', else 'n'."<<endl<<"Your Choice : ";
			cin>>choice;
		}
		while(choice == 'y');
		

		cout<<"\t|_________________________RECEIPT__________________________|\n";
		cout<<"Product Name\tProduct Quantity\tRate\tAmount\tDiscounted Price\n";
		
		for(int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data>>pcode>>pname>>price>>dis;
			
			while(!data.eof())
			{
				if(pcode == arrc[i])
				{
					amount = price*arrq[i];
					dis = amount -(amount*dis/100);
					total = total + dis;
					cout<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
	}
	cout<<"\t\t\t\t|__________________________________________________________|\n";
	cout<<"\t\t\t\t|______________Total Amount : "<<total<<"__________________|\n";
}
void shopping::remove(const char* filename) {
    if (std::remove(filename) != 0) {
        std::cerr << "Error removing the file " << filename << std::endl;
    }
    else {
        std::cout << "File " << filename << " removed successfully." << std::endl;
    }
}


int main()
{
	shopping shop;
	
	shop.menu();
}
