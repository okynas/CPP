#pragma once

#include "Plane.h"
#include <vector>


class Queue {
	int front, rear;

	std::vector<Plane> q;

public:
	Queue() {
		front = 0;
		rear = 0;
	}

	void enqueue(Plane value);
	Plane dequeue();
	Plane first();
	bool isEmpty();
	int size();

};