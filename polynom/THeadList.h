#pragma once
#include "TList.h"

template <class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();
	void InsFirst(T value);
	void DelFirst();
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>;
	pHead->pNext = pHead;
	TList<T>::pFirst = TList<T>::pLast = TList<T>::pPrev = TList<T>::pCurr = TList<T>::pStop = pHead;
	TList<T>::length = 0;
}

template<class T>
THeadList<T>::~THeadList()
{
	TList<T>::~TList();
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(T value)
{
	TList<T>::InsFirst(value);
	pHead->pNext = TList<T>::pFirst;
}

template <class T>
void THeadList<T>::DelFirst()
{
	TList<T>::DelFirst();
	pHead->pNext = TList<T>::pFirst;
}