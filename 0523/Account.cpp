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
		throw "잘못된 금액입니다.";
	
	balance = balance + money;
}

void Account::OutputMoney(int money) {
	if (money <= 0)
		throw "잘못된 금액입니다.";
	else if (money > balance)
		throw "잔액이 부족합니다.";

	balance = balance - money;
}

void Account::Print() const {
	cout << accid << "\t" << name << "\t" << balance << "원" << endl;
}

void Account::Println() const {
	cout << "계좌번호 : " << accid << endl;
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << balance << "원" << endl;
	cout << "개설일자 : " << WBLibrary::GetDay(date) << endl;
	cout << "개설시간 : " << WBLibrary::GetTime(date) << endl;

}