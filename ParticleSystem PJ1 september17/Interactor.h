#pragma once
#include "Particle.h"
class Interactor : public Particle
{
	const static long double scalar = 666e3; //self-defined constant, have some fun
public:
	Interactor(Vector3D position, Vector3D speed) noexcept;
	virtual ~Interactor();
	//methods
	virtual void operator*(Particle& other) noexcept override //this operation is commutative  
	{
		if (this != &other)
		{ 
			Vector3D distanceVector = (this->getPosition()) - other.getPosition();
			long double distance = !distanceVector;
			distanceVector = distanceVector / distance; //normalization
			long double scaling = (scalar * other.getMass() * (this->getMass())) / (distance*distance);
			Vector3D force = distanceVector * scaling;
			this->addForce(force);
			this->update();
			force = force * (-1);
			other.addForce(force);
			other.update();
		}	
	}
};

