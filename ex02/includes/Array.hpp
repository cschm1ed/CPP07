/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:02:33 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/05 18:02:38 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP07_ARRAY_HPP
#define CPP07_ARRAY_HPP

#include <iostream>
#include <colors.hpp>

template<typename T>
class Array {

public:
	Array();

	Array(unsigned int n);

	Array(Array const &other);

	~Array();

	Array &operator=(Array const &rhs);

	T &operator[](unsigned int index);

	T const &operator[](unsigned int index) const;

	unsigned int getSize();

	unsigned int size();

	class AccessOutOfBoundsException : public std::exception {
		const char *what() const _NOEXCEPT;
	};

private:
	T *_array;
	unsigned int _size;

};


#endif //CPP07_ARRAY_HPP
