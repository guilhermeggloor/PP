#include <iostream>

using namespace std;

class DFixedSizeArray{
    unsigned size;
    int *_data;

public:
    DFixedSizeArray(unsigned size = 10):
            size(size),
            _data(new int[size])
    {}
    ~DFixedSizeArray(){
        if(_data!= nullptr)
            delete [] _data;
    }
    unsigned getSize() const{
        return size;
    }
    int& at(unsigned i) const{
        return _data[i];
    }
    int& operator[](unsigned i) const{
        return _data[i];
    }
};

int main() {
    int i;
    DFixedSizeArray vet(5);

    for(i=0;i<5;++i)
        vet.at(i) = i+1;

    for(i=0;i<5;++i)
        cout<<vet.at(i)<<' ';
    return 0;
}

