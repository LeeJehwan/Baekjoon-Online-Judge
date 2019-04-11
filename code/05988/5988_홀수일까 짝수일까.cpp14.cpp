#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string t;
        cin>>t;
        int len = t.size();
        if(t[len-1]%2==0)
            cout<<"even"<<endl;
        else
            cout<<"odd"<<endl;
       }
    }