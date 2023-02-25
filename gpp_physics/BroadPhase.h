
/**
*Classe que implementa o algoritmo de broadphase do nosso simulador.
*Nesta fase, dada uma lista de corpos, o objetivo � retornar uma lista com todos os pares que possivelmente estejam colidindo.
*Nesta etapa, um teste de sobreposi��o aabb x aabb � feito.
*Caso uma sobreposi��o seja detectada, o par de corpos � adicionado a lista de sa�da para uma verifica��o mais precisa e de geometria no algoritmo contido na classe NarrowPhase.
**/

#ifndef BROADPHASE_H
#define BROADPHASE_H


namespace gpp
{

typedef std::pair<RigidBody*, RigidBody*> CollisionPair;
typedef std::vector<CollisionPair> CollisionPairList;
class BroadPhase
{
public:
void scan(const RigidBodyList& bodies, CollisionPairList& collisions);
void scan(const RigidBodyList& bodies, CollisionPairList& collisions, std::shared_mutex& m);
};
}
#endif
