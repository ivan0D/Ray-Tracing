#pragma once
#include <iostream>
#include "vec3.h"

class Matrix{

public:

    Matrix(int row, int col, float* data_){
        this->row = row;
        this->col = col;
        this->data = data_;

        for (int i = 0; i < this->row * this->col; ++i) {
            std::cout << this->data[i] << std::endl;
        }
        
    }

    ~Matrix(){
        delete[] data;
    }

    Matrix operator+(const Matrix& other){
        if(this->col != other.col || this->row != other.row)
            throw std::runtime_error("A.col != B.col || A.row != B.row");
        float* data_ = new float[this->col * this->col];
        for (int i = 0; i < this->col; ++i) {
            for (int j = 0; j < this->col; ++j) {
                int index = i * this->col + j;
                data_[index] = this->data[index] + other.data[index];
            }
        }
        return Matrix(this->row, this->col, data_);
    }

    Matrix operator*(const Matrix& other){
        if(this->col != other.row)
            throw std::runtime_error("A.col != B.row");
        float* data_ = new float[this->row * other.col]{0};
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < other.col; ++j) {
                for (int k = 0; k < this->col; ++k) {
                    data_[i * other.col + j] += this->data[i * this->col + k] * other.data[k * other.col + j];
                }
            }
        }
        return Matrix(this->row, other.col, data_);
    }

private:

    float* data; // содержимое
    int col; // размерность
    int row;

};