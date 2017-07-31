#this has problem
def int32(x):
    # if longer than 32 bit, just keep the lowest 32 bits
    if x > 0xFFFFFFFF:
        #raise OverflowError
        x |= 0xFFFFFFFF
    if x > 0x7FFFFFFF:
        x = int(0x100000000 - x)
    if x < 2147483648:
        return -x
    else:
        return -2147483648
    return x

def main():
    print int32(-2)
    print int32(1 << 31)
    print int32(~(1 << 31))

if __name__ == '__main__':
    max_int = 2147483647
    min_int = -2147483648
    main()
