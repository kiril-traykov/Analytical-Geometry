#pragma once
#include <exception>

class VectorLenghtException : public std::exception {

	const char * what() const throw();

};
