#include <ctime>

#include "Matrix.h"

//#define PROCESS
//#define TEST_TIME
//#define DISPLAY_RESULT

#ifdef PROCESS
#include "dataProcess.h"
int main() {
    string dataset[] = {
        "glove",
        "mnist"
    };
    srand((unsigned)time(NULL));
    for (int i = 0; i != 2; ++i) {
        Matrix& M = DenseMatrix(dataset[i]);
        size_t vecCount = M.getRow();
        size_t dimension = M.getColumn();

        // 2.Ԥ���������ݡ�
        // Preprocess
        preProcess(dataset[i]);

        // 3.��˹ͶӰ����͹�ӬͶӰ����
        GaussionProjection(dataset[i], vecCount, dimension);

        // build a fly projection matrix using a given probability p
        FlyProjection(dataset[i], vecCount, dimension, 0.1);

        // 4.ʹ�ø�˹ͶӰ�����ϣ������ݡ�
        // build matrix after gaussion project
        GaussionProject(dataset[i]);

        // 5.ʹ�ù�ӬͶӰ�����ϣ������ݡ�
        // build matrix after fly project
        FlyProject(dataset[i]);

        // 6.���ڹ�ӬͶӰ�����ϣ��Ӧ����random���Ƶ����ݡ�
        randomMatrix(dataset[i], 32);

        // 7.���ڹ�ӬͶӰ�����ϣ��Ӧ����WTA���Ƶ����ݡ�
        WTAMatrix(dataset[i], 32);

        // 8.���ڹ�ӬͶӰ�����ϣ��Ӧ����binary���Ƶ����ݡ�
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
        "glove",
        "mnist"
    };
    for (int i = 0; i != 2; ++i) {
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
