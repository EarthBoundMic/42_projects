// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/27 13:20:11 by mkass             #+#    #+#             //
//   Updated: 2019/04/27 13:20:12 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void) : _exited(false)
{
	std::string ref;

	_mapInit();
	std::cout << "⌨️ +💾=🕹 > ";
	getline(std::cin, ref);
	while (true)
	{
		try
		{
			ref.append("\n");
			if (!ref.compare(0, 2, ";;"))
			{
				 _commentCheck(ref.substr(2));
				std::cin.clear();
				ref.clear();
				break ;
			}
			_queue.push(_generateToken(ref));
		}
		catch (AbstractVMException&)
		{
			std::cerr << "; Inside Parser instance\n";
		}
		std::cout << "⌨️ +💾=🕹 > ";
		std::cin.clear();
		ref.clear();
		getline(std::cin, ref);
	}
	while (!_queue.empty())
	{
		try
		{
			if (_queue.front().command == Eexit)
				_exited = true;
			_letsDoThis.commandInit(_queue.front());
		}
		catch (AbstractVMException&)
		{
			std::cerr << "\nAn error has occured from your commands. Correct your errors and try again\n";
		}
		_queue.pop();
	}
	return ;
}

Parser::Parser(std::string file) : _exited(false)
{
	std::ifstream	data;
	std::string		cmd;
	t_cmd			parse;
	size_t			chk;

	_mapInit();
	try
	{
		if ((chk = file.find(".avm")) == file.npos || (chk && file[chk + 4] != 0))
			throw _FilenameException();
	}
	catch (AbstractVMException& e)
	{
		std::cerr << e.what() << std::endl;
		_exited = true;
		return ;
	}
	data.open(file);
	while (getline(data, cmd))
	{
		try
		{
			cmd.append("\n");
			if (NEXTCHR(cmd[0]))
				_commentCheck(cmd);
			else if ((parse = _generateToken(cmd)).command == Eexit)
			{
				_exited = true;
				break ;
			}
			else
				_letsDoThis.commandInit(parse);
		}
		catch (AbstractVMException&)
		{
			std::cerr << "\nAn error has occured from your commands.  Correct your errors and try again\n";
		}
	}
	data.close();
	return ;
}

Parser::Parser(Parser const&)
{
	return ;
}

