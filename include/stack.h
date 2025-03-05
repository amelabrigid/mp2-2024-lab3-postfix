// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, +
// - ���������� ��������, +
// - �������� �������� �������� (��� ��������) +
// - �������� �� �������, +
// - ��������� ���������� ��������� � ����� +
// - ������� ����� +
// ��� ������� � ������ ���� ������ �������������� ������ +
#include <iostream>
#pragma once
using namespace std;

template <class T>
class TDynamicStack
{
    T* data;
    size_t ind;
    size_t capacity;
    void resize()
    {
        T* newData = new T[capacity * 2]();
        copy(data, data + capacity, newData);
        capacity *= 2;
        delete[] data;
        data = newData;
    }
public:
    TDynamicStack(size_t size = 10)
    {
        if (size == 0)
        {
            throw invalid_argument("Size should be greater than zero");
        }
        data = new T[size];
        capacity = size;
        ind = 0;
    }
    bool isEmpty() const noexcept
    {
        return ind == 0;
    }
    void clear()
    {
        if (capacity > 10)
        {
            T* newData = new T[10];
            delete[] data;
            data = newData;
            capacity = 10;
        }
        ind = 0;
    }
    T top()
    {
        if (isEmpty())
            throw exception("Stack is empty");
        return data[ind - 1];
    }
    T pop()
    {
        if (isEmpty())
            throw exception("Stack is empty");
        else
            return data[--ind];
    }
    void push(const T& e)
    {
        if (ind == capacity)
            resize();
        data[ind++] = e;
    }
    size_t size() const noexcept
    {
        return ind;
    }

    ~TDynamicStack()
    {
        delete[] data;
        data = nullptr;
        ind = 0;
        capacity = 0;
    }
};