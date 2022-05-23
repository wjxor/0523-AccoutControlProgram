// AccountControl.cpp

#include <iostream>
using namespace std;
#include "AccountControl.h"
#include "Account.h"
#include "WBLibrary.h"

// insert
void AccountControl::MakeAccount() {
	try {
		string name = WBLibrary::InputString("�̸�");
		int money = WBLibrary::InputNumber("�Աݾ�");

		Account* acc = new Account(name, money);

		accounts.Add(acc);
		// ----------------------insert �Ϸ�---------------
		AccIO* accio = new AccIO(acc->GetAccId(), money, 0, money);
		accios.Add(accio);
		// ------------------------------------------------

		cout << "����Ǿ����ϴ�." << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	
}

// selectall
void AccountControl::PrintAllAccount() {
	cout << "[���尳��] " << accounts.getsize() << endl;

	for (int i = 0; i < accounts.getsize(); i++) {
		Account* pacc = accounts.getdata(i);
		pacc->Print();
	}

	printf("\n");

}

// select�˰���
int AccountControl::AccIDtoIdx(int accid) {

	for (int i = 0; i < accounts.getsize(); i++) {
		Account* pacc = accounts.getdata(i);
		if (pacc->GetAccId() == accid)
			return i;
	}
	throw "���� ���¹�ȣ";	//return -1;
}

// select
void AccountControl::SelectAccout() {
	try {
		int accnumber = WBLibrary::InputNumber("���¹�ȣ");
		int idx = AccIDtoIdx(accnumber);
		Account* pacc = accounts.getdata(idx);
		pacc->Println();
		// -------------- accnumber�� �ش�Ǵ� �ŷ� ������ ��� ------
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
		int accid = WBLibrary::InputNumber("���¹�ȣ");
		int money = WBLibrary::InputNumber("�Աݾ�");
		int idx = AccIDtoIdx(accid);
		Account* pacc = accounts.getdata(idx);
		pacc->InputMoney(money);
		// ------------------------------------------------------
		// �ŷ�����
		AccIO* accio = new AccIO(accid, money, 0, pacc->GetBalance());
		accios.Add(accio);

		cout << "�Աݼ���" << endl;

	}
	catch (const char* msg) {
		cout << msg << endl;
	}
}