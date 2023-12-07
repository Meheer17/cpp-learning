// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction
{
	int numerator {};
	int denominator {};
};

// Now we can make use of our Fraction type
int main()
{
	Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f

	return 0;
}