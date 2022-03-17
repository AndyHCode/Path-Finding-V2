#include <iostream>
#include "MapData.h"
using namespace std;

head::head(int row, int column, int weight) {
	this->row = row;
	this->column = column;
	this->weight = weight;
}
mapData::mapData() {
	this->weight = INT_MAX;
	this->row = -1;
	this->column = -1;
	this->beenTo = 0;
}
bool head::operator==(const head tempHead) {
	if(this->column == tempHead.column && this->row == tempHead.column) {
		return true;
	}
	return false;
}
