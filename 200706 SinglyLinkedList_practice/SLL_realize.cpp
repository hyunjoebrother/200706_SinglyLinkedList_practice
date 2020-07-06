//Singly Linked List를 구현해보자 realize
//하나의 줄로 연결, 다음 data는 어디에 있는지 주소값을 저장해야한다.

#include <string>
#include <iostream>
using namespace std;

class StringNode //새로운 단위 node 
{
private:
	string elem; //원소값 정보
	StringNode* next; //리스트의 다음 항목

	friend class StringLinkedList; //friend로 클래스에 접근 제공
};

class StringLinkedList //문자열의 LinkedList
{
private:
	StringNode* head; //리스트의 head를 가리키는 포인터

public:
	bool empty() const; //리스트가 비어있는가?
	const string& front() const; //이전 원소를 얻는다

	void addFront(const string& e); //리스트의 앞 head에서 추가한다
	void removeFront(); //앞 head의 리스트 항목을 삭제한다.

	//생성자 -> head 포인터를 비어있는 리스트로 만든다
	StringLinkedList();

	//소멸자 -> 리스트에 있는 원소들을 반복적으로 삭제한다
	~StringLinkedList();
};

bool StringLinkedList::empty() const
{
	return head == NULL;
}

const string& StringLinkedList::front() const
{
	return head->elem;
}

//Inserting at Head
void StringLinkedList::addFront(const string& e)
{
	//공간 v를 할당받아서 새로운 node를 만든다
	StringNode* v = new StringNode;
	//v에 새로운 데이터 값을 넣는다
	v->elem = e;
	//연결 선울 만든다
	v->next = head;
	//새로운 head는 v다
	head = v;
}

//Removing at Head
void StringLinkedList::removeFront()
{
	//head를 v에서 다음 node로 옮겨준다
	StringNode* old = head;
	head = old->next;
	//node 삭제 delete로 공간 반환
	delete old;
}

//생성자
StringLinkedList::StringLinkedList()
	: head(NULL) { }

//소멸자
StringLinkedList::~StringLinkedList()
{
	while (!empty())
		removeFront();
}
