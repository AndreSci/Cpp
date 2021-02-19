#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class FunctionPart
{
public:
	FunctionPart(char new_operation, double new_value)
	{
		operation = new_operation;
		value = new_value;
	}
	double Apply(double source_value) const
	{
		if (operation == '+')
		{
			return source_value + value;
		}
		else if (operation == '-')
		{
			return source_value - value;
		}
		else if (operation == '*')
		{
			return source_value * value;
		}
		else
		{
			return source_value / value;
		}
	}
	void Invers()
	{
		if (operation == '+')
		{
			operation = '-';
		}
		else if(operation == '-')
		{
			operation = '+';
		}
		else if (operation == '*')
		{
			operation = '/';
		}
		else
		{
			operation = '*';
		}
		
	}
private:
	char operation;
	double value;
};

class Function
{
public:
	void AddPart(char operation, double value)
	{
		parts.push_back({ operation, value });
	}
	double Apply(double value) const
	{
		for (const FunctionPart& part : parts)
		{
			value = part.Apply(value);
		}
		return value;
	}
	void Invert()
	{
		for (FunctionPart& part : parts)
		{
			part.Invers();
		}
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionPart> parts;
};

Function MakeWeigthFunction(const Params& param, const Image& image)
{
	Function function;
	function.AddPart('*', param.a);
	function.AddPart('-', image.freshness* param.b);
	function.AddPart('+', image.rating * param.c);
	return function;
}

double ComputeImageWeigth(const Params& param, const Image& image)
{
	Function function = MakeWeigthFunction(param, image);
	return function.Apply(image.quality);
}
double ComputeQualityByWeigth(const Params& param, const Image& image, double weigth)
{
	Function function = MakeWeigthFunction(param, image);
	function.Invert();
	return function.Apply(weigth);
}
