#ifndef _LIST_CPP_
#define _LIST_CPP_

#include <iostream>

#include "list.hpp"

ListNode* createList(std::vector<int> &values) {
	if (values.size() == 0)
		return nullptr;
	ListNode* head = new ListNode();
	head->val = values[0];
	head->next = nullptr;
	ListNode* aux = head;

	for (int i = 1, ie = values.size(); i != ie; i++) {
		aux->next = new ListNode();
		aux = aux->next;
		aux->val = values[i];
		aux->next = nullptr;
	}
	return head;
}

void deleteList(ListNode* list) {
	ListNode* toBeDeleted = list;
	while(list != nullptr) {
		list = list->next;
		delete(toBeDeleted);
		toBeDeleted = list;
	}
	if (toBeDeleted == nullptr) {
		delete(toBeDeleted);
	}
}

void printList(ListNode* list) {
	std::cout << "[";
	while(list != nullptr) {
		std::cout << list->val;
		list = list->next;
		if (list != nullptr) {
			std::cout << ",";
		}
	}
	std::cout << "]";
}

#endif
