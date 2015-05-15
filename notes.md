# CC_SYD_02_OculusRift

- VR in general
- Rift in OpenFrameworks
- Examples of some projects



VR - fooling your subconscious senses the more senses that are fooled, the more real the experience

VRis different to other forms of media - eg. tv, video, intellectualise whats being shown vs feel
presentation vs representation

motion sickness
 - disagreement between senses 


HOW IT WORKS
- screen & sensors
- previously needed bulky complicated multi-element lenses to correct distortion
  - Now we have: cheap accelerometers
  - cheap mobile phone screens
  - fast graphics hardware, allows us to counter distortion in software and use cheap lenses

FOOLING SENSES

sensors <--> display 
feedback


Types of VR hardware
 - DK1 / DK2 / GearVR / HTC Vive

DK1
- First development kit from Oculus
- Rotational tracking
- 1280x800 (640x800 / eye)

GearVR
- $250, plastic shell + lenses with IMUs, insert phone inside
- only actual released commercial VR product. Requires Samsung Galaxy Note 4, 2560x1440 (1280x1400 /eye)
- No positional tracking
- Much of the content so far seems to be spherical video
- Mobile SDK not supported by this ofx addon.

DK2
- 1920x1080 (960x1080 / eye)
- Low persistence screen (reduces smearing - pixels only illuminated for a short time)
- Positional tracking via IR camera/LEDs, computer vision

Dk1 vs dk2
- Biggest difference positional tracking. Parallax
- low persistence

CV1 Specs not known, but higher res than DK2

HTC/Valve Vive
- Dual screen, higher resolution
- Lighthouse tracking system






Stereo rendering for VR
- Render two images, offset by the IPD (inter-pupillary distance)
- Brain finding correspondence between images in each eye, calculating depth based on disparity
- At 'infinty' no difference between eyes, up close, big difference (try it with your finger)
- On a practical level, 'infinity' is just the distance at which any changes in space don't translate into pixel differences

Designing for stereo:
- Need enough detail for your brain to pick up differences between eyes, but don't want the shapes you're looking at to be too different per eye
- Large flat colours = little correspondence between eyes, has less of a depth effect
- Noise/aliasing different in each eye = Can create shimmering effect as each eye is looking at different patterns



