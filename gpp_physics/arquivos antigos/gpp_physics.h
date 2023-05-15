

/**
*Header principal que inclui todos os arquivos da biblioteca.
**/
#ifndef GPP_PHYSICS_H
#define GPP_PHYSICS_H

#include<algorithm>
#include<atomic>
#include<functional>
#include<map>
#include<unordered_map>
#include<mutex>
#include<shared_mutex>
#include<string>
#include<vector>
#ifndef GPP_DEBUG_SYSTEM_H
#include<gpp/debug_system.h>
#endif
#include"types.h"
#include"gpp_index.h"
#include"geometry/geometry.h"
#include"interfaces/interfaces.h"
#include"IndexTable.h"
#include"RigidBody.h"
#include"IntegratorVerlet.h"
#include"BinaryUtils.h"
#include"octree.h"
#include"BroadPhase.h"
#include"NarrowPhase.h"
#include"CollisionSolver.h"
#include"gpp_world.h"

#endif