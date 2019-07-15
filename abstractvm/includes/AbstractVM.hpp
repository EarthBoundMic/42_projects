// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/26 18:22:40 by mkass             #+#    #+#             //
//   Updated: 2019/04/26 18:22:42 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <forward_list>
# include "Operands.hpp"

enum						eCommand
{
	NoCmd,
	Epush,
	Eassert,
	Epop,
	Eadd,
	Esub,
	Emul,
	Ediv,
	Emod,
	Edump,
	Eprint,
	Eexit,
	Estop
};

struct						s_command
{
	eCommand				command;
	eOperandType			type;
	std::string				snbr;
};

typedef void (*cmd_select)(struct s_command);

class AbstractVM
{
private:
	static unsigned int					_size;
	static std::forward_list<IOperand*>	_stack;
	static Operand						_operand;
	static cmd_select					_select[11];

	static void							_pop(struct s_command);
	static void							_dump(struct s_command);
	static void							_print(struct s_command);

	static void							_push(struct s_command cmd);
	static void							_assert(struct s_command cmd);
	static void							_math(struct s_command cmd);

	class _PopException : public AbstractVMException
	{
	public:
		_PopException();
		_PopException(_PopException const&);
		~_PopException() throw();

		_PopException& operator=(_PopException const&);

		virtual const char* what() const throw();
	};

	class _AssertException : public AbstractVMException
	{
	public:
		_AssertException();
		_AssertException(_AssertException const&);
		~_AssertException() throw();

		_AssertException& operator=(_AssertException const&);

		virtual const char* what() const throw();
	};

	class _OperatorException : public AbstractVMException
	{
	public:
		_OperatorException();
		_OperatorException(_OperatorException const&);
		~_OperatorException() throw();

		_OperatorException& operator=(_OperatorException const&);

		virtual const char* what() const throw();
	};

public:
	AbstractVM(void);
	AbstractVM(AbstractVM const&);
	~AbstractVM(void);

	AbstractVM&				operator=(AbstractVM const&);

	void					commandInit(struct s_command cmd);
};

#endif
