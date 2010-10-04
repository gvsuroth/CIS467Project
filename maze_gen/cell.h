
struct cell {
	int state;
	int northWall;
	int southWall;
	int westWall;
	int eastWall;
	struct cell * north;
	struct cell * south;
	struct cell * east;
	struct cell * west;
};

typedef struct cell Cell;
