import sys

numPeople, numTrees = map(int, input().split(" "))
dictPeople = {}

for i in range(numPeople):
    lst = []
    for j in range(numTrees):
        lst.append(0)
    dictPeople[i] = lst

for line in sys.stdin:
    person, tree = map(int, line.split(" "))
    person -= 1
    tree -= 1
    currLst = dictPeople[person]
    if currLst[tree] == 0:
        currLst[tree] += 1

dictTrees = {}
for i in range(numPeople):
    dictTrees[tuple(dictPeople[i])] = i
print(len(dictTrees))