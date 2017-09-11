#include "Particle.h"
#include "Interactor.h"
#include <fstream>
#include <algorithm>
int main()
{
	//hardcoded simulation
	Particle **arr = new Particle*[3];
	arr[0] = new Interactor(Particle::Vector3D(0,0,0), Particle::Vector3D());
	arr[1] = new Interactor(Particle::Vector3D(0, 0, 1), Particle::Vector3D());
	arr[2] = new Interactor(Particle::Vector3D(1, 0, 0), Particle::Vector3D());
	std::fstream file("output.txt", std::ios::out);
	for (int i = 0; i < sizeof(arr)-1; ++i)
	{
		for (int j = 0; j < sizeof(arr)-1; ++j)
		{
			if (i != j)
				(*arr[i]) * (*arr[j]);			
		}
		file << i + 1 << ". iteration" << std::endl << std::endl;
		for (int j = 0; j < sizeof(arr) - 1; ++j)
		{
			file << j + 1 << ". particle: " << (*(arr[j])) << std::endl;
		}
	}
}