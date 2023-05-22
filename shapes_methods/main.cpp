#include<iostream>
#include<string>

//Треугольник:
//Правильная
//Количество сторон : 3
//Стороны : a = 10 b = 20 c = 30
//Углы : A = 50 B = 60 C = 70

class figure
{
public:
	figure()
	{
	}
	virtual void print_info()
	{
		std::cout << std::endl << name << std::endl;
		if (z) {
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Не правильная" << std::endl;
		}
		std::cout << "Количество сторон: " << number << std::endl;  
	}
	private:
		bool z = 1;
		int number = 0;
		std::string name = "Фигура";
};

// треугольник
class triangle:public figure
{
public:

	triangle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	    	if (A + B + C == 180) { z = 1; }
		    else
		    {
			z = 0;
		    }
	}
	void print_info()override
	{
		std::cout << std::endl << name << std::endl;
		if (z) {
			std::cout << "Правильная" << std::endl;
		}
		else
		{
			std::cout << "Не правильная" << std::endl;
		}
	
		std::cout << "Количество сторон: " << number << std::endl;
		std::cout << "Стороны: " << std::endl << a << " " << b << " " << c << std::endl
			      << "Углы: " << std::endl << A << " " << B << " " << C << std::endl;
	}
	

private:
	
	int a = 0;
	int b = 0;
	int c = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int number = 3;
	std::string name = "Треугольник";
	bool z = 0;
};

// равносторонний
class equilateral :public triangle
{
public:
	equilateral(int a, int b, int c, int A, int B, int C) :triangle(a, b, c, A, B, C)
	{
	}
	void print_info()override
	{
		
	}
private:
	bool z = 0;
	int number = 3;
	std::string name = "Равносторонний треугольник";

};
// прямоугольный
class rectangular :public equilateral
{
public:

	rectangular(int a, int b, int c, int A, int B, int C) :equilateral(a, b, c, A, B, C)
	{

	}
private:
	int number = 3;
	std::string name = "Прямоугольный треугольник";
};

// равнобедренный
class isosceles :public rectangular
{
public:
	isosceles(int a, int b, int c, int A, int B, int C) :rectangular(a, b, c, A, B, C)
	{
	}
private:
	int number = 3;
	std::string name = "Равнобедренный треугольник";
};

// четырехугольник
class quadrilateral :public figure
{
public:
	
	quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
		void Tell2()
		{
			std::cout << "Стороны: " << std::endl << a << " " << b << " " << c << " " << d << std::endl
				      << "Углы: " << std::endl << A << " " << B << " " << C << " " << D << std::endl;
		}

private:
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int number = 4;
	std::string name = "Четырехугольник";
};

// прямоугольник
class rectangle :public quadrilateral
{
public:

	rectangle(int a, int b, int c, int d, int A, int B, int C, int D) :quadrilateral(a, b, c, d, A, B, C, D)
	{

	}
private:
	int number = 4;
	std::string name = "Прямоугольник";
};

// квадрат
class square :public rectangle
{
public:
	square(int a, int b, int c, int d, int A, int B, int C, int D) :rectangle(a, b, c, d, A, B, C, D)
	{

	}
private:
	int number = 4;
	std::string name = "Квадрат";
};

// паралеллограмм
class parallellogram :public square
{
public:
	parallellogram(int a, int b, int c, int d, int A, int B, int C, int D) :square(a, b, c, d, A, B, C, D)
	{

	}
private:
	int number = 4;
	std::string name = "Паралеллограмм";
};

// ромб
class rhomb :public parallellogram
{
public:
	rhomb(int a, int b, int c, int d, int A, int B, int C, int D) :parallellogram(a, b, c, d, A, B, C, D)
	{

	}
private:
	int number = 4;
	std::string name = "Ромб";
};




int main() {

	setlocale(LC_ALL, "Russian");


	/*triangle q(1, 2, 1, 2, 1, 2);
	std::cout << "Треугольник" << std::endl;
	q.Tell();

	equilateral p(10, 10, 10, 60, 60, 60);
	std::cout << "Равносторонний треугольник" << std::endl;
	p.Tell();

	rectangular m(55, 66, 77, 88, 99, 11);
	std::cout << "Прямоугольный треугольник" << std::endl;
	m.Tell();

	isosceles e(30, 30, 20, 45, 60, 60);
	std::cout << "Равнобедренный треугольник" << std::endl;
	e.Tell();

	quadrilateral g(4, 4, 4, 4, 45, 45, 45, 45);
	std::cout << std::endl << "Четырехугольник" << std::endl;
	g.Tell2();

	rectangle d(55, 40, 55, 40, 90, 90, 90, 90);
	std::cout << "Прямоугольник" << std::endl;
	d.Tell2();

	square a(8, 8, 8, 8, 90, 90, 90, 90);
	std::cout << "Квадрат" << std::endl;
	a.Tell2();

	parallellogram s(234, 234, 230, 230, 45, 50, 45, 50);
	std::cout << "Параллеллограмм" << std::endl;
	s.Tell2();

	rhomb l(5, 5, 5, 5, 40, 50, 40, 50);
	std::cout << "Ромб" << std::endl;
	l.Tell2();*/

	//figure gg;
	//gg.print_info();

	//triangle cc(1, 2, 1, 60, 60, 60);
	//cc.print_info();

	equilateral aaaa(8, 8, 8, 60, 60, 60);
	aaaa.print_info();

















}
