#include<iostream>
#include<string>


class figure
{
public:
	figure()
	{
		this->tri = "������:";
	}
	virtual void Tell()
	{
		std::cout << tri << std::endl;
		if (Chek()) 
		{
			std::cout << "����������" << std::endl;
			std::cout << "���������� ������: 0" << std::endl << std::endl;
		}
		else 
		{
			std::cout << "�����������" << std::endl;
			std::cout << "���������� ������: 0" << std::endl << std::endl;
		}
	}

	virtual bool Chek()
	{
		return 1;
	}

protected:
	std::string tri;
};

// �����������
class triangle :public figure
{
public:
	triangle()
	{
	}
	triangle(int a, int A) // ��������������
	{
		this->a = a;
		this->b = a;
		this->c = a;
		this->A = A;
		this->B = A;
		this->C = A;
		this->tri = "�������������� �����������:";
	}
	triangle(int a, int c, double A) //��������������
	{
		this->a = a;
		this->b = a;
		this->c = c;
		this->A = A;
		this->B = (180 - A) / 2;
		this->C = B;
		this->tri = "�������������� �����������:";
	}
	triangle(int a, int b, int c, int A, int B)  // �������������
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = 90;
		this->tri = "������������� �����������:";
	}
	triangle(int a, int b, int c, int A, int B, int C)  // �����������
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->tri = "T����������:";
	}

	void Tell()override
	{
		std::cout << tri << std::endl;
		if (Chek())
		{
			std::cout << "����������" << std::endl;
			std::cout << "���������� ������: 3" << std::endl;
		}
		else
		{
			std::cout << "������������" << std::endl;
			std::cout << "���������� ������: 3" << std::endl;
		}
		std::cout << stor << "a = " << a << "  " << "b = " << b << "  " << "c = " << c << std::endl;
		std::cout << ugl << "A = " << A << "  " << "B = " << B << "  " << "C = " << C << std::endl << std::endl;
	}

	bool Chek()override
	{
		if (A + B + C == 180){ return 1; }
		else { return 0; }
	}
	
protected:
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	std::string tri;
	std::string stor = "�������:\t";
	std::string ugl = "����:\t\t";
};

// ��������������
class equilateral :public triangle
{
public:

	equilateral(int a, int A) :triangle(a, A)
	{
	}
	bool Chek()override
	{
		if (triangle::Chek())
		{
			if (a == b || b == c) { return 1; }
		}
		else { return 0; }
	}

};

// �������������
class rectangular :public triangle
{
public:

	rectangular(int a, int b, int c, int A, int B) :triangle(a, b, c, A, B)
	{
	}
	bool Chek()override
	{
		if (triangle::Chek())
		{
			if (A == 90 || B == 90 || C == 90) { return 1; }
		}
		else { return 0; }
	}
};

// ��������������
class isosceles :public triangle
{
public:

	isosceles(int a, int c, int A) :triangle(a, c, A)
	{

	}
	bool Chek()override
	{
		if (triangle::Chek())
		{
			if (a == c || a == b) { return 1; }
		}
		else { return 0; }
	}
};

// ���������������
class quadrilateral :public figure
{
public:
	quadrilateral()
	{
	}
	quadrilateral(int a)// �������
	{


		this->tri = "�������:";
	}
	quadrilateral(int a, int b)// �������������
	{
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;
		this->tri = "�������������:";
	}
	quadrilateral(int a, int A, int B)// ����
	{
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->tri = "����:";
	}
	quadrilateral(int a, int b, int A, int B)// ��������������
	{
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->tri = "��������������:";
	}
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
		this->tri = "���������������:";
	}
	void Tell()override
	{
		std::cout << tri << std::endl;
		if (Chek())
		{
			std::cout << "����������" << std::endl;
			std::cout << "���������� ������: 4" << std::endl;
		}
		else
		{
			std::cout << "������������" << std::endl;
			std::cout << "���������� ������: 4" << std::endl;
		}
		std::cout << stor << "a = " << a << "  " << "b = " << b << "  " << "c = " << c << " " << "d = " << d << std::endl;
		std::cout << ugl << "A = " << A << "  " << "B = " << B << "  " << "C = " << C << " " << "D = " << D << std::endl << std::endl;
	}

	bool Chek()override
	{
		if (A + B + C + D == 360) { return 1; }
		else { return 0; }
	}

protected:
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	std::string tri;
	std::string stor = "�������:\t";
	std::string ugl = "����:\t\t";
};

// �������������
class rectangle :public quadrilateral
{
public:

	rectangle(int a, int b) :quadrilateral(a, b)
	{

	}
	bool Chek()override
	{
		if (quadrilateral::Chek())
		{
			if (a == c && b == d) { return 1; }
		}
		else { return 0; }
	}
};

// �������
class square :public quadrilateral
{
public:
	square(int a) :quadrilateral(a)
	{
	}
	bool Chek()override
	{
		if (quadrilateral::Chek())
		{
			if (a == b && b == c && c == d) { return 1; }
		}
		else { return 0; }
	}
};

// ��������������
class parallellogram :public quadrilateral
{
public:
	parallellogram(int a, int b, int A, int B) :quadrilateral(a, b, A, B)
	{
	}
	bool Chek()override
	{
		if (quadrilateral::Chek())
		{
			if (a == c && b == d) { return 1; }
		}
		else { return 0; }
	}
};

// ����
class rhomb :public quadrilateral
{
public:
	rhomb(int a, int A, int B) :quadrilateral(a, A, B)
	{
	}
	bool Chek()override
	{
		if (quadrilateral::Chek())
		{
			if (a == b && b == c && c == d) { return 1; }
		}
		else { return 0; }
	}
};

int main() {

	setlocale(LC_ALL, "Russian");


	figure j;
	j.Tell();


	// �����������
	triangle q(2, 2, 2, 50, 60, 70);
	q.Tell();


	// ��������������
	equilateral a(4, 60);
	a.Tell();

	// �������������
	rectangular b(3, 4, 5, 60, 30);
	b.Tell();


	// ��������������
	isosceles c(22, 10, 45);
	c.Tell();

	// ���������������
	quadrilateral d(44, 44, 44, 44, 80, 100, 80, 100);
	d.Tell();

	// �������������
	rectangle e(500, 400);
	e.Tell();

	// �������
	square m(1000);
	m.Tell();

	// ��������������
	parallellogram n(10, 10, 70, 110);
	n.Tell();

	// ����
	rhomb v(35, 10, 170);
	v.Tell();


}

