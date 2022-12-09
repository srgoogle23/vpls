#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

#include "list.hpp"
#include "utils.hpp"

void replaceAll(std::string& str, std::string sub1, std::string sub2) {
	while (str.find(sub1) != std::string::npos) {
		std::size_t pos = str.find(sub1);
		str.replace(pos,sub1.size(),sub2);
	}
}

std::vector<ListNode*> readInputLine() {
	std::string str;
	std::cin >> str;
	
	replaceAll(str, "[[","");
	replaceAll(str, "]]","");
	replaceAll(str, "],[","\n");

        std::vector<std::string> lists;
	std::stringstream ss(str);

	while(ss.good()) {
		std::string substr;
		getline(ss, substr,'\n');
		lists.push_back(substr);
	}

	std::vector<ListNode*> listNodes;
	for (int i = 0, ie = lists.size(); i != ie; i++) {
		std::stringstream ssList(lists[i]);
		std::vector<int> elements;

		while(ssList.good()) {
			std::string substr;
			getline(ssList, substr,',');
			elements.push_back(std::stoi(substr));
		}
		
		// Assinatura da funcao
		//ListNode* createList(std::vector<int> &values);
		listNodes.push_back(createList(elements));
	}
	return listNodes;
	
}

#endif
