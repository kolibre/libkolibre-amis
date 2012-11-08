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

#ifndef NAVCONTAINER_H
#define NAVCONTAINER_H

#include "Media.h"
#include "NavNode.h"

namespace amis {

class NAVPARSE_API NavContainer
{
public:
    NavContainer();
    virtual ~NavContainer() = 0;

    virtual amis::NavNode* next() = 0;
    virtual amis::NavNode* first() = 0;
    virtual amis::NavNode* previous() = 0;
    virtual amis::NavNode* last() = 0;
    virtual void updateCurrent(amis::NavNode*) = 0;
    virtual amis::NavNode* syncPlayOrder(int) = 0;
    virtual amis::NavNode* goToContentRef(std::string) = 0;
    virtual amis::NavNode* goToId(std::string) = 0;

    amis::NavNode* previousBasedOnPlayOrder(int playOrder);
    amis::NavNode* nextBasedOnPlayOrder(int playOrder);
    void setLabel(amis::MediaGroup*);
    amis::MediaGroup* getLabel();

    void setNavInfo(amis::MediaGroup*);
    amis::MediaGroup* getNavInfo();

    void setId(std::string);
    std::string getId();

    amis::NavNode* current();

protected:
    std::vector<amis::NavNode*> mpNodes;
    amis::NavNode* mpCurrent;

private:
    amis::MediaGroup* mpLabel;
    amis::MediaGroup* mpNavInfo;
    std::string mId;

};

}
#endif
