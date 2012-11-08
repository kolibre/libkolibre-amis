/*
 SMIL Engine: linear and skippable navigation of Daisy 2.02 and Daisy 3 SMIL contents

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

#ifndef NODE_H
#define NODE_H

//SYSTEM INCLUDES
#include <string>

//PROJECT INCLUDES
#include "SmilEngineConstants.h"
#include "SmilMediaGroup.h"

//we need to declare these classes but not include them
class SmilTree;
class TimeContainerNode;

//! A Node is the basic element for a SMIL tree
/*
 each node has zero or one sibling and zero or more children
 playback invoked on a node causes it to play itself one or more its children, 
 depending on if the node is a seq or a par.
 this node class is abstract and does not specify the type of node it represents
 */
class Node
{
public:

    //LIFECYCLE
    //!default constructor
    Node();
    //!destructor
    virtual ~Node() = 0;

    //ACCESS
    //!return element id
    std::string getElementId();
    //!set the element id
    void setElementId(std::string);

    //!assign a parent to this node
    void setParent(TimeContainerNode*);
    //!return this node's parent
    TimeContainerNode* getParent();

    //!set the smil tree pointer
    void setSmilTreePtr(SmilTree*);
    //!retrieve the smil tree pointer
    SmilTree* getSmilTreePtr();

    //!virtual function implemented in derived classes
    virtual NodeType getTypeOfNode() = 0;
    //!virtual function implemented in derived classes
    virtual NodeType getCategoryOfNode() = 0;

    //!return the immediate sibling of this node
    Node* getFirstSibling();

    //METHODS
    //!invoke playback on this node
    virtual void play(amis::SmilMediaGroup*) = 0;
    //!print this node
    void print(int);
    //!add a sibling for this node
    void addSibling(Node*);

private:
    //!sibling node pointer
    Node* mpSibling;
    //!parent node pointer
    TimeContainerNode* mpParent;
    //!smil tree pointer
    SmilTree* mpSmilTree;
    //!element id string
    std::string mElementId;
};

#endif

