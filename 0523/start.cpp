// Start.cpp

#include <iostream>
using namespace std;

#include "AccountControl.h"

int main() {
	AccountControl con;
	con.MakeAccount();
	con.MakeAccount();
	con.MakeAccount();
	
	con.PrintAllAccount();

	con.InputAccout();
	con.InputAccout();

	con.SelectAccout();

	return 0;
}