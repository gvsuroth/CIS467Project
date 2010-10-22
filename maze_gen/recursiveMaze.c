#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cell.h"

int x,y, counter;
void makeMaze(int rows, int cols, Cell * cells[cols][rows], int counter, int xLoc, int yLoc);
int getNewCurrX(int rows, int cols, Cell * cells[cols][rows], int counter, int xLoc, int yLoc);
int getNewCurrY(int rows, int cols, Cell * cells[cols][rows], int counter, int xLoc, int yLoc);
int makeRand(int num);

int main(int argc, char *argv[]){
	int a, b, counter = 0, temp = 20;
	if(argc != 3){
		x = 11;
		y = 11;
	}
	else{
		x = atoi (argv[1]);
		y = atoi (argv[2]);
	}
	Cell * cells[x][y];
	srand(time(NULL));

	for (a = 0; a < x; a++){
		for(b = 0; b < y; b++){
			cells[a][b] = (Cell *)malloc(sizeof(Cell));
			cells[a][b]->state = 0;
		}

	}
	cells[0][0]->state = 1;
//	cells[3][2]->state = 2;
//	srand(time(NULL));
	makeMaze(x,y,cells, counter, 0, 0);
/**	printf("%d\n", makeRand(temp));
	temp++;
	printf("%d\n", makeRand(temp));
	printf("\n%d\n", counter);
**/

	return 0;
}
int getNewCurrX(int rows, int cols, Cell * cells[cols][rows], int counter, int xLoc, int yLoc){
	int a, b;

	for(a = 0; a < rows; a++){
		for(b = 0; b < cols; b++){
			if(cells[a][b]->state == 2){
				printf("Cells[%d][%d]\n", a, b);
				return a;
//				a = rows;
//				b = cols;
			}
		}
	}
}

int getNewCurrY(int rows, int cols, Cell * cells[cols][rows],int counter, int xLoc, int yLoc){
	int a, b;
	for ( a = 0; a < rows; a++){
		for(b = 0; b < cols; b++){
			if(cells[a][b]->state == 2){
				return b;
			}
		}
	}
}

