#include "stack_utils.h"
#include <vector>
#include <string>

/**
 * 递归枚举合法的出栈序列
 * 每次递归独立尝试两种操作（并列，不互斥）：
 *   1. 若栈非空：弹出栈顶，加入序列，递归，回溯恢复；
 *   2. 若还有未入栈元素：将下一元素压栈，递归，回溯恢复。
 * 终止条件：栈空且无待入栈元素时，记录当前序列为一个合法结果。
 * @brief 枚举合法的出栈序列
 * @param stack 栈
 * @param remaining 未入栈的元素
 * @param current 当前序列
 * @param result 合法序列
 */
void generateSequences(SqStack &stack, vector<ElemType> &remaining, string current, vector<string> &result) {
    // 栈非空时，尝试弹出栈顶元素
    if (!isEmpty(stack)) {
        ElemType topVal = peek(stack);
        pop(stack, topVal); // 弹出栈顶
        current += (char)topVal; // 加入当前序列
        generateSequences(stack, remaining, current, result); // 递归
        push(stack, topVal); // 回溯：恢复栈顶
        current.pop_back(); // 回溯：移除最后一个字符
    }

    // 还有未入栈的元素时，尝试入栈
    if (!remaining.empty()) {
        ElemType val = remaining.front();
        remaining.erase(remaining.begin()); // 移除第一个元素（入栈）
        push(stack, val); // 入栈
        generateSequences(stack, remaining, current, result); // 递归
        pop(stack, val); // 回溯：弹出刚入栈的元素
        remaining.insert(remaining.begin(), val); // 回溯：恢复剩余元素
    }

    // 栈空且无剩余元素：记录合法序列
    if (isEmpty(stack) && remaining.empty()) {
        result.push_back(current);
    }
}

int main() {
    SqStack S;
    initStack(S);

    // 第一步：入A、B、C，弹出C（第一个出栈）
    push(S, 'A');
    push(S, 'B');
    push(S, 'C');
    ElemType c;
    pop(S, c); // 弹出C，第一个出栈元素

    // 第二步：入D，弹出D（第二个出栈）
    push(S, 'D');
    ElemType d;
    pop(S, d); // 弹出D，第二个出栈元素

    // 剩余待处理：栈中是B、A；未入栈的是E
    vector<ElemType> remaining = {'E'}; // 未入栈的元素
    string initial = "CD"; // 前两个出栈元素固定为C、D
    vector<string> result;

    // 生成所有合法序列
    generateSequences(S, remaining, initial, result);

    // 输出结果
    cout << "第一个出栈为C、第二个出栈为D的序列：" << endl;
    for (const string &seq : result) {
        cout << seq << endl;
    }

    return 0;
}

/*
```
初始：栈[A,B]  remaining[E]  current="CD"
│
├─ ① pop B → current="CDB"，栈[A]，remaining[E]
│   ├─ ① pop A → current="CDBA"，栈[]，remaining[E]
│   │   └─ ② push E → current="CDBA"，栈[E]，remaining[]
│   │       └─ ① pop E → current="CDBAE" ✓ 记录
│   └─ ② push E → current="CDB"，栈[A,E]，remaining[]
│       └─ ① pop E → current="CDBE"，栈[A]，remaining[]
│           └─ ① pop A → current="CDBEA" ✓ 记录
│
└─ ② push E → current="CD"，栈[A,B,E]，remaining[]
    └─ ① pop E → current="CDE"，栈[A,B]，remaining[]
        └─ ① pop B → current="CDEB"，栈[A]，remaining[]
            └─ ① pop A → current="CDEBA" ✓ 记录
*/