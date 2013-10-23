/***************************************************************************
                    geometry.h  -  Geometry data for a node
                             -------------------
    begin                : Wed Jul 30 2003
    copyright            : (C) 2003 by Reality Rift Studios
    email                : mattias@realityrift.com
 ***************************************************************************

 The contents of this file are subject to the Mozilla Public License Version
 1.1 (the "License"); you may not use this file except in compliance with
 the License. You may obtain a copy of the License at 
 http://www.mozilla.org/MPL/

 Software distributed under the License is distributed on an "AS IS" basis,
 WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 for the specific language governing rights and limitations under the
 License.

 The Original Code is the NeoEngine, NeoABT, geometry.h

 The Initial Developer of the Original Code is Mattias Jansson.
 Portions created by Mattias Jansson are Copyright (C) 2003
 Reality Rift Studios. All Rights Reserved.

 ***************************************************************************/

#ifndef __NEABT_GEOMETRY_H
#define __NEABT_GEOMETRY_H

#include "base.h"

#include <neoengine/scenenode.h>
#include <neoengine/polygonbuffer.h>
#include <neoengine/aabb.h>


/**
  * \file geometry.h
  * Geometry data for a node in ABT
  */



namespace NeoABT
{




/**
  * \brief Geometry data for a node in ABT
  * \author Mattias Jansson (mattias@realityrift.com)
  */
class NEOABT_API Geometry : public NeoEngine::SceneNode
{
	public:

		/*! Polygons */
		NeoEngine::PolygonBufferPtr                   m_pkPolygons;

		/**
		* Partition the geometry
		* \param pvpkGeometries                       Vector storing final paritioned geometry objects
		* \param uiDepth                              Recursion depth
		*/
		void                                          Partition( std::vector< Geometry* > *pvpkGeometries, unsigned int uiDepth );

		/**
		* Render geometry
		* \param pkFrustum                            Frustum
		* \param bForce                               Force rendering flag
		*/
		virtual bool                                  Render( NeoEngine::Frustum *pkFrustum = 0, bool bForce = false );

		/**
		* Intersect ray with static geometry and scene nodes
		* \param rkRay                                Ray
		* \param pkCollSet                            Collision data set object receiving contact data
		* \return                                     true if intersection found, false if not
		*/
		virtual bool                                  Intersection( const NeoEngine::Ray &rkRay, NeoEngine::ContactSet *pkContactSet );

		/**
		* Intersect volume with static geometry and scene nodes
		* \param pkVolume                             Bounding volume
		* \param pkCollSet                            Collision data set object receiving contact data
		* \return                                     true if intersection found, false if not
		*/
		virtual bool                                  Intersection( NeoEngine::BoundingVolume *pkVolume, NeoEngine::ContactSet *pkContactSet );
};



};



#endif

