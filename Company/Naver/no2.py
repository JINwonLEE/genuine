# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# S = String, K = length of message
# 1 <= K <= 500, 1 <= len(S) <= 500
# if impossible to split  => return -1


def solution(S, K):
    split_S = S.split()
    messages_length = [0] * 250
    message_ind = 0
    # Check S is able to split or not
    for s in split_S:
        if len(s) > K:
            return -1

    for s in split_S:
        # add text with space
        if messages_length[message_ind] + len(s) + 1 <= K and messages_length[message_ind] != 0:
            messages_length[message_ind] += len(s) + 1
        # add text without space
        elif messages_length[message_ind] + len(s) <= K and messages_length[message_ind] == 0 :
            messages_length[message_ind] += len(s)
        # add text in next message:
        else :
            message_ind += 1
            messages_length[message_ind] += len(s)

    return message_ind + 1

print(solution("test for this", 5))
print(solution("asdfaewfqwefq", 13))
print(solution("asdfaeq eles fds", 5))
print(solution("a b c d e f g h", 4))
