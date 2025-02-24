
#include <assert.h>
#include "stateMachine.h"

#define TEST(x, y) void test ## x() \
    { StateMachine* machine = machineInit(&onError); y machineEnd(machine); }

unsigned errors = 0;

void onError() { errors++; }

TEST(1,
    assert(machineView(machine) == 0); // a -> b
    assert(machineView(machine) == 1); // b -> c
    assert(machineCoat(machine) == 4); // c -> e
    assert(machineCoat(machine) == 7); // e -> a
    assert(machineView(machine) == 0); // a -> b
    assert(machineView(machine) == 1); // b -> c
    assert(machineView(machine) == 3); // c -> d
    assert(machineView(machine) == STATE_ERROR); // d -> unknown
    assert(machineCoat(machine) == 5); // d -> e
    assert(machineCoat(machine) == 7); // e -> a
    assert(machineView(machine) == 0); // a -> b
    assert(machineCoat(machine) == 2); // b -> f
    assert(machineCoat(machine) == 8); // f -> f
)

TEST(2,
    assert(machineView(machine) == 0); // a -> b
    assert(machineView(machine) == 1); // b -> c
    assert(machineView(machine) == 3); // c -> d
    assert(machineCoat(machine) == 5); // d -> e
    assert(machineView(machine) == 6); // e -> f
    assert(machineCoat(machine) == 8); // f -> f
    assert(machineCoat(machine) == 8); // f -> f
    assert(machineView(machine) == STATE_ERROR); // f -> unknown
)

TEST(3,
    assert(machineCoat(machine) == STATE_ERROR); // a -> unknown
    assert(machineView(machine) == 0); // a -> b
    assert(machineView(machine) == 1); // b -> c
    assert(machineView(machine) == 3); // c -> d
    assert(machineView(machine) == STATE_ERROR); // d -> unknown
)

TEST(11,
    assert(nodeA(machine, OPERATION_VIEW) == 0); // a -> b
    assert(nodeB(machine, OPERATION_VIEW) == 1); // b -> c
    assert(nodeC(machine, OPERATION_COAT) == 4); // c -> e
    assert(nodeE(machine, OPERATION_COAT) == 7); // e -> a
    assert(nodeA(machine, OPERATION_VIEW) == 0); // a -> b
    assert(nodeB(machine, OPERATION_VIEW) == 1); // b -> c
    assert(nodeC(machine, OPERATION_VIEW) == 3); // c -> d
    assert(nodeD(machine, OPERATION_VIEW) == STATE_ERROR); // d -> unknown
    assert(nodeD(machine, OPERATION_COAT) == 5); // d -> e
    assert(nodeE(machine, OPERATION_COAT) == 7); // e -> a
    assert(nodeA(machine, OPERATION_VIEW) == 0); // a -> b
    assert(nodeB(machine, OPERATION_COAT) == 2); // b -> f
    assert(nodeF(machine, OPERATION_COAT) == 8); // f -> f
)

TEST(22,
    assert(nodeA(machine, OPERATION_VIEW) == 0); // a -> b
    assert(nodeB(machine, OPERATION_VIEW) == 1); // b -> c
    assert(nodeC(machine, OPERATION_VIEW) == 3); // c -> d
    assert(nodeD(machine, OPERATION_COAT) == 5); // d -> e
    assert(nodeE(machine, OPERATION_VIEW) == 6); // e -> f
    assert(nodeF(machine, OPERATION_COAT) == 8); // f -> f
    assert(nodeF(machine, OPERATION_COAT) == 8); // f -> f
    assert(nodeF(machine, OPERATION_VIEW) == STATE_ERROR); // f -> unknown
)

TEST(33,
    assert(nodeA(machine, OPERATION_COAT) == STATE_ERROR); // a -> unknown
    assert(nodeA(machine, OPERATION_VIEW) == 0); // a -> b
    assert(nodeB(machine, OPERATION_VIEW) == 1); // b -> c
    assert(nodeC(machine, OPERATION_VIEW) == 3); // c -> d
    assert(nodeD(machine, OPERATION_VIEW) == STATE_ERROR); // d -> unknown
)

int main(
    __attribute__((unused)) const int argc,
    __attribute__((unused)) char const* const* const argv
) {
    test1();
    test2();
    test3();
    assert(errors == 4);
    test11();
    test22();
    test33();
    assert(errors == 8);
    return 0;
}
