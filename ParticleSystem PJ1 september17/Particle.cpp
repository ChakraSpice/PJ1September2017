#include "Particle.h"
#include <cmath>


Particle::Particle(Vector3D position, Vector3D speed, long double mass) noexcept : position(position), speed(speed), mass(mass), acceleration() {}


Particle::~Particle()
{
}

long double Particle::getMass() const noexcept
{
	return mass;
}

typename Particle::Vector3D Particle::getPosition() const noexcept
{
	return position;
}

typename Particle::Vector3D Particle::getSpeed() const noexcept
{
	return speed;
}

typename Particle::Vector3D Particle::getAcceleration() const noexcept
{
	return acceleration;
}

void Particle::update() noexcept
{/* bez +=
	Vector3D tmp = speed = speed + acceleration;
	position = tmp;
	acceleration = Vector3D();*/
	speed += acceleration;
	position += speed;
	acceleration = Vector3D();
}

void Particle::addForce(const Vector3D& forceVector) noexcept
{
	acceleration = acceleration + forceVector / mass;
}

void Particle::print(std::ostream& stream) const noexcept
{
	stream << "Mass: " << getMass() << "\n";
	stream << "Position: " << position << std::endl;
	stream << "Speed: " << speed << std::endl;
}

typename Particle::Vector3D Particle::Vector3D::applyOperation(const Vector3D & other, std::function<double(double, double)> operation) const noexcept
{
	return Vector3D(operation(x, other.x), operation(y, other.y), operation(z, other.z));
}

Particle::Vector3D::Vector3D(double x, double y, double z) noexcept : x(x), y(y), z(z) {};

double Particle::Vector3D::operator!() const noexcept
{
	return sqrt(x*x + y*y + z*z);
}

typename Particle::Vector3D Particle::Vector3D::operator+(const Vector3D &other) const noexcept
{
	return Particle::Vector3D::applyOperation(other, [](double a, double b) { return a + b; });
	//drugi nacin
	// return Particle::Vector3D(x+other.x, y + other.y, z+other.z);
}

typename Particle::Vector3D Particle::Vector3D::operator-(const Vector3D & other) const noexcept
{
	return Particle::Vector3D::applyOperation(other, [](double a, double b) { return a - b; });
	//drugi nacin 
	//return Particle::Vetor3D(x-other.x, y-other.y, z-other.z);
}

typename Particle::Vector3D Particle::Vector3D::operator/(const long double number) const noexcept
{
	return Vector3D(x/number, y/number, z/number);
}

typename Particle::Vector3D Particle::Vector3D::operator*(const long double number) const noexcept
{
	return Vector3D(x*number, y*number, z*number);
}

double Particle::Vector3D::getX() const noexcept
{
	return x;
}
double Particle::Vector3D::getY() const noexcept
{
	return y;
}double Particle::Vector3D::getZ() const noexcept
{
	return z;
}
std::ostream& operator<<(std::ostream& stream, const Particle::Vector3D object) noexcept
{
	stream << "(" << object.x << ", "<< object.y << ", " << object.z << ") " << std::endl;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Particle& object) noexcept
{
	object.print(stream);
	return stream;
}

