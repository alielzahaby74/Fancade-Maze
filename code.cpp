#include <bits/stdc++.h>

using namespace std;

char grid[25][25];

int n, posy, posx;

bool sol;

bool canMove(int x, int y)
{
	return (grid[x + 1][y] == '.' && x + 1 < n + 1)
		|| (grid[x - 1][y] == '.' && x - 1 > 0)
		|| (grid[x][y + 1] == '.' && y + 1 < n + 1)
		|| (grid[x][y - 1] == '.' && y - 1 > 0);
}

vector<string> ans;
bool valid(int x, int y)
{
	return x > 0 && x < n + 1 && y > 0 && y < n + 1 && grid[x][y] == '.';
}
bool solve(int x, int y)
{
	//basecase
	if(sol)	return 1;
	if(!canMove(x, y))
	{
		for(int i = 1 ; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(grid[i][j] == '.')
					return 0;
		sol = 1;			
		return 1;
	}
	if(valid(x + 1, y))
	{
		int end = n;
		//Do
		for(int i = x + 1; i <= n; ++i)
		{
			if(valid(i, y))
			{
				grid[i][y] = 'x';
				end = i;
			}
			else
			{
				break;
			}
		}
		ans.push_back("Down");
		
		//Recurse
		if(solve(end, y))
			return 1;
		
		//Undo
		for(int i = end; i > x; --i)
			grid[i][y] = '.';
		ans.pop_back();
	}
	if(valid(x - 1, y))
	{
		int end = 1;
		//Do
		for(int i = x - 1; i >= 1; --i)
		{
			if(valid(i, y))
			{
				grid[i][y] = 'x';
				end = i;
			}
			else
			{
				break;
			}
		}
		ans.push_back("UP");
		
		//Recurse
		if(solve(end, y))
			return 1;
		
		//Undo
		for(int i = end; i < x; ++i)
			grid[i][y] = '.';
		ans.pop_back();
	}
	if(valid(x, y + 1))
	{
		int end = n;
		//Do
		for(int i = y + 1; i <= n; ++i)
		{
			if(valid(x, i))
			{
				grid[x][i] = 'x';
				end = i;
			}
			else
			{
				break;
			}
		}
		ans.push_back("Right");
		
		//Recurse
		if(solve(x, end))
			return 1;
		
		//Undo
		for(int i = end; i > y; --i)
			grid[x][i] = '.';
		ans.pop_back();
	}
	if(valid(x, y - 1))
	{
		int end = 1;
		//Do
		for(int i = y - 1; i >= 1; --i)
		{
			if(valid(x, i))
			{
				grid[x][i] = 'x';
				end = i;
			}
			else
			{
				break;
			}
		}
		ans.push_back("Left");
		
		//Recurse
		if(solve(x, end))
			return 1;
		
		//Undo
		for(int i = end; i < y; ++i)
			grid[x][i] = '.';
		ans.pop_back();
	}
	return 0;
}
int main()
{
	cout << "note: this code works on an N*N matrix and is 1-based\n";
	cout << "enter the grid size \n";
	cin >> n;
	cout << "enter the coordinate of the y-axis \n";
	cin >> posy;
	cout << "enter the coordinate of the x-axis \n";
	cin >> posx;
	//input
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> grid[i][j];
	
	//processing
	grid[posy][posx] = 'x';
	solve(posy, posx);
	
	//output
	if(ans.size())
		for(int i = 0 ; i < ans.size(); ++i)
			cout << ans[i] << " ";
	else
		puts("Cant");
	return 0;
}
