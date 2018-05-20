#include <ctime>
#include <cstdlib>

#include "compileOption.h"
#include "Matrix.h"

#ifdef PROCESS
#include <iostream>
#include "dataProcess.h"

using namespace std;

int main() {
    string dataset[] = {
        "mnist",
        //"glove"
    };
    srand((unsigned)time(NULL));
    for (int i = 0; i != 1; ++i) {
        DenseMatrix M(dataset[i] + "_source");

        // 2.Ԥ���������ݡ�
		cout << "[��ʼԤ����]" << endl;
        preProcess(dataset[i]);

        // 3.��˹ͶӰ����͹�ӬͶӰ����
        size_t vecCount = M.getRow();
        size_t dimension = M.getColumn();
		cout << "[��ʼ������˹ͶӰ����]" << endl;
		GaussionMatrix(dataset[i], 32, dimension);
		cout << "[��ʼ������ӬͶӰ����]" << endl;
		FlyMatrix(dataset[i], 32, dimension, 0.1);

        // 4.ʹ�ø�˹ͶӰ�����ϣ������ݡ�
		cout << "[��ʼʹ�ø�˹ͶӰ�����ϣ����]" << endl;
		GaussionProject(dataset[i]);

        // 5.ʹ�ù�ӬͶӰ�����ϣ������ݡ�
		cout << "[��ʼʹ�ù�ӬͶӰ�����ϣ����]" << endl;
		FlyProject(dataset[i]);

        // 6.���ڹ�ӬͶӰ�����ϣ��Ӧ����random���Ƶ����ݡ�
		cout << "[��ʼӦ��random����]" << endl;
		randomMatrix(dataset[i], 32);

        // 7.���ڹ�ӬͶӰ�����ϣ��Ӧ����WTA���Ƶ����ݡ�
		cout << "[��ʼӦ��WTA����]" << endl;
		WTAMatrix(dataset[i], 32);

        // 8.���ڹ�ӬͶӰ�����ϣ��Ӧ����binary���Ƶ����ݡ�
		cout << "[��ʼӦ��binary����]" << endl;
		binaryMatrix(dataset[i], 32);
    }
}
#endif // PROCESS

#ifdef TEST_TIME
#include <iostream>
using namespace std;
void testAccurateKNN(Matrix& rowData, Matrix& handledData);
int main() {
    srand((unsigned)time(NULL));
    string dataset[] = {
        //"glove",
        "mnist"
    };
    for (int i = 0; i != 1; ++i) {
        cout << "���ݼ�" << dataset[i] << "����:" << endl;
        testAccurateKNN(DenseMatrix(dataset[i] + "_source"), DenseMatrix(dataset[i] + "_preProcess"));
    }
}
#endif //TEST_TIME

#ifdef DISPLAY_RESULT
int main() {
    string dataset[] = {
        "glove",
        "mnist"
    };
    string set = dataset[0];
    // 1
    DenseMatrix(set + "_source").showPage(1);
    // 2
    DenseMatrix(set + "_preProcess").showPage(1);
    // 3 
    DenseMatrix(set + "_gaussMatrix").showPage(1);
    DenseMatrix(set + "_flyMatrix").showPage(1);
    // 4
    DenseMatrix(set + "_gaussProjectMatrix").showPage(1);
    // 5
    DenseMatrix(set + "_flyProjectMatrix").showPage(1);
    // 6
    DenseMatrix(set + "_randomMatrix").showPage(1);
    // 7
    DenseMatrix(set + "_WTAMatrix").showPage(1);
    // 8
    DenseMatrix(set + "_binaryMatrix").showPage(1);
}
#endif // DISPLAY_RESULT


#ifdef OTHER
#include <iostream>
using namespace std;
int main() {
    DenseMatrix M("mnist_preProcess");
    //M.showPage(10);
	for (int i = 0; i != M.getRow(); ++i) {
		float sum = 0;
		for (int j = 0; j != M.getColumn(); ++j) {
			sum += M[i][j];
		}
		cout << (sum /= M.getColumn()) << endl;
	}
}
#endif // OTHER

//int main() {
//    {
//        fstream fs("mnist");
//        string str;
//        clock_t start = clock();
//        while (getline(fs, str)) {
//        }
//        clock_t end = clock();
//        printf("��ȡ�ļ�ʱ��:%d��\n", (end - start) / CLOCKS_PER_SEC);
//    }
//    {
//        clock_t start = clock();
//        DenseMatrix M("mnist_source");
//        for (int i = 0; i != M.getRow(); ++i) {
//            Row r = M[i];
//        }
//        clock_t end = clock();
//        printf("��������ʱ��:%d��\n", (end - start) / CLOCKS_PER_SEC);
//    }
//}