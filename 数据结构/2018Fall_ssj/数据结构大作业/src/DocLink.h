#pragma once
#include <iostream>
#include <direct.h>
#include <fstream>
#include "CharString.h"

using namespace std;

class info//�洢�ĵ���źͳ��ִ���
{
public:
	int article_id;//�ĵ����
	int num;//���ִ���
	info(int article_id, int num) :article_id(article_id), num(num) {}
	info() :article_id(-1), num(0) {}
	info& operator=(const info& in);
};

class DocNode//�ĵ��ڵ�
{
public:
	info data;
	DocNode* next;
	DocNode() { next = NULL; }
};

class DocLink
{
private:
	DocNode *head;
	int len;
public:
	DocLink() { head = NULL; len = 0; }
	int GetLength();
	info GetInfo(int pos);
	bool Edit(info in);//����ͬ�ĵ���ŵ�num��ӣ�����������ĺ���
	int Search(int article_id);
	bool Add(int article_id);//��ӽڵ㣬���ʱ��������򣬽�Ϊ��
	bool Remove(int article_id);
	void Traverse();
	void FileTraverse(wofstream& output);//���������this���ĵ��������Ϣд�뵽�ļ�
	void addto(DocLink* p1);//���������this���ĵ������е��������ӵ�p1����
};
