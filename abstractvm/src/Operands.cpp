// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operands.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/02/09 15:47:51 by mkass             #+#    #+#             //
//   Updated: 2019/02/09 15:47:52 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Operands.hpp"

Operand::Operand(void)
{
	return ;
}

Operand::Operand(Operand const& src)
{
	(void)src;
	return ;
}

Operand::~Operand(void)
{
	return ;
}

Operand& Operand::operator=(Operand const& rhs)
{
	(void)rhs;
	return (*this);
}

IOperand const* Operand::createOperand(eOperandType type, std::string const& value) const
{
	(void)type;
	if (type == EInt8)
		return (createInt8(value));
	else if (type == EInt16)
		return (createInt16(value));
	else if (type == EInt32)
		return (createInt32(value));
	else if (type == EFloat)
		return (createFloat(value));
	else
		return (createDouble(value));
}

IOperand const* Operand::createInt8(std::string const& value) const
{
	IOperand *ret;

	try
	{
		ret = new Int8(value);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Operand::createInt8";
		throw AbstractVMException();
	}
	return (ret);
}

IOperand const* Operand::createInt16(std::string const& value) const
{
	IOperand *ret;

	try
	{
		ret = new Int16(value);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Operand::createInt16";
		throw AbstractVMException();
	}
	return (ret);
}

IOperand const* Operand::createInt32(std::string const& value) const
{
	IOperand *ret;

	try
	{
		ret = new Int32(value);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Operand::createInt32";
		throw AbstractVMException();
	}
	return (ret);
}

IOperand const* Operand::createFloat(std::string const& value) const
{
	IOperand *ret;

	try
	{
		ret = new Float(value);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Operand::createFloat";
		throw AbstractVMException();
	}
	return (ret);
}

IOperand const* Operand::createDouble(std::string const& value) const
{
	IOperand *ret;

	try
	{
		ret = new Double(value);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Operand::createDouble";
		throw AbstractVMException();
	}
	return (ret);
}

Int8::Int8(void) : _str("0"), _precision(EInt8)
{
	return ;
}

Int8::Int8(std::string str) : _str(str), _precision(EInt8)
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSCHR, 4);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int8";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int8::Int8(IOperand const& src) : _str(src.toString()), _precision(src.getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSCHR, 4);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int8";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int8::Int8(IOperand const* src) : _str(src->toString()), _precision(src->getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSCHR, 4);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int8";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int8::~Int8(void)
{
	return ;
}

IOperand& Int8::operator=(IOperand const& rhs)
{
	if (this != &rhs)
		_str = rhs.toString();
	return (*this);
}

IOperand const*	Int8::operator+(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) + stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) + stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) + stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) + stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator+";
		throw AbstractVMException();
	}
}

IOperand const*	Int8::operator-(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) - stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) - stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) - stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) - stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator-";
		throw AbstractVMException();
	}
}

IOperand const*	Int8::operator*(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) * stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) * stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) * stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) * stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator*";
		throw AbstractVMException();
	}
}

IOperand const*	Int8::operator/(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) / stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) / stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) / stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) / stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int8";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator/";
		throw AbstractVMException();
	}
}

IOperand const*	Int8::operator%(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((float)stof(_str), stof(rhs.toString())))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((double)stod(_str), stod(rhs.toString())))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) % stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) % stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int8";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator%";
		throw AbstractVMException();
	}
}

int					Int8::getPrecision(void) const
{
	return (static_cast<int>(_precision));
}

eOperandType		Int8::getType(void) const
{
	return (_precision);
}

std::string const&	Int8::toString(void) const
{
	return (_str);
}

Int8::_ZeroDivideException::_ZeroDivideException(void)
{
	return ;
}

Int8::_ZeroDivideException::_ZeroDivideException(_ZeroDivideException const&)
{
	return ;
}

Int8::_ZeroDivideException::~_ZeroDivideException(void) throw()
{
	return ;
}

Int8::_ZeroDivideException& Int8::_ZeroDivideException::operator=(_ZeroDivideException const&)
{
	return (*this);
}

