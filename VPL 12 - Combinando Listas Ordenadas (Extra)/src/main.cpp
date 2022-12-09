#include <iostream>

#include "list.hpp"
#include "utils.hpp"
#include "solucao.hpp"

int main(int argc, char *argv[]) {
	std::vector<ListNode*> listas = readInputLine();
	Solution sol;
	ListNode* list = sol.juntaListas(listas);
        printList(list);
	deleteList(list);	
	return 0;
}