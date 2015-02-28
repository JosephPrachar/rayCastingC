#pragma once


template <class aType> class LinkedList{
public:
	LinkedList(aType starting):
		mHead(starting, NULL)	
	{
		this->mLength = 0;
	}


	void add(aType toAdd){
		if (this->mLength == 0){
			this->mHead = LinkedListNode<aType>(toAdd, NULL);
			this->mHead.mNext = &this->mHead;
			this->mLength++;
		}
		else{
			LinkedListNode<aType> nodeToAdd = LinkedListNode<aType>(toAdd, this->mHead.mNext);
			this->mHead.mNext = &nodeToAdd;
		}
	}
	int getLength(){
		return this->mLength;
	}
	aType* toArray(){
		aType* toReturn = new aType[this->mLength];

		for (int i = 0; i < this->mLength; ++i){
			toReturn[i] = mHead.mData;
			this->advance();
		}

		return toReturn;
	}

private:
	LinkedListNode<aType> mHead;
	int mLength;

	void advance(){
		this->mHead = *this->mHead.mNext;
	}
};