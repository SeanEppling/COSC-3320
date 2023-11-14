def is_equal(l1, l2, n, m):
    if n != m:
        return False

    count_map = {}
    for i in range(n):
        count_map[l1[i]] = count_map.get(l1[i], 0) + 1

    for i in range(n):
        if l2[i] not in count_map or count_map[l2[i]] == 0:
            return False
        count_map[l2[i]] -= 1

    return True

if __name__ == "__main__":
    l1 = [1, 2, 3, 4, 5, 6]
    l2 = [3, 6, 2, 4, 1, 5]
    n = len(l1)
    m = len(l2)

    if is_equal(l1, l2, n, m):
        print("l1 and l2 are equal")
    else:
        print("l1 and l2 are not equal")
