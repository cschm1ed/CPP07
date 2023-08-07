/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:21:24 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 16:21:24 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>
#include <colors.hpp>
#include <iostream>

void printStringToUpper(std::string const &str) {
	std::string newStr;

	for (size_t i = 0; i < str.size(); i++) {
		newStr += static_cast<char>(toupper(str[i]));
	}
	std::cout << newStr << "\n";
}

void printPlus10(int const x) {
	std::cout << x + 10 << "\n";
}

int main() {
	std::cout << "-----testing strings-----\n";

	std::string arr[] = {"hello", "world", "uwu"};
	void (*printPtrStr)(const std::string &) = ::print<std::string>;

	std::cout << BLUE << "before:\n";
	iter(arr, 3, printPtrStr);
	std::cout << MAGENTA << "after:\n";
	iter(arr, 3, printStringToUpper);

	std::cout << "------testing ints------\n";

	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << BLUE << "before: \n";
	void (*printPtrInt)(const int &) = ::print<int>;
	iter(intArr, 5, printPtrInt);
	std::cout << MAGENTA << "after:\n";
	iter(intArr, 5, printPlus10);
}
