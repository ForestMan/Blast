// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2020 NVIDIA Corporation. All rights reserved.

// This file was generated by NvParameterized/scripts/GenParameterized.pl


#ifndef HEADER_DestructibleActorState_h
#define HEADER_DestructibleActorState_h

#include "NvParametersTypes.h"

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
#include "nvparameterized/NvParameterized.h"
#include "nvparameterized/NvParameterizedTraits.h"
#include "NvParameters.h"
#include "NvTraitsInternal.h"
#endif

namespace nvidia
{
namespace destructible
{

#if PX_VC
#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())
#endif

namespace DestructibleActorStateNS
{

struct GroupsMask_Type;
struct ShapeDescFlags_Type;
struct ShapeDescTemplate_Type;
struct ContactPairFlag_Type;
struct ActorDescFlags_Type;
struct ActorDescTemplate_Type;
struct BodyDescFlags_Type;
struct BodyDescTemplate_Type;
struct DestructibleDepthParameters_Type;
struct DestructibleParametersFlag_Type;
struct FractureGlass_Type;
struct FractureVoronoi_Type;
struct FractureAttachment_Type;
struct RuntimeFracture_Type;
struct DestructibleParameters_Type;
struct DamageSpreadFunction_Type;

struct DestructibleDepthParameters_Type
{
	bool OVERRIDE_IMPACT_DAMAGE;
	bool OVERRIDE_IMPACT_DAMAGE_VALUE;
	bool IGNORE_POSE_UPDATES;
	bool IGNORE_RAYCAST_CALLBACKS;
	bool IGNORE_CONTACT_CALLBACKS;
	bool USER_FLAG_0;
	bool USER_FLAG_1;
	bool USER_FLAG_2;
	bool USER_FLAG_3;
};
struct GroupsMask_Type
{
	bool useGroupsMask;
	uint32_t bits0;
	uint32_t bits1;
	uint32_t bits2;
	uint32_t bits3;
};
struct DestructibleParametersFlag_Type
{
	bool ACCUMULATE_DAMAGE;
	bool DEBRIS_TIMEOUT;
	bool DEBRIS_MAX_SEPARATION;
	bool CRUMBLE_SMALLEST_CHUNKS;
	bool ACCURATE_RAYCASTS;
	bool USE_VALID_BOUNDS;
	bool CRUMBLE_VIA_RUNTIME_FRACTURE;
};
struct ShapeDescFlags_Type
{
	bool NX_TRIGGER_ON_ENTER;
	bool NX_TRIGGER_ON_LEAVE;
	bool NX_TRIGGER_ON_STAY;
	bool NX_SF_VISUALIZATION;
	bool NX_SF_DISABLE_COLLISION;
	bool NX_SF_FEATURE_INDICES;
	bool NX_SF_DISABLE_RAYCASTING;
	bool NX_SF_POINT_CONTACT_FORCE;
	bool NX_SF_FLUID_DRAIN;
	bool NX_SF_FLUID_DISABLE_COLLISION;
	bool NX_SF_FLUID_TWOWAY;
	bool NX_SF_DISABLE_RESPONSE;
	bool NX_SF_DYNAMIC_DYNAMIC_CCD;
	bool NX_SF_DISABLE_SCENE_QUERIES;
	bool NX_SF_CLOTH_DRAIN;
	bool NX_SF_CLOTH_DISABLE_COLLISION;
	bool NX_SF_CLOTH_TWOWAY;
	bool NX_SF_SOFTBODY_DRAIN;
	bool NX_SF_SOFTBODY_DISABLE_COLLISION;
	bool NX_SF_SOFTBODY_TWOWAY;
};
struct ShapeDescTemplate_Type
{
	ShapeDescFlags_Type flags;
	uint16_t collisionGroup;
	GroupsMask_Type groupsMask;
	uint16_t materialIndex;
	float density;
	float skinWidth;
	uint64_t userData;
	uint64_t name;
};
struct FractureGlass_Type
{
	uint32_t numSectors;
	float sectorRand;
	float firstSegmentSize;
	float segmentScale;
	float segmentRand;
};
struct DamageSpreadFunction_Type
{
	float minimumRadius;
	float radiusMultiplier;
	float falloffExponent;
};
struct FractureVoronoi_Type
{
	physx::PxVec3 dimensions;
	uint32_t numCells;
	float biasExp;
	float maxDist;
};
struct ContactPairFlag_Type
{
	bool NX_IGNORE_PAIR;
	bool NX_NOTIFY_ON_START_TOUCH;
	bool NX_NOTIFY_ON_END_TOUCH;
	bool NX_NOTIFY_ON_TOUCH;
	bool NX_NOTIFY_ON_IMPACT;
	bool NX_NOTIFY_ON_ROLL;
	bool NX_NOTIFY_ON_SLIDE;
	bool NX_NOTIFY_FORCES;
	bool NX_NOTIFY_ON_START_TOUCH_FORCE_THRESHOLD;
	bool NX_NOTIFY_ON_END_TOUCH_FORCE_THRESHOLD;
	bool NX_NOTIFY_ON_TOUCH_FORCE_THRESHOLD;
	bool NX_NOTIFY_CONTACT_MODIFICATION;
};
struct BodyDescFlags_Type
{
	bool NX_BF_DISABLE_GRAVITY;
	bool NX_BF_FILTER_SLEEP_VEL;
	bool NX_BF_ENERGY_SLEEP_TEST;
	bool NX_BF_VISUALIZATION;
};
struct BodyDescTemplate_Type
{
	BodyDescFlags_Type flags;
	float wakeUpCounter;
	float linearDamping;
	float angularDamping;
	float maxAngularVelocity;
	float CCDMotionThreshold;
	float sleepLinearVelocity;
	float sleepAngularVelocity;
	uint32_t solverIterationCount;
	float sleepEnergyThreshold;
	float sleepDamping;
	float contactReportThreshold;
};
struct FractureAttachment_Type
{
	bool posX;
	bool negX;
	bool posY;
	bool negY;
	bool posZ;
	bool negZ;
};
struct RuntimeFracture_Type
{
	const char* RuntimeFractureType;
	bool sheetFracture;
	uint32_t depthLimit;
	bool destroyIfAtDepthLimit;
	float minConvexSize;
	float impulseScale;
	FractureGlass_Type glass;
	FractureVoronoi_Type voronoi;
	FractureAttachment_Type attachment;
};
struct DestructibleParameters_Type
{
	float damageCap;
	float forceToDamage;
	float impactVelocityThreshold;
	uint32_t minimumFractureDepth;
	int32_t impactDamageDefaultDepth;
	int32_t debrisDepth;
	uint32_t essentialDepth;
	float debrisLifetimeMin;
	float debrisLifetimeMax;
	float debrisMaxSeparationMin;
	float debrisMaxSeparationMax;
	float debrisDestructionProbability;
	physx::PxBounds3 validBounds;
	float maxChunkSpeed;
	DestructibleParametersFlag_Type flags;
	float fractureImpulseScale;
	uint16_t damageDepthLimit;
	uint16_t dynamicChunkDominanceGroup;
	GroupsMask_Type dynamicChunksGroupsMask;
	RuntimeFracture_Type runtimeFracture;
	float supportStrength;
	int8_t legacyChunkBoundsTestSetting;
	int8_t legacyDamageRadiusSpreadSetting;
	bool alwaysDrawScatterMesh;
};
struct ActorDescFlags_Type
{
	bool NX_AF_DISABLE_COLLISION;
	bool NX_AF_DISABLE_RESPONSE;
	bool NX_AF_LOCK_COM;
	bool NX_AF_FLUID_DISABLE_COLLISION;
	bool NX_AF_CONTACT_MODIFICATION;
	bool NX_AF_FORCE_CONE_FRICTION;
	bool NX_AF_USER_ACTOR_PAIR_FILTERING;
};
struct ActorDescTemplate_Type
{
	ActorDescFlags_Type flags;
	float density;
	uint16_t actorCollisionGroup;
	uint16_t dominanceGroup;
	ContactPairFlag_Type contactReportFlags;
	uint16_t forceFieldMaterial;
	uint64_t userData;
	uint64_t name;
	uint64_t compartment;
};

struct ParametersStruct
{

