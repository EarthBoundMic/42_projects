// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exceptions.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/02/09 16:00:37 by mkass             #+#    #+#             //
//   Updated: 2019/02/09 16:00:38 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
# include <exception>

class AbstractVMException : public std::exception
{
public:
	AbstractVMException();
	AbstractVMException(AbstractVMException const&);
	~AbstractVMException() throw();

	AbstractVMException& operator=(AbstractVMException const&);

	virtual const char* what() const throw();
};

class OverflowException : public AbstractVMException
{
public:
	OverflowException();
	OverflowException(OverflowException const&);
	~OverflowException() throw();

	OverflowException& operator=(OverflowException const&);

	virtual const char* what() const throw();
};

class UnderflowException : public AbstractVMException
{
public:
	UnderflowException();
	UnderflowException(UnderflowException const&);
	~UnderflowException() throw();

	UnderflowException& operator=(UnderflowException const&);

	virtual const char* what() const throw();
};

void	flowThrow(std::string nbr, long long limit, size_t count);
void	flowThrow(std::string nbr, long double limit, size_t count);

#endif
