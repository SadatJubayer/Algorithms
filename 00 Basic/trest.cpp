#include<iostream>
#include <cstring>

using namespace std;

class myStack{

private:
    int *stk, top, maxSize;
public:
    myStack(int sz = 5){
        maxSize = sz;
        stk = new int [maxSize];
        top = 0;
    }

    ~myStack(){
        delete [] stk;
    }

    bool isEmpty(){
        return (top==0);
    }

    bool isFull(){
        return (top==maxSize);
    }

    bool push(int element){
        if(isFull()){
            resiz();
        }
        stk[top]=element;
        top++;
        return true;
    }

    bool pop(){
        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
            return false;
        }
        top--;
        return true;
    }

    int topElement(){
        return stk[top-1];
    }

    void show(){
        if(isEmpty()){
            cout<<"Empty!"<<endl;
            return;
        }

        for(int i=0; i<top; i++){
            cout<<stk[i]<<" ";
        }
        cout<<endl;
    }

    void resiz( int sz = 5){
        int *S = new int [maxSize + sz];
        for(int i=0;i<maxSize;i++){
            S[i]=stk[i];
        }
        maxSize = maxSize + sz;
        delete [] stk;
        stk = S;
    }



void Reverse (char c[],int n)
{
    myStack s;
    for(int i=0;i<n; i++){
        s.push(c[i]);
    }
    for (int i=0;i<n;i++){
        c[i]=s.topElement();
        s.pop();
    }
}
};


int main()
{
    myStack s;
    char ch[20] = "Sadat Jubayer";
    s.Reverse(ch,strlen(ch));
    cout<<"After reversing: "<<ch<<"\n";
}
