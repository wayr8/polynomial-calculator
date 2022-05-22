#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
};

template <class T>
class TList
{
protected:
	int length;
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pPrev;
	TNode<T>* pCurr;
	TNode<T>* pStop;
public:
	TList();
	virtual ~TList();

	bool IsEmpty();
	bool IsNotEmpty();

	virtual void InsFirst(T value);
	void InsLast(T value);
	void InsCurr(T value);

	virtual void DelFirst();
	void DelCurr();

	T GetCurr();

	void Reset();
	void GoNext();
	bool IsEnd();
	bool IsNotEnd();

	string ToStr() const;

	friend ostream& operator<<(ostream& os, TList<T>& l)
	{
		TNode<T>* t = l.pFirst;

		while (t != l.pStop)
		{
			os << t->value << " ";
			t = t->pNext;
		}

		return os;
	}
};

template <class T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pLast = pPrev = pCurr = pStop;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template <class T>
bool TList<T>::IsEmpty()
{
	return pFirst == pStop;
}

template <class T>
bool TList<T>::IsNotEmpty()
{
	return pFirst != pStop;
}

template <class T>
void TList<T>::InsFirst(T value)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->value = value;
	newNode->pNext = pFirst;
	pFirst = newNode;
	length++;
	if (length == 1)
		pLast = pFirst;
}

template <class T>
void TList<T>::InsLast(T value)
{
	if (length > 0)
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = value;
		newNode->pNext = pStop;

		pLast->pNext = newNode;
		pLast = newNode;
		length++;
	}
	else
	{
		InsFirst(value);
	}
}

template <class T>
void TList<T>::InsCurr(T value)
{
	if (pCurr == pFirst)
	{
		InsFirst(value);
		pPrev = pFirst;
	}
	else if (pPrev == pLast)
	{
		InsLast(value);
		pPrev = pLast;
	}
	else
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = value;

		newNode->pNext = pCurr;
		pPrev->pNext = newNode;
		pCurr = newNode;
		length++;
	}
}

template <class T>
void TList<T>::DelFirst()
{
	if (pFirst == pStop)
		throw "Can't delete first value";

	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	length--;
}

template <class T>
void TList<T>::DelCurr()
{
	if (pCurr == pStop)
		throw "Can't delete current value";

	if (pCurr == pFirst)
	{
		DelFirst();
		pPrev = pStop;
		pCurr = pFirst;
	}
	else
	{
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPrev->pNext = pCurr;
		delete tmp;
		length--;
	}
}

template <class T>
T TList<T>::GetCurr()
{
	if (pCurr == pStop)
		throw "Can't get current value";
	return pCurr->value;
}

template <class T>
void TList<T>::Reset()
{
	pPrev = pStop;
	pCurr = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurr == pStop;
}

template <class T>
bool TList<T>::IsNotEnd()
{
	return pCurr != pStop;
}

template <class T>
string TList<T>::ToStr() const
{
	stringstream ss;
	TNode<T>* t = this->pFirst;

	if (pFirst == pStop)
	{
		ss << "0";
		return ss.str();
	}
	else
	{
		while (t != pStop)
		{
			ss << t->value << " ";
			t = t->pNext;
		}
		return ss.str();
	}
}