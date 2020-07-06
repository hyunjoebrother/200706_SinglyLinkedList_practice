//Singly Linked List�� �����غ��� realize
//�ϳ��� �ٷ� ����, ���� data�� ��� �ִ��� �ּҰ��� �����ؾ��Ѵ�.

#include <string>
#include <iostream>
using namespace std;

class StringNode //���ο� ���� node 
{
private:
	string elem; //���Ұ� ����
	StringNode* next; //����Ʈ�� ���� �׸�

	friend class StringLinkedList; //friend�� Ŭ������ ���� ����
};

class StringLinkedList //���ڿ��� LinkedList
{
private:
	StringNode* head; //����Ʈ�� head�� ����Ű�� ������

public:
	bool empty() const; //����Ʈ�� ����ִ°�?
	const string& front() const; //���� ���Ҹ� ��´�

	void addFront(const string& e); //����Ʈ�� �� head���� �߰��Ѵ�
	void removeFront(); //�� head�� ����Ʈ �׸��� �����Ѵ�.

	//������ -> head �����͸� ����ִ� ����Ʈ�� �����
	StringLinkedList();

	//�Ҹ��� -> ����Ʈ�� �ִ� ���ҵ��� �ݺ������� �����Ѵ�
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
	//���� v�� �Ҵ�޾Ƽ� ���ο� node�� �����
	StringNode* v = new StringNode;
	//v�� ���ο� ������ ���� �ִ´�
	v->elem = e;
	//���� ���� �����
	v->next = head;
	//���ο� head�� v��
	head = v;
}

//Removing at Head
void StringLinkedList::removeFront()
{
	//head�� v���� ���� node�� �Ű��ش�
	StringNode* old = head;
	head = old->next;
	//node ���� delete�� ���� ��ȯ
	delete old;
}

//������
StringLinkedList::StringLinkedList()
	: head(NULL) { }

//�Ҹ���
StringLinkedList::~StringLinkedList()
{
	while (!empty())
		removeFront();
}
