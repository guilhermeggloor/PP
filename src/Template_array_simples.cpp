#include <iostream>
using namespace std;

template <class T = int>
class DPilha{
    T vet[5];
    unsigned topo;

public:
    DPilha():
      topo(0)
    {}
    DPilha(const T &val):
      topo(5)
    {
        int i;
        for(i=0;i<topo;++i)
            vet[i] = val;
    }
    bool push(const T &val){
        if(topo>=5)
            return false;

        vet[topo] = val;
        ++topo;
        return true;
    }
    bool pop(){
        if(topo == 0)
            return false;
        --topo;
        return true;
    }
    T top() const{
        return vet[topo-1];
    }
};
int main() {
    DPilha<int> iPilha;
    DPilha<char> cPilha('x');
    DPilha<> defPilha;

    int i;
    for(i=0;i<5;++i)
        iPilha.push(i);

    cout<<"iPilha:";
    for(i=0;i<5;++i){
        cout<<iPilha.top()<<',';
        iPilha.pop();
    }

    cout<<"\ncPilha:";
    for(i=0;i<5;++i){
        cout<<cPilha.top()<<',';
        cPilha.pop();
    }
    return 0;
}

