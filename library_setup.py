import os

class Variable:
    type = ""
    name = ""
    size = ""

    def __init__(self, line):
        parts = line.split(' ')
        self.type = parts[0]

        if (parts[0] == "TexturePtr"):
            self.size = "[]"
        
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
    if (entry.name != "init.c") and (entry.name[-2:] == ".c"):
        with open(entry) as file:
            for line in file:
                if (line[0] != ' ') and ('=' in line):
                    variables.append(Variable(line))

init_parameters = "#define INIT_PARAMETERS "
externs = ""
init_function = ""
init_arguments = "#define INIT_ARGUMENTS "
init_macro = "#define IH_INIT \\\n"

for variable in variables:
    init_parameters += f"{variable.type} (**d{variable.name[1:]}){variable.size}, "

    externs += f"extern {variable};\n"

    init_function += f"    *d{variable.name[1:]} = &{variable.name};\n"

    init_arguments += f"&i{variable.name[1:]}, "
    
    init_macro += f"                {variable.type} (*i{variable.name[1:]}){variable.size}; \\\n"

init_parameters = init_parameters[:-2]
init_arguments = init_arguments[:-2]

print("-------------------------- INIT_PARAMETERS --------------------------\n\n")
print(init_parameters)
print("\n\nHere is the INIT_PARAMETERS macro. Replace the previous macro in init.c and interface_helper.h "
        "and press enter when you're ready to continue.")
input()

print("-------------------------- EXTERNS --------------------------\n\n")
print(externs)
print("\nHere are the externs. Replace the previous externs in init.c "
        "and press enter when you're ready to continue.")
input()

print("-------------------------- INIT FUNCTION --------------------------\n\n")
print(init_function)
print("\nHere is the content of the init function. Replace the previous content in init.c "
        "and press enter when you're ready to continue.")
input()

print("-------------------------- INIT_ARGUMENTS --------------------------\n\n")
print(init_arguments)
print("\n\nHere is the INIT_ARGUMENTS macro. Replace the previous macro in interface_helper.h "
        "and press enter when you're ready to continue.")
input()

print("-------------------------- IH_INIT --------------------------\n\n")
print(init_macro)
print("\nHere is the IH_INIT macro. Replace the previous macro in interface_helper.h up until the line beginning with RECOMP_IMPORT "
        "and press enter when you're ready to continue.")
input()