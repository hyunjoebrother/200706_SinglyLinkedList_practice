//Singly Linked List를 구현해보자 realize
//아까는 string. 이번에는 template을 이용하여 임의의 type

#include <string>
#include <iostream>
using namespace std;

template <typename E>
class SNode //새로운 단위 node 
{
private:
	E elem; //원소값 정보
	SNode<E>* next; //리스트의 다음 항목

	friend class SLinkedList<E>; //friend로 클래스에 접근 제공
};

template <typename E>
class SLinkedList //문자열의 LinkedList
{
private:
	SNode<E>* head; //리스트의 head를 가리키는 포인터

public:
	bool empty() const; //리스트가 비어있는가?
	const E& front() const; //이전 원소를 얻는다

	void addFront(const E& e); //리스트의 앞 head에서 추가한다
	void removeFront(); //앞 head의 리스트 항목을 삭제한다.

	//생성자 -> head 포인터를 비어있는 리스트로 만든다
	SLinkedList();

	//소멸자 -> 리스트에 있는 원소들을 반복적으로 삭제한다
	~SLinkedList();
};

template <typename E>
bool SLinkedList<E>::empty() const
{
	return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const
{
	return head->elem;
}

//Inserting at Head
template <typename E>
void SLinkedList<E>::addFront(const E& e)
{
	//공간 v를 할당받아서 새로운 node를 만든다
	SNode<E>* v = new SNode<E>;
	//v에 새로운 데이터 값을 넣는다
	v->elem = e;
	//연결 선울 만든다
	v->next = head;
	//새로운 head는 v다
	head = v;
}

//Removing at Head
template <typename E>
void SLinkedList<E>::removeFront()
{
	//head를 v에서 다음 node로 옮겨준다
	SNode<E>* old = head;
	head = old->next;
	//node 삭제 delete로 공간 반환
	delete old;
}

//생성자
template <typename E>
SLinkedList<E>::SLinkedList()
	: head(NULL) { }

//소멸자
template <typename E>
SLinkedList<E>::~SLinkedList()
{
	while (!empty())
		removeFront();
}
