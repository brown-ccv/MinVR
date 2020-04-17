#include "VRG3DInputDevice.h"
#include <config/VRDataQueue.h>
#include "VRG3DWindowToolkit.h"

namespace MinVR
{
  VRG3DInputDevice::VRG3DInputDevice()
  {

  }

  VRG3DInputDevice::~VRG3DInputDevice()
  {

  }

  void VRG3DInputDevice::appendNewInputEventsSinceLastCall(VRDataQueue* queue)
  {
    G3D::GEvent g3dEvent;
    _windows[0]->pollEvent(g3dEvent);
  }


  PLUGIN_API void VRG3DInputDevice::addWindow(G3DWindow* g3dWindow)
  {
    _windows.push_back(g3dWindow);
  }

}