#include <iostream>
#include <cstring>

using namespace std;

class DCircularDinamicList{
    int *ptr;
    int front,back;
    unsigned blockSize;

    void resizeBlock(unsigned newSize){
        int *pAux = new int[newSize];
        if(front<back){
            memcpy(pAux,ptr+front,(back-front) * sizeof(int));
            back = back-front;
            front = 0;
        }
        else if(front>back){
            memcpy(pAux,ptr+front,(blockSize-front)*sizeof(int));
            memcpy(pAux+blockSize-front,ptr,(back)*sizeof(int));
            back = blockSize-front+back;
            front = 0;
        }
        delete [] ptr;
        ptr = pAux;
        blockSize = newSize;
    }
public:
    DCircularDinamicList():
        blockSize(2),
        front(0),
        back(0)
    {
        ptr = new int[blockSize];
    }
    ~DCircularDinamicList(){
        delete [] ptr;
    }
    bool isEmpty() const{
        return front == back;
    }
    int getFront() const{
        return ptr[front];
    }
    int getBack() const{
        return ptr[back-1];
    }
    void pushFront(int elem){
        if((back+1)%blockSize == front)
            resizeBlock(blockSize*2);
        //front = (front-1+blockSize)%blockSize;
        front = front == 0 ? blockSize-1 : front-1;
        ptr[front] = elem;
    }
    void pushBack(int elem){
        if((back+1)%blockSize == front)
            resizeBlock(blockSize*2);
        ptr[back] = elem;
        back = (back +1) % blockSize;
    }
    bool popFront(){
        int nElem = 0;
        if(front<back)
            nElem = back-front;
        else if(front>back)
            nElem = blockSize - (front-back);
        else
            return false;
        if((blockSize-1)/2 > nElem)
            resizeBlock(blockSize/2);

        front = (front +1) % blockSize;
        return true;
    }
    bool popBack(){
        int nElem = 0;
        if(front<back)
            nElem = back-front;
        else if(front>back)
            nElem = blockSize - (front-back);
        else
            return false;
        if((blockSize-1)/2 > nElem)
            resizeBlock(blockSize/2);

        back = back == 0 ? blockSize-1 : back-1;
        return true;
    }
    /*void print(){
        cout<<"f="<<front<<"-b="<<back<<"-BS="<<blockSize<<endl;
        for(int i=0;i<blockSize;++i)
            cout<<ptr[i]<<',';
        cout<<endl;
    }*/
};

int main() {
    DCircularDinamicList cList;

    //cList.pushBack(1);
    //cList.pushFront(2);
    cList.popFront();
    //cList.print();

    return 0;
}

