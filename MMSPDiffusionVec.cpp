#include"MMSP.hpp"
#include<iostream>
#include<vector>
using namespace MMSP; 

// Add in Laplacian funciton that is built in to MMSP
// Try using a grid of vectors >> one iterated with this code, one with laplacian


//we start the program off the same way as before, but this time we do not need the offset length variable
int main() 
{ 
int length;
int iterate;
vector<float> VECTOR;

std::cout<<"input couple length"<<std::endl;
std::cin>>length;
std::cout<<""<<std::endl;

std::cout<<"input number of iterations"<<std::endl;
std::cin>>iterate;
std::cout<<""<<std::endl;

resize(VECTOR,length);
for (int i=0;i<length/2;i++) {
	VECTOR[i] = 1;
}

grid<1,vector<float> > GRID(length,0,length); 
grid<1,vector<float> > update(length,0,length); 

for (int x=x0(GRID); x<x1(GRID); x++) 
	if (x<length/2) { 
		GRID[x]=VECTOR;
		update[x]=VECTOR;	
	} 
	else { 
	} 

//now we set the boundary conditions of both grids.  By choosing the Dirichlet conditions, it is nearly identical to loop enforced boundaries.  
//the difference is that the first and last nodes of the grid can change, and the theoretical points outside the grid are fixed.
b0(GRID,0) = Dirichlet;
b1(GRID,0) = Dirichlet;
b0(update,0) = Dirichlet;
b1(update,0) = Dirichlet;

for (int k=0; k<iterate; k++) {
	for (int i=0; i<nodes(GRID); i++) {
//we can use MMSP's definition for laplacian instead of hard coding it.
		update(i)=0.5*laplacian(GRID,i)+GRID(i);
	}
	swap(GRID,update);
	ghostswap(GRID);
};


for (int x=x0(GRID); x<x1(GRID); x++) {
	for (int i=0; i<length; i++) {
		std::cout<<GRID[x][i];
		std::cout<<"	"; 
	}
	std::cout<<"\n";
}

Finalize(); 
} 

