#pragma once

#include <sstream>
#include <vector>

#include <symbol_table/class_info.hpp>
#include <symbol_table/method_info.hpp>
#include <symbol_table/symbol_table.hpp>
#include <symbol_table/var_info.hpp>
#include <visitors/visitor.hpp>

class SymbolTableBuilder : public Visitor {
public:
    explicit SymbolTableBuilder() = default;

    SymbolTablePtr Build(const Goal& goal);

public:
    void Visit(const Goal& goal) override;
    void Visit(const MainClass& main_class) override;
    void Visit(const ClassDeclaration& class_declaration) override;
    void Visit(const MethodDeclaration& method_declaration) override;
    void Visit(const VarDeclaration& var_declaration) override;

    void Visit(const IntType&) override;
    void Visit(const BoolType&) override;
    void Visit(const IntArrayType&) override;
    void Visit(const ClassType&) override;

    void Visit(const StatementList& statement_list) override;
    void Visit(const IfElseStatement& if_else_statement) override;
    void Visit(const WhileStatement& while_statement) override;
    void Visit(const PrintStatement& print_statement) override;
    void Visit(const AssignmentStatement& assignment_statement) override;
    void Visit(const ArrayAssignmentStatement& array_assignment_statement) override;

    void Visit(const AndExpression& and_expression) override;
    void Visit(const LessExpression& less_expression) override;
    void Visit(const AddExpression& add_expression) override;
    void Visit(const SubtractExpression& subtract_expression) override;
    void Visit(const MultiplyExpression& multiply_expression) override;

    void Visit(const ArrayExpression& array_expression) override;
    void Visit(const LengthExpression& length_expression) override;
    void Visit(const MethodCallExpression& method_call_expression) override;

    void Visit(const IntExpression& int_expression) override;
    void Visit(const BoolExpression& bool_expression) override;
    void Visit(const IdentifierExpression& identifier_expression) override;

    void Visit(const ThisExpression& this_expression) override;
    void Visit(const NewIntArrayExpression& new_int_array_expression) override;
    void Visit(const NewExpression& new_expression) override;

    void Visit(const NotExpression& not_expression) override;

    void Visit(const Identifier& identifier) override;

private:
    void PrintErrors() const;

private:
    SymbolTablePtr symbol_table_ = std::make_shared<SymbolTable>();

    ClassInfoPtr current_class_;
    MethodInfoPtr current_method_;

    std::string_view current_class_name_;
    TypePtr current_type_;
    bool is_valid_expr_ = true;

    std::ostringstream errors_;

    enum class EntityType { METHOD, VARIABLE, ENTITY_CLASS, ARGUMENT, NOTHING, CALLING_METHOD };
    enum class ErrorType {
        ALREADY_DECL,
        MISSED_DECL,
        WRONG_SIGN,
        BOOL_REQUIR,
        WRONG_TYPE_PRINT,
        TYPE_MISMATCH,
        NOT_EXIST,
        INT_ARRAY_REQUIR,
        INT_REQUIR,
        FROM_PRIM_TYPE
    };

private:
    void NoteError(const LocationPtr& location, EntityType entity_type, ErrorType error_type,
                   std::string name);
};
