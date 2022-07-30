#include "BANK.h"
void account::create_account()
{
	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
