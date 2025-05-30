#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name),
	_isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName() << " (sign: " << form.getGradeToSign();
	os << ",execute: " << form.getGradeToExecute();
	os << "),signed: " << (form.isSigned() ? "yes" : "no");
	return (os);
}
