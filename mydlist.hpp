#include <iostream>

template<typename T>
class MyNode
{
private:
	T* e;
	MyNode<T>* n;
	MyNode<T>* p;

public:
	void set(T* in) { this->e = in; }
	T* get() { return this->e; }
	void setNext(MyNode<T>* newnext) { n = newnext; }
	MyNode<T>* getNext() { return this->n; }
	void setPrev(MyNode<T>* newprev) { p = newprev; }
	MyNode<T>* getPrev() { return this->p; }
};

template<typename T>
class MyDoublyLinkedList
{
private:
	MyNode<T>* head;  // sentinel
	MyNode<T>* tail;  // sentinel
	int isize;

public:
	MyDoublyLinkedList()
	{
		head = new MyNode<T>();
		tail = new MyNode<T>();
		head->setNext(tail);
		head->setPrev(nullptr);
		tail->setPrev(head);
		tail->setNext(nullptr);
		isize = 0;
	}

	~MyDoublyLinkedList()
	{
		MyNode<T>* cur = head->getNext();
		while (cur != tail)
		{
			MyNode<T>* next = cur->getNext();
			delete cur;
			cur = next;
		}
		delete head;
		delete tail;
	}

	bool isEmpty()
	{
		return isize == 0;
	}

	int getSize()
	{
		return isize;
	}


	MyNode<T>* getHeadNode()
	{
		return head->getNext();
	}

	MyNode<T>* getTailNode()
	{
		return tail->getPrev();
	}

	void addToHead(T* in)
	{
		MyNode<T>* node = new MyNode<T>();
		node->set(in);
		node->setNext(head->getNext());
		node->setPrev(head);
		head->getNext()->setPrev(node);
		head->setNext(node);
		isize++;
	}

	void removeFromHead()
	{
		if (isEmpty()) return;
		MyNode<T>* node = head->getNext();
		head->setNext(node->getNext());
		node->getNext()->setPrev(head);
		delete node;
		isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T>* node = new MyNode<T>();
		node->set(in);
		node->setPrev(tail->getPrev());
		node->setNext(tail);
		tail->getPrev()->setNext(node);
		tail->setPrev(node);
		isize++;
	}

	void removeFromTail()
	{
		if (isEmpty()) return;
		MyNode<T>* node = tail->getPrev();
		tail->setPrev(node->getPrev());
		node->getPrev()->setNext(tail);
		delete node;
		isize--;
	}
};
