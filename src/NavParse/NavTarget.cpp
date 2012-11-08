/*
 NavParse: Navigation model for DAISY NCC and NCX

 Copyright (C) 2004  DAISY for All Project
 
 Copyright (C) 2012 Kolibre

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/**
 * @class amis::NavTarget
 *
 * @brief Pointer for navigating between navigation points
 *
 * @author Kolibre (www.kolibre.org)
 *
 * Contact: info@kolibre.org
 *
 */

#include "NavTarget.h"

using namespace amis;

NavTarget::NavTarget()
{
    this->mTypeOfNode = NavNode::NAV_TARGET;
}

NavTarget::~NavTarget()
{
}

int NavTarget::getIndex()
{
    return mIndex;
}

void NavTarget::setIndex(int idx)
{
    mIndex = idx;
}

void NavTarget::setNavList(amis::NavList* pList)
{
    mpNavList = pList;
}

amis::NavList* NavTarget::getNavList()
{
    return mpNavList;
}
