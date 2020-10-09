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
// Copyright (c) 2016-2020 NVIDIA Corporation. All rights reserved.


#ifndef NVBLASTTKJOINTIMPL_H
#define NVBLASTTKJOINTIMPL_H


#include "NvBlastTkJoint.h"
#include "NvBlastTkCommon.h"
#include "NvBlastIndexFns.h"

#include "NvBlastAssert.h"
#include "NvBlastDLink.h"

#include <atomic>


namespace Nv
{
namespace Blast
{

// Forward declarations
class TkActorImpl;
class TkJointImpl;
class TkFamilyImpl;
class TkEventQueue;


/**
Double-sided link (DLink) which holds a reference back to a joint which contains it.
*/
struct TkJointLink : public DLink
{
	TkJointImpl*	m_joint;	//!< The joint containing this link.
};


/**
Implementation of TkJoint.
*/
class TkJointImpl : public TkJoint
{
public:
	/** Blank constructor only creates valid TkJointLinks (point back to this object) */
	TkJointImpl();

	/**
	This constructor sets all internal data.  If the joint is defined in an asset, the family
	instanced from that asset will own this joint, and the 'owner' parameter is that family.
	Otherwise, in the case where a joint is created from TkFramwork::createJoint, the joint
	is not owned by a family and 'owner' will be NULL.
	*/
	TkJointImpl(const TkJointDesc& desc, TkFamilyImpl* owner);

	// Begin TkObject
	virtual void				release() override;
	// End TkObject

	// Begin TkJoint
	virtual const	TkJointData	getData() const override;
	// End TkJoint

	// Public API

	/**
	Internal method to access a const reference to the joint data.

	\return a const reference to the joint data.
	*/
	const TkJointData&			getDataInternal() const;	

	/**
	Internal method to access a non-const reference to the joint data.

	\return a non-const reference to the joint data.
	*/
	TkJointData&				getDataWritable();

	/**
	Set the actors that this joint attaches to.  When the actors are different from the joint's current actors,
	an event will be generated on one of the actors' families event queues to signal the change.  Alternatively,
	if alternateQueue is not NULL then it will be used to hold the event.

	If a non-NULL attached actor becomes NULL, then this joint will detach its references to both actors (if
	they exist) and send an event of subtype Unreferenced.  This signals the user that the joint may be deleted.

	\param[in]	actor0			The new TkActor to replace the first attached actor.
	\param[in]	actor1			The new TkActor to replace the second attached actor.
	\param[in]	alternateQueue	If not NULL, this queue will be used to hold events generated by this function.
	*/
	void						setActors(TkActorImpl* actor0, TkActorImpl* actor1, TkEventQueue* alternateQueue = nullptr);

	/**
	Ensures that any attached actors no longer refer to this joint.
	*/
	void						removeReferencesInActors();

	/**
	Ensures that any attached actors' families no longer refer to this joint.  External joints (created using
	TkFramework::createJoint) are referenced by the attached actors' families.
	*/
	void						removeReferencesInFamilies();

private:
	TkJointData		m_data;		//!< The data given to the user: attached actors, chunk indices, and actor-local attachment positions.
	TkJointLink		m_links[2];	//!< One link for each actor in m_data.m_actors.  If m_data.m_actors[0] == m_data.m_actors[1], then only m_links[0] is used.
	TkFamilyImpl*	m_owner;	//!< The owning family if this is an internal joint created during TkFramework::createActor() from a TkAssetDesc with joint flags.

	friend class TkFrameworkImpl;
	friend class TkFamilyImpl;
	friend class TkActorImpl;
};


//////// TkJointImpl inline methods ////////

NV_INLINE TkJointImpl::TkJointImpl()
{
	m_links[0].m_joint = m_links[1].m_joint = this;
}


NV_INLINE const TkJointData& TkJointImpl::getDataInternal() const
{
	return m_data;
}


NV_INLINE TkJointData& TkJointImpl::getDataWritable()
{
	return m_data;
}

} // namespace Blast
} // namespace Nv


#endif // ifndef NVBLASTTKJOINTIMPL_H
