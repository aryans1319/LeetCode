class Solution:
	def evalRPN(self, tokens: List[str]) -> int:

		stack = []

		for char in tokens:

			if char == '+':
				stack.append(stack.pop() + stack.pop())

			elif char == '-':
				first_top = stack.pop()
				second_top = stack.pop()
				stack.append(second_top - first_top)

			elif char == '*':
				stack.append(stack.pop() * stack.pop())

			elif char == '/':
				first_top = stack.pop()
				second_top = stack.pop()
				stack.append(int(second_top / first_top))

			else:
				stack.append(int(char))

		return stack[0]
