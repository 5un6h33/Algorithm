from glob import glob

ignore = [".c", ".cpp", ".txt"]
file_list = glob('**/*', recursive=True)
new_list = []
for i in file_list: 
    if "." not in i:
        new_list.append(i)

print(new_list)

