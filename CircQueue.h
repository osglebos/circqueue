#pragma once
#include <stdio.h>
class CircQueue
{
	private:
		struct Element
		{
			int *value;
			Element *nextEl;
		};
		Element *head;
		Element *tail;
		bool isFull(void);

	public:
		CircQueue(void);
		CircQueue(int n);
		void print(void);
		int size(void);
		void put(int n);
		int *get(void);
};

