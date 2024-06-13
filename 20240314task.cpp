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

//1번째 과제
void printList(Node* head) {
	Node* tail = head;
	while (tail->nextNode != NULL) {
		printf("%d ", tail->Data);
		tail = tail->nextNode;
	}
	printf("%d\n", tail->Data);
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

int main() {
	int n;
	Node* head = NULL;
	Node* newNode = NULL;
	Node* now, * next;

	newNode = createNode(8);
	appendNode(&head, newNode);
	newNode = createNode(12);
	appendNode(&head, newNode);
	newNode = createNode(24);
	appendNode(&head, newNode);
	newNode = createNode(87);
	appendNode(&head, newNode);
	printList(head);

	delNode(&head, 12);
	printList(head);
	orderInsert(&head, 50);
	printList(head);
}