#
# Code Contributor(s): Rajeev Ranjan
#2nd contributor Sanjeev

def prefixArray(pattern):
    i = 1
    j = 0
    prefix = [0,]
    while i < len(pattern):
        while j > 0 and pattern[i] != pattern[j]:
            j = prefix[j-1]
        if pattern[i] == pattern[j]:
            j = j + 1
            prefix.insert(i, j)
        else:
            prefix.insert(i, j)
        i = i + 1
    return prefix

def KMP(string, pattern):
    m = len(string)
    n = len(pattern)
    i, j = 0, 0
    prefix = prefixArray(pattern)
    while i < m:
        while j > 0 and string[i] != pattern[j]:
            j = prefix[j-1]
        if string[i] == pattern[j]:
            j = j + 1
        if j == n:
            print("Pattern found at index : ", i-n+1)
            j = prefix[j-1]
        i = i + 1

if __name__ == '__main__':
    string = input('Enter a sentence : ')
    pattern = input('Enter the pattern to be searched : ')
    KMP(string, pattern)


'''
Test Case 0:

INPUT

Enter a sentence : My very educated mother just showed us the nine planets.
Enter the pattern to be searched : mother

OUTPUT

Pattern found at index :  17

Test Case 1:

INPUT

Enter a sentence : Repeating the same word again and again.
Enter the pattern to be searched : again

OUTPUT
Pattern found at index :  24
Pattern found at index :  34

'''
