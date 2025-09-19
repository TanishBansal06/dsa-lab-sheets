//a))
#include <iostream>
using namespace std;
class Diagonal {
    int *A, n;
public:
    Diagonal(int n) { this->n = n; A = new int[n]; }
    void set(int i,int j,int x)
   { if(i==j) A[i-1]=x; }
    int get(int i,int j){ return (i==j)?A[i-1]:0; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};
int main(){
    Diagonal d(4);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display();
}
//b))
#include <iostream>
using namespace std;
class TriDiagonal {
    int *A, n;
public:
    TriDiagonal(int n){ this->n=n; A=new int[3*n-2]; }
    void set(int i,int j,int x){
        if(i-j==1) A[i-2]=x;
        else if(i==j) A[n-1+i-1]=x;
        else if(j-i==1) A[2*n-1+i-1]=x;
    }
    int get(int i,int j){
        if(i-j==1) return A[i-2];
        else if(i==j) return A[n-1+i-1];
        else if(j-i==1) return A[2*n-1+i-1];
        else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};
int main(){
    TriDiagonal t(4);
    t.set(1,1,5); t.set(2,1,1); t.set(2,2,6); t.set(1,2,2);
    t.set(3,2,3); t.set(3,3,7); t.set(2,3,4); t.set(4,3,5); t.set(4,4,8);
    t.display();
}
//c))
#include <iostream>
using namespace std;

class LowerTri {
    int *A, n;
public:
    LowerTri(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){
        if(i>=j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i,int j){
        if(i>=j) return A[i*(i-1)/2 + (j-1)];
        else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};
int main(){
    LowerTri lt(4);
    lt.set(1,1,5); lt.set(2,1,8); lt.set(2,2,9); lt.set(3,1,6);
    lt.set(3,2,7); lt.set(3,3,12); lt.set(4,1,2); lt.set(4,2,3);
    lt.set(4,3,4); lt.set(4,4,15);
    lt.display();
}


//d))
#include <iostream>
using namespace std;

class UpperTri {
    int *A, n;
public:
    UpperTri(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){
        if(i<=j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = x;
    }
    int get(int i,int j){
        if(i<=j) return A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
        else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};
int main(){
    UpperTri ut(4);
    ut.set(1,1,5); ut.set(1,2,8); ut.set(1,3,9); ut.set(1,4,12);
    ut.set(2,2,7); ut.set(2,3,6); ut.set(2,4,3);
    ut.set(3,3,4); ut.set(3,4,2);
    ut.set(4,4,10);
    ut.display();
}


//e))
#include <iostream>
using namespace std;

class Symmetric {
    int *A, n;
public:
    Symmetric(int n){ this->n=n; A=new int[n*(n+1)/2]; }
    void set(int i,int j,int x){
        if(i>=j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i,int j){
        if(i>=j) return A[i*(i-1)/2 + (j-1)];
        else return A[j*(j-1)/2 + (i-1)];
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};
int main(){
    Symmetric sm(4);
    sm.set(1,1,5); sm.set(2,1,8); sm.set(2,2,6);
    sm.set(3,1,3); sm.set(3,2,7); sm.set(3,3,9);
    sm.set(4,1,4); sm.set(4,2,2); sm.set(4,3,1); sm.set(4,4,10);
    sm.display();
}
