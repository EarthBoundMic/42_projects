// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/27 13:19:59 by mkass             #+#    #+#             //
//   Updated: 2019/04/27 13:20:00 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
# define PARSER_HPP

# include <queue>
# include <map>
# include <fstream>
# include <cctype>
# include "AbstractVM.hpp"

// # define NEXTCHR(a) (cmd[a] == ' ' || cmd[a] == '\t' || cmd[a] == '\n' || cmd[a] == ';' || cmd[a] == '\0')
# define NEXTCHR(a) (a == ' ' || a == '\t' || a == '\n' || a == ';' || a == '\0')
// # define CHKTYPE(a) (a == 'i' || a == 'f' || a == 'd')
# define CHKTYPE(a) (!a.compare(0, 4, "int8") || !a.compare(0, 5, "int16") || !a.compare(0, 5, "int32") || !a.compare(0, 5, "float") || !a.compare(0, 6, "double"))

typedef struct s_command t_cmd;

class Parser
{
private:
	bool								_exited;
	std::queue<struct s_command>		_queue;
	AbstractVM							_letsDoThis;
	std::map<std::string, eCommand>		_command;
	std::map<std::string, eOperandType>	_operand;

	void	_mapInit(void);

	t_cmd	_generateToken(std::string cmd);
	void	_cmdPushAssert(t_cmd *ret, std::string rest);
	void	_commentCheck(std::string cmd);
	void	_sizeCheck(std::string nbr, size_t size);

	void	_commandCheck(std::string cmd, eCommand ref);
	void	_typeCheck(std::string type, eCommand ref);
	void	_numberCheck(std::string nbr);

	class _BadFileException : public AbstractVMException
	{
	public:
		_BadFileException();
		_BadFileException(_BadFileException const& src);
		~_BadFileException() throw();

		_BadFileException& operator=(_BadFileException const& rhs);

		virtual const char* what() const throw();
	};

	class _InstructionException : public AbstractVMException
	{
	public:
		_InstructionException();
		_InstructionException(_InstructionException const&);
		~_InstructionException() throw();

		_InstructionException& operator=(_InstructionException const&);

		virtual const char* what() const throw();
	};

	class _OverflowException : public AbstractVMException
	{
	public:
		_OverflowException();
		_OverflowException(_OverflowException const&);
		~_OverflowException() throw();

		_OverflowException& operator=(_OverflowException const&);

		virtual const char* what() const throw();
	};

	class _UnderflowException : public AbstractVMException
	{
	public:
		_UnderflowException();
		_UnderflowException(_UnderflowException const&);
		~_UnderflowException() throw();

		_UnderflowException& operator=(_UnderflowException const&);

		virtual const char* what() const throw();
	};

	class _NoExitException : public AbstractVMException
	{
	public:
		_NoExitException();
		_NoExitException(_NoExitException const&);
		~_NoExitException() throw();

		_NoExitException& operator=(_NoExitException const&);

		virtual const char* what() const throw();
	};

	class _FilenameException : public AbstractVMException
	{
	public:
		_FilenameException();
		_FilenameException(_FilenameException const&);
		~_FilenameException() throw();

		_FilenameException& operator=(_FilenameException const&);

		virtual const char* what() const throw();
	};


public:
	Parser(void);
	Parser(std::string file);
	Parser(Parser const&);
	~Parser(void);

	Parser& operator=(Parser const&);
};

#endif
