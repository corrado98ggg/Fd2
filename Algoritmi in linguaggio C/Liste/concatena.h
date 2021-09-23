

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef CONCATENA_H_

#define CONCATENA_H_

enum ConcType {
	kCopy,
	kNoCopy
};

Item* cocatena(Item* i1, Item* i2, enum ConcType);

#endif // !CONCATENA_H_
