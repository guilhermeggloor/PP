#include <iostream>
#include <cstring>
using namespace std;

class DOrderedDinamicArray{
    unsigned size;
    unsigned nElem;
    int *_data;

    void resize(unsigned newSize){
        int *pAux;

        pAux = new int[newSize];
        memcpy(pAux,_data,nElem*sizeof(int));
        delete [] _data;
        _data = pAux;
        size = newSize;
    }
    void MySwap(int &a,int &b) const{
        register int aux;

        aux = a;
        a   = b;
        b   = aux;
    }
public:
    DOrderedDinamicArray():
            size(2),
            nElem(0),
            _data(new int[size])
    {}
    ~DOrderedDinamicArray(){
        if(_data!= nullptr)
            delete [] _data;
    }
    unsigned getSize() const{
        return size;
    }
    unsigned getNElem() const{
        return nElem;
    }
    int at(unsigned i) const{
        return _data[i];
    }
    bool search(int key, unsigned &index){
        index=0;
        while(index<nElem) {
            if (key == _data[index])
                return true;
            index++;
        }
        return false;
    }
    bool search(int key){
        unsigned none;
        return search(key,none);
    }
    void insert(int elem){
        unsigned i;
        if(nElem == size)
            resize(2*size);

        i=nElem;
        _data[nElem++] = elem;
        while(i>0 && _data[i]<_data[i-1] ){
            MySwap(_data[i],_data[i-1]);
            --i;
        }
    }
    void removeMax(){
        nElem = nElem? nElem-1 : 0;
        if(nElem < size/2 && size > 2)
            resize(size/2);
    }
    void removeMin(){
        unsigned i;
        i=0;
        while(i<nElem-1) {
            _data[i] = _data[i + 1];
            ++i;
        }
        --nElem;
        if(nElem < size/2 && size > 2)
            resize(size/2);
    }
    void removeFromKey(int key){
        unsigned i;
        if(search(key,i)){
            while(i<nElem-1) {
                _data[i] = _data[i + 1];
                ++i;
            }
            --nElem;
        }
        if(nElem < size/2 && size > 2)
            resize(size/2);
    }

};

int main() {
    int i;
    DOrderedDinamicArray vet;

    for(i=5;i>0;--i)
        vet.insert(i);

    vet.removeMin();
    vet.removeMin();

    for(i=0;i<vet.getNElem();++i)
        cout<<vet.at(i)<<' ';

    cout<<endl<<vet.getSize();
    return 0;
}



