
#include <stdlib.h>
#include "stateMachine.h"

#define SWITCH(x, y) { switch (x) { y } }
#define CASE(x, y, z) case x: machine->state = y; return z;
#define DEFAULT default: machine->onError(); return STATE_ERROR;
#define WAYS(x1, x2, y1, y2) \
    { if (!which) { machine->state = x1; return x2; } else { machine->state = y1; return y2; } }
#define WAY(x, y, z) \
    { if (x) { machine->state = y; return z; } else { machine->onError(); return STATE_ERROR; } }

unsigned STATE_ERROR = 0xffffffff;
char OPERATION_VIEW = 0, OPERATION_COAT = 1;

StateMachine* machineInit(VoidFunc onError) {
    StateMachine* machine = malloc(sizeof(StateMachine));
    machine->state = 0;
    machine->onError = onError;
    return machine;
}

unsigned machineView(StateMachine* machine) SWITCH(machine->state,
    CASE(0, 1, 0)
    CASE(1, 2, 1)
    CASE(2, 3, 3)
    CASE(4, 5, 6)
    DEFAULT
)

unsigned machineCoat(StateMachine* machine) SWITCH(machine->state,
    CASE(1, 5, 2)
    CASE(2, 4, 4)
    CASE(3, 4, 5)
    CASE(4, 0, 7)
    CASE(5, machine->state, 8)
    DEFAULT
)

void machineEnd(StateMachine* machine) { free(machine); }

unsigned nodeA(StateMachine* machine, char which) WAY(!which, 1, 0)
unsigned nodeB(StateMachine* machine, char which) WAYS(2, 1, 5, 2)
unsigned nodeC(StateMachine* machine, char which) WAYS(3, 3, 4, 4)
unsigned nodeD(StateMachine* machine, char which) WAY(which, 4, 5)
unsigned nodeE(StateMachine* machine, char which) WAYS(5, 6, 0, 7)
unsigned nodeF(StateMachine* machine, char which) WAY(which, 5, 8)
