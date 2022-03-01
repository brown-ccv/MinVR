/** 
This file is part of the MinVR Open Source Project, which is developed and 
maintained collaboratively by the University of Minnesota and Brown University.

Copyright (c) 2016 Regents of the University of Minnesota and Brown University.
This software is distributed under the BSD-3 Clause license, which can be found
at: MinVR/LICENSE.txt.

Original Author(s) of this File: 
	Dan Keefe, 2017, University of Minnesota
	
Author(s) of Significant Updates/Modifications to the File:
	... 
*/


#include "api/VRWindowResizeEvent.h"
#include "config/VRDataIndex.h"

namespace MinVR {

  VRWindowResizeEvent::VRWindowResizeEvent(const VRDataIndex &internalIndex) : _index(internalIndex) {

}

  VRWindowResizeEvent::~VRWindowResizeEvent() {

}
    
const float * VRWindowResizeEvent::getWindowSize() const {
    if (_index.exists("WindowSize")) {
        const std::vector<float>* v = _index.getValue("WindowSize");
        return &(v->front());
    }
    else {
        VRERROR("VRWindowResizeEvent::getWindowSize() cannot determine a data field to return for event named " +
                _index.getName() + ".", "Window's reSize events should have an entry in their data index called WindowSize.");
        return NULL;
    }
}
    
    

std::string VRWindowResizeEvent::getName() const {
    return _index.getName();
}

    
    
const VRDataIndex& VRWindowResizeEvent::index() const {
	return _index;
}

    
    
VRDataIndex VRWindowResizeEvent::createValidDataIndex(const std::string &eventName,
    std::vector<float> size)
{
    VRDataIndex di(eventName);
    di.addData("EventType", "WindowSize");
    di.addData("WindowSize", size);
    return di;
}
    

VRWindowCloseEvent::VRWindowCloseEvent(const VRDataIndex& internalIndex):_index(internalIndex)
{

}

VRWindowCloseEvent::~VRWindowCloseEvent()
{

}

std::string VRWindowCloseEvent::getName() const
{
  return _index.getName();
}

const MinVR::VRDataIndex& VRWindowCloseEvent::index() const
{
  return _index;
}

MinVR::VRDataIndex VRWindowCloseEvent::createValidDataIndex()
{
  VRDataIndex di("WindowClose");
  di.addData("EventType", "WindowClose");
  return di;
}

} // end namespace
