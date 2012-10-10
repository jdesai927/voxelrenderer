Updates from the last homework:

I've completed the full core functionality. I've also done the extra credit.

Each configuration file contains specifications for a second light. The tag is
"LPO2" (which comes first) for the second light's position, and "LCO2" for the
second light's color. These come directly after (with no empty lines in between
or before them) the first light's color.

In addition, I've added three more types of primitives. The first is the "cube"
primitive, which is a Perlin cloud with a cube as a base. The appropriate tag is
"cube", and the parameters are in the same format as the other primitives, with
the center being the center and the radius in this case corresponding to the
cube's edge length. The second is the "cylinder" primitive, which is a Perlin
cloud with a cylinder as a base. Once again the parameters are the same, with
the individual value denoting both the radius and half of the height of the base
cylinder. The third primitive I've added is the "boxfilter" primitive. This primitive
uses random points and a blurring algorithm to generate the values. The center value
in the configuration file is not used, but the individual value represents the
blurring radius.

I've put some of my favorite images in the "Best Images" folder, with the filenames
clearly describing what primitive those clouds are formed from. The "Config Files"
folder contains examples of "well-formed" config files for the different primitive
types.