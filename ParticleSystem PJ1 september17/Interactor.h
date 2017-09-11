#pragma once
#include "Particle.h"
class Interactor : public Particle
{
	const long double scalar = 666; //self-defined constant, have some fun
public:
	Interactor(Vector3D position, Vector3D speed) noexcept;
	virtual ~Interactor();
	//methods
	virtual void operator*(Particle& other) noexcept override //this operation is commutative  
	{
		Vector3D force;
		Vector3D distanceVector = (this->getPosition()) - other.getPosition();
		long double distance = !distanceVector;
		distanceVector = distanceVector / distance; //normalization
		long double scaling = (scalar * other.getMass() * (this->getMass())) / (distance*distance);
		force = distanceVector * scaling;
		this->addForce(force);
		this->update();
		force = force * (-1);
		other.addForce(force);
		other.update();
	}
};

