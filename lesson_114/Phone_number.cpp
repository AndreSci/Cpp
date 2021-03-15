#include "phone_number.h"
#include <string>
#include <sstream>
#include <exception>

PhoneNumber::PhoneNumber(const string & international_number)
{
	char test1(' '), test2(' '), test3(' '), simb;
	stringstream numb(international_number);

	numb >> test1;
	if (test1 != '+')
	{
		throw invalid_argument("incorrect number - does not start with '+'");
	}

	for (int i(1); i < static_cast<int>(international_number.size()); i++)
	{
		simb = international_number[i];
		if (simb == '-')
		{
			if (test2 != '-')
				test2 = '-';
			else if (test3 != '-')
			{
				test3 = '-';
				break;
			}
		}
	}
	
	getline(numb, country_code_, '-');
	if (test2 != '-')
	{
		throw invalid_argument("incorrect number - does not '-' in test 1");
	}
	getline(numb, city_code_, '-');
	if (test3 != '-')
	{
		throw invalid_argument("incorrect number - does not '-' in test 2");
	}
	getline(numb, local_number_);

	if(country_code_.empty())
		throw invalid_argument("incorrect number - does not country_code");
	else if (city_code_.empty())
		throw invalid_argument("incorrect number - does not city_code");
	else if (local_number_.empty())
		throw invalid_argument("incorrect number - does not local_number");

}

string PhoneNumber::GetCountryCode() const
{
	return country_code_;
}

string PhoneNumber::GetCityCode() const
{
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
