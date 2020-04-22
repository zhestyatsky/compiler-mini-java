#pragma once

#include <memory>
#include <vector>

#include <ast_node.hpp>
#include <identifier.hpp>
#include <statements.hpp>
#include <types.hpp>
#include <var_declaration.hpp>

class MethodDeclaration : public ASTNode {
public:
    MethodDeclaration(TypePtr return_type, IdentifierPtr name, VarDeclarations args,
                      VarDeclarations variables, Statements statements,
                      ExpressionPtr return_expression);
    void Accept(const Visitor& visitor) const override;

private:
    TypePtr return_type_;
    IdentifierPtr name_;
    VarDeclarations args_;
    VarDeclarations variables_;
    Statements statements_;
    ExpressionPtr return_expression_;
};

using MethodDeclarationPtr = std::shared_ptr<MethodDeclaration>;
using MethodDeclarations = std::vector<MethodDeclarationPtr>;