#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
#define endl '\n'

char maze[11][11];
int block[11][11];
int chk[11][11][11][11];
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> p(3);
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			cin>>maze[i][j];
			if(maze[i][j] =='R')
				p[0] = make_pair(i,j);
			if(maze[i][j] == 'B')
				p[1] = make_pair(i,j);
			if(maze[i][j] == 'O')
				p[2] = make_pair(i,j);
			if(maze[i][j] == '#')
				block[i][j]= -1;
		}
	}

	memset(chk,-1,sizeof(chk));
	queue<pair<int,int>> q;
	q.push(make_pair(p[0].first,p[0].second));		//push red
	q.push(make_pair(p[1].first,p[1].second));		//push blue
	chk[p[0].first][p[0].second][p[1].first][p[1].second] = 0;
	int ans = -1;
	while(!q.empty()){
		int xr = q.front().first;
		int yr = q.front().second;
		q.pop();

		int xb = q.front().first;
		int yb = q.front().second;
		q.pop();

		if(chk[xr][yr][xb][yb] == 11)
			break;
		


		//up
		bool blue_flag = 0;
		bool red_flag = 0;
		int n_xr = xr;
		int n_yr = yr;
		int n_xb = xb;
		int n_yb = yb;

		while(1){		//red 
			if(block[n_xr-1][n_yr] == -1 || ((n_xr-1) == n_xb && n_yr ==n_yb))
				break;
			else
				n_xr--;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}

		
		while(1){		//blue
			if(red_flag && n_xb ==p[2].first + 1 && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

			if(block[n_xb-1][n_yb] == -1 || ((n_xb-1) == n_xr && n_yb ==n_yr))
				break;
			else
				n_xb--;
			
			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

			
		}

		while(1){		//red 
			if(block[n_xr-1][n_yr] == -1 || ((n_xr-1) == n_xb && n_yr ==n_yb))
				break;
			else
				n_xr--;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue

			if(red_flag && n_xb ==p[2].first + 1 && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

			if(block[n_xb-1][n_yb] == -1 || ((n_xb-1) == n_xr && n_yb ==n_yr))
				break;
			else
				n_xb--;

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

		
		}

		if(blue_flag == 0 && red_flag ==1){
			ans = chk[xr][yr][xb][yb] +1;
			break;
		}


		if(blue_flag ==0 && chk[n_xr][n_yr][n_xb][n_yb] == -1){
			q.push(make_pair(n_xr,n_yr));
			q.push(make_pair(n_xb,n_yb));
			chk[n_xr][n_yr][n_xb][n_yb] = chk[xr][yr][xb][yb] +1;
		}

		//down
		blue_flag = 0;
		red_flag = 0;
		n_xr = xr;
		n_yr = yr;
		n_xb = xb;
		n_yb = yb;

		while(1){		//red 
			if(block[n_xr+1][n_yr] == -1 || ((n_xr+1) == n_xb && n_yr ==n_yb))
				break;
			else
				n_xr++;
			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue
			if(red_flag && n_xb ==p[2].first - 1 && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

			if(block[n_xb+1][n_yb] == -1 || ((n_xb+1) == n_xr && n_yb ==n_yr))
				break;
			else
				n_xb++;

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

		
		}
		while(1){		//red 
			if(block[n_xr+1][n_yr] == -1 || ((n_xr+1) == n_xb && n_yr ==n_yb))
				break;
			else
				n_xr++;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue
			if(red_flag && n_xb ==p[2].first - 1 && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

			if(block[n_xb+1][n_yb] == -1 || ((n_xb+1) == n_xr && n_yb ==n_yr))
				break;
			else
				n_xb++;

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}

		
		}

		if(blue_flag == 0 && red_flag ==1){
			ans = chk[xr][yr][xb][yb] +1;
			break;
		}


		if(blue_flag ==0 && chk[n_xr][n_yr][n_xb][n_yb] == -1){
			q.push(make_pair(n_xr,n_yr));
			q.push(make_pair(n_xb,n_yb));
			chk[n_xr][n_yr][n_xb][n_yb] = chk[xr][yr][xb][yb] +1;
		}

		//left
		blue_flag = 0;
		red_flag = 0;
		n_xr = xr;
		n_yr = yr;
		n_xb = xb;
		n_yb = yb;
		
		while(1){		//red 
			if(block[n_xr][n_yr-1] == -1 || ((n_xr) == n_xb && (n_yr-1) ==n_yb))
				break;
			else
				n_yr--;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue
			if(red_flag && n_xb ==p[2].first && n_yb == p[2].second +1 ){
				blue_flag = true;
				break;
			}

			if(block[n_xb][n_yb-1] == -1 || ((n_xb) == n_xr && (n_yb-1) ==n_yr))
				break;
			else
				n_yb--;
			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}
		}
		while(1){		//red 
			if(block[n_xr][n_yr-1] == -1 || ((n_xr) == n_xb && (n_yr-1) ==n_yb))
				break;
			else
				n_yr--;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue
			if(red_flag && n_xb ==p[2].first && n_yb == p[2].second +1 ){
				blue_flag = true;
				break;
			}

			if(block[n_xb][n_yb-1] == -1 || ((n_xb) == n_xr && (n_yb-1) ==n_yr))
				break;
			else
				n_yb--;

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}
		}

		
		if(blue_flag == 0 && red_flag ==1){
			ans = chk[xr][yr][xb][yb] +1;
			break;
		}


		if(blue_flag ==0 && chk[n_xr][n_yr][n_xb][n_yb] == -1){
			q.push(make_pair(n_xr,n_yr));
			q.push(make_pair(n_xb,n_yb));
			chk[n_xr][n_yr][n_xb][n_yb] = chk[xr][yr][xb][yb] +1;
		}


		//right
		blue_flag = 0;
		red_flag = 0;
		n_xr = xr;
		n_yr = yr;
		n_xb = xb;
		n_yb = yb;
		while(1){		//red 
			if(block[n_xr][n_yr+1] == -1 || ((n_xr) == n_xb && (n_yr+1) ==n_yb))
				break;
			else
				n_yr++;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue

			if(red_flag && n_xb ==p[2].first && n_yb == p[2].second - 1 ){
				blue_flag = true;
				break;
			}

			if(block[n_xb][n_yb+1] == -1 || ((n_xb) == n_xr && (n_yb+1) ==n_yr))
				break;
			else
				n_yb++;

			

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}
		}
		while(1){		//red 
			if(block[n_xr][n_yr+1] == -1 || ((n_xr) == n_xb && (n_yr+1) ==n_yb))
				break;
			else
				n_yr++;

			if(n_xr ==p[2].first && n_yr == p[2].second){
				red_flag = true;
				break;
			}
		}
		
		while(1){		//blue

			if(red_flag && n_xb ==p[2].first && n_yb == p[2].second - 1 ){
				blue_flag = true;
				break;
			}

			if(block[n_xb][n_yb+1] == -1 || ((n_xb) == n_xr && (n_yb+1) ==n_yr))
				break;
			else
				n_yb++;

			

			if(n_xb ==p[2].first && n_yb == p[2].second){
				blue_flag = true;
				break;
			}
		}
		
		if(blue_flag == 0 && red_flag ==1){
			ans = chk[xr][yr][xb][yb] +1;
			break;
		}


		if(blue_flag ==0 && chk[n_xr][n_yr][n_xb][n_yb] == -1){
			q.push(make_pair(n_xr,n_yr));
			q.push(make_pair(n_xb,n_yb));
			chk[n_xr][n_yr][n_xb][n_yb] = chk[xr][yr][xb][yb] +1;
		}

	}
	if(ans>10 || ans == -1)
		ans = 0;
	else
        ans = 1;
    cout<<ans<<endl;

}