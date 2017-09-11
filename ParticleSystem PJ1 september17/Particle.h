#pragma once
#include <vector>
#include <functional>
#include <iostream>
class Particle
{
	public:
	class Vector3D
	{
		double x;
		double y;
		double z;
		Vector3D applyOperation(const Vector3D&, std::function<double(double, double)>) const noexcept;
		friend Particle;
	public:
		Vector3D(double x = 0, double y = 0, double z = 0) noexcept;
		//Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {};
		double operator!() const noexcept;
		Vector3D operator+(const Vector3D&) const noexcept;
		Vector3D operator-(const Vector3D&) const noexcept;
		Vector3D operator/(const long double) const noexcept;//assume the user is not an idiot, won't divide by zero, TODO: implement divison by zero exception
		Vector3D operator*(const long double) const noexcept;
		Vector3D operator+=(const Vector3D& other) noexcept
		{
			Vector3D tmp = other + *this;
			*this = tmp;
			return *this;
		}
		friend std::ostream& operator<<(std::ostream&, const Particle::Vector3D) noexcept; //trouble
		//getters
		double getX() const noexcept;
		double getY() const noexcept;
		double getZ() const noexcept;
	};
	Particle(Vector3D, Vector3D, long double) noexcept;
	virtual ~Particle();

	//getters
	long double getMass() const noexcept;
	Vector3D getPosition() const noexcept;
	Vector3D getSpeed() const noexcept;
	Vector3D getAcceleration() const noexcept;

	//methods
	void update() noexcept;
	virtual void operator*(Particle&) noexcept = 0; //1.2 Impossible to instantiate, the class has a purely virtual function

	//1.3 The operator*(...) is not so good, as it could have been if it were static, 
	//but it couldn't be virtual then. It is used on two objects, and changes both of them
	friend std::ostream& operator<<(std::ostream&, const Particle&) noexcept;
	virtual void addForce(const Vector3D&) noexcept; //1.1 metoda treba biti privatna, tj. protected - zasticena, jer se samo iz metoda poziva, bug??
protected:
	long double mass;
	Vector3D position;
	Vector3D speed;
	Vector3D acceleration;
	//methods
	virtual void print(std::ostream&) const noexcept;
};

