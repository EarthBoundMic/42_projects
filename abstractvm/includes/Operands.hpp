// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operands.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/02/09 13:28:35 by mkass             #+#    #+#             //
//   Updated: 2019/02/09 13:28:35 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERANDS_HPP
# define OPERANDS_HPP

# include <cmath>
# include <sstream>
# include <iomanip>
# include <limits>
# include "IOperand.hpp"
# include "Exceptions.hpp"

# define MSCHR std::numeric_limits<signed char>::max()
# define MSSHT std::numeric_limits<signed short>::max()
# define MSINT std::numeric_limits<signed int>::max()
# define MFLOT std::numeric_limits<float>::max()
# define MDBLE std::numeric_limits<double>::max()

class Operand
{
private:
	IOperand const* createInt8(std::string const& value) const;
	IOperand const* createInt16(std::string const& value) const;
	IOperand const* createInt32(std::string const& value) const;
	IOperand const* createFloat(std::string const& value) const;
	IOperand const* createDouble(std::string const& value) const;

public:
	Operand(void);
	Operand(Operand const& src);
	~Operand(void);
	Operand& operator=(Operand const& rhs);

	IOperand const* createOperand(eOperandType type, std::string const& value) const;
};

class Int8 : public IOperand
{
private:
	std::string _str;
	eOperandType const _precision;

	class _ZeroDivideException : public AbstractVMException
	{
	public:
		_ZeroDivideException();
		_ZeroDivideException(_ZeroDivideException const&);
		~_ZeroDivideException() throw();

		_ZeroDivideException& operator=(_ZeroDivideException const&);

		virtual const char* what() const throw();
	};

public:
	Int8(void);
	Int8(std::string nbr);
	Int8(IOperand const& src);
	Int8(IOperand const* src);
	virtual ~Int8(void);

	IOperand& operator=(IOperand const& rhs);
	virtual IOperand const	*operator+(IOperand const& rhs) const;
	virtual IOperand const	*operator-(IOperand const& rhs) const;
	virtual IOperand const	*operator*(IOperand const& rhs) const;
	virtual IOperand const	*operator/(IOperand const& rhs) const;
	virtual IOperand const	*operator%(IOperand const& rhs) const;

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;
	virtual std::string const&	toString(void) const;
};

class Int16 : public IOperand
{
private:
	std::string _str;
	eOperandType const _precision;

	class _ZeroDivideException : public AbstractVMException
	{
	public:
		_ZeroDivideException();
		_ZeroDivideException(_ZeroDivideException const&);
		~_ZeroDivideException() throw();

		_ZeroDivideException& operator=(_ZeroDivideException const&);

		virtual const char* what() const throw();
	};

public:
	Int16(void);
	Int16(std::string nbr);
	Int16(IOperand const& src);
	Int16(IOperand const* src);
	virtual ~Int16(void);

	IOperand& operator=(IOperand const& rhs);
	virtual IOperand const	*operator+(IOperand const& rhs) const;
	virtual IOperand const	*operator-(IOperand const& rhs) const;
	virtual IOperand const	*operator*(IOperand const& rhs) const;
	virtual IOperand const	*operator/(IOperand const& rhs) const;
	virtual IOperand const	*operator%(IOperand const& rhs) const;

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;
	virtual std::string const&	toString(void) const;
};

class Int32 : public IOperand
{
private:
	std::string _str;
	eOperandType const _precision;

	class _ZeroDivideException : public AbstractVMException
	{
	public:
		_ZeroDivideException();
		_ZeroDivideException(_ZeroDivideException const&);
		~_ZeroDivideException() throw();

		_ZeroDivideException& operator=(_ZeroDivideException const&);

		virtual const char* what() const throw();
	};

public:
	Int32(void);
	Int32(std::string nbr);
	Int32(IOperand const& src);
	Int32(IOperand const* src);
	virtual ~Int32(void);

	IOperand& operator=(IOperand const& rhs);
	virtual IOperand const	*operator+(IOperand const& rhs) const;
	virtual IOperand const	*operator-(IOperand const& rhs) const;
	virtual IOperand const	*operator*(IOperand const& rhs) const;
	virtual IOperand const	*operator/(IOperand const& rhs) const;
	virtual IOperand const	*operator%(IOperand const& rhs) const;

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;
	virtual std::string const&	toString(void) const;
};

class Float : public IOperand
{
private:
	std::string _str;
	eOperandType const _precision;

	class _ZeroDivideException : public AbstractVMException
	{
	public:
		_ZeroDivideException();
		_ZeroDivideException(_ZeroDivideException const&);
		~_ZeroDivideException() throw();

		_ZeroDivideException& operator=(_ZeroDivideException const&);

		virtual const char* what() const throw();
	};

public:
	Float(void);
	Float(std::string nbr);
	Float(IOperand const& src);
	Float(IOperand const* src);
	virtual ~Float(void);

	IOperand& operator=(IOperand const& rhs);
	virtual IOperand const	*operator+(IOperand const& rhs) const;
	virtual IOperand const	*operator-(IOperand const& rhs) const;
	virtual IOperand const	*operator*(IOperand const& rhs) const;
	virtual IOperand const	*operator/(IOperand const& rhs) const;
	virtual IOperand const	*operator%(IOperand const& rhs) const;

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;
	virtual std::string const&	toString(void) const;
};

class Double : public IOperand
{
private:
	std::string _str;
	eOperandType const _precision;

	class _ZeroDivideException : public AbstractVMException
	{
	public:
		_ZeroDivideException();
		_ZeroDivideException(_ZeroDivideException const&);
		~_ZeroDivideException() throw();

		_ZeroDivideException& operator=(_ZeroDivideException const&);

		virtual const char* what() const throw();
	};

public:
	Double(void);
	Double(std::string nbr);
	Double(IOperand const& src);
	Double(IOperand const* src);
	virtual ~Double(void);

	IOperand& operator=(IOperand const& rhs);
	virtual IOperand const	*operator+(IOperand const& rhs) const;
	virtual IOperand const	*operator-(IOperand const& rhs) const;
	virtual IOperand const	*operator*(IOperand const& rhs) const;
	virtual IOperand const	*operator/(IOperand const& rhs) const;
	virtual IOperand const	*operator%(IOperand const& rhs) const;

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;
	virtual std::string const&	toString(void) const;
};

#endif
