total_string = input()
match_string = input()
count = 0
i = 0
flag = False
while True:
    if match_string not in total_string or len(total_string) < len(match_string) or (len(total_string) == len(match_string) and total_string != match_string):
        break
    if flag is True:
        i = 0
        flag = False
    if match_string == total_string[i:i+len(match_string)]:
        total_string = total_string[i+len(match_string):]
        count+=1
        flag = True
    i += 1

print(count)