//wbarr.h

#pragma once

#include "WBCollection.h"

template<typename T>
class WBArr : public WBCollection<T>
{
private:
	T* arr;  //동적배열  <================= T타입을 저장하겠다.
	int max;
	int size;

public:
	WBArr(int _max = 10);
	~WBArr();

public:
	int getsize();
	T getdata(int idx);   //<============

public:
	void Add(T value) {
		if (push_back(value) == false)
			throw "저장 실패";
	}

public:
	//저장(insert)
	bool push_back(T value); //<=========

	//삭제(delete)
	bool erase(int idx);
};

template<typename T>
WBArr<T>::WBArr(int _max /*= 10*/)
{
	max = _max;
	size = 0;
	arr = new T[max];
}

template<typename T>
WBArr<T>::~WBArr()
{
	delete[] arr;
}

template<typename T>
int WBArr<T>::getsize()
{
	return size;
}

template<typename T>
T WBArr<T>::getdata(int idx)
{
	return arr[idx];
}

template<typename T>
bool WBArr<T>::push_back(T value)
{
	if (max <= size)
		return false;

	arr[size] = value;
	size++;
	return true;
}

template<typename T>
bool WBArr<T>::erase(int idx)
{
	if (size <= 0)
		return false;

	for (int i = idx; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
	return true;
}