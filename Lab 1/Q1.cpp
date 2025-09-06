
#include <iostream>
using namespace std;

class BankAccount{
public:
	int account;
	float balance;
	string name;

BankAccount(){
	account=1;
	balance=5000;
	name="asad";
}	
BankAccount(int account, float balance, string name){
	this->account = account;
	this->balance = balance;
	this->name = name;
}	
void Display(){
	cout<<"Your account number is: "<<account<<"\nYour balance is: $"<<balance<<"\nYour name is: "<<name<<endl;
}
};
int main(){
	BankAccount Account2(2,1000,"Robert Lewandowski");
	Account2.Display();
	
	cout<<"-----------------------\n";
	BankAccount Account1;
	Account1.Display();
	
	cout<<"-----------------------\n";
	
	BankAccount Account3(Account2);
	cout<<"This is details of Bank account 3 BEFORE deduction: \n";
	Account3.Display();
	
	cout<<"-----------------------\n";
	
	Account3.balance=Account3.balance-200;
	
	cout<<"This is details of Bank account 3 AFTER deduction: \n";
	Account3.Display();
	
	cout<<"-----------------------\n";
	
	cout<<"This is details of Bank account 2 (to make sure it remains the same): \n";
	Account2.Display();
	
	
	return 0;
}
