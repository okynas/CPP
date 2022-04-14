#include "Queue.h"

void Queue::enqueue(Plane value) {
	q.push_back(value);
}

Plane Queue::dequeue() {
	Plane plane_to_remove = q.front();
	q.erase(q.begin());
	return plane_to_remove;
}

Plane Queue::first() {
	return q.front();
}

bool Queue::isEmpty() {
	return q.size() == 0;
}

int Queue::size() {
	return q.size();
}

