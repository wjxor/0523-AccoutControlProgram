// WBLibrary.cpp

#include <iostream>
using namespace std;
#include "WBLibrary.h"

string WBLibrary::InputString(string msg) {
	cout << msg << " : ";

	string input;
	cin >> input;

	return input;
}

int WBLibrary::InputNumber(string msg) {
	cout << msg << " : ";

	int number;
	cin >> number;

	return number;
}

tm WBLibrary::NowDate() {
	tm temp;

	time_t timer = time(NULL);
	localtime_s(&temp, &timer);

	return temp;
}

string WBLibrary::GetTime(tm date) {
	char temp[50];
	sprintf_s(temp, "%02d:%02d:%02d",
		date.tm_hour, date.tm_min, date.tm_sec);
	return temp;
}

string WBLibrary::GetDay(tm date) {
	int year = date.tm_year + 1900;
	int month = date.tm_mon + 1;
	int day = date.tm_mday;

	char temp[50];
	sprintf_s(temp, "%04d-%02d-%02d", year, month, day);
	return temp;

}