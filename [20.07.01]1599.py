num_strings = int(input())
string_list = []

for i in range(num_strings):
    string_list.append(input())
    string_list[i] = string_list[i].replace('k', 'c')
    string_list[i] = string_list[i].replace('p', 'q')
    string_list[i] = string_list[i].replace('o', 'p')
    string_list[i] = string_list[i].replace('ng', 'o')

string_list.sort()

for j in range(num_strings):
    string_list[j] = string_list[j].replace('o', 'ng')
    string_list[j] = string_list[j].replace('p', 'o')
    string_list[j] = string_list[j].replace('q', 'p')
    string_list[j] = string_list[j].replace('c', 'k')
    print(string_list[j])