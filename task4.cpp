#include<iostream>
using namespace std;
//printnode, insert Àç±ÍÇÔ¼ö »ç¿ë
typedef int ElementType;
typedef struct tagNode {
	ElementType Data;
	struct tagNode* leftNode;
	struct tagNode* rightNode;
}Node;

Node* createNode(ElementType newData) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->Data = newData;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

void insert(Node* head, int n) {
	if (head->Data > n) {
		if (head->leftNode == NULL) head->leftNode = createNode(n);
		else insert(head->leftNode, n);
	}
	if (head->Data < n) {
		if (head->rightNode == NULL) head->rightNode = createNode(n);
		else insert(head->rightNode, n);
	}
}

void printNode(Node* head) {
	if (head != NULL) {
		printNode(head->leftNode);
		cout << head->Data << " ";
		printNode(head->rightNode);
	}
}

void maximum(Node* head) {
	if (head->rightNode == NULL) cout << head->Data << endl;
	else maximum(head->rightNode);
}

void minimum(Node* head) {
	if (head->leftNode == NULL) cout << head->Data << endl;
	else minimum(head->leftNode);
}

int main() {
	Node* root = NULL;
	int n;
	while (1) {
		cin >> n;
		if (n <= 0) break;
		else {
			if (root == NULL) root = createNode(n);
			else insert(root, n);
		}
	}
	printNode(root);
	cout << endl << "ÃÖ¼Ú°ª: ";
	minimum(root);
	cout << "ÃÖ´ñ°ª: ";
	maximum(root);
	return 0;
}