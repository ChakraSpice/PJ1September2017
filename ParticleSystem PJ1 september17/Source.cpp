#include "Particle.h"
#include "Interactor.h"
#include <fstream>
#include <algorithm>
int main()
{
	//hardcoded simulation
	Particle **arr = new Particle*[3];
	arr[0] = new Interactor(Particle::Vector3D(1, 1, 1), Particle::Vector3D());
	arr[1] = new Interactor(Particle::Vector3D(-3, 1, 4), Particle::Vector3D());
	arr[2] = new Interactor(Particle::Vector3D(5, 3, 2), Particle::Vector3D());
	std::fstream file("output.txt", std::ios::out);
	/*for (int i = 0; i < sizeof(arr)-1; ++i)
	{
		for (int j = 0; j < sizeof(arr)-1; ++j)
		{
			if (i != j)
				(*arr[i]) * (*arr[j]);			
		}
		file << i + 1 << ". iteration" << std::endl;
		i = 1;
		for (int j = 0; j < sizeof(arr) - 1; ++j)
		{
			file << j + 1 << ". particle: " << arr[j] << std::endl;
		}
		/*std::for_each(arr, arr + sizeof(arr)-1, 
		[&i, &file](const Particle* particle) //example of lambda function capture mechanism
			{
			file << i << ". particle:" << (particle);
			});*/
	//} TODO: output, too tired right now, plough it, some loop is wrong, whatever
}