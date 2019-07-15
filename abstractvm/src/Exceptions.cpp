// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exceptions.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/02/09 16:00:52 by mkass             #+#    #+#             //
//   Updated: 2019/02/09 16:00:53 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exceptions.hpp"

AbstractVMException::AbstractVMException(void)
{
	return ;
}

AbstractVMException::AbstractVMException(AbstractVMException const&)
{
	return ;
}

AbstractVMException::~AbstractVMException(void) throw()
{
	return ;
}

AbstractVMException& AbstractVMException::operator=(AbstractVMException const&)
{
	return (*this);
}

const char* AbstractVMException::what() const throw()
{
	return ("AbstractVMException");
}

OverflowException::OverflowException(void)
{
	return ;
}

OverflowException::OverflowException(OverflowException const&)
{
	return ;
}

OverflowException::~OverflowException(void) throw()
{
	return ;
}

OverflowException& OverflowException::operator=(OverflowException const&)
{
	return (*this);
}

const char* OverflowException::what() const throw()
{
	return ("Error: A number is overflowing");
}

UnderflowException::UnderflowException(void)
{
	return ;
}

UnderflowException::UnderflowException(UnderflowException const&)
{
	return ;
}

UnderflowException::~UnderflowException(void) throw()
{
	return ;
}

UnderflowException& UnderflowException::operator=(UnderflowException const&)
{
	return (*this);
}

const char* UnderflowException::what() const throw()
{
	return ("Error: A number is underflowing");
}

void	flowThrow(std::string nbr, long double limit, size_t count)
{
	try
	{
		if (nbr[0] == '-' && (nbr.size() > count || stold(nbr) < -limit))
			throw UnderflowException();
		if (nbr[0] != '-' && (nbr.size() > count - 1 || stold(nbr) > limit))
			throw OverflowException();
	}
	catch (OverflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
	catch (UnderflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
}

void	flowThrow(std::string nbr, long long limit, size_t count)
{
	try
	{
		if (nbr[0] == '-' && (nbr.size() > count || stoll(nbr) < -limit))
			throw UnderflowException();
		if (nbr[0] != '-' && (nbr.size() > count - 1 || stoll(nbr) > limit))
			throw OverflowException();
	}
	catch (OverflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
	catch (UnderflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
}
