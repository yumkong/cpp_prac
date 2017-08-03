# merge sort: sorting with nlog(n)
def mergesort(lst):
    if len(lst) <= 1:
        return lst
    mid = len(lst) / 2
    #[0:mid-1]
    left = mergesort(lst[:mid])
    #[mid:len-1]
    right = mergesort(lst[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    # append the remaining, which must be large
    result += left[i:]
    result += right[j:]
    return result

if __name__ == '__main__':
    lst = [4,2,4,5,6,7,-8,87,2,1, 0, -82]
    print mergesort(lst)
