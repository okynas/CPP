#include "Queue.h"

void Queue::enqueue(Plane value) {
	q.push_back(value);
}

Plane Queue::dequeue() {
	return NULL;
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

