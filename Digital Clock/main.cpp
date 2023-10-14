#include<iostream>
#include<iomanip> //for setwidth and setfill
using namespace std;

class digitalC{
	private:
		int hours, minutes, seconds;
		
	public:
		digitalC(){
			int h, m, s;
			cout<<"Enter Hours : ";
			cin>>h;
			cout<<"Enter Minutes : ";
			cin>>m;
			cout<<"Enter Seconds : ";
			cin>>s;
			
			hours = h;
			minutes = m;
			seconds = s;
		}
		
		void displayTime(){
			cout<<"\n\n";
			if(hours<10){
				cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";
			}
			else if(minutes<10){
				cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";
			}
			else if(seconds<10){
				cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";
			}
			
			if(hours >= 12)
				cout<<"PM";
			else
				cout<<"AM";
		}
};

main(){
	digitalC clock;
	
	clock.displayTime();
}
