// AccIO.cpp

#include <iostream>
using namespace std;
#include "WBLibrary.h"
#include "AccIO.h"

AccIO::AccIO(int accid, int input, int output, int balance) {
	this->accid = accid;
	this->input = input;
	this->output = output;
	this->balance = balance;
	date = WBLibrary::NowDate();
}

void AccIO::Print() const {
	cout << accid << "\t";
	cout << input << "��\t";
	cout << output << "��\t";
	cout << balance << "��\t";
	cout << WBLibrary::GetDay(date) << "\t";
	cout << WBLibrary::GetTime(date) << endl;
}