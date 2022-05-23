// Account.h

#pragma once

// static 멤버필드[생성된 모든 객체들이 공유]---------
// 계좌번호는 자동생성
// (계좌번호 시작 : 1000번, +10번...)
// ---------------------------------------------------
class Account {
private:
	// 클래스멤버(단 하나만 생성-> 객체들이 공유해서 사용)
	// 클래스외부에서 초기화를 한다-> main함수 전에 생성이 된다.
	static int s_accid;

	// 인스턴스멤버(객체 생성될 때 객체마다 생성되는 저장공간)
	int accid;
	string name;
	int balance;
	struct tm date;		// 가입일시

public:
	Account(string name, int balance);

public:
	int GetAccId() const {
		return accid;
	}

	int GetBalance() const{
		return balance;
	}

public:
	void InputMoney(int money);

	void OutputMoney(int money);

	void Print() const;

	void Println() const;
};