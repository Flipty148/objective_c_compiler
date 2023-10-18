#include "user_functions.h"
int id = 0;

//---------- program ----------

Program_node* createProgramNode(Statement_list_node *Statements, Class_statement_list_node *ClassStatements)
{
	Program_node *res = new Program_node;
    res->id = id++;
    res->Statements = Statements;
    res->ClassStatements = ClassStatements;
    return res;
}
