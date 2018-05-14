#pragma once
#include <fstream>
#include <string>

#define PAGE_NUMBER 50
#define PAGE_SIZE (64 * 1024)

using std::fstream;
using std::string;

class Row {
public:
    static float dist(Row&, Row&);
    virtual float& operator[] (size_t) = 0;
    virtual float* getBuffer() = 0;
    void setID(size_t _id) {
        id = _id;
    }
    size_t getID() {
        return id;
    };
    size_t getSize() {
        return dimension;
    }
protected:
    size_t dimension;
    size_t id; // id��ʵ���Ǿ��������
};

class Matrix {
public:
    virtual Row& operator[] (size_t) = 0;
    virtual Matrix& transpose(string) = 0;
    size_t getRow() {
        return row;
    }
    size_t getColumn() {
        return column;
    }
private:
    size_t row;
    size_t column;
};

class SparseRow : Row {

};

class SparesMatrix : public Matrix{
public:
    SparesMatrix(int row, int col);
    SparesMatrix(char* matrixName);
    Row& operator[] (size_t);
    Matrix& transpose(string);
};

class DenseRow : public Row {
public:
    ~DenseRow();
    DenseRow(size_t _dimension, size_t _id, char* _buffer);
    float& operator[] (size_t);
    float* getBuffer() {
        return row;
    }
private:
    float* row;
};

class DenseMatrix : public Matrix {
public:
    DenseMatrix(string matrixName);
    DenseMatrix(string matrixName, size_t _vectorNum, size_t _dimension);
    Row& operator[] (size_t);
    Matrix& transpose(string);

    Row& operator[] (size_t _row);

    void setRow(Row& row);

    ~DenseMatrix();
private:
    // �õ�ָ��ҳ�ŵ�page��ҳ�������е�λ��
    int getPageIndex(size_t pageNum);

    // ����һҳ���Դ��������
    static size_t getVectorNumOfOnePage(size_t dimension);

    // �õ�ָ��ҳ�Ļ�����
    char* getPageBuffer(size_t pageNum);

    // �õ����е�ҳ����
    int getFreePageIndex();

    // �ڳ�ָ��λ�ŵĻ������ռ�
    void removeSelfFromBuffer(size_t pageIndex);

    static char buffer[PAGE_NUMBER][PAGE_SIZE];		//buffer page
    static size_t page[PAGE_NUMBER];				//page id of matrix
    //static int bufferUsed[PAGE_NUMBER];				//page states of buffer
    static DenseMatrix* usedMatrix[PAGE_NUMBER];	//matrix who used this page
    static const string dir;

    fstream file;
    size_t vectorNum;
    size_t dimension;
    int used[PAGE_NUMBER];
};

Matrix& dot(Matrix&, Matrix&);