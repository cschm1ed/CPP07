/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:21:44 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 16:21:44 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template<typename T>
void print(const T &arg) {
	std::cout << arg << "\n";
}

template<typename P, typename F>
void iter(P *aptr, int len, F fptr) {
	for (int i = 0; i < len; i++) {
		fptr(aptr[i]);
	}
}

#endif
