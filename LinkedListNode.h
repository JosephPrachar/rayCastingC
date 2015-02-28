#pragma once

template <class aType> class LinkedListNode{
public:
	LinkedListNode(aType data, LinkedListNode* next):
		mData(data)
	{
		this->mNext = next;
	}
	
	aType mData;
	LinkedListNode* mNext;
};
