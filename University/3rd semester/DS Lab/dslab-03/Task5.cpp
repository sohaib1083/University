#include<iostream>
using namespace std;

bool path(int a[4][4], int x, int y, int xf, int yf)
{
	if (x == xf && y == yf)
		return true;
	else
	{
		if (a[x][y + 1] == 1)
			y++;
		else if (a[x + 1][y] == 1)
			x++;
		
		cout << " Position [" << x << "][" << y << "]" << endl;
		return path(a, x, y, xf, yf);
	}
}

int main()
{
	int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}},
		x1 = 0, y1 = 0, x2 = 3, y2 = 3;
	
	for (int i = 0; i < 4; i++)
	{
		cout << "\n ";
		for (int j = 0; j < 4; j++)
			cout << maze[i][j] << "  ";
	}
	
	cout << "\n\n Start from Pos[" << x1 << "][" << y1 << "]" << endl;
	path(maze, x1, y1, x2, y2);
	return 0;
}
