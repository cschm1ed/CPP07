/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:00:19 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 16:00:19 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMP_HPP
#define COMP_HPP

template<typename T>
void swap(T &a, T &b) {
	T tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T min(T a, T b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T max(T a, T b) {
	if (a > b)
		return a;
	return b;
}

#endif
