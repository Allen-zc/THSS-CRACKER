#pragma once

#include<algorithm>
#include<iostream>
#include<cstring>

class mat {
private:
	int n, *a;
	int row;	// ����ÿ����ʼλ��֮��Ĳ���
				// Ӧ����Ϊ���2���ݣ���ɻ����ͻ
public:
	mat(int n, bool clear = false);
	mat(const mat &A);
	~mat();
	void clear() { memset(a, 0, sizeof(int)*n*row); }
	int *operator [](int x) { return a + x * row; }
	const int *operator [](int x) const { return a + x * row; }
	int size() const { return n; }
	
	// ���� 1/4 ������ res
	void left_top(mat &res) const;
	void right_top(mat &res) const;
	void left_bottom(mat &res) const;
	void right_bottom(mat &res) const;
};

mat operator + (const mat &A, const mat& B);
mat operator - (const mat &A, const mat& B);
bool operator == (const mat &A, const mat& B);
std::ostream & operator << (std::ostream &os, const mat &A);