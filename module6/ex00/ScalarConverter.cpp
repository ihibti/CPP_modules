#include "ScalarConverter.hpp"

// constructeur prive pour empecher l'instanciation
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

void ScalarConverter::convert(const std::string &literal)
{
	double	value;

	// detection du type
    if (literal == "inf" || literal == "inff" || literal == "+inff" || literal == "+inf")
        value  = std::numeric_limits<double>::infinity() ;
    else if (literal == "-inf" || literal == "-inff")
        value  = -std::numeric_limits<double>::infinity() ;
    else if (literal == "nan" || literal == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
	else if (isChar(literal))
	{
		value = static_cast<double>(literal[0]);
	}
	else if (isInt(literal))
	{
		value = static_cast<double>(std::atoi(literal.c_str()));
	}
	else if (isFloat(literal))
	{
		value = static_cast<double>(std::atof(literal.c_str()));
	}
	else if (isDouble(literal))
	{
		value = std::atof(literal.c_str());
	}
	else
	{
		std::cout << "Invalid literal" << std::endl;
		return ;
	}
	// resultat final
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
	char	*end;
	long	num;

	num = std::strtol(literal.c_str(), &end, 10);
	return (*end == '\0' && num >= std::numeric_limits<int>::min()
		&& num <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	return (literal.find('f') != std::string::npos
		&& literal.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	return (literal.find('.') != std::string::npos
		&& literal.find('f') == std::string::npos);
}

void ScalarConverter::printChar(double value)
{
	if (std::isnan(value) || value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (std::isprint(static_cast<int>(value)))
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(double value)
{
	if (std::isnan(value) || value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: " << static_cast<float>(value);
	if (value == static_cast<int>(value))
	{
		std::cout << ".0f" << std::endl;
	}
	else
	{
		std::cout << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
	{
		std::cout << ".0" << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}
