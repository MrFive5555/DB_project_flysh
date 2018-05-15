#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Matrix.h"

// 2.Ԥ���������ݡ�
// Preprocess
void preProcess(string sourceMatrixName);

// 3.��˹ͶӰ����͹�ӬͶӰ����
// build a gaussion projection matrix
// compute a gaussion distribution randomly
float GaussionDistribution();

void GaussionProjection(string sourceMatrixName, size_t m, size_t dim);

// build a fly projection matrix using a given probability p
void FlyProjection(string sourceMatrixName, size_t m, size_t dim, float p);


// 4.ʹ�ø�˹ͶӰ�����ϣ������ݡ�
// build matrix after gaussion project
void GaussionProject(string sourceMatrixName);

// 5.ʹ�ù�ӬͶӰ�����ϣ������ݡ�
// build matrix after fly project
void FlyProject(string sourceMatrixName);

// 6.���ڹ�ӬͶӰ�����ϣ��Ӧ����random���Ƶ����ݡ�
Matrix& randomMatrix(string sourceMatrixName, size_t k);

// 7.���ڹ�ӬͶӰ�����ϣ��Ӧ����WTA���Ƶ����ݡ�
DenseMatrix& WTAMatrix(string sourceMatrixName, size_t k);

// 8.���ڹ�ӬͶӰ�����ϣ��Ӧ����binary���Ƶ����ݡ�
DenseMatrix& binaryMatrix(string sourceMatrixName, size_t k);