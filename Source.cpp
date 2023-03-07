#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "CircQueue.h"

int isEven(int value) { return value % 2; }

int main(void)
{
	CircQueue cb;

	bool exit = false;
	char key;

	printf("�������������������������������ͻ\n");
	printf("�esc�Exit			�\n");
	printf("�1  �Print Ring			�\n");
	printf("�2  �Add element		�\n");
	printf("�3  �Get element		�\n");
	printf("�4  �Create Circle		�\n");
	printf("�5  �CountElements		�\n");
	printf("�������������������������������ͼ\n");

	while (!exit)
	{

		key = _getch();
		switch (key)
		{
		case 27:
			printf("Exit.\n");
			exit = true;
			break;

		case '1':
			cb.print();
		break;

		case '2':
		{
			int n = rand() % 100;
			printf("Adding %i\n", n);
			cb.put(n);
			break;
		}

		case '3':
		{
			int *n = cb.get();
			if(n != NULL) printf("Get %i\n", *n);
			else printf("There is nothing to delete.\n");
			delete(n);
			break;
		}
			
		case '4':
		{
			int n;
			printf("Input number of ring: ");
			scanf("%i", &n);
			cb = CircQueue(n);
			break;
		}

		case '5':
		{
			//if(cb.getFull() == true) printf("Size of ring: %i.\nAnd it is full.\n", cb.size());
			//else printf("Size of ring: %i.\nAnd it isn't full.\n", cb.size());
			printf("Size of ring: %i.\n", cb.size());
			break;
		}

		default:
			printf("Wrong symbol\n");
			break;
		}
	}
	return 0;
}