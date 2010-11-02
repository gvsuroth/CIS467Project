#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cell.h"

int x, y, counter;
void makeMaze(int rows, int cols, Cell * cells[rows][cols], int counter,
              int xLoc, int yLoc);
int makeRand(int num);

int main(int argc, char *argv[])
{
mtrace();
    int a, b, counter = 0, temp = 20;
    if (argc != 3) {
        x = 11;
        y = 11;
    } else {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }
    Cell *cells[x][y];
    srand(time(NULL));


    for (a = 0; a < x; a++) {
        for (b = 0; b < y; b++) {
            cells[a][b] = (Cell *) malloc(sizeof(Cell));
            cells[a][b]->state = 0;
        }

    }
    cells[0][0]->state = 1;
    cells[0][1]->state = 2;
    cells[1][0]->state = 2;
    makeMaze(x, y, cells, counter, 0, 0);



muntrace();
    return 0;
}



void makeMaze(int rows, int cols, Cell * cells[rows][cols], int counter,
              int xLoc, int yLoc)
{
    int a, b, tempNum, currentX, currentY;
    int deadEnd = 0;
    tempNum = 0;
    currentX = xLoc;
    currentY = yLoc;
    

//    printf("Counter = %d\n", counter);



    //Top LEFT START POINT
    if (currentX == 0 && currentY == 0) {
        tempNum = makeRand(2);
	if ((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3)){
		deadEnd = 1;
        }

        else {
            //ADDS DOWN
            if (tempNum == 0 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;

                if ((currentX + 3) < rows && cells[currentX + 3][currentY]->state == 2) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < rows && cells[currentX + 3][currentY]->state == 0)
                    cells[currentX + 3][currentY]->state = 2;

                if (cells[currentX + 2][currentY + 1]->state == 2) {
                    cells[currentX + 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY + 1]->state == 0)
                    cells[currentX + 2][currentY + 1]->state = 2;

//                if (cells[currentX][currentY + 1]->state == 0)
  //                  cells[currentX][currentY + 1]->state == 2;

		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}	        

	        currentX++;	
	        currentX++;
                counter = counter + 2;
            }
            //ADDS RIGHT
            else if (tempNum == 1 && (cells[currentX][currentY + 1]->state == 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;

                if ((currentY + 3) < cols && cells[currentX][currentY + 3]->state == 2) {
                    cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < cols && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                if (cells[currentX + 1][currentY + 2]->state == 2) {
                    cells[currentX + 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY + 2]->state == 0)
                    cells[currentX + 1][currentY + 2]->state = 2;

                if (cells[1][0]->state == 0)
                    cells[1][0]->state = 2;

		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}	        

	        currentY++;	
                currentY++;
                counter = counter + 2;
            }
        }
    }
    //LEFT ROW
    else if (currentY == 0 && (currentX > 0 && currentX < (rows - 1))) {
        tempNum = makeRand(3);
	if ((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3) && (cells[currentX - 1][currentY]->state == 1 || cells[currentX - 1][currentY]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS DOWN     
            if (tempNum == 0 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;
		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 2) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 0)
                    cells[currentX + 3][currentY]->state = 2;

                if (cells[currentX + 2][currentY + 1]->state == 2) {
                    cells[currentX + 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY + 1]->state == 0)
                    cells[currentX + 2][currentY + 1]->state = 2;

                currentX++;
                currentX++;
                counter = counter + 2;
            }
            //ADDS RIGHT
            else if (tempNum == 1 && (cells[currentX][currentY + 1]->state == 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;
		if(cells[currentX + 1][currentY + 1]->state != 3){
	        	cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY + 1]->state != 3){
                	cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 2) {
                    cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                if (cells[currentX + 1][currentY + 2]->state == 2) {
                    cells[currentX + 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY + 2]->state == 0)
                    cells[currentX + 1][currentY + 2]->state = 2;

                if (cells[currentX - 1][currentY + 2]->state == 2) {
                    cells[currentX - 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY + 2]->state == 0)
                    cells[currentX - 1][currentY + 2]->state = 2;

                currentY++;
                currentY++;
                counter = counter + 2;
            }
            //ADDS UP
            else if (tempNum == 2 && (cells[currentX - 1][currentY]->state == 0 || cells[currentX - 1][currentY]->state == 2)) {
                cells[currentX - 1][currentY]->state = 1;
                cells[currentX - 2][currentY]->state = 1;
		if(cells[currentX - 1][currentY + 1]->state != 3){
	                cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2) {
                    cells[currentX - 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
                    cells[currentX - 3][currentY]->state = 2;

                if (cells[currentX - 1][currentY + 1]->state == 2) {
                    cells[currentX - 1][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY + 1]->state == 0)
                    cells[currentX - 1][currentY + 1]->state = 2;

                currentX--;
                currentX--;
                counter = counter + 2;

            }
        }


    }
    //Top Row
    else if (currentX == 0 && (currentY > 0 && currentY < (cols - 1))) {
        tempNum = makeRand(3);
	if ((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3) && (cells[currentX][currentY - 1]->state == 1 || cells[currentX][currentY - 1]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS DOWN
            if (tempNum == 0 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;
                //South Cell of new cell
                if ((currentX + 3) < (rows - 1) && (cells[currentX + 3][currentY]->state == 2)) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 0))
                    cells[currentX + 3][currentY]->state = 2;
                //East Cell
                if (cells[currentX + 2][currentY + 1]->state == 2) {
                    cells[currentX + 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY + 1]->state == 0)
                    cells[currentX + 2][currentY + 1]->state = 2;
                //West Cell
                if (cells[currentX + 2][currentY - 1]->state == 2) {
                    cells[currentX + 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY - 1]->state == 0)
                    cells[currentX + 2][currentY - 1]->state = 2;

		if(cells[currentX + 1][currentY + 1]->state != 3){
		        cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}
		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}

                currentX++;
                currentX++;
                counter = counter + 2;
            }
            //ADDS RIGHT
            else if (tempNum == 1 && (cells[currentX][currentY + 1]->state == 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;

		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}

                if (cells[currentX + 1][currentY + 2]->state == 2) {
                    cells[currentX + 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY + 2]->state == 0)
                    cells[currentX + 1][currentY + 2]->state = 2;

                if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 2) {
                    cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                currentY++;
                currentY++;
                counter = counter + 2;
            }
            //ADDS LEFT
            else if (tempNum == 2 && (cells[currentX][currentY - 1]->state == 0 || cells[currentX][currentY - 1]->state == 2)) {
                cells[currentX][currentY - 1]->state = 1;
                cells[currentX][currentY - 2]->state = 1;

		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}

                if (cells[currentX + 1][currentY - 2]->state == 2) {
                    cells[currentX + 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY - 2]->state == 0)
                    cells[currentX + 1][currentY - 2]->state = 2;

                if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2) {
                    cells[currentX][currentY - 3]->state = 3;
                    counter++;
                } 
		else if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
                    cells[currentX][currentY - 3]->state = 2;

                currentY = currentY - 2;
                counter = counter + 2;

            }
        }
    }
    //Upper Right Corner
    else if (currentX == 0 && currentY == (cols - 1)) {
        tempNum = makeRand(2);
	if((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX][currentY - 1]->state == 1 || cells[currentX][currentY - 1]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS DOWN
            if (tempNum == 0 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;

                if ((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 2)) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < rows && (cells[currentX + 3][currentY]->state == 0))
                    cells[currentX + 3][currentY]->state = 2;

                if (cells[currentX + 2][currentY - 1]->state == 2) {
                    cells[currentX + 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY - 1]->state == 0)
                    cells[currentX + 2][currentY - 1]->state = 2;

		if(cells[currentX + 1][currentY - 1]->state != 3){
                	cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}

                currentX++;
                currentX++;
                counter = counter + 2;
            }
            //ADDS LEFT
            if (tempNum == 1 && (cells[currentX][currentY - 1]->state == 2 || cells[currentX][currentY - 1]->state == 0)) {
                cells[currentX][currentY - 1]->state = 1;
                cells[currentX][currentY - 2]->state = 1;

		if(cells[currentX + 1][currentY - 1]->state != 3){
                	cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentY - 3) > 0 && (cells[currentX][currentY - 3]->state == 2)) {
                    cells[currentX][currentY - 3]->state = 3;
                    counter++;
                } 
		else if ((currentY - 3) > 0 && (cells[currentX][currentY - 3]->state == 0))
                    cells[currentX][currentY - 3]->state = 2;

                if (cells[currentX + 1][currentY - 2]->state == 2) {
                    cells[currentX + 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY - 2]->state == 0)
                    cells[currentX + 1][currentY - 2]->state = 2;

                currentY--;
                currentY--;
                counter = counter + 2;
            }
        }

    }
    //BOTTOM LEFT CORNER
    else if (currentX == (rows - 1) && currentY == 0) {
        tempNum = makeRand(2);
	if((cells[currentX - 1][currentY]->state == 1 || cells[currentX - 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS UP
            if (tempNum == 0 && (cells[currentX - 1][currentY]->state == 0 || cells[currentX - 1][currentY]->state == 2)) {
                cells[currentX - 1][currentY]->state = 1;
                cells[currentX - 2][currentY]->state = 1;
	
		if(cells[currentX - 1][currentY + 1]->state != 3){
	                cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2) {
                    cells[currentX - 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
                    cells[currentX - 3][currentY]->state = 2;

                if (cells[currentX - 2][currentY + 1]->state == 2) {
                    cells[currentX - 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 2][currentY + 1]->state == 0)
                    cells[currentX - 2][currentY + 1]->state = 2;

                currentX--;
                currentX--;
                counter = counter + 2;
            }
            //ADDS RIGHT
            else if (tempNum == 1 && (cells[currentX][currentY + 1]->state = 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;
		if(cells[currentX - 1][currentY + 1]->state != 3){
	                cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentY + 3) < cols && cells[currentX][currentY + 3]->state == 2) {
                    cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < cols && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                if (cells[currentX - 1][currentY + 2]->state == 2) {
                    cells[currentX - 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY + 2]->state == 0)
                    cells[currentX - 1][currentY + 2]->state = 2;

                currentY++;
                currentY++;
                counter = counter + 2;
            }
        }

    }
    //BOTTOM ROW NOT AT ENDS
    else if ((currentX == (rows - 1)) && (currentY > 0 && currentY < (cols - 1))) {
        tempNum = makeRand(3);
	if((cells[currentX - 1][currentY]->state == 1 || cells[currentX - 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3) && (cells[currentX][currentY - 1]->state == 1 || cells[currentX][currentY - 1]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS RIGHT
            if (tempNum == 0 && (cells[currentX][currentY + 1]->state == 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;
		if(cells[currentX - 1][currentY + 1]->state != 3){
                	cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 2) {
                    cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                if (cells[currentX - 1][currentY + 2]->state == 2) {
                    cells[currentX - 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY + 2]->state == 0)
                    cells[currentX - 1][currentY + 2]->state = 2;

                currentY++;
                currentY++;
                counter = counter + 2;
            }
            //ADDS LEFT
            else if (tempNum == 1 && (cells[currentX][currentY - 1]->state == 0 || cells[currentX][currentY - 1]->state == 2)) {
                cells[currentX][currentY - 1]->state = 1;
                cells[currentX][currentY - 2]->state = 1;
		
		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2) {
                    cells[currentX][currentY - 3]->state = 3;
                    counter++;
                } 
		else if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
                    cells[currentX][currentY - 3]->state = 2;

                if (cells[currentX - 1][currentY - 2]->state == 2) {
                    cells[currentX - 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY - 2]->state == 0)
                    cells[currentX - 1][currentY - 2]->state = 2;

                currentY--;
                currentY--;
                counter = counter + 2;
            }
            //ADDS UP
            else if (tempNum == 2 && (cells[currentX - 1][currentY]->state == 0 || cells[currentX - 1][currentY]->state == 2)) {
                cells[currentX - 1][currentY]->state = 1;
                cells[currentX - 2][currentY]->state = 1;

		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY + 1]->state != 3){
        	        cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2) {
                    cells[currentX - 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
                    cells[currentX - 3][currentY]->state = 2;

                if (cells[currentX - 2][currentY - 1]->state == 2) {
                    cells[currentX - 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 2][currentY - 1]->state == 0)
                    cells[currentX - 2][currentY - 1]->state = 2;

                if (cells[currentX - 2][currentY + 1]->state == 2) {
                    cells[currentX - 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 2][currentY + 1]->state == 0)
                    cells[currentX - 2][currentY + 1]->state = 2;

                currentX--;
                currentX--;
                counter = counter + 2;
            }
        }
    }



    //RIGHT ROW
    else if ((currentX > 0 && currentX < (rows - 1)) && currentY == (cols - 1)) {
        tempNum = makeRand(3);
	if ((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX - 1][currentY]->state == 1 || cells[currentX - 1][currentY]->state == 3) && (cells[currentX][currentY - 1]->state == 1 || cells[currentX][currentY - 1]->state == 3)){
		deadEnd = 1;
        } 
	else {
            //ADDS DOWN
            if (tempNum == 0 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;
		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}			

                if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 2) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 0)
                    cells[currentX + 3][currentY]->state = 2;

                if (cells[currentX + 2][currentY - 1]->state == 2) {
                    cells[currentX + 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY - 1]->state == 0)
                    cells[currentX + 2][currentY - 1]->state = 2;

                currentX++;
                currentX++;
                counter = counter + 2;
            }
            //ADDS LEFT
            else if (tempNum == 1 && (cells[currentX][currentY - 1]->state == 0 || cells[currentX][currentY - 1]->state == 2)) {
                cells[currentX][currentY - 1]->state = 1;
                cells[currentX][currentY - 2]->state = 1;

		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2) {
                    cells[currentX][currentY - 3]->state = 3;
                    counter++;
                } 
		else if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
                    cells[currentX][currentY - 3]->state = 2;

                if (cells[currentX + 1][currentY - 2]->state == 2) {
                    cells[currentX + 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY - 2]->state == 0)
                    cells[currentX + 1][currentY - 2]->state = 2;

                if (cells[currentX - 1][currentY - 2]->state == 2) {
                    cells[currentX - 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY - 2]->state == 0)
                    cells[currentX - 1][currentY - 2]->state = 2;

                currentY--;
                currentY--;
                counter = counter + 2;
            }
            //ADDS UP
            else if (tempNum == 2 && (cells[currentX - 1][currentY]->state == 0 || cells[currentX - 1][currentY]->state == 2)) {
                cells[currentX - 1][currentY]->state = 1;
                cells[currentX - 2][currentY]->state = 1;
		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2) {
                    cells[currentX - 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
                    cells[currentX - 3][currentY]->state = 2;

                if (cells[currentX - 2][currentY - 1]->state == 2) {
                    cells[currentX - 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 2][currentY - 1]->state == 0)
                    cells[currentX - 2][currentY - 1]->state = 2;

                currentX--;
                currentX--;
                counter = counter + 2;
            }
        }
    }


    //Middle Cells
    else if ((currentX > 0 && currentX < rows - 1) && (currentY > 0 && currentY < (cols - 1))) {

        tempNum = makeRand(4);
	if ((cells[currentX + 1][currentY]->state == 1 || cells[currentX + 1][currentY]->state == 3) && (cells[currentX - 1][currentY]->state == 1 || cells[currentX - 1][currentY]->state == 3) && (cells[currentX][currentY + 1]->state == 1 || cells[currentX][currentY + 1]->state == 3) && (cells[currentX][currentY - 1]->state == 1 || cells[currentX][currentY - 1]->state == 3)){
		deadEnd = 1;
        } 
	else {

            //ADDS RIGHT
            if (tempNum == 0 && (cells[currentX][currentY + 1]->state == 0 || cells[currentX][currentY + 1]->state == 2)) {
                cells[currentX][currentY + 1]->state = 1;
                cells[currentX][currentY + 2]->state = 1;

		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY + 1]->state != 3){
	                cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 2) {
	            cells[currentX][currentY + 3]->state = 3;
                    counter++;
                } 
		else if ((currentY + 3) < (cols - 1) && cells[currentX][currentY + 3]->state == 0)
                    cells[currentX][currentY + 3]->state = 2;

                if (cells[currentX + 1][currentY + 2]->state == 2) {
                    cells[currentX + 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 1][currentY + 2]->state == 0)
                    cells[currentX + 1][currentY + 2]->state = 2;

                if (cells[currentX - 1][currentY + 2]->state == 2) {
                    cells[currentX - 1][currentY + 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY + 2]->state == 0)
                    cells[currentX - 1][currentY + 2]->state = 2;

                currentY++;
                currentY++;
                counter = counter + 2;

            }
            //ADDS DOWN
            else if (tempNum == 1 && (cells[currentX + 1][currentY]->state == 0 || cells[currentX + 1][currentY]->state == 2)) {
                cells[currentX + 1][currentY]->state = 1;
                cells[currentX + 2][currentY]->state = 1;

		if(cells[currentX + 1][currentY + 1]->state != 3){
	                cells[currentX + 1][currentY + 1]->state = 3;
			counter++;
		}
		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 2) {
                    cells[currentX + 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX + 3) < (rows - 1) && cells[currentX + 3][currentY]->state == 0)
                    cells[currentX + 3][currentY]->state = 2;

                if (cells[currentX + 2][currentY + 1]->state == 2) {
                    cells[currentX + 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY + 1]->state == 0)
                    cells[currentX + 2][currentY + 1]->state = 2;

                if (cells[currentX + 2][currentY - 1]->state == 2) {
                    cells[currentX + 2][currentY - 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX + 2][currentY - 1]->state == 0)
                    cells[currentX + 2][currentY - 1]->state = 2;

                currentX++;
                currentX++;
                counter = counter + 2;
            }
            //ADDS LEFT
            else if (tempNum == 2 && (cells[currentX][currentY - 1]->state == 0 || cells[currentX][currentY - 1]->state == 2)) {
                cells[currentX][currentY - 1]->state = 1;
                cells[currentX][currentY - 2]->state = 1;
		
		if(cells[currentX + 1][currentY - 1]->state != 3){
	                cells[currentX + 1][currentY - 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}

                if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 2) {
                    cells[currentX][currentY - 3]->state = 3;
                    counter++;
                } 
		else if ((currentY - 3) > 0 && cells[currentX][currentY - 3]->state == 0)
                    cells[currentX][currentY - 3]->state = 2;

                if (cells[currentX + 1][currentY - 2]->state == 2) {
                    cells[currentX + 1][currentY - 2]->state = 3;
                    counter++;
                }
		else if (cells[currentX + 1][currentY - 2]->state == 0)
                    cells[currentX + 1][currentY - 2]->state = 2;

                if (cells[currentX - 1][currentY - 2]->state == 2) {
                    cells[currentX - 1][currentY - 2]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 1][currentY - 2]->state == 0)
                    cells[currentX - 1][currentY - 2]->state = 2;

                currentY--;
                currentY--;
                counter = counter + 2;
            }
            //ADDS UP
            else if (tempNum == 3 && (cells[currentX - 1][currentY]->state == 0 || cells[currentX - 1][currentY]->state == 2)) {
                cells[currentX - 1][currentY]->state = 1;
                cells[currentX - 2][currentY]->state = 1;

		if(cells[currentX - 1][currentY - 1]->state != 3){
	                cells[currentX - 1][currentY - 1]->state = 3;
			counter++;
		}
		if(cells[currentX - 1][currentY + 1]->state != 3){
        	        cells[currentX - 1][currentY + 1]->state = 3;
			counter++;
		}

                if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 2) {
                    cells[currentX - 3][currentY]->state = 3;
                    counter++;
                } 
		else if ((currentX - 3) > 0 && cells[currentX - 3][currentY]->state == 0)
                    cells[currentX - 3][currentY]->state = 2;

                if (cells[currentX - 2][currentY - 1]->state == 2) {
                    cells[currentX - 2][currentY - 1]->state = 3;
                    counter++;
                }
		else if (cells[currentX - 2][currentY - 1]->state == 0)
                    cells[currentX - 2][currentY - 1]->state = 2;

                if (cells[currentX - 2][currentY + 1]->state == 2) {
                    cells[currentX - 2][currentY + 1]->state = 3;
                    counter++;
                } 
		else if (cells[currentX - 2][currentY + 1]->state == 0)
                    cells[currentX - 2][currentY + 1]->state = 2;

                currentX--;
                currentX--;
                counter = counter + 2;
            }
        }
  }	
	else if(currentX == (cols - 1) && currentY == (rows - 1)){
		deadEnd = 1;
	}

