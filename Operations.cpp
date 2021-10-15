#include <cmath>

class Operations
{
	public:
		double ToRad(double Degrees); //function that converts the degree input into radians
		double Sine(double Radians); //function that does sine operations
		double Cosine(double Radians); //function that does cosine operations
		double Tangent(double Radians); //function that does tangent operations
		double SquareRoot(double Number); //function that does square root operations
		double Exponent(double Number, double Power); //function that does exponent operations
		double Logarithm(double Number); //fucntion that does logarithm operations
		double NaturalLog(double Number); //function that does natural logarithm operations
		
	private:
		double degree;
		double radians;
		double ans;
		double num;
		double power;
};

double Operations::ToRad(double Degrees)
{
	degree = Degrees;
	radians = (degree * 3.1415926535) / 180;
	return radians;
}

double Operations::Sine(double Radians)
{
	ans = sin(Radians);
	return ans;
}

double Operations::Cosine(double Radians)
{
	ans = cos(Radians);
	return ans;
}

double Operations::Tangent(double Radians)
{
	ans = tan(Radians);
	return ans;
}

double Operations::SquareRoot(double Number)
{
	num = Number;
	ans = sqrt(num);
	return ans;
}

double Operations::Exponent(double Number, double Power)
{
	num = Number;
	power = Power;
	ans = pow(num, power);
	return ans;
}

double Operations::Logarithm(double Number)
{
	num = Number;
	ans = log10(num);
	return ans;
}

double Operations::NaturalLog(double Number)
{
	num = Number;
	ans = log(num);
	return ans;
}
