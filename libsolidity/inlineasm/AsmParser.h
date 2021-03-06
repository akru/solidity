/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @author Christian <c@ethdev.com>
 * @date 2016
 * Solidity inline assembly parser.
 */

#pragma once

#include <memory>
#include <vector>
#include <libsolidity/inlineasm/AsmData.h>
#include <libsolidity/parsing/ParserBase.h>

namespace dev
{
namespace solidity
{
namespace assembly
{

class Parser: public ParserBase
{
public:
	Parser(ErrorList& _errors): ParserBase(_errors) {}

	/// Parses an inline assembly block starting with `{` and ending with `}`.
	/// @returns an empty shared pointer on error.
	std::shared_ptr<Block> parse(std::shared_ptr<Scanner> const& _scanner);

protected:
	Block parseBlock();
	Statement parseStatement();
	/// Parses a functional expression that has to push exactly one stack element
	Statement parseExpression();
	Statement parseElementaryOperation(bool _onlySinglePusher = false);
	VariableDeclaration parseVariableDeclaration();
	FunctionalInstruction parseFunctionalInstruction(Statement const& _instruction);
};

}
}
}
