#FlyWeight Pattern

##Setup

Imagine a scence where we have thousands of trees coming into view. If we are
going to render each tree individually, the program will come to a halt because
the bus is not big enough to send the information of thousands of tress to the
GPU.

To make this problem more managable, these thounsands trees share few common
characteristics: their textures, their shape etc... We can take these common
characteristers our of the tree class and make all the tree objects share the
same characteristic.

Making multiple objects share the same object is the basic of the Flyweight
pattern. This is employed vi pointer or reference. The tree method will be
implemented with an pointer to the shared characteristics object. __Note__: the
pointer or reference must be const because the characteristic object affects all
the objects.


## Sample Code
