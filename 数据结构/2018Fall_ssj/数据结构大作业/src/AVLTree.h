#pragma once
#include <iostream>
#include "CharString.h"
#include "DocLink.h"

using namespace std;



class AVLTreeNode
{
public:
	CharString key;//�洢�����ַ��������У��Ƚϴ�С�����ַ����ıȽϴ�С
	int height;
	AVLTreeNode *lchild;
	AVLTreeNode *rchild;
	DocLink* doc;//�洢���ַ�����Ӧ���ĵ�����
	AVLTreeNode(CharString k, AVLTreeNode *l, AVLTreeNode *r) :
		key(k), height(0), lchild(l), rchild(r)
	{
		doc = new DocLink;
	}
	~AVLTreeNode()
	{
		delete doc;
	}
};

class AVLTree
{
private:
	AVLTreeNode* root;
public:
	AVLTree();
	~AVLTree();

	int GetHeight();
	void initConnection(double** connection);
	AVLTreeNode* Search(CharString key);//Ҫ��ʵ�ֵĽӿ�
	void Insert(CharString ket, int article_id);//Ҫ��ʵ�ֵĽӿ�
private:
	void initConnection(AVLTreeNode* root, double** connection);//�����ĵ�֮��Ĺ�ϵ���Ƽ�ʱʹ��
		//��һ��781*781��double���;��󣬱�ʾ�ĵ�i��j����ϵֵ��С
	void Adjust(AVLTreeNode* &root);//Ҫ��ʵ�ֵĽӿ�
	void LL(AVLTreeNode* &k2);//˫����
	void RR(AVLTreeNode* &k2);//˫����
	void LR(AVLTreeNode* &k2);//����������
	void RL(AVLTreeNode* &k2);//����������
	void Destroy(AVLTreeNode* &root);
	int GetHeight(AVLTreeNode* root);
	void Insert(AVLTreeNode* &root, CharString key, int article_id);
};