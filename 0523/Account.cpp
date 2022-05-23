// Account.cpp

#include <iostream>
using namespace std;
#include "WBLibrary.h"
#include "Account.h"

int Account::s_accid = 1000;

Account::Account(string name, int balance) {
	this->accid = s_accid;
	this->name = name;
	this->balance = balance;
	this->date = WBLibrary::NowDate();

	s_accid = s_accid + 10;

}

void Account::InputMoney(int money) {
	if (money <= 0)
		throw "�߸��� �ݾ��Դϴ�.";
	
	balance = balance + money;
}

void Account::OutputMoney(int money) {
	if (money <= 0)
		throw "�߸��� �ݾ��Դϴ�.";
	else if (money > balance)
		throw "�ܾ��� �����մϴ�.";

	balance = balance - money;
}

void Account::Print() const {
	cout << accid << "\t" << name << "\t" << balance << "��" << endl;
}

void Account::Println() const {
	cout << "���¹�ȣ : " << accid << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ܾ� : " << balance << "��" << endl;
	cout << "�������� : " << WBLibrary::GetDay(date) << endl;
	cout << "�����ð� : " << WBLibrary::GetTime(date) << endl;

}