Parser::~Parser(void)
{
	try
	{
		if (!_exited)
			throw _NoExitException();
	}
	catch (_NoExitException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Parser&	Parser::operator=(Parser const&)
{
	return (*this);
}

void	Parser::_mapInit(void)
{
	_command["push"] = Epush;
	_command["pop"] = Epop;
	_command["dump"] = Edump;
	_command["assert"] = Eassert;
	_command["add"] = Eadd;
	_command["sub"] = Esub;
	_command["mul"] = Emul;
	_command["div"] = Ediv;
	_command["mod"] = Emod;
	_command["print"] = Eprint;
	_command["exit"] = Eexit;
	_command[";;"] = Estop;
	_operand["int8"] = EInt8;
	_operand["int16"] = EInt16;
	_operand["int32"] = EInt32;
	_operand["float"] = EFloat;
	_operand["double"] = EDouble;
}

t_cmd	Parser::_generateToken(std::string cmd)
{
	t_cmd ret;

	ret.command = NoCmd;
	if (NEXTCHR(cmd[3]))
		ret.command = _command[cmd.substr(0, 3)];
	else if (NEXTCHR(cmd[4]))
		ret.command = _command[cmd.substr(0, 4)];
	else if (NEXTCHR(cmd[5]))
		ret.command = _command[cmd.substr(0, 5)];
	else if (NEXTCHR(cmd[6]))
		ret.command = _command[cmd.substr(0, 6)];
	_commandCheck(cmd, ret.command);
	ret.snbr = "";
	ret.type = NoType;
	try
	{
		if (ret.command == Epush)
			_cmdPushAssert(&ret, cmd.substr(5));
		else if (ret.command == Eassert)
			_cmdPushAssert(&ret, cmd.substr(7));
		if (ret.command == NoCmd)
			throw _InstructionException();
	}
	catch (_InstructionException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Parser::_generateToken";
		throw AbstractVMException();
	}
	catch (_BadFileException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Parser::_generateToken";
		throw AbstractVMException();
	}
	catch (AbstractVMException&)
	{
		std::cerr << "; Inside Parser::_generateToken";
		throw AbstractVMException();
	}
	return (ret);
}

void	Parser::_sizeCheck(std::string nbr, size_t size)
{
	try
	{
		if (nbr.size() > size)
		{
			if (nbr[0] == '-')
				throw _UnderflowException();
			else
				throw _OverflowException();
		}
	}
	catch (_OverflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
	catch (_UnderflowException& e)
	{
		std::cerr << e.what();
		throw AbstractVMException();
	}
}

void	Parser::_cmdPushAssert(t_cmd *ret, std::string rest)
{
	size_t		nbr = rest.find_first_of('(');
	size_t		end = rest.find_first_of(')');
	std::string	tmp;

	if (nbr == rest.npos || end == rest.npos)
		throw _BadFileException();
	tmp = rest.substr(0, end + 1).substr(nbr + 1);
	_typeCheck(rest, ret->command);
	ret->type = _operand[rest.substr(0, nbr)];
	if (ret->type == NoType)
		throw _InstructionException();
	_numberCheck(tmp);
		if (ret->type < EFloat)
			_sizeCheck(tmp, 12);
		else
			_sizeCheck(tmp, 318);
	ret->snbr = tmp.substr(0, tmp.find_first_of(')'));
}

void	Parser::_commandCheck(std::string cmd, eCommand ref)
{
	size_t		pos;
	size_t		i;

	if (NEXTCHR(cmd[0]))
	{
		_commentCheck(cmd);
		return ;
	}
	pos = cmd.find_first_of('\n');
	if (pos < 2)
		throw _BadFileException();
	if (ref > Eassert)
	{
		for (i = 2; !NEXTCHR(cmd[i]); i++);
		if (isspace(cmd[i]))
			_commentCheck(cmd.substr(i));
	}
}

void	Parser::_typeCheck(std::string type, eCommand ref)
{
	if (ref == Epush || ref == Eassert)
	{
		if (!isalpha(type[0]))
			throw _BadFileException();
		if (!CHKTYPE(type))
			throw _InstructionException();
	}
	if (NEXTCHR(type[0]))
		_commentCheck(type);
}

void	Parser::_numberCheck(std::string nbr)
{
	size_t		pos;
	bool		decimal = false;
	bool		neg = false;

	pos = nbr.find_first_of(')');
	if (pos == nbr.npos || nbr[0] == '.')
		throw _BadFileException();
	if (nbr[0] == '-')
		neg = true;
	for (size_t i = neg; i < pos; i++)
	{
		if (decimal && nbr[i] == '.')
			throw _BadFileException();
		if (nbr[i] == '.')
		{
			decimal = true;
			continue ;
		}
		if (!isdigit(nbr[i]))
			throw _BadFileException();
	}
}

void	Parser::_commentCheck(std::string rest)
{
	size_t	c = rest.find_first_of(';');

	try
	{
		if (c != rest.npos)
		{
			for (size_t i = 0; rest[i]; i++)
			{
				if (i == c)
					return ;
				if (rest[i] != ' ' && rest[i] != '\t')
					throw _BadFileException();
			}
		}
		else if (rest[0] != '\n')
			for (size_t i = 0; rest[i]; i++)
				if (!isspace(rest[i]))
					throw _BadFileException();
	}
	catch (_BadFileException& e)
	{
		std::cerr << e.what();
		std::cerr << "; Inside Parser::_commentCheck";
		throw AbstractVMException();
	}
}

Parser::_BadFileException::_BadFileException(void)
{
	return ;
}

Parser::_BadFileException::_BadFileException(_BadFileException const&)
{
	return ;
}

Parser::_BadFileException::~_BadFileException(void) throw()
{
	return ;
}

Parser::_BadFileException& Parser::_BadFileException::operator=(_BadFileException const&)
{
	return (*this);
}

const char* Parser::_BadFileException::what() const throw()
{
	return ("Error: Incorrect syntax");
}

Parser::_InstructionException::_InstructionException(void)
{
	return ;
}

Parser::_InstructionException::_InstructionException(_InstructionException const&)
{
	return ;
}

Parser::_InstructionException::~_InstructionException(void) throw()
{
	return ;
}

Parser::_InstructionException& Parser::_InstructionException::operator=(_InstructionException const&)
{
	return (*this);
}

const char* Parser::_InstructionException::what() const throw()
{
	return ("Error: Unknown instruction");
}

Parser::_OverflowException::_OverflowException(void)
{
	return ;
}

Parser::_OverflowException::_OverflowException(_OverflowException const&)
{
	return ;
}

Parser::_OverflowException::~_OverflowException(void) throw()
{
	return ;
}

Parser::_OverflowException& Parser::_OverflowException::operator=(_OverflowException const&)
{
	return (*this);
}

const char* Parser::_OverflowException::what() const throw()
{
	return ("Error: A number is overflowing");
}

Parser::_UnderflowException::_UnderflowException(void)
{
	return ;
}

Parser::_UnderflowException::_UnderflowException(_UnderflowException const&)
{
	return ;
}

Parser::_UnderflowException::~_UnderflowException(void) throw()
{
	return ;
}

Parser::_UnderflowException& Parser::_UnderflowException::operator=(_UnderflowException const&)
{
	return (*this);
}

const char* Parser::_UnderflowException::what() const throw()
{
	return ("Error: A number is underflowing");
}

Parser::_NoExitException::_NoExitException(void)
{
	return ;
}

Parser::_NoExitException::_NoExitException(_NoExitException const&)
{
	return ;
}

Parser::_NoExitException::~_NoExitException(void) throw()
{
	return ;
}

Parser::_NoExitException& Parser::_NoExitException::operator=(_NoExitException const&)
{
	return (*this);
}

const char* Parser::_NoExitException::what() const throw()
{
	return ("Error: No exit instruction");
}

Parser::_FilenameException::_FilenameException(void)
{
	return ;
}

Parser::_FilenameException::_FilenameException(_FilenameException const&)
{
	return ;
}

Parser::_FilenameException::~_FilenameException(void) throw()
{
	return ;
}

Parser::_FilenameException& Parser::_FilenameException::operator=(_FilenameException const&)
{
	return (*this);
}

const char* Parser::_FilenameException::what() const throw()
{
	return ("Error: Wrong filename.  Must have '.avm' suffix");
}
