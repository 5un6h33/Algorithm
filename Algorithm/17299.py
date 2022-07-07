from collections import Counter
import sys

lenght = int(sys.stdin.readline())
number = list(map(int,sys.stdin.readline().split()))
answer = [-1] * lenght
stack = [0]

number_len = Counter(number)

for i in range(1,lenght):
    while stack and number_len[number[stack[-1]]] < number_len[number[i]]:
        answer[stack.pop()] = number[i]
    stack.append(i)
print(*answer)
