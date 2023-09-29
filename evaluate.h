#ifndef EVALUATE_H
#define EVALUATE_H

#include <string>

std::string buildPostfix(std::string infixExpression);
double evalPostfix(std::string postfixExpression);

#endif