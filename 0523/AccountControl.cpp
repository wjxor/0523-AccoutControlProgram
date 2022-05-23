// AccountControl.cpp

#include <iostream>
using namespace std;
#include "AccountControl.h"
#include "Account.h"
#include "WBLibrary.h"

// insert
void AccountControl::MakeAccount() {
	try {
		string name = WBLibrary::InputString("이름");
		int money = WBLibrary::InputNumber("입금액");

		Account* acc = new Account(name, money);

		accounts.Add(acc);
		// ----------------------insert 완료---------------
		AccIO* accio = new AccIO(acc->GetAccId(), money, 0, money);
		accios.Add(accio);
		// ------------------------------------------------

		cout << "저장되었습니다." << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	
}

// selectall
void AccountControl::PrintAllAccount() {
	cout << "[저장개수] " << accounts.getsize() << endl;

	for (int i = 0; i < accounts.getsize(); i++) {
		Account* pacc = accounts.getdata(i);
		pacc->Print();
	}

	printf("\n");

}

// select알고리즘
int AccountControl::AccIDtoIdx(int accid) {

	for (int i = 0; i < accounts.getsize(); i++) {
		Account* pacc = accounts.getdata(i);
		if (pacc->GetAccId() == accid)
			return i;
	}
	throw "없는 계좌번호";	//return -1;
}

// select
void AccountControl::SelectAccout() {
	try {
		int accnumber = WBLibrary::InputNumber("계좌번호");
		int idx = AccIDtoIdx(accnumber);
		Account* pacc = accounts.getdata(idx);
		pacc->Println();
		// -------------- accnumber에 해당되는 거래 내역을 출력 ------
		WBList<AccIO*>::node* cur = accios.gethead();
		while (cur != NULL) {
			AccIO* pio = cur->data;
			if (pio->getAccID() == accnumber)
				pio->Print();

			cur = cur->next;
		}

		// -----------------------------------------------------------
	}

	catch (const char* msg) {
		cout << msg << endl;
	}

}

// update
void AccountControl::InputAccout() {
	try {
		int accid = WBLibrary::InputNumber("계좌번호");
		int money = WBLibrary::InputNumber("입금액");
		int idx = AccIDtoIdx(accid);
		Account* pacc = accounts.getdata(idx);
		pacc->InputMoney(money);
		// ------------------------------------------------------
		// 거래내역
		AccIO* accio = new AccIO(accid, money, 0, pacc->GetBalance());
		accios.Add(accio);

		cout << "입금성공" << endl;

	}
	catch (const char* msg) {
		cout << msg << endl;
	}
}