#include "SortingAlgorithmTest.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	SortingAlgorithmTest test;
	test.set_algos(7, "��������",
		"ϣ������",
		"��������",
		"�鲢����",
		"�������� with r=11",
		"�������� with r=16",
		"�������� with r=logn");
	bool no_pause = test.get_input(argc, argv);
	double t = test.run();
	cout << "algo = " << test.getAlgo() << endl;
	cout << "n = " << test.getN() << endl;
	cout << "ƽ����ʱ��" << fixed << setprecision(10) << setiosflags(ios::showpoint) << t  << " s" << endl;
	if (!no_pause)
		system("pause");
	return 0;
}

