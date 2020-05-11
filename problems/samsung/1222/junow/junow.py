TEST_CASE = 10

for tc in range(TEST_CASE):
  len = int(input())
  expression = input()
  answer=0
  for ch in expression:
    if ch.isdigit():
      answer += int(ch)
  print('#{0}'.format(tc+1), answer)