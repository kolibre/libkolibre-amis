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

#ifndef NAVPOINT_H
#define NAVPOINT_H

#include "NavNode.h"

namespace amis {

class NAVPARSE_API NavPoint: public NavNode
{
public:
    NavPoint();
    ~NavPoint();

    NavPoint* getFirstSibling();
    NavPoint* getChild(int);
    int getLevel();

    NavPoint* getParent();
    NavPoint* next();

    NavPoint* previous();

    void resetChildCount();
    int getNumChildren();

    void addChild(NavPoint*);
    void addSibling(NavPoint*);
    void setParent(NavPoint*);
    void setLevel(int);

private:


    NavPoint* mpSibling;
    NavPoint* mpFirstChild;
    int mLevel;
    //!number of children
    int mNumChildren;
    NavPoint* mpParent;
    int mChildCount;

};

}  // namespace
#endif
