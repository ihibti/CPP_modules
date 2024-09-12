#include <iomanip>
#include <iostream>
#include <string>

using std::string;

int	ft_isonlynumber(string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
class contact
{
  public:
	void set_quest(string new_q)
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
	string get_firstname(void)
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
	int set_get_age(bool state, int age)
	{
		if (state)
			this->age = age;
		else
			return (this->age);
		return (0);
	}
	int set_get_number(bool state, int number)
	{
		if (state)
			this->number = number;
		else
			return (this->number);
		return (0);
	}

  private:
	string firstname;
	string lastname;
	int number;
	int age;
	string question;
	string nickname;
};
class PhoneBook
{
  private:
	contact repertory[8];

  public:
	int nb_contacts;
	int get_oldest_contact(void)
	{
		int i = 0;
		while (i < 8)
		{
			if (repertory[i].set_get_age(false, 0) == 8)
				return (i);
			i++;
		}
		return (-1);
	}
	int add_contact(string name, string lastname, string nickname,
			string question, int number)
	{
		int i;
		if (this->nb_contacts < 8)
		{
			repertory[this->nb_contacts].set_firstname(name);
			repertory[this->nb_contacts].set_quest(question);
			repertory[this->nb_contacts].set_last(lastname);
			repertory[this->nb_contacts].set_nick(nickname);
			repertory[this->nb_contacts].set_get_age(true, 0);
			repertory[this->nb_contacts].set_get_number(true, number);
			nb_contacts++;
			i = 9;
		}
		else
		{
			i = get_oldest_contact();
			repertory[i].set_firstname(name);
			repertory[i].set_quest(question);
			repertory[i].set_last(lastname);
			repertory[i].set_nick(nickname);
			repertory[i].set_get_age(true, 0);
			repertory[i].set_get_number(true, number);
		}
		for (int j = 0; j < 8; j++)
		{
			if (j == i)
				continue ;
			repertory[j].set_get_age(true, repertory[j].set_get_age(false, 0)
					+ 1);
		}
		return (0);
	}
	void ADD()
	{
		string fn;
		string ln;
		string quest;
		string nick;
		string number;

		std::cout << "nom du contact:\n";
		std::cin >> fn;
		while (fn.empty() || std::all_of(fn.begin(), fn.end(), isspace))
		{
			std::cout << "nom du contact:\n";
			std::cin >> fn;
		}
		std::cout << "nom de famille du contact:\n";
		std::cin >> ln;
		while (ln.empty() || std::all_of(ln.begin(), ln.end(), isspace))
		{
			std::cout << "nom de famille du contact:\n";
			std::cin >> ln;
		}
		std::cout << "question du contact:\n";
		std::cin >> quest;
		while (quest.empty() || std::all_of(quest.begin(), quest.end(),
				isspace))
		{
			std::cout << "question du contact:\n";
			std::cin >> quest;
		}
		std::cout << "surnom du contact:\n";
		std::cin >> nick;
		while (nick.empty() || std::all_of(nick.begin(), nick.end(), isspace))
		{
			std::cout << "surnom du contact:\n";
			std::cin >> nick;
		}
		std::cout << "numero du contact:\n";
		std::cin >> number;
		while (number.empty() || std::all_of(number.begin(), number.end(),
				isspace) || !ft_isonlynumber(number))
		{
			std::cout << "numero du contact:\n";
			std::cin >> number;
		}
		add_contact(fn, ln, nick, quest, std::stoi(number));
	}
	void print_string(string str)
	{
		if ((str.length()) > 10)
		{
			std::cout << str.substr(0, 9) << ".|";
		}
		else
		{
			for (int i = str.length(); i <= 10; i++)
			{
				std::cout << ' ';
			}
			std::cout << str;
			std::cout << "|";
		}
	}
	int display()
	{
		for (int i = 0; i < nb_contacts; i++)
		{
			std::cout << "         " << i << "|";
			print_string(repertory[i].get_firstname());
			print_string(repertory[i].get_last());
			print_string(repertory[i].get_nick());
			std::cout << "\n";
		}
		return (0);
	}
	int search()
	{
		int i;
		i = -1;
		if (nb_contacts < 1)
			return (std::cout << "pas encore de contacts\n", 0);
		display();
		while (i < 0 || i > nb_contacts)
		{
			std::cout << "index du contact que vous recherchez:\n";
			std::cin >> i;
		}
		std::cout << repertory[i].get_firstname() << "\n";
		std::cout << repertory[i].get_last() << "\n";
		std::cout << repertory[i].get_nick() << "\n";
		std::cout << repertory[i].set_get_number(false, 0) << "\n";
		std::cout << repertory[i].get_quest() << "\n";
		return (0);
	}
	PhoneBook()
	{
		this->nb_contacts = 0;

		string request;
		while (true)
		{
			std::cout << "commmandes disponibles EXIT,SEARCH,ADD\n";
			std::cin >> request;
			if (!request.compare("EXIT"))
				return ;
			if (!request.compare("SEARCH"))
				search();
			if (!request.compare("ADD"))
				ADD();
		}
	}
};

int	main(void)
{
	PhoneBook new_phone = PhoneBook();
	return (0);
}