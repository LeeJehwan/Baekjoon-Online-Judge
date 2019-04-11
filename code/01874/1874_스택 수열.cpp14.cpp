#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define endl '\n'

int main(){
	int n;
	cin>>n;
	vector<int> v(n);	
	vector<char> ans;

	for(int i = 0; i<n ; i++){
		cin>>v[i];
	}
	stack<int> st;
	int last = 1;
	for(int i = 0; i<n; i++){
		int temp = v[i];
		while(1){
			if(last < temp){
//				cout<<"<"<<endl;
				st.push(last);
				ans.push_back('+');
				last++;
			}
			else if(last == temp){
//				cout<<"="<<endl;
				ans.push_back('+');
				ans.push_back('-');
				last++;
				break;
			}
			else if(last > temp){
//				cout<<">"<<endl;
				if(!st.empty() && st.top() == temp){
//					cout<<"pop"<<endl;
					st.pop();
					ans.push_back('-');
					break;
				}
				else{
					cout<<"NO"<<endl;
					i = n;
					break;
				}
			}
		}
	}
	
	if( ans.size() == 2*n){
		for(int i = 0 ; i< ans.size(); i++){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}
