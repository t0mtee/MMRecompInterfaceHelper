import os

class Variable:
    type = ""
    name = ""
    size = ""

    def __init__(self, line):
        parts = line.split(' ')
        self.type = parts[0]

        #if (parts[0] == "TexturePtr"):
        #    self.size = "[]"
        
        if (parts[1][-1:] == ']'):
            index = parts[1].index('[')

            self.name = parts[1][0:index]
            self.size += parts[1][index:]
        else:
            self.name = parts[1]

    def __str__(self):
        return f"{self.type} {self.name}{self.size}"

variables = []

for entry in os.scandir("./src"):
    if (entry.name != "library.c") and (entry.name[-2:] == ".c"):
        with open(entry) as file:
            for line in file:
                if (line[0] != ' ') and ('=' in line):
                    variables.append(Variable(line))

file =  "#include \"modding.h\"\n"
file += "#include \"global.h\"\n\n"

for variable in variables:
    file += f"extern {variable};\n\n"
    
    file += f"RECOMP_EXPORT void {variable.name}_Register({variable.type} (**pointer)"
    if variable.size != "":
        file += f"{variable.size}"
    file += f")\n"
    file += "{\n"
    file += f"  *pointer = &{variable.name};\n"
    file += "}\n\n"

print(file + "Paste everything above into library.c")