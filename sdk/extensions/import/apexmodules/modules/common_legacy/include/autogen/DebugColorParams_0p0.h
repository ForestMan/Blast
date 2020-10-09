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


#ifndef HEADER_DebugColorParams_0p0_h
#define HEADER_DebugColorParams_0p0_h

#include "NvParametersTypes.h"

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
#include "nvparameterized/NvParameterized.h"
#include "nvparameterized/NvParameterizedTraits.h"
#include "NvParameters.h"
#include "NvTraitsInternal.h"
#endif

namespace nvidia
{
namespace parameterized
{

#if PX_VC
#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())
#endif

namespace DebugColorParams_0p0NS
{



struct ParametersStruct
{

	uint32_t Default;
	uint32_t PoseArrows;
	uint32_t MeshStatic;
	uint32_t MeshDynamic;
	uint32_t Shape;
	uint32_t Text0;
	uint32_t Text1;
	uint32_t ForceArrowsLow;
	uint32_t ForceArrowsNorm;
	uint32_t ForceArrowsHigh;
	uint32_t Color0;
	uint32_t Color1;
	uint32_t Color2;
	uint32_t Color3;
	uint32_t Color4;
	uint32_t Color5;
	uint32_t Red;
	uint32_t Green;
	uint32_t Blue;
	uint32_t DarkRed;
	uint32_t DarkGreen;
	uint32_t DarkBlue;
	uint32_t LightRed;
	uint32_t LightGreen;
	uint32_t LightBlue;
	uint32_t Purple;
	uint32_t DarkPurple;
	uint32_t Yellow;
	uint32_t Orange;
	uint32_t Gold;
	uint32_t Emerald;
	uint32_t White;
	uint32_t Black;
	uint32_t Gray;
	uint32_t LightGray;
	uint32_t DarkGray;

};

static const uint32_t checksum[] = { 0x21b30efd, 0xaea10022, 0x72a4df62, 0x8fab217f, };

} // namespace DebugColorParams_0p0NS

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
class DebugColorParams_0p0 : public NvParameterized::NvParameters, public DebugColorParams_0p0NS::ParametersStruct
{
public:
	DebugColorParams_0p0(NvParameterized::Traits* traits, void* buf = 0, int32_t* refCount = 0);

	virtual ~DebugColorParams_0p0();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("DebugColorParams");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const uint32_t ClassVersion = ((uint32_t)0 << 16) + (uint32_t)0;

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
		bits = 8 * sizeof(DebugColorParams_0p0NS::checksum);
		return DebugColorParams_0p0NS::checksum;
	}

	static void freeParameterDefinitionTable(NvParameterized::Traits* traits);

	const uint32_t* checksum(uint32_t& bits) const
	{
		return staticChecksum(bits);
	}

	const DebugColorParams_0p0NS::ParametersStruct& parameters(void) const
	{
		DebugColorParams_0p0* tmpThis = const_cast<DebugColorParams_0p0*>(this);
		return *(static_cast<DebugColorParams_0p0NS::ParametersStruct*>(tmpThis));
	}

	DebugColorParams_0p0NS::ParametersStruct& parameters(void)
	{
		return *(static_cast<DebugColorParams_0p0NS::ParametersStruct*>(this));
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

class DebugColorParams_0p0Factory : public NvParameterized::Factory
{
	static const char* const vptr;

public:

	virtual void freeParameterDefinitionTable(NvParameterized::Traits* traits)
	{
		DebugColorParams_0p0::freeParameterDefinitionTable(traits);
	}

	virtual NvParameterized::Interface* create(NvParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(DebugColorParams_0p0), DebugColorParams_0p0::ClassAlignment);
		if (!NvParameterized::IsAligned(newPtr, DebugColorParams_0p0::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DebugColorParams_0p0");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(DebugColorParams_0p0)); // always initialize memory allocated to zero for default values
		return NV_PARAM_PLACEMENT_NEW(newPtr, DebugColorParams_0p0)(paramTraits);
	}

	virtual NvParameterized::Interface* finish(NvParameterized::Traits* paramTraits, void* bufObj, void* bufStart, int32_t* refCount)
	{
		if (!NvParameterized::IsAligned(bufObj, DebugColorParams_0p0::ClassAlignment)
		        || !NvParameterized::IsAligned(bufStart, DebugColorParams_0p0::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DebugColorParams_0p0");
			return 0;
		}

		// Init NvParameters-part
		// We used to call empty constructor of DebugColorParams_0p0 here
		// but it may call default constructors of members and spoil the data
		NV_PARAM_PLACEMENT_NEW(bufObj, NvParameterized::NvParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (DebugColorParams_0p0*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (DebugColorParams_0p0::staticClassName());
	}

	virtual uint32_t getVersion()
	{
		return (DebugColorParams_0p0::staticVersion());
	}

	virtual uint32_t getAlignment()
	{
		return (DebugColorParams_0p0::ClassAlignment);
	}

	virtual const uint32_t* getChecksum(uint32_t& bits)
	{
		return (DebugColorParams_0p0::staticChecksum(bits));
	}
};
#endif // NV_PARAMETERIZED_ONLY_LAYOUTS

} // namespace parameterized
} // namespace nvidia

#if PX_VC
#pragma warning(pop)
#endif

#endif
