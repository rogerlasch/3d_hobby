


#include"gpp_physics.h"

using namespace std;

namespace gpp
{

void IntegratorVerlet::integrate(RigidBody* rb, float delta_time)
{
if((rb==NULL)||(rb->getMass()<=0)) return;
    //Atualizar velocidade linear e posi��o
vector3d displacement;
    rb->linearVelocity = rb->linearMomentum / rb->mass;
displacement= rb->linearVelocity * delta_time + 0.5f * rb->linearAcceleration * delta_time * delta_time;
    rb->position +=displacement;
    rb->linearMomentum += rb->force * delta_time;
    rb->linearVelocity = rb->linearMomentum / rb->mass;

    //Atualizar orienta��o
    rb->angularVelocity = rb->inverseInertiaTensor * rb->angularMomentum;
    quaternion deltaOrientation(0.0f, rb->angularVelocity * delta_time * 0.5f);
    deltaOrientation = deltaOrientation * rb->orientation;
    rb->orientation += deltaOrientation;
    rb->orientation.normalize();

    //Atualizar velocidade angular
    rb->angularMomentum += rb->torque * delta_time;
    rb->angularVelocity = rb->inverseInertiaTensor * rb->angularMomentum;

    //Atualizar e calcular e aplicar torque
    rb->linearAcceleration = rb->force / rb->mass;
    rb->angularAcceleration = rb->inverseInertiaTensor * rb->torque;

    rb->linearMomentum *= pow(1.0f - rb->linearDamping, delta_time);
    rb->angularMomentum *= pow(1.0f - rb->angularDamping, delta_time);

    rb->force = vector3d(0.0f, 0.0f, 0.0f);
    rb->torque = vector3d(0.0f, 0.0f, 0.0f);
rb->translate(displacement);
if(rb->getGeometricShape()!=NULL)
{
rb->getGeometricShape()->Rotate(rb->orientation);
}
}
}
