#include "tables.h"
#include <string>
extern long maxId;

void Statement_node::semanticTransform(LocalVariablesTable* locals, ConstantsTable *constants)
{
	if (type == SIMPLE_STATEMENT_TYPE) {
		Expression->assignmentTransform();
		Expression->setDataTypesAndCasts(locals);
		Expression->setAttributes(locals, constants);
	}
	else if (type == RETURN_STATEMENT_TYPE) {
		if (Expression != NULL) {
			Expression->assignmentTransform();
			Expression->setDataTypesAndCasts(locals);
			Expression->setAttributes(locals, constants);
		}
	}
	else if (type == IF_STATEMENT_TYPE) {
		If_statement_node* cur = (If_statement_node*)this;
		cur->Condition->assignmentTransform();
		cur->Condition->setDataTypesAndCasts(locals);
		cur->Condition->setAttributes(locals, constants);
		if (cur->TrueBranch != NULL)
			cur->TrueBranch->semanticTransform(locals, constants);
		if (cur->FalseBranch != NULL) {
			cur->FalseBranch->semanticTransform(locals, constants);
		}
	}
	else if (type == WHILE_STATEMENT_TYPE) {
		While_statement_node* cur = (While_statement_node*)this;
		cur->LoopCondition->assignmentTransform();
		cur->LoopCondition->setDataTypesAndCasts(locals);
		cur->LoopCondition->setAttributes(locals, constants);
		if (cur->LoopBody != NULL)
			cur->LoopBody->semanticTransform(locals, constants);
	}
	else if (type == FOR_STATEMENT_TYPE) {
		For_statement_node* cur = (For_statement_node*)this;
		if (cur->InitExpression != NULL) {
			cur->InitExpression->assignmentTransform();
			cur->InitExpression->setDataTypesAndCasts(locals);
			cur->InitExpression->setAttributes(locals, constants);
		}
		if (cur->ConditionExpression != NULL) {
			cur->ConditionExpression->assignmentTransform();
			cur->ConditionExpression->setDataTypesAndCasts(locals);
			cur->ConditionExpression->setAttributes(locals, constants);
		}
		if (cur->LoopExpression != NULL) {
			cur->LoopExpression->assignmentTransform();
			cur->LoopExpression->setDataTypesAndCasts(locals);
			cur->LoopExpression->setAttributes(locals, constants);
		}
		if (cur->InitList != NULL)
			cur->InitList->semanticTransform(locals, cur->NameType->toDataType(), constants);
		if (cur->LoopBody != NULL)
			cur->LoopBody->semanticTransform(locals, constants);

		if (cur->ForType == FOREACH_FOR_TYPE || cur->ForType == FOREACH_WITH_DECLARATION_FOR_TYPE) {
			cur->checkFastEnumerationTypes(locals);
		}
	}
	else if (type == DO_WHILE_STATEMENT_TYPE) {
		Do_while_statement_node* cur = (Do_while_statement_node*)this;
		cur->LoopCondition->assignmentTransform();
		cur->LoopCondition->setDataTypesAndCasts(locals);
		cur->LoopCondition->setAttributes(locals, constants);
		if (cur->LoopBody != NULL)
			cur->LoopBody->semanticTransform(locals, constants);
	}
	else if (type == COMPOUND_STATEMENT_TYPE) {
		Statement_list_node* cur = (Statement_list_node*)this;
		if (cur->First != NULL) {
			Statement_node* elem = cur->First;
			while (elem != NULL) {
				elem->semanticTransform(locals, constants);
				elem = elem->Next;
			}
		}
	}
	else if (type == DECLARATION_STATEMENT_TYPE) {
		Declaration_node* cur = (Declaration_node*)this;
		if (cur->init_declarator_list != NULL)
			cur->init_declarator_list->semanticTransform(locals, cur->typeNode->toDataType(), constants);
	}
}

void Init_declarator_list_node::semanticTransform(LocalVariablesTable *locals, Type *dataType, ConstantsTable *constants)
{
	Init_declarator_node* declarator = First;
	while (declarator != NULL)
	{
		declarator->semanticTransform(locals, dataType, constants);
		declarator = declarator->Next;
	}
}

