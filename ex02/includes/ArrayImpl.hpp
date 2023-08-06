/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:02:33 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/06 11:23:13 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() {
	std::cout << BLUE"Array default constructor called\n"R;
	_array = new T[1];
	_size = 1;
	_array[0] = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	std::cout << BLUE"Array constructor called\n"R;
	_size = n;
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++) {
		_array[i] = T();
	}
}

template<typename T>
Array<T>::~Array() {
	std::cout << MAGENTA"Array default destructor called\n"R;
	delete[] _array;
}

template<typename T>
Array<T>::Array(Array const &other) {
	std::cout << YELLOW"Array copy constructor called\n"R;
	_size = other._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = other[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
	if (&rhs == this)
		return *this;
	_size = rhs._size;
	delete[] _array;
	_array = new T[rhs._size];
	for (int i = 0; i < _size; i++) {
		_array[i] = rhs[i];
	}
	return *this;
}

template<typename T>
T const &Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw Array<T>::AccessOutOfBoundsException();
	}
	return _array[index];
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw Array::AccessOutOfBoundsException();
	}
	return _array[index];
}

template<typename T>
unsigned int Array<T>::getSize() {
	return _size;
}

template<typename T>
const char *Array<T>::AccessOutOfBoundsException::what() const throw() {
	return RED"access out of memory bounds"R;
}
