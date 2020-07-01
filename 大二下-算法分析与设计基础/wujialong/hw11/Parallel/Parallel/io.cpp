#include "io.h"
#include "windows.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <omp.h>
#include <cassert>
using namespace std;

int get_n() {
	int n;
	while (true) {
		cout << "���� n��" << endl;
		if (!(cin >> n) || n < 0) {
			cout << "��������" << endl;
			cin.clear(istream::goodbit);
			cin.ignore();
		}
		else {
			break;
		}
	}
	return n;
}

int get_count() {
	int count;
	while (true) {
		cout << "���������� count������μ���ƽ����ʱ��" << endl;
		if (!(cin >> count) || count <= 0) {
			cout << "��������" << endl;
			cin.clear(istream::goodbit);
			cin.ignore();
		}
		else {
			break;
		}
	}
	return count;
}

int get_f() {
	int idx;
	while (true) {
		cout << "���������㷨��ţ�" << endl;
		cout << "\t0��serial MergeSort" << endl;
		cout << "\t1��parallel MergeSort�����й鲢���޽ضϣ�" << endl;
		cout << "\t2��parallel MergeSort�����й鲢���޽ضϣ�" << endl;
		cout << "\t3��parallel MergeSort�����й鲢���нضϣ�" << endl;
		cout << "\t4��parallel MergeSort�����й鲢���нضϣ�" << endl;
		cout << "\t5��serial QuickSort" << endl;
		cout << "\t6��parallel QuickSort������ partition���޽ضϣ�" << endl;
		cout << "\t7��parallel QuickSort������ partition���нضϣ�" << endl;
		cin >> idx;
		if (!cin.good() || !(idx >= 0 && idx < 8)) {
			cout << "��������" << endl;
			cin.clear(istream::goodbit);
			cin.ignore();
		}
		else {
			break;
		}
	}
	return idx;
}

void printOmpInfo() {
	printf("num_procs = %d\n", omp_get_num_procs());
	//omp_set_num_threads(8);
#pragma omp parallel
	{
#pragma omp single
		printf("num_threads = %d\n", omp_get_num_threads());
	}
}

void validate(int n, value_t *a, value_t *b, value_t *tmp) {
	printOmpInfo();

	double start, end;

	gen_data(a, n);
	memcpy(b, a, sizeof(a));
	cout << "merge" << endl;
	start = omp_get_wtime();
	MergeSort(a, 1, n, tmp);
	end = omp_get_wtime();
	cout << end - start << endl;

	cout << "pmerge" << endl;
	start = omp_get_wtime();
	parallelMergeSort(b, 1, n, tmp, 1, 0);
	end = omp_get_wtime();
	cout << end - start << endl;

	for (int i = 1; i <= n; i++) assert(a[i] == b[i]);
	cout << "pmerge ok" << endl;

	gen_data(a, n);
	memcpy(b, a, sizeof(a));

	cout << "quick" << endl;
	start = omp_get_wtime();
	QuickSort(a, 1, n);
	end = omp_get_wtime();
	cout << end - start << endl;

	cout << "pquick" << endl;
	start = omp_get_wtime();
	parallelQuickSort(b, 1, n, 0);
	end = omp_get_wtime();
	cout << end - start << endl;

	for (int i = 1; i <= n; i++) assert(a[i] == b[i]);
	cout << "pquick ok" << endl;
}