const char* Int8::_ZeroDivideException::what() const throw()
{
	return ("Error: Dividing by zero");
}

Int16::Int16(void) : _str("0"), _precision(EInt16)
{
	return ;
}

Int16::Int16(std::string str) : _str(str), _precision(EInt16)
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSSHT, 6);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int16";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int16::Int16(IOperand const& src) : _str(src.toString()), _precision(src.getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSSHT, 6);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int16";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int16::Int16(IOperand const* src) : _str(src->toString()), _precision(src->getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSSHT, 6);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int16";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int16::~Int16(void)
{
	return ;
}

IOperand& Int16::operator=(IOperand const& rhs)
{
	if (this != &rhs)
		_str = rhs.toString();
	return (*this);
}

IOperand const*	Int16::operator+(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) + stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) + stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) + stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) + stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator+";
		throw AbstractVMException();
	}
}

IOperand const*	Int16::operator-(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) - stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) - stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) - stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) - stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator-";
		throw AbstractVMException();
	}
}

IOperand const*	Int16::operator*(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) * stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) * stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) * stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) * stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator*";
		throw AbstractVMException();
	}
}

IOperand const*	Int16::operator/(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) / stof(rhs.toString()))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) / stod(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) / stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) / stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int16";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator/";
		throw AbstractVMException();
	}
}

IOperand const*	Int16::operator%(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((float)stof(_str), stof(rhs.toString())))));
			else if (rhs.getType() == EDouble)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((double)stod(_str), stod(rhs.toString())))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stoll(_str) % stoll(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) % stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int16";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator%";
		throw AbstractVMException();
	}
}

int					Int16::getPrecision(void) const
{
	return (static_cast<int>(_precision));
}

eOperandType		Int16::getType(void) const
{
	return (_precision);
}

std::string const&	Int16::toString(void) const
{
	return (_str);
}

Int16::_ZeroDivideException::_ZeroDivideException(void)
{
	return ;
}

Int16::_ZeroDivideException::_ZeroDivideException(_ZeroDivideException const&)
{
	return ;
}

Int16::_ZeroDivideException::~_ZeroDivideException(void) throw()
{
	return ;
}

Int16::_ZeroDivideException& Int16::_ZeroDivideException::operator=(_ZeroDivideException const&)
{
	return (*this);
}

const char* Int16::_ZeroDivideException::what() const throw()
{
	return ("Error: Dividing by zero");
}

Int32::Int32(void) : _str("0"), _precision(EInt32)
{
	return ;
}

Int32::Int32(std::string str) : _str(str), _precision(EInt32)
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSINT, 11);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int32";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int32::Int32(IOperand const& src) : _str(src.toString()), _precision(src.getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSINT, 11);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int32";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int32::Int32(IOperand const* src) : _str(src->toString()), _precision(src->getType())
{
	long long nbr;

	try
	{
		flowThrow(_str, (long long)MSINT, 11);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Int32";
		throw AbstractVMException();
	}
	nbr = stoll(_str);
	_str = std::to_string(nbr);
	return ;
}

Int32::~Int32(void)
{
	return ;
}

IOperand& Int32::operator=(IOperand const& rhs)
{
	if (this != &rhs)
		_str = rhs.toString();
	return (*this);
}

IOperand const*	Int32::operator+(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) + stof(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) + stod(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) + stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator+";
		throw AbstractVMException();
	}
}

IOperand const*	Int32::operator-(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) - stof(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) - stod(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) - stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator-";
		throw AbstractVMException();
	}
}

IOperand const*	Int32::operator*(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) * stof(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) * stod(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) * stoll(rhs.toString()))));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator*";
		throw AbstractVMException();
	}
}

IOperand const*	Int32::operator/(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stof(_str) / stof(rhs.toString()))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(stod(_str) / stod(rhs.toString()))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) / stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int32";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator/";
		throw AbstractVMException();
	}
}

