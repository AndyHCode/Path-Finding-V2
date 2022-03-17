//all the includes
#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include "MapData.h"


//using queue hold head and run code;
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_Z 122


//functions
void currentLocationFunc(int currentX, int currentY);
void createWallFunc();
void currentLocationFunc(int currentX, int currentY);
queue<head> scanFunc(int x, int y, int weight);
void queueScanFunc();
void printSnakeFunc();
void printFunc();
void createStartFunc();
void createEndFunc();

//global variables
int mapSizeRow = 10, mapSizeColumn = 10;
int startX = 1, startY = 2;
int endX = 9, endY = 8;


vector<vector<mapData>> map(mapSizeRow, vector<mapData>(mapSizeColumn));
int main() {
	/*cout << "input Map Size" << endl;
	cout << "Row: ";
	cin >> mapSizeRow;
	cout << "Column: ";
	cin >> mapSizeColumn;*/
	createWallFunc();
	createStartFunc();
	createEndFunc();
	queueScanFunc();
	//printFunc();
	printSnakeFunc();

}

void createWallFunc() {
	char key;
	head currentHead(mapSizeRow / 2, mapSizeColumn / 2, 0);
	currentLocationFunc(currentHead.column, currentHead.row);
	bool end = true;
	while (end) {
		char key = _getch();
		switch (key) {
		case KEY_UP:
			if (currentHead.column - 1 >= 0) {
				currentHead.column = currentHead.column - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
			}
			break;
		case KEY_DOWN:
			if (currentHead.column + 1 < mapSizeColumn) {
				currentHead.column = currentHead.column + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
			}
			break;

		case KEY_LEFT:
			if (currentHead.row - 1 >= 0) {
				currentHead.row = currentHead.row - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
			}
			break;
		case KEY_RIGHT:
			if (currentHead.row + 1 < mapSizeRow) {
				currentHead.row = currentHead.row + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
			}
			break;
		case KEY_X:
			if(map[currentHead.column][currentHead.row].beenTo == 1) {
				map[currentHead.column][currentHead.row].beenTo = 0;
				map[currentHead.column][currentHead.row].weight = INT_MAX;
			}else {
				map[currentHead.column][currentHead.row].beenTo = 1;
				map[currentHead.column][currentHead.row].weight = -1;
			}
			currentLocationFunc(currentHead.column, currentHead.row);
			break;
		case KEY_Z:
			end = false;
			break;
		}
	}
}

void createStartFunc() {
	char key;
	head currentHead(mapSizeRow / 2, mapSizeColumn / 2, 0);
	currentLocationFunc(currentHead.column, currentHead.row);
	cout << "select Start";
	bool end = true;
	while (end) {
		char key = _getch();
		switch (key) {
		case KEY_UP:
			if (currentHead.column - 1 >= 0) {
				currentHead.column = currentHead.column - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select Start";
			}
			break;
		case KEY_DOWN:
			if (currentHead.column + 1 < mapSizeColumn) {
				currentHead.column = currentHead.column + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select Start";
			}
			break;

		case KEY_LEFT:
			if (currentHead.row - 1 >= 0) {
				currentHead.row = currentHead.row - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select Start";
			}
			break;
		case KEY_RIGHT:
			if (currentHead.row + 1 < mapSizeRow) {
				currentHead.row = currentHead.row + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select Start";
			}
			break;
		case KEY_X:
			if (map[currentHead.column][currentHead.row].beenTo == 0) {
				startY = currentHead.row;
				startX = currentHead.column;
				end = false;
			}
			break;
		}
	}

}

void createEndFunc() {
	char key;
	head currentHead(mapSizeRow / 2, mapSizeColumn / 2, 0);
	currentLocationFunc(currentHead.column, currentHead.row);
	cout << "select End";
	bool end = true;
	while (end) {
		char key = _getch();
		switch (key) {
		case KEY_UP:
			if (currentHead.column - 1 >= 0) {
				currentHead.column = currentHead.column - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select End";
			}
			break;
		case KEY_DOWN:
			if (currentHead.column + 1 < mapSizeColumn) {
				currentHead.column = currentHead.column + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select End";
			}
			break;

		case KEY_LEFT:
			if (currentHead.row - 1 >= 0) {
				currentHead.row = currentHead.row - 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select End";
			}
			break;
		case KEY_RIGHT:
			if (currentHead.row + 1 < mapSizeRow) {
				currentHead.row = currentHead.row + 1;
				currentLocationFunc(currentHead.column, currentHead.row);
				cout << "select End";
			}
			break;
		case KEY_X:
			if (map[currentHead.column][currentHead.row].beenTo == 0) {
				endY = currentHead.row;
				endX = currentHead.column;
				end = false;
			}
			break;
		}
	}

}

void currentLocationFunc(int currentX, int currentY) {
	cout << "\033[H\033[2J\033[3J";
	for (int x = 0; x < mapSizeRow; x++) {
		for (int y = 0; y < mapSizeColumn; y++) {
			if(currentX == x && currentY == y) {
				cout << "[" << map[x][y].beenTo <<"]";
			} else {
				cout << " " << map[x][y].beenTo << " ";
			}
		}
		cout << endl;
	}
}

