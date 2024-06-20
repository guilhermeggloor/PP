#include <iostream>
#include <string>
#define MAX_MAP_SIZE 10

using namespace std;
template <class K,class V>
class DMap{
    K keyArray[MAX_MAP_SIZE];
    V valueArray[MAX_MAP_SIZE];
    unsigned nElem;


    bool findKey(K key,unsigned &index){
        index = 0;
        while(index<nElem) {
            if (key == keyArray[index])
                return true;
            ++index;
        }
        return false;
    }

public:
    DMap():
        nElem(0)
    {}
    bool insert(K key,V value){
        if(nElem>=MAX_MAP_SIZE) //mapa cheio
            return false;
        if(findKey(key))
            return false;
        keyArray[nElem] = key;
        valueArray[nElem] = value;
        ++nElem;
        return true;
    }
    bool findKey(K key){
        unsigned i;
        return findKey(key,i);
    }
    bool deleteFromkey(K key){
        unsigned index;
        if(!findKey(key,index))
            return false;
        --nElem;
        if(index != nElem){
            keyArray[index] = keyArray[nElem];
            valueArray[index] = valueArray[nElem];
        }
        return true;
    }
    V& at(K key){
        unsigned index;
        if(findKey(key,index))
            return valueArray[index];
        throw "DMap ERROR: key not found!!!";
    }
};

int main()
{
    DMap<string,int> myMap;

    myMap.insert("teste",1);
    myMap.insert("testa",2);

    cout<<myMap.at("teste")<<' '<<myMap.at("testa")<<endl;
    myMap.at("teste") = 20;
    cout<<myMap.at("teste")<<' '<<myMap.at("testa")<<endl;
    try {
        myMap.at("no");
    }
    catch(const char *msg){
        cout << msg;
    }

    return 0;
}

