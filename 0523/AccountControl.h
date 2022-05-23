// AccountControl.h

#pragma once

#include "Account.h"
#include "WBArr.h"
#include "AccIO.h"
#include "WBList.h"

class AccountControl {
private:
	WBArr<Account*> accounts;	// 계좌 내역
	WBList<AccIO*> accios;		// 거래 내역

private:
	int AccIDtoIdx(int accid);

public:
	void MakeAccount();
	void PrintAllAccount();
	void SelectAccout();
	void InputAccout();
};