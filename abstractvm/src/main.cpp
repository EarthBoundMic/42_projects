// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/05/01 14:16:47 by mkass             #+#    #+#             //
//   Updated: 2019/05/01 14:16:49 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Operands.hpp"
#include "AbstractVM.hpp"
#include "Parser.hpp"

void	avmIntro(void)
{
	std::cout << "Welcome to AbstractVM, the virtual machine for basic assembly language!\n";
	std::cout << "\nTo use this AbstractVM, you input commands to perform simple tasks.\n";
	std::cout << "Here are the following commands you can input; remember, syntax is important!\n";
	std::cout << "\n{push}: This inserts an item to the top of the stack.\n";
	std::cout << "\n{pop}: This removes the topmost item of the stack.\n";
	std::cout << "\n{print}: This prints the top of the stack into an ASCII character.  Only works with type int8.\n";
	std::cout << "\n{assert}: This lets you know if the top item of the stack is the type and number you are expecting.\n";
	std::cout << "\n{dump}: This prints all the numbers in the stack, not losing the order they were inserted in.\n";
	std::cout << "\n{add}/{sub}/{mul}/{div}/{mod}: These perform their associated operations; {add} for addition, {sub} for subtraction, {mul} for multiplication, {div} for division, and {mod} for modulo.\n";
	std::cout << "\n{exit}: Required to properly quit AbstractVM\n";
	std::cout << "\n{;;}: The command to actually quit AbstractVM.  Must insert {exit} first though.  Only applicable to standard input.\n";
	std::cout << "\nThe following only applies to {push} and {assert}:\n";
	std::cout << "\nTo properly {push} and {assert}, you must also apply the type and number in a specific manner.  For example:\n\npush int8(0)\nassert int8(0)\n";
	std::cout << "\nThese are the types used: [int8], [int16], [int32], [float], [double].\n";
	std::cout << "\nWhen predicting what to {assert}, the types go by a precision-based hierarchy:\n[int8] < [int16] < [int32] < [float] < [double]\n";
	std::cout << "What this means is if you're using an operator for different types, the higher type is used for final calculation.\n";
	std::cout << "\nHere's an example code:\npush int32(34)\npush int8(56)\nprint\nadd\nassert int32(90)\ndump\npop\nexit\n";
	std::cout << "\nHave fun with AbstractVM!\n\n";
}

int		main(int ac, char *av[])
{
	if (ac == 1)
	{
		avmIntro();
		Parser();
	}
	else if (ac == 2)
		Parser(std::string(av[1]));
	else
		std::cerr << "Error: Too many inputs\nAn error has occured inside program standard input. Only have between zero and one parameters\n";
	return (0);
}
