#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int n) : val(n), next(nullptr) {}
	ListNode(int n, ListNode *next);
};

ListNode* createList(std::vector<int> &values);

void deleteList(ListNode* list);

void printList(ListNode* list);

#endif
