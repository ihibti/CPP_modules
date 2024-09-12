#include <iomanip>
#include <iostream>
#include <string>

using std::string;
class contact
{
  public:
	void set_ques(string new_q)
	{
		this->question = new_q;
	}
	string get_quest(void)
	{
		return (this->question);
	}
	void set_firstname(string new_n)
	{
		this->firstname = new_n;
	}
	string get_firstn(void)
	{
		return (this->firstname);
	}
	void set_last(string new_l)
	{
		this->lastname = new_l;
	}
	string get_last(void)
	{
		return (this->lastname);
	}
	void set_nick(string new_nick)
	{
		this->nickname = new_nick;
	}
	string get_nick(void)
	{
		return (this->nickname);
	}
	void set_ques(string new_q)
	{
		this->question = new_q;
	}
	string get_quest(void)
	{
		return (this->question);
	}

  private:
	string firstname;
	string lastname;
	int number;
	int rank;
	string question;
	string nickname;
};
class PhoneBook
{
  private:
	contact repertory[8];

  public:
	int nb_contacts;
	int new_index;
	int add_contact(string name, string lastname, string nickname,
		string question)
	{
		if (this->nb_contacts < 8)
		{
			repertory[new_index].set_firstname(name);
			nb_contacts++;
		}
        else
        {
            repertory[]
        }
	}
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
	PhoneBook new_p;
	PhoneBook *ptr;
	contact pl;
	ptr = new (PhoneBook);

	std::cout << "yessir\n";
	delete (ptr);
	pl.set_fisrtname("pierrelou9p");

	// 	string request;
	// 	std::cout << "Enter command\n";
	// 	std::cin >> request;
	// 	if (!ft_strcmp(request, "EXIT"))
	// 		return (0);
	// 	if (!ft_strcmp(request, "ADD"))
	// 		return ;
	// 	if (!ft_strcmp(request, "SEARCH"))
	// 		return ;
}