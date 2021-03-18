class Operand
{
public:
	Operand(char operation, double value)
	{
		this->operation = operation;
		this->value = value; 
	}
	void change_signs()
	{
		if (this->operation == '+')
		{
			this->operation = '-';
		}
		else if (this->operation == '*')
                {
                        this->operation = '/';
                }
		else if (this->operation == '/')
                {
                        this->operation = '*';
                }
		else
		{
			this->operation = '+';
		}
	}
	char getOperation() const
	{
		return this->operation;
	}
	double getValue() const
	{
		return this->value;
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
		operations.push_back(Operand(operation, value));
	}
	void Invert()
	{
		for (auto & item : operations)
		{
			item.change_signs();
		}
		reverse(operations.begin(), operations.end());
	}
	double Apply(double value) const
	{
		for (auto & item : operations)
		{
			if (item.getOperation() == '+')
			{
				value += item.getValue();
			}
			else if (item.getOperation() == '*')
			{
				value *= item.getValue();
			}
			else if (item.getOperation() == '/')
			{
				value /= item.getValue();
			}
			else
			{
				value -= item.getValue();
			}
		}
		return value;
	}
private:
	std::vector<Operand> operations;
};
