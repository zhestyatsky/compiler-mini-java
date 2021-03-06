#pragma once

#include <deque>
#include <memory>

#include <ast/ast_node.hpp>
#include <ast/identifier.hpp>
#include <ast/statements.hpp>
#include <ast/types.hpp>
#include <ast/var_declaration.hpp>

class MethodDeclaration : public ASTNode {
public:
    MethodDeclaration(LocationPtr location, TypePtr return_type, IdentifierPtr method_name,
                      VarDeclarations args, VarDeclarations variables, Statements statements,
                      ExpressionPtr return_expression);
    void Accept(Visitor& visitor) const override;
    const TypePtr& GetReturnType() const;
    const IdentifierPtr& GetMethodName() const;
    const VarDeclarations& GetArgs() const;
    const VarDeclarations& GetVariables() const;
    const Statements& GetStatements() const;
    const ExpressionPtr& GetReturnExpression() const;

private:
    TypePtr return_type_;
    IdentifierPtr method_name_;
    VarDeclarations args_;
    VarDeclarations variables_;
    Statements statements_;
    ExpressionPtr return_expression_;
};

using MethodDeclarationPtr = std::shared_ptr<MethodDeclaration>;
using MethodDeclarations = std::deque<MethodDeclarationPtr>;
