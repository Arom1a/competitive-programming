# N = int(input())
name_map = {}
ZODIAZ = {'Ox':1, 'Tiger':2, 'Rabbit':3, 'Dragon':4, 'Snake':5, 'Horse':6, 'Goat':7, 'Monkey':8, 'Rooster':9, 'Dog':10, 'Pig':11, 'Rat':12}
# for i in range(N):
#     string = input().split(' ')
#     name = string[0]
#     relation = string[3]
#     animal = string[4]
#     name_map[name] = (relation, animal)

def calculate_between(pre_relation_tuple, relation_tuple):
    if relation_tuple[0] == 'previous':
        return abs(ZODIAZ[pre_relation_tuple[1]]-ZODIAZ[relation_tuple[1]])-12
    else:
        return abs(ZODIAZ[pre_relation_tuple[1]]-ZODIAZ[relation_tuple[1]])
print(calculate_between(('pre', 'Ox'), ('previous', 'Dragon')))