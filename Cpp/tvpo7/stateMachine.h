
#pragma once
#pragma pack()

typedef void (*VoidFunc)(void);

typedef struct StateMachine {
    unsigned state; // a=0..f=5
    VoidFunc onError;
} StateMachine;

extern unsigned STATE_ERROR;
extern char OPERATION_VIEW, OPERATION_COAT;

StateMachine* machineInit(VoidFunc onError);
unsigned machineView(StateMachine* machine);
unsigned machineCoat(StateMachine* machine);
void machineEnd(StateMachine* machine);

unsigned nodeA(StateMachine* machine, char which);
unsigned nodeB(StateMachine* machine, char which);
unsigned nodeC(StateMachine* machine, char which);
unsigned nodeD(StateMachine* machine, char which);
unsigned nodeE(StateMachine* machine, char which);
unsigned nodeF(StateMachine* machine, char which);