void Init_declarator_node::semanticTransform(LocalVariablesTable* locals, Type *dataType, ConstantsTable *constants)
{
	if (expression != NULL) {
		expression->assignmentTransform();
		expression->setDataTypesAndCasts(locals);
		expression->setAttributes(locals, constants);

		if (type == ARRAY_WITH_INITIALIZING_DECLARATOR_TYPE) {
			if (dataType->DataType != CHAR_TYPE || expression->type != LITERAL_EXPRESSION_TYPE) {
				string msg = string("Type '") + expression->DataType->toString() + "' can't assignment to '" + dataType->toString() + "'";
				throw new std::exception(msg.c_str());
			}
		}

		if (!expression->DataType->equal(dataType) && !(type == ARRAY_WITH_INITIALIZING_DECLARATOR_TYPE && expression->DataType->DataType == dataType->DataType && expression->DataType->ClassName == dataType->ClassName)) {
			if (expression->DataType->isCastableTo(dataType)) {
				Expression_node* cast = new Expression_node();
				cast->id = maxId++;
				if (dataType->DataType == INT_TYPE) {
					cast->type = INT_CAST;
				}
				else if (dataType->DataType == CHAR_TYPE) {
					cast->type = CHAR_CAST;
				}
				else {
					cast->type = CLASS_CAST;
				}
				cast->DataType = dataType;
				cast->Right = expression;
				expression = cast;
			}
			else {
				string msg = string("Type '") + expression->DataType->toString() + "' doesn't castable to type '" + dataType->toString();
				throw new std::exception(msg.c_str());
			}
		}
	}
	if (InitializerList != NULL) {
		InitializerList->assignmentTransform();
		InitializerList->setDataTypesAndCasts(locals);
		InitializerList->setAttributes(locals, constants);
	}
	if (ArraySize != NULL) {
		ArraySize->assignmentTransform();
		ArraySize->setDataTypesAndCasts(locals);
		ArraySize->setAttributes(locals, constants);
		Type* castType = new Type(INT_TYPE);
		if (!ArraySize->DataType->isCastableTo(castType)) {
			string msg = "Array size isn't 'int' or castable to 'int'. It has type '" + ArraySize->DataType->toString() + "'";
			throw new std::exception(msg.c_str());
		}
		delete castType;
	}
}


// -------------------- ASSIGNMENT TRANSFORMATIONS --------------------

void Expression_node::assignmentTransform()
{
	arrayAssignmentTransform();
	memberAccessAssignmentTransform();
}

void Expression_node::arrayAssignmentTransform()
{
	if (this->type == ASSIGNMENT_EXPRESSION_TYPE && this->Left->type == ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE) {
		this->type = ARRAY_ASSIGNMENT_EXPRESSION_TYPE; 
		
		Expression_node* tmp = this->Left;
		this->Left = tmp->Left; //Левая часть от expr массива
		this->Child = tmp->Right; //Правая часть от expr массива
		delete tmp;
	}
	
	// Вызов преобразования на дочерних
	if (this->Left != NULL)
		this->Left->assignmentTransform();
	if (this->Right != NULL)
		this->Right->assignmentTransform();
	if (this->Child != NULL)
		this->Child->assignmentTransform();
}

void Expression_node::memberAccessAssignmentTransform()
{
	if (this->type == ASSIGNMENT_EXPRESSION_TYPE && (this->Left->type == DOT_EXPRESSION_TYPE || this->Left->type == ARROW_EXPRESSION_TYPE)) {
		this->type = MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE;

		Expression_node* tmp = this->Left;
		this->Left = tmp->Left; //Левая часть от expr dot
		this->name = tmp->name; //Правая часть от expr dot (identifier)
		this->Constant = tmp->Constant;
		this->Field = tmp->Field;
		delete tmp;
	}

	// Вызов преобразования на дочерних
	if (this->Left != NULL)
		this->Left->assignmentTransform();
	if (this->Right != NULL)
		this->Right->assignmentTransform();
	if (this->Child != NULL)
		this->Child->assignmentTransform();
}

void Expression_list_node::assignmentTransform()
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->assignmentTransform();
		cur = cur->Next;
	}
}


// -------------------- ADD DEFAULT RETURN --------------------
void MethodsTableElement::addDefaultReturn(Statement_node* lastStatement)
{
	Statement_node* defaultReturn;
	if (ReturnType->DataType == VOID_TYPE)
		defaultReturn = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, NULL); //Создать пустой return
	else {
		int defaultValue = ReturnType->getDefaultValue(); //Получить значение по умолчанию
		Numeric_constant_node *num = Numeric_constant_node::createNumericConstantNodeFromInteger(defaultValue); //Сформировать константу
		Expression_node* expr = Expression_node::createExpressionNodeFromNumericConstant(num); //Сформировать expression
		defaultReturn = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, expr); //Сформировать statement с return
	}
	
	lastStatement->Next = defaultReturn;
}

void FunctionsTableElement::addDefaultReturn(Statement_node* lastStatement)
{
	Statement_node* defaultReturn;
	if (ReturnType->DataType == VOID_TYPE || NameStr == "main")
		defaultReturn = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, NULL); //Создать пустой return
	else {
		int defaultValue = ReturnType->getDefaultValue(); //Получить значение по умолчанию
		Numeric_constant_node* num = Numeric_constant_node::createNumericConstantNodeFromInteger(defaultValue); //Сформировать константу
		Expression_node* expr = Expression_node::createExpressionNodeFromNumericConstant(num); //Сформировать expression
		defaultReturn = Statement_node::createStatementNodeFromSimpleStatement(RETURN_STATEMENT_TYPE, expr); //Сформировать statement с return
	}

	lastStatement->Next = defaultReturn;
}

