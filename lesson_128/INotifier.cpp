class INotifier
{
public:
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier
{
public:
	SmsNotifier(const string& n = "no number") : _number(n) {}
	virtual void Notify(const string& message) const override
	{
		SendSms(_number, message);
	}

private:
	const string _number;
};

class EmailNotifier : public INotifier
{
public:
	EmailNotifier(const string& em = "") : _email(em) {}
	virtual void Notify(const string& message) const override
	{
		SendEmail(_email, message);
	}
private:
	const string _email;
};
