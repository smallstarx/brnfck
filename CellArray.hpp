#pragma once
#include <cstring>

class CellArray
{
public:
    long* array;
    int ptr;
    int size;

public:
    CellArray(const int initial_size)
    {
        array = new long[initial_size];
        memset(array, 0L, initial_size*sizeof(long));
        ptr = initial_size / 2;
        size = initial_size;
    }
    ~CellArray()
    {
        delete[] array;
    }
    void PtrUp()
    {
        ptr++;
        if(ptr >= size)
        {
            long* buffer = new long[size*2];
            memcpy(buffer, array, size*sizeof(long));
            memset(buffer+size, 0, size*sizeof(long));
            size*=2;
            delete[] array;
            array = buffer;
        }
    }
    void PtrDown()
    {
        ptr--;
        if(ptr < 0)
        {
            long* buffer = new long[size*2];
            memset(buffer, 0, size*sizeof(long));
            memcpy(buffer+size, array, size*sizeof(long));
            ptr += size;
            size*=2;
            delete[] array;
            array = buffer;
        }
    }
    void CellUp()
    {
        array[ptr]++;
    }
    void CellDown()
    {
        array[ptr]--;
    }
    char GetChar()
    {
        return (char)array[ptr];
    }
    long GetLong()
    {
        return array[ptr];
    }
};