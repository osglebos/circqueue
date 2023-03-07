#include "CircQueue.h"
CircQueue::CircQueue(void) {}

CircQueue::CircQueue(int n) {
	if (n == 0)
	{
		tail = head = NULL;
		return;
	}
	head = new Element;
	head->value = NULL;
	Element *prev = head;
	for (int i = 0; i < n - 1; i++) {
		Element *T = new Element;
		prev->nextEl = T;
		T->value = NULL;
		prev = T;
	}
	prev->nextEl = head;
	tail = head;
}

void CircQueue::print(void)
{
	if (head == NULL)
	{
		printf("there is no elements.\n");
		return;
	}
	if (tail == head) printf("{(head)%i(tail)} ", head->value == NULL ? 0 : *head->value);
	else printf("{(head)%i} ", head->value == NULL ? 0 : *head->value);

	for (Element *T = head->nextEl; T != head; T = T->nextEl)
		if (T == tail) printf("{%i(tail)} ", T->value == NULL ? 0 : *T->value);
		else printf("{%i} ", T->value == NULL ? 0 : *T->value);
	printf("\n");
}

int CircQueue::size(void)
{
	if (head == NULL)	return 0;
	int count = 1;
	for (Element *T = head->nextEl; T != head; T = T->nextEl)
		count++;
	return count;
}

void CircQueue::put(int n)
{
	if(this->size() == 0) return;
	if (head->value == NULL)	head->value = new int;
	*head->value = n;
	if (head == tail && this->isFull()) tail = tail->nextEl;
	head = head->nextEl;
}

bool CircQueue::isFull(void)
{
	if (head == NULL)	return true;
	int count = 0;
	if (head->value != NULL) count++;
	for (Element *T = head->nextEl; T != head; T = T->nextEl)
		if (T->value != NULL)
			count++;
	return count == this->size() ? true : false;
}

int *CircQueue::get(void)
{
	int *res = NULL;
	if (tail == NULL || tail->value == NULL) return res;
	res = new int(*tail->value);
	delete(tail->value);
	tail->value = NULL;
	tail = tail->nextEl;
	return res;
}

