#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <iostream>
# include <stdexcept>
# include <string>

class	Form;

class Bureaucrat
{
  public:
    Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  private:
	const std::string _name;
	int _grade;

	void checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
