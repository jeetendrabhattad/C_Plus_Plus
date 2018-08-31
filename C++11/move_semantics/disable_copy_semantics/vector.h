#ifdef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>
using namespace std;
//Our Own Version of Vector with copying disabled
template <class T>
class CVector : public vector<T>
{
    public:
    CVector() : vector<T>()
    {
        cout <<"Default Constructor."<<endl;
    }
    explicit CVector(size_t size) : vector<T>(size)
    {
        cout <<"Create empty vector with size Constructor."<<endl;
    }
    CVector(initializer_list<T> l) : vector<T>(l)
    {
        cout <<"Create vector with initializer list."<<endl;
    }
    CVector(CVector&& v) : vector<T>(v)
    { 
        cout <<"Move Constructor."<<endl;
        v.erase();
    }
    private:
    CVector(const CVector&);
    CVector& operator=(const CVector&);
};
#endif
