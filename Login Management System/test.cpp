#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User{
	private:
		string username, password;
	
	public:
		User(string name, string pass)
		{
			username = name;
			password = pass;
		}
		string getUser(){
			return username;
		}
		string getPassword(){
			return password;
		}
};

class UserManager{
	private:
		vector<User> users; //create object of vector
	
	public:
		void registerUser(){
			string username, password;
			cout<<"\n\t\tEnter Username : ";
			cin>>username;
			
			cout<<"\t\tEnter Password : ";
			cin>>password;
			
			User newUser(username, password);
			users.push_back(newUser);
			
			cout<<"\t\tUser Registered Successfully"<<endl;
		}
		
		bool LoginUser(string name, string pass){
			for(int i=0; i<users.size();i++){
				if((users[i].getUser() == name) && (users[i].getPassword() == pass)){
					cout<<"\t\tLogin Successful!";
					return true;
				}
				cout<<"\n\t\tInvalid Username or Password"<<endl;
				return false;
			}
		}
		
		void showUser(){
			cout<<"\n\n\t\t\t\tUsers List"<<endl;
			for(int i=0; i<users.size(); i++){
				cout<<"\t\t\t"<<users[i].getUser()<<endl;
			}
		}
		
		void searchUser(string username){
			for(int i=0; i<users.size();i++){
				if(users[i].getUser() == username){
					cout<<"\n\t\tUser found";
				}
			}
		}
		
		void deleteUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUser() == username){
					users.erase(users.begin()+i);
					cout<<"\n\t\tUser deleted successfully";
				}
			}
		}
};

main(){
	UserManager usermanager;
	
	int op;
	char choice;
	
	do{
		system("cls");
		cout<<"\n\n\t\t1. Register User"<<endl;
		cout<<"\t\t2. Login"<<endl;
		cout<<"\t\t3. Show User List"<<endl;
		cout<<"\t\t4. Search User"<<endl;
		cout<<"\t\t5. Delete User"<<endl;
		cout<<"\t\t6. Exit"<<endl;
		
		cout<<"\t\tEnter your Choice:";
		cin>>op;
		
		switch(op){
			case 1:
				usermanager.registerUser();
				break;
			case 2:{
				string name, pass;
				
				cout<<"\n\t\tEnter Username : ";
				cin>>name;
				cout<<"\t\tEnter Password : ";
				cin>>pass;
				usermanager.LoginUser(name, pass);
				break;
				}
			case 3:
				usermanager.showUser();
				break;
			case 4:{
				string user;
				
				cout<<"\n\t\tEnter Username : ";
				cin>>user;
				
				usermanager.searchUser(user);
				break;
			}
			case 5:{
				string user;
				
				cout<<"\n\t\tEnter Username : ";
				cin>>user;
				
				usermanager.deleteUser(user);
				break;
			}
			case 6:
				exit(1);
		}
		
		cout<<"\n\n\t\tDo you want to continue? [y/n] :";
		cin>>choice;
	}while(choice == 'y');
}