	bool enableCrumbleEmitter;
	bool enableDustEmitter;
	uint32_t lod;
	bool forceLod;
	DestructibleParameters_Type destructibleParameters;
	uint64_t userData;
	NvParameterized::Interface* actorParameters;
	NvParameterized::Interface* actorChunks;

};

static const uint32_t checksum[] = { 0xc6984ee8, 0x0dae2202, 0x4f638ad1, 0x24536329, };

} // namespace DestructibleActorStateNS

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
class DestructibleActorState : public NvParameterized::NvParameters, public DestructibleActorStateNS::ParametersStruct
{
public:
	DestructibleActorState(NvParameterized::Traits* traits, void* buf = 0, int32_t* refCount = 0);

	virtual ~DestructibleActorState();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("DestructibleActorState");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const uint32_t ClassVersion = ((uint32_t)0 << 16) + (uint32_t)4;

	static uint32_t staticVersion(void)
	{
		return ClassVersion;
	}

	uint32_t version(void) const
	{
		return(staticVersion());
	}

	static const uint32_t ClassAlignment = 8;

	static const uint32_t* staticChecksum(uint32_t& bits)
	{
		bits = 8 * sizeof(DestructibleActorStateNS::checksum);
		return DestructibleActorStateNS::checksum;
	}

	static void freeParameterDefinitionTable(NvParameterized::Traits* traits);