/**
    for(a = 0; a < cols; a++){	
        for (b = 0; b < rows; b++){
            printf("%d  ", cells[a][b]->state);
        }
        printf("\n\n");
    }
**/



	if(counter < ((rows * cols) - 2)){
		if(deadEnd > 0){
			for(a = 0; a < rows; a++){
				for(b = 0; b < cols; b++){
					if(cells[a][b]->state == 2){
						int cont = 0;				
						while(cont == 0){
							tempNum = makeRand(4);
							if(tempNum == 0){
								if((a - 1) >= 0 && cells[a - 1][b]->state == 1){
									currentX = (a - 1);
									currentY = b;
									cont++;
								}
							}
							else if(tempNum == 1){
								if((a + 1) < cols && cells[a + 1][b]->state == 1){
									currentX = (a + 1);
									currentY = b;
									cont++;
								}
							}
							else if(tempNum == 2){
								if((b - 1) >= 0 && cells[a][b - 1]->state == 1){
									currentX = a;
									currentY = (b - 1);
									cont++;
								}
							}
							else if(tempNum == 3){
								if((b + 1) < rows && cells[a][b + 1]->state == 1){
									currentX = a;
									currentY = (b + 1);
									cont++;
								}
							}
						}
						a = rows;
						b = cols;
				}
			}
		}
		deadEnd = 0;
	}
	makeMaze(rows,cols,cells,counter,currentX, currentY);

   }
   else{
	for(a = 0; a < rows; a++){
		for(b = 0; b < cols; b++){
			if(cells[a][b]->state != 1)
				cells[a][b]->state = 0;
			printf("%d ",cells[a][b]->state);
			free(cells[a][b]);
		}
		printf("\n");
	}
   }     
}

int makeRand(int num)
{
    return (rand() % num);
}
