// WBCollection.h

#pragma once

template<typename T>
class WBCollection {
public:
	// 순수가상함수(==추상메서드)
	virtual void Add(T value) = 0;
};

