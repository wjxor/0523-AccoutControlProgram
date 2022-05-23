// WBLibrary.h

#pragma once

class WBLibrary {
	// 입력 기능
public:
	static string InputString(string msg);
	static int InputNumber(string msg);


//날짜 정보
public:
	static tm NowDate();
	static string GetTime(tm date);
	static string GetDay(tm date);
};

