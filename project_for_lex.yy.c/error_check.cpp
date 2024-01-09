#include "tables.h"

void Expression_node::checkLvalueError()
{
	if (type == ASSIGNMENT_EXPRESSION_TYPE) {
		bool isIncorrectLvalue = Left->type != IDENTIFIER_EXPRESSION_TYPE;
		isIncorrectLvalue = isIncorrectLvalue && Left->type != SELF_EXPRESSION_TYPE;
		isIncorrectLvalue = isIncorrectLvalue && Left->type != ASSIGNMENT_EXPRESSION_TYPE;
		isIncorrectLvalue = isIncorrectLvalue && Left->type != ARROW_EXPRESSION_TYPE;
		isIncorrectLvalue = isIncorrectLvalue && Left->type != ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE;

		if (isIncorrectLvalue) {
			string msg = "Incorrect lvalue. Lvalue have '" + Left->getTypeName() + "' type";
			throw std::exception(msg.c_str());
		}
	}
}

string Expression_node::getTypeName()
{
	switch (type)
	{
	case IDENTIFIER_EXPRESSION_TYPE:
		return "identifier";
		break;
	case LITERAL_EXPRESSION_TYPE:
		return "literal";
		break;
	case NUMERIIC_CONSTANT_EXPRESSION_TYPE:
		return "numeric constant";
		break;
	case SELF_EXPRESSION_TYPE:
		return "self";
		break;
	case SUPER_EXPRESSION_TYPE:
		return "super";
		break;
	case MESSAGE_EXPRESSION_EXPRESSION_TYPE:
		return "message expression";
		break;
	case FUNCTION_CALL_EXPRESSION_TYPE:
		return "function call";
		break;
	case UMINUS_EXPRESSION_TYPE:
		return "unary minus";
		break;
	case UPLUS_EXPRESSION_TYPE:
		return "unary plus";
		break;
	case UAMPERSAND_EXPRESSION_TYPE:
		return "unary ampersand";
		break;
	case PLUS_EXPRESSION_TYPE:
		return "plus";
		break;
	case MINUS_EXPRESSION_TYPE:
		return "minus";
		break;
	case MUL_EXPRESSION_TYPE:
		return "multiplication";
		break;
	case DIV_EXPRESSION_TYPE:
		return "division";
		break;
	case EQUAL_EXPRESSION_TYPE:
		return "equal";
		break;
	case NOT_EQUAL_EXPRESSION_TYPE:
		return "not equal";
		break;
	case GREATER_EXPRESSION_TYPE:
		return "greater";
		break;
	case LESS_EXPRESSION_TYPE:
		return "less";
		break;
	case LESS_EQUAL_EXPRESSION_TYPE:
		return "less equal";
		break;
	case GREATER_EQUAL_EXPRESSION_TYPE:
		return "greater equal";
		break;
	case ASSIGNMENT_EXPRESSION_TYPE:
		return "assignment";
		break;
	case DOT_EXPRESSION_TYPE:
		return "dot";
		break;
	case ARROW_EXPRESSION_TYPE:
		return "arrow";
		break;
	case ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE:
		return "array element access";
		break;
	case ARRAY_ASSIGNMENT_EXPRESSION_TYPE:
		return "array assignment";
		break;
	case MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE:
		return "member access assignment";
		break;
	case CHAR_CAST:
		return "char cast";
		break;
	case INT_CAST:
		return "int cast";
		break;
	case CLASS_CAST:
		return "class cast";
		break;
	default:
		break;
	}
}

void For_statement_node::checkFastEnumerationTypes(LocalVariablesTable* locals)
{
	// Проверка итерирующей переменной
	if (locals->isContains(name)) { //Локальная переменная
		Type* type = locals->items[name]->type;
		if (type->ClassName == "") {
			string msg = "Variable in fast enumeration isn't an object. It has type '" + type->toString();
			throw new std::exception(msg.c_str());
		}
	}
	else { //Поле
		if (ClassesTable::items.count(locals->items["self"]->type->ClassName) != 0) {
			ClassesTableElement* selfClass = ClassesTable::items[locals->items["self"]->type->ClassName];
			if (selfClass->isContainsField(name)) {
				string descr;
				string className;
				FieldsTableElement* field = selfClass->getFieldForRef(name, &descr, &className);
				Type* type = field->type;
				if (type->ClassName == "") {
					string msg = "Variable in fast enumeration isn't an object. It has type '" + type->toString();
					throw new std::exception(msg.c_str());
				}
			}
			else {
				string msg = "Variable '" + string(name) + "' is undeclarated";
				throw new std::exception(msg.c_str());
			}
		}
	}

	//Проверка итерируемой переменной
	if (ConditionExpression->type != IDENTIFIER_EXPRESSION_TYPE) {
		string msg = "Iterable variable isn't variable. It has type '" + ConditionExpression->getTypeName() + "'";
		throw new std::exception(msg.c_str());
	}
	if (locals->isContains(ConditionExpression->name)) { //Локальная переменная
		Type* type = locals->items[ConditionExpression->name]->type;
		if (type->ClassName == "") {
			string msg = "Variable in fast enumeration isn't an object. It has type '" + type->toString() + "'";
			throw new std::exception(msg.c_str());
		}
	}
	else { //Поле
		if (ClassesTable::items.count(locals->items["self"]->type->ClassName) != 0) {
			ClassesTableElement* selfClass = ClassesTable::items[locals->items["self"]->type->ClassName];
			if (selfClass->isContainsField(ConditionExpression->name)) {
				string descr;
				string className;
				FieldsTableElement* field = selfClass->getFieldForRef(ConditionExpression->name, &descr, &className);
				Type* type = field->type;
				if (type->ClassName == "") {
					string msg = "Variable in fast enumeration isn't an object. It has type '" + type->toString() + "'";
					throw new std::exception(msg.c_str());
				}
			}
			else {
				string msg = "Variable '" + string(ConditionExpression->name) + "' is undeclarated";
				throw new std::exception(msg.c_str());
			}
		}

	}
}