queue<head> scanFunc(int x, int y, int weight) {
	queue<head> queueScan;
	//right
	if (y + 1 < mapSizeColumn) {
		if (map[x][y + 1].weight > (weight + 1)) {
			map[x][y + 1].weight = weight + 1;
			map[x][y + 1].row = y;
			map[x][y + 1].column = x;
		}
	} 
	//down
	if (x + 1 < mapSizeRow) {
		if (map[x + 1][y].weight > (weight + 1)) {
			map[x + 1][y].weight = weight + 1;
			map[x + 1][y].row = y;
			map[x + 1][y].column = x;
		}
	}


	//left
	if (x - 1 > -1) {
		if (map[x - 1][y].weight > (weight + 1)) {
			map[x - 1][y].weight = weight + 1;
			map[x - 1][y].row = y;
			map[x - 1][y].column = x;
		}
	}


	//up
	if (y - 1 > -1) {
		if (map[x][y - 1].weight > (weight + 1)) {
			map[x][y - 1].weight = weight + 1;
			map[x][y - 1].row = y;
			map[x][y - 1].column = x;
		}
	}
	//cout << "(" << map[1][1].column << ", " << map[1][1].row << ")";

	if (y + 1 < mapSizeColumn && map[x][y + 1].beenTo != 1) {
		queueScan.push(head(x, y + 1,map[x][y + 1].weight));
	} 
	//right
	if (x + 1 < mapSizeRow && map[x + 1][y].beenTo != 1) {
		queueScan.push(head(x + 1, y, map[x + 1][y].weight));
	}
	//left
	if (x - 1 > -1 && map[x - 1][y].beenTo != 1) {
		queueScan.push(head(x - 1, y, map[x - 1][y].weight));
	}
	//down
	if (y - 1 > -1 && map[x][y - 1].beenTo != 1) {
		queueScan.push(head(x, y - 1, map[x][y - 1].weight));
	}
	map[x][y].beenTo = 1;
	return queueScan;
}

void queueScanFunc() {
	queue<head> queue1;
	queue<head> queue2;
	queue<head> queue3;
	queue1 = scanFunc(startX, startY, 0);
	map[startX][startY].beenTo = 1;
	map[startX][startY].weight = 0;
	while (true) {
		while (!queue1.empty()) {
			queue2 = scanFunc(queue1.front().row, queue1.front().column, queue1.front().weight);
			while(!queue2.empty()) {
				queue3.push(queue2.front());
				queue2.pop();
			}
			queue1.pop();
		}
		while(!queue3.empty()) {
			queue2 = scanFunc(queue3.front().row, queue3.front().column, queue3.front().weight);
			while (!queue2.empty()) {
				queue1.push(queue2.front());
				queue2.pop();
			}
			queue3.pop();
		}
		if(queue1.empty() && queue3.empty()) {
			break;
		}
	}
	currentLocationFunc(-1,-1);
}
//use two queue that hold the x and y value for scan func to run. it will go through creating new queue job to do until there no more. it will switch between each queue

void printSnakeFunc() {
	vector<vector<char>> printArray(mapSizeRow, vector<char>(mapSizeColumn));
	for (int x = 0; x < mapSizeColumn; x++) {
		for (int y = 0; y < mapSizeRow; y++) {
			printArray[x][y] = '0';
		}
	}
	cout << endl;
	//start
	head tempHead(endY, endX, 0);
	//end
	head tempHead2(startY, startX, 0);
	if (map[endX][endY].column != -1) {

		int holder = tempHead.column;
		while (!(tempHead.column == tempHead2.column && tempHead.row == tempHead2.row)) {
			printArray[tempHead.column][tempHead.row] = '#';
			holder = tempHead.column;
			tempHead.column = map[tempHead.column][tempHead.row].column;
			tempHead.row = map[holder][tempHead.row].row;
		}
		printArray[tempHead.column][tempHead.row] = '#';
		for (int x = 0; x < mapSizeColumn; x++) {
			for (int y = 0; y < mapSizeRow; y++) {
				cout << " " << printArray[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}else if (tempHead == tempHead2){
			printArray[tempHead.column][tempHead.row] = '#';
			for (int x = 0; x < mapSizeColumn; x++) {
				for (int y = 0; y < mapSizeRow; y++) {
					cout << " " << printArray[x][y] << " ";
				}
				cout << endl;
			}
		}else {
		cout << "No path";
	}
}

void printFunc() {
	cout << "PosMap" << endl;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << " " << map[x][y].beenTo << " ";
		}
		cout << endl;
	}
	cout << "Weight" << endl;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << " " << map[x][y].weight << " ";
		}
		cout << endl;
	}
	cout << "path cords" << endl;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << "(" << map[x][y].column << ", " << map[x][y].row << ")";
		}
		cout << endl;
	}
	cout << "cords" << endl;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << "(" << x << ", " << y << ")";
		}
		cout << endl;
	}
	cout << endl;
}