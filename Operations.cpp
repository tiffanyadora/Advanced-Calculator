class Operations
{
	public:
		double ToRad(double Degrees); //converts the degree input into radians
		double Sine(double Degrees); //does sine operations
		double Cosine(double Degrees); //does cosine operations
		double Tangent(double Degrees); //does tangent operations
		double SquareRoot(double Number); //does square root operations
		double Exponent(double Number, double Power); //does exponent operations
		double Logarithm(double Number); //does logarithm operations
		double NaturalLog(double Number); //does natural logarithm operations
		
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

double Operations::Sine(double Degrees)
{
	degree = Degrees;
	radians = ToRad(degree);
	ans = sin(radians);
	return ans;
}

double Operations::Cosine(double Degrees)
{
	degree = Degrees;
	radians = ToRad(degree);
	ans = cos(radians);
	return ans;
}

double Operations::Tangent(double Degrees)
{
	degree = Degrees;
	radians = ToRad(degree);
	ans = tan(radians);
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