IOperand const*	Int32::operator%(IOperand const& rhs) const
{
	IOperand *ret;

	try
	{
		if (!stoll(rhs.toString()))
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			if (rhs.getType() == EFloat)
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((float)stof(_str), stof(rhs.toString())))));
			else
				ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), std::to_string(fmod((double)stod(_str), stod(rhs.toString())))));
		}
		else
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, std::to_string(stoll(_str) % stoll(rhs.toString()))));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Int32";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator%";
		throw AbstractVMException();
	}
}

int					Int32::getPrecision(void) const
{
	return (static_cast<int>(_precision));
}

eOperandType		Int32::getType(void) const
{
	return (_precision);
}

std::string const&	Int32::toString(void) const
{
	return (_str);
}

Int32::_ZeroDivideException::_ZeroDivideException(void)
{
	return ;
}

Int32::_ZeroDivideException::_ZeroDivideException(_ZeroDivideException const&)
{
	return ;
}

Int32::_ZeroDivideException::~_ZeroDivideException(void) throw()
{
	return ;
}

Int32::_ZeroDivideException& Int32::_ZeroDivideException::operator=(_ZeroDivideException const&)
{
	return (*this);
}

const char* Int32::_ZeroDivideException::what() const throw()
{
	return ("Error: Dividing by zero");
}

Float::Float(void) : _str("0.0"), _precision(EFloat)
{
	return ;
}

Float::Float(std::string str) : _str(str), _precision(EFloat)
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MFLOT, 40);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Float";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stof(_str);
	_str = stream.str();
	return ;
}

Float::Float(IOperand const& src) : _str(src.toString()), _precision(src.getType())
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MFLOT, 40);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Float";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stof(_str);
	_str = stream.str();
	return ;
}

Float::Float(IOperand const* src) : _str(src->toString()), _precision(src->getType())
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MFLOT, 40);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Float";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stof(_str);
	_str = stream.str();
	return ;
}

Float::~Float(void)
{
	return ;
}

IOperand& Float::operator=(IOperand const& rhs)
{
	if (this != &rhs)
		_str = rhs.toString();
	return (*this);
}

IOperand const*	Float::operator+(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			stream << std::fixed << std::setprecision(2) << stod(_str) + stod(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), stream.str()));
		}
		else
		{
			stream << std::fixed << std::setprecision(2) << stof(_str) + stof(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		}
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator+";
		throw AbstractVMException();
	}
}

IOperand const*	Float::operator-(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			stream << std::fixed << std::setprecision(2) << stod(_str) - stod(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), stream.str()));
		}
		else
		{
			stream << std::fixed << std::setprecision(2) << stof(_str) - stof(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		}
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator-";
		throw AbstractVMException();
	}
}

IOperand const*	Float::operator*(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (_precision < rhs.getPrecision())
		{
			stream << std::fixed << std::setprecision(2) << stod(_str) * stod(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), stream.str()));
		}
		else
		{
			stream << std::fixed << std::setprecision(2) << stof(_str) * stof(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		}
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator*";
		throw AbstractVMException();
	}
}

IOperand const*	Float::operator/(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (stof(rhs.toString()) == 0)
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			stream << std::fixed << std::setprecision(2) << stod(_str) / stod(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), stream.str()));
		}
		else
		{
			stream << std::fixed << std::setprecision(2) << stod(_str) / stof(rhs.toString());
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		}
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Float";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator/";
		throw AbstractVMException();
	}
}

IOperand const*	Float::operator%(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (stof(rhs.toString()) == 0)
			throw _ZeroDivideException();
		if (_precision < rhs.getPrecision())
		{
			stream << std::fixed << std::setprecision(2) << fmod((double)stod(_str), stod(rhs.toString()));
			ret = const_cast<IOperand*>(Operand().createOperand(rhs.getType(), stream.str()));
		}
		else
		{
			stream << std::fixed << std::setprecision(2) << fmod(stof(_str), stof(rhs.toString()));
			ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		}
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Float";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator%";
		throw AbstractVMException();
	}
}