	const uint32_t* checksum(uint32_t& bits) const
	{
		return staticChecksum(bits);
	}

	const DestructibleActorStateNS::ParametersStruct& parameters(void) const
	{
		DestructibleActorState* tmpThis = const_cast<DestructibleActorState*>(this);
		return *(static_cast<DestructibleActorStateNS::ParametersStruct*>(tmpThis));
	}

	DestructibleActorStateNS::ParametersStruct& parameters(void)
	{
		return *(static_cast<DestructibleActorStateNS::ParametersStruct*>(this));
	}

	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle) const;
	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle);

	void initDefaults(void);

protected:

	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void);
	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void) const;


	virtual void getVarPtr(const NvParameterized::Handle& handle, void*& ptr, size_t& offset) const;

private:

	void buildTree(void);
	void initDynamicArrays(void);
	void initStrings(void);
	void initReferences(void);
	void freeDynamicArrays(void);
	void freeStrings(void);
	void freeReferences(void);

	static bool mBuiltFlag;
	static NvParameterized::MutexType mBuiltFlagMutex;
};

class DestructibleActorStateFactory : public NvParameterized::Factory
{
	static const char* const vptr;

public:

	virtual void freeParameterDefinitionTable(NvParameterized::Traits* traits)
	{
		DestructibleActorState::freeParameterDefinitionTable(traits);
	}

	virtual NvParameterized::Interface* create(NvParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(DestructibleActorState), DestructibleActorState::ClassAlignment);
		if (!NvParameterized::IsAligned(newPtr, DestructibleActorState::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DestructibleActorState");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(DestructibleActorState)); // always initialize memory allocated to zero for default values
		return NV_PARAM_PLACEMENT_NEW(newPtr, DestructibleActorState)(paramTraits);
	}

	virtual NvParameterized::Interface* finish(NvParameterized::Traits* paramTraits, void* bufObj, void* bufStart, int32_t* refCount)
	{
		if (!NvParameterized::IsAligned(bufObj, DestructibleActorState::ClassAlignment)
		        || !NvParameterized::IsAligned(bufStart, DestructibleActorState::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DestructibleActorState");
			return 0;
		}

		// Init NvParameters-part
		// We used to call empty constructor of DestructibleActorState here
		// but it may call default constructors of members and spoil the data
		NV_PARAM_PLACEMENT_NEW(bufObj, NvParameterized::NvParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (DestructibleActorState*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (DestructibleActorState::staticClassName());
	}

	virtual uint32_t getVersion()
	{
		return (DestructibleActorState::staticVersion());
	}

	virtual uint32_t getAlignment()
	{
		return (DestructibleActorState::ClassAlignment);
	}

	virtual const uint32_t* getChecksum(uint32_t& bits)
	{
		return (DestructibleActorState::staticChecksum(bits));
	}
};
#endif // NV_PARAMETERIZED_ONLY_LAYOUTS

} // namespace destructible
} // namespace nvidia

#if PX_VC
#pragma warning(pop)
#endif

#endif
