#pragma once
struct head {
	int row;
	int column;
	int weight;
	head(int row, int column, int weight);
	bool operator==(const head tempHead);
};
struct mapData {
	int row;
	int column;
	int weight;
	int beenTo;
	mapData();
};