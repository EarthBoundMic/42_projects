// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/02/09 13:23:32 by mkass             #+#    #+#             //
//   Updated: 2019/02/09 13:23:33 by mkass            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <string>

enum		eOperandType
{
	NoType,
	EInt8,
	EInt16,
	EInt32,
	EFloat,
	EDouble
};

class IOperand
{
public:
	virtual ~IOperand( void ) {}

	virtual IOperand const*	operator+(IOperand const& rhs) const = 0; // Sum
	virtual IOperand const*	operator-(IOperand const& rhs) const = 0; // Difference
	virtual IOperand const*	operator*(IOperand const& rhs) const = 0; // Product
	virtual IOperand const*	operator/(IOperand const& rhs) const = 0; // Quotient
	virtual IOperand const*	operator%(IOperand const& rhs) const = 0; // Modulo

	virtual int					getPrecision(void) const = 0; // Precision of the type of the instance
	virtual eOperandType		getType(void) const = 0; // Type of the instance
	virtual std::string const&	toString(void) const = 0; // String representation of the instance
};

#endif