int					Float::getPrecision(void) const
{
	return (static_cast<int>(_precision));
}

eOperandType		Float::getType(void) const
{
	return (_precision);
}

std::string const&	Float::toString(void) const
{
	return (_str);
}

Float::_ZeroDivideException::_ZeroDivideException(void)
{
	return ;
}

Float::_ZeroDivideException::_ZeroDivideException(_ZeroDivideException const&)
{
	return ;
}

Float::_ZeroDivideException::~_ZeroDivideException(void) throw()
{
	return ;
}

Float::_ZeroDivideException& Float::_ZeroDivideException::operator=(_ZeroDivideException const&)
{
	return (*this);
}

const char* Float::_ZeroDivideException::what() const throw()
{
	return ("Error: Dividing by zero");
}

Double::Double(void) : _str("0.0"), _precision(EDouble)
{
	return ;
}

Double::Double(std::string str) : _str(str), _precision(EDouble)
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MDBLE, 310);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Double";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stod(_str);
	_str = stream.str();
	return ;
}

Double::Double(IOperand const& src) : _str(src.toString()), _precision(src.getType())
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MDBLE, 310);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Double";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stod(_str);
	_str = stream.str();
	return ;
}

Double::Double(IOperand const* src) : _str(src->toString()), _precision(src->getType())
{
	std::stringstream stream;

	try
	{
		flowThrow(_str, (long double)MDBLE, 310);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Double";
		throw AbstractVMException();
	}
	stream << std::fixed << std::setprecision(2) << stod(_str);
	_str = stream.str();
	return ;
}

Double::~Double(void)
{
	return ;
}

IOperand& Double::operator=(IOperand const& rhs)
{
	if (this != &rhs)
		_str = rhs.toString();
	return (*this);
}

IOperand const*	Double::operator+(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		stream << std::fixed << std::setprecision(2) << stod(_str) + stod(rhs.toString());
		ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator+";
		throw AbstractVMException();
	}
}

IOperand const*	Double::operator-(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		stream << std::fixed << std::setprecision(2) << stod(_str) - stod(rhs.toString());
		ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator-";
		throw AbstractVMException();
	}
}

IOperand const*	Double::operator*(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		stream << std::fixed << std::setprecision(2) << stod(_str) * stod(rhs.toString());
		ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		return (ret);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator*";
		throw AbstractVMException();
	}
}

IOperand const*	Double::operator/(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{

		if (stod(rhs.toString()) == 0)
			throw _ZeroDivideException();
		stream << std::fixed << std::setprecision(2) << stod(_str) / stod(rhs.toString());
		ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Double";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator/";
		throw AbstractVMException();
	}
}

IOperand const*	Double::operator%(IOperand const& rhs) const
{
	IOperand *ret;
	std::stringstream stream;

	try
	{
		if (stod(rhs.toString()) == 0)
			throw _ZeroDivideException();
		stream << std::fixed << std::setprecision(2) << fmod(stod(_str), stod(rhs.toString()));
		ret = const_cast<IOperand*>(Operand().createOperand(_precision, stream.str()));
		return (ret);
	}
	catch (_ZeroDivideException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Double";
		throw _ZeroDivideException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside operator%";
		throw AbstractVMException();
	}
}

int					Double::getPrecision(void) const
{
	return (static_cast<int>(_precision));
}

eOperandType		Double::getType(void) const
{
	return (_precision);
}

std::string const&	Double::toString(void) const
{
	return (_str);
}

Double::_ZeroDivideException::_ZeroDivideException(void)
{
	return ;
}

Double::_ZeroDivideException::_ZeroDivideException(_ZeroDivideException const&)
{
	return ;
}

Double::_ZeroDivideException::~_ZeroDivideException(void) throw()
{
	return ;
}

Double::_ZeroDivideException& Double::_ZeroDivideException::operator=(_ZeroDivideException const&)
{
	return (*this);
}

const char* Double::_ZeroDivideException::what() const throw()
{
	return ("Error: Dividing by zero");
}
