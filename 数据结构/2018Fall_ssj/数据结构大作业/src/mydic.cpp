#include "pch.h"
#include "mydic.h"

MyDicNode::MyDicNode()
{
	head = this;
	next = NULL;
	down = NULL;
	endmark = 0;
}

void MyDicNode::insert(CharString str)
{
	int len = str.getSize();
	MyDicNode* m_present = this->down;
	MyDicNode* m_up = this;
	MyDicNode *p;
	for (int i = 0; i < len; i++)
	{
		p = this->findNode_not(m_present, str[i]);
		if (p == NULL)
		{
			MyDicNode* q = new MyDicNode;
			q->data = str[i];
			m_up->down = q;
			m_up = q;
			m_present = q->down;//�Խ��ͣ���ͬ��NULL
			if (i == len - 1)
			{
				q->endmark = 1;
			}
		}
		else
		{
			if (p->next == NULL && p->data != str[i])
			{
				MyDicNode* q = new MyDicNode;
				q->data = str[i];
				p->next = q;
				m_up = q;
				m_present = q->down;//�Խ��ͣ���ͬ��NULL
				if (i == len - 1)
				{
					q->endmark = 1;
				}
			}
			else if(p->next == NULL && p->data == str[i])
			{
				m_up = p;
				m_present = p->down;
				if (i == len - 1)
				{
					p->endmark = 1;
				}
			}
			else if (p->next != NULL)
			{
				m_up = p;
				m_present = p->down;
				if (i == len - 1)
				{
					p->endmark = 1;
				}
			}
		}
	}
}

MyDicNode * MyDicNode::findNode_not(MyDicNode * first, wchar_t c)//����ҵ������ҵ�����һ�������û�ҵ��������һ��
{
	MyDicNode* p = first;
	if (first == NULL)
	{
		return NULL;
	}
	while (p->data != c)
	{
		if (p->next == NULL)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

MyDicNode * MyDicNode::findNode(MyDicNode * first, wchar_t c)
{
	MyDicNode* p = first;
	if (first == NULL)
	{
		return NULL;
	}
	while (p->data != c)
	{
		if (p->next == NULL)
		{
			return NULL;
		}
		p = p->next;
	}
	return p;
}

bool MyDicNode::findString(CharString str)
{
	int len = str.getSize();
	MyDicNode* first = this->down;
	MyDicNode* f;
	if (len == 0)
		return false;
	for (int i = 0; i < len; i++)
	{
		f = findNode(first, str[i]);
		if (f == NULL)
		{
			return false;
		}
		
		if (i == len - 1)
		{
			if (f->endmark == 1)
			{
				return true;
			}
		}
		first = f->down;
	}
	return false;
}
