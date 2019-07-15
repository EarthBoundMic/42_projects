// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/26 18:22:58 by mkass             #+#    #+#             //
//   Updated: 2019/04/26 18:22:59 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AbstractVM.hpp"

AbstractVM::AbstractVM(void)
{
	_select[Epush]		= _push;
	_select[Epop]		= _pop;
	_select[Eprint]		= _print;
	_select[Edump]		= _dump;
	_select[Eassert]	= _assert;
	_select[Eadd]		= _math;
	_select[Esub]		= _math;
	_select[Emul]		= _math;
	_select[Ediv]		= _math;
	_select[Emod]		= _math;
	return ;
}

AbstractVM::AbstractVM(AbstractVM const&)
{
	return ;
}

AbstractVM::~AbstractVM(void)
{
	IOperand *tmp;

	while (!_stack.empty())
	{
		tmp = _stack.front();
		_stack.pop_front();
		delete tmp;
	}
	return ;
}

AbstractVM& AbstractVM::operator=(AbstractVM const&)
{
	return (*this);
}

unsigned int AbstractVM::_size = 0;

std::forward_list<IOperand*> AbstractVM::_stack;

cmd_select AbstractVM::_select[11];

Operand AbstractVM::_operand;

void		AbstractVM::commandInit(struct s_command cmd)
{
	if (cmd.command == Estop || cmd.command == Eexit)
		return ;
	try
	{
		_select[cmd.command](cmd);
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside AbstractVM::commandInit";
		throw AbstractVMException();
	}
}

void		AbstractVM::_push(struct s_command cmd)
{
	try
	{
		_stack.push_front(const_cast<IOperand*>(_operand.createOperand(cmd.type, cmd.snbr)));
		_size++;
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside AbstractVM::_push";
		throw AbstractVMException();
	}
}

void		AbstractVM::_pop(struct s_command)
{
	IOperand *tmp;

	try
	{
		if (!_size)
			throw _PopException();
	}
	catch (_PopException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside AbstractVM::_pop";
		throw AbstractVMException();
	}
	tmp = _stack.front();
	_stack.pop_front();
	_size--;
	delete tmp;
}

void		AbstractVM::_dump(struct s_command)
{
	std::forward_list<IOperand*> tmp = _stack;

	while (!tmp.empty())
	{
		std::cout << tmp.front()->toString() << std::endl;
		tmp.pop_front();
	}
}

void		AbstractVM::_assert(struct s_command cmd)
{
	long long	intref;
	long double	fltref;

	try
	{
		if (cmd.type < EFloat)
		{
			if (cmd.type == EInt8)
				flowThrow(cmd.snbr, (long long)MSCHR, 4);
			else if (cmd.type == EInt16)
				flowThrow(cmd.snbr, (long long)MSSHT, 6);
			else if (cmd.type == EInt32)
				flowThrow(cmd.snbr, (long long)MSINT, 11);
			intref = stoll(cmd.snbr);
			if (_stack.empty() || stoll(_stack.front()->toString()) != intref ||
				_stack.front()->getType() != cmd.type)
				throw _AssertException();
		}
		else
		{
			if (cmd.type == EFloat)
				flowThrow(cmd.snbr, (long double)MFLOT, 40);
			if (cmd.type == EDouble)
			{
				flowThrow(cmd.snbr, (long double)MDBLE, 310);
			}
			fltref = stold(cmd.snbr);
			if (stold(_stack.front()->toString()) != fltref)
				throw _AssertException();
		}
	}
	catch (_AssertException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside AbstractVM::_assert";
		throw AbstractVMException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside AbstractVM::_assert";
		throw AbstractVMException();
	}
}

void		AbstractVM::_math(struct s_command cmd)
{
	IOperand	*res;
	IOperand	*iMath[2];

	try
	{
		if (_size < 2)
			throw _OperatorException();
	}
	catch (_OperatorException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside AbstractVM::_math";
		throw AbstractVMException();
	}
	iMath[1] = _stack.front();
	_stack.pop_front();
	iMath[0] = _stack.front();
	_stack.pop_front();
	try
	{
		if (cmd.command == Eadd)
			res = const_cast<IOperand*>(*iMath[0] + *iMath[1]);
		else if (cmd.command == Esub)
			res = const_cast<IOperand*>(*iMath[0] - *iMath[1]);
		else if (cmd.command == Emul)
			res = const_cast<IOperand*>(*iMath[0] * *iMath[1]);
		else if (cmd.command == Ediv)
			res = const_cast<IOperand*>(*iMath[0] / *iMath[1]);
		else if (cmd.command == Emod)
			res = const_cast<IOperand*>(*iMath[0] % *iMath[1]);
	}
	catch (AbstractVMException&)
	{
		_stack.push_front(iMath[0]);
		_stack.push_front(iMath[1]);
		std::cerr << "; Inside AbstractVM::_math";
		throw AbstractVMException();
	}
	_stack.push_front(res);
	_size--;
	delete iMath[0];
	delete iMath[1];
}

void		AbstractVM::_print(struct s_command)
{
	try
	{
		if (_stack.empty() || _stack.front()->getType() != EInt8)
			throw _AssertException();
	}
	catch (_AssertException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside AbstractVM::_print";
		throw AbstractVMException();
	}
	std::cout << (char)stoi(_stack.front()->toString()) << std::endl;
}

AbstractVM::_PopException::_PopException(void)
{
	return ;
}

AbstractVM::_PopException::_PopException(_PopException const&)
{
	return ;
}

AbstractVM::_PopException::~_PopException(void) throw()
{
	return ;
}

AbstractVM::_PopException& AbstractVM::_PopException::operator=(_PopException const&)
{
	return (*this);
}

const char* AbstractVM::_PopException::what() const throw()
{
	return ("Error: No number to pop");
}

AbstractVM::_AssertException::_AssertException(void)
{
	return ;
}

AbstractVM::_AssertException::_AssertException(_AssertException const&)
{
	return ;
}

AbstractVM::_AssertException::~_AssertException(void) throw()
{
	return ;
}

AbstractVM::_AssertException& AbstractVM::_AssertException::operator=(_AssertException const&)
{
	return (*this);
}

const char* AbstractVM::_AssertException::what() const throw()
{
	return ("Error: Assert failed");
}

AbstractVM::_OperatorException::_OperatorException(void)
{
	return ;
}

AbstractVM::_OperatorException::_OperatorException(_OperatorException const&)
{
	return ;
}

AbstractVM::_OperatorException::~_OperatorException(void) throw()
{
	return ;
}

AbstractVM::_OperatorException& AbstractVM::_OperatorException::operator=(_OperatorException const&)
{
	return (*this);
}

const char* AbstractVM::_OperatorException::what() const throw()
{
	return ("Error: Not enough numbers to perform instruction");
}
