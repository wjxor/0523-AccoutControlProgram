// WBLibrary.h

#pragma once

class WBLibrary {
	// �Է� ���
public:
	static string InputString(string msg);
	static int InputNumber(string msg);


//��¥ ����
public:
	static tm NowDate();
	static string GetTime(tm date);
	static string GetDay(tm date);
};

