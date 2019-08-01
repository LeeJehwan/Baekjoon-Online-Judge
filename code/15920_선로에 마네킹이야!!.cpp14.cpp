#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    
    int p=0, w=0;
    int fw=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='W'){
            fw = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='W'){
            w++;
        }
    }
    if(w<=1)
        cout<<0<<endl;
    else if(s[fw+1]=='P')
        cout<<6<<endl;
    else if(fw%2 == 1)
        cout<<1<<endl;
    else
        cout<<5<<endl;
}