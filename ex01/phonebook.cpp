#include <iostream>
#include <string>

using std::string;

class PhoneBook
{
	class contact
	{
		string firstname;
		string lastname;
		int number;
		int rank;
	};
};

int	ft_strcmp(string s1, string s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	while (1)
	{
		string request;
		std::cout << "Enter command\n";
		std::cin >> request;
		if (!ft_strcmp(request, "EXIT"))
			return (0);
		if (!ft_strcmp(request, "ADD"))
			return ;
		if (!ft_strcmp(request, "SEARCH"))
			return ;
	}
}