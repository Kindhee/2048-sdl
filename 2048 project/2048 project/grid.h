
const int size_gridC = 4;

class Grid
{

public:

	int starting;

	Grid(int grid[size_gridC][size_gridC]);

	int randomNumberC(int number);

	void moveUpC(int grid[size_gridC][size_gridC]);
	void moveDownC(int grid[size_gridC][size_gridC]);
	void moveLeftC(int grid[size_gridC][size_gridC]);
	void moveRightC(int grid[size_gridC][size_gridC]);

	int newTilesC(int grid[size_gridC][size_gridC]);

	bool testInGridC(int grid[size_gridC][size_gridC], int i, int j);
	bool testLooseC(int grid[size_gridC][size_gridC], int zero);

	void showTableC(int grid[size_gridC][size_gridC]);

};

