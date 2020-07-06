//Singly Linked List�� �����غ��� realize
//�Ʊ�� string. �̹����� template�� �̿��Ͽ� ������ type

#include <string>
#include <iostream>
using namespace std;

template <typename E>
class SNode //���ο� ���� node 
{
private:
	E elem; //���Ұ� ����
	SNode<E>* next; //����Ʈ�� ���� �׸�

	friend class SLinkedList<E>; //friend�� Ŭ������ ���� ����
};

template <typename E>
class SLinkedList //���ڿ��� LinkedList
{
private:
	SNode<E>* head; //����Ʈ�� head�� ����Ű�� ������

public:
	bool empty() const; //����Ʈ�� ����ִ°�?
	const E& front() const; //���� ���Ҹ� ��´�

	void addFront(const E& e); //����Ʈ�� �� head���� �߰��Ѵ�
	void removeFront(); //�� head�� ����Ʈ �׸��� �����Ѵ�.

	//������ -> head �����͸� ����ִ� ����Ʈ�� �����
	SLinkedList();

	//�Ҹ��� -> ����Ʈ�� �ִ� ���ҵ��� �ݺ������� �����Ѵ�
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
	//���� v�� �Ҵ�޾Ƽ� ���ο� node�� �����
	SNode<E>* v = new SNode<E>;
	//v�� ���ο� ������ ���� �ִ´�
	v->elem = e;
	//���� ���� �����
	v->next = head;
	//���ο� head�� v��
	head = v;
}

//Removing at Head
template <typename E>
void SLinkedList<E>::removeFront()
{
	//head�� v���� ���� node�� �Ű��ش�
	SNode<E>* old = head;
	head = old->next;
	//node ���� delete�� ���� ��ȯ
	delete old;
}

//������
template <typename E>
SLinkedList<E>::SLinkedList()
	: head(NULL) { }

//�Ҹ���
template <typename E>
SLinkedList<E>::~SLinkedList()
{
	while (!empty())
		removeFront();
}
