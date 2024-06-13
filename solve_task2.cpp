#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int ElementType;
typedef struct tagNode {
	ElementType Data;
	struct tagNode* nextNode;
}Node;

Node* createNode(ElementType newData) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->Data = newData;
	newNode->nextNode = NULL;
	return newNode;
}

void appendNode(Node** head, Node* newNode) {
	if ((*head) == NULL) {
		*head = newNode;
	}
	else {
		Node* tail = (*head);
		while (tail->nextNode != NULL) {
			tail = tail->nextNode;
		}
		tail->nextNode = newNode;
	}
}

void printList(Node* head, int index) {
	Node* tail = head;
	printf("[%d] : ", index);
	while (tail != NULL) {
		printf("%d ", tail->Data);
		tail = tail->nextNode;
	}
	printf("\n");
}

void delNode(Node** head, int n) {
	Node* now = (*head);
	Node* prev = NULL;
	int flag = 0;
	if ((*head) == NULL) {
		printf("no delete\n");
		return;
	}
	if ((*head)->Data == n) {
		*head = (*head)->nextNode;
		free(now);
		return;
	}
	prev = now;
	now = now->nextNode;
	while (now != NULL) {
		if (now->Data == n) {
			prev->nextNode = now->nextNode;
			free(now);
			flag = 1;
			break;
		}
		prev = now;
		now = now->nextNode;
	}
	if (flag == 0) {
		printf("no delete\n");
	}
}

void insertAfter(Node* current, Node* newnode) {
	newnode->nextNode = current->nextNode;
	current->nextNode = newnode;
}

void orderInsert(Node** head, int n) {
	Node* newNode = createNode(n);

	if (*head == NULL || n < (*head)->Data) {
		newNode->nextNode = *head;
		*head = newNode;
	}
	else {
		Node* now = *head;
		while (now->nextNode != NULL && now->nextNode->Data < n) {
			now = now->nextNode;
		}
		insertAfter(now, newNode);
	}
}

void orderInsertNoDuple(Node** head, int data) {
	int Duple = 0;

	Node* temp = *head;
	while (temp != NULL) {
		if (temp->Data == data) {
			Duple = 1;
			break;
		}
		temp = temp->nextNode;
	}
	if (Duple == 0) {
		orderInsert(head, data);
	}
}

int main() {
	Node* buketlist[10] = { NULL };
	int number;
	while (true) {
		scanf("%d", &number);
		if (number == 0) break;
		int listnum = number % 10;
		if (buketlist[listnum] == NULL) buketlist[listnum] = createNode(number);
		else if (number < 0) delNode(&buketlist[-listnum], -number);
		else if (number > 0) {
			orderInsertNoDuple(&buketlist[listnum], number);
		}
	}

	for (int i = 0; i < 10; i++) printList(buketlist[i], i);

	return 0;
}