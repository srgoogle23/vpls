#ifndef _SOLUCAO_CPP_
#define _SOLUCAO_CPP_

#include "solucao.hpp"


ListNode* Solution::juntaListas(std::vector<ListNode*> &lists)
{
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	ListNode* min = nullptr;
	int minIndex = -1;
	int i = 0;
	while (true) {
		min = nullptr;
		minIndex = -1;
		for (i = 0; i < lists.size(); i++) {
			if (lists[i] != nullptr) {
				if (min == nullptr) {
					min = lists[i];
					minIndex = i;
				} else if (min->val > lists[i]->val) {
					min = lists[i];
					minIndex = i;
				}
			}
		}
		if (min == nullptr) {
			break;
		}
		if (head == nullptr) {
			head = min;
			tail = min;
		} else {
			tail->next = min;
			tail = min;
		}
		lists[minIndex] = lists[minIndex]->next;
	}
	return head;
}

#endif