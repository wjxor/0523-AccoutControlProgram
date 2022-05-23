// AccountControl.h

#pragma once

#include "Account.h"
#include "WBArr.h"
#include "AccIO.h"
#include "WBList.h"

class AccountControl {
private:
	WBArr<Account*> accounts;	// ���� ����
	WBList<AccIO*> accios;		// �ŷ� ����

private:
	int AccIDtoIdx(int accid);

public:
	void MakeAccount();
	void PrintAllAccount();
	void SelectAccout();
	void InputAccout();
};