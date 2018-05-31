#pragma once
#include <string>
#define PAGE_NUMBER 50
#define PAGE_SIZE (64 * 1024)

using std::fstream;
using std::string;

class Matrix {
public:
    virtual float* operator[] (size_t) = 0;
    size_t getRow() {
        return row;
    }
    size_t getColumn() {
        return dimension;
    }
protected:
    size_t row;
    size_t dimension;
};

class DenseMatrix : public Matrix {
public:
    DenseMatrix(string matrixName);
    DenseMatrix(string matrixName, size_t _vectorNum, size_t _dimension);
    ~DenseMatrix();

    float* operator[] (size_t);

    // ֪ͨ����ĳһ��Ԫ���������޸�
    void setRow(size_t row);

    void showPage(int);
private:
    // �õ�ָ��ҳ�ŵ�page��ҳ�������е�λ�ã���ҳ�������ڻ������У���Ӵ����н�������
    int getPageIndexInBuffer(size_t pageNum);

    // ����һҳ���Դ��������
    static size_t getVectorNumPerPage(size_t dimension);

    // �õ����е�ҳ����
    int getFreePageIndex();

    // �ڳ�ָ��λ�ŵĻ������ռ�
    void removeSelfFromBuffer(size_t pageIndex);

    static char buffer[PAGE_NUMBER][PAGE_SIZE];		//buffer page
    static size_t page[PAGE_NUMBER];				//page id of matrix
    static DenseMatrix* usedMatrix[PAGE_NUMBER];	//matrix who used this page
    static bool hasChange[PAGE_NUMBER];

    static const size_t FILE_HEAD_SIZE = sizeof(size_t) * 2;
    static const string dir;

    FILE* file;
    bool used[PAGE_NUMBER];
    size_t vectorNumPerPage;
};

float dist(const float* a, const float* b, size_t size);