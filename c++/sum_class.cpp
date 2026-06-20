#include<iostream>
using namespace std;
class a {
    public :
     static int sum;
    a(){
      sum+=1;
    };
};
int a::sum=0;
int main(){
    a obj1;
    a obj2;
    a obj3;
    cout<<"The sum is : "<<a::sum<<endl;
    return 0;
};