void makeMaze(int rows, int cols, Cell * cells[cols][rows], int counter, int xLoc, int yLoc){
	int a, b, tempNum, cont = 0, currentX, currentY;
	tempNum = 0;
	currentX = xLoc;
	currentY = yLoc;
//	int currentX = 0, currentY = 0;
//	srand(time(NULL));
/**	for (a = 0; a < x; a++){
		for(b = 0; b < y; b++){
			cells[a][b] = (Cell *)malloc(sizeof(Cell));
			cells[a][b]->state = 0;
		}
	}
**/
/**	for (a = 0; a <x; a++){
		for(b = 0; b < y; b++){
			printf("%d  ", cells[a][b]->state);
		}
		printf("\n\n");
	}
**/
	printf("Counter = %d\n", counter);
//	srand(time(NULL));
//	while ( cont < 2){


	
	//Top LEFT START POINT
	if(currentX == 0 && currentY == 0){
		printf("\nBefore RAND\n");
		tempNum = makeRand(2);
		printf("%d\n", tempNum);
		if(tempNum == 0){//Adds down
			cells[currentX + 1][currentY]->state = 1;
			cells[currentX + 2][currentY]->state = 1;
			if((currentX + 3) < rows && cells[currentX + 3][currentY]->state == 2)
				cells[currentX + 3][currentY]->state = 3;
			else if((currentX + 3) < rows && cells[currentX + 3][currentY]->state == 0)
				cells[currentX + 3][currentY]->state = 2;
			if(cells[currentX + 2][currentY + 1]->state == 2)
				cells[currentX + 2][currentY + 1]->state = 3;
			else if(cells[currentX + 2][currentY + 1]->state == 0)
				cells[currentX + 2][currentY + 1]->state = 2;

			if(cells[currentX][currentY + 1]->state == 0)
				cells[currentX][currentY + 1]->state == 2;

			cells[currentX + 1][currentY + 1]->state = 3;
			currentX++;
			currentX++;
		}

		else if(tempNum == 1){//Adds to the right
			cells[currentX][currentY + 1]->state = 1;
			cells[currentX][currentY + 2]->state = 1;	
			if((currentY + 3) < rows && cells[currentX][currentY + 3]->state == 2)
				cells[currentX][currentY + 3]->state = 3;
			else if((currentY + 3) < rows && cells[currentX][currentY + 3]->state == 0)
				cells[currentX][currentY + 3]->state = 2;
			if(cells[currentX + 1][currentY + 2]->state == 2)
				cells[currentX + 1][currentY + 2]->state = 3;
			else if(cells[currentX + 1][currentY + 2]->state == 0)
				cells[currentX + 1][currentY + 2]->state = 2;

			if(cells[currentX + 1][currentY]->state == 0)
				cells[currentX + 1][currentY]->state = 2;
			cells[currentX + 1][currentY + 1]->state = 3;
			currentY++;
			currentY++;
		}
	}


	//LEFT ROW
	else if (currentY == 0 && (currentX > 0 && currentX < (rows-1))){
		tempNum = makeRand(3);

		//ADDS DOWN	
		if(tempNum == 0 && cells[currentX + 1][currentY]->state < 3){
			cells[currentX + 1][currentY]->state = 1;
			cells[currentX + 2][currentY]->state = 1;
			cells[currentX + 1][currentY + 1]->state = 3;

			if((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 2)
				cells[currentX + 3][currentY]->state = 3;
			else if((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 0)
				cells[currentX + 3][currentY]->state = 2;

			if(cells[currentX + 2][currentY + 1]->state == 2)
				cells[currentX + 2][currentY + 1]->state = 3;
			else if(cells[currentX + 2][currentY + 1]->state == 0)
				cells[currentX + 2][currentY + 1]->state = 2;

			currentX++; currentX++;
		}

		//ADDS RIGHT
		else if(tempNum == 1 && cells[currentX][currentY + 1]->state < 3){
			cells[currentX][currentY + 1]->state = 1;
			cells[currentX][currentY + 2]->state = 1;
			cells[currentX + 1][currentY + 1]->state = 3;
			cells[currentX - 1][currentY + 1]->state = 3;

			if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 2)
				cells[currentX][currentY + 3]->state = 3;
			else if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 0)
				cells[currentX][currentY + 3]->state = 2;

			if(cells[currentX + 1][currentY + 2]->state == 2)
				cells[currentX + 1][currentY + 2]->state = 3;
			else if(cells[currentX + 1][currentY + 2]->state == 0)
				cells[currentX + 1][currentY + 2]->state = 2;

			if(cells[currentX - 1][currentY + 2]->state == 2)
				cells[currentX - 1][currentY + 2]->state = 3;
			else if(cells[currentX - 1][currentY + 2]->state == 0)
				cells[currentX - 1][currentY + 2]->state = 2;

			currentY++;currentY++;
		}

		//ADDS UP
		else if(tempNum == 2 && cells[currentX - 1][currentY]->state < 3){
			cells[currentX - 1][currentY]->state = 1;
			cells[currentX - 2][currentY]->state = 1;
			cells[currentX - 1][currentY + 1]->state = 3;

			if((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2)
				cells[currentX - 3][currentY]->state = 3;
			else if((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
				cells[currentX - 3][currentY]->state = 2;

			if(cells[currentX - 1][currentY + 1]->state == 2)
				cells[currentX - 1][currentY + 1]->state = 3;
			else if(cells[currentX - 1][currentY + 1]->state == 0)
				cells[currentX - 1][currentY + 1]->state = 2;

			currentX--;currentX--;

		}


	}


	//Top Row
	else if(currentX == 0 && (currentY > 0 && currentY < (rows - 1))){
		tempNum = makeRand(3);
		printf("\n%d\n", tempNum);

		//ADDS DOWN
		if(tempNum == 0 && cells[currentX + 1][currentY]->state < 3){
			cells[currentX + 1][currentY]->state = 1;
			cells[currentX + 2][currentY]->state = 1;
			//South Cell of new cell
			if((currentX + 3) < (rows - 1) && (cells[currentX + 3][currentY]->state == 2))
				cells[currentX + 3][currentY]->state = 3;
			else if((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 0))
				cells[currentX + 3][currentY]->state = 2;
			//East Cell
			if(cells[currentX + 2][currentY + 1]->state == 2)
				cells[currentX + 2][currentY + 1]->state = 3;
			else if(cells[currentX + 2][currentY + 1]->state == 0)
				cells[currentX + 2][currentY + 1]->state = 2;
			//West Cell
			if(cells[currentX + 2][currentY - 1]->state == 2)
				cells[currentX + 2][currentY - 1]->state = 3;
			else if(cells[currentX + 2][currentY - 1]->state == 0)
				cells[currentX + 2][currentY - 1]->state = 2;

			cells[currentX + 1][currentY + 1]->state = 3;
			cells[currentX + 1][currentY - 1]->state = 3;

			currentX++;
			currentX++;
		}
		//ADDS RIGHT
		else if(tempNum == 1 && cells[currentX][currentY + 1]->state < 3){
			cells[currentX][currentY + 1]->state = 1;
			cells[currentX][currentY + 2]->state = 1;
			
			cells[currentX + 1][currentY + 1]->state = 3;
			if(cells[currentX + 1][currentY + 2]->state == 2)
				cells[currentX + 1][currentY + 2]->state = 3;
			else if(cells[currentX + 1][currentY + 2]->state == 0)
				cells[currentX + 1][currentY + 2]->state = 2;
				
			if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 2)
				cells[currentX][currentY + 3]->state = 3;
			else if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 0)
				cells[currentX][currentY + 3]->state = 2;
				
			currentY++;currentY++;
		}
		//ADDS LEFT
		else if(tempNum == 2 && cells[currentX][currentY - 1]->state < 3 && cells[currentX][currentY - 1]->state < 3){
			cells[currentX][currentY - 1]->state = 1;
			cells[currentX][currentY - 2]->state = 1;

			cells[currentX + 1][currentY - 1]->state = 3;

		}
	}

	//Upper Right Corner
	else if(currentX == 0 && currentY == (cols - 1)){
		tempNum = makeRand(2);

		//ADDS DOWN
		if(tempNum == 0){
			if(cells[currentX + 1][currentY]->state != 3){
				cells[currentX + 1][currentY]->state = 1;
				cells[currentX + 2][currentY]->state = 1;
			}
			
			if((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 2))
				cells[currentX + 3][currentY]->state = 3;
			else if((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 0))
				cells[currentX + 3][currentY]->state = 2;

			if(cells[currentX + 2][currentY - 1]->state == 2)
				cells[currentX + 2][currentY - 1]->state = 3;
			else if(cells[currentX + 2][currentY - 1]->state == 0)
				cells[currentX + 2][currentY - 1]->state = 2;
			cells[currentX + 1][currentY - 1]->state = 3;

			currentX++;currentX++;
		}

		//ADDS LEFT
		if(tempNum == 1){
			if(cells[currentX][currentY - 1]-> state != 3){
				cells[currentX][currentY - 1]->state = 1;
				cells[currentX][currentY - 2]->state = 1;
			}
			cells[currentX + 1][currentY - 1]->state = 3;
			
			if((currentY - 3) > 0 && (cells[currentX][currentY - 3]->state == 0))
				cells[currentX][currentY - 3]->state = 2;
			else if((currentY - 3) > 0 && (cells[currentX][currentY - 3]->state == 2))
				cells[currentX][currentY - 3]->state = 3;

			if(cells[currentX + 1][currentY - 2]->state == 2)
				cells[currentX + 1][currentY - 2]->state == 3;
			else if (cells[currentX + 1][currentY - 2]->state == 0)
				cells[currentX + 1][currentY - 2]->state = 2;			
			currentY--;currentY--;
		}

	}

	//Bottom Row not at the ends
	else if(currentX == (rows - 1) && (currentY > 0 && currentY < (rows - 1))){
			tempNum = makeRand(3);

			//ADDS RIGHT
			if(tempNum == 0 && cells[currentX][currentY + 1]->state < 3){				
				cells[currentX][currentY + 1]->state = 1;
				cells[currentX][currentY + 2]->state = 1;

				//Mid North Cell
				cells[currentX - 1][currentY + 1]->state == 3;

				//East Cell
				if((currentY + 3) < rows && (cells[currentX][currentY + 3]->state == 0))
					cells[currentX][currentY + 3]->state = 2;
				else if((currentY + 3) < rows && (cells[currentX][currentY + 3]->state == 2))
					cells[currentX][currentY + 3]->state = 3;
				//North Cell
				if(cells[currentX - 1][currentY + 2]->state == 2)
					cells[currentX - 1][currentY + 2]->state = 3;
				else if(cells[currentX - 1][currentY + 2]->state == 0)
					cells[currentX - 1][currentY + 2]->state = 2;
			
				currentY ++;currentY++;
			}

			//ADDS LEFT
			else if(tempNum == 1 && cells[currentX][currentY - 1]->state < 3){
				cells[currentX][currentY - 1]->state = 1;
				cells[currentX][currentY - 2]->state = 1;
				cells[currentX - 1][currentY - 1]->state = 3;

				if((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
					cells[currentX][currentY - 3]->state = 2;
				else if((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2)
					cells[currentX][currentY - 3]->state = 3;
			
				if(cells[currentX - 1][currentY - 2]->state = 0)
					cells[currentX - 1][currentY - 2]->state = 2;
				else if(cells[currentX - 1][currentY - 2]->state = 2)
					cells[currentX - 1][currentY - 2]->state = 3;

				currentY--;currentY--;
			}

			//ADDS UP
			else if(tempNum == 2 && cells[currentX - 1][currentY]->state < 3){
				cells[currentX - 1][currentY]->state = 1;
				cells[currentX - 2][currentY]->state = 1;
				cells[currentX - 1][currentY - 1]->state = 3;
				cells[currentX - 1][currentY + 1]->state = 3;

				if(cells[currentX - 3][currentY]->state == 0)
					cells[currentX - 3][currentY]->state = 2;
				else if(cells[currentX - 3][currentY]->state == 2)
					cells[currentX - 3][currentY]->state = 3;
				
				if(cells[currentX - 2][currentY - 1]->state == 0)
					cells[currentX - 2][currentY - 1]->state = 2;
				else if (cells[currentX - 2][currentY - 1]->state == 2)
					cells[currentX - 2][currentY - 1]->state = 3;

				if(cells[currentX - 2][currentY + 1]->state == 0)
					cells[currentX - 2][currentY + 1]->state = 2;
				else if(cells[currentX - 2][currentY + 1]->state == 2)
					cells[currentX - 2][currentY + 1]->state = 3;

				currentX--;currentX--;
			}

	}

	//Middle Cells
	else if((currentX > 0 && currentX < rows - 1) && (currentY > 0 && currentY < (rows - 1))){

		tempNum = makeRand(4);

		//ADDS RIGHT
		if(tempNum == 0 && cells[currentX][currentY + 1]->state < 3){
			cells[currentX][currentY + 1]->state = 1;
			cells[currentX][currentY + 2]->state = 1;
			cells[currentX + 1][currentY + 1]->state = 3;
			cells[currentX - 1][currentY + 1]->state = 3;

			if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 2)
				cells[currentX][currentY + 3]->state = 3;
			else if((currentY + 3) < (rows - 1) && cells[currentX][currentY + 3]->state == 0)
				cells[currentX][currentY + 3]->state = 2;

			if(cells[currentX + 1][currentY + 2]->state == 0)
				cells[currentX + 1][currentY + 2]->state = 2;
			else if(cells[currentX + 1][currentY + 2]->state == 2)
				cells[currentX + 1][currentY + 2]->state = 3;

			if(cells[currentX - 1][currentY + 2]->state ==0)
				cells[currentX - 1][currentY + 2]->state = 2;
			else if(cells[currentX - 1][currentY + 2]->state == 2)
				cells[currentX - 1][currentY + 2]->state = 3;

			currentY++;currentY++;

		}

		//ADDS DOWN
		else if(tempNum == 1 && cells[currentX + 1][currentY]->state < 3){
			cells[currentX + 1][currentY]->state = 1;
			cells[currentX + 2][currentY]->state = 1;
			cells[currentX + 1][currentY + 1]->state = 3;
			cells[currentX + 1][currentY - 1]->state = 3;

			if((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 0)
				cells[currentX + 3][currentY]->state = 2;
			else if((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 2)
				cells[currentX + 3][currentY]->state = 3;

			if(cells[currentX + 2][currentY + 1]->state == 0)
				cells[currentX + 2][currentY + 1]->state = 2;
			else if(cells[currentX + 2][currentY + 1]->state == 2)
				cells[currentX + 2][currentY + 1]->state = 3;

			if(cells[currentX + 2][currentY - 1]->state == 0)
				cells[currentX + 2][currentY - 1]->state = 2;
			else if(cells[currentX + 2][currentY - 1]->state == 2)
				cells[currentX + 2][currentY - 1]->state = 3;

			currentX++;currentX++;
		}

		//ADDS LEFT
		else if(tempNum == 2 && cells[currentX][currentY - 1]->state < 3){
			cells[currentX][currentY - 1]->state = 1;
			cells[currentX][currentY - 2]->state = 1;
			cells[currentX + 1][currentY - 1]->state = 3;
			cells[currentX - 1][currentY - 1]->state = 3;

			if((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
				cells[currentX][currentY - 3]->state = 2;
			else if((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2)
				cells[currentX][currentY - 3]->state = 3;

			if(cells[currentX + 1][currentY - 2]->state == 0)	
				cells[currentX + 1][currentY - 2]->state = 2;
			else if(cells[currentX + 1][currentY - 2]->state == 2)
				cells[currentX + 1][currentY - 2]->state = 3;

			if(cells[currentX - 1][currentY - 2]->state == 0)
				cells[currentX - 1][currentY - 2]->state = 2;
			else if(cells[currentX - 1][currentY - 2]->state == 2)
				cells[currentX - 1][currentY - 2]->state = 3;

			currentY--;currentY--;
		}

		//ADDS UP
		else if(tempNum == 3 && cells[currentX - 1][currentY]->state < 3){
			cells[currentX - 1][currentY]->state = 1;
			cells[currentX - 2][currentY]->state = 1;
			cells[currentX - 1][currentY - 1]->state = 3;
			cells[currentX - 1][currentY + 1]->state = 3;

			if((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
				cells[currentX - 3][currentY]->state = 2;
			else if((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2)
				cells[currentX - 3][currentY]->state = 3;

			if(cells[currentX - 2][currentY - 1]->state == 0)
				cells[currentX - 2][currentY - 1]->state = 2;
			else if(cells[currentX - 2][currentY - 1]->state == 2)
				cells[currentX - 2][currentY - 1]->state = 3;

			if(cells[currentX - 2][currentY + 1]->state == 0)
				cells[currentX - 2][currentY + 1]->state = 2;
			else if(cells[currentX - 2][currentY + 1]->state == 2)
				cells[currentX - 2][currentY + 1]->state = 3;
			
			currentX--;currentX--;
		}



/**		if(cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2){
		cells[currentX + 1][currentY]->state = 1;
		cells[currentX + 2][currentY]->state = 1;
	
		if((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 0))
			cells[currentX + 3][currentY]->state = 2;
		else if((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 2))
			cells[currentX + 3][currentY]->state = 3;
		
		if(cells[currentX + 2][currentY + 1]->state == 2)
			cells[currentX + 2][currentY + 1]->state = 3;
		else if(cells[currentX + 2][currentY + 1]->state == 0)
			cells[currentX + 2][currentY + 1]->state = 2;

		if(cells[currentX + 2][currentY - 1]->state == 2)
			cells[currentX + 2][currentY - 1]->state = 3;
		else if(cells[currentX + 2][currentY - 1]->state == 0)
			cells[currentX + 2][currentY - 1]->state = 2;

		cells[currentX + 1][currentY + 1]->state = 3;
		cells[currentX + 1][currentY - 1]->state = 3;
		currentX++;
		currentX++;

	} **/

	}
	
//	tempNum = (rand()/(RAND_MAX + 1.0)) * 2;
//	printf("\n%d\n", tempNum);

//	printf("%d\n", makeRand(20));
//	printf("%d\n", makeRand(20));

	for (a = 0; a < x; a++){
		for(b = 0; b < y; b++){
			printf("%d  ", cells[a][b]->state);
		}
		printf("\n\n");
	}
	counter++;
	



	printf("Counter = %d\n", counter);
	if((currentX == (rows - 1)) && (currentY == (cols - 1))){
		counter = 4;
		printf("\nEND POINT");

		currentX = getNewCurrX(rows,cols,cells,counter, currentX, currentY);
		currentY = getNewCurrY(rows,cols,cells,counter, currentX, currentY);
		currentY --;
	}
	if(counter < 20)
		makeMaze(rows,cols,cells,counter, currentX, currentY);
//	printf("%d\n", counter);
//	printf("END\n");
}

int makeRand(int num){
	return (rand() % num);
//	return (rand()/(RAND_MAX + 1.0)) * num;
}
