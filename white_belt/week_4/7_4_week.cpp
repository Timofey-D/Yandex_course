#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <exception>
using namespace std;

class Rational {
public:
   	 Rational() {
		this->numerator = 0;
		this->denominator = 1;
    	}

    	Rational(int numerator, int denominator) {
    		int gcd = std::gcd(numerator, denominator);
		if (denominator == 0)
		{
			throw invalid_argument("Invalid argument");
		}
		if (numerator == 0)
		{
			this->numerator = 0;
			this->denominator = 1; 
		}
		else if (numerator < 0 && denominator > 0)
		{
			this->numerator = denominator > 0 ? numerator / gcd : ((numerator / gcd) * -1);
			this->denominator = denominator > 0 ? denominator / gcd : ((denominator / gcd) * -1);
		}
		else
		{
			this->numerator = denominator < 0 ? (numerator / gcd) * -1 : numerator / gcd;
                        this->denominator = denominator < 0 ? (denominator / gcd) * -1 : denominator / gcd;
		}
	}
    	int Numerator() const
	{
   		return this->numerator;
	}

    	int Denominator() const
	{
		return this-> denominator;
    	}
private:
	int numerator;
	int denominator;
};
        bool operator==(const Rational& left, const Rational& right)
        {
                if (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator())
                {
                        return 1;
                }
                return 0;
        }
        Rational operator+(const Rational& left, const Rational& right)
        }
                int n_l = left.Numerator();
                int n_r = right.Numerator();
                int d_l = left.Denominator();
                int d_r = right.Denominator();

                int res_n;
                int res_d;

                if (left.Denominator() == right.Denominator())
                {
                        res_n = left.Numerator() + right.Numerator();
                        res_d = left.Denominator();
                        return Rational(res_n, res_d);
                }
                else
                {
                        d_l = left.Denominator() * right.Denominator();
                        d_r = right.Denominator() * left.Denominator();

                        n_l = left.Numerator() * right.Denominator();
                        n_r = right.Numerator() * left.Denominator();

                        res_n = n_l + n_r;
                        res_d = d_l;

                        return Rational(res_n, res_d);
                }
        }
        Rational operator-(const Rational& left, const Rational& right)
        {
                int n_l = left.Numerator();
                int n_r = right.Numerator();
                int d_l = left.Denominator();
                int d_r = right.Denominator();

                int res_n;
                int res_d;

                if (left.Denominator() == right.Denominator())
                {
                        res_n = left.Numerator() - right.Numerator();
                        res_d = left.Denominator();
                        return Rational(res_n, res_d);
                }
                else
                {
                        d_l = left.Denominator() * right.Denominator();
                        d_r = right.Denominator() * left.Denominator();

                        n_l = left.Numerator() * right.Denominator();
                        n_r = right.Numerator() * left.Denominator();

                        res_n = n_l - n_r;
                        res_d = d_l;

                        return Rational(res_n, res_d);
                }
        }

Rational operator*(const Rational& left, const Rational& right)
{
        int res_n;
        int res_d;

        res_n = left.Numerator() * right.Numerator();
        res_d = left.Denominator() * right.Denominator();

        return Rational(res_n, res_d); } Rational operator/(const Rational& left, const Rational& right) { if (right.Numerator() == 0) { throw domain_error("Division by zero"); }
        int res_n;
        int res_d;

        res_n = left.Numerator() * right.Denominator();
        res_d = left.Denominator() * right.Numerator();

        return Rational(res_n, res_d); }


ostream& operator<<(ostream& out, const Rational& value)
{
	return out << value.Numerator() << "/" << value.Denominator();
}
istream& operator>>(istream& in, Rational& value) { int N, D; char sym;

	if (in)
	{
		in >> N >> sym >> D;
		if (in)
		{
			if (sym == '/')
			{
				value = Rational(N, D);
			}
			else
			{
				in.setstate(ios_base::failbit);
			}
		}
	}
			
	return in;
}


bool operator<(const Rational& left, const Rational& right)
{
	int l_num = left.Numerator();
	int r_num = right.Numerator();

	if (left.Denominator() < right.Denominator())
	{
		l_num *= right.Denominator();
		r_num *= left.Denominator();
	}
	else
	{
		l_num *= right.Denominator();
		r_num *= left.Denominator();
	}

	return l_num < r_num;
}

int main() {
	Rational n1;
	char sym;
	Rational n2;
	Rational res;

	try
	{
		cin >> n1 >> sym >> n2;
		if (sym == '+')
		{
			res = n1 + n2;	
		}
		else if (sym == '-')
		{
			res = n1 - n2;
		}
		else if (sym == '*')
		{
			res = n1 * n2;
		}
		else if (sym == '/')
		{
			res = n1 / n2;
		}
		cout << res << endl;
	} catch (invalid_argument& error_1)
	{
		cout << error_1.what() << endl;
	} catch (domain_error& error_2)
	{
		cout << error_2.what() << endl;
	}

    return 0;
}

