

#include"../common.h"
#include"../gpp_physics.h"
#include"CollisionSolver.h"

using namespace std;

namespace gpp
{

void CollisionSolver::solve(vector<CollisionInfo>& collisions)
{
for(auto it=collisions.begin(); it!=collisions.end(); ++it)
{
this->solvePair(*it);
}
}

void CollisionSolver::solvePair(CollisionInfo& info)
{
}
}