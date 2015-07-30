# CC_SYD_02_OculusRift
### Oculus Rift in OpenFrameworks
### Matt Ebb
matt (at) mattebb.com
[http://mattebb.com]()

Slides are available here: http://ccsyd.github.io/CC_SYD_02_OculusRift/


### Required for examples:
- of 0.8.4
- ofxOculusDK2 addon (mattebb branch: https://github.com/mattebb/ofxOculusDK2/ )
- Oculus Runtime
- Oculus SDK (may not actually need this, I haven't tested without it. Handy to have anyway)

### New Project Installation

Getting all the libraries and headers set up can be a little annoying. Here are some rough instructions for Max OS X:

- XCode - use project generator, include the ofxOculusDK2 addon
- in Xcode folder list addons/ofxOculusDF2, delete 'lib' folder

- Edit Project.xcconfig:

````
ADDONS_PATH = $(OF_PATH)/addons

// ofxOculusRift
OFX_OCULUSRIFT_HEADERS = $(ADDONS_PATH)/ofxOculusDK2/libs/LibOVR/include/ $(ADDONS_PATH)/ofxOculusDK2/src

OF_ADDON_HEADERS = $(OFX_OCULUSRIFT_HEADERS)
OF_ADDON_LIBS = $(OFX_OCULUSRIFT_LIBS)

OTHER_LDFLAGS = $(OF_CORE_LIBS) $(OF_ADDON_LIBS)
HEADER_SEARCH_PATHS = $(OF_CORE_HEADERS)  $(OF_ADDON_HEADERS)
````

- add LibOVR.framework to Project &rarr; Build Phases &rarr; Link Binary with Libraries
