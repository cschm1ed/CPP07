/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:15:09 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 17:15:09 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include "ArrayImpl.hpp"

#define MAX_VAL 750

int main(int, char **) {
	{

		std::cout << "----test dynamic and static allocation / test [] operator reading and assigning----\n";
		Array<int> numbers(MAX_VAL);
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		std::cout << "\n\n";

		//SCOPE
		std::cout << "----test copy constructor----\n";
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		std::cout << "\n\n";
		std::cout << "----test exceptions----\n";

		try {
			numbers[-2] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete[] mirror;//
		std::cout << "\n\n";
	}
	{
		Array<std::string> strArr(3);

		std::cout << "---test size function and exception---\n";
		std::cout << strArr.size();

		strArr[0] = "Hello World";
		strArr[1] = "42";
		strArr[2] = "Goodbye World";
		try {
			strArr[3] = "climate crisis";
		} catch (std::exception &e) {
			std::cerr << "an exception occured: " << e.what() << "\n";
		}
	}
}
