#include "maze.h"
#include "stack.h"

int main(void) {
    Stack stack;
    stackInit(&stack);

    printf("=== 스택 Push/Pop 테스트 ===\n\n");

    // 1. isEmpty 테스트
    printf("[1] 초기 상태: %s\n\n",
        stackIsEmpty(&stack) ? "비어있음 (정상)" : "비어있지 않음 (오류!)");

    // 2. Push 테스트
    Position a = {0, 0};
    Position b = {1, 2};
    Position c = {3, 4};

    stackPush(&stack, a);
    printf("[2] Push (0,0) -> top = %d\n", stack.top);

    stackPush(&stack, b);
    printf("    Push (1,2) -> top = %d\n", stack.top);

    stackPush(&stack, c);
    printf("    Push (3,4) -> top = %d\n\n", stack.top);

    // 3. Peek 테스트
    Position top = stackPeek(&stack);
    printf("[3] Peek: (%d, %d)  <- (3,4)가 나와야 정상\n\n",
        top.row, top.col);

    // 4. Pop 테스트 (LIFO 순서 확인)
    printf("[4] Pop 순서 (LIFO 확인):\n");
    while (!stackIsEmpty(&stack)) {
        Position p = stackPop(&stack);
        printf("    Pop -> (%d, %d)\n", p.row, p.col);
    }

    // 5. Pop 후 isEmpty 확인
    printf("\n[5] 모두 Pop 후: %s\n",
        stackIsEmpty(&stack) ? "비어있음 (정상)" : "비어있지 않음 (오류!)");

    return 0;
}