// -------------------- SET DATA TYPES AND CASTS --------------------

void Expression_node::setDataTypesAndCasts(LocalVariablesTable *locals)
{
	// Вызов на дочерних элементах
	if (Left != NULL)
		Left->setDataTypesAndCasts(locals);
	if (Right != NULL)
		Right->setDataTypesAndCasts(locals);
	if (Child != NULL)
		Child->setDataTypesAndCasts(locals);
	string className;
	ClassesTableElement* classElem;

	switch (type) {
	case IDENTIFIER_EXPRESSION_TYPE:
	{
		if (locals->isContains(name)) { //Локальная переменная
			DataType = locals->items[name]->type;
		}
		else { //Поле
			if (ClassesTable::items->count(locals->items["self"]->type->ClassName) != 0) {
				ClassesTableElement* selfClass = ClassesTable::items->at(locals->items["self"]->type->ClassName);
				if (selfClass->isContainsField(name)) {
					string descr;
					string className;
					FieldsTableElement* field = selfClass->getFieldForRef(name, &descr, &className);
					DataType = field->type;
				}
				else {
					string msg = string("Class '") + selfClass->getClassName() + "doesn't contains field '" + string(name);
					throw new std::exception(msg.c_str());
				}
			}

		}
	}
		break;
	case LITERAL_EXPRESSION_TYPE: //Тип для литерала будет соответствовать типу литерала
	{
		if (literal->type == CHAR_CONSTANT_TYPE)
			DataType = new Type(CHAR_TYPE);
		else if (literal->type == STRING_CONSTANT_TYPE)
			DataType = new Type(CHAR_TYPE, strlen(literal->value) + 1);
		else if (literal->type == NSSTRING_CONSTANT_TYPE) {
			DataType = new Type(CLASS_NAME_TYPE, ClassesTable::getFullClassName("NSString"));
			type = MESSAGE_EXPRESSION_EXPRESSION_TYPE;

			char* className = new char[strlen("rtl/NSString")];
			strcpy(className, "rtl/NSString");
			Receiver = Receiver_node::createReceiverNode(CLASS_NAME_RECEIVER_TYPE, className);
			Receiver->DataType = new Type(CLASS_NAME_TYPE, className);
			Expression_node* val = Expression_node::createExpressionNodeFromLiteral(Literal_node::createLiteralNode(STRING_CONSTANT_TYPE, literal->value));
			val->DataType = new Type(CHAR_TYPE, strlen(literal->value));
			char* methodName = new char[strlen("stringWithCStringStatic")];
			strcpy(methodName, "stringWithCStringStatic");
		    Arguments = Message_selector_node::createMessageSelectorNode(methodName, val, NULL, NULL);
			literal = NULL;

			string thisClass = locals->items["self"]->type->ClassName;
			ConstantsTable* constantTable = ClassesTable::items->at(thisClass)->ConstantTable;
			Constant = constantTable->findOrAddMethodRefConstant(className, methodName, "([C)Lrtl/NSString;");
			string d;
			string c;
			Method = ClassesTable::items->at(className)->getMethodForRef("stringWithCStringStatic", &d, &c);
		}
	}
		break;
	case NUMERIIC_CONSTANT_EXPRESSION_TYPE: //Тип для числовой константы будет соответствовать int (т.к. float не поддерживается)
	{
		DataType = new Type(INT_TYPE);
	}
		break;
	case SELF_EXPRESSION_TYPE:
	{
		DataType = locals->items["self"]->type;
	}
		break;
	case SUPER_EXPRESSION_TYPE:
	{
		Type* selfType = locals->items["self"]->type;
		DataType = selfType->getSuperType();
		if (DataType == NULL) {
			string msg = string("Class '") + selfType->ClassName + "' don't have superclass";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case MESSAGE_EXPRESSION_EXPRESSION_TYPE:
	{
		Receiver->setDataType(locals);
		Type* receiverType = Receiver->DataType;
		if (receiverType->DataType != CLASS_NAME_TYPE && receiverType->DataType != ID_TYPE) {
			string msg = string("Receiver is not a class or object. It has type: '") + receiverType->toString();
			throw new std::exception(msg.c_str());
		}
		else if (ClassesTable::items->count(receiverType->ClassName) == 0) {
			string msg = string("Class '") + receiverType->ClassName + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
		else if (!ClassesTable::items->at(receiverType->ClassName)->isContainsMethod(Arguments->MethodName)) {
			string msg = string("Class '") + receiverType->ClassName + "doesn't contains method '" + string(Arguments->MethodName);
			throw new std::exception(msg.c_str());
		}
		else {
			string descriptor;
			string className;
			MethodsTableElement* method = ClassesTable::items->at(receiverType->ClassName)->getMethodForRef(Arguments->MethodName, &descriptor, &className);
			DataType = method->ReturnType;
			Arguments->setDataTypes(locals, receiverType->ClassName); //Установить DataType для параметров
		}
	}
		break;
	case FUNCTION_CALL_EXPRESSION_TYPE:
	{
		if (FunctionsTable::items.count(name) != 0) {
			DataType = FunctionsTable::items[name]->ReturnType;
			ArgumentsList->setDataTypesAndCasts(locals);
		}
		else {
			string msg = "Function '" + string(name) + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case UMINUS_EXPRESSION_TYPE:
	case UPLUS_EXPRESSION_TYPE:
	{
		if (Right->DataType->isPrimitive())
			DataType = Right->DataType;
		else {
			string msg = string("Type '") + Right->DataType->toString() + "can't using as argument of unary operation";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case UAMPERSAND_EXPRESSION_TYPE:
	{
		string msg = "Error! Unsupported operation unary ampersand.";
		throw new std::exception(msg.c_str());
	}
	break;
	case PLUS_EXPRESSION_TYPE:
	case MINUS_EXPRESSION_TYPE:
	case MUL_EXPRESSION_TYPE:
	case DIV_EXPRESSION_TYPE:
	case EQUAL_EXPRESSION_TYPE:
	case NOT_EQUAL_EXPRESSION_TYPE:
	case GREATER_EXPRESSION_TYPE:
	case LESS_EXPRESSION_TYPE:
	case GREATER_EQUAL_EXPRESSION_TYPE:
	case LESS_EQUAL_EXPRESSION_TYPE:
	{
		if (Left->DataType->isPrimitive() && Right->DataType->isPrimitive()) {
			if (Left->DataType->DataType == VOID_TYPE || Right->DataType->DataType == VOID_TYPE) {
				string msg = "Void type can't using as argument of binary arithmetic or comparation operation";
			}
			if (Left->DataType->equal(Right->DataType)) {
				DataType = Left->DataType;
			}
			else {
				if (Right->DataType->isCastableTo(Left->DataType)) {
					// Преобразовать тип
					Expression_node* cast = new Expression_node();
					cast->id = maxId++;
					if (Left->DataType->DataType == INT_TYPE) {
						cast->type = INT_CAST;
						cast->DataType = new Type(INT_TYPE);
					}
					else {
						cast->type = CHAR_CAST;
						cast->DataType = new Type(CHAR_TYPE);
					}
					cast->Right = Right;
					Right = cast;
					DataType = Left->DataType;
				}
				else {
					string msg = string("Type '") + Right->DataType->toString() + "' doesn't castable to type '" + Left->DataType->toString();
					throw new std::exception(msg.c_str());
				}
			}
		}
		else if (!Left->DataType->isPrimitive() && !Right->DataType->isPrimitive() && (type == EQUAL_EXPRESSION_TYPE || type == NOT_EQUAL_EXPRESSION_TYPE))
		{
			DataType = new Type(INT_TYPE);
		}
		else {
			string msg = "Type '";
			if (!Left->DataType->isPrimitive())
				msg += Left->DataType->toString() + "can't using as argument of binary arithmetic or comparation operation";
			else
				msg += Right->DataType->toString() + "can't using as argument of binary arithmetic or comparation operation";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case ARRAY_ELEMENT_ACCESS_EXPRESSION_TYPE:
	{
		if (!Right->DataType->isCastableTo(new Type(INT_TYPE))) {
			string msg = "Array element access isn't 'int' or castable to 'int'. It have type '" + Right->DataType->toString() + "'";
			throw new std::exception(msg.c_str());
		}
		DataType = new Type(Left->DataType->DataType, Left->DataType->ClassName);
	}
		break;
	case ARROW_EXPRESSION_TYPE:
	{
		if (Left->DataType->ClassName == "") {
			string msg = string("Can't access to field '") + string(name) + "' because of left is not object";
			throw new std::exception(msg.c_str());
		}
		className = Left->DataType->ClassName;
		if (ClassesTable::items->count(className) == 0) {
			string msg = string("Class '") + className + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
		if (Left->type == SUPER_EXPRESSION_TYPE) {
			string msg = "Can't access to field of super object";
			throw new std::exception(msg.c_str());
		}
		ClassesTableElement* classElem = ClassesTable::items->at(className);
		if (classElem->isContainsField(name)) {
			string descr;
			string n;
			FieldsTableElement* field = classElem->getFieldForRef(name, &descr, &n);
			DataType = field->type;
		}
		else {
			string msg = string("Class '") + className + "' doesn't contains field '" + string(name);
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case ASSIGNMENT_EXPRESSION_TYPE:
	{
		DataType = Left->DataType;
		if (!Right->DataType->equal(Left->DataType)) {
			if (Right->DataType->isCastableTo(Left->DataType)) {
				Expression_node* cast = new Expression_node();
				cast->id = maxId++;
				if (Left->DataType->DataType == INT_TYPE) {
					cast->type = INT_CAST;
					cast->DataType = new Type(INT_TYPE);
				}
				else if (Left->DataType->DataType == CHAR_TYPE) {
					cast->type = CHAR_CAST;
					cast->DataType = new Type(CHAR_TYPE);
				}
				else {
					cast->type = CLASS_CAST;
					cast->DataType = Left->DataType;
				}
				cast->Right = Right;
				Right = cast;
			}
			else {
				string msg = string("Type '") + Right->DataType->toString() + "' doesn't castable to type '" + Left->DataType->toString();
				throw new std::exception(msg.c_str());
			}
		}
	}
	break;
	case ARRAY_ASSIGNMENT_EXPRESSION_TYPE:
	{
		if (!Child->DataType->isCastableTo(new Type(INT_TYPE))) {
			string msg = "Array element access isn't 'int' or castable to 'int'. It has type '" + Child->DataType->toString() + "'";
			throw new std::exception(msg.c_str());
		}
		DataType = Left->DataType;
		if (!Right->DataType->equal(new Type(Left->DataType->DataType))) {
			if (Right->DataType->isCastableTo(Left->DataType)) {
				Expression_node* cast = new Expression_node();
				cast->id = maxId++;
				if (Left->DataType->DataType == INT_TYPE) {
					cast->type = INT_CAST;
					cast->DataType = new Type(INT_TYPE);
				}
				else if (Left->DataType->DataType == CHAR_TYPE) {
					cast->type = CHAR_CAST;
					cast->DataType = new Type(CHAR_TYPE);
				}
				else {
					cast->type = CLASS_CAST;
					cast->DataType = Left->DataType;
				}
				cast->Right = Right;
				Right = cast;
			}
			else {
				string msg = string("Type '") + Right->DataType->toString() + "' doesn't castable to type '" + Left->DataType->toString();
				throw new std::exception(msg.c_str());
			}
		}
	}
		break;
	
	case MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE:
	{
		if (Left->DataType->ClassName == "") {
			string msg = string("Can't access to field '") + string(name) + "' because of left is not object";
			throw new std::exception(msg.c_str());
		}
		className = Left->DataType->ClassName;
		if (ClassesTable::items->count(className) == 0) {
			string msg = string("Class '") + className + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
		ClassesTableElement* classElem = ClassesTable::items->at(className);
		if (classElem->isContainsField(name)) {
			string descr;
			string n;
			FieldsTableElement* field = classElem->getFieldForRef(name, &descr, &n);
			DataType = field->type;
			if (!field->type->equal(Right->DataType)) {
				if (Right->DataType->isCastableTo(field->type)) {
					Expression_node* cast = new Expression_node();
					cast->id = maxId++;
					if (field->type->DataType == INT_TYPE) {
						cast->type = INT_CAST;
						cast->DataType = new Type(INT_TYPE);
					}
					else if (field->type->DataType == CHAR_TYPE) {
						cast->type = CHAR_CAST;
						cast->DataType = new Type(CHAR_TYPE);
					}
					else {
						cast->type = CLASS_CAST;
						cast->DataType = field->type;
					}
					cast->Right = Right;
					Right = cast;
				}
				else {
					string msg = string("Type '") + Right->DataType->toString() + "' doesn't castable to type '" + Left->DataType->toString();
					throw new std::exception(msg.c_str());
				}
			}
		}
		else {
			string msg = string("Class '") + className + "' doesn't contains field '" + string(name);
			throw new std::exception(msg.c_str());
		}
	}
		break;
	default:
		break;
	}


}

void Receiver_node::setDataType(LocalVariablesTable* locals)
{
	switch (type)
	{
	case SUPER_RECEIVER_TYPE:
	{
		Type* selfType = locals->items["self"]->type;
		DataType = selfType->getSuperType();
		if (DataType == NULL) {
			string msg = string("Class '") + selfType->ClassName + "' don't have superclass";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case SELF_RECEIVER_TYPE:
	{
		DataType = locals->items["self"]->type;
	}
		break;
	case OBJECT_NAME_RECEIVER_TYPE:
	{
		if (locals->isContains(name)) { //Локальная переменная
			DataType = locals->items[name]->type;
		}
		else { //Поле
			if (ClassesTable::items->count(locals->items["self"]->type->ClassName) != 0) {
				ClassesTableElement* selfClass = ClassesTable::items->at(locals->items["self"]->type->ClassName);
				if (selfClass->isContainsField(name)) {
					string descr;
					string className;
					FieldsTableElement* field = selfClass->getFieldForRef(name, &descr, &className);
					DataType = field->type;
				}
				else {
					string msg = string("Class '") + selfClass->getClassName() + "doesn't contains field '" + string(name);
					throw new std::exception(msg.c_str());
				}
			}

		}
		if (DataType == NULL) { //Отсутствует в локальных переменных и полях
			string msg = string("Doesn't contains variable '") + string(name);
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case CLASS_NAME_RECEIVER_TYPE:
	{
		if (ClassesTable::items->count(name) != NULL) {
			DataType = new Type(CLASS_NAME_TYPE, ClassesTable::getFullClassName(name));
		}
		else {
			string msg = string("Class '") + string(name) + "doesn't exist";
			throw new std::exception(msg.c_str());
		}
	}
		break;
	case MESSAGE_EXPRESSION_RECEIVER_TYPE:
	{
		Receiver->setDataType(locals);
		Type* receiverType = Receiver->DataType;
		if (receiverType->DataType != CLASS_NAME_TYPE && receiverType->DataType != ID_TYPE) {
			string msg = string("Receiver is not a class or object. It has type: '") + receiverType->toString();
			throw new std::exception(msg.c_str());
		}
		else if (ClassesTable::items->count(receiverType->ClassName) == 0) {
			string msg = string("Class '") + receiverType->ClassName + "' doesn't exist";
			throw new std::exception(msg.c_str());
		}
		else if (!ClassesTable::items->at(receiverType->ClassName)->isContainsMethod(Arguments->MethodName)) {
			string msg = string("Class '") + receiverType->ClassName + "doesn't contains method '" + string(Arguments->MethodName);
			throw new std::exception(msg.c_str());
		}
		else {
			string descriptor;
			string className;
			MethodsTableElement* method = ClassesTable::items->at(receiverType->ClassName)->getMethodForRef(Arguments->MethodName, &descriptor, &className);
			DataType = method->ReturnType;
			Arguments->setDataTypes(locals, receiverType->ClassName); //Установить DataType для параметров
		}
	}
		break;
	default:
		break;
	}
}

void Message_selector_node::setDataTypes(LocalVariablesTable* locals, string receiverClassName)
{
	if (FirstArgument != NULL)
		FirstArgument->setDataTypesAndCasts(locals);
	if (Arguments != NULL)
		Arguments->setDataTypes(locals);
	if (ExprArguments != NULL)
		ExprArguments->setDataTypesAndCasts(locals);

	// Проверка типов и добавление при необходимости cast

	// Получить метод
	ClassesTableElement* classElem = ClassesTable::items->at(receiverClassName);
	MethodsTableElement* method;
	if (classElem->isContainsMethod(MethodName)) {
		string descr;
		string n;
		method = classElem->getMethodForRef(MethodName, &descr, &n);
	}
	else {
		string msg = string("Class '") + receiverClassName + "' doesn't contains method '" + MethodName + "'";
		throw new std::exception(msg.c_str());
	}

	//Проверка количества параметров
	int kwCount = 0;
	if (FirstArgument != NULL)
		kwCount++;
	if (Arguments != NULL)
		kwCount += Arguments->getElements()->size();
	int paramCount = 0;
	if (ExprArguments != NULL)
		ExprArguments->getElements()->size();

	if (kwCount != method->KeywordsTypes->size()) {
		string msg = string("Method '") + string(MethodName) + "' get '" + to_string(kwCount) + "' keyword arguments, but expected '" + to_string(method->KeywordsTypes->size()) + "'";
		throw new std::exception(msg.c_str());
	}
	if (paramCount != method->ParamsTypes->size()) {
		string msg = string("Method '") + string(MethodName) + "' get '" + to_string(paramCount) + "' parameters arguments, but expected '" + to_string(method->ParamsTypes->size()) + "'";
		throw new std::exception(msg.c_str());
	}


	//Проверка типов и добавление cast
	if (FirstArgument != NULL) {
		Type* kwType = method->KeywordsTypes->at(0);
		if (kwType->equal(FirstArgument->DataType) || FirstArgument->DataType->isCastableTo(kwType)) {
			if (!kwType->equal(FirstArgument->DataType)) {
				Expression_node* cast = new Expression_node();
				cast->id = maxId++;
				if (kwType->DataType == INT_TYPE) {
					cast->type = INT_CAST;
				}
				else if (kwType->DataType == CHAR_TYPE) {
					cast->type = CHAR_CAST;
				}
				else if (kwType->DataType == CLASS_NAME_TYPE) {
					cast->type = CLASS_CAST;
				}
				cast->DataType = kwType;
				cast->Right = FirstArgument;
				FirstArgument = cast;
			}
		}
		else {
			string msg = string("Type '") + FirstArgument->DataType->toString() + "' doesn't castable to type '" + method->KeywordsTypes->at(0)->toString() + "' in method '" + string(MethodName);
			throw new std::exception(msg.c_str());
		}
	}

	if (Arguments != NULL) {
		vector<Keyword_argument_node*> *kwArgs = Arguments->getElements();
		for (int i = 1; i <= kwArgs->size(); i++) {
			Type* kwType = method->KeywordsTypes->at(i);
			Type* argType = kwArgs->at(i - 1)->expression->DataType;

			if (kwType->equal(argType) || argType->isCastableTo(kwType)) {
				if (!kwType->equal(argType)) {
					Expression_node* cast = new Expression_node();
					cast->id = maxId++;
					if (kwType->DataType == INT_TYPE) {
						cast->type = INT_CAST;
					}
					else if (kwType->DataType == CHAR_TYPE) {
						cast->type = CHAR_CAST;
					}
					else if (kwType->DataType == CLASS_NAME_TYPE) {
						cast->type = CLASS_CAST;
					}
					cast->DataType = kwType;
					cast->Right = kwArgs->at(i-1)->expression;
					kwArgs->at(i - 1)->expression = cast;
				}
			}
			else {
				string msg = string("Type '") + kwArgs->at(i - 1)->expression->DataType->toString() + "' doesn't castable to type '" + method->KeywordsTypes->at(i)->toString() + "' in method '" + string(MethodName);
				throw new std::exception(msg.c_str());
			}
		}
	}

	if (ExprArguments != NULL) {
		vector<Expression_node*>* args = ExprArguments->getElements();
		for (int i = 0; i < args->size(); i++) {
			Type* paramType = method->ParamsTypes->at(i);
			Type* argType = args->at(i)->DataType;

			if (paramType->equal(argType) || argType->isCastableTo(paramType)) {
				if (!paramType->equal(argType)) {
					Expression_node* cast = new Expression_node();
					cast->id = maxId++;
					if (paramType->DataType == INT_TYPE) {
						cast->type = INT_CAST;
					}
					else if (paramType->DataType == CHAR_TYPE) {
						cast->type = CHAR_CAST;
					}
					else if (paramType->DataType == CLASS_NAME_TYPE) {
						cast->type = CLASS_CAST;
					}
					cast->DataType = paramType;
					cast->Right = args->at(i);
					args->at(i) = cast;
				}
			}
			else {
				string msg = string("Type '") + args->at(i)->DataType->toString() + "' doesn't castable to type '" + method->ParamsTypes->at(i)->toString() + "' in method '" + string(MethodName);
				throw new std::exception(msg.c_str());
			}
		}
	}

}

void Keyword_argument_list_node::setDataTypes(LocalVariablesTable* locals)
{
	Keyword_argument_node* cur = First;
	while (cur != NULL)
	{
		if (cur->name != NULL) {
			string msg = "ERROR! Unsupported identifiers in keyword arguments: '" + string(cur->name) + "'";
			throw new std::exception(msg.c_str());
		}
		cur->expression->setDataTypesAndCasts(locals);
		cur = cur->Next;
	}
}


void Expression_list_node::setDataTypesAndCasts(LocalVariablesTable* locals)
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->setDataTypesAndCasts(locals);
		cur = cur->Next;
	}
}

// -------------------- SET ATTRIBUTES --------------------

void Expression_node::setAttributes(LocalVariablesTable* locals, ConstantsTable* constants)
{
	// Вызов на дочерних элементах
	if (Left != NULL)
		Left->setAttributes(locals, constants);
	if (Right != NULL)
		Right->setAttributes(locals, constants);
	if (Child != NULL)
		Child->setAttributes(locals, constants);
	string className;
	ClassesTableElement* classElem;

	switch (type) {
	case IDENTIFIER_EXPRESSION_TYPE:
	{
		if (locals->isContains(name)) { //Локальная переменная
			LocalVariable = locals->items[name];
		}
		else { //Поле
				ClassesTableElement* selfClass = ClassesTable::items->at(locals->items["self"]->type->ClassName);
				string descr;
				string className;
				Field = selfClass->getFieldForRef(name, &descr, &className);
		}
	}
	break;
	case LITERAL_EXPRESSION_TYPE: {
		if (literal->type != CHAR_CONSTANT_TYPE) {
			int num = constants->findConstant(UTF8, new string(literal->value));
			int str = constants->findConstant(String, NULL, NULL, num);
			literal->constant = constants->getConstant(str);
		}
	}
	break;
	case NUMERIIC_CONSTANT_EXPRESSION_TYPE: {
		if (num->Int < -32768 || num->Int > 32767) {
			num->constant = constants->findConstant(Integer, NULL, num->Int);
		}
	}
	break;
	case SELF_EXPRESSION_TYPE:
	case SUPER_EXPRESSION_TYPE:
	{
		LocalVariable = locals->items["self"];
	}
	break;
	case MESSAGE_EXPRESSION_EXPRESSION_TYPE:
	{
		Receiver->setAttributes(locals, constants);
		Type* receiverType = Receiver->DataType;
		string descriptor;
		string className;
		Method = ClassesTable::items->at(receiverType->ClassName)->getMethodForRef(Arguments->MethodName, &descriptor, &className);
		Arguments->setAttributes(locals, constants); //Установить атрибуты для параметров
	}
	break;
	case ARROW_EXPRESSION_TYPE:
	{
		className = Left->DataType->ClassName;
		ClassesTableElement* classElem = ClassesTable::items->at(className);
		string descr;
		string n;
		Field = classElem->getFieldForRef(name, &descr, &n);
	}
	break;
	case MEMBER_ACCESS_ASSIGNMENT_EXPRESSION_TYPE:
	{
		className = Left->DataType->ClassName;
		ClassesTableElement* classElem = ClassesTable::items->at(className);
		string descr;
		string n;
		Field = classElem->getFieldForRef(name, &descr, &n);
	}
	break;
	default:
		break;
	}
}

void Expression_list_node::setAttributes(LocalVariablesTable* locals, ConstantsTable *constants)
{
	Expression_node* cur = First;
	while (cur != NULL)
	{
		cur->setAttributes(locals, constants);
		cur = cur->Next;
	}
}


void Receiver_node::setAttributes(LocalVariablesTable* locals, ConstantsTable *constants)
{
	switch (type)
	{
	case SELF_RECEIVER_TYPE:
	case SUPER_RECEIVER_TYPE:
	{
		LocalVariable = locals->items["self"];
	}
	break;
	case OBJECT_NAME_RECEIVER_TYPE:
	{
		if (locals->isContains(name)) { //Локальная переменная
			LocalVariable = locals->items[name];
		}
		else { //Поле
			ClassesTableElement* selfClass = ClassesTable::items->at(locals->items["self"]->type->ClassName);
			string descr;
			string className;
			Field = selfClass->getFieldForRef(name, &descr, &className);
		}
	}
	break;
	case MESSAGE_EXPRESSION_RECEIVER_TYPE:
	{
		Receiver->setAttributes(locals, constants);
		Type* receiverType = Receiver->DataType;
		
		string descriptor;
		string className;
		Method = ClassesTable::items->at(receiverType->ClassName)->getMethodForRef(Arguments->MethodName, &descriptor, &className);
		Arguments->setAttributes(locals, constants); //Установить атрибуты для параметров
	}
	break;
	default:
		break;
	}
}


void Message_selector_node::setAttributes(LocalVariablesTable* locals, ConstantsTable *constants)
{
	if (FirstArgument != NULL)
		FirstArgument->setAttributes(locals, constants);
	if (Arguments != NULL)
		Arguments->setAttributes(locals, constants);
	if (ExprArguments != NULL)
		ExprArguments->setAttributes(locals, constants);

}

void Keyword_argument_list_node::setAttributes(LocalVariablesTable* locals, ConstantsTable *constant)
{
	Keyword_argument_node* cur = First;
	while (cur != NULL)
	{
		cur->expression->setAttributes(locals, constant);
		cur = cur->Next;
	}
}


// ---------- APPEND_DEFAULT_CONSTRUCTOR ----------
void ClassesTableElement::appendConstructor()
{
	if (isNeedToGenerateClassFile()) {
		string name = "<init>";
		string descriptor = "()V";
		Type* returnType = new Type(VOID_TYPE);
		vector<Type*>* params = new vector<Type*>;
		vector<Type*>* kw = new vector<Type*>;
		MethodsTableElement *method = Methods->addMethod(ConstantTable, name, descriptor, false, NULL, returnType, params, kw);

		Type* dataType = new Type(CLASS_NAME_TYPE, getClassName());
		method->LocalVariables->findOrAddLocalVariable("self", dataType);

		constructorNumber = ConstantTable->findOrAddMethodRefConstant(getSuperClassName(), "<init>", "()V"); 
	}

}

// ---------- APPEND CLASS CONSTANTS FROM LOCALS ----------
void LocalVariablesTable::addConstantsToTable(ConstantsTable* constantsTable)
{
	for (auto iter = items.begin(); iter != items.end(); iter++) {
		if (iter->second->type->DataType == CLASS_NAME_TYPE) {
			int utf = constantsTable->findOrAddConstant(UTF8, iter->second->type->ClassName);
			constantsTable->findOrAddConstant(Class, NULL, utf);
		}
		else if (iter->second->type->DataType == ID_TYPE) {
			int utf = constantsTable->findOrAddConstant(UTF8, "rtl/NSObject");
			constantsTable->findOrAddConstant(Class, NULL, utf);
		}
	}
}

void ClassesTable::addConstantsToTable()
{
	for (auto iter = items->begin(); iter != items->end(); iter++) {
		iter->second->addConstantsToTable();
	}
}

void ClassesTableElement::addConstantsToTable()
{
	Methods->addConstantsToTable(ConstantTable);
}

void MethodsTable::addConstantsToTable(ConstantsTable* constantsTable)
{
	for (auto iter = items.begin(); iter != items.end(); iter++) {
		iter->second->addConstantsToTable(constantsTable);
	}
}

void MethodsTableElement::addConstantsToTable(ConstantsTable* constantsTable)
{
	LocalVariables->addConstantsToTable(constantsTable);
}
