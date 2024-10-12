#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::checkGrade(int grade) const
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ",requires grade ";
	os << form.getGradeToSign() << " to sign,grade ";
	os << form.getGradeToExecute() << " to execute. Signed: ";
	os << (form.isSigned() ? "yes" : "no");
	return (os);
}
