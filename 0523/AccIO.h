// AccIO.h

#pragma once

class AccIO {
private:
	int accid;
	int input;
	int output;
	int balance;
	tm date;

public:
	AccIO(int accid, int input, int output, int balance);

public:
	int getAccID() const { return accid; }

public:
	void Print() const;
};

